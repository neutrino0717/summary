#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh
vimcat $0
eprt '
Pass a here document as a bash function argument
'
foo1 () { while read -r line; do var1+=$line$'\n'; done; echo "$var1"; }
foo2 () { while read    line; do var2+=$line$'\n'; done; echo "$var2"; }
foo3 () { echo "$1"; }
foo1 <<EOF
a\nbc
d\tef
g\shi
EOF
foo2 <<EOF
a\nbc
d\tef
g\shi
EOF
foo3 "$(cat<<EOF
a\nbc
d\tef
g\shi
EOF
)"
