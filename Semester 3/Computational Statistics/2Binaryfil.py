import pickle
n = [[1,2,3],[4,5,6],[7,8,9]]
f = open('n.bin','wb')
pickle.dump(n,f)
f.close()

fp = open('n.bin','rb')
temp = pickle.load(fp)
for i in range(len(temp[0])) :
  print(temp[i])
fp.close()

f1 = open('n.bin','rb')
f2 = open('t.bin','wb')
bstring = f1.readlines()
print("The content are read from the binary file.\n")
f2.writelines(bstring)
f1.close()
f2.close()

import pickle
with open('t.bin','rb') as t :
  k = pickle.load(t)
print("After writing from num to t.bim, the contents are : ")
for i in range(len(k)):
  print(k[i])
      