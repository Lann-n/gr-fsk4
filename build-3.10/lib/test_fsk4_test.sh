#!/usr/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/lann/Project/gr-fsk4/lib
export GR_CONF_CONTROLPORT_ON=False
export PATH="/home/lann/Project/gr-fsk4/build-3.10/lib":"$PATH"
export LD_LIBRARY_PATH="":$LD_LIBRARY_PATH
export PYTHONPATH=/home/lann/Project/gr-fsk4/build-3.10/test_modules:$PYTHONPATH
test-fsk4 
