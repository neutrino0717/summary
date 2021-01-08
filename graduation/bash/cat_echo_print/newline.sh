#!/bin/bash
############# source code #####################
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh
vimcat $0

<<EOF
\n is not a newline; it's an escape sequence that in some situations will be translated into a newline
newline='\n'         #wrong
newline=$'\n'        #right, it's newline
EOF

eprt "the wrong way"
newline='\n'
echo "hello $newline boys"
echo -e "hello $newline boys"

eprt "the right way"
newline=$'\n'
echo "hello $newline boys"
echo -e  "hello $newline boys"

#############   output   #####################
