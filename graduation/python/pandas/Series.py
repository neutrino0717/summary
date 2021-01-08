#!/usr/bin/env eepython
import pandas as pd
pd.options.display.width = 150
pd.options.display.max_colwidth = 150

ufo = pd.read_csv('data/ufo.csv')
print type(ufo)
print type(ufo.head())
print ufo.head(2)

##pandas.core.series.Series
print type(ufo['City'])
print ufo['City'].head(2)
print ufo['City'].tail(2)
print ufo.City.head(2)
##create a new column 
ufo['Location'] =  ufo.City + ', ' + ufo.State
print ufo.head(2);
