import numpy as np
import pandas as pd
dataFrame = pd.read_csv("/content/Heart.csv")
dataFrame.shape # shape
dataFrame.info()
dataFrame.head()
dataFrame.dtypes
dataFrame.isnull()
dataFrame.isnull().sum()
dataFrame.Age.mean()
count = (dataFrame["Age"] == 0).sum()
count
var = dataFrame.loc[:, ["Age", "Sex", "ChestPain", "RestBP", "Chol"]]
var
from sklearn.model_selection import train_test_split
X_train, X_test = train_test_split(var, test_size=0.25, random_state=42)
X_train.shape, X_test.shape


tp=45
fp=55
fn=05
tn=395
acc=(tp+tn)/(tp+fp+fn+tn)
pre=tp/(tp+fp)
rec=tp/(tp+fn)
print("Accuracy is : {}".format(acc))
print("Precision is : {}".format(pre))
print("Recall is : {}".format(rec))
print("F1-Score is : {}".format((2*pre*rec)/(pre+rec)))
