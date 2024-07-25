io8253a     equ 280h
io8253b     equ 281h
io8253c     equ 282h
io8253ctl   equ 283h
io8253ctlw  equ 76h

io8255a     equ 298h
io8255b     equ 299h
io8255c     equ 29ah
io8255ctl   equ 29bh

icw1        equ 2b0h
icw2        equ 2b1h
icw3        equ 2b1h
icw4        equ 2b1h
ocw1        equ 2b1h
ocw2        equ 2b0h
ocw3        equ 2b0h

;接线
;280~287H   8253CS
;CLK0       1MHz
;OUT0       CLK1
;GATE0      +5V
;OUT1       逻辑 外圈
;GATE1      +5V

;298~29FH   8255CS
;PA         PL4 数码管 A-DP
;PB         PL6 数码管 S0-S5
;PC         PL2 LED

;2B0~2B7H   8259CS
;INT        NOT_A
;NOT_Y      IRQ
;IR0        PULSE2+
;IR1        PULSE1+
;INTA       +5V

;按键输入输出可以套一个 D 触发器
;触发器 CLK 接 OUT1
;触发器 SD/CD 接 +5V

data segment
    msgclk db 13,10,'Clock tick','$'
    clk byte 1
    
    led db 01000100b,01000100b,01000100b,01000100b,01000100b,01000100b,01000100b,01000100b, \
            00h,01000010b,00h,01000010b,\
            00100001b,00100001b,00100001b,00100001b,00100001b,00100001b,00100001b,00100001b, \
            00h,10000001b,00h,10000001b, \
            01000001b ; 所有种情况 最后一种为救护车
    digits db 66h,66h,4fh,4fh,5bh,5bh,06h,06h, \
            00h,00h,00h,00h,\
            66h,66h,4fh,4fh,5bh,5bh,06h,06h, \
            00h,00h,00h,00h, \
            00h ; 所有种情况
    dpos db 1fh,1fh,1fh,1fh,1fh,1fh,1fh,1fh, \
            3fh,3fh,3fh,3fh,\
            3eh,3eh,3eh,3eh,3eh,3eh,3eh,3eh, \
            3fh,3fh,3fh,3fh, \
            3fh ; 所有种情况
    ambu byte 0 ; 救护车
    time byte 0 ; 当前时间 0-23 救护车 24
    ;digits db 3fh,06h,5bh,4fh,66h,6dh,7dh,07h,7fh,6fh,00h ; 共阴数码管数字
    count byte 10    ; 数码管当前数字
    
    msgint0 db 13,10,'Ambulance come','$'
    msgint1 db 13,10,'Ambulance gone','$'
    msgint2 db 13,10,'Already come','$'
    msgint3 db 13,10,'No ambulance','$'
    intnum db 00H
data ends

stk segment stack
    dw 0,0,0,0,0,0,0,0,0,0
stk ends

code segment
    assume cs:code, ds:data, ss:stk
start:
    ; 初始化中断
    mov ax, cs
    mov ds, ax
    mov dx, offset int3
    mov ax, 250bh
    int 21h
    cli
    in al, 21h
    and al, 0f7h
    out 21h, al
    mov al, 11h
    mov dx, icw1
    out dx, al 
    mov al, 08h
    mov dx, icw2
    out dx, al
    mov al, 01h
    mov dx, icw4
    out dx, al
    mov al, 00h
    mov dx, ocw1
    out dx, al
    mov cx, 0fffh

    mov dx, seg data
    mov ds, dx
    mov dx, seg stk
    mov ss, dx
    
    ;初始化8253
    mov dx, io8253ctl
    mov al, 00110110b   ; 通道0工作方式3 初值50000
    out dx, al
    mov dx, io8253a
    mov ax, 50000
    out dx, al
    mov al, ah
    out dx, al
    mov dx, io8253ctl
    mov al, 01010100b   ; 通道1工作方式2 初值10 只读写低8位
    out dx, al
    mov dx, io8253b
    mov al, 10
    out dx, al
    
    ; 初始化8255
    mov dx,io8255ctl    ;将8255设为A C口输出
    mov al,80h
    out dx,al
    mov dx, io8255a
    mov al, 0
    out dx, al
    mov dx, io8255c
    out dx, al          ;关显示
    
    sti ; 开中断
    
bigloop:
    ; 获取时间 0.5s 触发一次
    call getclk
    dec al
    test al, 255
    jnz nowork
    
    mov al, byte ptr clk
    test al, 255
    jnz oldsec

    mov dx, offset msgclk
    mov ah, 09h
    int 21h
    ; 防止触发多次
    mov byte ptr clk, 1
    
    ; 数码管和LED
    xor ax, ax
    
    mov si,offset dpos
    mov al, byte ptr time
    add si, ax
    mov al, byte ptr [si]
    mov dx, io8255b
    out dx, al
    mov si,offset digits
    mov al, byte ptr time
    add si, ax
    mov al, byte ptr [si]
    mov dx, io8255a
    out dx, al

    mov si,offset led
    mov al, byte ptr time
    add si, ax
    mov al, byte ptr [si]
    mov dx, io8255c
    out dx, al
    
    ; 是否救护车情况
    test byte ptr ambu, 255
    jnz incircle
    
    ; 时间++
    inc byte ptr time
    cmp byte ptr time, 24
    jb incircle
    mov byte ptr time, 0
    
incircle:
    jmp oldsec
nowork:
    mov byte ptr clk, 0
oldsec:
    call readkey
    jnz quit
    call delay100ms
    jmp bigloop

quit:
    mov ah, 4ch
    int 21h

int3:
    cli ;关中断
    mov dx, ocw3
    mov al, 0ah
    out dx, al
    in al, dx
    mov byte ptr intnum, al
    cmp al, 00h
    jz iend
    and al, 03h
    test al, 01h
    jnz itr0
    test al, 02h
    jnz itr1
    jmp iend
itr0:
    mov ax, seg data
    mov ds, ax
    test byte ptr ambu, 255 ; 如果已经在救护车状态则显示已经来到
    jnz hasemb
    mov dx, offset msgint0
    mov ah, 09h
    int 21h
    mov byte ptr ambu, 1
    mov byte ptr time, 24
    jmp enditr0
hasemb:
    mov dx, offset msgint2
    mov ah, 09h
    int 21h
enditr0:
    mov al, intnum
    test al, 02h
    jnz itr1
    jmp iend
itr1:
    mov ax, seg data
    mov ds, ax
    test byte ptr ambu, 255 ; 如果并不在救护车状态则显示无救护车
    jz noemb
    mov dx, offset msgint1
    mov ah, 09h
    int 21h
    mov byte ptr ambu, 0
    mov byte ptr time, 0
    jmp iend
noemb:
    mov dx, offset msgint3
    mov ah, 09h
    int 21h
iend:
    mov al, 20h
    out 20h, al
    jmp next
    in al, 21h
    or al, 08h
    out 21h, al
    ;mov ah, 4ch
    ;int 21h
next:
    sti
    iret    ; 中断返回

readkey proc neer
    ; 读一个键盘
    push dx
    mov ah, 06h
    mov dl, 0ffh
    int 21h
    pop dx
    ret
readkey endp
    
getclk proc near
    ; 读8253b入al
    push dx
    mov dx, io8253b
    in al, dx
    pop dx
    ret
getclk endp

delay100ms proc
    push dx 
    push cx
    push bx
    push ax
    mov bx,04e8h
lp22:
    mov cx,0dbh
lp21:
    pushf
    popf
    loop lp21
    dec bx
    jnz lp22
    pop ax
    pop bx
    pop cx
    pop dx
    ret
delay100ms endp

code ends

end start
