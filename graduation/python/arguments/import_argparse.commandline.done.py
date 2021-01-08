#!/usr/bin/env eepython
##argparse module was added to Python 2.7 as a replacement for optparse
##argparse can be used as a straightforward replacement by updating the names of the classes and methods used in many cases.
##
import argparse
cmd="%s -w local -f /etc/hosts"%sys.argv[1]; print cmd
sys.argv=cmd.split(); print sys.argv

parser = argparse.ArgumentParser(prog='PROG', usage="usage %(prog)s -w <word> -f <file>", description="this is a sample test")
#parser = argparse.ArgumentParser()
parser.add_argument('-w', dest='word',type=str,help='specify a word to search for')
parser.add_argument('-f', dest='fname',type=str,help='specify a file to search')
ns=parser.parse_args()
if(ns.word == None) | (ns.fname == None):
    print parser.usage
    exit(0)
print parser
print ns
print ns.__class__.__name__
print ns.word
print ns.fname

