@echo off
setlocal enabledelayedexpansion

rem =================================================
rem Setup mingw gcc environments.

set TOOLCHAINPATH=%~dp0..\..\..\toolchain\gcc4
set CMAKE_ROOT=%TOOLCHAINPATH%\share\cmake-3.12

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

rem =================================================
rem Generate building scripts by CMake
rem Using "out-of-source" build style.

if not exist build (
    mkdir build
)

cd build

if exist %Configuration% (
    move %Configuration% %Configuration%.old
    rmdir /s /q %Configuration%.old
)

mkdir %Configuration%
cd %Configuration%

rem For use GNU make
cmake -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=mingw32-make.exe -DPLATFORM=mingw32 -DCONFIGURATION=%Configuration% ../..

rem For use Ninja
rem cmake -G "Ninja" -DCMAKE_MAKE_PROGRAM=ninja.exe -DPLATFORM=mingw32 -DCONFIGURATION=%Configuration% ../..

if errorlevel 1 (
    exit /b %errorlevel%
)

rem =================================================
rem Build target binary

cmake --build . -j
if errorlevel 1 (
    exit /b %errorlevel%
)

cd ..
cd ..
