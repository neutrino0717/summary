#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
EOF

elrun <<"EOF"
arr=("hatter" "duchess" "alice")
# remove by index(assigning null)
unset arr[1]
echo "${arr[@]}"
echo "${#arr[@]}"
echo "${#arr[*]}"
for ((i=0; i<${#arr[@]}; i++)); do echo -n "->${arr[$i]}<- "; done
echo "${arr[1]}"
# remove the 2nd elements completely
arr=("hatter" "duchess" "alice")
pos=1
arr=(${arr[@]:0:$pos} ${arr[@]:$(($pos+1))})
for ((i=0; i<${#arr[@]}; i++)); do echo -n "->${arr[$i]}<- "; done
echo "${arr[@]}"
echo "${arr[$pos]}"

arr=("hatter" "duchess" "duchess" "alice")
# remove by value
##all occurrences are removed
arr=(${arr[@]/duchess/})
echo ${arr[@]}
echo ${arr[1]} #return alice

arr=("hatter" "duchess" "duchess" "alice")
# search aand replace
echo ${arr[@]/duchess/hare}

arr=("hatter" "duchess" "alice")
# append
arr=(${arr[@]} rabbit)
echo ${arr[@]}

pos=1
arr=("hatter" "duchess" "alice")
# insert after index 1
arr=(${arr[@]:0:$pos} 'rabbit' ${arr[@]:$pos})
echo ${arr[@]}

arr1=("hatter" "duchess" "alice")
arr2=("rabbit" "hare")
# concatenate two arrays
arr=("${arr1[@]}" "${arr2[@]}")
echo ${arr[@]}

arr=("hatter" "duchess" "alice")
IFS='-'
# join with '-'
echo "${arr[*]}"
unset IFS

arr=("hatter" "duchess" "alice")
# get index of a value
for ((i=0;i<${#arr[@]};i++));do [[ ${arr[$i]} = 'duchess' ]] && echo $i; done

declare -A ass
ass=([hatter]=0 [duchess]=1 [alice]=2); 
#get index of a value 
echo ${ass[duchess]}

arr=("hatter" "duchess" "alice")
# reverse
arr=(`for ((i=${#arr[@]}-1; i>=0; i--)); do echo "${arr[$i]}"; done`); 
echo ${arr[@]}

arr=(e{16..5} e{101..96})
# sort
IFS=$'\\r\\n' arr=(`for i in "${arr[@]}"; do echo  "$i"; done | sort`)
echo ${arr[@]}

EOF
