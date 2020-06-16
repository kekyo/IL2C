@echo off
setlocal enabledelayedexpansion

set TOOLCHAINPATH=%~dp0toolchain\gcc4
set CMAKE_ROOT=%TOOLCHAINPATH%\share\cmake-3.17

if not exist %TOOLCHAINPATH% (
    echo Native toolchain not found.
    echo Execute "init-tools.bat" if build runtime at first time.
    exit /b 1
)

set PATH=%TOOLCHAINPATH%\bin;%PATH%

set Configuration=%1
if "%Configuration%" == "" (
    set Configuration=Debug
)

cd IL2C.Runtime

if exist build.cmake (
    move build.cmake build.cmake.old
    rmdir /s /q build.cmake.old
)

if not exist lib (
    mkdir lib
)

if exist lib\%Configuration% (
   move lib\%Configuration% lib\%Configuration%.old
   rmdir /s /q lib\%Configuration%.old
)

mkdir lib\%Configuration%

mkdir build.cmake
cd build.cmake

rem ================================================================================

:msvc-win-win32-rts

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-win32-rts-%Configuration%)
echo.

mkdir msvc-win-win32-rts-%Configuration%
cd msvc-win-win32-rts-%Configuration%

cmake -G "Visual Studio 16 2019" -A Win32 -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DPLATFORM=Win32 -DRUNTIMELIB=rts -DCONFIGURATION=%Configuration% ../..
if errorlevel 1 (
    exit /b %errorlevel%
)
cmake --build . -j --config %Configuration%
if errorlevel 1 (
    exit /b %errorlevel%
)

cd ..

rem ================================================================================

:msvc-win-x64-rts

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-x64-rts-%Configuration%)
echo.

mkdir msvc-win-x64-rts-%Configuration%
cd msvc-win-x64-rts-%Configuration%

cmake -G "Visual Studio 16 2019" -A x64 -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DPLATFORM=x64 -DRUNTIMELIB=rts -DCONFIGURATION=%Configuration% ../..
if errorlevel 1 (
    exit /b %errorlevel%
)
cmake --build . -j --config %Configuration%
if errorlevel 1 (
    exit /b %errorlevel%
)

cd ..

rem ================================================================================

:msvc-win-win32-rtd

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-win32-rtd-%Configuration%)
echo.

mkdir msvc-win-win32-rtd-%Configuration%
cd msvc-win-win32-rtd-%Configuration%

cmake -G "Visual Studio 16 2019" -A Win32 -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DPLATFORM=Win32 -DRUNTIMELIB=rtd -DCONFIGURATION=%Configuration% ../..
if errorlevel 1 (
    exit /b %errorlevel%
)
cmake --build . -j --config %Configuration%
if errorlevel 1 (
    exit /b %errorlevel%
)

cd ..

rem ================================================================================

:msvc-win-x64-rtd

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-x64-rtd-%Configuration%)
echo.

mkdir msvc-win-x64-rtd-%Configuration%
cd msvc-win-x64-rtd-%Configuration%

cmake -G "Visual Studio 16 2019" -A x64 -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-win.cmake -DPLATFORM=x64 -DRUNTIMELIB=rtd -DCONFIGURATION=%Configuration% ../..
if errorlevel 1 (
    exit /b %errorlevel%
)
cmake --build . -j --config %Configuration%
if errorlevel 1 (
    exit /b %errorlevel%
)

cd ..

rem ================================================================================

:msvc-uefi-win32

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-uefi-win32-%Configuration%)
echo.

mkdir msvc-uefi-win32-%Configuration%
cd msvc-uefi-win32-%Configuration%

cmake -G "Visual Studio 16 2019" -A Win32 -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-uefi.cmake -DPLATFORM=Win32 -DCONFIGURATION=%Configuration% ../..
if errorlevel 1 (
    exit /b %errorlevel%
)
cmake --build . -j --config %Configuration%
if errorlevel 1 (
    exit /b %errorlevel%
)

cd ..

rem ================================================================================

:msvc-uefi-x64

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-uefi-x64-%Configuration%)
echo.

mkdir msvc-uefi-x64-%Configuration%
cd msvc-uefi-x64-%Configuration%

cmake -G "Visual Studio 16 2019" -A x64 -DCMAKE_TOOLCHAIN_FILE=../../cmake/msvc-uefi.cmake -DPLATFORM=x64 -DCONFIGURATION=%Configuration% ../..
if errorlevel 1 (
    exit /b %errorlevel%
)
cmake --build . -j --config %Configuration%
if errorlevel 1 (
    exit /b %errorlevel%
)

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
if errorlevel 1 (
    exit /b %errorlevel%
)
cmake --build . -j
if errorlevel 1 (
    exit /b %errorlevel%
)
move ..\..\lib\libil2c-gcc4-win-mingw32-%Configuration%.a ..\..\lib\%Configuration%\libil2c-gcc4-win-mingw32.a
if errorlevel 1 (
    exit /b %errorlevel%
)

cd ..

cd ..
cd ..

:exit
