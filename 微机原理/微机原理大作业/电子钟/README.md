#   概述
##  <font color='red'>请注意: 分享的目的为了提供问题解决的思路，不是为了抄袭</font>
本代码是计算机科学与技术专业微机原理实验的大作业的电子时钟设计。

软件代码详见clock.asm文件

硬件连线请参照本文档

##  调试tips:
1.由于232机房的微机原理实验箱都过于老旧，所以挑选一个好用的箱子极为重要。
2.如果在使用TPC烧入程序时出现了奇怪的错误，在确定自己程序没有问题以及箱子确实已连接后，重启最优解
3.在编写代码而不需要使用箱子查看结果时，暂时关掉箱子的电源能有一定几率避免烧程序时出现奇怪的错误，但要记得烧程序时别忘记打开电源。
##  本程序未完善之处
1.仅实现24小时时间循环，未实现年月日的进位转换，但在最后答辩时老师指出了这个问题，建议在理解代码逻辑以后对其进行实现，可以简化为每月固定30天，不考虑闰年。如有成功者也欢迎更新本项目
2.代码560行处使用了jmp强制跳转，原因是sing子函数使用ret调用返回时总是返回到奇怪的位置，我并没有找到为什么出现这个BUG，不过现在的写法能正常实现功能，问题不是很大
3.程序有些命名并不规范，还请见谅
#   实验目的
通过完成电子钟的设计，加深对芯片8253，8255，8259的理解，增强编程能力，巩固课内知识。
#   实验设备
8255，8259，8253，七段数码管，与非门，音响及合成部分
#   实验内容
使用8255，8253，8259，LED等器件搭建电子钟。该电子钟具有时、分、秒计时、显示功能，并且通过定义键盘的字母，可对电子钟进行时分秒时间调整。功能可以进一步扩展，包括整点和半点报时、年月的显示、闹钟功能等
#   实验原理
所用芯片的端口：
8259
奇口 2b9H
偶口 2b8H
8253
计数器0 280H
计数器1 281H
计数器2 282H
控制口  283H
8255
a口 288H
b口 289H
c口 28ah
控制口 28bH
#   功能概述
程序实现了在LED显示时分秒以及年月日，按住w和s上下翻页，实现时间，年，月日的显示转换，a设置时间，只支持时分秒设置，格式为XXXXXX，s设置闹钟，格式同上
#   硬件设计概述
首先通过8253计数器0以及计数器1每一秒发出一次信号，具体设计如下
首先，一个定时器在接1MHZ脉冲下最大的定时时间为
65536/(1$\times$10^6)=65.536ms
显然不满足要求
所以采用计数器1与计数器0结合的方式来达到目的	
设置计数器1的计数初值为5000
则其out1输出的脉冲时间为5000/(1$\times$10^6) = 5ms
将out1接到clk0,设计数初值为200
则out0输出的脉冲时间为200$\times$5ms = 1s
通过计数器0发出脉冲，使用8259产生中断，通过8255控制LED以及音响的产生
##  电路图
![picture](https://img-blog.csdnimg.cn/20210719081651647.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzMjYyNTgy,size_16,color_FFFFFF,t_70)
## 流程图
### 主程序流程图                                         
![在这里插入图片描述](https://img-blog.csdnimg.cn/2021071908265721.png)
### 显示函数
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719082737806.png)
### 按键处理程序
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719082809446.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzMjYyNTgy,size_16,color_FFFFFF,t_70)

### 设置时间函数       
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719082836978.png)
### 设置闹钟函数
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719082848968.png)

### 向下翻页程序
![在这里插入图片描述](https://img-blog.csdnimg.cn/2021071908291673.png)   
### 向上翻页子程序
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719082933604.png)
### 判断整时半时程序    
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719082959949.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzMjYyNTgy,size_16,color_FFFFFF,t_70)
                         
### 判断闹钟子程序
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/2021071908301948.png)
### 响铃子程序
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719083037699.png)

#   实验结果
因为数码管为分位显示，手机拍摄的图可能有所残缺。
正常数码管显示
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719101919993.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzMjYyNTgy,size_16,color_FFFFFF,t_70)

按ESC返回
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719101924595.png)
按a键设置时间
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719101932990.png)
此时数码管熄灭
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719101940384.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzMjYyNTgy,size_16,color_FFFFFF,t_70)
设置完后从设定的时间开始走表
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719101950273.png)
在时分秒界面按s键显示月，日
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719101958662.png)
在时分秒界面按w键显示年
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719102005582.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzMjYyNTgy,size_16,color_FFFFFF,t_70)
按d设置闹钟时间
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719102012493.png)
到设定的闹钟时间输出信息并响铃
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719102019389.png)

到整点半点输出信息并响铃
![在这里插入图片描述](https://img-blog.csdnimg.cn/2021071910202436.png)
