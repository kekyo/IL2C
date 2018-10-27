#ifndef __System_Boolean_H__
#define __System_Boolean_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Boolean

typedef bool System_Boolean;

typedef __System_ValueType_VTABLE_DECL__ __System_Boolean_VTABLE_DECL__;

extern __System_Boolean_VTABLE_DECL__ __System_Boolean_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Boolean_RUNTIME_TYPE__;

extern /* virtual */ System_String* System_Boolean_ToString(bool* this__);
extern /* virtual */ int32_t System_Boolean_GetHashCode(bool* this__);
extern bool System_Boolean_Equals(bool* this__, bool obj);
extern /* virtual */ bool System_Boolean_Equals_1(bool* this__, System_Object* obj);
extern bool System_Boolean_TryParse(System_String* s, bool* result);

#ifdef __cplusplus
}
#endif

#endif
