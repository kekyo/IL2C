@echo off
setlocal enabledelayedexpansion

set TOOLCHAINPATH=%~dp0toolchain\gcc4
set CMAKE_ROOT=%TOOLCHAINPATH%\share\cmake-3.12

if not exist %TOOLCHAINPATH% (
    echo Native toolchain not found.
    echo Execute "init-tools.bat" if build runtime at first time.
    goto exit
)

set PATH=%TOOLCHAINPATH%\bin;%PATH%

set Configuration=%1
if "%Configuration%" == "" (
    set Configuration=Debug
)

cd IL2C.Runtime

if exist build (
    move build build.old
    rmdir /s /q build.old
)

if not exist lib (
    mkdir lib
)

if exist lib\%Configuration% (
   move lib\%Configuration% lib\%Configuration%.old
   rmdir /s /q lib\%Configuration%.old
)

mkdir lib\%Configuration%

mkdir build
cd build

rem goto gcc-azuresphere-arm

rem ================================================================================

:msvc-win-win32

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-win32-%Configuration%)
echo.

mkdir msvc-win-win32-%Configuration%
cd msvc-win-win32-%Configuration%

cmake -G "Visual Studio 15 2017" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DPLATFORM=Win32 -DCONFIGURATION=%Configuration% ../..
cmake --build . -j --config %Configuration%

cd ..

rem ================================================================================

:msvc-win-x64

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-x64-%Configuration%)
echo.

mkdir msvc-win-x64-%Configuration%
cd msvc-win-x64-%Configuration%

cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DPLATFORM=x64 -DCONFIGURATION=%Configuration% ../..
cmake --build . -j --config %Configuration%

cd ..

rem ================================================================================

:msvc-uefi-x64

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-uefi-x64-%Configuration%)
echo.

mkdir msvc-uefi-x64-%Configuration%
cd msvc-uefi-x64-%Configuration%

cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-uefi.cmake -DPLATFORM=x64 -DCONFIGURATION=%Configuration% ../..
cmake --build . -j --config %Configuration%

cd ..

goto gcc4-win-mingw32

rem ================================================================================

rem TEMPORARY DISABLED:
rem 1. gcc-azuresphere-arm has a problem by cmake's generated rules.ninja.
rem    It contains the executable path translated to short path form.
rem    Will cause not found error at the ninja.
rem 2. Azure Sphere toolchain can't fit CI process because it has to install by vsix.

:gcc-azuresphere-arm

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (gcc-azuresphere-arm-%Configuration%)
echo.

mkdir gcc-azuresphere-arm-%Configuration%
cd gcc-azuresphere-arm-%Configuration%

cmake -G "Ninja" -DCMAKE_MAKE_PROGRAM=ninja.exe -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc-azuresphere.cmake -DPLATFORM=arm -DCONFIGURATION=%Configuration% ../..
cmake --build . -j

if not exist ()

move ..\..\lib\libil2c-gcc-azuresphere-arm-Debug.a ..\..\lib\%Configuration%\libil2c-gcc-azuresphere-arm.a

cd ..

rem ================================================================================

:gcc4-win-mingw32

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (gcc4-win-mingw32-%Configuration%)
echo.

mkdir gcc4-win-mingw32-%Configuration%
cd gcc4-win-mingw32-%Configuration%

cmake -G "Ninja" -DCMAKE_MAKE_PROGRAM=ninja.exe -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc4-win-mingw32.cmake -DPLATFORM=mingw32 -DCONFIGURATION=%Configuration% ../..
cmake --build . -j
move ..\..\lib\libil2c-gcc4-win-mingw32-%Configuration%.a ..\..\lib\%Configuration%\libil2c-gcc4-win-mingw32.a

cd ..

cd ..
cd ..

:exit
