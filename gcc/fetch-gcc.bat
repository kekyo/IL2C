@echo off

rmdir /s/q fetch bin mingw32 lib include

mkdir fetch

rem MinGW manually download guide: http://www.mingw.org/wiki/howto_install_the_mingw_gcc_compiler_suite

rem curl --output fetch\basic-bsdtar-2.8.3-1-mingw32-bin.zip https://jaist.dl.sourceforge.net/project/mingw/MinGW/Extension/bsdtar/basic-bsdtar-2.8.3-1/basic-bsdtar-2.8.3-1-mingw32-bin.zip
curl --output fetch\binutils-2.28-1-mingw32-bin.tar.xz https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/binutils/binutils-2.28/binutils-2.28-1-mingw32-bin.tar.xz
curl --output fetch\mingwrt-3.20-2-mingw32-dev.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/mingwrt/mingwrt-3.20/mingwrt-3.20-2-mingw32-dev.tar.lzma
curl --output fetch\mingwrt-3.20-2-mingw32-dll.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/mingwrt/mingwrt-3.20/mingwrt-3.20-2-mingw32-dll.tar.lzma
curl --output fetch\w32api-3.17-2-mingw32-dev.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/w32api/w32api-3.17/w32api-3.17-2-mingw32-dev.tar.lzma
curl --output fetch\mpc-1.0.1-2-mingw32-dll.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/mpc/mpc-1.0.1-2/mpc-1.0.1-2-mingw32-dll.tar.lzma
curl --output fetch\mpfr-3.1.2-2-mingw32-dll.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/mpfr/mpfr-3.1.2-2/mpfr-3.1.2-2-mingw32-dll.tar.lzma
curl --output fetch\gmp-5.1.2-1-mingw32-dll.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gmp/gmp-5.1.2/gmp-5.1.2-1-mingw32-dll.tar.lzma
curl --output fetch\libiconv-1.14-3-mingw32-dll.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/libiconv/libiconv-1.14-3/libiconv-1.14-3-mingw32-dll.tar.lzma
curl --output fetch\pthreads-w32-2.9.1-1-mingw32-dev.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/pthreads-w32/pthreads-w32-2.9.1/pthreads-w32-2.9.1-1-mingw32-dev.tar.lzma
curl --output fetch\pthreads-w32-2.9.1-1-mingw32-dll.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/pthreads-w32/pthreads-w32-2.9.1/pthreads-w32-2.9.1-1-mingw32-dll.tar.lzma
curl --output fetch\zlib-1.2.8-1-mingw32-dll.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/zlib/zlib-1.2.8/zlib-1.2.8-1-mingw32-dll.tar.lzma
curl --output fetch\gettext-0.18.3.1-1-mingw32-dll.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gettext/gettext-0.18.3.1-1/gettext-0.18.3.1-1-mingw32-dll.tar.lzma
curl --output fetch\gcc-core-4.8.1-4-mingw32-bin.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-bin.tar.lzma
curl --output fetch\gcc-core-4.8.1-4-mingw32-dev.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-dev.tar.lzma
curl --output fetch\gcc-core-4.8.1-4-mingw32-dll.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-dll.tar.lzma

curl --output fetch\gcc-cpp-4.8.1-4-mingw32-bin.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-bin.tar.lzma
curl --output fetch\gcc-cpp-4.8.1-4-mingw32-dev.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-dev.tar.lzma
curl --output fetch\gcc-cpp-4.8.1-4-mingw32-dll.tar.lzma https://jaist.dl.sourceforge.net/project/mingw/MinGW/Base/gcc/Version4/gcc-4.8.1-4/gcc-c++-4.8.1-4-mingw32-dll.tar.lzma

tar -j -xf fetch\binutils-2.28-1-mingw32-bin.tar.xz
tar --lzma -xf fetch\mingwrt-3.20-2-mingw32-dll.tar.lzma
tar --lzma -xf fetch\mingwrt-3.20-2-mingw32-dev.tar.lzma
tar --lzma -xf fetch\w32api-3.17-2-mingw32-dev.tar.lzma
tar --lzma -xf fetch\mpc-1.0.1-2-mingw32-dll.tar.lzma
tar --lzma -xf fetch\mpfr-3.1.2-2-mingw32-dll.tar.lzma
tar --lzma -xf fetch\gmp-5.1.2-1-mingw32-dll.tar.lzma
tar --lzma -xf fetch\libiconv-1.14-3-mingw32-dll.tar.lzma
tar --lzma -xf fetch\pthreads-w32-2.9.1-1-mingw32-dev.tar.lzma
tar --lzma -xf fetch\pthreads-w32-2.9.1-1-mingw32-dll.tar.lzma
tar --lzma -xf fetch\zlib-1.2.8-1-mingw32-dll.tar.lzma
tar --lzma -xf fetch\gettext-0.18.3.1-1-mingw32-dll.tar.lzma
tar --lzma -xf fetch\gcc-core-4.8.1-4-mingw32-bin.tar.lzma
tar --lzma -xf fetch\gcc-core-4.8.1-4-mingw32-dev.tar.lzma
tar --lzma -xf fetch\gcc-core-4.8.1-4-mingw32-dll.tar.lzma

tar --lzma -xf fetch\gcc-cpp-4.8.1-4-mingw32-bin.tar.lzma
tar --lzma -xf fetch\gcc-cpp-4.8.1-4-mingw32-dev.tar.lzma
tar --lzma -xf fetch\gcc-cpp-4.8.1-4-mingw32-dll.tar.lzma

rmdir /s/q fetch

cd bin
cc -o ../test.exe ../test.c
cd ..
.\test.exe
del test.exe
