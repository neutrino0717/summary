#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

eprtdoc <<"EOF"
(()) is only for numeric
[[]] is only for string
[]   can be for both

#numeric comparisons
1. (( == )) 
2. [  -eq ]
#string comparisons
1. [[ = ]], [[ == ]] 
2. [  =  ], [  ==  ] 


for numeric comparisons
1. use '==' in '(())', do not use '=' 
2. use '-eq' in '[]', test or '[[]]'.
EOF

elrun <<"EOF"
foo=6
((foo > 7))     && echo "right" || echo "wrong"
[ $foo -gt 7 ]  && echo "right" || echo "wrong"
test $foo -gt 7 && echo "right" || echo "wrong"

count=10; ((count++)); echo $count

EOF
