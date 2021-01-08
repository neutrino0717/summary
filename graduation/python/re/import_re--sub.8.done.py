#!/usr/bin/env eepython
import re
print re.sub.__doc__
##re.sub: trim whitespace in the start and end of a line
s=" \t  how to trim a string  \t"
print "'%s'" %s
print "'"+re.sub(r'^\s*|\s*$',r'',s)+"'"
#or
print "'"+s.strip()+"'"

##re.sub: comment change to echo
cmds='''
#list all blades
gsh list_piu
gsh list_alarms  #check the alarms
#done
'''
print cmds
print re.sub('^(#.*)', r'echo "\1"', cmds, flags=re.M)

##re.sub: comment removal
phone = "2004-959-559 # This is Phone Number"
print "Phone Num:", re.sub(r'#.*$', "", phone)

##re.sub: remove anything other than digits
phone = "2004-959-559 # This is Phone Number"
print "Phone Num:", re.sub(r'\D', "", phone)
