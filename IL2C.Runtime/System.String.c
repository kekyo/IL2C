#include "il2c_private.h"

/////////////////////////////////////////////////
// String special functions

// The string instance has special depended layout. (IL2C_TYPE_VARIABLE)
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
// +----------------------+ (terminated with \0)               ---------------------------

// Const (literal) string has compatibility layout for heap allocated.
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
// +----------------------+ (terminated with \0)

static System_String* new_string_internal__(uintptr_t byteSize)
{
    uintptr_t bodySize = sizeof(System_String) + byteSize;
    System_String* pString = il2c_get_uninitialized_object_internal__(
        il2c_typeof(System_String),
        bodySize);
    pString->vptr0__ = &System_String_VTABLE__;
    wchar_t* string_body = (wchar_t*)(((uint8_t*)pString) + sizeof(System_String));
    pString->string_body__ = string_body;
    return pString;
}

System_String* il2c_new_string(const wchar_t* pString)
{
    if (pString == NULL)
    {
        return NULL;
    }

    uintptr_t size = (uintptr_t)(il2c_wcslen(pString) + 1) * sizeof(wchar_t);
    System_String* p = new_string_internal__(size);

    // Copy string at below
    il2c_memcpy((wchar_t*)(p->string_body__), pString, size);

    return p;
}

System_String* il2c_new_string_from_utf8(const char* pUtf8String)
{
    if (pUtf8String == NULL)
    {
        return NULL;
    }

    // https://en.wikipedia.org/wiki/UTF-8

    size_t length = 1;
    const char* pSource = pUtf8String;
    while (1)
    {
        const char ch0 = *pSource;
        if (ch0 == '\0')
        {
            break;
        }

        if (ch0 <= 0x7f)
        {
            pSource += 1;
            length++;
            continue;
        }
        if (ch0 <= 0xdf)
        {
            pSource += 2;
            length++;
            continue;
        }
        if (ch0 <= 0xef)
        {
            pSource += 3;
            length++;
            continue;
        }
        if (ch0 <= 0xf7)
        {
            pSource += 4;
            length++;
            continue;
        }
        if (ch0 <= 0xfb)
        {
            pSource += 5;
            length++;
            continue;
        }
        if (ch0 <= 0xfd)
        {
            pSource += 6;
            length++;
            continue;
        }
        break;
    }

    uintptr_t size = (uintptr_t)(length) * sizeof(wchar_t);
    System_String* p = new_string_internal__(size);
    wchar_t* pDest = (wchar_t*)(p->string_body__);

    pSource = pUtf8String;
    while (1)
    {
        const char ch0 = *pSource++;
        if (ch0 == '\0')
        {
            *pDest = L'\0';
            break;
        }

        // 2byte page
        if (ch0 <= 0x7f)
        {
            *pDest++ = (wchar_t)ch0;
            continue;
        }
        const char ch1 = *pSource++;
        if (ch0 <= 0xdf)
        {
            *pDest++ = ((((wchar_t)ch0) & 0x1f) << 6) | (((wchar_t)ch1) & 0x3f);
            continue;
        }
        const char ch2 = *pSource++;
        if (ch0 <= 0xef)
        {
            *pDest++ = ((((wchar_t)ch0) & 0x0f) << 8) | ((((wchar_t)ch1) & 0x3f) << 6) | (((wchar_t)ch2) & 0x3f);
            continue;
        }
#if 0 // TODO: 4-6bytes decoder (surrogate pair)
        const char ch3 = *pSource++;
        if (ch0 <= 0xf7)
        {
            il2c_assert(0);
            continue;
        }
        const char ch4 = *pSource++;
        if (ch0 <= 0xfb)
        {
            il2c_assert(0);
            continue;
        }
        const char ch5 = *pSource++;
        if (ch0 <= 0xfd)
        {
            il2c_assert(0);
            continue;
        }
#endif
        break;
    }

    return p;
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

/////////////////////////////////////////////////////////////
// System.String

System_String* System_String_ToString(System_String* this__)
{
    il2c_assert(this__ != NULL);

    return this__;
}

bool System_String_Equals(System_String* this__, System_String* obj)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    if (this__ == obj)
    {
        return true;
    }
    if (obj == NULL)
    {
        return false;
    }

    il2c_assert(obj->string_body__ != NULL);

    return
        (this__->string_body__ == obj->string_body__) ||
        (il2c_wcscmp(this__->string_body__, obj->string_body__) == 0);
}

bool System_String_Equals_1(System_String* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    // TODO: castclass
    return System_String_Equals(this__, (System_String*)obj);
}

int32_t System_String_GetHashCode(System_String* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    // TODO: maybe better for limits with maximum count.
    // TODO: will we cache the calculated hash value?

    int32_t value = 0;
    const wchar_t* p = this__->string_body__;
    while (1)
    {
        const wchar_t ch = *p;
        if (*p != L'\0')
        {
            break;
        }
        value = (value << 16) ^ ~ch;
        p++;
    }
    return value;
}

System_String* System_String_Concat_3(System_String* str0, System_String* str1)
{
    // TODO: NullReferenceException
    il2c_assert(str0 != NULL);
    il2c_assert(str1 != NULL);

    il2c_assert(str0->string_body__ != NULL);
    il2c_assert(str1->string_body__ != NULL);

    uintptr_t str0Size = (uintptr_t)il2c_wcslen(str0->string_body__) * sizeof(wchar_t);
    uintptr_t str1Size = (uintptr_t)il2c_wcslen(str1->string_body__) * sizeof(wchar_t);

    System_String* pString = new_string_internal__(str0Size + str1Size + sizeof(wchar_t));
    il2c_memcpy((wchar_t*)(pString->string_body__), str0->string_body__, str0Size);
    il2c_memcpy(((uint8_t*)(pString->string_body__)) + str0Size, str1->string_body__, str1Size + sizeof(wchar_t));

    return pString;
}

System_String* System_String_Concat_4(System_Object* arg0, System_Object* arg1)
{
    // TODO: NullReferenceException
    il2c_assert(arg0 != NULL);
    il2c_assert(arg1 != NULL);

    System_String* str0 = arg0->vptr0__->ToString(arg0);
    System_String* str1 = arg1->vptr0__->ToString(arg1);

    return System_String_Concat_3(str0, str1);
}

System_String* System_String_Concat_5(System_String* str0, System_String* str1, System_String* str2)
{
    // TODO: NullReferenceException
    il2c_assert(str0 != NULL);
    il2c_assert(str1 != NULL);
    il2c_assert(str2 != NULL);

    il2c_assert(str0->string_body__ != NULL);
    il2c_assert(str1->string_body__ != NULL);
    il2c_assert(str2->string_body__ != NULL);

    uintptr_t str0Size = (uintptr_t)il2c_wcslen(str0->string_body__) * sizeof(wchar_t);
    uintptr_t str1Size = (uintptr_t)il2c_wcslen(str1->string_body__) * sizeof(wchar_t);
    uintptr_t str2Size = (uintptr_t)il2c_wcslen(str2->string_body__) * sizeof(wchar_t);

    System_String* pString = new_string_internal__(str0Size + str1Size + str2Size + sizeof(wchar_t));
    il2c_memcpy((wchar_t*)(pString->string_body__), str0->string_body__, str0Size);
    il2c_memcpy(((uint8_t*)(pString->string_body__)) + str0Size, str1->string_body__, str1Size);
    il2c_memcpy(((uint8_t*)(pString->string_body__)) + str0Size + str1Size, str2->string_body__, str2Size + sizeof(wchar_t));

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

    int32_t thisLength = (int32_t)il2c_wcslen(this__->string_body__);
    // TODO: IndexOutOfRangeException
    il2c_assert(startIndex < thisLength);

    uintptr_t newSize = (uintptr_t)(thisLength - startIndex + 1) * sizeof(wchar_t);
    System_String* pString = new_string_internal__(newSize);
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

    int32_t thisLength = (int32_t)il2c_wcslen(this__->string_body__);
    // TODO: IndexOutOfRangeException
    il2c_assert((startIndex + length) <= thisLength);

    if ((startIndex == 0) && (length == thisLength))
    {
        return this__;
    }

    uintptr_t newSize = (uintptr_t)length * sizeof(wchar_t);
    System_String* pString = new_string_internal__(newSize + sizeof(wchar_t));
    il2c_memcpy((wchar_t*)(pString->string_body__), this__->string_body__ + startIndex, newSize);
    ((wchar_t*)(pString->string_body__))[length] = L'\0';

    return pString;
}

wchar_t System_String_get_Chars(System_String* this__, int32_t index)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    // TODO: Improvement
    if ((index < 0) || (index >= il2c_wcslen(this__->string_body__)))
    {
        il2c_throw_indexoutofrangeexception__();
    }

    return this__->string_body__[index];
}

int32_t System_String_get_Length(System_String* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    return (int32_t)il2c_wcslen(this__->string_body__);
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

bool System_String_op_Inequality(System_String* lhs, System_String* rhs)
{
    // TODO: ArgumentNullException
    il2c_assert(lhs != NULL);
    il2c_assert(rhs != NULL);

    il2c_assert(lhs->string_body__ != NULL);
    il2c_assert(rhs->string_body__ != NULL);

    return wcscmp(lhs->string_body__, rhs->string_body__) != 0;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

System_String_VTABLE_DECL__ System_String_VTABLE__ = {
    0, // Adjustor offset
    (bool(*)(void*, System_Object*))System_String_Equals_1,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_String_GetHashCode,
    (System_String* (*)(void*))System_String_ToString,
};

IL2C_RUNTIME_TYPE_BEGIN(System_String, "System.String", IL2C_TYPE_VARIABLE, 0, System_Object, NULL, 0)
IL2C_RUNTIME_TYPE_END();
