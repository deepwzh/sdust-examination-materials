# coding=utf-8
#1.先设置编码，utf-8可支持中英文，如上，一般放在第一行

#2.注释：包括记录创建时间，创建人，项目名称。
'''
Created on 2016-7-27
@author: Jennifer
Project:使用unittest框架编写测试用例思路
'''
#3.导入unittest模块

import unittest

from ds import FrequentPattern
class TestFrequentPattern(unittest.TestCase): 
    
  def setUp(self):
    self.fp = FrequentPattern()
  
  def test_or(self):
    self.fp | "1"
    self.assertEqual(self.fp.pattern, ["1"], msg='Your input is not 10')

  @unittest.skip('暂时跳过用例3的测试')
  def test_case3(self):
    pass
    
  def tearDown(self):
    pass

if __name__=='__main__':
  unittest.main()