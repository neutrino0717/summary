#!/usr/bin/python





############## multilayer decorator #####################################
def strong_decorate(func): #get_text = strong_decorate(get_text)
    def func_wrapper(name):
        return "<strong>{0}</strong>".format(func(name))
    return func_wrapper

def p_decorate(func):
   def func_wrapper(name):
       return "<p>{0}</p>".format(func(name))
   return func_wrapper
   
def div_decorate(func):
    def func_wrapper(name):
        return "<div>{0}</div>".format(func(name))
    return func_wrapper
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
@div_decorate
@p_decorate
@strong_decorate
def get_text(name):
    return "Hello "+name
-----------------------------------------
def get_text(name):
    return "Hello "+name
get_text = strong_decorate(get_text)
get_text = p_decorate(get_text)
get_text = div_decorate(get_text)
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
print(get_text("John"))
# <div><p><strong>Hello John</strong></p></div>

###########Passing arguments to decorators################################
#from functools import wraps
def tags(tag_name):
    def tags_decorator(func):
        #@wraps(func)       #--> get_text.__name__, get_text.__doc__, get_text.__module__ will return correct values
        def func_wrapper(name):
            return "<{1}>{0}</{1}>".format(func(name),tag_name)
        return func_wrapper
    return tags_decorator
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
@tags("div")
@tags("p")
@tags("strong")
def get_text(name):
    return "Hello "+name
----------------------------------------
def get_text(name):
    return "Hello "+name
print(get_text("John"))
get_text = tags("strong")(get_text)
get_text = tags("p")(get_text)
get_text = tags("div")(get_text)
print(get_text("John"))
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
print(get_text("John"))
#<div><p><strong>Hello John</strong></p></div>