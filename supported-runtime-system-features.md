# Supported runtime system features


Feature | Test | Descrition
|:---|:---|:---|
| EnumTypes | [Test [18]](tests/IL2C.Core.Test.Target/RuntimeSystems/EnumTypes) | The enum types have the underlying primitive integer types. These tests are verified the IL2C can manage enum underlying types at the boxing-unboxing conversion with narrowing-widing combinations. |
| DelegateTypes | [Test [13]](tests/IL2C.Core.Test.Target/RuntimeSystems/DelegateTypes) | The delegate types contain special member fields, the objref instance reference and the raw method pointer. These tests are verified the IL2C can invoke delegate types combination features between static, instance, virtual method and multicasting at the runtime. |
| ArrayTypes | [Test [43]](tests/IL2C.Core.Test.Target/RuntimeSystems/ArrayTypes) | Array type generates on the runtime. Example: System.Int32[] isn't declared anything assembly. These tests are verified the IL2C can handle runtime array types and initialize array items from resources. |
| ExceptionHandling | [Test [31]](tests/IL2C.Core.Test.Target/RuntimeSystems/ExceptionHandling) | These tests are verified the IL2C translates with simple and/or complext exception handling. |
| ExceptionThrownByCLI | [Test [31]](tests/IL2C.Core.Test.Target/RuntimeSystems/ExceptionThrownByCLI) | These tests are verified the IL2C throw some exceptions from the internal runtimes by ECMA-335 I.12.4.2.1. |
