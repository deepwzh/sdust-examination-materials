data = [
  [1,2,5],
  [2,4],
  [2,3],
  [1,2,4],
  [1,3],
  [2,3],
  [1,3],
  [1,2,3,5],
  [1,2,3]
]

def apriori_gen(L):
  Ck = []
  for l1 in L:
    for l2 in L:
      # print(l1, l2)
      if l1[: -1] == l2[: -1] and l1[-1] < l2[-1]:
        c = l1 + [l2[-1]]
        # print(c)
        # connent
        if has_infrequent_subset(c, L):
          pass
          # delete c
        else:
          Ck.append(c)
  return Ck

def n_1_subset(c):
  return [(c[0: i] + c[i + 1: ]) for i in range(len(c))]
  
def has_infrequent_subset(c, L):
  for s in n_1_subset(c):
    # print("#", s, L)
    if s not in L:
      return True
  return False

class Counter:
  """
  辅助类：计数器类
  """
  def __init__(self):
    self.data = {}

  def increase(self, name):
    if name not in self.data:
      self.data[name] = 1
    else:
      self.data[name] += 1
  
  def __iter__(self):
      return iter(sorted(self.data.keys()))

  def __getitem__(self, name):
    try:
      return self.data[name]
    except KeyError:
      return 0

  def __str__(self):
    return str(dict(sorted((k,self.data[k]) for k in sorted(self.data.keys()))))

def find_frequent_1_itemsets(D, min_sup):
  """
  find frequent 1 itemsets
  """
  count = Counter()
  for t in D:
    for item in t:
      count.increase(item)
  print(count)
  res = []
  for item in count:
    if count[item] >= min_sup:
      res.append([item])
  return res

def subset(Ck, t):
  # res = []
  st = set(t)

  def is_in_Ck(item):
    for c in item:
      if c not in st:
        return False
    return True

  return list(filter(lambda item: is_in_Ck(item), Ck))

def aprior(D, min_sup):
  L = [0]
  # find out frequent 1 itemsets
  L[0] = find_frequent_1_itemsets(D, min_sup)
  # print(L[0])
  # k = 2
  while L[-1]:
    Ck = apriori_gen(L[-1])
    # print(Ck)
    count = Counter()
    for t in D:
      Ct = subset(Ck, t)
      # print(Ct)
      # print("#")
      for c in Ct:
        count.increase(tuple(c))
    # print(count)
    Lk = list(filter(lambda x: count[tuple(x)] >= min_sup, Ck))
    # print(Lk)
    L.append(Lk)
  return [item for item in L[:-1]]

if __name__ == '__main__':
  res = aprior(data, 2)
  print(res)
