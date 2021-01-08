#!/usr/bin/env eepython
import pandas as pd
##by default, tab is used to separate tsv file
pd.options.display.width = 150
pd.options.display.max_colwidth = 150
orders = pd.read_table('data/chipotle.tsv')
#orders = pd.read_table('http://bit.ly/chiporders')
print type(orders)
print orders.head()

##a file using '|' as separater
print pd.read_table('data/movieusers').head(2)
print pd.read_table('data/movieusers',sep='|').head(2)

##add head for the file
user_cols = ['user_id', 'age', 'gender', 'ocupation', 'zip_code']
print pd.read_table('data/movieusers',sep='|', header=None).head(2)
print pd.read_table('data/movieusers',sep='|', names=user_cols).head(2)
##read_csv() is the same as read_table() expect using ',' as default delimiter, 
print pd.read_csv('data/movieusers',sep='|', names=user_cols).head(2)




print pd.read_table.__doc__
