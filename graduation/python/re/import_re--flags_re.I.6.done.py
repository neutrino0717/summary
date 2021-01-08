#!/usr/bin/env eepython
###re.I        
## ignore case matching
###re.M       
## $ and ^ match the end/start of a line
## AKA multiline mode -- a string may consists of multiple lines
## re.M Makes $ match the end of a line (not just the end of the string) 
## and makes ^ match the start of any line (not just the start of the string).
###re.S        
## makes .(dot) match any character even the new line character
###re.U        
## interprets in Unicode
###re.X        
## ignores whitespace within the pattern
###(?imx)      
## Temporarily toggles on i, m, or x options within a regular expression. If in parentheses, only that area is affected.
###(?-imx)     
## Temporarily toggles off i, m, or x options within a regular expression. If in parentheses, only that area is affected.
print re.__doc__
