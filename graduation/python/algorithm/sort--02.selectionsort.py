#!/usr/bin/env eepython
##http://interactivepython.org/courselib/static/pythonds/SortSearch/TheSelectionSort.html
##The selection sort improves on the bubble sort by making only one exchange for every pass through the list. 
##In order to do this, a selection sort looks for the largest value as it makes a pass and, after completing the pass, places it in the proper location.
def selectionSort(alist):
   for fillslot in range(len(alist)-1,0,-1):
       positionOfMax=0
       for location in range(1,fillslot+1):
           positionOfMax = location if  alist[location]>alist[positionOfMax] else positionOfMax
       print fillslot,":", positionOfMax, "-->", alist
       alist[fillslot], alist[positionOfMax] = alist[positionOfMax], alist[fillslot]
alist = [54,26,93,17,77,31,44,55,20]
selectionSort(alist)
print(alist)
