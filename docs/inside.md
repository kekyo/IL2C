# Inside IL2C

// TODO: Sorry, this document write in progress.

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

The IL2C uses these types sometimes using "Mangled type name." For example: "System.Int32" mangles to "System_Int32".
A variable with simple declaration has an alias name:

```c
void foo()
{
    // Using alias name
    int32_t i32Value;
}
```

But if the IL2C uses into the custom operators:

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

```c
// Const literal string places into read only section.
IL2C_CONST_STRING(string1__, L"Hello world IL2C!");

// ...

// Const literal string is assignable.
System_String* str;
str = string1__;
```

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

The IL2C aggregates from all array types into a single array type named "System.Array". The translated source code defines with the macro [il2c_arraytype(elementTypeName)](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/Array.h#L41).

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
So the IL2C way is simply combined unifying structure:

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

The "System_Delegate" has multiple method target at the "IL2C_METHOD_TABLE". And you will surprise because the IL2C's delegate is variable storage size same as System.String, the field "methodtbl__". If we combine multiple delegates with ["System.Delegate.Combine()"](https://github.com/kekyo/IL2C/blob/216916632f880a73dd5233ad0b5d1fa204ce9fb0/IL2C.Runtime/src/System/Delegate.c#L47) method, combines all delegate target into a single instance.

Multicast delegate type is same as single cast delegate: [System_MulticastDelegate](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/MulticastDelegate.h#L17)

Type definition: [System_Delegate](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/Delegate.h#L27)

Macro: [il2c_new_delegate(typeName, object, method)](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/Delegate.h#L49)

## Enum type

// TODO: details

The C language's enum types cannot declare with storage size likely C#:

```csharp
// The .NET enum type with storage size "byte".
// The C language cannot do it because by language design.
enum Test_Colors : byte
{
    None,
    Red,
    Blue,
    Green
};
```

The C language cannot do it because by language design.

```c
enum Test_Colors /* : byte */  // can't do it
{
    None,   // And these symbols not structured by type names - places at globally
    Red,
    Blue,
    Green
};
```

So, the IL2C defines enum type values with simple way:

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

## Managed references

## Constructor

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

### Except constants

## Exception handling

## Interoperabilities

### P/Invoke

### IL2C/Invoke

## Packaging related features
