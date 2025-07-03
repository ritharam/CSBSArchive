#t_test
import pandas as pd       # works with datasets
import io                 # main input/output operations
df = pd.read_csv('C:\\Users\\Star\\Downloads\\mtcars.csv')
# print(df.head)
# print(df.shape)
# print(df.describe())

import scipy.stats
alpha = 0.05
print("Two sampled T-test : ")
h =  list(df.head())[2:]
print(h)
print(df['mpg'])

for i in h:
  t = scipy.stats.ttest_ind(df['mpg'],df[i])
  print(t)
  p = t[1]
  print('(mpg,{})'.format(i),':',sep=' ')

if p <= alpha :
  print("\tH1 is accepted (population means are different)")
else :
  print("\tH0 is accepted (population means are the same)")