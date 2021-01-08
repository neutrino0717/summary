#!/usr/bin/env eepython
##Quicksort. Quicksort is a fast sorting algorithm, which is used not only for educational purposes, but widely applied in practice. 
##On the average, it has O(n log n) complexity, making quicksort suitable for sorting big data volumes.

global qsort
def qsort(seq):
    if seq==[]:
        return []
    else:
        pivot=seq[0]
        print '-->%s' % pivot
        lesser=qsort([x for x in seq[1:] if x<pivot])
        greater=qsort([x for x in seq[1:] if x>=pivot])
        #print lesser+[pivot]+greater
        return lesser+[pivot]+greater
seq=[5,6,78,9,0,-1,2,3,-65,12]
print qsort(seq)

global qsort2
def qsort2(arr): 
    if len(arr) <= 1:
        return arr
    else:
        return qsort2([x for x in arr[1:] if x<arr[0]]) + [arr[0]] + qsort2([x for x in arr[1:] if x>=arr[0]])

seq=[5,6,78,9,0,-1,2,3,-65,12]
print qsort2(seq)
