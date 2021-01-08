#!/bin/esh
##exclude /lab
##-o
##expr1 -o expr2     means Or; expr2 is not evaluated if expr1 is true.
#find / -path '/lab' -prune -o -name "*.py"
##in all paths under /gtec/ except for /gtec/lab, find all file named *.sh
#find /gtec -path '/gtec/lab' -prune -o -name "*.sh"   

##stackoverflow
## You pretty much always want the the -o immediately after -prune, 
## because that first part of the test (up to including -prune) will return false for the stuff you actually wanti
## (ie: the stuff you don't want to prune out).
#find [path] [conditions to prune] -prune -o [your usual conditions] [actions to perform]
##^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^    ~~~~~~~~~~~~~~~~~~~~~|
##                                      |                         |- part 2 will execute if part 1 return false
##                                      |- part 1: return false for the stuff you actually want

