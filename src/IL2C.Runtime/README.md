```c
////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////
```

# What's this?

This is part of IL2C runtime distribution file.
You'll require these items when make manually building process with IL2C translated code.

For more informations, refer [Getting started IL2C.](https://github.com/kekyo/IL2C/blob/master/docs/getting-started.md)

You can build easier to choice another distribution for these situations:

## Translation step

* Translate by IL2C for C# and F# project (csproj/fsproj)
  * You can use NuGet package named `IL2C.Build`, it'll automatically translate to C source code.
  * All translation steps have to use it.

## Linking step

* Target for combination between Windows/UEFI and 32/64bit using Visual C++ 2022
  * You can use NuGet package named `IL2C.Runtime.msvc`.
  * It'll make automatic configuration for VC environments.
* Target for Windows 32bit using MinGW/MSYS gcc4
  * (WIP)
  * Currently IL2C is used self packed MinGW gcc4 toolchain: [you can get binary packed files from here.](https://github.com/kekyo/IL2C/releases/tag/IL2C-toolchain-gcc4-mingw32-2)
* Target for Arduino (tested only M5Stack platform)
  * (WIP)

# Contains

## Using runtimes

* All IL2C Runtime header files (include/*)
  * These files are IL2C runtime header files.
  * It requires at compiling and linking time when translated C source files by IL2C.
* All IL2C Runtime library binary distribution files (lib/*)
  * These files are official IL2C runtime prebuilt binary files. These files are only static library forms (NOT contains dynamic link libraries, because performance issues.)
  * `libil2c-gcc4-win-mingw32.a`: MinGW x86 32bit library
  * `libil2c-msvc-win-*.lib`: Visual C++ libraries. Contains different configurations:
    * Debug/Release: Prebuilt configuration for IL2C runtime. Debug: Enable debug heap and contains many assetion. Release: Fastest and Smallest for standard usages.
    * Win32/x64: 32bit/64bit binary
    * rts/rtd: VC++ runtime library type: static or dynamic (DLL)
  * If you have to check up for these files configurations at the building time, please refer CMake scripts.

## Building runtimes

These files will make helpful if you have to build runtime manually:

* All IL2C Runtime source code (src/*)
  * These files are IL2C runtime core written by C language.
  * It requires only ports for your own platform.
  * For important to use, you have to set compiler include directories both `src/` and `include/`.
* All IL2C Runtime CMake build scripts (cmake/*, CMakefile.txt)
  * These items contain to make stable configurations, it always uses at CI processes.
