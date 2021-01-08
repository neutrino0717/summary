#!/usr/bin/env eepython

#illustrate
items = range(10)
print items
print iter(items)
print items.__iter__()
print [iter(items)]
print [iter(items)]*3
#print zip([iter(items)]*3)
#asterisk
# * unpacks the sequence/collection into positional arguments
#** does the same, only using a dictionary and thus named arguments:
print zip(*[iter(items)]*3)

def groupby(items, size):
    return zip(*[iter(items)]*size)
print groupby(range(10), 3)
print groupby(range(11), 3)
print groupby(range(12), 3)
