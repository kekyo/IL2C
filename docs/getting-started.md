
# Getting started the IL2C

## How works the IL2C

The IL2C will translate your C# (or another .NET based) code to the C language source code.
It bites the .NET assembly (*.dll or *.exe) and will produce multiple C language source code files. It illustrates:

![The IL2C building structure](../images/overview.png)

First half stage, we can automate building process with the NuGet package nemed [IL2C.Build](https://www.nuget.org/packages/IL2C.Build).

Then we'll get the translated C language source code files, so we need compile and get the target binary at the second half stage manually.

This document introduces generally usage for the IL2C. Try it!

## 1. Step by step for first trying

We know about better first step, it's the "Hello world."

### 1-1. Create new C# library project with "net46" or "netcoreapp2.0" platform using Visual Studio 2017.

You can choice ether old (.NET Framework style) project or new (.NET Core/Standard style) project. For example, this project named "GettingStartedIL2C".

![.NET Core console app](../images/tutorial11.png)

### 1-2. Add [the IL2C.Build NuGet package](https://www.nuget.org/packages/IL2C.Build) using the "Package Manager Console" or "NuGet package manager dialog."

![The IL2C.Build NuGet package](../images/tutorial12.png)

Shows example csproj file:

```xml
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <OutputType>Exe</OutputType>
    <TargetFramework>netcoreapp2.0</TargetFramework>
  </PropertyGroup>
  <ItemGroup>
    <PackageReference Include="IL2C.Build" Version="0.4.35" />
  </ItemGroup>
</Project>
```

### 1-3. Write code fragment:

```csharp
using System;

namespace GettingStartedIL2C
{
    public static class Program
    {
        public static void Main() =>
            Console.WriteLine("Hello world with IL2C!");
    }
}
```

### 1-4. Build project and run.

![The hello world result on the pure .NET runtime.](../images/tutorial13.png)

You'll see print it inside the console window and you'll definitely say: "Is not that natural? It's running on the pure .NET runtime." Yes it is. But you already have the translated C source code files. Check it up:

```
[The project directory]
|
|   GettingStartedIL2C.csproj
|   Program.cs
\---bin
    \---Debug
        \---netcoreapp2.0
            |   GettingStartedIL2C.deps.json
            |   GettingStartedIL2C.dll           // It's standard .NET executable assembly (we saw results)
            |   GettingStartedIL2C.pdb
            |   GettingStartedIL2C.runtimeconfig.dev.json
            |   GettingStartedIL2C.runtimeconfig.json
            \---IL2C                             // The IL2C translated C language source codes
                +---include
                |   |   GettingStartedIL2C.h
                |   |
                |   \---GettingStartedIL2C
                |       \---GettingStartedIL2C
                |               Program.h
                \---src
                    |   GettingStartedIL2C_internal.c
                    |   GettingStartedIL2C_internal.h
                    |
                    \---GettingStartedIL2C
                        \---GettingStartedIL2C
                                Program.c
```

You can find the "IL2C" subdirectory descendant bin directory. It's default output directory for IL2C. These files are the C source codes and headers, indicate extensions "*.c" or "*.h".

The "src" directory contains translated method body code, and the "include" directory contains public/internal types and methods definitions. We can build native binary both using these files and the IL2C runtime library.

"IL2C.Runtime" directory at the IL2C repository root contains runtime library. This tutorial compiles with Visual C++ (But the IL2C is aiming for targeting multiple platform. You can also choice the gcc.)

### 1-5. Add Visual C++ console application into your solution.

This is the second half stage. For example, this project named "GettingStartedIL2CMain".

![Add the Visual C++ project](../images/tutorial14.png)

(The Visual C++ wizard generates a lot of helper code fragemnts. We can remove it, but I don't it in this tutorial because I'll focus for the IL2C usage.)

Open project file (GettingStartedIL2CMain.vcxproj) and edit directly below (because it's easy way):

1. Add "AdditionalIncludeDirectories" property each descendant ItemDefinitionGroup/ClCompile elements. We have to do it because the VC++ compiler requires referring IL2C runtime header files and translated header files.

```xml
<ItemDefinitionGroup Condition="..."> <!-- each conditions --> 
  <ClCompile>
    <!-- ... -->
    <!-- Added below -->
    <AdditionalIncludeDirectories>$(ProjectDir)../../../IL2C.Runtime/include;$(ProjectDir)../../../IL2C.Runtime/src;$(ProjectDir)../GettingStartedIL2C/bin/$(Configuration)/netcoreapp2.0/IL2C/include;$(ProjectDir)../GettingStartedIL2C/bin/$(Configuration)/netcoreapp2.0/IL2C/src;%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>
  </ClCompile>
  <!-- ... -->
</ItemDefinitionGroup>
```

2. Add referring the IL2C runtime and translated files nearly exist "ClInclude" and "ClCompile" elements:

```xml
<ItemGroup>
  <ClInclude Include="pch.h" />
  <!-- Added below -->
  <ClInclude Include="$(ProjectDir)../../../IL2C.Runtime/include/**/*.h" />
  <ClInclude Include="$(ProjectDir)../../../IL2C.Runtime/src/**/*.h" />
  <ClInclude Include="$(ProjectDir)../GettingStartedIL2C/bin/$(Configuration)/netcoreapp2.0/IL2C/include/**/*.h" />
  <ClInclude Include="$(ProjectDir)../GettingStartedIL2C/bin/$(Configuration)/netcoreapp2.0/IL2C/src/**/*.h" />
</ItemGroup>
<ItemGroup>
  <ClCompile Include="GettingStartedIL2CMain.cpp" />
  <ClCompile Include="pch.cpp">
    <!-- ... -->
  </ClCompile>
  <!-- Added below -->
  <ClCompile Include="$(ProjectDir)../../../IL2C.Runtime/src/**/*.c">
    <PrecompiledHeader>NotUsing</PrecompiledHeader>
  </ClCompile>
  <ClCompile Include="$(ProjectDir)../GettingStartedIL2C/bin/$(Configuration)/netcoreapp2.0/IL2C/src/**/*.c">
    <PrecompiledHeader>NotUsing</PrecompiledHeader>
  </ClCompile>
</ItemGroup>
```

You have to adjust valid paths for your environments. The "PrecompiledHeader" property requires because the translated files target to the "C language" and the feature can use only C++ language.

3. Write (change) C main function body:

```c++
#include "pch.h"
#include <iostream>

// Referrer translated code.
#include <GettingStartedIL2C.h>

int main()
{
    // Initialize the IL2C runtime.
    il2c_initialize();

    // Invoke (translated) the C# code.
    GettingStartedIL2C_Program_Main();

    // Shutdown the IL2C runtime.
    il2c_shutdown();

    return 0;
}
```

### 1-5. Finished Hello world

Run the project and got result (Note: you maybe fail if you forget set the startup project.)

![Finished Hello world](../images/tutorial15.png)

### 1-6. Visual C++ related hints

If your build random failing, it maybe causes the Visual Studio can't calculate project dependencies. You need to set dependance manually at the "Project dependency" dialog.

![Project dependency dialog](../images/tutorial16.png)

![Configuration manager dialog](../images/tutorial17.png)


## 2. Trying sample for the polish notation calculator

* Run the Win32 native Calculator sample

* (can write C# code with the OOP technics)
* (Step by step? or refer the samples/Calculator?)
  * (if choices step by step, maybe setting up is complex)
  * (if can use the GccDriver, write from scratch)

## 3. You can witness working the C# code at non-OSes environment

* Run the UEFI native Calculator sample
