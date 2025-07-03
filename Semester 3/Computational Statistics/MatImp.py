# Matrix Implementations

import numpy as np

def matADD(m1,m2,R1,C1) :
  for i in range(R1):
    for j in range(C1):
       result[i][j] = m1[i][j] + m2[i][j]
  for r in result:
    print(r)

def matMUL(m1,m2,R1,C1) :
  for i in range(R1):
    for j in range(C1):
      for k in range(len(m1)):
       result[i][j] += m1[i][k] * m2[k][j]
  for r in result:
    print(r)

def matINV(m1,m2) :
  mx = np.array(m1)
  print(np.linalg.inv(mx))
  my = np.array(m2)
  print(np.linalg.inv(my))

def matTrans(m1,m2) :
  mx = np.array(m1)
  print(mx.T)
  my = np.array(m2)
  print(my.T)

R1 = int(input("Enter the number of rows for m1 :"))
C1 = int(input("Enter the number of columns for m1:"))
R2 = int(input("Enter the number of rows for m2 :"))
C2 = int(input("Enter the number of columns for m2:"))

m1 = []
m2 = []

print("Enter the entries row wise:")

for i in range(R1):
    a1 =[]
    for j in range(C1):
         a1.append(int(input()))
    m1.append(a1)

for i in range(R2):
    a2 =[]
    for j in range(C2):
         a2.append(int(input()))
    m2.append(a2)

result = [[0,0,0],
         [0,0,0],
         [0,0,0]]

print("1. Matrix Addition\n2. Matrix Multiplication\n3. Inverse of a Matrix\n4. Transpose of a matrix\n ")
yn ="Y"
while (yn == "Y") :
  ch = int(input("Enter your choice : "))
  if (ch == 1) :
    matADD(m1,m2,R1,C1)
  elif (ch == 2) :
    matMUL(m1,m2,R1,C1)
  elif (ch == 3) :
    matINV(m1,m2)
  elif (ch == 4) :
    matTrans(m1,m2)
  else :
    break

yn = input("Do you want to continue ? ")