import numpy as np
from statistics import mean
from numpy.linalg import eig
np.set_printoptions(suppress=True, precision = 3)

x1 = [2.5,0.5,2.2,1.9,3.1,2.3,2,1,1.5,1.1]
x2 = [2.4,0.7,2.9,2.2,3,2.7,1.6,1.1,1.6,0.9]

m1 = mean(x1)
m2 = mean(x2)
m2 = round(m2,2)

for i in range(len(x1)):
  x1[i] = x1[i] - m1
for i in range(len(x2)):
  x2[i] = x2[i] - m2

x1 = np.array(x1)
x2 = np.array(x2)
x = [x1,x2]

a = np.matmul(x,np.transpose(x))
N = len(np.transpose(x))
a = a/(N-1)
#print(a)

eigval,eigvec = eig(a)
print('The Eigen Values are:\n',eigval)
print('The Eigen Vectors are:\n',eigvec)

y = np.matmul(np.transpose(x),eigvec)
print('The components PC1 & PC2 are:\n',y)