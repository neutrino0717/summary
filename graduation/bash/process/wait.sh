#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}
In computing, wait is a command which pauses until execution of a background process has ended.

the pid or job ID of a currently executing background process (job). If pid is not given, the command waits until all jobs known to the invoking shell have terminated.
wait [pid]
wait

1.
echo -n "Preparing SDK : "
setupsim_prepare.sh -sdk seosRelease.tar.gz  > /logs/prepare_log 2>&1 &
wait

2.
sleep 15 &
[1] 18004
wait %1   #or wait 18004

${endColor}"
eprt 'start 5 sleep processes, and wait'
FAIL=0
for t in 1 2 4 7 11; do 
    sleep $t &
done
newline=$'\n'
echo "the jobs list: 'jobs -p' -->$newline`jobs -p`"
for job in `jobs -p`; do
    wait $job && echo "$job ends at `date`" || let "FAIL+=1"
done

echo "$FAIL job(s) failed"
