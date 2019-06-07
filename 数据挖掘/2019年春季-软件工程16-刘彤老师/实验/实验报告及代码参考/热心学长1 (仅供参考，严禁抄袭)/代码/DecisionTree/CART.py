from base import DecisionTree
from utils import get_split_choice
import math

class CARTree(DecisionTree):
    def __init__(self):
        super().__init__()

    def attribute_selection_method(self, D, attribute_list):
        def getGini(D):
            """
            获取元组分类的熵
            """

            group = D.groupby(self.get_class_attribute())
            total = len(D)
            #     print([len(x[1]) for x in group1])
            InfoD = 1 - sum([math.pow(len(x[1]) / total, 2) for x in group])
            return InfoD

        def getGiniA(D, attribute):
            """
            获取对属性划分后的熵
            """
            min_gini = (None, tuple())
            values = list(D[attribute].drop_duplicates())
            print(values)
            choices = get_split_choice(values)
            D_size = len(choices)
            for choice in choices:
                gini = 0
                D1_size = len(choice[0])
                D2_size = len(choice[1])
                D1 = D[D[attribute].isin(choice[0])]
                D2 = D[D[attribute].isin(choice[1])]
                gini = (D1_size / D_size) * getGini(D1) + (D2_size / D_size) * getGini(D2)
                if min_gini[0] == None or gini < min_gini[0]:
                    min_gini = (gini, choice)
            return min_gini

        candidate_splitting_criterion = []
        gini_d = getGini(D)
        total = len(D.groupby(self.get_class_attribute()))
        for attribute in attribute_list:
            (gini_a, choice) = getGiniA(D, attribute)
            gain = gini_d - gini_a
            candidate_splitting_criterion.append((gain, attribute, choice))
            # print(gain, attribute)
        splitting_criterion = max(candidate_splitting_criterion, key=lambda item: item[0])[1:]
        print("chose attribute", splitting_criterion)
        return splitting_criterion
    
    def get_surface_err_gains(self, class_field, N, node, queue):
        childs = node.get_all_child()
        child_cnt = len(childs)
        node._child_num = 0
        node._Rt = 0
        if child_cnt:
            RT = 0
            child_num = 0
            for child_node in childs:
                self.get_surface_err_gains(class_field, N, child_node, queue)
                RT += node._Rt
                node._child_num += child_node._child_num
            class_desc = child_node.get_class_description(class_field)
            Rt = min([item[1] for item in class_desc]) / N            
            #Rt = min(class_desc[0][1], class_desc[1][1]) / (class_desc[0][1] + class_desc[1][1]) * ( class_desc[0][1] + class_desc[1][1] / N)
            err_gain = (Rt - RT) / (child_num - 1)
            queue.append((node, err_gain))
            node._child_num = child_num
            node._Rt = RT
        else:
            class_desc = node.get_class_description(class_field)
            Rt = min([item[1] for item in class_desc]) / N
            node._Rt = Rt
            node._child_num = 0

    def pruning_tree(self):
        queue = []
        self.get_surface_err_gains(self.get_class_attribute(), len(self.df), self.tree.get_root(), queue)
        pruned_node = max(queue, key=lambda x: x[1])[0]
        pruned_node.cut_up_childs()
        pruned_node.value = self.get_majority_class(pruned_node.D)

def main():
    tree = CARTree()
    tree.load_csv_data_set("data.csv")
    tree.build()    
    #print(decision_tree.get_json_result())

if __name__ == '__main__':
    main()