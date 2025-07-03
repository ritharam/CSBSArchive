#Fisher Discrimiant Score

import numpy as np
import pandas as pd

x1 = [[4.26,1.33]]
x2 = [[5.55,2.03]]
x1, x2 = np.array(x1),np.array(x2)
np.set_printoptions(suppress = True, precision = 3)
n1 = n2 = 50
s1 = [[0.291,0.049],[0.049,0.075]]
s2 = [[0.212,0.072],[0.072,0.837]]
s1, s2 = np.array(s1), np.array(s2)

sp = ((n1-1)/((n1-1)+(n2-1)))*s1 + ((n2-1)/((n1-1)+(n2-1)))*s2
print("Spooled : \n",sp)
spinv = np.linalg.inv(sp)
print("Spooled Inverse : \n",spinv)

x0 = []
for i in range(2) :
  num = float(input("Enter values of x0 : "))
  x0.append(num)
  
a = np.dot((x1-x2),spinv)
y1 = np.matmul(a,np.transpose(x1))
y2 = np.matmul(a,np.transpose(x2))
midp = 0.5*(y1 + y2)
print("Mid Point : ", midp)

y0 = np.matmul(a,np.transpose(x0))
print('y0 : ',y0)
if y0 > midp :
  print("Since y0 > midpoint, Allocate x0 to p1")
else :
  print("Since y0 < midpoint, Allocate x0 to p2")
