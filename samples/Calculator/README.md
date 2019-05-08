# Polish notation calculator project for IL2C proof of concept

## What's this?

* These are sample code for IL2C.

## The core

* "Calculator.Core" is a proof of concept for polish-notation based calculator code library written by C#.
* It's very neutral implementation, not included any platform dependent code.
* Target platform is .NET Standard 2.0, but IL2C can't understand external libraries currently :)

## The rule for unit tests

* "Calculator.Core" already independent. So we can test this library with standard .NET test technics.
* The "Calculator.Core.Tests" project contains same test code using for NUnit library.

## Platform implementations

* IL2C translated to C language code and stored to "$(SolutionDir)Generated" directory.

### Windows

* "Calculator.Win32" can execute directly on Windows.
* It contains platform-dependent glue functions at the bootstrap main function.

![Calculator.Win32](../../images/Calculator.Win32.png)

### CMake (MinGW32)

* This is sample structure for building with CMake.
* Ready to build using CMake if you already build "Calculator.Core" and stored translated code into "Generated" directory.
* "Generated/CMakeLists.txt" is CMake script and you can build using "build.bat".

### UEFI

* "Calculator.UEFI" can execute directly on UEFI platform.
  * Exactly, this code absolutely contains non-OSes, can boot up from USB flash memory :)
* It contains platform-dependent glue functions at the bootstrap main function.
  * ConIn, ConOut, OutputString, WaitForEvent, WaitForKey, ReadKeyStroke.

![Calculator.UEFI](../../images/Calculator.UEFI.jpg)

### M5Stack

* "Calculator.M5Stack" can execute directly on [M5Stack with calculator FACES module.](http://m5stack.com/)
  * Exactly, this code absolutely contains non-OSes, it's firmware-level programming :)
* It contains platform-dependent glue functions at the bootstrap main function.
  * Bypass from-to display module (ILI9341) on SPI and Calculator-FACES keyboard (custom AVR) on I2C.
  * M5_Terminal, i2c_keyboard_read

![Calculator.M5Stack](../../images/Calculator.M5Stack.jpg)

### WDM

// TODO:
