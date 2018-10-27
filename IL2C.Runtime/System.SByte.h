#ifndef __System_SByte_H__
#define __System_SByte_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.SByte

typedef int8_t System_SByte;

typedef __System_ValueType_VTABLE_DECL__ __System_SByte_VTABLE_DECL__;

extern __System_SByte_VTABLE_DECL__ __System_SByte_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_SByte_RUNTIME_TYPE__;

extern /* virtual */ System_String* System_SByte_ToString(int8_t* this__);
extern /* virtual */ int32_t System_SByte_GetHashCode(int8_t* this__);
extern bool System_SByte_Equals(int8_t* this__, int8_t obj);
extern /* virtual */ bool System_SByte_Equals_1(int8_t* this__, System_Object* obj);
extern bool System_SByte_TryParse(System_String* s, int8_t* result);

#ifdef __cplusplus
}
#endif

#endif
