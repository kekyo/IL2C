#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Runtime.CompilerServices.RuntimeHelpers

int32_t System_Runtime_CompilerServices_RuntimeHelpers_GetHashCode(
    System_Object* o)
{
    return System_Object_GetHashCode(o);
}

void System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray(
    System_Array* array, System_RuntimeFieldHandle fldHandle)
{
    il2c_assert(array != NULL);
    il2c_assert(fldHandle.field__ != NULL);

    uintptr_t arraySize = array->Length * il2c_sizeof__(array->elementType__);
    uintptr_t size = (fldHandle.size__ < arraySize) ? fldHandle.size__ : arraySize;

    il2c_memcpy(&il2c_array_item(array, uint8_t*, 0), fldHandle.field__, size);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_RUNTIME_STATIC_TYPE(
    System_Runtime_CompilerServices_RuntimeHelpers,
    "System.Runtime.CompilerServices.RuntimeHelpers",
    System_Object);
