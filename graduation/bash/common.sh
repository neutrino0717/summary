green='\e[0;32m'; blue='\e[0;34m'; red='\e[31m'; yellow='\e[0;33m'; endColor='\e[0m'


#allow alias expansion in non-interactive shells.
shopt -s expand_aliases

alias grep_grey="GREP_COLOR='1;30' grep --color=always"
alias grep_red="GREP_COLOR='1;31' grep --color=always"
alias grep_green="GREP_COLOR='1;32' grep --color=always"
alias grep_yellow="GREP_COLOR='1;33' grep --color=always"
alias grep_blue="GREP_COLOR='1;34' grep --color=always"
alias grep_magenta="GREP_COLOR='1;35' grep --color=always"
alias grep_cyan="GREP_COLOR='1;36' grep --color=always"
alias grep_white="GREP_COLOR='1;37' grep --color=always"
alias egrep_grey="GREP_COLOR='1;30' egrep --color=always"
alias egrep_red="GREP_COLOR='1;31' egrep --color=always"
alias egrep_green="GREP_COLOR='1;32' egrep --color=always"
alias egrep_yellow="GREP_COLOR='1;33' egrep --color=always"
alias egrep_blue="GREP_COLOR='1;34' egrep --color=always"
alias egrep_magenta="GREP_COLOR='1;35' egrep --color=always"
alias egrep_cyan="GREP_COLOR='1;36' egrep --color=always"
alias egrep_white="GREP_COLOR='1;37' egrep --color=always"

eprt(){
  echo -e "${red}$*${endColor}"
}
eprtdoc() {
  while read linp; do
    if [ "${linp:0:2}" == "##" ]; then
      echo -e "${yellow}$linp${endColor}"
    elif [ "${linp:0:1}" == "#" ]; then
      echo -e "${green}$linp${endColor}"
    else
      echo -e "${red}$linp${endColor}"
    fi
  done
}
erunw(){
  erun $*
  read -p "Hit Enter or wait 30 seconds" -t 30
}

elrun()
{
  #echo "$1" | while IFS= read linp; do
  while read linp; do
    if egrep -q '^#' <<<"$linp"; then 
        echo -e "${yellow}$linp${endColor}"
    else
        #echo "$linp"|pygmentize -l bash
        #echo -e "$linp\n${green}`eval $linp`${endColor}\n"
        echo -e "${green}$linp${endColor}"; eval "$linp"; echo 
    fi
  done
}

ebrun(){
  pattern='^\S' 
  multilinp=false
  b=''
  newlinp=$'\n'
  echo "$1" | while IFS= read -r linp; do
  #while read linp; do
    if [ -z "$linp" ]; then continue; fi
    if echo "$linp" |egrep -q "$pattern"; then
      if $multilinp; then
        b="$b$newlinp$linp"
        erun_nocolor "$b"
        b=""
        multilinp=false
      else
        if [ ! -z "$b" ]; then erun_nocolor "$b"; fi
        b="$linp"
      fi
    else
      multilinp=true 
      b="$b$newlinp$linp"
    fi
  done
  #echo "==>$b"
  #if [ "$b" ]; then echo "$b"; fi
}

esrun() {
  IFS='' read -r -d '' blx    #read in all
  blu=`echo "$blx" | sed -e 's/^\s*$/\xBF/'`  #replace ^\s*$ with a unicode charactor
  #1. split into a array
  #IFS=$'\xBF' read -d '' -a array <<< "$blu" 
  #2. or 
  echo "$blu" | while read -d $'\xBF' blui
  do
    #echo "$blui"
    erun_nocolor "$blui"
  done

}
edrun() {
  IFS='' read -r -d '' blx    #read in all
  blu=`echo "$blx" | sed -e 's/^---$/\xBF/'`  #replace ^---$ with a unicode charactor
  #1. split into a array
  #IFS=$'\xBF' read -d '' -a array <<< "$blu" 
  #2. or 
  echo "$blu" | while read -d $'\xBF' blui
  do
    #echo "$blui"
    erun_nocolor "$blui"
  done
}
erun(){
  #pygmentize -l bash <<EOF
  #$*
  #EOF

  #alog=`eval "$*"`
  #echo -e "${green}$alog${endColor}"
  #echo "$alog" |egrep_green "^.*$" 

  echo "$1" # |pygmentize -l bash
  echo -e -n "${green}`eval $1`${endColor}"
  echo
  echo
}

erun_nocolor(){
#pygmentize -l bash <<EOF
#$*
#EOF
echo -e "${green}$*${endColor}"; eval "$*"; #echo 
}


