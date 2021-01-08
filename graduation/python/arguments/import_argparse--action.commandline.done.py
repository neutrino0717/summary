#!/usr/bin/env eepython
##Argument Actions
##
##There are six built-in actions that can be triggered when an argument is encountered:
##
##store
##    Save the value, after optionally converting it to a different type. This is the default action taken if none is specified expliclity.
##store_const
##    Save a value defined as part of the argument specification, rather than a value that comes from the arguments being parsed. This is typically used to implement command line flags that are not booleans.
##store_true / store_false
##    Save the appropriate boolean value. These actions are used to implement boolean switches.
##append
##    Save the value to a list. Multiple values are saved if the argument is repeated.
##append_const
##    Save a value defined in the argument specification to a list.
##version
##    Prints version details about the program and then exits. 
#cmd="%s -h" % sys.argvb[1]
#cmd="%s -c" % sys.argvb[1]
#cmd="%s -t" % sys.argvb[1]
#cmd="%s -f" % sys.argvb[1]
#cmd="%s -a one -a two -a three" % sys.argvb[1]
#cmd="%s -B -A" % sys.argvb[1]
#cmd="%s --version" % sys.argvb[1]
cmd="%s -s test.txt -c -t -f -a aone -a atwo -a athree -B -A" % sys.argv[1]; print cmd
sys.argv=cmd.split(); print sys.argv

import argparse
parser = argparse.ArgumentParser()
parser.add_argument('-s', action='store',        dest='var_simple',                                          help='Store a simple value')
parser.add_argument('-c', action='store_const',  dest='var_constant',         const='conlyvalue',            help='Store a constant value')
parser.add_argument('-t', action='store_true',   dest='var_bool_true',                        default=True,  help='Set a switch to true')
parser.add_argument('-f', action='store_false',  dest='var_bool_false',                       default=False, help='Set a switch to false')
parser.add_argument('-a', action='append',       dest='var_collection',                       default=[],    help='Add repeated values to a list')
parser.add_argument('-A', action='append_const', dest='var_collection_const', const='value1', default=[],    help='Add different values to list')
parser.add_argument('-B', action='append_const', dest='var_collection_const', const='value2',                help='Add different values to list')
parser.add_argument('--version', action='version', version='%(prog)s 1.0')

results = parser.parse_args()
print results.var_simple
print results.var_constant
print results.var_bool_true
print results.var_collection
print results.var_collection_const
