from sklearn.model_selection import train_test_split
from sklearn import svm
import pandas as pd

def proprocess(data):
  del data['user_id']
  return data

def train(data, label):
  clf = svm.SVC(gamma='scale')
  clf.fit(data, label)
  return clf

def data_label_split(data, label_name):
  label = data[label_name]
  del data['y']
  return data, label

def get_precision(result_labels, test_data_labels):
    stat = (result_labels == test_data_labels).value_counts()
    print(stat)
    return stat.loc[True] / stat.sum()

def predict(clf, test_data):
  return clf.predict(test_data)

def main():
  data = pd.read_csv("dataset/model.csv")
  training_data, test_data = train_test_split(data, test_size=0.2,shuffle = False)
  training_data = proprocess(training_data)
  training_mean = training_data.mean()
  training_data = training_data.fillna(training_mean)
  training_data, training_labels = data_label_split(training_data, 'y')
  clf = train(training_data, training_labels)
  
  test_data = proprocess(test_data)
  test_data = test_data.fillna(training_mean)
  test_data, test_labels = data_label_split(test_data, 'y')
  res = predict(clf, test_data)
  percision = get_precision(res, test_labels)
  print(percision)
  
if __name__ == '__main__':
  main()