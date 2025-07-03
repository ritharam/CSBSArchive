import pandas as pd
import numpy as np 
data = np.array([[2.5,2.4],[0.5,0.7],[2.2,2.9],[1.9,2.2],[3.1,3],[2.3,2.7],[2,1.6],[1,1.1],[1.5,1.6],[1.1,0.9]])
data = pd.DataFrame(data)
print(data)
a = data[0]
b = data[1]
point = ['p1','p2','p3','p4','p5','p6','p7','p8','p9','p10',]
data = pd.DataFrame({'point':point,'a':np.round(a,2),'b':np.round(b,2)})
data = data.set_index('point')
print(data)

import matplotlib.pyplot as plt 
plt.figure(figsize=(8,5))
plt.scatter(data['a'],data['b'],c='r',marker='*')
plt.xlabel('column a')
plt.ylabel('column b')
plt.title('scatter plot of x and y')

for j in data.itertuples():
    plt.annotate(j.Index,(j.a,j.b),fontsize=15)

import scipy.cluster.hierarchy as shc
from scipy.spatial.distance import squareform,pdist
dist1 = pd.DataFrame(squareform(pdist(data[['a','b']]),'euclidean'),columns=data.index.values,index=data.index.values)
print(dist1)

# single linkage
plt.figure(figsize=(12,5))
plt.title('dendogram with single linkage')
dend = shc.dendrogram(shc.linkage(data[['a','b']],method='single'),labels=data.index)

# complete linkage
plt.figure(figsize=(12,5))
plt.title('dendogram with complete linkage')
dend = shc.dendrogram(shc.linkage(data[['a','b']],method='complete'),labels=data.index)
