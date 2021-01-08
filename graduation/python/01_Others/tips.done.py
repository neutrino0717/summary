#!/usr/bin/env eepython
##reverse a list
print ["a","b",3][::-1]
print ("a","b",3)[::-1]
print "hello"[::-1]
print range(3)[::-1]

##double values in a list
print range(7)
print range(7) * 2 #wrong
print map(lambda x: x*2, range(7))
print [e * 2 for e in range(7)]

##if you need to use index in list, it's good idea to use enumerate instead
list = ["live", "long", "and", "prosper"]
for i, e in enumerate(list): print i, e

##switch variable values
a, b = 7, 11   #or a, b=(7, 11)
b, a = a, b
print a, b

##format a string
print '{}/../servicelayer'.format(os.path.dirname(__file__))
print os.path.realpath('{}/../servicelayer'.format(os.path.dirname(__file__)))
 
d={"name": "Evan", "age":16, "gender":"boy"}
print "{0} is {1} years old, a {2}.".format("Evan", 16,  "boy")   #use list
print "{name} is {age} years old, a {gender}.".format(**d)        #use map
print "%s is %s years old, a %s." % ("Evan", 16,  "boy")          #use list
print "%(name)s is %(age)s years old, a %(gender)s." % d          #use map

##store occurence of keys to map
#use: dict.get('key', 'defaultvalue')
#     D.get(k[,d]) -> D[k] if k in D, else d.  d defaults to None. 
counter={}
bag = [2, 2, 2, 4, 0, 4, 4, 3, 2, 1,1]
for i in bag:
    counter[i] = counter.get(i, 0) + 1
print counter
#another way, more time-consuming
print      (i                for i in bag)
print      [i                for i in bag]
print      [(i,bag.count(i)) for i in bag]
print dict([(i,bag.count(i)) for i in bag])
