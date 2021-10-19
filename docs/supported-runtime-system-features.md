# Supported runtime system features


Feature | Test | Descrition
|:---|:---|:---|
| ArrayTypes | [Test [43]](../tests/IL2C.Core.Test.RuntimeSystems/ArrayTypes) | Array type generates on the runtime. Example: System.Int32[] isn't declared anything assembly. These tests are verified the IL2C can handle runtime array types and initialize array items from resources. |
| DelegateTypes | [Test [15]](../tests/IL2C.Core.Test.RuntimeSystems/DelegateTypes) | The delegate types contain special member fields, the objref instance reference and the raw method pointer. These tests are verified the IL2C can invoke delegate types combination features between static, instance, virtual method and multicasting at the runtime. |
| EnumTypes | [Test [18]](../tests/IL2C.Core.Test.RuntimeSystems/EnumTypes) | The enum types have the underlying primitive integer types. These tests are verified the IL2C can manage enum underlying types at the boxing-unboxing conversion with narrowing-widing combinations. |
| ExceptionHandling | [Test [31]](../tests/IL2C.Core.Test.RuntimeSystems/ExceptionHandling) | These tests are verified the IL2C translates with simple and/or complext exception handling. |
| ExceptionThrownByCLI | [Test [33]](../tests/IL2C.Core.Test.RuntimeSystems/ExceptionThrownByCLI) | These tests are verified the IL2C throw some exceptions from the internal runtimes by ECMA-335 I.12.4.2.1. |
| GarbageCollection | [Test [22]](../tests/IL2C.Core.Test.RuntimeSystems/GarbageCollection) | These tests are verified the IL2C manages tracing the object references and collect garbages from the heap memory. |
| Interoperability | [Test [5]](../tests/IL2C.Core.Test.RuntimeSystems/Interoperability) | These tests are verified the IL2C manages interoperability with the P/Invoke adn IL2C/Invoke method and internalcall method. |
| Threading | [Test [11]](../tests/IL2C.Core.Test.RuntimeSystems/Threading) | These tests are verified the IL2C can handle threading features. |
| TypeInitializer | [Test [15]](../tests/IL2C.Core.Test.RuntimeSystems/TypeInitializer) | These tests are verified the IL2C can handle the type initializer special translation cases. |
| TypeInitializer_Defaults | [Test [16]](../tests/IL2C.Core.Test.RuntimeSystems/TypeInitializer_Defaults) | These tests are verified the IL2C can handle the type initializer special translation cases. |
| TypeInitializer_Non_Static_Class | [Test [15]](../tests/IL2C.Core.Test.RuntimeSystems/TypeInitializer_Non_Static_Class) | These tests are verified the IL2C can handle the type initializer special translation cases. |
| TypeInitializer_Singleton | [Test [2]](../tests/IL2C.Core.Test.RuntimeSystems/TypeInitializer_Singleton) |  |
| TypeInitializer_Struct | [Test [15]](../tests/IL2C.Core.Test.RuntimeSystems/TypeInitializer_Struct) | These tests are verified the IL2C can handle the type initializer special translation cases. |
| TypeRelations | [Test [95]](../tests/IL2C.Core.Test.RuntimeSystems/TypeRelations) | CLR type system contains single-inheritance class types and multiple-implementation interface types. These tests are verified the IL2C can handle the member methods both simple instance methods and complex overriden virtual methods. |
| ValueTypes | [Test [18]](../tests/IL2C.Core.Test.RuntimeSystems/ValueTypes) | Value types are specialized types at the .NET type system. Because the type inherited from the System.ValueType (objref type), all method has the managed pointer at the arg0 and these instances will box and apply the pseudo vptrs. These tests are verified the IL2C can handle value types. |
