# To the extent possible under law, the author(s) have dedicated all 
# copyright and related and neighboring rights to this software to the 
# public domain worldwide. This software is distributed without any warranty. 
# You should have received a copy of the CC0 Public Domain Dedication along 
# with this software. 
# If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 

# base-files version 4.1-1

# ~/.bashrc: executed by bash(1) for interactive shells.

# The latest version as installed by the Cygwin Setup program can
# always be found at /etc/defaults/etc/skel/.bashrc

# Modifying /etc/skel/.bashrc directly will prevent
# setup from updating it.

# The copy in your home directory (~/.bashrc) is yours, please
# feel free to customise it to create a shell
# environment to your liking.  If you feel a change
# would be benifitial to all, please feel free to send
# a patch to the cygwin mailing list.

# User dependent .bashrc file

# If not running interactively, don't do anything
[[ "$-" != *i* ]] && return

# Shell Options
#
# See man bash for more options...
#
# Don't wait for job termination notification
# set -o notify
#
# Don't use ^D to exit
# set -o ignoreeof
#
# Use case-insensitive filename globbing
# shopt -s nocaseglob
#
# Make bash append rather than overwrite the history on disk
# shopt -s histappend
#
# When changing directory small typos can be ignored by bash
# for example, cd /vr/lgo/apaache would find /var/log/apache
# shopt -s cdspell

# Completion options
#
# These completion tuning parameters change the default behavior of bash_completion:
#
# Define to access remotely checked-out files over passwordless ssh for CVS
# COMP_CVS_REMOTE=1
#
# Define to avoid stripping description in --option=description of './configure --help'
# COMP_CONFIGURE_HINTS=1
#
# Define to avoid flattening internal contents of tar files
# COMP_TAR_INTERNAL_PATHS=1
#
# Uncomment to turn on programmable completion enhancements.
# Any completions you add in ~/.bash_completion are sourced last.
# [[ -f /etc/bash_completion ]] && . /etc/bash_completion

# History Options
#
# Don't put duplicate lines in the history.
# export HISTCONTROL=$HISTCONTROL${HISTCONTROL+,}ignoredups
#
# Ignore some controlling instructions
# HISTIGNORE is a colon-delimited list of patterns which should be excluded.
# The '&' is a special pattern which suppresses duplicate entries.
# export HISTIGNORE=$'[ \t]*:&:[fb]g:exit'
# export HISTIGNORE=$'[ \t]*:&:[fb]g:exit:ls' # Ignore the ls command as well
#
# Whenever displaying the prompt, write the previous line to disk
# export PROMPT_COMMAND="history -a"

# Aliases
#
# Some people use a different file for aliases
if [ -f "${HOME}/.bash_aliases" ]; then
  source "${HOME}/.bash_aliases"
fi
#
# Some example alias instructions
# If these are enabled they will be used instead of any instructions
# they may mask.  For example, alias rm='rm -i' will mask the rm
# application.  To override the alias instruction use a \ before, ie
# \rm will call the real rm not the alias.
#
# Interactive operation...
# alias rm='rm -i'
# alias cp='cp -i'
# alias mv='mv -i'
#
# Default to human readable figures
# alias df='df -h'
# alias du='du -h'
#
# Misc :)
# alias less='less -r'                          # raw control characters
# alias whence='type -a'                        # where, of a sort
# alias grep='grep --color'                     # show differences in colour
# alias egrep='egrep --color=auto'              # show differences in colour
# alias fgrep='fgrep --color=auto'              # show differences in colour
#
# Some shortcuts for different directory listings
# alias ls='ls -hF --color=tty'                 # classify files in colour
# alias dir='ls --color=auto --format=vertical'
# alias vdir='ls --color=auto --format=long'
# alias ll='ls -l'                              # long list
# alias la='ls -A'                              # all but . and ..
# alias l='ls -CF'                              #

# Umask
#
# /etc/profile sets 022, removing write perms to group + others.
# Set a more restrictive umask: i.e. no exec perms for others:
# umask 027
# Paranoid: neither group nor others have any perms:
# umask 077

# Functions
#
# Some people use a different file for functions
# if [ -f "${HOME}/.bash_functions" ]; then
#   source "${HOME}/.bash_functions"
# fi
#
# Some example functions:
#
# a) function settitle
# settitle () 
# { 
#   echo -ne "\e]2;$@\a\e]1;$@\a"; 
# }
# 
# b) function cd_func
# This function defines a 'cd' replacement function capable of keeping, 
# displaying and accessing history of visited directories, up to 10 entries.
# To use it, uncomment it, source this file and try 'cd --'.
# acd_func 1.0.5, 10-nov-2004
# Petar Marinov, http:/geocities.com/h2428, this is public domain
# cd_func ()
# {
#   local x2 the_new_dir adir index
#   local -i cnt
# 
#   if [[ $1 ==  "--" ]]; then
#     dirs -v
#     return 0
#   fi
# 
#   the_new_dir=$1
#   [[ -z $1 ]] && the_new_dir=$HOME
# 
#   if [[ ${the_new_dir:0:1} == '-' ]]; then
#     #
#     # Extract dir N from dirs
#     index=${the_new_dir:1}
#     [[ -z $index ]] && index=1
#     adir=$(dirs +$index)
#     [[ -z $adir ]] && return 1
#     the_new_dir=$adir
#   fi
# 
#   #
#   # '~' has to be substituted by ${HOME}
#   [[ ${the_new_dir:0:1} == '~' ]] && the_new_dir="${HOME}${the_new_dir:1}"
# 
#   #
#   # Now change to the new dir and add to the top of the stack
#   pushd "${the_new_dir}" > /dev/null
#   [[ $? -ne 0 ]] && return 1
#   the_new_dir=$(pwd)
# 
#   #
#   # Trim down everything beyond 11th entry
#   popd -n +11 2>/dev/null 1>/dev/null
# 
#   #
#   # Remove any other occurence of this dir, skipping the top of the stack
#   for ((cnt=1; cnt <= 10; cnt++)); do
#     x2=$(dirs +${cnt} 2>/dev/null)
#     [[ $? -ne 0 ]] && return 0
#     [[ ${x2:0:1} == '~' ]] && x2="${HOME}${x2:1}"
#     if [[ "${x2}" == "${the_new_dir}" ]]; then
#       popd -n +$cnt 2>/dev/null 1>/dev/null
#       cnt=cnt-1
#     fi
#   done
# 
#   return 0
# }
# 
# alias cd=cd_func

alias ll='ls -al'
alias ls='ls --color=auto'
alias vi='/usr/bin/vim'
alias vcat='vimcat'
alias pcat='fnpcat'
alias grep='grep --color=auto'
alias egrep='egrep --color=auto'
alias fgrep='fgrep --color=auto'              # show differences in colour
alias cd1="cd .." 
alias cd2="cd ../.." 
alias cd3="cd ../../.." 
alias cd4="cd ../../../.." 
alias cd5="cd ../../../../.." 

fnpcat ()
{
  echo 'cat>test.pl<<"EOF"'
  vimcat $1
  echo 'EOF'
  echo 'perl test.pl'
}
fnegrep () 
{
  #for i in ~/script/*; do egrep -r "$1" "$2" $i; done;
  [[ $# -eq 1 ]] && for i in ~/script/*; do egrep -r "$1" $i; done
  [[ $# -gt 1 ]] && for i in ~/script/*; do egrep -r "$1" $i; done | awk -F : '!/^Binary/{print $1}' | xargs egrep -i --color=auto "$2"
}
 
fnfgrep () 
{
  for i in ~/script/*; do fgrep -r "$1" $i; done;
}

fngrep () 
{
  for i in ~/script/*; do grep -r "$1" $i; done;
}

alias egrepall=fnegrep
alias fgrepall=fnfgrep
alias grepall=fngrep
tk()
{
 taskkill /F /IM $@
}

fnfind ()
{
  for i in ~/script/*; do find `readlink.exe -f $i` -name $1; done;
}

alias findall=fnfind

fnxcd ()
{
  mypath="$@"
  [ -f "$mypath" ] || [ ! -e "$mypath" ] && mypath=${mypath%\\*} 
  mypath=`echo "$mypath" |sed 's/\\\/\//g'|awk -F: '{print "/cygdrive/"tolower($1)$2}'`
  cd "$mypath"
  pwd
}
manbash () {
#function manbash {
   man -P "less +/\ \ \ $1" bash
}
alias xcd=fnxcd
#export JAVA_HOME=/cygdrive/c/Java/jdk1.8.0_25/
export PATH=$PATH:$JAVA_HOME/bin
export PATH=$PATH:~/script/bin:~/scripts/eenmliu
#export PS1="\[$(tput bold)\]\[$(tput setaf 1)\][\[$(tput setaf 6)\]\u\[$(tput setaf 2)\]@\[$(tput setaf 4)\]\h \[$(tput setaf 5)\]\W\[$(tput setaf 1)\]]\[$(tput setaf 3)\]\\$\\n\[$(tput sgr0)\]"
alias tmpl="cd ~/bash4u/bash_perl_python/templates/bash_perl_python/"
alias static="cd ~/bash4u/bash_perl_python/static/bash_perl_python/"
alias pp="cd ~/bash4u/bash_perl_python/"
alias mypl='rlwrap perl -MData::Dumper -d -e 1'
alias t='tmux a -t 0'
alias h=history
alias ww=which
alias j=jobs
alias gits='git status'
alias gita='git commit --amend --no-edit'
alias gitc='git commit -m'
alias gitd='git diff'
alias s='sslocal -c /etc/shadowsocks.json'
alias less='less -R'

HISTTIMEFORMAT="%F %T "
#alias mon="killall monxls.sh; ~/*/monxls.sh &"
function mon {
killall monxls.sh
~/bash4u/monxls.sh $@ &
}


alias dj="exec 6<>/dev/tcp/0.0.0.0/8080 || python ~/bash4u/manage.py runserver 0.0.0.0:8080&"
#alias log="cat /var/log/apache2/access.log | egrep -v 'static|114.80.|59.45.|138.128.219.193|192.3.177.185|114.111.|54.172.|223.104.' | egrep '([[:digit:]]+\.){3}[[:digit:]]+'; date"
export ipfilter='static|^112\.|^47\.|^116.*|^114.80.|^59.45.|^61.|^138.128.219.193|^192.3.177.185|^114.111.|^54.172.|^223.104.|^101.199.112.'
export acc="/var/log/apache2/access.log"
function alog { 
cat /var/log/apache2/access.log{.1,} | egrep -v $ipfilter | egrep '^([[:digit:]]+\.){3}[[:digit:]]+|bot'; date
}
function ulog { 
set -v
cat /var/log/apache2/access.log{.1,} | egrep -v $ipfilter | egrep -v '(404|google|baidu|bing)'| egrep '^([[:digit:]]+\.){3}[[:digit:]]+|bot'; date
set +v
}
function atail { 
tail -100lf /var/log/apache2/access.log | egrep -v $ipfilter | egrep '([[:digit:]]+\.){3}[[:digit:]]+'; date 
}
#alias log="cat /var/log/apache2/access.log | egrep -v $ipfiler | egrep '([[:digit:]]+\.){3}[[:digit:]]+'; date"
#alias g="~/bash4u/git.sh"
#A surprise I found out recently is that Bash natively supports tcp connections as file descriptors. To use:
#0,1,2 are stdin, stdout, and stderr. 5 is sometimes used by Bash for child processes, so 3,4,6,7,8, and 9 should be safe.
#exec 6<>/dev/tcp/0.0.0.0/8080
#echo -e "GET / HTTP/1.0\n" >&6
#cat <&6

#exec 6<>/dev/tcp/0.0.0.0/8080 || nohup python ~/bash4u/manage.py runserver 0.0.0.0:8080&
#exec 6<>/dev/tcp/0.0.0.0/8080 || python ~/bash4u/manage.py runserver 0.0.0.0:8080&
#~/*/monxls.sh &
#curl ifconfig.me &
function igrep {
echo "egrep --color -i -r \"$1\" ~/summary" | bash -x
}

function a {
    declare -f $1 || { alias $1 || cat `which $1`; }
}
function ipgrep {
echo "egrep --color -i -r \"$1\" ~/graduation/python" | bash -x
}

function ibgrep {
echo "egrep --color -i -r \"$1\" ~/graduation/bash" | bash -x
}

function ijgrep {
echo "egrep --color -i -r \"$1\" ~/graduation/java" | bash -x
}

function ifind {
echo "find ~/summary/ -iname \"*$1*\" |egrep --color \"$1\"" | bash -x
}

function ijfind {
echo "find ~/graduation/java -iname \"*$1*\" |egrep --color \"$1\"" | bash -x
}

function ipfind {
echo "find ~/graduation/python -iname \"*$1*\" |egrep --color \"$1\"" | bash -x
}

function ibfind {
echo "find ~/graduation/bash -iname \"*$1*\" |egrep --color \"$1\"" | bash -x
}

function iprun {
gpfind "$1" | egrep "(^|[-_./])$1[-_.].*py$" | while read line; do echo -e "\n\n========== $line =========="; $line; done
}

function ibrun {
gbfind "$1" | egrep "(^|[-_./])$1[-_.].*sh$" | while read line; do echo -e "\n\n========== $line =========="; $line; done
}

function ihgrep {
echo "find /usr/include -name \"*.h\" -print |xargs egrep -n -i --color \"$1\"" |bash -x
}

function igcc {
#out=$1
out=${1%.*}
echo "gcc -o ${out}.o $1" | bash -x
}
#export PS1="\[$(tput bold)\]\[$(tput setaf 1)\][\[$(tput setaf 6)\]\u\[$(tput setaf 2)\]@\[$(tput setaf 4)\]\h \[$(tput setaf 5)\]\W\[$(tput setaf 1)\]]\[$(tput setaf 3)\]\\$\\n\[$(tput sgr0)\]"

function nonzero_return() {
	RETVAL=$?
	[ $RETVAL -ne 0 ] && echo "$RETVAL" || echo "$RETVAL"
}

alias g="~/summary/graduation/git.sh"
alias lrt='ls -lrt'
alias lt='ls -lt'
gen_subheader(){
  f="$1"
  header=" ~/graduation/${f#*graduation/} "
  length=100
  h_len=${#header}
  start=$(($((length-h_len))/2))
  endp=$((length - start - h_len))
  echo 
  #printf '=%.0s' 1 2 3 ...
  #printf '+%.0s' `seq $length`; echo
  printf '+%.0s' `seq $start`; printf "$header"; printf '+%.0s' `seq $endp`; echo
  #printf '+%.0s' `seq $length`;  echo
}

function ia {
for f in *.{py,sh}; do 
    if [ "$f" == "color.py" ] || [ "$f" == "common.sh" ]|| [ "$f" == '*.sh' ] || [ "$f" == '*.py' ]; then continue; fi
    echo -e "\n\n========== $f ==========" | egrep '^.*$' --color
    #gen_subheader $f  && $f
    "$f"
done
}

function ib {
if [ "$1" ]; then level=$1; fi
echo "level: $level"
if [ "$level" ]; then
  for f in ~/graduation/bash/*/*${level}.sh; do
    if fgrep -q '*' <<<"$f"; then continue; fi
    gen_subheader $f && $f
  done
else
  for f in ~/graduation/bash/*/*.sh; do
    if ! egrep -q '([0-9]|color).py'<<<"$f"; then
      gen_subheader $f && $f    
    fi
  done
fi
unset level
}



function ip {
if [ "$1" ]; then level=$1; fi
echo "level: $level"
if [ "$level" ]; then
  for f in ~/graduation/python/*/*${level}.{sh,py}; do
    if fgrep -q '*' <<<"$f"; then continue; fi
    gen_subheader $f && $f
  done
else
  for f in ~/graduation/python/*/*.{sh,py}; do
    if ! egrep -q '([0-9]|color).py'<<<"$f"; then
      gen_subheader $f && $f    
    fi
  done
fi
unset level
}

function ij {
if [ ! "$1" ]; then echo "usage: j javafilename"; return; fi
jname=`echo $1 | sed 's|\..*||g'`
pygmentize -g $jname.java
echo "------- output -------"
javac $jname.java && java $jname
rm -rf *.class
}

ide ()
{
    local pname;
    pname=$1;
    set -xv
   #mv -v $pname `sed 's/\.\(.*$\)/.done.\1/' <<<"$pname"`
    git mv -v $pname `sed 's/\.\(\w*\)$/.done.\1/' <<<"$pname"`
    set +xv
    ls -al | grep -v done
}
export VISUAL=vim
export EDITOR="$VISUAL"
export PATH=.:~/summary:$PATH
export PYTHONPATH=~/summary/graduation/python/
alias pz='pygmentize -g'
alias vimc='vim -U ~/.vimrc_c'
alias vimp='vim -u ~/.vimrc_py'

if [ -f ~/summary/graduation/projects/others/git-completion.bash ]; then
  #echo . ~/graduation/projects/others/git-completion.bash
  . ~/summary/graduation/projects/others/git-prompt.sh
fi

iwatch () 
{ 
    declare -f $FUNCNAME
    watch -n 1 -c "$@ |tail -n $((LINES-2))"
}

iw() {
  md1=""
  while(true); do
    md2=$(md5sum $1) 
    [ "$md1" = "$md2" ] || { md1=$md2; ic $1; } 
    sleep 2
  done 
}

iyoutube-cv-sub ()
{
    declare -f $FUNCNAME
    for f in *.vtt;
    do
bash -v <<EOF
sed -i 's/<[^>]*>//g' "$f";
EOF
    done;
}
iyoutube-dl (){
    declare -f $FUNCNAME
    youtube-dl --no-mtime --write-sub --write-auto-sub --sub-lang en --prefer-ffmpeg $@
    iyoutube-cv-sub
}
iyoutube-dl-sub (){
    declare -f $FUNCNAME
    youtube-dl --no-mtime --write-sub --write-auto-sub --sub-lang en --skip-download $@
    iyoutube-cv-sub
}

#build by http://ezprompt.net/
export PS1="\[\e[31m\][\[\e[m\]\[\e[33m\]\`nonzero_return\`\[\e[m\]\[\e[31m\]]\[\e[m\]\[\e[31m\][\[\e[m\]\s\v\[\e[31m\]]\[\e[m\]\[\e[31m\][\[\e[m\]\[\e[36m\]\u\[\e[m\]\[\e[32m\]@\[\e[m\]\[\e[34m\]\h\[\e[m\]\[\e[35m\] \W\[\e[m\]\[\e[31m\]]\[\e[m\]\n\[\e[33m\]\\$ \[\e[m\]"

alias sss='sudo killall ssserver; sudo  ssserver -p 22 -k siemens -m rc4-md5 --user nobody -d start; sleep 2; ps -ef|grep sss'
alias myperl='rlwrap perl -MData::Dumper -d -e 1'
