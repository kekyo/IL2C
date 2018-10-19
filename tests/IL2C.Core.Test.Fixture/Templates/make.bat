@echo off
setlocal
set PATH={gccBinPath};%PATH%
rmdir /s /q obj
mkdir obj
gcc.exe -I D:\PROJECT\IL2C\IL2C.Runtime -save-temps=obj -O0 -g -fdata-sections -ffunction-sections -Wl,--gc-sections -o obj\test.exe test.c
