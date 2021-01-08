#!/usr/bin/python
from datetime import date  
#function under test 
def get_most_popular_animal():  
    month = get_month()  
    if month in [11,12,1]:  
        return 'penguin'  
    elif month in [6,7,8]:  
        return 'swan'  
    else:  
        return 'tiger'  
#to be mocked  
def get_month():  
    today = date.today()  
    return today.month  
#to be mocked
def get_day():  
    today = date.today()  
    return today.day 



#class under test
class Zoo(object):  
   def __init__(self):  
       self.animals = ['penguin', 'swan', 'tiger', 'monkey']  
   def get_most_popular_animal(self):  
       month = self.get_month()  
       if month in [11,12,1]:  
           return 'penguin'  
       elif month in [6,7,8]:  
           return 'swan'  
       else:  
           return 'tiger'  
   def get_month(self):  
       today = date.today()  
       return today.month   
