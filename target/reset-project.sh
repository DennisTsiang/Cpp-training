#!/bin/sh

echo "resetting project..."

rm -f src/*.cpp
rm -f src/*.h

scons -c --rtos

cp ./init_src/*.* src/
