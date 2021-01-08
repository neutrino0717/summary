#!/usr/bin/env eepython
#metaclass is the class of a class
#metaclass is a instance's class's class
print type('1'), type(type('1'))
#or
print '1'.__class__, '1'.__class__.__class__
