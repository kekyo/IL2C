#ifndef __System_UInt64_H__
#define __System_UInt64_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UInt64

typedef uint64_t System_UInt64;

typedef __System_ValueType_VTABLE_DECL__ __System_UInt64_VTABLE_DECL__;

extern __System_UInt64_VTABLE_DECL__ __System_UInt64_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_UInt64_RUNTIME_TYPE__;

extern System_String* System_UInt64_ToString(uint64_t* this__);
extern int32_t System_UInt64_GetHashCode(uint64_t* this__);
extern bool System_UInt64_Equals(uint64_t* this__, uint64_t obj);
extern bool System_UInt64_Equals_1(uint64_t* this__, System_Object* obj);
extern bool System_UInt64_TryParse(System_String* s, uint64_t* result);

#ifdef __cplusplus
}
#endif

#endif
