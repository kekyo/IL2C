# Actual proof code of P/Invoke on IL2C

## What's this?

* These code are very preliminary translated code for Seeed WioLTE (JP) arduino environments.
* There're actual proof of P/Invoke combined relations between .NET and C++ code.
  * il2c runtime and translated source code are annotated by "cpp" extension because the arduino environment partially supported C++ (not C).

## How to load and run

TODO: Currently, I broke my WioLTE :( so can't check these code...

1. Before you have to setup and test WioLTE environments: https://github.com/SeeedJP/WioLTEforArduino/wiki/Setup-ja
2. Store il2c directory to arduino's user directory (usually $HOME/Documents/Arduino/libraries/)
3. Run Arduino IDE
4. Invoke menu: Sketch --> Include Library --> Manage libraries. It loads il2c directory into Arduino IDE.
5. Load main.ino and run then grow up LED for rainbow color.
