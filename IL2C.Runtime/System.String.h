#ifndef __System_String_H__
#define __System_String_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.String

typedef struct System_String System_String;

typedef __System_Object_VTABLE_DECL__ __System_String_VTABLE_DECL__;

struct System_String
{
    // Instance's vptr
    __System_String_VTABLE_DECL__* vptr0__;

    const wchar_t* string_body__;
};

extern IL2C_RUNTIME_TYPE_DECL __System_String_RUNTIME_TYPE__;
extern __System_String_VTABLE_DECL__ __System_String_VTABLE__;

#define __System_String_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER

extern /* virtual */ System_String* System_String_ToString(System_String* this__);
extern bool System_String_Equals(System_String* this__, System_String* obj);
extern /* virtual */ bool System_String_Equals_1(System_String* this__, System_Object* obj);
extern /* virtual */ int32_t System_String_GetHashCode(System_String* this__);
extern /* static */ System_String* System_String_Concat_3(System_String* str0, System_String* str1);
extern /* static */ System_String* System_String_Concat_4(System_Object* arg0, System_Object* arg1);
extern /* static */ System_String* System_String_Concat_5(System_String* str0, System_String* str1, System_String* str2);
extern System_String* System_String_Substring(System_String* this__, int32_t startIndex);
extern System_String* System_String_Substring_1(System_String* this__, int32_t startIndex, int32_t length);
extern wchar_t System_String_get_Chars(System_String* this__, int32_t index);
extern int32_t System_String_get_Length(System_String* this__);
extern /* static */ bool System_String_IsNullOrWhiteSpace(System_String* value);
extern /* static */ bool System_String_op_Equality(System_String* lhs, System_String* rhs);

/////////////////////////////////////////////////
// String special functions

extern System_String* il2c_new_string(const wchar_t* pString);
extern System_String* il2c_new_string_from_utf8(const char* pUtf8String);
extern const wchar_t* il2c_c_str(System_String* str);

typedef const struct
{
    // IL2C_REF_HEADER
    void* pNext;             // Const string will not collect by GC, so this link is always NULL.
    IL2C_RUNTIME_TYPE_DECL* type;  // Const string always fixed runtime type pointer from "__System_String_RUNTIME_TYPE__."
    intptr_t gcMark;         // Const string always marked (GCMARK_CONST:2)

    // Instance's vptr
    __System_String_VTABLE_DECL__* vptr0__;   // Const string always fixed VTable pointer from "__System_String_VTABLE__."

    wchar_t* string_body__;
} IL2C_CONST_STRING_DECL;

#define IL2C_CONST_STRING(name, string_body) \
    static IL2C_CONST_STRING_DECL __##name##_CONST_STRING__ = { \
        NULL, &__System_String_RUNTIME_TYPE__, /* GCMARK_CONST */ 2, &__System_String_VTABLE__, string_body }; \
    static System_String* const name = ((System_String*)&(__##name##_CONST_STRING__.vptr0__))

#ifdef __cplusplus
}
#endif

#endif
