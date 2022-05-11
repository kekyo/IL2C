@echo off

rem ========================================================
rem Download preconfigured gcc4 toolchain from GitHub.
rem It contains:
rem -----------------
rem bsdTarUrl = mingwBaseUrl + "/Extension/bsdtar/basic-bsdtar-2.8.3-1/basic-bsdtar-2.8.3-1-mingw32-bin.zip";
rem mingwBaseUrl = "https://jaist.dl.sourceforge.net/project/mingw/MinGW";
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
rem builderRequirementUrls =
rem     "https://cmake.org/files/v3.23/cmake-3.23.1-windows-i386.zip",
rem     "https://github.com/ninja-build/ninja/releases/download/v1.9.0/ninja-win.zip"

cd ..\toolchain

curl -L -O https://github.com/kekyo/IL2C/releases/download/IL2C-toolchain-gcc4-mingw32-3/7z-19.00.exe
if errorlevel 1 (
    exit /b %errorlevel%
)

7z-19.00.exe
if errorlevel 1 (
    exit /b %errorlevel%
)

del /q 7z-19.00.exe
if errorlevel 1 (
    exit /b %errorlevel%
)

7z\7za.exe a -mx9 -sfx ..\artifacts\IL2C-toolchain-gcc4-mingw32-4.exe gcc4

rem ========================================================

cd ..\misc
