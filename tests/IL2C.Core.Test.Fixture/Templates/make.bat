@echo off
setlocal
set PATH={gccBinPath};%PATH%
rmdir /s /q out
mkdir out
gcc.exe -I D:\PROJECT\IL2C\IL2C.Runtime -save-temps=obj -Wall -O0 -g -fdata-sections -ffunction-sections -Wl,--gc-sections -o out\test.exe test.c
