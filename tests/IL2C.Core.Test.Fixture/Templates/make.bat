@echo off
setlocal enabledelayedexpansion
set PATH={gccBinPath};%PATH%
if exist out (
    ren out out.tmp
    rmdir /s /q out.tmp
)
mkdir out
set outpaths=
for /r %%c in (*.c) do (
    rem echo Compile: %%~nc.c
    gcc.exe -I {includePath} -I . -save-temps=obj {optimizeFlag} -g -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--enable-stdcall-fixup -Wl,--add-stdcall-alias -o out\%%~nc.o -c %%c
    if !errorlevel! neq 0 exit /b
    set outpaths=!outpaths! out/%%~nc.o
)
gcc.exe -I {includePath} -I . -save-temps=obj {optimizeFlag} -g -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--enable-stdcall-fixup -Wl,--add-stdcall-alias -o out\test.exe !outpaths! {libPath}\libil2c.a 
if %errorlevel% neq 0 exit /b
{disableObjDump}if exist out\test.exe ( objdump.exe -d out\test.exe > out\test.dmp )
