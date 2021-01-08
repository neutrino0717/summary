#!/usr/bin/env eepython
###re.split(pattern, string, maxsplit=0, flags=0)
###Split string by the occurrences of pattern. If capturing parentheses are used in pattern, then the text of all groups in the pattern are also returned as part of the resulting list.
###

import re
print re.split.__doc__
print re.findall.__doc__
##use split to split into list
print re.split('\W+', 'Words**&$words&^%%.*&words')
print re.split('(\W+)', 'Words**&$words&^%%.*&words')
print re.split('(\W+)', 'Words**&$words&^%%.*&words', 1)
##or use findall to match into list
print re.findall(r'(\w+)', 'Words**&$words&^%%.*&words')
print re.findall(r'(\d{1,4})','cherry123,no.338832end')
