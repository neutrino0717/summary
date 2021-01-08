#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt '
outputs a sequence of numbers 
seq -s ' ' -f 'R10A%g' 2 12
-s, --separator=STRING     use STRING to separate numbers (default: \n)
-f, --format=FORMAT        use printf style floating-point FORMAT (default: %g)
-w, --equal-width          equalize width by padding with leading zeroes
'
elrun <<"EOF"
seq -f 'dir%g'     7
seq -f 'dir%3g'    7
seq -f 'dir%03g' 1 7
awk 'BEGIN { while (num < 7 ) printf "dir%03d\\n", ++num ; exit}'
EOF
