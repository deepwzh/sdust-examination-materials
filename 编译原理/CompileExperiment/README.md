#   编译原理实验
#   使用本工程前, 请务必阅读完本工程说明(~~你们都不读说明书的吗?~~)
#   说明: 本文档并非面向提交给教师的工程说明, 仅可以作为使用该工程的学生的简单参考.
#   如果想编写一份作为作业提交的说明报告, 请另行起草!!!
#   还有一件事:这是一个Markdown文件, 是有格式的!是不能直接粘贴到Word里去的!!!

工程文件结构
```tree
CompileExperiment
├─.idea
├─cmake-build-debug/        该文件夹为CMake的输出文件夹. 导入至Clion时会自动扫描
├─Experiment1               实验一代码
│  ├─out                    这群文件夹其实都挺没用的...
│  ├─parser
│  └─word
├─Experiment2               实验二代码
├─Experiment3               实验三工程及其代码
│  ├─header
│  └─src
├─Experiment4               实验四代码
│  ├─header
│  └─src
├─src                       本来打算写一个文法持久化的算法来着...最后没实现..
└─UnxUtils
    ├─bin
    └─usr
        └─local
            ├─include
            ├─lib
            ├─share
            └─wbin
```

##  工程使用说明

~~本说明并非可以提交给教师的版本, 故会写的相对轻松且乱七八糟~~

使用前, 请在电脑中安装Parser Generator, 并随之修改CMakeList.txt中的内容.

使用2019版本以上的CLion打开工程文件, Clion自动扫描Cmake文件后会自动创建构建树.

注: 由于实验二中笔者对Lex/yacc学习不够深入. 因此仅一定程度的配置了CMake的构建环境. 尚未完全完成自动化构建.

CLion中有yacc的编写插件, 可以对.y文件进行高亮显示.

**如果可以, 请继续补充并完善实验二中LEX与YACC的内容**

环境: C++11, C++14(MinGW并在CLion导入工程时选择C++11即可) CMake(构建环境)

##  配置说明

在使用此工程前, 请务必安装CLion(默认2018以上版本). Clion是一个非常优秀的C/C++IDE, 配合着强大的跨平台构建工具CMake, 你几乎可以在任何平台(windows/linux/mac)构建你的工程!

当然, CLion作为Jetbrain公司出品的一款IDE, 自然也继承了IDEA的优秀的界面风格与令人舒适的编写体验. 在CLion中编写C++代码本身就是一件享受.

~~好了我吹完了~~

###  准备工作:

1.  下载并安装CLion, [CLion的jb官网](https://www.jetbrains.com/clion/)
2.  如果你想长期使用CLion, 请到官网申请一个账号, 并随之申请一个学生账号(至少可以让你用到大四毕业), 或者使用你想用的破解方式(后果自负), 不差钱买一套也行(一套一年才300多, 值的要死)
3.  安装并配置MINGW, 请务必记住你的MINGW的位置
4.  在CLion中配置MINGW
5.  在CLion中导入此工程, 并选择C++11/C++14版本(lambda和auto万岁!)
6.  等待CLion自动扫描工程中的文件, 这段时间你可以去喝杯水.
7.  点击右上角的构建(图标是个小锤子)
8.  正常来讲, 已经可以用了.

### 常见报错:
1.  CMake环境出错, 找不到CMake: 配一个CMake
2.  MINGW版本有问题: 重新配一个MINGW
3.  语法错误: 自己改改, 要么就是你用了C++03(要不然我怎么编译通过的?)
4.  CMake报错, 缺少库: 这个应该是实验二的常见错误. 解决方案1: 把实验二中的CMakeLists.txt中东西该注释的注释, 先编译成功再说. 解决方案2: 在电脑上安个Paser Generator, 然后把相关的库连接过去.
5.  其他错误: 百度, bing, google, stackoverflow, 给学长发邮件sumover@foxmail.com, 或者去(学长的gitee)[https://gitee.com/sumoverGitee/sdust-examination-materials]评论区底下发评论顺便Fork+Star

##  输入说明:

由于ASCII中没有希腊字母"ε"因此我们用$代替之.

仍然使用#来代替解析字符串的结束.

##  关于重定向输入&输出乱码

CLion很贴心的给我们准备了重定向输入的功能, 顺便解决了中文乱码的问题.(毕竟工程的文件的编码都是固定的)

1.  右上角有几个小符号(构建, 运行, 调试那几个), 有一个下拉框, 点击Edit Configurations.
2.  选择一个你想要设置的工程, 右侧有一个Redirect input from, 打上勾, 然后选择你要重定向输入的文件.

感兴趣的话可以仔细研究一下这个地方. IDE的自动化构建等就是在这儿进行的.

如果你不想重定向输入:
~~真的会有人不想吗~~

通常来讲, 我们是点击那个小三角并直接运行的, 如果你不想Run, 那么你可以选择调试模式, 一般来讲, RUN的时候乱码的字符在debug的时候都不会乱码.

**在debug之前, 如果你不想一步步跳着走的话, 请务必把所有的breakpoint删掉!**

如果这样还是乱码的话, 建议百度或者把工程里面所有汉字自己敲一遍.


#   详细实验使用说明

### 实验1使用说明

将待输入的文件写入Experiment1/input

打开"Experiment1\main.cpp", 并点击第 13行左侧的三角箭头运行.
在Run中即可查看输出.

样例输入
```text
int main() {
    int a,b;
    int c=100;
    double r=1;
    int d=a+b;
}
```

样例输出

```text
"D:\Compilation principle\CompileExperiment\cmake-build-debug\Experiment1\Experiment1.exe"

************
待输入的字符串为:
int main() {
    int a,b;
    int c=100;
    double r=1;
    int d=a+b;
}
************
(2,"int")	(0," ")	(2,"main")	(5,"(")	(5,")")	(0," ")	(5,"{")	(0,"\n")	(0," ")	(0," ")	(0," ")	(0," ")	(2,"int")	(0," ")	(2,"a")	(5,",")	(2,"b")	(5,";")	(0,"\n")	(0," ")	(0," ")	(0," ")	(0," ")	(2,"int")	(0," ")	(2,"c")	(4,"=")	(3,"100")	(5,";")	(0,"\n")	(0," ")	(0," ")	(0," ")	(0," ")	(2,"double")	(0," ")	(2,"r")	(4,"=")	(3,"1")	(5,";")	(0,"\n")	(0," ")	(0," ")	(0," ")	(0," ")	(2,"int")	(0," ")	(2,"d")	(4,"=")	(2,"a")	(4,"+")	(2,"b")	(5,";")	(0,"\n")	(5,"}")	parse success!
Process finished with exit code 0

```

### 实验2使用说明

实验2中的环境配置问题说明:

笔者实在是不想看vc++那个上古~~垃圾~~界面. 因此笔者选择了BISON和FLEX.

如果不想在电脑中配置一个BISON/FLEX环境, 可以仅仅对CLion的Terminal配置一个.

配置方法:

1.  按Ctrl+Alt+S(或者打开Setting)
2.  搜索框中输入Terminal(一般输入Termi就能出来), 选择Tool->Terminal
3.  点击编辑Environment Variables, 然后像配置Java环境那样配置之.


该文法仅简单实现了C语言中的简单表达式. 故我们仅可以对简单表达式进行解析.

将待解析的字符串写入Experiment2/input
打开Experiment2/yacc.tab.c, 并点击第954行左侧的三角箭头运行


样例输入

```text
1+3*5
3*4-233
7-9*30-999
7-9*30-(999

```

样例输出

```text
"D:\Compilation principle\CompileExperiment\cmake-build-debug\Experiment2\Experiment2.exe"
16
-221
-1262
missing ')'-1262

Process finished with exit code 0
```

### 实验3使用说明

将待输入的文件写入至Experiment3\GRAMMER_IN
打开Experiment3\main.cpp,并点击200行左侧的三角箭头运行
在run中查看输出

样例输入

```text
i+i*i#
```

样例输出

```text
"D:\Compilation principle\CompileExperiment\cmake-build-debug\Experiment3\Experiment3.exe"
GRAMMER	FIRST	FELLOW
E->TG	( i 	#
G->+TG	+ 	#
G->-TG	- 	#
G->$	$ 	#
T->FS	( i 	+ - #
S->*FS	* 	+ - #
S->/FS	/ 	+ - #
S->$	$ 	+ - #
F->(E)	( 	* / + - #
F->i	i 	* / + - #
编制人: sumover 201701061100 2017级软件工程三班
输入待解析的字符串.(以#结束)
待解析的字符串为"i+i*i#"
start parsing....
解析成功!待解析字符串`i+i*i#`是符合文法的字符串

Process finished with exit code 0
```


### 实验4使用说明

将待输入的文件写入至Experiment4\input
打开Experiment4\main.cpp,并点击236行左侧的三角箭头运行
在run中查看输出

**本实验的输出实际上是有一定的格式问题的, 但是我实在是懒得改了, 有心的同学可以想办法自己整一下**

样例输入

```text
i+i*(i+i*i)+i#
```

样例输出

```text
"D:\Compilation principle\CompileExperiment\cmake-build-debug\Experiment4\Experiment4.exe"
GRAMMER		FIRST	FELLOW
E->TG		( i 		#
G->+TG		+ 		#
G->-TG		- 		#
G->$		$ 		#
T->FS		( i 		+ - #
S->*FS		* 		+ - #
S->/FS		/ 		+ - #
S->$		$ 		+ - #
F->(E)		( 		* / + - #
F->i		i 		* / + - #
编制人: sumover 201701061100 2017级软件工程三班
输入待解析的字符串.(以#结束)
待解析的字符串为"i+i*(i+i*i)+i#"
start parsing....
步骤		分析栈	剩余子串		产生式
1		#GT		i+i*(i+i*i)+i#		E->TG
2		#GSF		i+i*(i+i*i)+i#		T->FS
3		#GSi		i+i*(i+i*i)+i#		F->i
4		#GT+		+i*(i+i*i)+i#		G->+TG
5		#GSF		i*(i+i*i)+i#		T->FS
6		#GSi		i*(i+i*i)+i#		F->i
7		#GSF*		*(i+i*i)+i#		S->*FS
8		#GS)E(		(i+i*i)+i#		F->(E)
9		#GS)GT		i+i*i)+i#		E->TG
10		#GS)GSF		i+i*i)+i#		T->FS
11		#GS)GSi		i+i*i)+i#		F->i
12		#GS)GT+		+i*i)+i#		G->+TG
13		#GS)GSF		i*i)+i#		T->FS
14		#GS)GSi		i*i)+i#		F->i
15		#GS)GSF*		*i)+i#		S->*FS
16		#GS)GSi		i)+i#		F->i
17		#GS)G		)+i#		S->$
18		#GS)		)+i#		G->$
19		#GT+		+i#		G->+TG
20		#GSF		i#		T->FS
21		#GSi		i#		F->i
22		#		#		G->$
解析成功!待解析字符串`i+i*(i+i*i)+i#`是符合文法的字符串

Process finished with exit code 0
```
