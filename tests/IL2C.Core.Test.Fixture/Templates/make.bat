@echo off
setlocal
set PATH={gccBinPath};%PATH%
rmdir /s /q out
mkdir out
gcc.exe -I D:\PROJECT\IL2C\IL2C.Runtime -save-temps=obj {optimizeFlag} -g -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--enable-stdcall-fixup -o out\test.exe test.c
objdump.exe -d out\test.exe > out\test.dmp
