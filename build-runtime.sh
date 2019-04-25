#!/bin/sh

cd IL2C.Runtime

rm -rf build

mkdir build
cd build

rem ================================================================================

:gcc

echo ""
echo "///////////////////////////////////////////////"
echo "// Build IL2C.Runtime (gcc-linux-debug)"
echo ""

mkdir gcc-linux-debug
cd gcc-linux-debug

cmake -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=make -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc-linux.cmake ../..
cmake --build . -j

cd ..

rem ===============================================

echo ""
echo "///////////////////////////////////////////////"
echo "// Build IL2C.Runtime (gcc-linux-release)"
echo ""

mkdir gcc-linux-release
cd gcc-linux-release

cmake -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=make -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc-linux.cmake ../..
cmake --build . -j

cd ..

cd ..
cd ..

:exit
