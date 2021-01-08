#!/usr/bin/env eepython
## When adding sections or items, add them in the reverse order of
## how you want them to be displayed in the actual file.
## In addition, please note that using RawConfigParser's and the raw
## mode of ConfigParser's respective set functions, you can assign
## non-string values to keys internally, but will receive an error
## when attempting to write to a file or when you get it in non-raw
## mode. SafeConfigParser does not allow such assignments to take place.

##write to a configuration file
import ConfigParser
config = ConfigParser.RawConfigParser(); print config
config.add_section('Section1')
config.set('Section1', 'an_int', '15')
config.set('Section1', 'a_bool', 'true')
config.set('Section1', 'a_float', '3.1415')
config.set('Section1', 'baz', 'fun')
config.set('Section1', 'bar', 'Python')
config.set('Section1', 'foo', '%(bar)s is %(baz)s!')

print sys.argv[1]
print os.path.basename(sys.argv[1])
print os.path.splitext(os.path.basename(sys.argv[1]))[0]
cfgfile = os.path.splitext(os.path.basename(sys.argv[1]))[0] + '.cfg'
with open(cfgfile, 'wb') as configfile:
    config.write(configfile)
os.system('cat ' + cfgfile)

##read from a configuration file
config = ConfigParser.RawConfigParser()
config.read(cfgfile)
# getfloat() raises an exception if the value is not a float
# getint() and getboolean() also do this for their respective types
a_float = config.getfloat('Section1', 'a_float'); print a_float
an_int = config.getint('Section1', 'an_int'); print an_int
print a_float + an_int
# Notice that the next output does not interpolate '%(bar)s' or '%(baz)s'.
# This is because we are using a RawConfigParser().
print config.getboolean('Section1', 'a_bool')
if config.getboolean('Section1', 'a_bool'):
    print config.get('Section1', 'foo')

##To get interpolation, you will need to use a ConfigParser or SafeConfigParser
config = ConfigParser.ConfigParser()
config.read(cfgfile)

# Set the third, optional argument of get to 1 if you wish to use raw mode.
print config.get('Section1', 'foo', 0)
print config.get('Section1', 'foo', 1)
# The optional fourth argument is a dict with members that will take
# precedence in interpolation.
print config.get('Section1', 'foo', 0, {'bar': 'Documentation',
                                        'baz': 'evil'})

##Defaults are available in all three types of ConfigParsers. They are used in interpolation if an option used is not defined elsewhere.
# New instance with 'bar' and 'baz' defaulting to 'Life' and 'hard' each
config = ConfigParser.SafeConfigParser({'bar': 'Life', 'baz': 'hard'})
config.read(cfgfile)
print config.get('Section1', 'foo')
config.remove_option('Section1', 'bar')
config.remove_option('Section1', 'baz')
print config.get('Section1', 'foo')
