from base import DecisionTree
import math

class ID3Tree(DecisionTree):
    def __init__(self):
        super().__init__()

    def attribute_selection_method(self, D, attribute_list):
        def getInfo(D):
            group = D.groupby(self.get_class_attribute())
            total = len(D)
            #     print([len(x[1]) for x in group1])
            InfoD = -sum([len(x[1]) / total * math.log2(len(x[1]) / total) for x in group])
            return InfoD

        candidate_splitting_criterion = []
        InfoD = getInfo(D)
        total = len(D.groupby(self.get_class_attribute()))
        for attribute in attribute_list:
            group1 = D.groupby(attribute)
            InfoageD = 0
            for x in group1:
                column_name = x[0]
                cdf = x[1]
                property_size = len(cdf)
                #             print(property_size)
                #             print(column_name)
                #             print(cdf)
                InfoageD += property_size / (len(group1)) * getInfo(cdf)
            #         print(InfoageD)
            gain = InfoD - InfoageD
            candidate_splitting_criterion.append((gain, attribute))
            print(gain, attribute)
        attribute = max(candidate_splitting_criterion, key=lambda item: item[0])[1]
        splitting_criterion = (attribute, list([item] for item in D[attribute].drop_duplicates()))
        print("chose attribute", splitting_criterion)
        return splitting_criterion

def main():
    id3_tree = ID3Tree()
    id3.load_csv_data_set("data.csv")
    id3.build()
    
    #print(decision_tree.get_json_result())


if __name__ == '__main__':
    main()