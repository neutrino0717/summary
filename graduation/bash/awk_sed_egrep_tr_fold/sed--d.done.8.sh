#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

eprtdoc <<"EOF"
#how to delete a line
sed -e '/gsh check_config/b' -e '/gsh activate_config_pending/b' -e '/gsh start_small_restart/b' -e d /Core/log/ConTest_Log/log

sed -i -e '/gsh check_config/d' -e '/gsh activate_config_pending/d' -e '/gsh start_small_restart/d' /Core/log/ConTest_Log/log

sed -i '/gsh check_config\|gsh activate_config_pending\|gsh start_small_restart/d' automme_op153_16A-00-03_dallas_green

#other:
egrep -v "aaa|bbb|ccc" file.txt > newfile.txt
awk '!/facebook|youtube|google|amazon|dropbox/' file.txt > newfile.txt
EOF
