#!/bin/bash

set -e

OPT="-O2"
DBG="-ggdb3 -DDEBUG"
CFLAGS="-Wall -I../src"
OPTCFLAGS="${CFLAGS} ${OPT}"
DBGCFLAGS="${CFLAGS} ${DBG}"

rm -f *.exe *.dbg

gcc ${OPTCFLAGS} test_z85.c ../src/z85.c -o test_z85.exe
gcc ${DBGCFLAGS} test_z85.c ../src/z85.c -o test_z85.dbg

strip *.exe
