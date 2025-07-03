#mpg vs all features of mtcars
import pandas as pd
import io
df=pd.read_csv('C:\\Users\\Star\\Downloads\\mtcars.csv')
import matplotlib.pyplot as plt
b = list(df.head())[2:]
for i in b:
    plt.scatter(df['mpg'],df[i])
    plt.show()

# single-line plot for mpg
import pandas as pd
from matplotlib import pyplot as plt
plt.rcParams["figure.figsize"] = [10,5]
plt.rcParams["figure.autolayout"] = True
columns = ['mpg']
df = pd.read_csv("mtcars.csv", usecols=columns)
df.plot()
plt.show()

# multi-line plot for disp and hp
import pandas as pd
from matplotlib import pyplot as plt
plt.rcParams["figure.figsize"] = [10,5]
plt.rcParams["figure.autolayout"] = True
columns = ['disp','hp']
df = pd.read_csv("mtcars.csv", usecols=columns)
df.plot()
plt.show()
# multi-line plot for cyl,drat,wt,qsec,vs,am,gear,carb
import pandas as pd
from matplotlib import pyplot as plt
plt.rcParams["figure.figsize"] = [10, 5]
plt.rcParams["figure.autolayout"] = True
columns = ['cyl','drat','wt','qsec','vs','am','gear','carb']
df = pd.read_csv("mtcars.csv", usecols=columns)
df.plot()
plt.show()