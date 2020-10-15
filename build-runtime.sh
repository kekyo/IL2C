#!/bin/sh

Platform=`uname -m`; export Platform

if [ $# != 1 ]; then
  Configuration=Debug
else
  Configuration=$1
fi

cd IL2C.Runtime

rm -rf build.cmake

if [ ! -d lib ]; then
  mkdir lib
fi

mkdir build.cmake
cd build.cmake

# ================================================================================

echo ""
echo "///////////////////////////////////////////////"
echo '// Build IL2C.Runtime (gcc-linux-$Platform-$Configuration)'
echo ""

mkdir gcc-linux-$Platform-$Configuration
cd gcc-linux-$Platform-$Configuration

cmake -G "Ninja" -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc-linux.cmake -DPLATFORM=$Platform -DCONFIGURATION=$Configuration ../..
cmake --build .

cd ..

cd ..
cd ..
