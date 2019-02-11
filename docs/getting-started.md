
# Getting started using the IL2C

## How works the IL2C

* (Tell the IL2C structures)
  * Overview and build pipelines.

## Step by step for first trying

* (Hello world for Win32 native)

1. Construct the C# "net46" library project using Visual Studio 2017.
  * (Re-validate can use the "netstandard20" environment - see the Calculator.Core)
  * Add IL2C.Build reference.
2. Write the hello world.

```csharp
using System;

public static class HelloWorld
{
    public static void Main()
    {
        Console.WriteLine("Hello world with IL2C!");
    }
}
```

3. Build and translate
  * (REQ if doing: optionally automation step, if using GccDriver in IL2C.Tasks)

4. (If doesn't use the GccDriver) Build with the native compiler
  * Construct VC2017 project and setting up properties.

5. Execute and see result.

## Trying sample for the polish notation calculator

* Run the Win32 native Calculator sample

* (can write C# code with the OOP technics)
* (Step by step? or refer the samples/Calculator?)
  * (if choices step by step, maybe setting up is complex)
  * (if can use the GccDriver, write from scratch)

## You can witness working the C# code at non-OSes environment

* Run the UEFI native Calculator sample
