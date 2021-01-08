#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
1. '=' is a synonym for '==' in bash
2. '==' was introduced in bash, but bourne shell does not support it
3. [[ is a keyword, also need a space, only for string comparsion
4. [ is a command, so need a whitespace
[   "$foo" = bar ] 
~~  ~~~~~~~~~~~~~~ arguments
\\-command

EOF

elrun <<"EOF"
foo="bar"
[ "$foo" = bar ] && echo "OK"     #Pretty close!
[[ $foo = bar ]] && echo "OK"     #Right!
[ bar = "$foo" ] && echo "OK"     #Also right!
[ x"$foo" = xbar ] && echo "OK"   #Also right!

[ "$foo" == bar ] && echo "OK"     #Pretty close!
[[ $foo == bar ]] && echo "OK"     #Right!
[ bar == "$foo" ] && echo "OK"     #Also right!

#wrong!, = need a whitespace
[ abc=bar ] && echo "not right"     
[[ abc=bar ]] && echo "not right"  
[ bar=abc ] && echo "not right"   
#if [bar="$foo"]      # Wrong!
#if [ bar="$foo" ]    # Still wrong!
#if [ bar = "$foo" ]  # right!
EOF
