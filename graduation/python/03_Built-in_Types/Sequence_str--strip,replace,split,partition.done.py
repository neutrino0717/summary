#!/usr/bin/env eepython

##strip, rstrip, lstrip
url="  evencoding.com   "
print '|'+url.strip()+'|'
print '|'+url+'|'
print '|'+url.rstrip().lstrip()+'|'

##replace
print "Scarborough Fair".replace("Fair","fair")

##upper, lower, capitalize, title
name="scarBorough FAIR"
print name.upper()
print name.lower()
print name.capitalize()
print name.title()

##split, partition, rpartition
str="bing.com|google.com|baidu.com|yahoo.com"
sites=str.split('|'); print sites
sites=str.partition('|'); print sites
sites=str.rpartition('|'); print sites

