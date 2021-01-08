#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}-n     do not output the trailing newline${endColor}"
erun 'echo -n "I will "; echo "have a try"'

echo -e "${red}-E     disable interpretation of backslash escapes (default)${endColor}"
erun 'echo -E "planet\tdistance\nMars\t333\n"'
erun 'echo    "planet\tdistance\nMars\t333\n"'

echo -e "${red}-e     enable interpretation of backslash escapes${endColor}"
erun 'echo -e "planet\tdistance\nMars\t333\n"'

