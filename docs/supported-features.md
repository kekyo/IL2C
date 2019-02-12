# Supported features

* Following lists are manually maintained (and occasionally old a little...)

## Support basic types

| Issue | Status | Milestone
|:---|:---|:---|
| Value types | Supported | M3
| Class types | Supported |
| Managed reference | Supported | M3
| Unmanaged pointer |
| Enum types | Supported |
| Delegate types | Supported |
| Interface types | Supported |
| Nested types | Supported |
| Class inherits | Supported |
| Interface implements | Supported |
| Array types | Supported |
| Multi dimensional array types |
| Closed generic types |
| Open generic types | (not support) | -

## Support type members

| Issue | Status | Milestone
|:---|:---|:---|
| Static field | Supported | M3
| Instance field | Supported | M3
| Static method | Supported | M3
| Instance method | Supported | M3
| Virtual method (class) | Supported |
| Virtual method (interface) | Supported |
| Constructor | Supported |
| Constructor (ValueType) | Supported | M3
| Type initializer | Supported |
| Static property | Supported |
| Instance property | Supported |
| Static event | Supported |
| Instance event | Supported |

## Support metadata handling

| Issue | Status | Milestone
|:---|:---|:---|
| Value type scopes | Supported | M3
| Class type scopes | Supported |
| Enum type scopes | Supported |
| Delegate type scopes | Supported |
| Interface type scopes | Supported |
| Nested type scopes | Supported |
| Field scopes | Supported | M3
| Method scopes | Supported | M3
| Property scopes | Supported |
| Event scopes | Supported |
| Can handle reflection | (not support) | -

## Support runtime relates

| Issue | Status | Milestone
|:---|:---|:---|
| Referenced instance handler | Supported | 
| Value type boxed instance handler | Supported |
| Collect unused instance (GC) | Supported |
| Heap compaction (GC) |
| Exception throw and handles | Partial supported |
| Async exception throws | Partial supported |
| Monitor lock features |
| Interop (P/Invoke) | Partial supported |
| Interop (IL2C/Invoke) | Partial supported |
| Can handle unsafe pointers |
| Can handle marshaling features (Marshal) | Partial supported |

## Application lifecycle managements

| Issue | Status | Milestone
|:---|:---|:---|
| Basic commandline driver | Supported | M2
| MSBuild (old/Task handler) | Partial supported |
| MSBuild (new) | Supported |
| MSBuild (.NET Core CLI) |
| Platform independent core library |
| Translator platform on .NET 4.5 | Supported | M1
| Translator platform on .NET Core 1 | (not support) | -
| Translator platform on .NET Core 2 | Supported |
| Translator platform on mono |
| Support C99 compilers | Supported | M1
| Support non C99 (ANSI) compilers | Supported |
| Support better C code output via C++ symbol declarations |
| Support continuous integrations | Partial supported |
