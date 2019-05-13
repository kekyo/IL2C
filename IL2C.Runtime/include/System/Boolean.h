#ifndef System_Boolean_H__
#define System_Boolean_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Boolean

typedef bool System_Boolean;

typedef System_ValueType_VTABLE_DECL__ System_Boolean_VTABLE_DECL__;

extern System_Boolean_VTABLE_DECL__ System_Boolean_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Boolean);

extern /* virtual */ System_String* System_Boolean_ToString(bool* this__);
extern /* virtual */ int32_t System_Boolean_GetHashCode(bool* this__);
extern bool System_Boolean_Equals__System_Boolean(bool* this__, bool obj);
extern /* virtual */ bool System_Boolean_Equals__System_Object(bool* this__, System_Object* obj);
extern /* static */ bool System_Boolean_TryParse__System_String_System_Boolean_REF(System_String* s, bool* result);

#ifdef __cplusplus
}
#endif

#endif
