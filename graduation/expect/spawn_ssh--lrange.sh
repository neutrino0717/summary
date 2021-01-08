#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/common.sh

echo -e "${red}${endColor}"
eprt '
Instead of this:

set host_name [lrange $argv 0 0]
set user [lrange $argv 1 1]
set password [lrange $argv 2 2]
set var [lrange $argv 3 end]

You should be doing this:

set host_name [lindex $argv 0]
set user [lindex $argv 1]
set password [lindex $argv 2]
set var [lindex $argv 3]

Notice the use of lindex rather than lrange.

The reason is, using lrange means that host_name, user, password and
var will be lists instead of scalers. 
**************************************
You are getting lucky with the first three because the string representation of lists with simple
values is often the same as the values separated with spaces (read:
[list foo bar] == "foo bar").
**************************************
'
elrun <<"EOF"
. constant.sh

pygmentize -g ${0}.exp

expect ${0}.exp $ipaddr $username $password grep BASH /etc/passwd -i --color

#lrange will return a list with one element consisting of a string with spaces, to get rid of "{ }", use lindex
#below will run 'grep BASH /etc/passwd -i --color', which will not be successful
expect ${0}.exp $ipaddr $username $password 'grep BASH /etc/passwd -i --color'
EOF

