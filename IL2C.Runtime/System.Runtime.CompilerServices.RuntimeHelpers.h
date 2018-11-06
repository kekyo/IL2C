#ifndef __System_Runtime_CompilerServices_RuntimeHelpers_H__
#define __System_Runtime_CompilerServices_RuntimeHelpers_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Runtime.CompilerServices.RuntimeHelpers

extern IL2C_RUNTIME_TYPE_DECL __System_Runtime_CompilerServices_RuntimeHelpers_RUNTIME_TYPE__;

extern /* static */ int32_t System_Runtime_CompilerServices_RuntimeHelpers_GetHashCode(
    System_Object* o);
extern /* static */ void System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray(
    System_Array* array, System_RuntimeFieldHandle fldHandle);

#ifdef __cplusplus
}
#endif

#endif
