@echo off
setlocal enabledelayedexpansion

set TOOLCHAINPATH=%~dp0toolchain\gcc4

if not exist %TOOLCHAINPATH% (
    echo Native toolchain not found.
    echo Execute "init-tools.bat" if build runtime at first time.
    goto exit
)

set PATH=%TOOLCHAINPATH%\bin;%PATH%

cd IL2C.Runtime

if exist build (
    rmdir /s /q build
)

mkdir build
cd build

if exist lib (
    rmdir /s /q lib
)

rem goto msvc-uefi-x64
rem goto gcc4-win-mingw32

rem ================================================================================

:msvc-win-win32

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-win32-debug)
echo.

mkdir msvc-win-win32-debug
cd msvc-win-win32-debug

cmake.exe -G "Visual Studio 15 2017" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DCMAKE_CONFIGURATION_TYPES=Debug ../..
cmake.exe --build . -j

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-win32-release)
echo.

mkdir msvc-win-win32-release
cd msvc-win-win32-release

cmake.exe -G "Visual Studio 15 2017" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DCMAKE_CONFIGURATION_TYPES=Release ../..
cmake.exe --build . -j

cd ..

rem ================================================================================

:msvc-win-x64

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-x64-debug)
echo.

mkdir msvc-win-x64-debug
cd msvc-win-x64-debug

cmake.exe -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DCMAKE_CONFIGURATION_TYPES=Debug ../..
cmake.exe --build . -j

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-x64-release)
echo.

mkdir msvc-win-x64-release
cd msvc-win-x64-release

cmake.exe -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DCMAKE_CONFIGURATION_TYPES=Release ../..
cmake.exe --build . -j

cd ..

rem ================================================================================

:msvc-uefi-x64

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-uefi-x64-debug)
echo.

mkdir msvc-uefi-x64-debug
cd msvc-uefi-x64-debug

cmake.exe -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-uefi.cmake -DCMAKE_CONFIGURATION_TYPES=Debug ../..
cmake.exe --build . -j

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-uefi-x64-release)
echo.

mkdir msvc-uefi-x64-release
cd msvc-uefi-x64-release

cmake.exe -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-uefi.cmake -DCMAKE_CONFIGURATION_TYPES=Release ../..
cmake.exe --build . -j

cd ..

rem ================================================================================

:gcc4-win-mingw32

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (gcc4-win-mingw32-debug)
echo.

mkdir gcc4-win-mingw32-debug
cd gcc4-win-mingw32-debug

cmake.exe -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=mingw32-make.exe -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc4-win-mingw32.cmake -DCMAKE_BUILD_TYPE=Debug ../..
cmake.exe --build . -j

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (gcc4-win-mingw32-release)
echo.

mkdir gcc4-win-mingw32-release
cd gcc4-win-mingw32-release

cmake.exe -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=mingw32-make.exe -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc4-win-mingw32.cmake -DCMAKE_BUILD_TYPE=Release ../..
cmake.exe --build . -j

cd ..

cd ..
cd ..

:exit
