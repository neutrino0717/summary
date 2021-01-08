#!/bin/esh
#"true" is a command, which will always return correctly
true && echo "'true' command return successfully"

abc='pwd'; $abc 1>/dev/null  && echo "command in variable \$abc return successfully"

if $abc 1>/dev/null; then echo "command in variable \$abc return successfully"; fi

cd no_such_dir 2>/dev/null || echo "cd failed"

#if the last command return successfully, \$? will return 0
true; echo $?
abc='pwd'; $abc 2>/dev/null; echo $?
cd no_such_dir 2>/dev/null; echo $?
