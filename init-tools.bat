@echo off
echo "Setup nbgv ..."
dotnet tool install -g nbgv

echo "Setup native binary toolchain (IL2C-toolchain-gcc4-mingw32) ..."

rmdir /s /q toolchain
mkdir toolchain

cd toolchain

rem ========================================================
rem Download preconfigured gcc4 toolchain from GitHub.
rem It contains:
rem -----------------
rem mingwBaseUrl = "https://jaist.dl.sourceforge.net/project/mingw/MinGW";
rem bsdTarUrl = mingwBaseUrl + "/Extension/bsdtar/basic-bsdtar-2.8.3-1/basic-bsdtar-2.8.3-1-mingw32-bin.zip";
rem gccRequirementUrls =
rem     mingwBaseUrl + "/Base/binutils/binutils-2.28/binutils-2.28-1-mingw32-bin.tar.xz",
rem     mingwBaseUrl + "/Base/mingwrt/mingwrt-3.20/mingwrt-3.20-2-mingw32-dev.tar.lzma",
rem     mingwBaseUrl + "/Base/mingwrt/mingwrt-3.20/mingwrt-3.20-2-mingw32-dll.tar.lzma",
rem     mingwBaseUrl + "/Base/w32api/w32api-3.17/w32api-3.17-2-mingw32-dev.tar.lzma",
rem     mingwBaseUrl + "/Base/mpc/mpc-1.0.1-2/mpc-1.0.1-2-mingw32-dll.tar.lzma",
rem     mingwBaseUrl + "/Base/mpfr/mpfr-3.1.2-2/mpfr-3.1.2-2-mingw32-dll.tar.lzma",
rem     mingwBaseUrl + "/Base/gmp/gmp-5.1.2/gmp-5.1.2-1-mingw32-dll.tar.lzma",
rem     mingwBaseUrl + "/Base/libiconv/libiconv-1.14-3/libiconv-1.14-3-mingw32-dll.tar.lzma",
rem     mingwBaseUrl + "/Base/pthreads-w32/pthreads-w32-2.9.1/pthreads-w32-2.9.1-1-mingw32-dev.tar.lzma",
rem     mingwBaseUrl + "/Base/pthreads-w32/pthreads-w32-2.9.1/pthreads-w32-2.9.1-1-mingw32-dll.tar.lzma",
rem     mingwBaseUrl + "/Base/zlib/zlib-1.2.8/zlib-1.2.8-1-mingw32-dll.tar.lzma",
rem     mingwBaseUrl + "/Base/gettext/gettext-0.18.3.1-1/gettext-0.18.3.1-1-mingw32-dll.tar.lzma",
rem     mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-bin.tar.lzma",
rem     mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-dev.tar.lzma",
rem     mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-dll.tar.lzma",
rem     // Require C++
rem     //mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-bin.tar.lzma",
rem     //mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-dev.tar.lzma",
rem     //mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-dll.tar.lzma",
rem     mingwBaseUrl + "/Extension/make/make-3.82-mingw32/make-3.82-5-mingw32-bin.tar.lzma",
rem     mingwBaseUrl + "/Extension/gdb/gdb-7.6.1-1/gdb-7.6.1-1-mingw32-bin.tar.lzma",
rem     "https://cmake.org/files/v3.12/cmake-3.12.3-win32-x86.zip",
rem     "https://github.com/ninja-build/ninja/releases/download/v1.9.0/ninja-win.zip"

curl -L -O https://github.com/kekyo/IL2C/releases/download/IL2C-toolchain-gcc4-mingw32-2/IL2C-toolchain-gcc4-mingw32-2.exe
if errorlevel 1 (
    exit /b %errorlevel%
)

rem It zipped by 7z sfx.
IL2C-toolchain-gcc4-mingw32-2.exe
if errorlevel 1 (
    exit /b %errorlevel%
)

del /q IL2C-toolchain-gcc4-mingw32-2.exe
if errorlevel 1 (
    exit /b %errorlevel%
)

rem ========================================================

cd ..
