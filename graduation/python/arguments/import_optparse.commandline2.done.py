#!/usr/bin/env eepython
import optparse
##manipulate the command line
cmd="%s -w localhost -f /etc/hosts" %sys.argv[1]; print cmd
sys.argv=cmd.split(); print sys.argv
h='''
usage %s -w <word> -f <file>
for example: 
%s -w localhost -f /etc/hosts
''' % (sys.argv[1], sys.argv[1])

parser = optparse.OptionParser(h)
parser.add_option('-w', dest='word',type='string',help='specify a word to search for')
parser.add_option('-f', dest='fname',type='string',help='specify a file to search')
(options, args) = parser.parse_args()
if(options.word == None) | (options.fname == None):
    print parser.usage
    exit(0)

print options.word
print options.fname
searchFile = open(options.fname)
linenum = 0
for line in searchFile.readlines():
    line = line.strip('\n\r')
    linenum += 1
    searchResult = re.search(options.word, line, re.M|re.I)
    if searchResult:
        print str(linenum) + ': ' + line

