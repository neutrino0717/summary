#!/bin/bash
#-------------source-----------------#
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh
vimcat $0
<<<"${red}
eval "string" --> "translates" a value , and then runs the command.
exec script   --> starts another process with the same PID and exits the current process.
                  or in other word, replace the shell with a given program (executing it, not as new process)
./script      --> starts another process, then return to the current process(environment variable changed in the child is LOST FOREVER)
source script --> force the script to run in the current process. environment variables in the script you ran are NOT LOST
${endColor}"
echo "Current process is: $0"
exec echo "leaving this script forever: $0"
echo "this will never be printed"
#-------------output-----------------#
