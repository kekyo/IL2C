#!/bin/sh

cd IL2C.Runtime

rmdir /s /q build.gcc-linux-debug
rmdir /s /q build.gcc-linux-release

rem ================================================================================

:gcc

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (gcc-linux-debug)
echo.

mkdir build.gcc-linux-debug
cd build.gcc-linux-debug

cmake -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=make -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=../cmake/gcc-linux.cmake ..
cmake --build . -j

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (gcc-linux-release)
echo.

mkdir build.gcc-linux-release
cd build.gcc-linux-release

cmake -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=make -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=../cmake/gcc-linux.cmake ..
cmake --build . -j

cd ..

cd ..

:exit
