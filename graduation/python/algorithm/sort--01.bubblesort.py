#!/usr/bin/env eepython
##http://interactivepython.org/runestone/static/pythonds/SortSearch/TheBubbleSort.html
##A bubble sort is often considered the most inefficient sorting method since it must exchange items before the final location is known
def bubbleSort(alist):
    #exchanges = True
    for passnum in range(len(alist)-1,0,-1):
        #if not exchanges: break
        #exchanges = False
        for i in range(passnum):
            if alist[i]>alist[i+1]:
                #exchanges = True
                alist[i], alist[i+1] = alist[i+1], alist[i]

alist = [54,26,93,17,77,31,44,55,20]
bubbleSort(alist)
print(alist)

##for lists that require just a few passes, a bubble sort may have an advantage in that it will recognize the sorted list and stop. ActiveCode 2 shows this modification, which is often referred to as the short bubble
def shortBubbleSort(alist):
    exchanges = True
    for passnum in range(len(alist)-1,0,-1):
        if not exchanges: break
        exchanges = False
        for i in range(passnum):
            if alist[i]>alist[i+1]:
                exchanges = True
                alist[i], alist[i+1] = alist[i+1], alist[i]
            print passnum,':',i,'-->',alist
alist=[20,30,40,90,50,60,70,80,100,110]
shortBubbleSort(alist)
print(alist)
