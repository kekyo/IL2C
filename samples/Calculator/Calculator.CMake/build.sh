#!/bin/sh

if [ $# != 1 ]; then
  Configuration=Debug
else
  Configuration=$1
fi

Platform=`uname -m`

# =================================================
# Generate building scripts by CMake
# Using "out-of-source" build style.

if [ ! -d build ]; then
  mkdir build
fi

cd build

rm -rf $Configuration

mkdir $Configuration
cd $Configuration

cmake -G "Ninja" -DCMAKE_MAKE_PROGRAM=ninja -DBUILDER=gcc-linux -DPLATFORM=$Platform -DCONFIGURATION=$Configuration ../..
#cmake -DBUILDER=gcc-linux -DPLATFORM=$Platform -DCONFIGURATION=$Configuration ../..

if [ $? != 0 ]; then
    exit $?
fi

# =================================================
# Build target binary

cmake --build . -j

cd ..
cd ..
