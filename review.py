#!/usr/bin/python
import os
import sys
import re
import logging
from color import *


def pp(str):
    print("\n" + RED + "========= %s =========" % str + ENDC)


def ep(str):
    print RED + str + ENDC
    exec (str, globals())

def eep(str):
    import subprocess
    str = '''eepython << "EOF"
''' + str + '''
EOF
'''
    print subprocess.check_output(str, shell=True)

def peep(head, str, way=eep, run=True):
    if not run: return
    pp(head)
    way(str)


pp("multilayer decorator")
def strong_decorate(func):  # get_text = strong_decorate(get_text)
    def func_wrapper(name):
        return "<strong>{0}</strong>".format(func(name))

    return func_wrapper


def p_decorate(func):
    def func_wrapper(name):
        return "<p>{0}</p>".format(func(name))

    return func_wrapper


def div_decorate(func):
    def func_wrapper(name):
        return "<div>{0}</div>".format(func(name))

    return func_wrapper


# get_text = strong_decorate(get_text)
# get_text = p_decorate(get_text)
# get_text = div_decorate(get_text)
@div_decorate
@p_decorate
@strong_decorate
def get_text(name):
    return "Hello " + name


print(get_text("John"))
# <div><p><strong>Hello John</strong></p></div>

pp("Passing arguments to decorators")


# from functools import wraps
def tags(tag_name):
    def tags_decorator(func):
        # @wraps(func)       #--> get_text.__name__, get_text.__doc__, get_text.__module__ will return correct values
        def func_wrapper(name):
            return "<{1}>{0}</{1}>".format(func(name), tag_name)

        return func_wrapper

    return tags_decorator


@tags("div")
@tags("p")
@tags("strong")
def get_text(name):
    return "Hello " + name


# get_text = tags("strong")(get_text)
# get_text = tags("p")(get_text)
# get_text = tags("div")(get_text)
print(get_text("John"))
# <div><p><strong>Hello John</strong></p></div>

pp("namemangle to prevent accidental access")


# _var, _func():       semiprivate and meant just for convention
# __var, __func():     namemangle to prevent accidental access,
#                     __var changed to _cls__var by interpreter to ensure that the name will not overlap
#                     with a similar name in another class
# __var__, __func__(): reserved for builtin methods/variables
class Test(object):
    def __init__(self):
        self._a = 'a'
        self.__b = 'b'
        self.__c__ = 'c'


t = Test()
print t._a  # a  ## _a is a private variable
print t.__c__  # c  ## __c__ is a private variable, and in my view only for buildin, but it's OK if you use it
# print t.__b         ## __b not exist namemangling, use _Test__b instead
print t._Test__b  # b

pp("object.__dict__")
from pprint import pprint


class A:
    pass
ep("pprint(A.__dict__)")

class B(object):
    pass
ep("pprint(dict(object.__dict__))")
ep("pprint(dict(B.__dict__))")


a = A()
b = B()
ep("print(B.__dict__['__dict__'])")
ep("pprint(a.__dict__)")
ep("pprint(b.__dict__)")

pp("object.__file__")
ep("print [ i for i in dir(os) if '__' in i ]")
ep("print os.__file__, os.__name__, __name__")
ep("print re.__file__")
ep("print logging.__file__")

'''
#__init__.py will run when you import a package.
  For instance, import idlelib within a program, runs idlelib/__init__.py
#__main__.py will run when you run a package as the main program.
  For instance, python -m idlelib at a command line runs idlelib/__main__.py,

#1.  sys.path
As long as the parent directory is on sys.path you will be able to call:
import mymodule       #or
from mymodule.submodule import something

#2.  __init__.py
You are dealing with a package. The package structure you should have is:
/dir_in_sys.path
    /mypackage             # This is not really a module - it's a package
        __init__.py         # loaded when you `import mypackage` or anything below it
        some.py             # import mypackage.some
        /submodule
            __init__.py       # loaded when you `import mypackage.submodule` or anything below it
            submodule_impl.py # import mypackage.submodule.submodule_impl
2.1 suppose class CustomClass is defined in the submodule_impl.py module
2.2  in __init__.py, add below
from .submodule_impl import CustomClass
2.3 #Now CustomClass can be imported directly from submodule
from mymodule.submodule import CustomClass
'''

pp("__init__.py")

# for example below:
# 1. import unitest will run __init__.py automaticaly
# 2. in __init__.py, result.py is importted
# 3. as a result all classes in result.py can be used now
import unittest

ep("print unittest.__file__")
ep("print [x for x in open(unittest.__file__[0:-1]) if 'from .result' in x]")
ep("print next(x for x in open(unittest.__file__[0:-1]) if 'from .result' in x)")
ep("print unittest")
ep("print unittest.result")
ep("print unittest.TestResult")


############################ atexit, signal ####################################################################
pp("atexit")
import atexit
ep('assert True, "it is True, so no output"')
ep("assert 'tough' in 'toughtough'")

# Below will throw out AssertionError exception, and exit
# assert False, "the result is False."
# print "this will not be executed"

'''
pp("atexit decorator")

@atexit.register
def goodbye():
    print 'Goodbye, no more message will be displayed'


print "before run sys.exit()"
# sys.exit()        #uncomment this to test
print "after run sys.exit()"
'''

peep("signal", """
import signal
print signal.__doc__
def signal_handler(signal, frame):
    print 'signal -->', signal
    print 'frame -->', frame
    print dir(frame)
    #print frame.f_globals
    #print frame.f_locals
    #print frame.f_trace
    print('You pressed Ctrl+C!')
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)
print('Press Ctrl+C')
print signal.pause.__doc__
signal.pause()
""", ebrun, 0)
#sys.exit()



peep("bitwise", '''
a = 60            # 60 = 0011 1100 
b = 13            # 13 = 0000 1101 
c = 0
print a & b;        # 12 = 0000 1100
print a | b;        # 61 = 0011 1101 
print a ^ b;        # 49 = 0011 0001
print ~a;           # -61 = 1100 0011
print a << 2;       # 240 = 1111 0000
print a >> 2;       # 15 = 0000 1111

#use bitwise to check if even or odd
print 383 & 1
print 888 & 1

aa = 123
if aa & 1: print "it is odd"
''', ebrun, 0)
#sys.exit()

peep("True is 1, False is 0", """
print "true" if 1 else "false"
print "true" if 0 else "false"
print "true" if '' else "false"
print "true" if [] else "false"
print "true" if False else "false"
print "true" if None else "false"

print True + True
print False + False
print True + False
print True == 1, True == 0, True == 2
print False ==1, False ==0, False ==2

""", ebrun, 0)
#sys.exit()

pp("tenary")
ebrun('''
x='021'; y =(x=='021' and "SH" or "not SH"); print y; #SH
x='021'; y = x=='021' and "SH" or "not SH";  print y; #SH
x='010'; y = x=='021' and "SH" or "not SH";  print y; #not SH
y = 1        and "SH" or "not SH";  print y; #SH
y = 0        and "SH" or "not SH";  print y; #not SH
''')

pp("calendar")
ebrun('''
import calendar
cal = calendar.month(2016, 4)
print cal
print type(cal)
#Returns a 3-column calendar for an entire year as a multi-line string using the formatyear() of the TextCalendar class.
#w  The width between two columns. Default value is 2.
#l  Blank line between two rows. Default value is 1. 
#c  Space between two months (Column wise). Default value is 6. 
#m  Number of months in a row. Default value is 3.  
print calendar.calendar(1975,2,1,6,3)
''')

pp("callable() function. The function checks if an object is a callable object. Or in other words, if an object is a function. ")
ebrun('''
print callable.__doc__
class Car:
    def setName(self, name):
        self.name = name

c = Car(); print callable(c.setName)
def fun(): pass
print callable(fun)
print callable([])
print callable(1)
''')

pp("cmp")
ebrun('''
print dir(cmp)
print cmp.__doc__
print cmp.__class__
print cmp(5,10)
print cmp(10,10)
print cmp(10,5)
''')

pp("for break continue else")
ebrun('''
def func(p1):
    for i in xrange(p1+1):
        if i==7: print "break out!"; break
        if i==2: print "two",; continue
        print i,
    else:
        print "done!"
func(10)
func(5)
''')

pp("try except else")
ebrun('''
def func(*a_list):
    try:
        print 'the list is:', a_list
        print 'third element:', a_list[2]
    except IndexError:
        print 'raised IndexError'
    else:
        print 'no error in try-block'
func()
func(1,2,3)
''')

pp("while else")
erun('''
i = 0
while i < 2:
    print 'in while: ', i
    i += 1
else:
    print 'in else: ', i   
''')

pp("for else")
erun('''
for i in range(2):
    print 'in while: ', i
else:
    print 'in else: ', i
   
''')

pp("deepcopy")
import copy

ebrun('''
a = [[1,2,3],[4,5,6]]
b = a
a.append(7); print a; print b           #make change to a; b also changed

##shallow copy
import copy
a = [[1,2,3],[4,5,6]]
b = copy.copy(a)
a.append(7); print a; print b           #make change to a; b not changed because of copy 
a[0][0] = 0; print a; print b           #make change to a; b also changed because of shallow copy only

##deep copy
import copy
a = [[1,2,3],[4,5,6]]
b = copy.deepcopy(a)
a.append(7); print a; print b  
a[0][0] = 0; print a; print b  


aa = [3, 2, 1]
bb = aa
#an interesting way to do deep copy
cc = aa[:]
print id(aa), id(bb), id(cc)
aa.append(4)
print aa, bb, cc
#dict deep copy
''')

################################ collections ##################################################################################

peep("collections.OrderedDict", """
from collections import OrderedDict
###class collections.OrderedDict([items])
###  Ordered dictionaries are just like regular dictionaries but they remember the order that items were inserted.
###  When iterating over an ordered dictionary, the items are returned in the order their keys were first added.
print sorted.__doc__
print OrderedDict.__doc__
## regular unsorted dictionary
d = {'banana': 3, 'apple': 4, 'pear': 1, 'orange': 2}
## sort by key, return a list
print sorted(d.items(), key=lambda t: t[0])

## dictionary sorted by key
print OrderedDict(sorted(d.items(), key=lambda t: t[0]))
## dictionary sorted by value
print OrderedDict(sorted(d.items(), key=lambda t: t[1]))
## dictionary sorted by length of the key string
print OrderedDict(sorted(d.items(), key=lambda t: len(t[0])))
""", eep, 0)
#sys.exit()


##Usually, a Python dictionary throws a KeyError if you try to get an item with a key that is not currently in the dictionary.
##The defaultdict in contrast will simply create any items that you try to access (provided of course they do not exist yet).
##
##To create such a "default" item, it calls the function object that you pass in the constructor (more precisely, it's an arbitrary "callable" object, which includes function and type objects).
##
##1.
##For the first example, default items are created using int(), which will return the integer object 0.
##
##2.
##For the second example, default items are created using list(), which returns a new empty list object.
# defaultdict is just a subclass of the standard dict type
peep("defaultdict for int, list, dict", '''
from collections import defaultdict
import inspect
print inspect.getmro(defaultdict)
print int()
print list()
print dict()
s = 'mississippi'

#default items are created using int(), which will return the integer object 0.
d = defaultdict(int)
print d
for k in s:
    d[k] += 1  #int() will be called when d[k], and assign d[k] = int()
print d
print d.items()

#default items are created using list(), which returns a new empty list object.
s = [('yellow', 1), ('blue', 2), ('yellow', 3), ('blue', 4), ('red', 1)]
d = defaultdict(list)
print d

###list() will be called whtn d[k], and assgin d[k]=list()
for k, v in s:
    d[k].append(v)   
print d

#default items are created using dict(), which returns a new empty dict object
data=defaultdict(dict)
for n in xrange(7):
    data[n]["rnc"] = "RNC" + str(n)
    data[n]["lac"] = "LAC" + str(n)
print data
for n in xrange(7):
    print str(n) + '--> ' + str(data[n])
''', ebrun, 0)
#sys.exit()

pp("collections.deque")

ebrun('''
###Deques support thread-safe, memory efficient appends and pops from either side of the deque
###Deques are a generalization of stacks and queues the name is pronounced "deck" and is short for "double-ended queue"

from collections import deque

##deque([iterable[, maxlen]]) --> deque object
d = deque('lo');
print d
##extend(iterable), extendleft(iterable)
d.extend('ves');
print d
##append(x), apend on both sides
d.append('physics')
d.appendleft('Evan')
print d
##iterate over the deque's elements
for elem in d:
    print elem.upper(),
##pop() on both sides
d.pop();
print d
d.popleft();
print d
##reverse
print reversed(d)
print deque(reversed(d))
print list(reversed(d))
##rotate
d.rotate(1);
print d
d.rotate(-1);
print d
##slice just as list
print d[0], d[-1]
print 'o' in d
##clear
d.clear();
print d
''')
#sys.exit()

pp("collections.namedtuple")
ebrun("""
from collections import namedtuple
###Named tuples assign meaning to each position in a tuple and allow for more readable, self-documenting code. 
###they add the ability to access fields by name instead of position index.

###      namedtuple(typename, field_names[, verbose=False][, rename=False])
#Point = namedtuple('Point',  ['x', 'y'],   verbose=True)
Point  = namedtuple('Point',  ['x', 'y'])
## instantiate with positional or keyword arguments
p = Point(11, y=22)     

## by index like the plain tuple (11, 22)
print p[0] + p[1]       
## by name new feature
print p.x + p.y               

## readable __repr__ with a name=value style
print p                       
##others
x, y = p; print x, y

""")
#sys.exit()


pp("collections.Counter")
ebrun('''
from collections import Counter
import inspect

##A Counter is a dict subclass for counting hashable objects.
print inspect.getmro(Counter)

##class collections.Counter([iterable-or-mapping])
c = Counter();                      print c
c = Counter({'red': 4, 'blue': 2}); print c
c = Counter(['eggs', 'ham']);       print c
c = Counter('gallahad');            print c
c = Counter(cats=4, dogs=8);        print c

##for missing items return 0, instead of raising a KeyError
c = Counter(['eggs', 'ham']);       print c, c['hello'], c.get('hello')

## elements() return an iterator over elements repeating each as many times as its count
c = Counter(a=4, b=2, c=0, d=-2);   print c.elements(); print list(c.elements())

## most_common([n]) Return a list of the n most common elements and their counts from the most common to the least
print Counter('abracadabra').most_common(3)

## subtract([iterable-or-mapping]) Elements are subtracted from an iterable or from another mapping (or counter).
c = Counter(a=4, b=2, c=0, d=-2)
d = Counter(a=1, b=2, c=3, d=4)
c.subtract(d); print c
print sum(c.values())            # total of all counts, aka, 3 + 0 + (-3) + (-6)
c+=Counter();  print c           # remove zero and negative counts

##
c = Counter(a=3, b=1)
d = Counter(a=1, b=2)
print c + d                       # add two counters together:  c[x] + d[x]
print c - d                       # subtract (keeping only positive counts)
print c & d                       # intersection:  min(c[x], d[x])
print c | d                       # union:  max(c[x], d[x])
''')
#sys.exit()

############################ StringIO ######################################################
###when you need to build a huge string, please use cStringIO
###myview: cStringIO is similiar to StringBuffer in Java
peep("cStringIO", '''
import cStringIO

output = cStringIO.StringIO()
output.write('First line.\\n')
# add the \\n automatically
print >> output, 'Second line.'
output.write('Third line.\\n')

# Retrieve file contents -- this will be
# 'First line.\\nSecond line.\\nThird line.\\n'
contents = output.getvalue()
print contents
# Close object and discard memory buffer, .getvalue() will now raise an exception.
output.close()''', ebrun, 0)
#sys.exit()

peep("StringIO", """
##io.StringIO       is a class. It handles Unicode. It reflects the preferred Python 3 library structure.
##StringIO.StringIO is a class. It handles strings. It reflects the legacy Python 2 library struct
##cStringIO.StringIO  is faster version of StringIO.StringIO

import timeit
test_join='''a=[]
for i in range(100):
    a.append('a')
'''

test_StringIO='''from StringIO import StringIO
a = StringIO()
for i in range(100):
    a.write('a')
'''
test_cStringIO='''from cStringIO import StringIO
a = StringIO()
for i in range(100):
    a.write('a')
'''
print(timeit.timeit(test_join, number=1))
print(timeit.timeit(test_StringIO, number=1))
print(timeit.timeit(test_cStringIO, number=1))

""", eep, 0)
#sys.exit()

##################################### dict ############################################################################
pp("use dict to store list")
ebrun('''
### if elements in dict are list, how to give default value '[]' 
##1. when use dict, no default value build in for dict
contxt = {}
if True:
    if "name_list" in contxt:
        contxt["name_list"].append("Fiona")
    else:
        contxt["name_list"] = ["Fiona"]
print contxt
''')

pp("use defaultdict to store list")
ebrun('''
##2. when use defaultdict, default value is available for all elements
from collections import defaultdict
contxt = defaultdict(list)
contxt["name_list"].append("Fiona")
print contxt
''')

pp("use dict setdefault")
ebrun('''
##3. use setdefault to set default for only one element
contxt = {}
contxt.setdefault("name_list", []).append("Fiona")
print contxt

contxt = {}
print contxt.get("name_list", [])
print contxt.get("name_list")
''')

pp("use fromkeys")
ebrun('''
##4. use fromkeys to set default for multiple elements
#   fromkeys() creates a new dictionary with keys from seq and values set to value.
#   dict.fromkeys(seq[, value]))
lst = ['name_list', 'school_list']
#warn: the value [] is for all elements, so normaly we should use immutable as value
contxt = {}.fromkeys(lst, [])
print contxt
contxt['name_list'].append("Fiona")
print contxt
#                ^^^^^^                  ^^^^^^^
''')

pp("make dict with two list")
ebrun('''
keys = ['a', 'b', 'c']
values = [1, 2, 3]
print zip(keys, values)
dd = dict(zip(keys, values))
print dd
#reverse dict
print {v: k for k, v in dd.items()}
#another way to reverse dict
print                 dd.items()
print            zip(*dd.items())
print            zip(*dd.items())[::-1]
print      zip(*(zip(*dd.items())[::-1]))
print dict(zip(*(zip(*dd.items())[::-1])))
#the 3rd way
print dict(zip(dd.values(), dd.keys()))
''')
#sys.exit()


pp("dir")
ebrun('''
###dir() function
##dir() is the most important function when doing introspection. The function returns a sorted list of attributes and methods belonging to an object
###why dir() doesn't display __dict__ attribute
print dir.__doc__

class Foo:
    def __init__(self):
        self.a = "bar"
        self.b = 4711
global a
a=Foo(); 
print type(Foo), dir(Foo)
print type(a),   dir(a)
print a; print a.__class__; print a.__class__.__name__
print type(1),   dir(1)
print type(int), dir(int)
''')
#sys.exit()

pp("__dict__")
ebrun('''
class Base():
    def __init__(self, conf):
        print self
        self.__conf__ = conf
        print self.__dict__
        print dir(self)
class Test(Base):
      a = 1
      b = 2
      def func1(self):
        self.c = "hello"

## self is instance of subclass
t = Test("myconf")
print t
##__dict__ only contains attributes of instance itself
print t.__dict__
t.func1()
print t.__dict__
##dir() contains __dict_ and class attribues,etc
print dir(t)


''')


pp("enumerate")

##enumerate(sequence, start=0)
#Return an enumerate object. sequence must be a sequence, an iterator, or some other object which supports iteration. The next() method of the iterator returned by enumerate() returns a tuple containing a count (from start which defaults to 0) and the values obtained from iterating over sequence:
#
##my_enumerate() below is similar to enmerate(), however
#The real enumerate function returns an iterator, not an generator. You can see this if you call help(x) after doing creating an enumerate object:
#
#In Python, generators are basically a specific type of iterator that's implemented by using a yield to return data from a function.
#However, enumerate is actually implemented in C, not pure Python, so there's no yield involved. You can find the source here: http://hg.python.org/cpython/file/2.7/Objects/enumobject.c
#

ebrun('''
def my_enumerate(sequence, start=0):
    n = start
    for elem in sequence:
        yield n, elem
        n += 1
# 1
e=enumerate    (["spring", "summer","fall" ,"winter"], 1)
##enumerate return an iterator(enumerate is iterator)
print type(e), dir(e)
print list(e)
import inspect; print inspect.getmro(enumerate)

# 2 
##my_enumerate return a generator
e=my_enumerate (["spring", "summer","fall" ,"winter"], 1)
print type(e), dir(e)
print list(e)

## use for loop
e=enumerate    (["spring", "summer","fall" ,"winter"])
for i in e: print i
e=my_enumerate (["spring", "summer","fall" ,"winter"])
for i in e: print i
''')

pp("eval and exec")
ebrun('''
#eval and exec have these two differences:
#eval: take a single expression, return a value
#exec: take a block,             return None 
#
#1.eval accepts only a single expression, 
#  exec can take a code block that has Python statements: loops, try: except:, class and function/method definitions and so on.
#2.eval returns the value of the given expression, 
#  exec always returns None, ignores the return value from its code

a=5; a = eval('37 + a'); print a          #42
a=5; exec('a = 37 + a'); print a          #42 
#a=5; eval('a = 37 + a')                   #SyntaxError: invalid syntax, you cannot evaluate a statement with eval
''')

pp("try except raise")
###1. the way to capture multiple exceptions is use a tuple as the first parmamter of except
###2. and always use 'as', for both python 2&3 support it
erun("""
try:
    l = ["a", "b"]
    int(l[2])
except (ValueError, IndexError) as e:  
    print "expection captured"

""")

erun("""
##raise an exception
#raise NameError('HiThere')

#raise then capture an exception
try:
    raise NameError('HiThere1')
except NameError:
    print 'An exception captured!'
""")

erun("""
##re-raise the same exception
#If you need to determine whether an exception was raised but don't intend to handle it, a simpler form of the raise statement allows you to re-raise the same exception:
try:
    raise NameError('HiThere2')
except NameError:
    print 'An exception flew by!'
    #raise    #comment out the raise NameError
""")
################################### filter, map, reduce #######################################################
peep("filter and map", """
##The function filter(function, list) offers an elegant way to print out all the elements of a list, that for which the function function returns True. 

fib = [0,1,1,2,3,5,8,13,21,34,55]
print "Odd numbers: ", filter(lambda x: x % 2, fib)
print "Even numbers:", filter(lambda x: x % 2 == 0, fib)

##print all elements start with 'h'
f = ['hello',"where", 'hare', "hmm"]
print filter(lambda x: x[0:1] == 'h', f)
print filter(lambda x: x.startswith('h'), f)

import os
#current dir
dir1 =  os.path.dirname(os.path.abspath(os.getcwd())); print dir1
dir2 = os.path.dirname(dir1);                          print dir2
flst = os.listdir(dir1);                               print flst
##print files starting with 'c'
flt1 = filter(lambda x: x.startswith('c'), flst);      print flt1

##removing the '.py' extension
flt2 = map(lambda x: x.rstrip('.py'), flst);           print flt2
""", ebrun, 0)
#sys.exit()


peep("map", """
##map(function, iterable, ...)
##Apply function to every item of iterable and return a list of the results
print map(lambda x: x*x, [1,2,3])

##map with two iterables for input
a = [1, 2, 3, 4]
b = [2, 3, 4, 5]
print map(lambda x, y: x*y, a, b)

#check if items in a list exits in a string
alist = ["scala", "akka", "play framework", "sbt", "typesafe"]
print map(lambda x: x in "This is an example tweet talking about scala and sbt.".split(), alist)
print [ x in "This is an example tweet talking about scala and sbt.".split() for x in alist ]          #[True, False, False, False, False]
""", ebrun, 1)
#sys.exit()


peep("reduce", """
###The function reduce(func, seq) continually applies the function func() to the sequence seq. It returns a single value. 
##reduce(func, seq)
##reduce(func, [ s1, s2, s3, ... , sn ])
##reduce(func(s1, s2), [ s3, s4, s5... , sn ])
##reduce(func(func(s1, s2),s3), [s4, s5 ... ,  sn ])
##.....

##the largest number
f = lambda a,b: a if (a > b) else b
result=reduce(f, [47,11,42,102,13]); print result

##1 + 2 + 3 ...+ 10
result=reduce(lambda x, y: x+y, range(1,10)); print result

##turn [1, 2, 3, 4, 5, 6, 7, 8] into 12345678
result=reduce(lambda x, y: 10*x+y, range(1,9)); print result

##turn [[1, 2, 3], [4, 5], [6, 7, 8]] into [1, 2, 3, 4, 5, 6, 7, 8]
result=reduce(list.__add__,[[1, 2, 3], [4, 5], [6, 7, 8]]); print result
""", ebrun, 0)
#sys.exit()

########################### arguments ####################################################
pp("positional arguments and named arguments")
ebrun("""
##use individual parameters
def func(p1,p2): 
    print(p1, p2)
print func.__doc__
tup=("param1","param2")
func("param1","param2")
func(*tup)

##The single star * unpacks the sequence/collection into positional arguments, use tuple as parmaters instead
def func(*t): print(t)
tup=("one", 2, 3.0)
func("one", 2, 3.0)
func(*tup)

##The double star ** does the same, only using a dictionary and thus named arguments, use dict as parameter
def func(**ages): 
    print(ages)  #**ages is dictionary
    print "the age of dad, mom, lisa are: %(dad)s, %(mom)s, %(lisa)s" % ages
dic={'dad':42,'mom':48,'lisa':7}; 
func(**dic)
func(dad=42,mom=48,lisa=7)

#The double star ** uses a dictionary --> named arguments
def func(particle, weight=0): print "the weight of %s is %s" %(particle, weight)
d={"particle": "neutrino", "weight": 0.001}
func(**d)

##parameters with default value
def func4(p1='tst1',p2='tst2'): print(p1+" "+p2)
func4()

###function with tuple and dictionary as parameters
#first, last only take one parameters respectively
#*numbers takes as many as possible until a '=' 
#**items takes all parameters start with a '='
def profile(first, last, *numbers, **items):
    print first, last
    print numbers
    print items
profile('bucky', 'roberts', 1,2,3,4,5, bacon=4, saus=64)

""")

pp("generator")
ebrun("""
#myview:
#1. creating a function with yield statement in it
#2. then the function would return a generator object
#3. generator object is a iterator object, support next() method
#
#myview:
#1. generator function is a function with yield statement inside
#2. generator function return generator object
#3. generator object is iterator

#Every generator is an iterator, but not vice versa. A generator is built by calling a function that has one or more yield 
def city_generator():
    yield("Konstanz")
    yield("Zurich")
    yield("Schaffhausen")
    yield("Stuttgart")

x=city_generator()
#import inspect; inspect.getmro(x)
print type(x), type(type(x))
print x
print x.next()
print x.next()
print x.next()
print x.next()

#'i for i in list if' syntax will return a generator
g=(x for x in os.listdir('/etc') if '.conf' in x)
print g
print g.next()
print g.next()
print g.next()
g2=[x for x in glob.glob('/etc/*.conf')]
print g2
""")

pp("glob")
ebrun("""
import glob
for sfile in glob.glob("/etc/r*.conf"):
    print sfile
""")


pp("dec and hex");
ebrun("""
#dec to hex
print hex(16)           #0x10
print "%X"     % 16     #10
print "%x"     % 16     #10
print "0x%x"   % 16     #0x10
print "0x%x"   % 1616   #0x650
print "0x%2x"  % 1616   #0x650
print "0x%17x" % 1616   #0x              650

print ord.__doc__
print chr.__doc__

print ord('a'), chr(ord('a'))  #97 a
print ord('1'), chr(ord('a'))  #49 a

s = "Hello world!"
print ":".join(            str(ord(x))for x in s)  #72:101:108:108:111:32:119:111:114:108:100:33
print ":".join(  '%d'  %       ord(x) for x in s)  #72:101:108:108:111:32:119:111:114:108:100:33
print ":".join(  '%x'  %       ord(x) for x in s)  #48:65:6c:6c:6f:20:77:6f:72:6c:64:21
print ":".join( '%0X'  %       ord(x)  for x in s) #48:65:6C:6C:6F:20:77:6F:72:6C:64:21
print ":".join("{:02x}".format(ord(x)) for x in s) #48:65:6c:6c:6f:20:77:6f:72:6c:64:21
print ":".join(            hex(ord(x)) for x in s) #0x48:0x65:0x6c:0x6c:0x6f:0x20:0x77:0x6f:0x72:0x6c:0x64:0x21

#a list of A-E
print map(lambda x: chr(x), xrange(ord('A'),ord('E')+1))     #['A', 'B', 'C', 'D', 'E']
print    [ chr(x) for x in xrange(ord('A'), ord('E')+1)]     #['A', 'B', 'C', 'D', 'E']
print    ( chr(x) for x in xrange(ord('a'), ord('z')+1))     #<generator object <genexpr> at 0x7f16f2c915f0>
""")


############################################ inspect ###########################################
peep("id", """
##Return the identity of an object. This is an integer (or long integer) which is guaranteed to be unique and constant for this object during its lifetime.
##
##id() (or its equivalent) is used in the is operator.
##
import copy
foo = 1; bar = foo; print id(foo), id(bar)
list = [1,2,3]; print id(list), id(list[0]), id(list[1]), id(list[2])
for i in list: print id(i), 

#for imutable, copy.copy() don't really copy
list2 = copy.copy(list); print id(list2)
for i in list2: print id(i),
""", ebrun, 0)
#sys.exit()

peep("hasattr", """
##The hasattr() function checks if an object has an attribute. The getattr() function returns the contents of an attribute if there are some.

##class attributes:
class Foo:
    def __init__(self):
        self.a = "bar"
        self.b = 4711
    def bar(): pass
foo=Foo()

#object
print object.__dict__
print dir(object)
for i in dir(object): print "class object has attribute", i,":", hasattr(object, i)
#Foo
print Foo.__dict__
print dir(Foo)
for i in dir(Foo): print "class Foo has attribute", i,":", hasattr(Foo, i)
#foo
print foo.__dict__
print dir(foo)
for i in dir(foo): print "instance foo has attribute", i,":", hasattr(foo, i)
for i in dir(foo): print "instance foo's  attribute", i,":", getattr(foo, i)

##function attributes:
def fun(): pass
print fun.__dict__
print dir(fun)
for i in dir(fun): print "function fun() has attribute", i,":", hasattr(fun, i)
#for i in dir(fun): print "function fun()'s attribute", i,":", getattr(fun, i)
""", ebrun, 0)
#sys.exit()

pp("inspect.getcallargs()")
ebrun("""
import inspect
def f(a, b=1, *pos, **named):
    pass
print inspect.getcallargs(f,7)
print inspect.getcallargs(f,7,2)
print inspect.getcallargs(f,7,2,'a','b','c')
m={'d':'dd', 'e':'ee'}
print inspect.getcallargs(f,7,2,'a','b','c',**m)
""")

pp("inspect.getmembers()")
ebrun("""
##All functions of the module re:
print inspect.getmembers(re, inspect.isfunction)
#or:
print dir(re); print type(re)
""")

pp("inspect.getmro()")
ebrun("""
##inspect.getmro(cls)
##mro --> method resolution order
##Return a tuple of class cls's base classes, including cls, in method resolution order. No class appears more than once in this tuple. Note that the method resolution order depends on cls type. Unless a very peculiar user-defined metatype is in use, cls will be the first element of the tuple.
import inspect
print inspect.getmro.__class__
print inspect.getmro.__doc__

class A(object): pass
class B(A): pass
print inspect.getmro(B)
print B.__base__
print B.__base__.__base__
print B.__base__.__base__.__base__
""")

pp("isinstance()")
ebrun("""
##isinstance(object, classinfo)
##  check if the object argument is an instance of the classinfo argument
##  classinfo need to be a class object nor a type object
print isinstance ("hello", str)
print isinstance ("hello", object)
print isinstance (123.0, float )
print isinstance (False, bool )
print isinstance (0, bool )
print isinstance(u'foo', (str))
print isinstance(u'foo', (str,basestring))
print isinstance(u'foo', (str,unicode))
print isinstance([], list)
print isinstance((), tuple)
""")

pp("issubclass()")
ebrun("""
class MyObject():
   def __init__(self):
      pass
class Wall(MyObject):
   def __init__(self):
      pass
import inspect; print inspect.getmro(Wall)
print issubclass(MyObject, MyObject)
print issubclass(MyObject, Wall)
print issubclass(Wall, MyObject)
print issubclass(Wall, Wall)

""")
#sys.exit()

############################## iterator, generator ############################################################
pp("iterator")
ebrun("""
##what is iterable: 
#An iterable is an object that you can get an iterator from.
#list, str, xrange, dict, file are iterable
#An iterable is an object that has 
#1. __iter__()   #method which returns an iterator,  or
#2. __getitem__  #method 

##what is iterator:
#An iterator is an object with a next (Python 2) or __next__ (Python 3) method. 
#Iterator objects are required to support the following two methods
#1. __iter__()
#    Return the iterator object itself
#    allow both containers and iterators to be used with the for and in statements.
#2. next()   #I think it's generator instead of Iterator
#    Return the next item from the container. If there are no further items, raise the StopIteration exception. 

#Whenever you use a for loop, or map, or a list comprehension, etc. in Python, the next method is called automatically to get each item from the iterator, thus going through the process of iteration.

##iterable
#1. Iterable_instance.__iter__()  --> Iterrator_instance
#2. iter(Iterable_instance)       --> Iterrator_instance
#3. Iterable_instance.__getitem__()->  the item of the index
##iterator
#1. Iterator_instance.__iter__() --> get the iterator itself
#2. Iterator_instance.next()      --> get item for python 2
#3. Iterator_instance.__next__()  --> get item for python 3

#fname=os.path.dirname(os.path.abspath(__file__))+'/color.py'
fname=os.path.join(os.path.expanduser('~'), 'graduation/python/color.py')
x=[1,2,3];           print type(iter(x)), type(x.__iter__()), x.__getitem__(1)
x='123';             print type(iter(x)),                     x.__getitem__(1)
x=xrange(1,4);       print type(iter(x)), type(x.__iter__()), x.__getitem__(1)
x=range(1,4);        print type(iter(x)), type(x.__iter__()), x.__getitem__(1)
with open(fname) as x:print type(x), type(iter(x)), type(x.__iter__())

i=iter([1,2,3]);     print i.next(), i.next(), i.next()
i=iter('123');       print i.next(), i.next(), i.next()
i=iter(xrange(1,4)); print i.next(), i.next(), i.next()
i=iter(range(1,4));  print i.next(), i.next(), i.next()
i=open(fname);       print i.next(), i.next(), i.next()
ii=iter(i);          print ii.next(),ii.next(),ii.next(); i.close()

#use the 'globl' next() method
i=iter([1,2,3]);     print next(i), next(i), next(i)
i=open(fname);       print next(i), next(i), next(i); i.close()

#iterator type 1 --> str
print "__getitem__" in  dir(str)
for c in 'python': print c

#iterator type 2 --> list
for i in [1,2,3,4]: print i
for i in iter([1,2,3,4]): print i

#iterator type 3: dictionary
for k in {"feng":36, "yu":25, "zhong":27}: print k
for k in {"feng":36, "yu":25, "zhong":27}.keys(): print k
for k in {"feng":36, "yu":25, "zhong":27}.values(): print k
for k in {"feng":36, "yu":25, "zhong":27}.items(): print k
#iterator type 4: read file
with open("/etc/hosts") as f:
    print type(f) 
    for line in f: print line,
""")
#sys.exit()

########################################## itertools ###########################################
pp("itertools.chain(),count(),repeat(),cycle()")
ebrun("""
import itertools
##1. itertools.chain(*iterables)
print [ i for i in itertools.chain('ABC', 'DEF','XYZ') ]

#user defined equivelent
#chain('ABC', 'DEF') --> A B C D E F

def chain(*iterables):
    for it in iterables:
        for element in it:
            yield element

##2. itertools.count(start=0, step=1: once for each integer, Infinite!
for num in xrange(10008):
    if num < 10000: continue
    print num,

#same as below
for num in itertools.count():
    if num < 10000: continue
    if num > 10007: break
    print num,

##3. chain, repeat, cycle
##   itertools.cycle(iterable)
##   itertools.repeat(object[, times])
seq = itertools.chain(itertools.repeat(17,3), itertools.cycle(range(7, 11, 1)))
print seq
for count, num in enumerate(seq):
    if count > 20: break
    print num,
""")
#sys.exit()

pp("join")
ebrun("""
print ":".join(["a", "b", "c"])
print list("python")
print "".join(list("python"))

map={"guo":36, "zhi":25, "shang":27}
print list(map)
print "--".join(map)
print "--".join(list(map))
""")

pp("json.load()")
ebrun("""
import json
from pprint import pprint

cmd='''cat > AAT.conf <<EOF
{
    "data"              : "/home/eenmliu/aat/data01",
    "backup"            : "/home/eenmliu/aat/backup",
    "log-dir"           : "/home/eenmliu/aat/logs"
}
EOF
'''
os.system(cmd)
with open('AAT.conf') as f:
    print f.read()
    f.seek(0)
    data = json.load(f)
print type(data)
print data[u'log-dir']
print data['log-dir']
pprint(data)
""")

pp("Lambda")
ebrun("""
###Lambda expressions are a shorthand to create anonymous functions; yields a function object. 
## lambda
#  lambda arguments: expression 
## function
#  def name(arguments): return expression
import os
os.system('pydoc lambda|cat')

##equal to 'def sum(x,y): return x + y'
sum = lambda x,y: x + y
print sum(1,2)

def sum(x,y): return x + y
print sum(1,2)


##How to make a lambda, that takes a object as input, return the object's atribute "name"'s value
##aka:  lambda_fun(object) ---> return object.getname()
class A(object):
    name="hello"
#self is just the name of parameter, which is a object, which must have attribute 'name'
aaa = lambda self: self.__dict__['name'] 
print aaa(A)

#or
def makeGetter(attrName):
    return lambda self: self.__dict__[attrName]
aaa = makeGetter('name')
print aaa(A)

""")

pp("list")
ebrun("""
x = [ 1, 2 ,3 ]; print id(x), x  #140714377773496 [1, 2, 3]
x.append(4);     print id(x), x  #140714377773496 [1, 2, 3, 4]
x.append([4,5]); print id(x), x  #140714377773496 [1, 2, 3, 4, [4, 5]]
x.extend([4,5]); print id(x), x  #140714377773496 [1, 2, 3, 4, [4, 5], 4, 5]
x = x + [4, 5 ]; print id(x), x  #140714377754240 [1, 2, 3, 4, [4, 5], 4, 5, 4, 5]

list1=['1', '2', '3']; 
print      ''.join(list1)        #123
print list(''.join(list1))       #['1', '2', '3']

""")

pp("locals(), vars(), globals()")
ebrun("""
##globals() returns the dictionary of the module namespace
##          global variables can be accessed inside functions, but cann't be modified inside functions
##locals()  returns a dictionary of the current namespace
##vars()    returns either a dictionary of the current namespace (if called with no argument) or the dictionary of the argument.

map_l=locals(); print map_l
map_l=locals(); print type(map_l)
map_l=locals(); print map_l.get("name")
map_l=locals(); name=""; print map_l
print globals()["__name__"]
print vars()

ages={'dad':42,'mom':48,'me':7}
ages.clear()          # remove all entries in dict
print ages if 'ages' in locals() else "ages not defined"

ages={'dad':42,'mom':48,'me':7}
del ages              # delete all entries
print ages if 'ages' in locals() else "ages not defined"

age = "16"
name = "Evan"
print "hello %(name)s you are %(age)s years old" % locals()


a_string="this is a global variable"
def foo():
    a_string = "this is local variable"
    print '''-->locals() variabls '''
    print locals()
    print '''-->vars() variabls '''
    print vars()

foo()
print '''-->global variabls '''
print globals()

""")

pp("logging stream=sys.stdout")
ebrun("""
### stream=sys.stdout
lightyear={'Sun':0,'Sirius':8.6}
import logging
#set the logging output level to debug, by default, sys.stderr will be used.
logging.basicConfig(level=logging.INFO,stream=sys.stdout)
#logging is hierarchical,getLogger() will return root logger
logger=logging.getLogger(__name__); print logger
logger.warn ('the distance of nearby stars: %s ' % lightyear)
logger.info ('the distance of nearby stars: %s ' % lightyear)
logger.debug('the distance of nearby stars: %s ' % lightyear)

### handler
logging.basicConfig(level=logging.INFO)
logger=logging.getLogger(__name__); print logger
#create a filehandle
handler=logging.FileHandler('/tmp/stars.log','w')
logger.addHandler(handler)
logger.warn ('the distance of nearby stars: %s ' % lightyear)
logger.info ('the distance of nearby stars: %s ' % lightyear)
logger.debug('the distance of nearby stars: %s ' % lightyear)
with open('/tmp/stars.log', 'r') as f: print f.read()

### format
logging.basicConfig(level=logging.INFO)
logger=logging.getLogger(__name__); print logger
#create a filehandle
handler=logging.FileHandler('/tmp/stars2.log','w')
logger.addHandler(handler)
fmt1=logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s') 
fmt2=logging.Formatter('%(asctime)s %(levelname)s %(threadName)s: %(message)s','%b %d %H:%M:%S')
handler.setFormatter(fmt2) 
lightyear={'Sun':0,'Sirius':8.6}
logger.warn ('the distance of nearby stars: %s ' % lightyear)
logger.info ('the distance of nearby stars: %s ' % lightyear)
logger.debug('the distance of nearby stars: %s ' % lightyear)
with open('/tmp/stars2.log', 'r') as f: print f.read()
""")

pp("magic *****")
ebrun("""
#e1 = Employee('evan' 'liu',10000)
#
#str(e1)     --> call e1.__str__()
#repr(e1)    --> call e1.__repr__()

#e1+e2       --> call e1.__add__(e2)
#'a'+'b'     --> call str.__add__('a','b')
#1+2         --> call int.__add__(1,2)

#'ls'>'la'   --> call 'ls'.__ge__('la')
#            --> call str.__ge__('ls','la')

#len('ls')   --> call 'ls'.__len__()
import inspect
class Employee:
    def __str__(self):
        return inspect.stack()[0][3] + " called"
    def __repr__(self):
        return inspect.currentframe().f_code.co_name + " called"
    def __add__(self, n):
        return inspect.currentframe().f_code.co_name + " called"
e1 = Employee()
e2 = Employee()
print str(e1)            #__str__ called
print repr(e2)           #__repr__ called
print e1 + e2            #__add__ called
""")


pp("math")
ebrun("""
import math
#square root
print math.sqrt(81)
print math.sqrt.__doc__
#all the functions of module math
print dir(math)
#help(math) shows the help of each functions
#__doc__ to show help
for i in dir(math):
    #exec "print math.%s.__doc__" % i
    print "math.%s.__doc__" % i
    print
""")

###################################### subprocess ############################################
pp("os and subprocess")
ebrun("""
###           errorcode                                output
# --------------------------------------------------------------------------------
##  shell     os.system("ls -al")                      os.popen(ls -al).read()
##            subprocess.call('ls -al',shell=True)     subprocess.check_output('ls -al', shell=True)
##                                                     subprocess.popen()
# -----------------------------------------------------------------------------------------------
##  python    subprocess.call(['uname', '-a'])         subprocess.check_output(['ls', '-al'])
##

##if you need to get the error code,
# use os.system()
# use subprocess.call()
##if you need to get the stdout,
# use os.popen
# use subprocess.popen
# use subprocess.check_output (in python2.7)
import subprocess

os.system('ls -al |head -n3')
print os.popen('ls -al |head -n3').read()

#shell=True is only available in subprocess
subprocess.call('ls -al |head -n3', shell=True)
subprocess.check_output('ls -al |head -n3', shell=True)

errorcode=os.system('uname -a');    print errorcode
output=os.popen('uname -a').read(); print output
output=subprocess.check_output('uname -a', shell=True); print output
output=subprocess.check_output(['uname', '-a']);        print output
errorcode=subprocess.call('uname -a', shell=True);      print errorcode
errorcode=subprocess.call(['uname', '-a']);             print errorcode
""")

####################################### threading ######################################

peep("threading: inherent, no lock, no semaphore", """
import time
import threading
from random import randint
class AsyncPrint(threading.Thread):
    def __init__(self, text):
        threading.Thread.__init__(self)
        self.text = text
    def run(self):
        for i in range(1,10):
            time.sleep(randint(0,2))
            print self.text,
        print "Finished Background", self.text

background1 = AsyncPrint("#")
background2 = AsyncPrint("$")
background3 = AsyncPrint("^")
background1.start()
background2.start()
background3.start()
for i in range(1,5):
    time.sleep(randint(0,2))
    print "-",
print "Finished Main"
""", ebrun, 0)

peep("threading: no lock, no semaphore", """
#global tLock
#tLock = threading.Lock()
def timer(name, delay, repeat):
    c=colors.YELLOW
    if name=="Test2": c=colors.RED
    print c + 'timer: ' + name + " Started"+colors.ENDC
    #tLock.acquire(); print(c + name + " has acquired lock to some codes")
    while repeat > 0:
        time.sleep(delay)
        print c + 'timer: ' + name +": " + str(time.ctime(time.time())) + colors.ENDC
        repeat -= 1
    #tLock.release(); print(c + name + " released lock to the codes")
    print c + "Timer: " + name + " Completed"+colors.ENDC

threading.Thread(target=timer, args=("Test1", 1, 5)).start()
threading.Thread(target=timer, args=("Test2", 2, 5)).start()
print "Main Complete"
""", ebrun, 0)


#global not supported by ebrun
'''
pp("threading: lock")
global tLock
tLock = threading.Lock()
def timer(name, delay, repeat):
    c=colors.YELLOW
    if name=="Test2": c=colors.RED
    print c + 'timer: ' + name + " Started"+colors.ENDC
    tLock.acquire(); print(c + name + " has acquired lock to some codes")
    while repeat > 0:
        time.sleep(delay)
        print c + 'timer: ' + name +": " + str(time.ctime(time.time())) + colors.ENDC
        repeat -= 1
    tLock.release(); print(c + name + " released lock to the codes")
    print c + "Timer: " + name + " Completed"+colors.ENDC

threading.Thread(target=timer, args=("Test1", 1, 5)).start()
threading.Thread(target=timer, args=("Test2", 2, 5)).start()
print "Main Complete"
'''

peep("threading: inherent", """
import threading
import re
import urllib
import time
class WebpageThread(threading.Thread):
    def __init__(self, site):
        #super(WebpageThread,self).__init__()
        threading.Thread.__init__(self)
        self.site=site
        self.total=0
    def run(self):
        t1=time.time()
        #print "--> accessing to %s ..." % self.site
        u=urllib.urlopen("http://"+ self.site)
        text = u.read()
        #print "--> done with %s " % self.site
        self.total = time.time() - t1

sites = 'baidu.com|163.com|qq.com'.split('|')
#sites = 'google.com|facebook.com|linuxfromscratch.org'.split('|')
threadlst = []
t1=time.time()
for i in xrange(0,len(sites)):
    threadlst.append(WebpageThread(sites[i]))
for i in xrange(0,len(sites)):
    threadlst[i].start()
for i in xrange(0,len(sites)):
    threadlst[i].join()
total=0
for i in xrange(0,len(sites)):
    print "%-15s --> %-15s seconds" % (threadlst[i].site, threadlst[i].total)
    total += threadlst[i].total
actual = time.time() - t1
print "total time used: %d" % total
print "actual time used: %d" % actual
""", ebrun, 0)

########################################## multiprocessing #################################
pp("multiprocessing.Queue")
eep("""
# multiprocessing.Queue, a near clone of Queue.Queue, thread and process safe
from multiprocessing import Process, Queue
def f(q):
    q.put([42, None, 'hello'])
q = Queue()
p = Process(target=f, args=(q,))
p.start()
print q.get()                        #[42, None, 'hello'], #data retrieved from the subprocess by queue.
p.join()
""")
#sys.exit()

pp("multiprocessing.Pipe")
ebrun("""
#multiprocessing.Pipe, a pipe which by default is duplex (two-way)
from multiprocessing import Process, Pipe
def f(conn):
    conn.send([42, None, 'hello'])
    conn.close()
parent_conn, child_conn = Pipe()
p = Process(target=f, args=(child_conn,))
p.start()
print parent_conn.recv()            #[42, None, 'hello'],  #data retrieved from the subprocess by pipe.
p.join()
""")
#sys.exit()

pp("multiprocessing.Pool")  
eep("""
#start multiple new processes
##return value from all the processes will be in a list as Pool.map() function's return value
import multiprocessing
def f1(x): 
    return x*x
print multiprocessing.Pool(processes=4).map(f1,range(1,11))

#start multiple new processes
from multiprocessing import Process
from multiprocessing import Pool
def f(title):
    print '-->{}'.format(title)
    print 'module name:', __name__
    if hasattr(os, 'getppid'):  # only available on Unix
        print 'parent process:', os.getppid()
    print 'process id:', os.getpid()
    return title
print os.getpid()          ###current process, 43003
f('function all')          #not start a new process, parent process: 60652, process id: 43003
p  = Process(target=f, args=('function all with process',))
p.start()
p.join()                   #    start a new process, parent process: 43003, process id: 43004
p2 = Pool(5)               #    start multiple new processes ....
result = p2.map(f, ['function call {} in pool'.format(x) for x in xrange(7)])
print result

""")
#sys.exit()

pp("multiprocessing.Lock")
eep("""
import multiprocessing
l = multiprocessing.Lock()
def timer(tLock, name, delay, repeat):
    tLock.acquire();
    print 'delay %s, repeat %s' % (delay, repeat)
    tLock.release();
multiprocessing.Process(target=timer, args=(l, "Test1", 1, 5)).start()
multiprocessing.Process(target=timer, args=(l, "Test2", 2, 4)).start()

""")
#sys.exit()


######################### file #######################################################
pp("open")

eep("""
#mode can be 
#'r'     when the file will only be read,it's default with omitted
#'w'     for only writing (an existing file with the same name will be erased)
#'a'     opens the file for appending; any data written is added to the end. 
#'r+'    opens the file for both reading and writing. 
#'b'     Windows only, 'b' appended to the mode opens the file in binary mode, 
#        so there are also modes like 'rb', 'wb', and 'r+b'. 

fo = open('/etc/hosts','r')
print type(fo)
#some properties
print fo.name
print fo.closed
print fo.mode
print fo.softspace

#read(10): read 10 bytes to str
tenbytes=fo.read(10); print tenbytes

#readline: read a line to str
print fo.readline()

#read(): read all the rest str
content=fo.read(); fo.close()
print type(content); print content

#readlines(): read all lines to list
fo = open('/etc/hosts','r')
arr = fo.readlines(); fo.close()
print type(arr)
for i in arr: print i,
""")

pp("readlines()")
eep("""
##read file into list
with  open("/etc/hosts") as f: print f.readlines()
print open("/etc/hosts").readlines()
""")

pp("ord and chr")
eep("""
print ord.__doc__
print chr.__doc__
print ord('a'), chr(ord('a'))
print ord('1'), chr(ord('a'))

s = "Hello world!"
print ":".join( str(ord(x)) for x in s)
print ":".join( ('%0X' % ord(x) for x in s))
print ":".join("{:02x}".format(ord(x)) for x in s)
print ":".join( hex(ord(x)) for x in s)
#a list of A-Z, use map
l = map(lambda x: chr(x), xrange(ord('A'),ord('Z')+1)); print l
#a list of a-z, use 'x for x in'
print [ chr(x) for x in xrange(ord('a'), ord('z')+1)]
#a generator of A-Z, use 'x for x in'
g = ( chr(x) for x in xrange(ord('a'), ord('z')+1))
print g
print list(g)
""")


pp("os")
eep("""
###os.name is 'posix', 'nt', 'os2', 'ce' or 'riscos'
###os.curdir is a string representing the current directory ('.' or ':')
###os.pardir is a string representing the parent directory ('..' or '::')
###os.sep is the (or a most common) pathname separator ('/' or ':' or '\\')

###os.extsep is the extension separator ('.' or '/')
###os.altsep is the alternate pathname separator (None or '/')
###os.pathsep is the component separator used in $PATH etc
###os.linesep is the line separator in text files ('\\r' or '\\n' or '\\r\\n')
###os.defpath is the default search path for executables
###os.devnull is the file path of the null device ('/dev/null', etc.)
###difference between os.fchdir() and os.chdir()
##1.os.fchdir(fd)
# change the current working directory to the directory represented by the file descriptor fd. 
# The descriptor must refer to an opened directory, not an open file.
##2.os.chdir(str)
# ...
import os, sys
## use chdir()
# current working dir:
print os.getcwd()
# change current working dir to home dir:
os.chdir(os.path.expanduser("~")); print os.getcwd()

## use fchdir()
fd = os.open( "/tmp", os.O_RDONLY )
os.fchdir(fd); print os.getcwd()

##get pid and parent pid
print os.getpid(), os.getppid()

##os data values
print os.environ['HOME']
print type(os.environ)
print os.curdir
print os.pardir
print os.sep
print os.pathsep
print ">%s<"%os.linesep
print os.defpath
print os.devnull

##directory 
os.makedirs("/tmp/tmp1/tmp2"); print os.path.isdir("/tmp/tmp1/tmp2")
os.removedirs("/tmp/tmp1/tmp2");print os.path.isdir("/tmp/tmp1")
os.makedirs("/tmp/tmp1/tmp2"); print os.path.isdir("/tmp/tmp1/tmp2")
os.rmdir("/tmp/tmp1/tmp2")
os.rmdir("/tmp/tmp1")

##document
print os.remove.__doc__
print os.rmdir.__doc__
print os.removedirs.__doc__
print os.rename.__doc__
print os.stat.__doc__
print os.unlink.__doc__
print os.utime.__doc__
print os.symlink.__doc__
print os.link.__doc__
print os.chown.__doc__
""")

pp("os.path")
eep("""
###1. os.path is not a submodule of os "package"
###2. actually both os and os.path are modules

##to verify, see below##
print os; print os.path
#note: posixpath for UNIX-style paths; ntpath for Windows paths
print sys.modules['os']; print sys.modules['os.path']
print type(sys.modules)

##functions in os##
fname = os.__file__; print fname
print os.path.abspath(fname)
print os.path.dirname(fname)
print os.path.basename(fname)
print os.path.split(fname)
print os.path.splitext(os.path.basename(fname))
print os.path.join('/full/path/to/dir','abc.txt')
print os.path.join('/full/path/to/dir/','abc.txt')
print os.path.join('/full/path/to/dir//','abc.txt')
print os.path.join('/full/path/to/dir//','rpath/abc.txt')
print os.path.expanduser('~')
print os.path.expanduser('~root')
p=os.path
print p.exists(fname), p.isfile(fname), p.isdir(fname), p.islink(fname), p.ismount(fname)
for i in ('$HOME', '$IFS', '$LANG', '$HISTFILE'):  
    print os.path.expandvars(i)
#cwd is where before you run the scripts
print os.getcwd()
print os.listdir(os.getcwd())
print re.sub(r'(.*)\/.*', r'\1',fname, flags=re.M)

##document##
print os.path.abspath.__doc__
print os.path.realpath.__doc__
print os.path.dirname.__doc__
print os.path.basename.__doc__
print os.path.split.__doc__
print os.path.isdir.__doc__
print os.path.expanduser.__doc__
print os.path.join.__doc__
print os.path.splitext.__doc__
print os.path.exists.__doc__
print os.path.expandvars.__doc__
print os.path.getmtime.__doc__
print os.listdir.__doc__
print os.getcwd.__doc__
""")

pp("os.walk")
eep("""
from os.path import expanduser
home = expanduser("~")
print "home dir: " + home
##list root, the dirs in root, the files in root
for root, dirs, files in os.walk(os.path.join(home, 'graduation/javascript/'), topdown=False):
    print ('\\n----> root: ') + root
    for name in files:
        print('----> file: ' + os.path.join(root, name))
    for name in dirs:
        print('----> dir:  ' + os.path.join(root, name))

##list the roots(directories), topdown is False
for root, dirs, files in os.walk(os.path.join(home, 'graduation/javascript/'), topdown=False):
    print ('----> root: ') + root

##list the roots(directories), topdown is True
for root, dirs, files in os.walk(os.path.join(home, 'graduation/javascript/')):
    print ('----> root: ') + root
""")

pp("pickle")
eep("""
###called when being pickled: __getstate__
###called when being unpickled: __setstate__
##unless you need to override how a class is pickled or unpickled you shouldn't need to worry about it.

import pickle
class Foo(object):
  def __init__(self, val=2):
     self.val = val
  def __getstate__(self):
     print "I'm being pickled"
     self.val *= 2
     return self.__dict__
  def __setstate__(self, d):
     print "I'm being unpickled with these values:", d
     self.__dict__ = d
     self.val *= 3

import pickle
f = Foo(); print f.val
f_string = pickle.dumps(f)
print f_string
f_new = pickle.loads(f_string); print f_new.val
""")

pp("random")
eep("""
import random
print random.random()        # Random float x, 0.0 <= x < 1.0
print random.uniform(1, 10)  # Random float x, 1.0 <= x < 10.0
print random.randint(1, 10)  # Integer from 1 to 10, endpoints included
print random.randrange(0, 101, 2)  # Even integer from 0 to 100
print random.choice('abcdefghij')  # Choose a random element
items = [1, 2, 3, 4, 5, 6, 7]; print random.shuffle(items); print items
print random.sample([1, 2, 3, 4, 5],  3)  # Choose 3 elements
print random.sample(xrange(10000000), 7)  # Choose 3 samples
""")

pp("raw_input")
eep("""
#                  return string     return as expression
#python 2          raw_input()       input()
#python 3          input()           eval(input())

##In Python 2, raw_input() returns a string
##In Python 2, input() tries to run the input as expression
##In Python 3, input() returns a string
##In Python 3, eval(input()) is similar to Python 2 input()

##x=raw_input("Your name: ")
#Your name:                  #put in "Evan"
#print "Hello, " + x         #Hello, Evan
""")

pp("re")
eep("""
import re
with open('/etc/passwd') as f: c = f.read()
print c
#test r'' and re.M
print re.findall(r'^(\w+):',         c      )       #
print re.findall(r'^(\w+):',         c, re.M)       #['root',                ..,  'puppet']
print re.findall(r'^\w+(?=:)',      c, re.M)        #['root',                ..,  'puppet']  #lookahead
print re.findall(r'^(\w+):.*:(.+)$', c, re.M)       #[('root', '/bin/bash'), .., ('puppet', '/bin/false')]

#test match(), search, findall, finditer()
print re.findall (r'^(\w+):.*:(.+)$', c, re.M)                                   #[('root', '/bin/bash'), .., ('puppet', '/bin/false')]
print re.finditer(r'^(\w+):.*:(.+)$', c, re.M)                                   #<callable-iterator object at 0x7f8c69fb8390>
print re.search  (r'^(\w+):.*:(.+)$', c, re.M)                                   #<_sre.SRE_Match object at 0x7f8c69eab250>
print re.match   (r'^(\w+):.*:(.+)$', c, re.M)                                   #<_sre.SRE_Match object at 0x7f8c69eab0b8>

for l in re.findall (r'^(\w+):.*:(.+)$', c, re.M): print l                       #('root', '/bin/bash'),..,('puppet', '/bin/false')
for m in re.finditer(r'^(\w+):.*:(.+)$', c, re.M): print (m.group(1), m.group(2))#('root', '/bin/bash'),..,('puppet', '/bin/false')

m =      re.search  (r'^(\w+):.*:(.+)$', c, re.M); print (m.group(1), m.group(2))  #('root', '/bin/bash')
#m =      re.match   (r'^(\w+):.*:(.+)$', c, re.M); print (m.group(1), m.group(2))#('root', '/bin/bash')

#test regex named group(P means placeholder),
#myview named groups are for search() or match()
#m = re.match   (r'(root):.*:(.+)$', c, re.M);                print(m.group(1), m.group(2))          #('root', '/bin/bash')
m = re.search (r'^(root):.*:(.+)$', c, re.M);                print(m.group(1), m.group(2))          #('root', '/bin/bash')
m = re.search (r'^(?P<id>root):.*:(?P<shell>.+)$', c, re.M); print(m.group('id'), m.group(2))       #('root', '/bin/bash')
m = re.search (r'^(?P<id>root):.*:(?P<shell>.+)$', c, re.M); print(m.group('id'), m.group('shell')) #('root', '/bin/bash')
l = re.findall(r'^(?P<id>root):.*:(?P<shell>.+)$', c, re.M); print l                                #[('root', '/bin/bash')]

#re.I, (?i), (?imx)
for m in re.finditer(r'.*(BASH|sh)$', c, re.M|re.I)     : print m.group(0)
for m in re.finditer(r'(?im).*(BASH|sh)$', c)           : print m.group(0)

#split into list in the boundary of \W+
print re.findall(r'\w+'         , c, re.M) #same as
print re.findall(r'\w+'         , c)       #same as
print re.split(r'\W+'           , c)       #same as
print re.split(r'[^a-zA-Z0-9_]+', c)       #['root', 'x', '0', '0', 'root', 'root',...,'']
print re.split(r'\W+'           , c, 1)    #['root', 'x:0:0:root:/root...\\n]
print re.split(r'\W+'           , c, 2)    #['root', 'x', '0:0:root:/root...\\n']
print re.split(r'(\W+)'         , c, 2)    #['root', ':', 'x', ':', '0:0:root...\\n']

""")



pp("select.select()")
eep("""
##a select call is for input timout
import sys, select
print select.select.__doc__

print "You have 1 seconds to say something!"
i, o, e = select.select( [sys.stdin], [], [], 1 )
print i
print o
print e
if (i):
    print "You said", sys.stdin.readline().strip()
""")


pp("sequence")
eep("""
##about the sequence slice
#a[start:end] # items start through end-1
#a[start:]    # items start through the rest of the array
#a[:end]      # items from the beginning through end-1
#a[:]         # a copy of the whole array
#
# +---+---+---+---+---+
# | H | e | l | p | A |
# +---+---+---+---+---+
# 0   1   2   3   4   5
#-5  -4  -3  -2  -1

##"One way to remember how slices work is to think of the indices as pointing between characters, with the left edge of the first character numbered 0."
#>>> seq[:]                # [seq[0],   seq[1],          ..., seq[-1]    ]
#>>> seq[low:]             # [seq[low], seq[low+1],      ..., seq[-1]    ]
#>>> seq[:high]            # [seq[0],   seq[1],          ..., seq[high-1]]
#>>> seq[low:high]         # [seq[low], seq[low+1],      ..., seq[high-1]]
#>>> seq[::stride]         # [seq[0],   seq[stride],     ..., seq[-1]    ]
#>>> seq[low::stride]      # [seq[low], seq[low+stride], ..., seq[-1]    ]
#>>> seq[:high:stride]     # [seq[0],   seq[stride],     ..., seq[high-1]]
#>>> seq[low:high:stride]  # [seq[low], seq[low+stride], ..., seq[high-1]]

###sequence supports the following operations
##1. in, not in
print "str" in "string"
print "str" not in "string"
print 2 in [0, 1, 2, 3]
print 2 in [0, 1, 22, 3]
##2. + 
print [1,2,3] + [3,4]
print "long live" + " and prosper"
##3. * 
print [1,2,3] *3 
print "cloud" *3 
##4. slicing: s[i], s[i:j], s[i:j:k]
#s=[0,1,2,3,4,5,6,7,8,9]
s=list("0123456789")
print s[0:4]
print s[3:5]
print s[3:]
print s[-1]
print s[:-1]
#reverse the order
print s[::-1]         #s not changed
s.reverse(); print s; #s changed
#sort the order
print sorted(s)          #s is not changed
s.sort(); print s        #s is changed
#remove 2 elements while insert 7 elements
s[3:5] = [11]*7; print s
#remove 7 elements
s[3:3+7] = []; print s
#insert back the 7 elements with insert()
s.insert(3, 11); s.insert(3,11); print s
#remove() will not remove the fist occurence
s.remove(11); print s
##5. len(s), min(s), max(s)
s=(1,2,3); print len(s), min(s), max(s)
##6. s.index(i), s.count(i), s.find(i)
s="banana"; print s.index('an'), s.count('an'), s.find('an')
s=(12,1,2,12); print s.index(2), s.count(2)
##7. ==, is -->the below difference is caused by that str is immutable
a=[1,2,3];c=b=[1,2,3]; print a==b, a is b, c is b
a='12345';c=b='12345'; print a==b, a is b, c is b
##8. del s[i] only works for mutable sequene 
a=b=[1,2,3]; del a[0]; print a,b
a=b=[1,2,3]; a.pop(0); print a,b
print inspect.getmro(str)
print inspect.getmro(tuple)
print inspect.getmro(xrange)
""")

peep("set", """
##get intersection of two sets
set1 = set([0,2,4,6,8])
set2 = set((0,3,6,9))
print set1 & set2
print set1.intersection(set2)

##get difference of two sets
set1 = set([0,2,4,6,8])
set2 = set((0,3,6,9))
print set1 - set2
print set1.difference(set2)

##get union of two sets
set1 = set([0,2,4,6,8])
set2 = set((0,3,6,9))
print set1 | set2
print set1.union(set2)
##below not supported
#print set1 + set2

import copy
##assignment will only create a pointer
set1 = set([0,2,4]); set2 = set1;            set1.clear(); print set1, set2
##copy() will do a shallow copy
set1 = set([0,2,4]); set2 = set1.copy();     set1.clear(); print set1, set2
set1 = set([0,2,4]); set2 = copy.copy(set1); set1.clear(); print set1, set2

##two ways to define a Set
set1 = set([0,2,4,6,8,2,6]); print set1, type(set1)
set1 = {0,2,4,6,8,2,6};      print set1, type(set1)  # using curly braces

""")

peep("frozenset", """
##add, remove, discard#
print dir(set)
print set.__doc__
print set.__bases__
set1 = set([0,2,4,6,8])
set1.add(10);    print set1
set1.remove(10); print set1
#discard() is similar to remove(), butt it will not throw error if the 9 not a member of set1
set1.discard(9); print set1

##frozensets are sets immutable, 'set2.add(11)' will throw exception
set2 = frozenset([1,3,5,7,9]); print set2

""")

peep("shutil", """
import shutil
#shutil.move('/root/lab/testtools/rhel664/dallas',             '/lab/testtools/rhel664/')
#shutil.move('/root/lab/testtools/rhel664/otp/R15B01_halfword','/lab/testtools/rhel664/otp/')
#shutil.copy2   ('/root/var/dallas/1419_973_emalavn_BS',       '/var/dallas/OP305_R10A72')
#shutil.copytree('/root/var/dallas/1419_973_emalavn_BS',       '/var/dallas/OP305_R10A72')
#shutil.rmtree  (deploy_to_data_dir, ignore_errors=True)
#if not os.path.isdir(deploy_to_data_dir):
#   shutil.copytree(base_data_dir, deploy_to_data_dir)
#os.listdir('/lab/testtools/rhel664')
""")


peep("singleton", """
## getinstance is same as Myclass,    they are class 
## geinstance() is same as Myclass(), they are instance
def singleton(class_):
  instances = {}
  def getinstance(*args, **kwargs):
    if class_ not in instances:
        instances[class_] = class_(*args, **kwargs)
        print "-->instance created here with id: %s" % id(instances[class_]) 
    return instances[class_]
  print "-->class created here with id: %s" % id(getinstance)
  return getinstance

@singleton
class Myclass(object):
  pass

c=Myclass
a=Myclass(); print id(a)
b=Myclass(); print id(b)
""")

peep("socket","""
###python -c 'import socket; s=socket.socket(); s.bind(("", 0)); print(s.getsockname()[1]); s.close()'
import socket
s=socket.socket(); print s; print(s.getsockname())
s.bind(("", 0));   print s; print(s.getsockname())
s.close();         print s
""")
#sys.exit()

peep("str repr backtick", """
#str(), repr(), `` are three ways to convert objects to str

#str is a class, repr is a function
#back tick is similar to str(), to trasform everything to string

print str.__doc__
#str(object='') -> string
#Return a nice string representation of the object.
#If the argument is a string, the return value is the same object.
print repr.__doc__
#repr(object) -> string
#Return the canonical string representation of the object.
#For most object types, eval(repr(object)) == object.

print str.__class__               #<type 'type'>
print repr.__class__              #<type 'builtin_function_or_method'>

print "my mom is " + `29`              #my mom is 29
print "my mom is " + repr(29)          #my mom is 29
print "my mom is " + str(29)           #my mom is 29
""")
#sys.exit()

peep("sys", """
#ImportError: No module named foo actually means the module foo.py or package foo/__init__.py could not be found in any of the directories in the search path (sys.path list).
print sys.path
sys.path.append('/path/to/the/example_file.py')
print sys.path
print sys.argv
print sys.executable
""")

peep("tarfile", """
#import tarfile
#tar = tarfile.open("1.tar.gz")
#tar.extractall()
#tar.close()
""")

######################################### time ################################
peep("time, datetime", """
import time
mytuple=(1975,7,11,22,59,59,0,0,0)
print                             time.mktime(mytuple)   #174322799.0
print time.asctime(time.localtime(time.mktime(mytuple))) #Fri Jul 11 22:59:59 1975
print                             time.time()            #1493094303.6  #num of ticks since 1970/1/1/12:00 
print              time.localtime(time.time())           #time.struct_time() #local time in tuple
print time.asctime(time.localtime(time.time()))          #Tue Apr 25 12:25:05 2017  #convert tuple to local formatted string

import datetime
print datetime.timedelta                    #<type 'datetime.timedelta'>
print datetime.date                         #<type 'datetime.date'>  #class for date only
print datetime.time                         #<type 'datetime.time'>  #class for time only
print datetime.datetime                     #<type 'datetime.datetime'> #class for both date and time
print datetime.datetime(2016, 10, 1, 19, 30, 59, 99999)   #2016-10-01 19:30:59.099999
print datetime.datetime.today()             #2017-04-25 12:51:08.911752
print datetime.datetime.today().date()      #2017-04-25     #local date
print datetime.datetime.today().time()      #12:52:05.980688
print datetime.datetime.utcnow()            #2017-04-25 04:58:29.998501
print datetime.datetime.now()               #2017-04-25 12:58:47.785288
print datetime.datetime.now()  .date()      #2017-04-25     #local date
print datetime.datetime.now()  .time()      #12:46:52.723122
print datetime.date.today()                 #2017-04-25
print datetime.date.today().weekday()       #1              #0 for Mon, 6 for Sun
print datetime.date(1975,7,17)              #1975-07-17
print datetime.date.today()-datetime.date(1975,7,11)        #15264 days, 0:00:00 #how many days have I lived
print datetime.date.today()+datetime.timedelta(days=10000)  #2044-09-10  #after 10000 days

print datetime.timedelta(hours=1)                           #1:00:00
print datetime.timedelta(hours=25,days=1,seconds=1)         #2 days, 1:00:01

""", ebrun, 0)
