def get_subset(nodes):
  """
  二进制子集枚举
  """
  res = []
  for i in range(1 << len(nodes)):
    item = []
    for j in range(len(nodes)):
      if i & (1 << j) :
        item.append(nodes[j])
    res.append(item)
  return res[1:]