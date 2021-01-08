#!/usr/bin/env eepython
##There is currently only one standard mapping type, the dictionary

print type({})

## ways to define dict
a = dict(one=1, two=2, three=3)
b = {'one': 1, 'two': 2, 'three': 3}
c = dict(zip(['one', 'two', 'three'], [1, 2, 3]))
d = dict([('two', 2), ('one', 1), ('three', 3)])
e = dict({'three': 3, 'one': 1, 'two': 2})
print a == b == c == d == e

## items(), keys(), values()
ages={'dad':42,'mom':48,'me':7}
print ages
print ages.items()
print dict(ages.items())
print ages.keys()
print ages.values()
print {'dad':42,'mom':48,'me':7}['me']

##has_key(), get()
print ages.has_key('me'), ages.get('me')
print ages.has_key('Me'), ages.get('Me')

## iterate
ages={'dad':42,'mom':48,'me':7}
for key in ages: print key, ages[key]
for k,v in ages.items(): print k,v

## delete an element
ages={'dad':42,'mom':48,'me':7}
del ages['me']; print ages.items()

## remove all entries in dict
ages.clear()  ; print ages if 'ages' in locals() else "ages not defined"

# delete all entries
ages={'dad':42,'mom':48,'me':7}
del ages      ; print ages if 'ages' in locals() else "ages not defined"
