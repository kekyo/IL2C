# Inside IL2C

// TODO: Sorry, this document write in progress.

## Getting started for core hacking

### Summarized lazy steps

* Sorry, currently IL2C developing environment supports on Visual Studio 2017 only. If you installed 2017, you can use side-by-side installed Visual Studio 2019.

1. Run "init-tools.bat", then run "build-runtime.bat". "build-runtime" can take a argument for configuration name both "Debug" and "Release", will implicit apply "Debug" if you don't give it. (The names are important case sensitive.)
2. Open il2c.sln by Visual Studio. Your environment requires enabling C#, VC++ and NUnit3 vsix addin.
3. Build with "Debug - AnyCPU" configuration.
4. If this don't show any errors, kick starts unit tests at the Test Explorer (Run All).
5. The unit tests need a long time for the first execution. It's because these tests automatically download mingw platform and run on it.
6. After all tests passed, you are ready to hack!

### Core implementation note

* Essentially, the unit tests compare and verify results executed on .NET CLR with results executed by the native code gcc compiled.
* You can see ["tests/IL2C.Core.Test.Target project"](https://github.com/kekyo/IL2C/tree/master/tests/IL2C.Core.Test.Target). The translated code:  ["tests/IL2C.Core.Test.Fixture project"](https://github.com/kekyo/IL2C/tree/master/tests/IL2C.Core.Test.Fixture) of subfolder "bin/Debug/net462."
* About the CI engineering, you can get more information: ["azure-pipelines.yml"](azure-pipelines.yml) file.
* Currently IL2C contains the VC++ project file because it's better for debugging mates. You don't need this because "IL2C.Runtime.vcxproj" project file DOESN'T REQUIRE for any building (manually and CI buildings.)
* If you want to see internal IL2C, I think these slides help you: [Making archive IL2C #6-55: dotNET 600 2018 session slide](https://www.slideshare.net/kekyo/making-archive-il2c-655-dotnet600-2018)

## Basis types

// TODO: details

Uses with "stdint.h", "stdbool.h", "float.h" and "wchar.h" headers.

|Full type name|Alias|
|--|--|
|System.Boolean|bool|
|System.Byte|uint8_t|
|System.Int16|int16_t|
|System.Int32|int32_t|
|System.Int64|int64_t|
|System.SByte|int8_t|
|System.UInt16|uint16_t|
|System.UInt32|uint32_t|
|System.UInt64|uint64_t|
|System.IntPtr|intptr_t|
|System.UIntPtr|uintptr_t|
|System.Single|float|
|System.Double|double|
|System.Char|wchar_t|
|System.Void|void|

IL2C uses these types sometimes using "Mangled type name." For example: "System.Int32" mangles to "System_Int32".
A variable with simple declaration has an alias name:

```c
void foo()
{
    // Using alias name
    int32_t i32Value;
}
```

But if IL2C uses into the custom operators:

```c
void foo()
{
    int32_t i32Value;
    System_ValueType* value;

    // It has to apply mangled type name instead alias name.
    value = il2c_box(&i32Value, System_Int32);
}
```

Implementation: [IL2C.Utilities.GetCLanguageTypeName()](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Core/Utilities.cs#L60)

## String type

// TODO: details

The System.String gonna never change string body.
So, IL2C will place string body in the rdata section with "IL2C_CONST_STRING()" macro.

The macro marks the constant flag into the header. The GC will ignore constant string instances.
But will track if make string instance at the runtime (dynamic generate with string constructors).

![String (1)](../images/inside-string.png)

```c
// Const literal string places into read only section.
IL2C_CONST_STRING(string1__, L"Hello world IL2C!");

// ...

// Const literal string is assignable.
System_String* str;
str = string1__;
```

![String (2)](../images/inside-string2.png)

```c
// String instance come from the UTF8 string.
// It places into the heap (will copy string body).
System_String* str;
str = il2c_new_string_from_utf8("Hello world dynamic string!");
```

Macro: [IL2C_CONST_STRING(symbol, str)](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/String.h#L70)

Dynamic generate: [il2c_new_string(pString)](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/String.h#L49)

## Array type

// TODO: details

IL2C aggregates from all array types into a single array type named "System.Array". The translated the pseudo type name with the macro [il2c_arraytype(elementTypeName)](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/Array.h#L41) because readability.

It's pseudo generic implementation, use the macros [il2c_array_item0ptr__(array)](https://github.com/kekyo/IL2C/blob/254390d506b1dec5faa5eb94ce7a893768618905/IL2C.Runtime/include/System/Array.h#L44) and [il2c_array_item(array, elementTypeName, index)](https://github.com/kekyo/IL2C/blob/254390d506b1dec5faa5eb94ce7a893768618905/IL2C.Runtime/include/System/Array.h#L63) can access array elements with tiny overheads.

```c
// The array type variable (int[])
il2c_arraytype(System_Int32)* arr;

// Create array instance (arr = new int[100])
arr = il2c_new_array(System_Int32, 100);
// Access array element (arr[10] = 12345)
il2c_array_item(arr, System_Int32, 10) = 12345;
```

The array instance create with [il2c_new_array(elementTypeName, length)](https://github.com/kekyo/IL2C/blob/254390d506b1dec5faa5eb94ce7a893768618905/IL2C.Runtime/include/System/Array.h#L68).

## Delegate type

// TODO: details

The delegates have too complex implementation at the .NET Framework/.NET Core.
So IL2C way is simply combined unifying structure:

```c
typedef const struct IL2C_METHOD_TABLE_DECL
{
    System_Object* target;
    intptr_t methodPtr;
} IL2C_METHOD_TABLE;

struct System_Delegate
{
    System_Delegate_VTABLE_DECL__* vptr0__;

    uintptr_t count__;
    IL2C_METHOD_TABLE methodtbl__[1];
};
```

The "System_Delegate" has multiple method target with "IL2C_METHOD_TABLE" entries. And you'll surprise because IL2C's delegate is variable storage size same as System.String. Stretches the field "methodtbl__". If we combine multiple delegates with ["System.Delegate.Combine()"](https://github.com/kekyo/IL2C/blob/216916632f880a73dd5233ad0b5d1fa204ce9fb0/IL2C.Runtime/src/System/Delegate.c#L47) method, combines all delegate target into a single instance.

![Delegate](../images/inside-delegate.png)

[System_MulticastDelegate](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/MulticastDelegate.h#L17) type is same as single cast delegate. It means it has always multicast capabilitiy for IL2C solution.

Type definition: [System_Delegate](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/Delegate.h#L27)

Macro: [il2c_new_delegate(typeName, object, method)](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/Delegate.h#L49)

## Enum type

// TODO: details

The C language's enum types cannot declare with storage size likely C#. Because the C language cannot do it because by language design.

```c
// Enum type in the C Language:
enum Test_Colors /* : uint8_t */  // can't do it
{
    None,   // And these symbols not structured by type names - places at globally
    Red,
    Blue,
    Green
};
```

So, IL2C defines enum type values with simple way:

```c
// Storage size
typedef uint8_t Test_Colors;

// Mangled with type name prefix.
static const Test_Colors Test_Colors_None = 0;
static const Test_Colors Test_Colors_Red = 1;
static const Test_Colors Test_Colors_Blue = 2;
static const Test_Colors Test_Colors_Green = 3;
```

[The System.Enum type implementations](https://github.com/kekyo/IL2C/blob/254390d506b1dec5faa5eb94ce7a893768618905/IL2C.Runtime/include/System/Enum.h#L15) only use for the boxed instance.

## Boxing and Unboxing

IL2C can boxing and unboxing operation. If a value type boxed, it gonna [allocate on the heap (malloc)](https://github.com/kekyo/IL2C/blob/3057cc0cd19492ae339fbffc7c699ed2d73ff1a8/IL2C.Runtime/src/il2c.c#L52) with instance header and will copy value body into it.

![Boxing](../images/inside-boxing.png)

Unbox operation will get naturally direct refer pointer. Do dereference pointer if we wanna read a value:

```c
// Boxing
int32_t value = 123;
il2c_boxedtype(System_Int32)* boxedInt32 = il2c_box(&value, System_Int32);

// Unboxing (with dereference)
int32_t unboxedInt32;
unboxedInt32 = *il2c_unbox(boxedInt32, System_Int32);
```

The boxed type is declared to a raw pointer with C language. But it's different to both managed object reference (objref) and managed reference (&). The ["il2c_boxedtype()"](https://github.com/kekyo/IL2C/blob/3057cc0cd19492ae339fbffc7c699ed2d73ff1a8/IL2C.Runtime/include/il2c.h#L237) macro makes pseudo boxed type same as "il2c_arraytype()" macro because readability too. 

And if call the method with real (unboxed) this pointer:

```c
il2c_boxedtype(Test_Foo)* boxedfoo;
boxedFoo = ...;

// Unboxing, but not dereference for will call instance method:
Test_Foo* unboxedFoo = il2c_unbox(boxedFoo, Test_Foo);

// public struct Foo { public void FooMethod(int a, int b); }
// Maybe it requires mutable access on the value type instance method, the "this" pointer can do it.
// (And the virtual and interface implemented method aren't mutable (makes copy).)
Test_Foo_FooMethod(unboxedFoo, 123, 456);
```

TIPS: Do you know that "System.ValueType" is objref? ;) All boxed instance [inherited from System.ValueType](https://github.com/kekyo/IL2C/blob/e2e222f935a8217bcff7da464b0c372ae1b90c65/IL2C.Runtime/src/System/ValueType.c#L59) at [the runtime](https://github.com/kekyo/IL2C/blob/e2e222f935a8217bcff7da464b0c372ae1b90c65/IL2C.Runtime/src/il2c.c#L524).

Type definition: [System.ValueType](https://github.com/kekyo/IL2C/blob/e2e222f935a8217bcff7da464b0c372ae1b90c65/IL2C.Runtime/include/System/ValueType.h#L19).

## Managed references

// TODO: details

A managed reference almost same as a raw pointer.

```c
// void Foo(ref int value)
void Test_Foo(int32_t* value)
{
    // ...
}
```

 The object reference (objref) has pointer form. So it will be double pointer form.

```c
// void Foo(ref string value)
void Test_Foo(System_String** value)
{
    // ...
}
```

The managed reference doesn't track by garbage collector. Because it always refers trackable (linked from another) instance.

## Runtime type information

// TODO: details
// TODO: I'll change the structures in the future.

The IL2C requires runtime type information, structure named ["IL2C_RUNTIME_TYPE_DECL"](https://github.com/kekyo/IL2C/blob/03fe578a5e1aa959a3463a2b6f13491ee0fd042a/IL2C.Runtime/src/il2c_private.h#L53) and refer pointer named ["IL2C_RUNTIME_TYPE"](https://github.com/kekyo/IL2C/blob/03fe578a5e1aa959a3463a2b6f13491ee0fd042a/IL2C.Runtime/include/il2c.h#L87). It's public but the body is opaque.

It contains these fields:

```c
struct IL2C_RUNTIME_TYPE_DECL
{
    const char* pTypeName;
    const uintptr_t flags;
    const uintptr_t bodySize;       // uint32_t
    const IL2C_RUNTIME_TYPE baseType;
    const void* vptr0;
    const uintptr_t markTarget;     // mark target count / custom mark handler
    const uintptr_t interfaceCount;
    //IL2C_MARK_TARGET markTargets[markTarget];
    //IL2C_IMPLEMENTED_INTERFACE interfaces[interfaceCount];
};
```

Toughly you can understand meaning these fields, I'll tell you important fields:

* flags: The field contains [flag values declared here](https://github.com/kekyo/IL2C/blob/e2e222f935a8217bcff7da464b0c372ae1b90c65/IL2C.Runtime/include/il2c.h#L113). It's characteristics for the type. For example, "IL2C_TYPE_REFERENCE" is a object reference (objref) type, "IL2C_TYPE_VARIABLE" is a variable storage type (only array, string, delegate and thread types).

  | Symbol | Description |
  |---|---|
  | IL2C_TYPE_REFERENCE | A objref type. |
  | IL2C_TYPE_VALUE | A value type. |
  | IL2C_TYPE_INTEGER | A integer (numeric but not floating point) type. The boxing operator uses on bothe narrowing and widing storage size. |
  | IL2C_TYPE_VARIABLE | A variable type, only using with array, string, delegate and thread types. |
  | IL2C_TYPE_MARK_HANDLER | The GC traverser using custom mark handler for this type. |
  | IL2C_TYPE_UNSIGNED_INTEGER | A unsigned integer (numeric but not floating point) type. The boxing operator uses on bothe narrowing and widing storage size. |
  | IL2C_TYPE_STATIC | A static type (sealed abstract). It doesn't have the VTables. |
  | IL2C_TYPE_INTERFACE | A interface type. [It has lesser fields than another types](https://github.com/kekyo/IL2C/blob/03fe578a5e1aa959a3463a2b6f13491ee0fd042a/IL2C.Runtime/src/il2c_private.h#L67). |

* vptr0: The primary VTable pointer for the types. The [il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE type)](https://github.com/kekyo/IL2C/blob/03fe578a5e1aa959a3463a2b6f13491ee0fd042a/IL2C.Runtime/src/il2c.c#L119) function setup instance using it.
* markTarget, markTargets: Variable fields and count for garbage collector mark target (below).
* interfaceCount, interfaces: Variable fields and count for implemented interfaces (below).

### The mark targets and implemented interfaces

These are multiple entries by following structures:

```c
typedef const struct IL2C_MARK_TARGET_DECL
{
    const IL2C_RUNTIME_TYPE valueType;
    const uintptr_t offset;
} IL2C_MARK_TARGET;

typedef const struct IL2C_IMPLEMENTED_INTERFACE_DECL
{
    const IL2C_RUNTIME_TYPE type;
    const void* vptr0;
} IL2C_IMPLEMENTED_INTERFACE;
```

[The mark targets "IL2C_MARK_TARGET"](https://github.com/kekyo/IL2C/blob/03fe578a5e1aa959a3463a2b6f13491ee0fd042a/IL2C.Runtime/src/il2c_private.h#L41) append tracking ability for the object references by the garbage collector. It has two way usages (mark target count or custom mark handler pointer).

[The implemented interfaces "IL2C_IMPLEMENTED_INTERFACE"](https://github.com/kekyo/IL2C/blob/03fe578a5e1aa959a3463a2b6f13491ee0fd042a/IL2C.Runtime/src/il2c_private.h#L47) uses for two ways:

* Setup interface VTable pointers into [the allocated instance](https://github.com/kekyo/IL2C/blob/e2e222f935a8217bcff7da464b0c372ae1b90c65/IL2C.Runtime/src/il2c.c#L98).
* [The dynamic cast calculation](https://github.com/kekyo/IL2C/blob/e2e222f935a8217bcff7da464b0c372ae1b90c65/IL2C.Runtime/src/il2c.c#L457) at the runtime.

## Constructor and allocate the object

// TODO: details

The IL2C's allocation strategy for the object reference (objref) type has two steps:

1. Allocate memory on [the heap (malloc)](https://github.com/kekyo/IL2C/blob/3057cc0cd19492ae339fbffc7c699ed2d73ff1a8/IL2C.Runtime/src/il2c.c#L52).
Then initialize [object reference header (IL2C_REF_HEADER)](https://github.com/kekyo/IL2C/blob/03fe578a5e1aa959a3463a2b6f13491ee0fd042a/IL2C.Runtime/include/il2c.h#L100). All objref instance has this header. It's linked list, holds "IL2C_RUNTIME_TYPE" pointer and the "gcmark" field. Initializer sequence [setups the vptr0 and interface vptrs (See below sections)](https://github.com/kekyo/IL2C/blob/03fe578a5e1aa959a3463a2b6f13491ee0fd042a/IL2C.Runtime/src/il2c.c#L131). It does only objref types.
2. Call the constructor (.ctor) method.

```c
// public class Foo {
//   public Foo(int num, string str) { ... }
// }

Test_Foo* foo;
foo = il2c_get_uninitialized_object(Test_Foo);  // returns "pReference"
Test_Foo__ctor(foo, 123, string1__);
```

The objref's memory layout is:

```c
// IL2C_REF_HEADER structure
struct IL2C_REF_HEADER_DECL
{
    IL2C_REF_HEADER* pNext;   // Next instance pointer (all objref instances are linked this field)
    IL2C_RUNTIME_TYPE type;
    interlock_t gcMark;
};
```

```
+----------------------+ <-- pHeader
| IL2C_REF_HEADER      |
+----------------------+ <-- pReference   -------
|          :           |                    ^
| (Instance body)      |                    | bodySize
|          :           |                    v
+----------------------+                  -------
```

"pReference" is real pointer value. "pHeader" isn't public, it'll recalculate from "pReference" at the runtime.

The value types are different for objref's:

1. Clear value with storage size (Using memset() directly).
2. Call the constructor (.ctor) method if available.

```c
// public struct Bar {
//   public Bar(int num, string str) { ... }
// }

Test_Bar bar;
memset(&bar, 0, sizeof bar);
Test_Bar__ctor(&bar, 123, string1__);
```

Of course, the value type storage doesn't include "IL2C_REF_HEADER."

Helper function: [il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE type)](https://github.com/kekyo/IL2C/blob/03fe578a5e1aa959a3463a2b6f13491ee0fd042a/IL2C.Runtime/src/il2c.c#L119)

## Type initializer

## Class type and inheritance

## Interface type and implementations

## Member mangler specification

## Overload/Override resolution

## Virtual function

### Adjustor thunk less VTable

### Devirtualization

## Garbage collector

### Strategies

### Stack walking

### Static instance walking

### Temporary refenrece anchor

### Custom mark handler

### Except constants

## Exception handling

## Threading

### Monitor locking

### Arbitrary thread handling

## Interoperabilities

### P/Invoke

### IL2C/Invoke

## Packaging related features
