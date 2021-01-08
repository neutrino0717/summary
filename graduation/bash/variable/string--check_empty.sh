#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
EOF

esrun <<"EOF"
func1(){
s=$1
if [ "$s" ]; then e1=" not"; fi
if [ "$s" != "" ]; then e2=" not"; fi
if [ -n "$s" ]; then e3=" not"; fi
if [ ! -z "$s" ]; then e4=" not"; fi
echo "\\$1 is$e1 empty"
echo "\\$1 is$e2 empty"
echo "\\$1 is$e3 empty"
echo "\\$1 is$e4 empty"
}

func1

func1 ""

func1 " "

EOF
