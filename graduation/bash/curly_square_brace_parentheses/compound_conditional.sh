#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
EOF

elrun <<"EOF"
foo=bar
bar=foo
test bar = "$foo" && test foo = "$bar" && echo "right" || echo "wrong"    # Right!
[ bar = "$foo" ] && [ foo = "$bar" ]   && echo "right" || echo "wrong"    # Right!
[[ $foo = bar && $bar = foo ]]         && echo "right" || echo "wrong"    # Also right!
if [ bar = "$foo" ] && [ foo = "$bar" ]; then echo "right"; else echo "wrong"; fi    # Right!
if [[ $foo = bar && $bar = foo ]];       then echo "right"; else echo "wrong"; fi    # Also right!


EOF
