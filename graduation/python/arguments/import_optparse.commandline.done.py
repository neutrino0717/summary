#!/usr/bin/env eepython
import optparse
cmd="%s -w local -f /etc/hosts"%sys.argv[1]; print cmd
sys.argv=cmd.split(); print sys.argv
parser = optparse.OptionParser(usage="%prog -w <word> -f <file>", description="this is a sample test")
parser.add_option('-w', '--word', dest='word',type='string',help='specify a word to search for')
parser.add_option('-f', '--file', dest='fname',type='string',help='specify a file to search')
parser.add_option('-v', '--verbose', dest='vv', action="store_true", help='output verbose info')
#(options, args) = parser.parse_args()
#or the same as
(options, args) = parser.parse_args(sys.argv[1:])
#if(options.word == None) | (options.fname == None):
print parser.usage
print parser.print_help()
print parser
print options
print options.__class__.__name__
print {}.__class__.__name__
print args
print options.word
print options.fname
