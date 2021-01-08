#!/bin/bash -v
echo $'print("Star trek!")' > /tmp/knight.py
python -m dis /tmp/knight.py
python3 -m dis /tmp/knight.py
python3 -c 'import dis; dis.dis(open("/tmp/knight.py").read())'

