import numpy as np

class HMM:
  def __init__(self, pi, A, B, S, V):
    # 初始概率
    self.pi = pi
    # 隐状态概率转移矩阵
    self.A = A
    # 观测状态概率转移矩阵
    self.B = B
    # 隐藏状态数量
    self.N = len(S)
    # 可观测状态数量
    self.M = len(V)

    self.S = S
    self.V = V
    self.S_map = {self.S[i]: i for i in range(len(self.S))}
    self.V_map = {self.V[i]: i for i in range(len(self.V))}

  def get_S_index(self, value):
    return self.S_map[value]

  def get_V_index(self, value):
    return self.V_map[value]

  def _forward_algorithm(self, observation):
    """
    前向算法
    """
    def _forward_vector(self):
      pass
    o = list(map(lambda x: self.get_V_index(x), observation))
    alpha = np.empty((len(observation), self.N))
    # print(alpha)
    T = len(observation)
    # 1.初始化
    for i in range(self.N):
      alpha[0][i] = self.pi[i] * self.B[i, o[0]]
    # 2. 递归处理
    for t in range(1, T):
      for j in range(self.N):
        alpha[t][j] = sum([alpha[t-1][i] * self.A[i][j] for i in range(self.N)]) * self.B[j][o[t]]
    print(alpha)
    # 3. 终结
    lambda_ = sum([alpha[T-1][i] for i in range(self.N)])
    return lambda_


  def evaluation(self, observation):
    """
    HMM第一类问题：评估问题求解
    Parameters
        ----------
        observation : numpy.array
            观测序列值
    """
    return self._forward_algorithm(observation)
  
  def _viterbi(self, observation):
    """
    VITERBI 算法实现
    """
    o = list(map(lambda x: self.get_V_index(x), observation))
    delta = np.empty((len(observation), self.N))
    phi = np.empty((len(observation), self.N), dtype=int)
    # print(alpha)
    T = len(observation)
    # 1.初始化
    for i in range(self.N):
      delta[0][i] = self.pi[i] * self.B[i, o[0]]
      phi[0][i] = 0
    # 2. 递归处理
    for t in range(1, T):
      for j in range(self.N):
        delta[t][j] = np.array([delta[t-1][i]*self.A[i][j] for i in range(self.N)]).max() * self.B[j][o[t]]
        phi[t][j] = np.array([delta[t-1][i]*self.A[i][j] for i in range(self.N)]).argmax()
    print(phi)
    print(delta)
    # 3. 终结
    p_star = delta[T-1].max()
    q_t_star = np.argmax(delta[T-1])
    q_star = q_t_star
    res = []
    res.append(self.S[q_star])

    for t in range(self.N)[::-1]:
      q_star = phi[t+1][q_star]
      res.append(self.S[q_star])
    return res[::-1]

  def decode(self, observation):
    """
    HMM第二类问题：解码问题求解
    Parameters:
        ----------
        observation : numpy.array
            观测序列值
    """
    return self._viterbi(observation)
    
def main():
  # pi = np.array([0.3,0.7])
  # print(pi)
  # A = np.array([[0.1,0.9],[0.8,0.2]])
  # B = np.array([[0.7,0.1,0.2],[0.3,0.5,0.2]])
  pi = np.array([0.2, 0.4, 0.4])
  print(pi)
  A = np.array([[0.5,0.2, 0.3], [0.3, 0.5,0.2], [0.2, 0.3, 0.5]])
  B = np.array([[0.5,0.5],[0.4,0.6], [0.7, 0.3]])
  S = ['1', '2', '3']
  # S = ['吃', '睡']
  # V=["哭", "没精神", "找妈妈"]
  V = ['1', '2']
  hmm = HMM(pi, A, B, S, V)
  observation = np.array(['1', '2', '1'])

  # observation = np.array(['哭', '没精神', '找妈妈'])
  print(hmm.evaluation(observation))



if __name__ == '__main__':
  main()
