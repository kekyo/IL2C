#!/bin/sh

if [ $# != 1 ]; then
  Configuration=Debug
else
  Configuration=$1
fi

PLATFORM=`uname -m`

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

cmake -DARCHITECTURE=gcc-linux -DPLATFORM=$PLATFORM -DCONFIGURATION=$Configuration ../..

if [ $? != 0 ]; then
    exit $?
fi

# =================================================
# Build target binary

cmake --build . -j

cd ..
cd ..
