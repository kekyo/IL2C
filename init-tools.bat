@echo off

echo "Setup native binary toolchain (IL2C-toolchain-gcc4-mingw32) ..."

rmdir /s /q toolchain
mkdir toolchain

cd toolchain

curl -L -O https://github.com/kekyo/IL2C/releases/download/IL2C-toolchain-gcc4-mingw32-3/IL2C-toolchain-gcc4-mingw32-3.exe
if errorlevel 1 (
    exit /b %errorlevel%
)

rem It zipped by 7z sfx.
IL2C-toolchain-gcc4-mingw32-3.exe
if errorlevel 1 (
    exit /b %errorlevel%
)

del /q IL2C-toolchain-gcc4-mingw32-3.exe
if errorlevel 1 (
    exit /b %errorlevel%
)

rem ========================================================

cd ..
