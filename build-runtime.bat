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
    move build build.old
    rmdir /s /q build.old
)

if exist lib (
   move lib lib.old
   rmdir /s /q lib.old
)

mkdir build
cd build

rem ================================================================================

:msvc-win-win32

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-win32-debug)
echo.

mkdir msvc-win-win32-debug
cd msvc-win-win32-debug

cmake -G "Visual Studio 15 2017" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DPLATFORM=Win32 -DCONFIGURATION=Debug ../..
cmake --build . -j --config Debug

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-win32-release)
echo.

mkdir msvc-win-win32-release
cd msvc-win-win32-release

cmake -G "Visual Studio 15 2017" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DPLATFORM=Win32 -DCONFIGURATION=Release ../..
cmake --build . -j --config Release

cd ..

rem ================================================================================

:msvc-win-x64

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-x64-debug)
echo.

mkdir msvc-win-x64-debug
cd msvc-win-x64-debug

cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DPLATFORM=x64 -DCONFIGURATION=Debug ../..
cmake --build . -j --config Debug

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-x64-release)
echo.

mkdir msvc-win-x64-release
cd msvc-win-x64-release

cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DPLATFORM=x64 -DCONFIGURATION=Release ../..
cmake --build . -j --config Release

cd ..

rem ================================================================================

:msvc-uefi-x64

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-uefi-x64-debug)
echo.

mkdir msvc-uefi-x64-debug
cd msvc-uefi-x64-debug

cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-uefi.cmake -DPLATFORM=x64 -DCONFIGURATION=Debug ../..
cmake --build . -j --config Debug

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-uefi-x64-release)
echo.

mkdir msvc-uefi-x64-release
cd msvc-uefi-x64-release

cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-uefi.cmake -DPLATFORM=x64 -DCONFIGURATION=Release ../..
cmake --build . -j --config Release

cd ..

rem ================================================================================

:gcc4-win-mingw32

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (gcc4-win-mingw32-debug)
echo.

mkdir gcc4-win-mingw32-debug
cd gcc4-win-mingw32-debug

cmake -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=mingw32-make.exe -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc4-win-mingw32.cmake -DPLATFORM=mingw32 -DCONFIGURATION=Debug ../..
cmake --build . -j
move ..\..\lib\libil2c-gcc4-win-mingw32-Debug.a ..\..\lib\Debug\libil2c-gcc4-win-mingw32.a

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (gcc4-win-mingw32-release)
echo.

mkdir gcc4-win-mingw32-release
cd gcc4-win-mingw32-release

cmake -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=mingw32-make.exe -DCMAKE_TOOLCHAIN_FILE=../../cmake/gcc4-win-mingw32.cmake -DPLATFORM=mingw32 -DCONFIGURATION=Release ../..
cmake --build . -j
move ..\..\lib\libil2c-gcc4-win-mingw32-Release.a ..\..\lib\Release\libil2c-gcc4-win-mingw32.a

cd ..

cd ..
cd ..

:exit
