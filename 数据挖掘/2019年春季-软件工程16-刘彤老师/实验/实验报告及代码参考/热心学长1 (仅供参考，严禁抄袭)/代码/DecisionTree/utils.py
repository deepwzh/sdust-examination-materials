import pandas as pd
import numpy as np
def get_split_choice(values):
  """
  二进制子集枚举
  """
  res = []
  for i in range((1 << len(values)) // 2):
    item1 = []
    item2 = []
    for j in range(len(values)):
      if i & (1 << j):
        item1.append(values[j])
      else:
        item2.append(values[j])
    res.append((item1, item2))
  return res[1:]

def shuffle_data_set(D):
  D = D.reindex(np.random.permutation(D.index))
  return D

def divide_dataset(D, percent=0.8):
  data_length = len(D)
  boundary = int(data_length * percent)
  return D[0: boundary], D[boundary:]

def load_csv_data_set(filename):
  return pd.read_csv(filename)