#ifndef System_Char_H__
#define System_Char_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Char

typedef wchar_t System_Char;

typedef System_ValueType_VTABLE_DECL__ System_Char_VTABLE_DECL__;

extern System_Char_VTABLE_DECL__ System_Char_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Char);

extern /* virtual */ System_String* System_Char_ToString(wchar_t* this__);
extern /* virtual */ int32_t System_Char_GetHashCode(wchar_t* this__);
extern bool System_Char_Equals__System_Char(wchar_t* this__, wchar_t obj);
extern /* virtual */ bool System_Char_Equals__System_Object(wchar_t* this__, System_Object* obj);
extern /* static */ bool System_Char_TryParse__System_String_System_Char_REF(System_String* s, wchar_t* result);

#ifdef __cplusplus
}
#endif

#endif
