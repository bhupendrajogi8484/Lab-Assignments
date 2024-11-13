import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score


temp_dataset = pd.read_csv("temperatures.csv")
temp_dataset.head()
temp_dataset.shape
temp_dataset.isnull().sum()

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
X = temp_dataset[["YEAR"]] # input column
y = temp_dataset["JAN"] # target column
X_train, X_test, y_train, y_test = train_test_split(
X, y, test_size=0.2, random_state=42
)
print(X_train.shape, X_test.shape)
# instantiate the model
lr = LinearRegression()
# fit the model
lr.fit(X_train, y_train)
# predicting the target value from the model for the samples
y_test_lr = lr.predict(X_test)

y_train_lr = lr.predict(X_train)
print("Intercept", lr.intercept_)
print("Slope", lr.coef_)
# computing the accuracy of the model performance
print(
"Linear Regression: Accuracy on test Data: {:.3f}".format(
lr.score(X_test, y_test)
))
# visulaize annaul temperature
plt.plot(X, y)
plt.xlabel("Year")
plt.ylabel("Temperature")
plt.title("Annual Temperature from 1901-2017")
plt.show()
# plot the regression line for the month januwary
# plt.figure(figsize=(8, 6))
plt.scatter(X_test, y_test, color="blue")
plt.scatter(X_train, y_train, color="red")
plt.plot(X_train, lr.predict(X_train), color="black")
plt.legend(["Best fit Regression lIne", "Testing Set", "Training Set"])
plt.title("Temperature vs Year for month Jan")
plt.xlabel("Year")
plt.ylabel("Temperature")
plt.show()
# Errors for month Jan
print("R-Squared Error :", r2_score(y_test, y_test_lr))
print("Mean Absolute Error :", mean_absolute_error(y_test, y_test_lr))
print("Mean Squared Error :", mean_squared_error(y_test, y_test_lr))
print(
"Root Mean Squared Error :", np.sqrt(mean_squared_error(y_test, y_test_lr))
)
