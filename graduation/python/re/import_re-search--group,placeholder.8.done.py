#!/usr/bin/env eepython
import re
global line
line='''
Sirius-8.5828-1844
Alpha Centauri-4.3650-1689
Procyon-11.402-1844
'''
##re.search: use regex named group, P means placeholder" + colors.ENDC
amatch=re.search('(?P<star>.*)-(?P<distance>.*)-(?P<year>.*)',line);  print amatch.group('star'), amatch.group('distance'), amatch.group('year')
##re.findall: use regex named group, seems meaningless, for it returns list instead of match object" + colors.ENDC
alist=re.findall('(?P<star>.*)-(?P<distance>.*)-(?P<year>.*)',line);  print alist
alist=re.findall('(.*)-(.*)-(.*)',line, re.M);                        print alist 

