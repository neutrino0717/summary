#!/usr/bin/env eepython
import os, sys
##multiple parents class
class Mom(object):
    def __init__(self):
        print "in Mom __init__, but self argument is child!!!", self
        self.var1="hey im mom"
        self.name="linda"

class Dad(object):
    var2="hey im dad"
    name="peter"

class Child(Mom,Dad):
    var3="hey im new"
    name="vina"
    def change(self, v="hey im mother"):
        print "in change:", self.var1
        self.var1 = v
        print "in change:", self.var1
    
childObj=Child()
childObj.change()
print childObj.var1
print childObj.var2
print childObj.var3
print childObj.name
