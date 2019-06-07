from base import DecisionTree
import math


class C45Tree(DecisionTree):
    def __init__(self):
        super().__init__()

    def attribute_selection_method(self, D, attribute_list):
        def getInfo(D):
            """
            获取元组分类的熵
            """

            group = D.groupby(self.get_class_attribute())
            total = len(D)
            #     print([len(x[1]) for x in group1])
            InfoD = -sum([len(x[1]) / total * math.log2(len(x[1]) / total) for x in group])
            return InfoD

        def getInfoSubD(D, attribute):
            """
            获取对属性划分后的熵
            """
            info = 0
            group1 = D.groupby(attribute)
            for x in group1:
                #column_name = x[0]
                Dj = x[1]
                property_size = len(Dj)
                info += property_size / (len(group1)) * getInfo(Dj)
            return info

        def getSplitInfoA(D, attribute):
            """
            获取对属性划分后的熵
            """
            split_info = 0
            group1 = D.groupby(attribute)
            D_size = len(group1)
            for x in group1:
                #column_name = x[0]
                Dj = x[1]
                Dj_size = len(Dj)
                split_info += (Dj_size / D_size) * math.log2( Dj_size / D_size)
            return split_info

        candidate_splitting_criterion = []
        InfoD = getInfo(D)
        total = len(D.groupby(self.get_class_attribute()))
        for attribute in attribute_list:
            InfoSubD = getInfoSubD(D, attribute)
            gain = InfoD - InfoSubD
            split_info = getSplitInfoA(D, attribute)
            gain_rate = gain / split_info
            candidate_splitting_criterion.append((gain_rate, attribute))
            print(gain_rate, attribute)
        attribute = max(candidate_splitting_criterion, key=lambda item: item[0])[1]
        splitting_criterion = (attribute, list([item] for item in D[attribute].drop_duplicates()))
        print("chose attribute", splitting_criterion)
        return splitting_criterion


def main():
    tree = C45Tree()
    tree.load_csv_data_set("data.csv")
    tree.build()
    
    #print(decision_tree.get_json_result())
