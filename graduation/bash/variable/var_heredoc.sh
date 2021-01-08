#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

eprtdoc <<"EOF"
#How to assign a heredoc value to a variable in Bash?
##way 1: use IFS
you want to preserve the tabs in the contents of the resulting variable, you need to remove tab from IFS. 

##way 2: use $(cat <<EOF\n....\nEOF)
EOF

edrun <<"EOF"
IFS='' read -r -d '' VAR <<'EOD'
# this \is the right way!
# this is the right way
EOD
---
echo "$VAR"
---
EOF
