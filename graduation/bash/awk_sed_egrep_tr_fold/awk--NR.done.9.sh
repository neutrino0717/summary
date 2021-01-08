#!/bin/esh

# fs: field separator
# awk '[ -F fs]  pattern {action}'
cat /etc/nsswitch.conf | awk 'NR==1,NR==3'
cat /etc/nsswitch.conf | awk 'NR==1,/passwd/'
