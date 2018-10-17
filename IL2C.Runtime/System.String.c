#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.String

void __System_String_IL2C_MarkHandler__(System_String* this__)
{
    il2c_assert(this__ != NULL);
}

void* __System_String_IL2C_RuntimeCast__(System_String* this__, IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(this__ != NULL);

    if (type == il2c_typeof(System_String)) return this__;
    return __System_Object_IL2C_RuntimeCast__((System_Object*)this__, type);
}

System_String* __System_String_ToString__(System_String* this__)
{
    return this__;
}

int32_t __System_String_GetHashCode__(System_String* this__)
{
    // TODO:
    return (int32_t)(intptr_t)this__;
}

/////////////////////////////////////////////////
// String special functions

static System_String* __new_string_internal__(uintptr_t byteSize)
{
    // +----------------------+
    // | IL2C_REF_HEADER      |
    // +----------------------+ <-- pString                        ---------------------------
    // | vptr0__              |                                       ^                   ^
    // +----------------------+                                       | System_String     |
    // | string_body__        | ----+                                 v                   |
    // +----------------------+     | il2c_new_string():memcpy     -------                | bodySize
    // |        :             | <---+                                 ^                   |
    // | (Copied string)      |                                       | byteSize          |
    // |        :             |                                       v                   v
    // +----------------------+                                    ---------------------------

    uintptr_t bodySize = sizeof(System_String) + byteSize;
    System_String* pString = il2c_get_uninitialized_object_internal__(
        il2c_typeof(System_String),
        bodySize);
    pString->vptr0__ = &__System_String_VTABLE__;
    wchar_t* string_body = (wchar_t*)(((uint8_t*)pString) + sizeof(System_String));
    pString->string_body__ = string_body;
    return pString;
}

System_String* il2c_new_string(const wchar_t* string_body__)
{
    il2c_assert(string_body__ != NULL);

    uintptr_t size = (uintptr_t)(wcslen(string_body__) + 1) * sizeof(wchar_t);
    System_String* pString = __new_string_internal__(size);

    // Copy string at below
    il2c_memcpy((wchar_t*)(pString->string_body__), string_body__, size);

    return pString;
}

const wchar_t* il2c_c_str(System_String* str)
{
    if (str != NULL)
    {
        il2c_assert(str->string_body__ != NULL);
        return str->string_body__;
    }
    else
    {
        return NULL;
    }
}

/////////////////////////////////////////////////
// System.String members

System_String* System_String_Concat_6(System_String* str0, System_String* str1)
{
    il2c_assert(str0 != NULL);
    il2c_assert(str1 != NULL);
    il2c_assert(str0->string_body__ != NULL);
    il2c_assert(str1->string_body__ != NULL);

    uintptr_t str0Size = (uintptr_t)wcslen(str0->string_body__) * sizeof(wchar_t);
    uintptr_t str1Size = (uintptr_t)wcslen(str1->string_body__) * sizeof(wchar_t);

    System_String* pString = __new_string_internal__(str0Size + str1Size + sizeof(wchar_t));
    il2c_memcpy((wchar_t*)(pString->string_body__), str0->string_body__, str0Size);
    il2c_memcpy(((uint8_t*)(pString->string_body__)) + str0Size, str1->string_body__, str1Size + sizeof(wchar_t));

    return pString;
}

System_String* System_String_Substring(System_String* this__, int32_t startIndex)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    // TODO: IndexOutOfRangeException
    il2c_assert(startIndex >= 0);

    if (startIndex == 0)
    {
        return this__;
    }

    int32_t thisLength = (int32_t)wcslen(this__->string_body__);
    // TODO: IndexOutOfRangeException
    il2c_assert(startIndex < thisLength);

    uintptr_t newSize = (uintptr_t)(thisLength - startIndex + 1) * sizeof(wchar_t);
    System_String* pString = __new_string_internal__(newSize);
    il2c_memcpy((wchar_t*)(pString->string_body__), this__->string_body__ + startIndex, newSize);

    return pString;
}

System_String* System_String_Substring_1(System_String* this__, int32_t startIndex, int32_t length)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    // TODO: IndexOutOfRangeException
    il2c_assert(startIndex >= 0);
    il2c_assert(length >= 0);

    int32_t thisLength = (int32_t)wcslen(this__->string_body__);
    // TODO: IndexOutOfRangeException
    il2c_assert((startIndex + length) <= thisLength);

    if ((startIndex == 0) && (length == thisLength))
    {
        return this__;
    }

    uintptr_t newSize = (uintptr_t)length * sizeof(wchar_t);
    System_String* pString = __new_string_internal__(newSize + sizeof(wchar_t));
    il2c_memcpy((wchar_t*)(pString->string_body__), this__->string_body__ + startIndex, newSize);
    ((wchar_t*)(pString->string_body__))[length] = L'\0';

    return pString;
}

wchar_t System_String_get_Chars(System_String* this__, int32_t index)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    // TODO: IndexOutOfRangeException
    il2c_assert(index >= 0);
    il2c_assert(index < wcslen(this__->string_body__));

    return this__->string_body__[index];
}

int32_t System_String_get_Length(System_String* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    return (int32_t)wcslen(this__->string_body__);
}

bool System_String_IsNullOrWhiteSpace(System_String* value)
{
    if (value == NULL)
    {
        return true;
    }

    il2c_assert(value->string_body__ != NULL);

    uint32_t index = 0;
    while (1)
    {
        wchar_t ch = value->string_body__[index];
        switch (ch)
        {
        case L'\0':
            return true;
        case L' ':
        case L'\t':
            break;
        default:
            return false;
        }

        index++;
    }
}

bool System_String_op_Equality(System_String* lhs, System_String* rhs)
{
    // TODO: ArgumentNullException
    il2c_assert(lhs != NULL);
    il2c_assert(rhs != NULL);

    il2c_assert(lhs->string_body__ != NULL);
    il2c_assert(rhs->string_body__ != NULL);

    return wcscmp(lhs->string_body__, rhs->string_body__) == 0;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

__System_String_VTABLE_DECL__ __System_String_VTABLE__ = {
    /* internalcall */ __System_String_IL2C_RuntimeCast__,
    __System_String_ToString__,
    __System_String_GetHashCode__,
    (void*)__System_Object_Finalize__,
    (void*)__System_Object_Equals__,
};

IL2C_RUNTIME_TYPE_DECL __System_String_RUNTIME_TYPE__ = {
    "System.String", UINTPTR_MAX, /* internalcall */ (IL2C_MARK_HANDLER)__System_Object_IL2C_MarkHandler__ };
