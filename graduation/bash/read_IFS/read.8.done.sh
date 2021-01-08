#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh
eprt "
-p      prompt
-i      added in bash 4.0. help '[r]ead' to get the help for read only.
        Note that while read -e will be able to complete inside ~, it will not be expanded.

-e      If the standard input is coming from a terminal, Readline is used to obtain the line.
-r      do not allow backslashes to escape any characters

-d delim    continue until the first character of DELIM is read, rather than newline
"

erun "read -r -e name <<<'Neutrino'; echo \$name"


eprt "dls972-3.seln.ete.ericsson.se       ----->    dls972"
erun "echo dls972-3.seln.ete.ericsson.se | sed 's/^\(.*\)-.*$/\1/'"



