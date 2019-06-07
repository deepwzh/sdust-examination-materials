import pandas as pd
import numpy as np
from sklearn import svm
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.ensemble import AdaBoostClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import VotingClassifier

from sklearn.metrics import fbeta_score
from sklearn.metrics import accuracy_score
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn.decomposition import PCA

def get_score(y_pred,y_true):
    acc_ = accuracy_score(y_true=y_true,y_pred=y_pred)
    TP = np.sum((y_pred==1) & (y_true == 1))
    precision = TP / np.sum(y_pred)
    recall = TP / np.sum(y_true)
    print('TP: ',TP,'/', np.sum(y_true), 'all ',np.sum(y_pred), ' accuracy: ',acc_, ' precision: ',precision, ' recall: ',recall, ' F_score: ', 2 * precision * recall / (precision + recall),fbeta_score(y_true=y_true,y_pred=y_pred,beta=1) )

data = pd.read_csv("model.csv")
data = data.dropna(subset=['x_001'])
data[data.iloc[:,2:]<0] = np.nan
X = data.iloc[:,2:]
training_mean = X.mean()
X =X.fillna(training_mean)
Y = data['y']
X = preprocessing.scale(X)




# PCA降维处理，这里暂定维数为50
pca = PCA(40)
training_X, test_X, training_Y, test_Y = train_test_split(X, Y, test_size=0.2,shuffle = True)
training_X = pca.fit_transform(training_X)


clf = svm.SVC(gamma='auto', probability=True)

rfc = RandomForestClassifier(n_estimators=100, max_depth=None,
    min_samples_split=2, random_state=0)

dtc = DecisionTreeClassifier(random_state=0)

abc = AdaBoostClassifier(n_estimators=100)

# 使用投票器整合多个分类器，bagging，参数有待考量
eclf = VotingClassifier(estimators=[('rfc', rfc), ('clf', clf), ('abc', abc), ('dtc', dtc)], weights=[4,1,3,1])  # 无权重投票
eclf.fit(training_X, training_Y)

test_X = pca.transform(test_X)
preY = eclf.predict(test_X)
# 获取模型评价数据
get_score(preY, test_Y)


# 读取测试文件并进行预处理
test_data = pd.read_csv("test.csv")
test_data = test_data.iloc[:, 1:]
test_data[test_data.iloc[:, 1: ] < 0] = np.nan
test_data = test_data.fillna(training_mean)
test_data = preprocessing.scale(test_data)
test_data = pca.transform(test_data)


res = eclf.predict(test_data)


np.savetxt('result.csv', res,fmt='%d',delimiter=',')
