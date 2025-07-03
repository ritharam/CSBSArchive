# K-mean clustering

import pandas as pd
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt 

df = pd.read_csv('iris.csv')
print(df)

x = df.iloc[:,[0,1,2,3]].values
wcss = []
for i in range(1,11):
    kmeans = KMeans(n_clusters=i,init='k-means++',max_iter=300,n_init=1,random_state=0)
    kmeans.fit(x)
    wcss.append(kmeans.inertia_)

plt.plot(range(1,11),wcss)
plt.title("the elbow method")
plt.xlabel("no. of cluster")
plt.ylabel("wcss")
plt.show()

kmeans = KMeans(n_clusters=i,init='k-means++',max_iter=30000,n_init=100,random_state=0)
y_kmeans = kmeans.fit_predict(x)

plt.scatter(x[y_kmeans == 0,0], x[y_kmeans == 0,1], s=50, c='blue', label='iris-setose')
plt.scatter(x[y_kmeans == 1,0], x[y_kmeans == 1,1], s=50, c='green', label='iris-versicolour')
plt.scatter(x[y_kmeans == 2,0], x[y_kmeans == 2,1], s=50, c='black', label='iris-verginica')
plt.scatter(kmeans.cluster_centers_[:,0], kmeans.cluster_centers_[:,1], s=100, c='yellow', label='centroids')
plt.legend()