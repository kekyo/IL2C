@echo off
setlocal enabledelayedexpansion
set PATH=..\..\..\..\..\..\..\..\..\toolchain\gcc4\bin;%PATH%
if exist out (
    ren out out.tmp
    rmdir /s /q out.tmp
)
mkdir out
gcc.exe -I ..\..\..\..\..\..\..\..\IL2C.Runtime\include -I . {optimizeFlag} -g2 -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--enable-stdcall-fixup -Wl,--add-stdcall-alias -o out\test.exe test.c ..\..\..\..\..\..\..\..\IL2C.Runtime\lib\{configuration}\libil2c-gcc4-win-mingw32.a 
