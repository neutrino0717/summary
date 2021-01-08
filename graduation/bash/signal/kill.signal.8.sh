#!/bin/bash
rdir=`dirname $0`; adir=`(cd $rdir; pwd)`; . ${adir}/../common.sh
#source-highlight -s bash -o STDOUT  --out-format=esc
echo -e  "${yellow}

Signal     Value     Action   Comment
────────────────────────────────────────
SIGHUP        1       Term    Hangup detected on controlling terminal  --> kill 1 --> terminal closed?
                              or death of controlling process
SIGINT        2       Term    Interrupt from keyboard                  --> kill 2 --> ctrl-c
SIGQUIT       3       Core    Quit from keyboard
SIGILL        4       Core    Illegal Instruction
SIGABRT       6       Core    Abort signal from abort(3)
SIGFPE        8       Core    Floating point exception
SIGKILL       9       Term    Kill signal                              --> kill -9
SIGSEGV      11       Core    Invalid memory reference
SIGPIPE      13       Term    Broken pipe: write to pipe with no readers
SIGALRM      14       Term    Timer signal from alarm(2)
SIGTERM      15       Term    Termination signal                       --> kill [default]
SIGUSR1   30,10,16    Term    User-defined signal 1
SIGUSR2   31,12,17    Term    User-defined signal 2
SIGCHLD   20,17,18    Ign     Child stopped or terminated
SIGCONT   19,18,25    Cont    Continue if stopped
SIGSTOP   17,19,23    Stop    Stop process
SIGTSTP   18,20,24    Stop    Stop typed at terminal
SIGTTIN   21,21,26    Stop    Terminal input for background process
SIGTTOU   22,22,27    Stop    Terminal output for background process
${endColor}

default disposition for each signal, as follows:
Term   Default action is to terminate the process.
Ign    Default action is to ignore the signal.
Core   Default action is to terminate the process and dump core (see core(5)).
Stop   Default action is to stop the process.
Cont   Default action is to continue the process if it is currently stopped

TERM  -->  terminate
CORE  -->  terimnate and coredump


NAME
       kill - send a signal to a process

SYNOPSIS
       kill [options] <pid> [...]

DESCRIPTION
       The default signal for kill is TERM.  Use -l or -L to list available signals.  Particularly useful signals include HUP, INT, KILL, STOP, CONT, and
       0.  Alternate signals may be specified in three ways: -9, -SIGKILL or -KILL.  Negative PID values may be used to choose whole process groups;  see
       the PGID column in ps command output.  A PID of -1 is special; it indicates all processes except the kill process itself and init.
-1 or -HUP 
       This argument makes kill send the "Hang Up" signal to processes. This probably originates from the modem/dial-in era, this is very likely ${red}the safest kill signal${endColor} 
-2 or -SIGINT 
       This is the same as starting some program and pressing ${red}CTRL+C${endColor} during execution. Most programs will stop, you could lose data.
-9 or -KILL 
       The kernel will let go of the process ${red}without informing the process of it${endColor}.
-15 or -TERM 
       Tell the process to stop whatever it's doing, and end itself. ${red}When you don't specify any signal, this signal is used.${endColor} It should be fairly safe to perform, but better start with a "-1" or "-HUP".
"
echo "15 is default signal(TERM) for kill(send a signal to a process)"
erun "kill -l 15"
erun "kill -l"
erun "kill -l 1" 
erun "kill -l 9" 
