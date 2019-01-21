@echo off
setlocal enabledelayedexpansion
set PATH={gccBinPath};%PATH%
if exist out (
    ren out out.tmp
    rmdir /s /q out.tmp
)
mkdir out
for /r {includePath}\..\src %%c in (*.c) do (
    rem echo Compile: %%~nc.c
    gcc.exe -I {includePath}\..\src -I {includePath} -save-temps=obj {optimizeFlag} -g -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--enable-stdcall-fixup -Wl,--add-stdcall-alias -o out\%%~nc.o -c %%c
    if !errorlevel! neq 0 exit /b
)
rem echo Archive: libil2c.a
if exist libil2c.a (
    del /q libil2c.a
)
ar.exe rcs libil2c.a out\*.o
if exist libil2c.a ( objdump.exe -d libil2c.a > libil2c.dmp )
