#!/usr/bin/env eepython
#str is a built-in function (actually a class) which converts its argument to a string. 
#string is a module which provides common string operations.
import string
print str
print string

print string.Template('var is $var').substitute({'var': 1})

test = 5
print string.Template("test = $test").substitute(locals())
print string.Template("test = $test").safe_substitute(locals())
del test
print string.Template("test = $test").safe_substitute(locals())

