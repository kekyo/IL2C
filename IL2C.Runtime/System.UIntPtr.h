#ifndef __System_UIntPtr_H__
#define __System_UIntPtr_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UIntPtr

typedef uintptr_t System_UIntPtr;

typedef __System_ValueType_VTABLE_DECL__ __System_UIntPtr_VTABLE_DECL__;

extern __System_UIntPtr_VTABLE_DECL__ __System_UIntPtr_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_UIntPtr_RUNTIME_TYPE__;

extern /* virtual */ System_String* System_UIntPtr_ToString(uintptr_t* this__);
extern /* virtual */ int32_t System_UIntPtr_GetHashCode(uintptr_t* this__);
extern bool System_UIntPtr_Equals(uintptr_t* this__, uintptr_t obj);
extern /* virtual */ bool System_UIntPtr_Equals_1(uintptr_t* this__, System_Object* obj);

extern const System_UIntPtr System_UIntPtr_Zero;

#ifdef __cplusplus
}
#endif

#endif
