#!/bin/esh

# -z string     True if the length of string is zero.
# -n string     True if the length of string is non-zero.

f="$HOME/.bash_aliases"

[ -a "$f" ] && echo "$f exists"
[ -e "$f" ] && echo "$f exists"
[ -f "$f" ] && echo "$f exists and is a regular file"
[ -s "$f" ] && echo "$f exists and is greater that zero in size"
[ -r "$f" ] && echo "$f exists and is readable"
[ -x "$f" ] && echo "$f exists and is executable"
[ -h "$f" ] && echo "$f exists and is a synbolic link"
[ -L "$f" ] && echo "$f exists and is a synbolic link"
[ -p "$f" ] && echo "$f exists and is a named pipe"
[ -b "$f" ] && echo "$f exists and is a block special file"
[ -d "$f" ] && echo "$f exists and is a directory"

testvar(){
    echo "the variable is \"$1\""
    echo -n "1: "; [ -v "$1" ] && echo "\$1 is assigned a value" || echo
    echo -n "2: "; [ -R "$1" ] && echo "\$1 is name reference"   || echo 
    echo -n "3: "; [ -z "$1" ] && echo "\$1 the length is zero"  || echo 
    echo -n "4: "; [ -n "$1" ] && echo "\$1 the length is not zero" || echo
    echo -n "5: "; [ "$1" ] && echo "\$1 the length is not zero" || echo
}
testvar
testvar ""
testvar "hello" 

