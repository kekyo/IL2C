#ifndef __System_String_H__
#define __System_String_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.String

typedef struct System_Object System_Object;
typedef struct System_String System_String;

typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(System_String* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_String* this__);
    int32_t(*GetHashCode)(System_String* this__);
    void(*Finalize)(System_String* this__);
    bool(*Equals)(System_String* this__, System_Object* obj);
} __System_String_VTABLE_DECL__;

struct System_String
{
    // Instance's vptr
    __System_String_VTABLE_DECL__* vptr0__;

    const wchar_t* string_body__;
};

extern IL2C_RUNTIME_TYPE_DECL __System_String_RUNTIME_TYPE__;
extern __System_String_VTABLE_DECL__ __System_String_VTABLE__;

// Binary layout compatible: IL2C_REF_HEADER + System_String.
// +----------------------+                -------------------------
// | IL2C_REF_HEADER      |                                      ^
// +----------------------+ <-- pString    -------               |
// | vptr0__              |                  ^                   | IL2C_CONST_STRING_DECL
// +----------------------+                  | System_String     |
// | string_body__        | ----+            v                   v
// +----------------------+     |          -------------------------
//                              |
//                              |
// +----------------------+     |
// |        :             | <---+
// | (Literal string)     |
// |        :             |
// +----------------------+

typedef struct
{
    // IL2C_REF_HEADER
    const void* pNext;
    IL2C_RUNTIME_TYPE_DECL* type;
    const intptr_t gcMark;           // Pretty hack: const string always marked (GCMARK_LIVE:0)

    // Instance's vptr
    __System_String_VTABLE_DECL__* vptr0__;

    const wchar_t* string_body__;
} IL2C_CONST_STRING_DECL;

#define IL2C_CONST_STRING(name, string_body) \
    static IL2C_CONST_STRING_DECL __##name##_CONST_STRING__ = { \
        NULL, &__System_String_RUNTIME_TYPE__, /* GCMARK_LIVE */ 0, &__System_String_VTABLE__, string_body }; \
    static System_String* const name = ((System_String*)&(__##name##_CONST_STRING__.vptr0__))

extern System_String* il2c_new_string(const wchar_t* pString);

extern /* internalcall */ void __System_String_IL2C_MarkHandler__(System_String* this__);
extern /* internalcall */ void* __System_String_IL2C_RuntimeCast__(System_String* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern /* virtual */ System_String* __System_String_ToString__(System_String* this__);
extern /* virtual */ int32_t __System_String_GetHashCode__(System_String* this__);

#define System_String_ToString(/* System_String* */ this__) \
    ((this__)->vptr0__->ToString((this__)))
#define System_String_GetHashCode(/* System_String* */ this__) \
    ((this__)->vptr0__->GetHashCode((this__)))
#define System_String_Finalize(/* System_String* */ this__) \
    ((this__)->vptr0__->Finalize((this__)))
#define System_String_Equals(/* System_String* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals((this__), (obj)))

extern System_String* System_String_Concat_6(System_String* str0, System_String* str1);
extern System_String* System_String_Substring(System_String* this__, int32_t startIndex);
extern System_String* System_String_Substring_1(System_String* this__, int32_t startIndex, int32_t length);
extern wchar_t System_String_get_Chars(System_String* this__, int32_t index);
extern int32_t System_String_get_Length(System_String* this__);
extern bool System_String_IsNullOrWhiteSpace(System_String* value);
extern bool System_String_op_Equality(System_String* lhs, System_String* rhs);

#ifdef __cplusplus
}
#endif

#endif
