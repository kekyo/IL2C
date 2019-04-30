#!/bin/sh

PLATFORM=`arch`; export PLATFORM

cd IL2C.Runtime

rm -rf lib
rm -rf build

mkdir lib

mkdir build
cd build

# ================================================================================

echo ""
echo "///////////////////////////////////////////////"
echo '// Build IL2C.Runtime (gcc-linux-$PLATFORM-debug)'
echo ""

mkdir gcc-linux-$PLATFORM-debug
cd gcc-linux-$PLATFORM-debug

cmake -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=make -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc-linux.cmake -DPLATFORM=$PLATFORM -DCONFIGURATION=Debug ../..
cmake --build .

cd ..

# ===============================================

echo ""
echo "///////////////////////////////////////////////"
echo '// Build IL2C.Runtime (gcc-linux-$(PLATFORM)-release)'
echo ""

mkdir gcc-linux-$PLATFORM-release
cd gcc-linux-$PLATFORM-release

cmake -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=make -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc-linux.cmake -DPLATFORM=$PLATFORM -DCONFIGURATION=Release ../..
cmake --build .

cd ..

cd ..
cd ..
