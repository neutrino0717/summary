#!/usr/bin/env eepython
##http://interactivepython.org/courselib/static/pythonds/SortSearch/TheInsertionSort.html
##The insertion sort, although still O(n2), works in a slightly different way from selection sort. It always maintains a sorted sublist in the lower positions of the list.

def insertionSort(alist):
   print "-->", '  ', ": ", alist
   for index in range(1,len(alist)):
     currentvalue = alist[index]
     print "-->", currentvalue,": ", alist
     position = index
     while position>0 and alist[position-1]>currentvalue:
         alist[position]=alist[position-1]
         alist[position-1]=''    #can be removed, just for good view
         position = position-1
         print "-->", currentvalue,": ", alist
     alist[position]=currentvalue
alist = [54,26,17,77,31,44,93,55,20]
insertionSort(alist)
print "-->", '  ', ": ", alist
