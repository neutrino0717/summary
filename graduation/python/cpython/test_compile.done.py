#!/usr/bin/env eepython
print compile.__doc__
c = compile('test.compile.py','test.compile.py','exec')
print c
print c.__doc__
print dir(c)
print type(c.co_code)
print c.co_code; print len(c.co_code)
print [byte for byte in c.co_code]
print [ord(byte) for byte in c.co_code]
print dir(compile)
