#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
EOF

elrun <<"EOF"
#associative array
declare -A ages
ages=([dad]=42 [mom]=40 [me]=7)
# key array
echo ${!ages[@]} 
# value array
echo ${ages[@]}
# lookup
echo ${ages['me']}
# iterate
for key in ${!ages[@]}; do echo "$key ${ages[$key]}"; done

EOF
