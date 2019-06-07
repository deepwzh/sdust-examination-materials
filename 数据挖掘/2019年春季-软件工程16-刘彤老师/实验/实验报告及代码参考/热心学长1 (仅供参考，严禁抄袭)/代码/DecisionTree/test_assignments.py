from Assignment import *
import unittest

class TestID3Dict(unittest.TestCase):
    def setUp(self):
        pass
        # self.decision_tree = ()
                #print(self.decision_tree.get_json_result())

    def tearDown(self):
        pass

    def test_car_scale(self):
        D = load_csv_data_set("dataset/car.csv")
        D = shuffle_data_set(D)
        training_data, test_data = divide_dataset(D)
        print(training_data)
        self.decision_tree.load_data_set(training_data)
        # self.decision_tree.set_class_attribute(0)
        self.decision_tree.build()
        print(test_data.values.tolist())
        output = self.decision_tree.get_json_result()
        with open("TMP.txt", 'w') as f:
            import json
            f.write(json.dumps(output))
            # test_data
        res = self.decision_tree.test(test_data.values.tolist())
        
        print("准确率:", sum([item[0] for item in res]) / len(res))

if __name__ == '__main__':
  unittest.main()