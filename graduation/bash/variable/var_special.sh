#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh

echo -e "${red}${endColor}"
eprt ''

eprtdoc <<"EOF"
EOF

elrun <<"EOF"
# enironment related
echo "the login name: $LOGNAME"
echo "the current working dir: $PWD"
echo "the user default working dir: $HOME"
echo "the users mail file full path: $MAIL"
echo "the current shell: $SHELL"
echo "the shell search path: $PATH"
echo "the default locale: $LANG"
echo "the current terminal type: $TERM"
echo "the primary system prompt: $PS1"
echo "the secondary system prompt: $PS2"
echo "the Internal field separator: $IFS"
#echo "the files colour: $LS_COLORS"

# process related
echo "current bash PID: $$"
pgrep "$0"
echo "parent PID of the bash: $PPID"
sleep 1 &
echo "last background process PID: $!"
cat /etc/noexists 2>/dev/null; echo "exit status of the last command: $?"

EOF
