import collections
from ds import FrequentPattern, NodeLinkListItem, Node
from utils import get_subset
from functools import reduce
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
  # print(count)
  res = []
  for item in count:
    if count[item] >= min_sup:
      res.append([item])
  return res


class Edge():
  def __init__(self):
    self.source = None
    self.target = None
  
class FPTreeBase():
  def __init__(self, *, min_sup):
    self._rank = {}
    self.min_sup = min_sup
    self.nodes = [] # 记录树的节点
    self.edges = {} # 记录树的边
    self.parents = {} # 记录父节点，方便回溯
    self.node_link_list = collections.OrderedDict()
    self.init() # 初始化null根节点

  def create_node(self, value, cnt):
    nodes_length = len(self.nodes)
    node = Node(nodes_length, value, cnt, self)
    self.nodes.append(node)
    return node

  def get_all_node_exclude_root(self):
    return self.nodes[1:]
  
  def init(self):
    self.create_node('null', 0)
    self.parents[0] = None
  
  def insert(self, record):
    pass

  def get_head_table(self):
    return list(self.node_link_list.values())[::-1]
  # def init_node_list(self, itemset):
  #   # 初始化节点链
  #   for item in itemset:
  #     self.node_link_list[item] = 

  def update_node_list(self, node):
    # 更新节点链及其支持度计数
    # print("@@@@@", str(node))
    if node.v not in self.node_link_list:
      self.node_link_list[node.v] = NodeLinkListItem(node.v)
    self.node_link_list[node.v].nodes.append(node)

  def get_sorted_record(self, record):
    return sorted(record, key=lambda x: self._rank[x])

  def get_root(self):
    return self.nodes[0]

  def insert_node(self, item):
    pass
    
  def insert_affair(self, affair):
    items = affair
    root = self.get_root()
    cur_node = root
    common_prefix = True
    for (item, support_count) in items:
      if common_prefix:
        # print(str(cur_node),[str(item) for item in cur_node.get_child()])
        if len(cur_node.get_child()) == 0:
          common_prefix = False
        update_flag = False
        for node in cur_node.get_child():
          if str(node.v) == str(item):
            node.cnt += support_count
            # print("Update %s" % (str(node),))
            cur_node = node
            update_flag = True
            break
      if not update_flag:
        common_prefix = False
      if not common_prefix:        
        node = self.create_node(item, support_count)
        # print("CREATE %d" % (item, ))
        cur_node.append_child(node)
        cur_node = node
        self.update_node_list(node)

  def has_unique_branch(self):
    """
    判断是否只有一个分支
    """
    # 根节点度数为一，即为只有一条边
    return len(self.edges[0]) == 1

class ConditionalFPTree(FPTreeBase):
  def __init__(self, *, min_sup, D = []):
    super().__init__(min_sup=min_sup)
    self.D = D

  def set_conditional_pattern_base(self, D):
    # //list(filter(lambda x: x.support_count >= self.min_sup, D))
    #print([str(item) for item in D])
    self.D = D

  def is_empty(self):
    return not self.D

  def build(self):
    for record in self.D:
      self.insert_affair(list(map(lambda x: (x, record.support_count), record.pattern)))

class FPTree(FPTreeBase):
  """
  FP树的数据结构，0代表根节点
  """
  def __init__(self, *, min_sup):
    super().__init__(min_sup=min_sup)
    self.D = []


  def loads(self, D):
    self.D = D


  def get_inital_frequent_itemset(self, D, min_sup):
    count = Counter()
    for t in D:
      for item in t:
        count.increase(item)
    # print(count)
    res = {}
    for item in count:
      if count[item] >= min_sup:
        res[item] = count[item]
    sorted_items = sorted(res.items(), key=lambda x: -x[1])
    for i in range(len(sorted_items)):
      self._rank[sorted_items[i][0]] = i
    return {key: value for key, value in sorted_items}
    # return itemset

  def build(self):
    self.get_inital_frequent_itemset(self.D, self.min_sup)
    # self.init_node_list(itemset)
    # print(itemset)
    # print(self.node_link_list)
    for record in self.D:
      sorted_record = self.get_sorted_record(record)
      ## 以下是条件FP树与FP树的共同之处
      #print(list(map(lambda x: (x, 1), sorted_record)))
      self.insert_affair(list(map(lambda x: (x, 1), sorted_record)))

def fpGrowth(tree, alpha):
  if tree.has_unique_branch():
    nodes = tree.get_all_node_exclude_root()
    # print([str(r) for r in nodes])
    for node_list in get_subset(nodes):
      beta = FrequentPattern(node_list)
      if beta.support_count >= tree.min_sup:
        beta = beta | alpha
      # print([str(r) for r in node_list])
        print(beta)
  else:
    print(tree.get_head_table())
    for item in tree.get_head_table():
      #print("item %s " % (item))
      #print(alpha)

      # 产生模式beta
      beta = FrequentPattern([item])
      beta = beta | alpha
      print(beta)
      conditional_pattern_base = []
      def get_prefix_path(node):
        path = []
        cur_node = node.get_parent()
        while cur_node and not cur_node.is_root():
          path.insert(0, cur_node)
          cur_node = cur_node.get_parent()
        return path
      
      for node in item.nodes:
        prefix_path = get_prefix_path(node)
        if prefix_path:
          conditional_pattern_base.append(FrequentPattern(prefix_path, support_count=node.cnt))
      #conditional_pattern_base()
      # print([str(item) for item in conditional_pattern_base])
      # print("############")
      if conditional_pattern_base:
        tree_beta = ConditionalFPTree(min_sup=tree.min_sup)
        tree_beta.set_conditional_pattern_base(conditional_pattern_base)
        tree_beta.build()
        fpGrowth(tree_beta, beta)
      # tmp = tree_beta.node_link_list
      # for item0 in tmp.values():
        # print(item0.item, item0.count)
        # print(str([str(i) for i in item0.nodes]))
      #print("####")
def main():
  fptree = FPTree(min_sup=2)
  fptree.loads(data)
  fptree.build()
  # tmp = fptree.node_link_list
  # for item in tmp.values():
  #   print(item.item, item.count)
  #   print(str(item.nodes))
  fpGrowth(fptree, FrequentPattern())
if __name__ == '__main__':
  main()

