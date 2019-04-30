#!/bin/sh

PLATFORM=`arch`; export PLATFORM

cd IL2C.Runtime

rm -rf build

mkdir build
cd build

# ================================================================================

echo ""
echo "///////////////////////////////////////////////"
echo "// Build IL2C.Runtime (gcc-linux-${PLATFORM}-debug)"
echo ""

mkdir gcc-linux-debug
cd gcc-linux-debug

cmake -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=make -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc-linux.cmake -DPLATFORM=${PLATFORM} -DCONFIGURATION=Debug ../..
cmake --build . -j

cd ..

# ===============================================

echo ""
echo "///////////////////////////////////////////////"
echo '// Build IL2C.Runtime (gcc-linux-$(PLATFORM)-release)'
echo ""

mkdir gcc-linux-release
cd gcc-linux-release

cmake -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=make -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc-linux.cmake -DPLATFORM=${PLATFORM} -DCONFIGURATION=Release ../..
cmake --build . -j

cd ..

cd ..
cd ..

:exit
