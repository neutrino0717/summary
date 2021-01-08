#!/usr/bin/env eepython
##https://blog.miguelgrinberg.com/post/easy-websockets-with-flask-and-gevent
##_pre_9_Creating a Chat App With Flask-SocketIO.mp4
##[neutrino@dell flask]$
##pip install flask-socketio
##  Downloading itsdangerous-0.24.tar.gz (46kB)
##  Downloading click-6.6.tar.gz (283kB)
##  Downloading Jinja2-2.8-py2.py3-none-any.whl (263kB)
##  Downloading Werkzeug-0.11.11-py2.py3-none-any.whl (306kB)
##Successfully installed Flask-0.11.1 Jinja2-2.8 Werkzeug-0.11.11 click-6.6 itsdangerous-0.24
##
##if you get message below, do as instructed: pip install eventlet
##WebSocket transport not available. Install eventlet or gevent and gevent-websocket for improved performance.
from flask import Flask
from flask_socketio import SocketIO, send

app = Flask(__name__)
app.config['SECRET_KEY'] = 'mysecret'
socketio = SocketIO(app)

#listen for 'message' event
@socketio.on('message')
def handleMessage(msg):
    print('get message: ' + str(msg))
    send(msg, broadcast=True)

if __name__ == '__main__':
    #app.run()
    socketio.run(app)
    
