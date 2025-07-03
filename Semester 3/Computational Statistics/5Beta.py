import numpy as np
import pandas as pd
# from sklearn.linear_model import LinearRegression
z = np.array([[1,1,1,1,1],[5,7,10,12,20]])
y = np.array([10,20,30,40,50])
print(z)
z.shape
zt = np.transpose(z)
x = np.dot(z,zt)
x_inv = np.linalg.inv(x)
print(x_inv)
t2 = np.dot(z,y)
y.shape
beta = np.dot(x_inv,t2)
print("Coefficient BETA : ",beta)
#prediction
y_pred = np.dot(zt,beta)
print(y_pred)
#error calculation
r = (sum((y-y_pred)**2)/6)**0.5
print(r)