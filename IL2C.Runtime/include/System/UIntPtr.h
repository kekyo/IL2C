#ifndef System_UIntPtr_H__
#define System_UIntPtr_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UIntPtr

typedef uintptr_t System_UIntPtr;

typedef System_ValueType_VTABLE_DECL__ System_UIntPtr_VTABLE_DECL__;

extern System_UIntPtr_VTABLE_DECL__ System_UIntPtr_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_UIntPtr);

extern /* virtual */ System_String* System_UIntPtr_ToString(uintptr_t* this__);
extern /* virtual */ int32_t System_UIntPtr_GetHashCode(uintptr_t* this__);
extern bool System_UIntPtr_Equals(uintptr_t* this__, uintptr_t obj);
extern /* virtual */ bool System_UIntPtr_Equals_1(uintptr_t* this__, System_Object* obj);

#define System_UIntPtr_op_Explicit_2(value) ((uintptr_t)(value))
#define System_UIntPtr_op_Explicit_3(value) ((uintptr_t)(value))
#define System_UIntPtr_op_Addition(lhs, rhs) (((uintptr_t)(lhs)) + ((uintptr_t)(rhs)))

extern const System_UIntPtr System_UIntPtr_Zero;

#ifdef __cplusplus
}
#endif

#endif
