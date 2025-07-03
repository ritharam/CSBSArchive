def L1Norm(x) :
  sum = 0
  for i in range(len(x)):
    sum += (abs(x[i]))
  print("L1 norm : ",sum)

def L2Norm(x) :
  res = 0
  for i in range(len(x)) :
    res += (abs(x[i])**2)
  print("L2 norm : ",res**0.5)

def Ortho(x,y) :
  v = np.transpose(x)
  res = np.dot(y,v)
  if (res == 0) :
    print("Orthogonal")
  else :
    print("Not Orthogonal")

def MaxNorm(x) :
  print("Max Norm : ", max(x))

import numpy as np

ch = 'y'
while (ch == 'y') :
  x = []
  print("1. L1 Norm\n2. L2 norm\n3. Orthogonal\n4. Max Norm")
  opt = int(input())
  if (opt == 1) :
    print("Enter number of elements : ")
    n = int(input())
    print("Enter the elements.")
    for i in range(n) :
      E = int(input())
      x.append(E)
    L1Norm(x)
  if (opt == 2) :
    print("Enter number of elements : ")
    n = int(input())
    print("Enter the elements.")
    for i in range(n) :
      E = int(input())
      x.append(E)
    L2Norm(x)
  if (opt == 3) :
    v = [1,2,3]
    y = [4,5,6]
    Ortho(v,y)
  if (opt == 4) :
    print("Enter number of elements : ")
    n = int(input())
    print("Enter the elements.")
    for i in range(n) :
      E = int(input())
      x.append(E)
    MaxNorm(x)
  ch = input("Do you want to continue (y/n) ? ")