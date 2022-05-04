@echo off

curl -L -O https://github.com/kekyo/IL2C/releases/download/IL2C-toolchain-gcc4-mingw32-4/IL2C-toolchain-gcc4-mingw32-4-base.exe
if errorlevel 1 (
    exit /b %errorlevel%
)

IL2C-toolchain-gcc4-mingw32-4-base.exe

del IL2C-toolchain-gcc4-mingw32-4-base.exe
