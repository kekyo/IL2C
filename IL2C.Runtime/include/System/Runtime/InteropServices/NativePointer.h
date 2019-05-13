#ifndef System_Runtime_InteropServices_NativePointer_H__
#define System_Runtime_InteropServices_NativePointer_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Runtime.InteropServices.NativePointer

typedef void* System_Runtime_InteropServices_NativePointer;

typedef System_IntPtr_VTABLE_DECL__ System_Runtime_InteropServices_NativePointer_VTABLE_DECL__;

#define System_Runtime_InteropServices_NativePointer_VTABLE__ System_IntPtr_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_Runtime_InteropServices_NativePointer);

#define System_Runtime_InteropServices_NativePointer_op_Implicit__System_IntPtr(value) ((System_Runtime_InteropServices_NativePointer)(value))
#define System_Runtime_InteropServices_NativePointer_op_Implicit__System_Runtime_InteropServices_NativePointer(value) ((intptr_t)(value))

#ifdef __cplusplus
}
#endif

#endif
