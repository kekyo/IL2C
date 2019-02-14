# Inside IL2C

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

Implementation: [IL2C.Utilities.GetCLanguageTypeName()](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Core/Utilities.cs#L60)

## String type

// TODO: details

The System.String gonna never change string body.
So, IL2C will place string body in the rdata section with "IL2C_CONST_STRING()" macro.

The macro marks the constant flag into the header. The GC will ignore constant string instances.
But will track if make string instance at the runtime (dynamic generate with string constructors).

Dynamic generate: [il2c_new_string(pString)](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/String.h#L49)

Macro: [IL2C_CONST_STRING(symbol, str)](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/String.h#L70)

## Array type

// TODO: details

Pseudo macro: [il2c_arraytype(elementTypeName)](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/Array.h#L41)

## Delegate type

// TODO: details

The delegates are complex implementation at the .NET Framework/.NET Core.
So IL2C is simply combined structure.

Multicast delegate type is same as single cast delegate: [System_MulticastDelegate](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/MulticastDelegate.h#L17)

Type definition: [System_Delegate](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/Delegate.h#L27)

Macro: [il2c_new_delegate(typeName, object, method)](https://github.com/kekyo/IL2C/blob/dbf94e22c6ca4e523f60cd10052defbdd8eeb51c/IL2C.Runtime/include/System/Delegate.h#L49)

## Enum type

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
