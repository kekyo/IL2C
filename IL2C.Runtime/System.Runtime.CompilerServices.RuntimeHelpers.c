#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Runtime.CompilerServices.RuntimeHelpers

void System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray(
    System_Array* array, System_RuntimeFieldHandle fldHandle)
{
    il2c_assert(array != NULL);
    il2c_assert(fldHandle != NULL);

    // TODO: The field handle can't verify, we have to check it size.
    il2c_memcpy(array->Item, fldHandle, array->Length * il2c_sizeof__(array->elementType__));
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_DECLARE_RUNTIME_STATIC_TYPE(
    System_Runtime_CompilerServices_RuntimeHelpers,
    "System.Runtime.CompilerServices.RuntimeHelpers",
    System_Object);
