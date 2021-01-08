#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

eprtdoc <<"EOF"
${var:?word1}     # [ "$var" ] && echo "$var" || echo "var: word1"
${var:-word1}     # [ "$var" ] && echo "$var" || echo "word1"
${var:=word1}     # [ "$var" ] && echo "$var" || { var="word1"; echo "word1"; } 
${var:+word1}     # [ "$var" ] && echo "word1" || echo ""
EOF
elrun <<"EOF"
var="var1"
echo ${var:?word1}     # [ "$var" ] && echo "$var" || echo "var: word1"
echo ${var:-word1}     # [ "$var" ] && echo "$var" || echo "word1"
echo ${var:+word1}     # [ "$var" ] && echo "word1" || echo ""
echo ${var:=word1}     # [ "$var" ] && echo "$var" || { var="word1"; echo "word1"; } 
unset var
#echo ${var:?word1}     # [ "$var" ] && echo "$var" || echo "var: word1"
echo ${var:-word1}     # [ "$var" ] && echo "$var" || echo "word1"
echo ${var:+word1}     # [ "$var" ] && echo "word1" || echo ""
echo ${var:=word1}     # [ "$var" ] && echo "$var" || { var="word1"; echo "word1"; } 
EOF

