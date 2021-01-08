#!/usr/bin/env eepython
#multiprocessing supports two types of communication channel between processes:
##Queues
#a near clone of Queue.Queue, thread and process safe
##Pipes
#returns a pair of connection objects connected by a pipe which by default is duplex (two-way)

##test multiprocessing.Queue
from multiprocessing import Process, Queue
def f(q):
    q.put([42, None, 'hello'])

q = Queue()
p = Process(target=f, args=(q,))
p.start()
#data retrieved from the subprocessi by queue.
print q.get() 
p.join()

##test multiprocessing.Pipe
from multiprocessing import Process, Pipe
def f(conn):
    conn.send([42, None, 'hello'])
    conn.close()

parent_conn, child_conn = Pipe()
p = Process(target=f, args=(child_conn,))
p.start()
#data retrieved from the subprocess by pipe.
print parent_conn.recv()
p.join()
