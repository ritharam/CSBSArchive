import numpy as np
from sklearn.linear_model import LinearRegression
import pandas as pd
import io
df2 = pd.read_csv('C:\\Users\\Star\\Downloads\\mtcars.csv')
# print(df2)
df2.shape
df2.head(10)
x=df2.iloc[:,1:11,]
x.shape
x.head(5)
print(x)
y=df2.iloc[:,11,]
print(y)
y.shape
x, y = np.array(x), np.array(y)
from sklearn.model_selection import train_test_split
X_train, X_test, Y_train, Y_test = train_test_split( x, y, test_size=0.2, random_state=0)
X_train.shape
X_test.shape
Y_train.shape
Y_test.shape
model = LinearRegression().fit(X_train, Y_train)
r_sq = model.score(x, y)
print('coefficient of determination:', r_sq)
print('intercept:', model.intercept_)
print('slope:', model.coef_)
y_pred = model.predict(X_test)
print('predicted response:', y_pred, sep='\n')
y_pred = model.intercept_ + np.sum(model.coef_ * X_test, axis=1)
print('predicted response:', y_pred, sep='\n')
## SSR
res=(Y_test-y_pred)**2
print(sum(res))
res=((sum(Y_test-y_pred)**2)/7)**0.5
print(res)