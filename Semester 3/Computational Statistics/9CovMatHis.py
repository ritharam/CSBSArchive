import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('C:\\Users\\Star\\Downloads\\mtcars.csv')
data = df.iloc[:,1:]
x = np.array(data)
xt = np.mean(x,axis=0)
c = np.subtract(x,xt)
ct = np.transpose(c)
cov = np.matmul(ct,c) /len(data.index -1)
print(cov)

for x in ['gear','mpg','cyl','am','carb']:
  plt.hist(data[x])
  plt.title(f"{x}")
  plt.show()

# import numpy as np
# import pandas as pd
# import io
# import matplotlib.pyplot as plt
# df2 = pd.read_csv('C:\\Users\\Star\\Downloads\\mtcars.csv')
# dataset=df2.iloc[:,1:]
# means=dataset.sum()/len(dataset)
# b=dataset-means
# b=b.to_numpy()
# s=(1/(len(b)-1))*(b.T @ b)
# print(s.shape)
# print(f'First two rows of covariance matrix are\n{s[:2]}')
# if np.all(np.cov(dataset.T)-s==0):
#   print('Covariance matrix is correct')
# else:
#   print('Covariance matrix is incorrect')

# plt.hist(df2['cyl'])
# plt.show()