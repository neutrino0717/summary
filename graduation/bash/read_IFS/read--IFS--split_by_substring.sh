#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
EOF


esrun <<"EOF"
IFS='' read -r -d '' v1 <<EOD
the head
==
line 1
line 2
==
the end
==
EOD
echo "$v1"

v2=`echo "$v1" | sed -e 's/^==$/\\xAF/'`  #replace ^---$ with a unicode charactor
echo "$v2"

#1. split into a array
IFS=$'\\xAF' read -d '' -a arr <<< "$v2"
for i in "${arr[@]}"; do echo "->$i<-"; done

#2. or
while read -d $'\\xAF' v3 
do
  echo "->$v3<-"
done <<< "$v2"

EOF
