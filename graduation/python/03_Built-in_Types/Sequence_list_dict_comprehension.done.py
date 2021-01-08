#!/usr/bin/env eepython
##list comprehension
print [ n for n in range(5) ]
print [ n**2 for n in range(5) ]
print ["%s%s"%(a,b) for a in range(3) for b in 'abcd' ]
print ( n**2 for n in range(5) )
##dict comprehension
print { n: n for n in range(5) }
print { n: True for n in range(5) }
##set compreahension
nums=[1,3,2,1,4,3,9,2,3]
print { n for n in nums }
