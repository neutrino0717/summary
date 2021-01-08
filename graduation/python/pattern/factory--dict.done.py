#!/usr/bin/env eepython
##factory pattern: let a function to choose the class to return
BaseClass=type("BaseClass", (object,), {})
C1=type("C1", (BaseClass,), {"x":1})
C2=type("C2", (BaseClass,), {"x":2})
print C1
def myFactory(cc):
    d = {"c1":C1, "c2":C2}
    assert cc in d
    #return C1() if myBool else C2()
    return d[cc]()
m = myFactory('c1'); print m.x
m = myFactory('c2'); print m.x
#m = myFactory('c3'); print m.x
