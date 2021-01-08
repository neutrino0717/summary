#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
EOF

elrun <<'EOF'
s=" \\t  how to trim a string  \\t"; echo -e "'$s'"
# sed support |(or)
echo -e "$s" |sed "s/^[[:space:]]*\\|[[:space:]]*$//g"
# use multiple sed
echo -e "$s" |sed -e 's/^[[:space:]]*//g' -e 's/[[:space:]]*$//g'


EOF
