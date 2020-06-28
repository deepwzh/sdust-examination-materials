import json
import io
from flask import Flask, request
import sys
sys.path.append('C:\\Users\\wzh\\data_mining')
from DecisionTree.ID3 import ID3Tree
from DecisionTree.C45 import C45Tree
from DecisionTree.CART import CARTree
from DecisionTree.utils import *

app = Flask(__name__)


@app.route('/api/algo/id3', methods=['POST'])
def request_id3():
    content = request.get_json()
    print(content)
    data_type = content["data_type"]
    training_data = content["training_data"]
    test_data = content["test_data"]
    # print(data_type)
    # print(training_data)
    # print(test_data)
    file = io.StringIO(training_data)
    D = load_csv_data_set(file)
    D = shuffle_data_set(D)
    training_data, test_data = divide_dataset(D)
    print(training_data)
    #
    decision_tree = ID3Tree()
    decision_tree.load_data_set(training_data)
    decision_tree.build()
    tree_data = decision_tree.get_json_result()
    test_res = decision_tree.test(test_data.values.tolist())
    precision = sum([item[0] for item in test_res]) / len(test_res)
    print("准确率:", precision)
    return json.dumps({
        "tree_data": tree_data,
        "precision": precision
    })

@app.route('/api/algo/c45', methods=['POST'])
def request_c45():
    content = request.get_json()
    print(content)
    data_type = content["data_type"]
    training_data = content["training_data"]
    test_data = content["test_data"]
    # print(data_type)
    # print(training_data)
    # print(test_data)
    file = io.StringIO(training_data)
    D = load_csv_data_set(file)
    D = shuffle_data_set(D)
    training_data, test_data = divide_dataset(D)
    print(training_data)
    #
    decision_tree = C45Tree()
    decision_tree.load_data_set(training_data)
    decision_tree.build()
    tree_data = decision_tree.get_json_result()
    test_res = decision_tree.test(test_data.values.tolist())
    precision = sum([item[0] for item in test_res]) / len(test_res)
    print("准确率:", precision)
    return json.dumps({
        "tree_data": tree_data,
        "precision": precision
    })

@app.route('/api/algo/cart', methods=['POST'])
def request_cart():
    content = request.get_json()
    print(content)
    data_type = content["data_type"]
    training_data = content["training_data"]
    test_data = content["test_data"]
    # print(data_type)
    # print(training_data)
    # print(test_data)
    file = io.StringIO(training_data)
    D = load_csv_data_set(file)
    D = shuffle_data_set(D)
    training_data, test_data = divide_dataset(D)
    print(training_data)
    #
    decision_tree = C45Tree()
    decision_tree.load_data_set(training_data)
    decision_tree.build()
    tree_data = decision_tree.get_json_result()
    test_res = decision_tree.test(test_data.values.tolist())
    precision = sum([item[0] for item in test_res]) / len(test_res)
    print("准确率:", precision)
    return json.dumps({
        "tree_data": tree_data,
        "precision": precision
    })

@app.route('/api/upload')
def file_upload():
    return "FILE_PATH"


if __name__ == '__main__':
    app.run(debug=True)
