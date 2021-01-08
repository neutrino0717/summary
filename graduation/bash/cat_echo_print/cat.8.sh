#!/bin/bash
# absolute dir
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}
-A, --show-all   equivalent to -vET
                 tab displayed as ^I, end is $
${endColor}"

erun "cat -A /etc/*rel*"

erun "cat -n /etc/*rel*"
