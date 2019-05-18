#!/bin/sh

Platform=`arch`; export Platform

cd IL2C.Runtime

rm -rf lib
rm -rf build

mkdir lib

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
