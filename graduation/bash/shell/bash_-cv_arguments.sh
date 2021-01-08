pygmentize -g <<EOF
#command: bash -c
/bin/bash -cv 'echo "$0" "$1"' foo bar
/bin/bash -c 'echo "$@"' bash foo bar
EOF

