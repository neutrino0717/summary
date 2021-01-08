#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
#Up     Ctrl+P
#Down   Ctrl+N
#Left   Ctrl+B
#Right  Ctrl+F
Home   Ctrl+A
End    Ctrl+E
#Delete Ctrl+D
EOF

elrun <<"EOF"

EOF
