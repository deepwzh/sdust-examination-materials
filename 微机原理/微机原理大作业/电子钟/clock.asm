;***************************************
; Name: E-CLOCK
; Author: BHLL
; Date: 2021-5-27
;***************************************
data segment
    io8255c       equ 28ah ; 1010 8255 c口 输出位码
    io8255b       equ 289h   ;1001 8255 b口 控制扬声器
    io8255a       equ 288h ; 1000 8255 a口 输出段码
    io8255contorl equ 28bh; 1011 8255控制口
	
    cs8259odd     equ 2b9H;     8259奇口
    cs8259even    equ 2b8H;      8259偶口
	
    io8253control equ 283h;     8253控制口
    io8253_0       equ 280h;     8253计数器0
    io8253_1       equ 281h;     8253计数器1
    io8253_2       equ 282h;     8253计数器2
    led    db 3fh,06h,5bh, 4fh,66h,6dh,7dh,07h,7fh,6fh;段码
    count0          db 0C8H
    count1          dw  1388H
    hour             equ 04H;偏移量
    minute           equ 05H
    second           equ 06H
    bz      dw        ?;
    bw      dw        ?;位码
    led_wei db 1fH,2FH,37H,3BH,3DH,3EH
    show_time db 00H,00H,00H
    show_type db 02H;显示时间类型 0-年 1-月日 2-时分秒
    ;提示信息段
    linefeed db 0dh,0ah,'$';换行符
    input_time db 'please input time like xxxxxx!',0dh,0ah,'$'
    
    
data ends
code segment
    assume cs:code,ds:data
;***************************************
; 
; 初始化芯片
; 
;***************************************
open_int macro; 开中断
    push ax
    in al,21h
    and al,0f7h
    out 21h,al
    pop ax
endm
close_int macro; 屏蔽中断
    push ax
    in al,21h
    or al,08h
    out 21h,al
    pop ax
endm
start:  
    mov ax,data
    mov ds,ax
    ;8255
    mov dx,io8255contorl;
    mov al,80h; 1000 0000 设置A B C口输出 
    out dx,al
    ;8253
    ;计数器0
    mov dx,io8253control
    mov al,14H    ;00 01 010 0 计数器0 只写低八位 工作方式2 二进制
    out dx,al
    mov dx,io8253_0
    mov al, count0
    out dx,al
    ;计数器1
    mov dx,io8253control
    mov al, 74H    ;;01 11 010 0 计数器1 先写低八位，后写高八位 工作方式2 二进制
    out dx,al
    mov dx,io8253_1
    mov ax ,count1
    out dx , al
    mov al ,ah
    out dx,al
    ;计数器2
    mov dx,io8253control
    mov al,0B6H ;10 11 011 0 计数器2 先写低八位，后写高八位 工作方式3 二进制
    out dx,al
    
    mov ax,046AH
    mov dx,io8253_2
    out dx,al
    mov al,ah
    out dx,al
    ;8259
    ;设置中断
     
 mov dx,cs8259even;ICW1
    mov al, 12H ;000 1 0 0 1 0 边沿触发 多片 不设置ICW4 
    out dx, al
    mov dx,cs8259odd;ICW2
    mov al, 40H;10001 000 高五位特性  IR0
    out dx,al
    ;mov al,08h;奇地址 0000 1000  IR3
    ;out dx,al
    ;mov al,11h;0001 0001 特殊全嵌套 非缓冲方式 从片 中断非自动结束 8086
    ;out dx,al

    ;0cw1
    mov al,0d6h;1101 0110
    out dx,al
    ;ocw2
    mov al,20h; 0 0 1 0 0000 优先级固定 l2-l0无效 使ISR中相应位为0 
    mov dx,cs8259even
    out dx,al
    
    mov ax,cs
    mov ds,ax
    mov dx,offset int3
    mov ax,250bh;
    int 21h
    mov ax, 0H
    mov es, ax

    ;设置年月日的存储位置和初值
    mov bx, 0200h;
    mov byte ptr es:[bx+0],2H
    mov byte ptr es:[bx+1],0H
    mov byte ptr es:[bx+2],2H
    mov byte ptr es:[bx+3],1H
    mov byte ptr es:[bx+4],0H
    mov byte ptr es:[bx+5],5H
    mov byte ptr es:[bx+6],2H
    mov byte ptr es:[bx+7],8H
    mov byte ptr es:[bx+8],0H;hh
    mov byte ptr es:[bx+9],0H;hl
    mov byte ptr es:[bx+10],0h;mh
    mov byte ptr es:[bx+11],0H;ml
    mov byte ptr es:[bx+12],0H;sh
    mov byte ptr es:[bx+13],0H;sl
    mov byte ptr es:[bx+14],0H;Ahh
    mov byte ptr es:[bx+15],0H;Ahl
    mov byte ptr es:[bx+16],0h;Amh
    mov byte ptr es:[bx+17],0H;Aml
    mov byte ptr es:[bx+18],0H;Ash
    mov byte ptr es:[bx+19],1H;Asl

    mov ax,data
    mov ds,ax
    mov bx,offset show_time
    mov [bx+0], 0207H
    mov byte ptr[bx+2], 06H
    open_int

ll: ;时钟显示
    cli
    call displaytime
   ; jmp SET_ALARM
    sti
    mov ah,01h
    int 16h
    jz backTOll
    mov ah ,00h
    int 16h
    cmp al,27;esc
    je exit
    cmp al,61h;a
    je SET_TIME
    cmp al, 77H;w
    je ADD_TYPE
    cmp al,73h;s
    je SUB_TYPE
    cmp al,64H;d
    je SET_ALARM
backTOll:
    open_int
    jmp ll
SET_ALARM:
    close_int
    call setAlarmTime
    open_int
    jmp ll
SET_TIME:
    close_int
    call setTime
    open_int
    jmp ll
ADD_TYPE:
    close_int
    call add_show_type
    call set_show_time
    open_int
    jmp ll
SUB_TYPE:
    close_int
    call sub_show_type
    call set_show_time
    open_int
    jmp ll
exit:
    mov dx,io8255a
    mov al,0
    out dx,al
    mov ah,4ch
    int 21h
;子程序段
setAlarmTime proc near
    push dx
    push ax
    push cx
    push bx
    close_int
    mov dx,io8255a
    mov al, 0
    out dx,al
    mov dx,offset linefeed
    mov ah,09
    int 21h
    mov dx,offset input_time
    mov ah,09
    int 21h
    xor dx,dx
    mov bx,20eH
str2:
    mov ah,1
    int 21h
    cmp al,13
je return_sub2
    jmp save2
    
save2:
    sub al,30H
    mov byte ptr es:[bx],al
    inc bx
    inc dx
nextstr2:
    jmp str2
return_sub2:
    mov dx,offset linefeed
    mov ah,09
    int 21h
    pop bx
    pop cx
    pop ax
    pop dx
    sti
    ret
setAlarmTime endp
set_show_time proc near
    push ax
    push bx
    mov bx, offset show_type
    mov al,byte ptr [bx]
    mov bx, offset show_time
    cmp al,00
    je type0
    cmp al,01
    je type1
    cmp al,02
    je type3
end_set_show_time:
    pop bx
    pop ax
    ret
type0:
    mov word ptr[bx],1FFH
    mov byte ptr[bx+2],4H
    jmp end_set_show_time
type1:
    mov word ptr[bx],0203H
    mov byte ptr[bx+2],4H
    jmp end_set_show_time
type3:
    mov word ptr[bx],207H
    mov byte ptr[bx+2],6H
    jmp end_set_show_time
set_show_time endp
;SUB_TYPE
sub_show_type proc near
    
    push ax
    push bx
    mov di, offset show_type
    mov bl,byte ptr[di]
    add bl,03H
    dec bl
    xor ax,ax
    mov al,bl
    mov bl,03H
    div bl
    mov bx ,offset show_type
    mov byte ptr [bx],ah 
    pop bx
    pop ax
    ret
sub_show_type endp
;ADD_TYPE
add_show_type proc near
    
    push ax
    push bx
    mov di, offset show_type
    mov bl,byte ptr [di]
    inc bl
    xor ax,ax
    mov al,bl
    mov bl,03H
    div bl
    mov bx, offset show_type
    mov byte ptr [bx],ah
    pop bx
    pop ax
    ret
add_show_type endp
;设置时间子程序
setTime proc near
;清除显示
    push dx
    push ax
    push cx
    push bx
    close_int
    mov dx,io8255a
    mov al, 0
    out dx,al
    mov dx,offset linefeed
    mov ah,09
    int 21h
    mov dx,offset input_time
    mov ah,09
    int 21h
    xor dx,dx
    mov bx,208H
str1:
    mov ah,1
    int 21h
    cmp al,13
je return_sub
    jmp save
    
save:
    sub al,30H
    mov byte ptr es:[bx],al
    inc bx
    inc dx
nextstr:
    jmp str1
return_sub:
    mov dx,offset linefeed
    mov ah,09
    int 21h
    pop bx
    pop cx
    pop ax
    pop dx
    sti
    ret
setTime endp    
;时钟显示子程序
displaytime proc near
;
     close_int
;
    mov cx,009h
    loop2:
     mov si,offset show_time 
    mov bh,[si+2]
    lll: mov byte ptr bz,bh
            push bx
            mov bx,offset show_time
            mov di,[bx]
            pop bx
            mov bl,offset led_wei
                        
            add di,bz
            mov bl,es:[di]
            mov bh,0
            mov si, offset led
            add si,bx
            
            mov dx,io8255a
            mov al, 0
            out dx,al
            
            mov di,offset led_wei
            mov al,byte ptr bz
            dec al
            mov ah,0
            add di,ax
            mov al, [di]
            mov dx,io8255c
            out dx,al
            mov al,byte ptr [si]
            mov dx,io8255a
            out dx,al
            push cx
            mov cx, 01h
    delay:
            push cx
            mov cx,0fffh
    delay2: 
            loop delay2
            pop cx
            loop delay
            pop cx
            mov bh,byte ptr bz
            dec bh
            cmp bh,0
            jne lll 
            loop loop2
    call judge1
    call judge2
     open_int
   ;
    ret
displaytime endp
;中断子程序
int3:
    ;cli
   ; push bx
    ;push ax
     push cx
    ; ax,0H
    mov cl,es:[200H+13]
    cmp cl, 9H
    je S1
    ;cl不为9,不会产生进位,自增一写回
    inc cl
    mov es:[200H+13],cl
    jmp end_int 
S1:
    ;cl为9，则秒个位置零
    mov byte ptr es:[200H+13],0h
    mov cl,es:[200h+12]
    cmp cl, 5h
    je S2
    inc cl
    mov es:[200H+12],cl
    jmp end_int
S2: 
    ;当前为59秒，下一秒为00
    mov byte ptr es:[200H+12],0H 
    ;取分钟个位
    mov cl,es:[200H+11]
    cmp cl, 9H
    je S3
    ;cl不为9,不会产生进位,自增一写回
    inc cl
    mov es:[200H+11],cl
    jmp end_int 
S3:
    ;cl为9，则分个位置零
    mov byte ptr es:[200h+11],0H
    mov cl,es:[200H+10]
    cmp cl, 5H
    je S4
    inc cl
    mov es:[200H+10],cl
    jmp end_int
S4:
    ;当前为59分，下一秒为00
    mov byte ptr es:[200H+10],00H 
    ;取时十位:
    mov cl,es:[200H+8]
    cmp cl,2H
    je S6
    mov cl,es:[200H+9]
    cmp cl ,9H
    je S5
    inc cl
    mov es:[200H+9],cl
    jmp end_int
S5:
    ;
    mov byte ptr es:[200h+9],0H
    mov cl, es:[200h+8]
    ;十位小于2，直接加10H写回
    inc cl
    mov es:[200h+8],cl
    jmp end_int
S6:
    mov cl, es:[200h+9]
    cmp cl, 3H
    je S7
    inc cl
    mov es:[200h+9],cl
    jmp end_int
S7:
    mov byte ptr es:[200h+9],0H
    mov byte ptr es:[200h+8],0H
    jmp end_int
end_int:
    mov al,20h
    out 20h,al
    pop cx
    ;cli
    ;call displaytime
    ;call judge
   ; mov ah ,01h
    ;int 21h
    sti

    ;pop ax
    ;pop bx
    ;sti

    iret
;判断是否有半时整时
judge1 proc near
push bx
push ax
    mov bx,13
    mov al,es:[200H+bx];sl
    cmp al,5
    jne return_judge1
    dec bx
    mov al,es:[200H+bx];sh
    cmp al,00
    jne return_judge1
    dec bx
    mov al,es:[200H+bx];ml
    cmp al,0
    jne return_judge1
    dec bx
    mov al,es:[200H+bx];mh
    cmp al,3
    je sing
    cmp al,0
    je sing
return_judge1:
pop ax
pop bx
ret
judge1 endp
judge2 proc near
    push bx
    push cx
    push ax
    mov bx ,208H
    mov cx,06H
check_time:
    mov ah,es:[bx]
    mov al,es:[bx+6]
    cmp ah, al
    jne return_judge2
    inc bx
    loop check_time
    call sing2
return_judge2:
    pop ax
    pop cx
    pop bx
    ret
judge2 endp
sing proc near
    
    mov dx,io8255b
    mov al,03h
    out dx,al
    call sing_delay
    mov al ,00h
    out dx,al
    ;ret
    jmp return_judge1
sing endp
sing2 proc near
    
    mov dx,io8255b
    mov al,03h
    out dx,al
    call sing_delay
    mov al ,00h
    out dx,al
    ret
sing2 endp
sing_delay proc near          ;延时子程序
    push cx
    push ax
    mov ax,15
x1: mov cx,0ffffh
x2: dec cx
    jnz x2
    dec ax
    jnz x1
    pop ax
    pop cx
    ret
sing_delay endp
code ends
    end start