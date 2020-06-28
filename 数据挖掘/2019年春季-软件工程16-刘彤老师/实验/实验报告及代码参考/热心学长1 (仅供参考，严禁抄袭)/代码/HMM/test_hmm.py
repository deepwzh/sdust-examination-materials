from HMM import HMM
import unittest
import numpy as np

class HMMTest(unittest.TestCase):
    def setUp(self):
      pass

    def tearDown(self):
        pass

    def test_decode_assignment(self):
      pi = np.array([0.3,0.7])
      print(pi)
      A = np.array([[0.1,0.9],[0.8,0.2]])
      B = np.array([[0.7,0.1,0.2],[0.3,0.5,0.2]])
      S = ['吃', '睡']
      V=["哭", "没精神", "找妈妈"]
      hmm = HMM(pi, A, B, S, V)
      observation = np.array(['哭', '没精神', '找妈妈'])
      res = hmm.decode(observation)
      print(res)
      self.assertEqual(res, ['吃', '睡', '吃'])
      # self.assertAlmostEqual(res, 0.026880000000000005)

    def test_evalution_assignment(self):
      pi = np.array([0.3,0.7])
      print(pi)
      A = np.array([[0.1,0.9],[0.8,0.2]])
      B = np.array([[0.7,0.1,0.2],[0.3,0.5,0.2]])
      S = ['吃', '睡']
      V=["哭", "没精神", "找妈妈"]
      hmm = HMM(pi, A, B, S, V)
      observation = np.array(['哭', '没精神', '找妈妈'])
      res = hmm.evaluation(observation)
      print(res)
      self.assertAlmostEqual(res, 0.026880000000000005)
    def test_decode_ppt(self):
      """
      """
      pi = np.array([1, 0, 0])
      print(pi)
      A = np.array([[0.4, 0.6, 0],
                    [0, 0.8, 0.2],
                    [0, 0, 1.0]])
      B = np.array([[0.7, 0.3],
                    [0.4, 0.6],
                    [0.8, 0.2]])
      S = ['1', '2', '3']
      V=["A", "B"]
      hmm = HMM(pi, A, B, S, V)
      observation = np.array(['A', 'B', 'A', 'B'])
      res = hmm.decode(observation)
      print(res)
      self.assertEqual(res, ['1', '2', '2', '2'])

    def test_decode_weather(self):
      """
      dataset source: https://www.cnblogs.com/Denise-hzf/p/6612212.html
      """
      pi = np.array([0.63, 0.17, 0.20])
      print(pi)
      A = np.array([[0.5, 0.375, 0.125],
                    [0.25, 0.125, 0.652],
                    [0.25, 0.375, 0.375]])
      B = np.array([[0.6, 0.2, 0.15, 0.05],
                    [0.25, 0.25, 0.25, 0.25],
                    [0.05, 0.10, 0.35, 0.5]])
      S = ['Sunny', 'Cloudy', 'Rainy']
      V=["Dry", "Dryish", "Damp", "Soggy"]
      hmm = HMM(pi, A, B, S, V)
      observation = np.array(['Dry', 'Damp', 'Soggy'])
      res = hmm.decode(observation)
      print(res)
      # self.assertAlmostEqual(res, 0.026880000000000005)


    def test_1(self):
      pi = np.array([0.2, 0.4, 0.4])
      print(pi)
      A = np.array([[0.5,0.2, 0.3], [0.3, 0.5,0.2], [0.2, 0.3, 0.5]])
      B = np.array([[0.5,0.5],[0.4,0.6], [0.7, 0.3]])
      S = ['1', '2', '3']
      V = ['1', '2']
      hmm = HMM(pi, A, B, S, V)
      observation = np.array(['1', '2', '1'])
      res = hmm.evaluation(observation)
      print(res)
      self.assertAlmostEqual(res, 0.130218)

if __name__ == '__main__':
  unittest.main()