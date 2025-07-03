#chi2_test
import pandas as pd       # works with datasets
import io                 # main input/output operations
df = pd.read_csv('C:\\Users\\Star\\Downloads\\mtcars.csv')
print(df.head)
print(df.shape)
print(df.describe())
print("Chi square testing : \n")

a = []
c = []
a = df.mpg
b1 = list(df.columns)
print(b1)
b = b1[2:]
print(b)

from scipy.stats import chi2_contingency
for i in range(len(b)):
  c = df[b[i]]
  data = [a,c]
  stat, p, dof, expected = chi2_contingency(data)
  alpha = 0.05
  print(b[i])
  print("p value is : ", p)
  if p <= alpha:
    print("Dependent (reject H0)\n")
  else :
    print("Independent (H0 holds true)\n")