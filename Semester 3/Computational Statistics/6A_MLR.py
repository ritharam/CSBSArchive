import numpy as np
import statsmodels.api as sm
x = [[0, 1], [5, 1], [15, 2], [25, 5], [35, 11], [45, 15], [55, 34], [60, 35]]
y = [4, 5, 20, 14, 32, 22, 38, 43]
x, y = np.array(x), np.array(y)
x = sm.add_constant(x)
print(x)
print(y)
model = sm.OLS(y, x)
results = model.fit()
print(results.summary())

print('coefficient of determination:', results.rsquared)
print('adjusted coefficient of determination:', results.rsquared_adj)
print('regression coefficients:', results.params)

print('predicted response:', results.fittedvalues, sep='\n')
print('predicted response:', results.predict(x), sep='\n')

x_new = sm.add_constant(np.arange(10).reshape((-1, 2)))
print(x_new)

y_new = results.predict(x_new)
print(y_new)