@echo off
echo "Setup native binary toolchain (IL2C-toolchain-gcc4-mingw32) ..."

rmdir /s /q toolchain
mkdir toolchain

cd toolchain

curl -L -O https://github.com/kekyo/IL2C/releases/download/IL2C-toolchain-gcc4-mingw32/IL2C-toolchain-gcc4-mingw32.exe
IL2C-toolchain-gcc4-mingw32.exe

del /q IL2C-toolchain-gcc4-mingw32.exe

cd ..
