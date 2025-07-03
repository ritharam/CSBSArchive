import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler

url = "https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data"
d = pd.read_csv(url, names=['sepal length','sepal width','petal length','petal width','target'])
d0 = StandardScaler().fit_transform(d.iloc[:,1:4])
d_trans = np.transpose(d0)
C = np.dot(d_trans,d0)
print("Covariance : ", C)
W,V = np.linalg.eig(C)
print('Eigen-value:', W)
print('Eigen-vector', V)
Y = np.dot(d0,V)
n = min(10,len(W))
pve = [0]*n
print("Principal Components are \n")
for i in range(n):
  pve[i] = (W[i]/sum(W))*100
print(pve)
df = pd.DataFrame(Y, columns=['PC1','PC2','PC3','PC4'][:n])
print(df.iloc[:, :n])
x_axis = range(1,n+1)
plt.xlabel('Principal Components')
plt.ylabel('PVE')
plt.title('SCREEN PLOT')
plt.plot(x_axis,pve,"r")
plt.show()