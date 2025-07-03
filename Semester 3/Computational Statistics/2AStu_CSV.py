import csv
reg = []
m1 = []
m2 = []
total = [0,0,0]
n = int(input("Enter the number of elements : "))
print("\nEnter the elements : ")

for i in range(n) :
  e = int(input("Enter the Register number : "))
  reg.append(e)
  f = int(input("Enter the external mark : "))
  m1.append(f)
  f1 = int(input("Enter the external mark : "))
  m2.append(f1)
#   a = 0
#   total.append(a)

# for j in range(n) :
  print(reg[i]," ",m1[i]," ",m2[i])
  total[i] = m1[i]+m2[i]

with open ('student.csv',mode='w',newline='') as student :
  stu_write = csv.writer(student,delimiter='\t')
  stu_write.writerow(reg)
  stu_write.writerow(m1)
  stu_write.writerow(m2)
  stu_write.writerow(total)

import numpy as np
file = open('student.csv',mode='r',newline='')
fd = csv.reader(file,delimiter='\t',quotechar='*')
s = list()
for i in fd :
    s.append(i)
f = np.array([s[0],s[1],s[2]])
print(f)
s = np.array([s[3]])
print(s)