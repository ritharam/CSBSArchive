#box plot for disp and hp
import pandas as pd
import csv
df = pd.read_csv('C:\\Users\\Star\\Downloads\\mtcars.csv')
df2 = df.reindex(columns = ['disp','hp'])
boxplot = df2.boxplot(figsize = (5,5))
#boxplot for mpg
import pandas as pd
df = pd.read_csv('C:\\Users\\Star\\Downloads\\mtcars.csv')
df2 = df.reindex(columns = ['mpg'])
boxplot = df2.boxplot(figsize = (5,5))
#boxplot for cyl,drat,wt,qsec,vs,am,gear,carb
import pandas as pd
df = pd.read_csv('C:\\Users\\Star\\Downloads\\mtcars.csv')
df2 = df.reindex(columns = ['cyl','drat','wt','qsec','vs','am','gear','carb'])
boxplot = df2.boxplot(figsize = (5,5))