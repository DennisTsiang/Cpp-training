#!/bin/bash

rm -f src/*.cpp
rm -f src/*.h
scons -c --rtos

case "$1" in
  2)  echo "BUILDING EXERCISE 02 (Classes)"
      cp ../../solutions/02_Classes/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  3)  echo "BUILDING EXERCISE 03 (STL)"
      cp ../../solutions/03_STL/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  4)  echo "BUILDING EXERCISE 04 (Hardware manipulation)"
      cp ../../solutions/04_Hardware_manipulation/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  5)  echo "BUILDING EXERCISE 05 (Hardware manipulation with objects)"
      cp ../../solutions/05_Hardware_with_objects/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  6)  echo "BUILDING EXERCISE 06 (Copmplex objects)"
      cp ../../solutions/06_Complex_objects/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  7)  echo "BUILDING EXERCISE 07 (Connecting objects)"
      cp ../../solutions/07_Connecting_objects/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  8)  echo "BUILDING EXERCISE 08 (Bit fields)"
      cp ../../solutions/08_Bit_fields/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  9)  echo "BUILDING EXERCISE 09 (Resource management)"
      cp ../../solutions/09_Resource_management/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  10) echo "BUILDING EXERCISE 10 (Move semantics)"
      cp ../../solutions/10_Move_semantics/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  11) echo "BUILDING EXERCISE 11 (Substitution)"
      cp ../../solutions/11_Substitution/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  12) echo "BUILDING EXERCISE 12 (Interfaces)"
      cp ../../solutions/12_Interfaces/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  13) echo "BUILDING EXERCISE 13 (Templates)"
      cp ../../solutions/13_Templates/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  14) echo "BUILDING EXERCISE 14 (Perfect forwarding)"
      cp ../../solutions/14_Perfect_forwarding/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  15) echo "BUILDING EXERCISE 15 (Interrupts)"
      cp ../../solutions/15_Interrupts/*.* src/
      scons || { echo 'build failed' ; exit 1; }
  ;;
  *)  echo "Please select between 2 - 15"
  ;;
esac
