import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

data = pd.read_csv("Admission_Predict.csv")
data.head()
data.shape

data.columns

data.drop("Serial No.", axis=1, inplace=True) 

data["Chance of Admit "] = data["Chance of Admit "].apply(
lambda x: 1 if x > 0.5 else 0
)

print("Missing values:\n")
data.isnull().sum()

data_admit = data[data["Chance of Admit "] == 1]
data_non_admit = data[data["Chance of Admit "] == 0]
print("Admitted count : ", data_admit.shape[0])
print("Non - Admitted count : ", data_non_admit.shape[0])


X = data.drop("Chance of Admit ", axis=1)
y = data["Chance of Admit "]

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(
X, y, test_size=0.2, random_state=42
)

print(X_train.shape, y_train.shape)
print(X_test.shape, y_test.shape)
from sklearn.tree import DecisionTreeClassifier
tree = DecisionTreeClassifier()

tree.fit(X_train, y_train)

y_train_tree = tree.predict(X_train)
y_test_tree = tree.predict(X_test)

from sklearn.metrics import accuracy_score
acc_test_tree = accuracy_score(y_test, y_test_tree)
print("Decision Tree : Accuracy on test Data: {:.3f}".format(acc_test_tree))

from sklearn.metrics import classification_report
print(classification_report(y_test, y_test_tree))

import sklearn.tree as tr
fig = plt.figure(figsize=(20, 15))
_ = tr.plot_tree(
tree,
feature_names=X.columns,
class_names=np.array(["Non admit", "Admit"]),
filled=True,
)
