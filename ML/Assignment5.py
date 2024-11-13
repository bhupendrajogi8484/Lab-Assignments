import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
import seaborn as sns


df = pd.read_csv("Mall_Customers.csv")
df.head()
df.shape
df.columns
df.drop("CustomerID",axis=1,inplace=True)
print("Missing values:")
df.isnull().sum()
from sklearn.preprocessing import LabelEncoder
from sklearn import metrics
le = LabelEncoder()
df["Genre"] = le.fit_transform(df["Genre"])
# Finding the optimum number of clusters using k-means
data = df.copy()
x = data.iloc[:,[2,3]]
wcss = []
for i in range(1,11):
kmeans = KMeans(n_clusters=i, init='k-means++',random_state=42)

kmeans.fit(x)
wcss.append(kmeans.inertia_)
print('k:',i ,"-> wcss:",kmeans.inertia_)
# Plotting the results onto a line graph, to observe 'The elbow'
plt.plot(range(1,11),wcss,marker='o')
plt.title('The Elbow Method')
plt.xlabel('Number of Clusters')
plt.ylabel('WCSS')
plt.show()
#Taking k = 5
km1=KMeans(n_clusters=5)
km1.fit(data)
pred_y =km1.predict(data)
data["label"] = pred_y
#Scatterplot of the clusters
plt.figure(figsize=(6,4))
sns.scatterplot(x = 'Annual Income (k$)',y = 'Spending Score (1-100)',hue="label",
palette=['green','brown','orange','red','dodgerblue'],data = data )
plt.xlabel('Annual Income (k$)')
plt.ylabel('Spending Score (1-100)')
plt.title('Spending Score (1-100) vs Annual Income (k$)')
plt.show()
X=data.iloc[:,:4]
y=data.iloc[:,-1]
# Splitting of dataset into train and test
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
print(X_train.shape,y_train.shape)
print(X_test.shape,y_test.shape)
from sklearn.cluster import KMeans
km=KMeans(n_clusters=5)
km.fit(X_train)
# predicting the target (cluster) from the model for the samples
y_train_km = km.predict(X_train)


y_test_km = km.predict(X_test)
from sklearn.metrics.cluster import adjusted_rand_score
acc_train_gmm = adjusted_rand_score(y_train,y_train_km)
acc_test_gmm = adjusted_rand_score(y_test,y_test_km)
print("K mean : Accuracy on training Data: {:.3f}".format(acc_train_gmm))
print("K mean : Accuracy on test Data: {:.3f}".format(acc_test_gmm))
data = data.iloc[:,[2,3]]
from sklearn.cluster import AgglomerativeClustering
agc = AgglomerativeClustering(n_clusters=5)
data["label"] = agc.fit_predict(data)
data
#Scatterplot of the clusters
sns.scatterplot(x = 'Annual Income (k$)',y = 'Spending Score (1-100)',hue="label",
palette=['green','brown','orange','red','dodgerblue'],data = data )
plt.xlabel('Annual Income (k$)')
plt.ylabel('Spending Score (1-100)')
plt.title('Spending Score (1-100) vs Annual Income (k$)')
plt.show()
