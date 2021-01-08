#!/usr/bin/env eepython
###easy_install-2.7 flask
import flask
from flask import Flask
print flask.__doc__
#print Flask.__doc__
app = Flask(__name__)

@app.route("/")
def hello():
    return "Hello World!"

#Running on http://localhost:5000/
app.run()

