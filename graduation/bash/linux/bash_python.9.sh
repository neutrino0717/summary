#!/bin/bash


""":"
if [ ! "$1" ]; then set "p1" "p2" "p3"; fi
echo "in bash "
echo "    usage: $0 $@"
echo '    note: ${varname:+word1}
            If varname exists and is not null, return word1; otherwise return null.
            Purpose: Testing for the existence of a variable.
'
echo '    1. \"\"\":\" means two double quotes'
echo '    2. bash exits when exec, and be replaced by python $0 ${1+"$@"}'
echo "    Set PYTHONPATH to include what is needed"
# export PYTHONPATH=/lab/epg_st_utils/lib
echo '    exec python $0 ${1+"$@"}'
exec python $0 ${1+"$@"}
"""
import re
import sys
print "in python"
print "    %s" % re.__file__
print "    %s" % sys.argv
