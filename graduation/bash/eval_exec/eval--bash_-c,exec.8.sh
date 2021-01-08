#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh
echo -e "${red}
eval "string" --> "translates" a value , and then runs the command.
exec script  --> starts another process with the same PID and exits the current process.
${endColor}"
erun 'for i in whoami uname pwd; do eval "$i"; done'
erun 'for i in whoami uname pwd; do bash -c "$i"; done'
erun 'for i in whoami uname pwd; do bash -x <<<"$i"; done'
erun 'for i in whoami uname pwd; do bash -v <<<"$i"; done'



