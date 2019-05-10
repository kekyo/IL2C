#ifndef System_Runtime_InteropServices_GCHandle_H__
#define System_Runtime_InteropServices_GCHandle_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Runtime.InteropServices.GCHandle

typedef intptr_t System_Runtime_InteropServices_GCHandle;

typedef System_Object_VTABLE_DECL__ System_Runtime_InteropServices_GCHandle_VTABLE_DECL__;

extern System_Runtime_InteropServices_GCHandle_VTABLE_DECL__ System_Runtime_InteropServices_GCHandle_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Runtime_InteropServices_GCHandle);

extern System_Object* System_Runtime_InteropServices_GCHandle_get_Target(System_Runtime_InteropServices_GCHandle* this__);
extern void System_Runtime_InteropServices_GCHandle_set_Target__System_Object(System_Runtime_InteropServices_GCHandle* this__, System_Object* value);
extern void System_Runtime_InteropServices_GCHandle_Free(System_Runtime_InteropServices_GCHandle* this__);
extern intptr_t System_Runtime_InteropServices_GCHandle_AddrOfPinnedObject(System_Runtime_InteropServices_GCHandle* this__);

extern /* static */ System_Runtime_InteropServices_GCHandle System_Runtime_InteropServices_GCHandle_Alloc__System_Object(System_Object* value);
extern /* static */ System_Runtime_InteropServices_GCHandle System_Runtime_InteropServices_GCHandle_Alloc__System_Object_System_Runtime_InteropServices_GCHandleType(System_Object* value, System_Runtime_InteropServices_GCHandleType type);

#define System_Runtime_InteropServices_GCHandle_FromIntPtr__System_IntPtr(value) ((System_Runtime_InteropServices_GCHandle)value)
#define System_Runtime_InteropServices_GCHandle_ToIntPtr__System_Runtime_InteropServices_GCHandle(value) ((intptr_t)value)

extern /* virtual */ int32_t System_Runtime_InteropServices_GCHandle_GetHashCode(System_Runtime_InteropServices_GCHandle* this__);
extern /* virtual */ bool System_Runtime_InteropServices_GCHandle_Equals__System_Object(System_Runtime_InteropServices_GCHandle* this__, System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
