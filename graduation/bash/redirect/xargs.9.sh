#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}
xargs
  1. xargs command reads standard input, then builds and executes commands with the input as parameters. 
  2. xargs breaks the input at blanks, and each resulting token becomes a parameter. 
  3. If no command is given, then the echo command is used.

Suppose you want to use the output of a command or the contents of a file as arguments to a command rather than as input. Pipelines don't work for that. Three common methods are:
  1.     The xargs command
  2.     The find command with the -exec option
  3.     Command substitution


-p     Prompt User Before Execution
-t     Print the Command Along with Output
-n 2   Limit Output parameters number to 2 Per Line 
-L 2   Limit Output Parameters number to 2 lines(non-empty) of arguments from standard input 
       -l is the same as -L 1
${endColor}"
elrun <<"EOF"
#2 arguments per line
xargs -n 2 <<<`echo p{1..7}`
echo p{1..7}
echo p{1..7} |xargs
#every two line of output merge to one agument line
echo p{1..7} |xargs -L 2
#split output to two arguments a line
echo p{1..7} |xargs -n 2

seq -f 'p%g' 7 
seq -f 'p%g' 7 | xargs -L 2
seq -f 'p%g' 7 | xargs -n 2

echo p{1..7} |xargs -n 3
echo p{1..7} |xargs -n 3 -t
echo p{1..7} |xargs -n 3 -p
ls *.sh | xargs -n 1 -i echo cp {} /backup
EOF
