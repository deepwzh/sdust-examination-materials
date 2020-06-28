# 代码说明

<https://github.com/deepwzh/course-design-of-data-mining/tree/algorithm>

## 1. 实验1 Aporio

代码位于`aprior.py`文件下，输入数据位于代码第一行`data`列表中

## 2. 实验2 FP树

FP数代码位于FP-Tree目录下

`ds.py` 包含所需的基础的数据结构

`FP-Tree.py`是关键实现代码

`utils.py`是包含一些工具函数

`test_xx.py`是对应的测试文件

得运行结果，直接

`python FP-Tree.py`

运行即可

## 3. 实验3，4 ID3, C4.5,CART决策树

决策树代码位于DecisionTree目录下，

`base.py`是所有决策树的共有基类方法

`CART.py`, `ID3.py`, `C4.5.py`分别是其对应的实现

`utils.py`包含一些工具函数

`test_xx.py`是他们的测试文件

代码还包含相应的Web实现，具体见`Web`目录

## 5. 实验5 HMM

HMM代码位于HMM目录下

`HMM.py`是算法实现

`test_hmm.py`是测试文件，其中**test_decode_assignment**，**test_evalution_assignment** 分别对应解码问题和，评估问题的测试