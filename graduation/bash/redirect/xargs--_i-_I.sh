#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}
xargs -i:      insert to {}, {} is called placeholder
xargs -I:      insert to a var, '-I varname' specify a replacement string.
xargs -0:      seperate accoding to 0 charater instead of default whilespace
If no command is given to xargs, then the echo command is used.
${endColor}"
elrun <<"EOF"
fname=~/.gitconfig
cat $fname
cat $fname |xargs 
cat $fname |xargs -l
cat $fname |xargs -L 1
cat $fname |xargs -L 1 echo 
cat $fname |xargs -i      echo "{}"
cat $fname |xargs -I line echo " ==> line -->OK"
cat $fname |xargs -i      echo " ==> {} -->OK"
EOF
elrun <<"EOF"
find . -name "e*.sh" -print0 |xargs -0 -i echo mv {} linux/
ls e*.sh                     |xargs -n 1 -i echo cp {} /backup
EOF
