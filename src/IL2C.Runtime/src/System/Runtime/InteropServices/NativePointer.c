#include "il2c_private.h"
#include <System/Runtime/InteropServices/NativePointer.h>

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_BEGIN(
    System_Runtime_InteropServices_NativePointer,
    "System.Runtime.InteropServices.NativePointer",
    IL2C_TYPE_VALUE,
    sizeof(System_Runtime_InteropServices_NativePointer),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
