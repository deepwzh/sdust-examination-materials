from ID3 import ID3Tree
from utils import load_csv_data_set, divide_dataset, shuffle_data_set
import unittest

class TestID3Dict(unittest.TestCase):
    def setUp(self):
        self.decision_tree = ID3Tree()
                #print(self.decision_tree.get_json_result())

    def tearDown(self):
        pass

    def test_car_scale(self):
        D = load_csv_data_set("dataset/car.csv")
        D = shuffle_data_set(D)
        training_data, test_data = divide_dataset(D)
        print(training_data)
        self.decision_tree.load_data_set(training_data)
        self.decision_tree.build()
        # print(test_data.values.tolist())
        output = self.decision_tree.get_json_result()
        res = self.decision_tree.test(test_data.values.tolist())
        
        print("准确率:", sum([item[0] for item in res]) / len(res))

        # def test_balance_scale(self):
    #     D = load_csv_data_set("dataset/balance-scale.csv")
    #     D = shuffle_data_set(D)
    #     training_data, test_data = divide_dataset(D)
    #     print(training_data)
    #     self.decision_tree.load_data_set(training_data)
    #     self.decision_tree.set_class_attribute(0)
    #     self.decision_tree.build()
    #     print(test_data.values.tolist())
    #     output = self.decision_tree.get_json_result()
    #     with open("TMP.txt", 'w') as f:
    #         import json
    #         f.write(json.dumps(output))
    #         # test_data
    #     res = self.decision_tree.test(test_data.values.tolist())
        
    #     print("准确率:", sum([item[0] for item in res]) / len(res))
        # print("召回率:", "")
    # def test_record(self):
    #     self.decision_tree.load_csv_data_set("data.csv")
    #     self.decision_tree.build()
    #     res = self.decision_tree.test([[14, 'senior', 'medium', 'no', 'excellent', 'no']])
    #     self.assertEqual(res, ["no"])

if __name__ == '__main__':
  unittest.main()