#ifndef __System_UInt32_H__
#define __System_UInt32_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UInt32

typedef uint32_t System_UInt32;

typedef __System_ValueType_VTABLE_DECL__ __System_UInt32_VTABLE_DECL__;

extern __System_UInt32_VTABLE_DECL__ __System_UInt32_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_UInt32_RUNTIME_TYPE__;

extern System_String* System_UInt32_ToString(uint32_t* this__);
extern int32_t System_UInt32_GetHashCode(uint32_t* this__);
extern bool System_UInt32_Equals(uint32_t* this__, uint32_t obj);
extern bool System_UInt32_Equals_1(uint32_t* this__, System_Object* obj);
extern bool System_UInt32_TryParse(System_String* s, uint32_t* result);

#ifdef __cplusplus
}
#endif

#endif
