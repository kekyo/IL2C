#ifndef __System_Int32_H__
#define __System_Int32_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Int32

typedef int32_t System_Int32;

typedef __System_ValueType_VTABLE_DECL__ __System_Int32_VTABLE_DECL__;

extern __System_Int32_VTABLE_DECL__ __System_Int32_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Int32_RUNTIME_TYPE__;

#define __System_Int32_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER

extern /* virtual */ System_String* System_Int32_ToString(int32_t* this__);
extern /* virtual */ int32_t System_Int32_GetHashCode(int32_t* this__);
extern bool System_Int32_Equals(int32_t* this__, int32_t obj);
extern /* virtual */ bool System_Int32_Equals_1(int32_t* this__, System_Object* obj);
extern /* static */ bool System_Int32_TryParse(System_String* s, int32_t* result);

#ifdef __cplusplus
}
#endif

#endif
