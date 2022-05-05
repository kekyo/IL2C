# What's this?

This is part of [IL2C](https://github.com/kekyo/IL2C) toolchain distribution file.
It contains GNU compiler collection built on MinGW environment.

## License

IL2C is under Apache-v2, but there are under GPL-v2 inside following directories:

* gcc4/

These files come from:

```csharp
mingwBaseUrl = "https://jaist.dl.sourceforge.net/project/mingw/MinGW";
gccRequirementUrls =
    mingwBaseUrl + "/Base/binutils/binutils-2.28/binutils-2.28-1-mingw32-bin.tar.xz",
    mingwBaseUrl + "/Base/mingwrt/mingwrt-3.20/mingwrt-3.20-2-mingw32-dev.tar.lzma",
    mingwBaseUrl + "/Base/mingwrt/mingwrt-3.20/mingwrt-3.20-2-mingw32-dll.tar.lzma",
    mingwBaseUrl + "/Base/w32api/w32api-3.17/w32api-3.17-2-mingw32-dev.tar.lzma",
    mingwBaseUrl + "/Base/mpc/mpc-1.0.1-2/mpc-1.0.1-2-mingw32-dll.tar.lzma",
    mingwBaseUrl + "/Base/mpfr/mpfr-3.1.2-2/mpfr-3.1.2-2-mingw32-dll.tar.lzma",
    mingwBaseUrl + "/Base/gmp/gmp-5.1.2/gmp-5.1.2-1-mingw32-dll.tar.lzma",
    mingwBaseUrl + "/Base/libiconv/libiconv-1.14-3/libiconv-1.14-3-mingw32-dll.tar.lzma",
    mingwBaseUrl + "/Base/pthreads-w32/pthreads-w32-2.9.1/pthreads-w32-2.9.1-1-mingw32-dev.tar.lzma",
    mingwBaseUrl + "/Base/pthreads-w32/pthreads-w32-2.9.1/pthreads-w32-2.9.1-1-mingw32-dll.tar.lzma",
    mingwBaseUrl + "/Base/zlib/zlib-1.2.8/zlib-1.2.8-1-mingw32-dll.tar.lzma",
    mingwBaseUrl + "/Base/gettext/gettext-0.18.3.1-1/gettext-0.18.3.1-1-mingw32-dll.tar.lzma",
    mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-bin.tar.lzma",
    mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-dev.tar.lzma",
    mingwBaseUrl + "/Base/gcc/Version4/gcc-4.8.1-4/gcc-core-4.8.1-4-mingw32-dll.tar.lzma",
    mingwBaseUrl + "/Extension/make/make-3.82-mingw32/make-3.82-5-mingw32-bin.tar.lzma",
    mingwBaseUrl + "/Extension/gdb/gdb-7.6.1-1/gdb-7.6.1-1-mingw32-bin.tar.lzma",
```
