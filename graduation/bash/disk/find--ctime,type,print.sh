#!/bin/esh
#find files belongs to coreUser                      
find /tmp -user coreUser -print       

#files not changed in 7 days
find ~/graduation -ctime +7 -print |head -n 5

#files changed in 2 days
find ~/graduation -ctime -2 -print |head -n 5

#files belong to root 
find ~ -user root -print |head -n 5

#files not match *.sh
find .. ! -name "*.sh" | tail -n 5
