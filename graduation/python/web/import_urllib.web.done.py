#!/usr/bin/env eepython
#import urllib.request
import re, urllib

#sites = 'yahoo cnn startrek'.split()
#sites = 'evencoding startrek yahoo'.split()
pat = re.compile(r'<title>+.*</title>', re.I | re.M)

s = 'startrek'
print('Searching: ' + s )
u = urllib.urlopen('http://' + s + '.com')
#u= urllib.request.urlopen('http://' + s + '.com')
text = u.read()
#title= re.findall(r'<title>+.*</title>',str(text),re.I|re.M)
title = re.findall(pat, str(text))
print(title[0])
