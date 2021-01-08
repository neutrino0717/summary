#!/usr/bin/env eepython
x = [ 1, 2 ,3 ]; print id(x), x
x.append(4);     print id(x), x
x.append([4,5]); print id(x), x
x.extend([4,5]); print id(x), x
x = x + [4, 5 ]; print id(x), x
