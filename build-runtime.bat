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

for /d %%f in (build.*) do (
    rmdir /s /q %%f
)

rem goto msvc-uefi-x64
rem goto gcc4-win-mingw32

rem ================================================================================

:msvc-win-win32

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-win32-debug)
echo.

mkdir build.msvc-win-win32-debug
cd build.msvc-win-win32-debug

cmake.exe -G "Visual Studio 15 2017" -DCMAKE_TOOLCHAIN_FILE=../include/cmake/msvc-win.cmake ..
cmake.exe --build . --config Debug

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-win32-release)
echo.

mkdir build.msvc-win-win32-release
cd build.msvc-win-win32-release

cmake.exe -G "Visual Studio 15 2017" -DCMAKE_TOOLCHAIN_FILE=../include/cmake/msvc-win.cmake ..
cmake.exe --build . --config Release

cd ..

rem ================================================================================

:msvc-win-x64

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-x64-debug)
echo.

mkdir build.msvc-win-x64-debug
cd build.msvc-win-x64-debug

cmake.exe -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../include/cmake/msvc-win.cmake ..
cmake.exe --build . --config Debug

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-win-x64-release)
echo.

mkdir build.msvc-win-x64-release
cd build.msvc-win-x64-release

cmake.exe -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../include/cmake/msvc-win.cmake ..
cmake.exe --build . --config Release

cd ..

rem ================================================================================

:msvc-uefi-x64

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-uefi-x64-debug)
echo.

mkdir build.msvc-uefi-x64-debug
cd build.msvc-uefi-x64-debug

cmake.exe -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../include/cmake/msvc-uefi.cmake ..
cmake.exe --build . --config Debug

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (msvc-uefi-x64-release)
echo.

mkdir build.msvc-uefi-x64-release
cd build.msvc-uefi-x64-release

cmake.exe -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=../include/cmake/msvc-uefi.cmake ..
cmake.exe --build . --config Release

cd ..

rem ================================================================================

:gcc4-win-mingw32

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (gcc4-win-mingw32-debug)
echo.

mkdir build.gcc4-win-mingw32-debug
cd build.gcc4-win-mingw32-debug

cmake.exe -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=mingw32-make.exe -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=../include/cmake/gcc4-win-mingw32.cmake ..
cmake.exe --build . -j

cd ..

rem ===============================================

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime (gcc4-win-mingw32-release)
echo.

mkdir build.gcc4-win-mingw32-release
cd build.gcc4-win-mingw32-release

cmake.exe -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=mingw32-make.exe -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=../include/cmake/gcc4-win-mingw32.cmake ..
cmake.exe --build . -j

cd ..

cd ..

:exit
