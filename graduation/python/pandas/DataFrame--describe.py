#!/usr/bin/env eepython
import pandas as pd
pd.options.display.width = 150
pd.options.display.max_colwidth = 150
movies = pd.read_csv('data/imdbratings')
print movies.head(2)
##count the numeric columns automatically
print movies.describe()
##number of cols and lines
print movies.shape
##data types: note object means string
print movies.dtypes
