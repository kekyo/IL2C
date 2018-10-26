#ifndef __System_Int16_H__
#define __System_Int16_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Int16

typedef int16_t System_Int16;

typedef __System_ValueType_VTABLE_DECL__ __System_Int16_VTABLE_DECL__;

extern __System_Int16_VTABLE_DECL__ __System_Int16_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Int16_RUNTIME_TYPE__;

extern System_String* System_Int16_ToString(int16_t* this__);
extern int32_t System_Int16_GetHashCode(int16_t* this__);
extern bool System_Int16_Equals(int16_t* this__, int16_t obj);
extern bool System_Int16_Equals_1(int16_t* this__, System_Object* obj);
extern bool System_Int16_TryParse(System_String* s, int16_t* result);

#ifdef __cplusplus
}
#endif

#endif
