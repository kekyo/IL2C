#ifndef __System_Char_H__
#define __System_Char_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Char

typedef wchar_t System_Char;

typedef __System_ValueType_VTABLE_DECL__ __System_Char_VTABLE_DECL__;

extern __System_Char_VTABLE_DECL__ __System_Char_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Char_RUNTIME_TYPE__;

#define __System_Char_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER

extern /* virtual */ System_String* System_Char_ToString(wchar_t* this__);
extern /* virtual */ int32_t System_Char_GetHashCode(wchar_t* this__);
extern bool System_Char_Equals(wchar_t* this__, wchar_t obj);
extern /* virtual */ bool System_Char_Equals_1(wchar_t* this__, System_Object* obj);
extern bool System_Char_TryParse(System_String* s, wchar_t* result);

#ifdef __cplusplus
}
#endif

#endif
