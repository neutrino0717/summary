#!/usr/bin/env eepython
### https://docs.python.org/2/library/re.html#regular-expression-syntax
### split()    split to array with pattern as delimeter
### match()    expression match the start of a string, or match the entire string, return match object
### search()   expression match anywhere in the string, return match object
### findall()  Return a list of all non-overlapping matches in the string
import re
print inspect.getsource(re.split)
print inspect.getsource(re.match)
print inspect.getsource(re.search)
print inspect.getsource(re.findall)
line='''
Sirius-8.5828-1844
Alpha Centauri-4.3650-1689
Procyon-11.402-1844
'''
print line
## 1. re.match() returns a match object, only  match the start of the string" + colors.ENDC
amatch=re.match(r'\shello', ' hello, neutrino');        print amatch; print amatch.group(0)
print re.match(r'hello', ' hello, neutrino')


## 2. re.search() returns a match object, with only the first match in the string
#use regex parentheses
amatch=re.search(r'(.*)-(.*)-(.*)', line);              print amatch
amatch=re.search('(.*)-(.*)-(.*)', line);               print amatch
amatch=re.search('(.*)-(.*)-(.*)', line);               print amatch.group(1), amatch.group(2), amatch.group(3)
#group() and group(0) returns the entire match
amatch=re.search('(.*)-(.*)-(.*)', line);               print amatch.group(0)
amatch=re.search('(.*-.*-.*)', line);                   print amatch.group(0)
amatch=re.search('(.*-.*-.*)', line);                   print amatch.group(1)
#use regex named group, P means placeholder" + colors.ENDC
amatch=re.search('(?P<star>.*)-(?P<distance>.*)-(?P<year>.*)',line); 
print amatch.group('star'), amatch.group('distance'), amatch.group('year')

##3. re.findall() returns a list
tpl_in_list = re.findall ('(.*)-(.*)-(.*)',line);       print tpl_in_list
tpl_in_list = re.findall ('(.*)-(.*)-(.*)',line, re.M); print tpl_in_list 
alist = re.findall ('(.*-.*-.*)',line, re.M);           print alist
alist = re.findall ('.*-.*-.*',line);                   print alist

##4. re.finditer return a iterator
for amatch in re.finditer('(.*)-(.*)-(.*)', line, re.M): print amatch.group(1), amatch.group(2), amatch.group(3)
print re.finditer('(.*)-(.*)-(.*)', line, re.M)
