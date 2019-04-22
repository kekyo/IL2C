@echo off
setlocal enabledelayedexpansion

set TOOLCHAINPATH=%~dp0toolchain\gcc4\
set PATH=%TOOLCHAINPATH%bin;%PATH%

cd IL2C.Runtime

rmdir /s /q build.msvc-win32-debug
rmdir /s /q build.msvc-win32-release
rmdir /s /q build.msvc-x64-debug
rmdir /s /q build.msvc-x64-release
rmdir /s /q build.gcc4-mingw32-debug
rmdir /s /q build.gcc4-mingw32-release

rem goto gcc4-mingw32

rem ================================================================================

:msvc-win32

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win32-debug)
echo.

mkdir build.msvc-win32-debug
cd build.msvc-win32-debug

cmake.exe -G "Visual Studio 15 2017" -DCMAKE_TOOLCHAIN_FILE=../cmake/msvc.cmake ..
msbuild IL2C.Runtime.sln /p:Platform=Win32 /p:Configuration=Debug

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win32-release)
echo.

mkdir build.msvc-win32-release
cd build.msvc-win32-release

cmake.exe -G "Visual Studio 15 2017" -DCMAKE_TOOLCHAIN_FILE=../cmake/msvc.cmake ..
msbuild IL2C.Runtime.sln /p:Platform=Win32 /p:Configuration=Release

cd ..

rem ================================================================================

:msvc-x64

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-x64-debug)
echo.

mkdir build.msvc-x64-debug
cd build.msvc-x64-debug

cmake.exe -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../cmake/msvc.cmake ..
msbuild IL2C.Runtime.sln /p:Platform=x64 /p:Configuration=Debug

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-x64-release)
echo.

mkdir build.msvc-x64-release
cd build.msvc-x64-release

cmake.exe -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../cmake/msvc.cmake ..
msbuild IL2C.Runtime.sln /p:Platform=x64 /p:Configuration=Release

cd ..

rem ================================================================================

:gcc4-mingw32

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (gcc4-mingw32-debug)
echo.

mkdir build.gcc4-mingw32-debug
cd build.gcc4-mingw32-debug

cmake.exe -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=../cmake/gcc-mingw.cmake ..
mingw32-make.exe -j

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (gcc4-mingw32-release)
echo.

mkdir build.gcc4-mingw32-release
cd build.gcc4-mingw32-release

cmake.exe -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=../cmake/gcc-mingw.cmake ..
mingw32-make.exe -j

cd ..

cd ..
