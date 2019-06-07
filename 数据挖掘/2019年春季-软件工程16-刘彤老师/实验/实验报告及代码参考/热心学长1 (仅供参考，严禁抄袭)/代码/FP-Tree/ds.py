import copy
class ConditionalPatternBase():
  def __init__(self):
    pass

class NodeLinkListItem:
  def __init__(self, item):
    self.item = item
    self._count = None
    self.nodes = []
  
  def __str__(self):
    return "%s %s" % (str(self.item), str(self.count))

  @property
  def count(self):
      if not  self._count:
        self._count = sum(map(lambda item: item.cnt, self.nodes))
      return self._count

class Node():
  def __init__(self, identify, v, cnt, tree):
    self._tree = tree
    self.v = v
    self.cnt = cnt
    self.identify = identify

  def is_root(self):
    return not self.identify
  def get_child(self):
    if self.identify not in self._tree.edges:
      return []
    return self._tree.edges[self.identify]

  def get_parent(self):
    return self._tree.parents[self.identify]

  def append_child(self, node):
    if self.identify not in self._tree.edges:
      self._tree.edges[self.identify] = []
    self._tree.edges[self.identify].append(node)
    self._tree.parents[node.identify] = self

  def __str__(self):
    return "%s:%d" % (self.v, self.cnt)

class FrequentPattern:
  def __init__(self, u=[], **kwargs):
    self.support_count = kwargs.get("support_count", None)
    self.pattern = []
    self.join(u)

  def __str__(self):
    return "%d %s" % (self.support_count or 0, str(self.pattern))
  
  def _add_frequent_pattern(self, other):
    if other.support_count:
      self.pattern += other.pattern
      self.support_count = min(self.support_count, other.support_count) if self.support_count else other.support_count

  def _add_nodelink_item(self, other):
    self.pattern.append(other.item)
    self.support_count = min(self.support_count, other.count) if self.support_count else other.count
  
  def _add_node_item(self, other):
    self.pattern.append(other.v)
    self.support_count = min(self.support_count, other.cnt) if self.support_count else other.cnt

  def join(self, u):
    if isinstance(u, list):
      for item in u:
        if isinstance(item, Node):
          self._add_node_item(item)
        elif isinstance(item, NodeLinkListItem):
          self._add_nodelink_item(item)
    elif isinstance(u, FrequentPattern):
      self._add_frequent_pattern(u)

  def __or__(self, other):
    #_self = copy.deepcopy(self)
    #_self.pattern.append(other)
    self.join(other)
    return self
    #return _self
