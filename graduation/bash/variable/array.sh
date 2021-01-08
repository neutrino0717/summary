#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
EOF

elrun <<"EOF"
# 1.create an array
arr=("hatter" "duchess" "alice")
echo "$arr[@]"
#for loop
for ((i=0;i<${#arr[@]};i++)); do echo -n "${arr[$i]} "; done; echo
#for loop alternative
for i in "${arr[@]}"; do echo -n "$i "; done
#get array size
echo ${#arr[*]}
echo ${#arr[@]}

arr=(e{1..7})
#print all elements
echo ${arr[@]}  #or
echo ${arr[*]}
echo ${arr[1]}
#print two elements start from index 1 
echo ${arr[@]:1:2}
#print elements start with index 1
echo ${arr[*]:1}
#print the last element
echo ${arr[-1]}   #or
echo ${arr[${#arr[@]}-1]}


EOF
