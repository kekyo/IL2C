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

#if defined(IL2C_USE_LINE_INFORMATION)
static System_String* new_string_internal__(uintptr_t byteSize, const char* pFile, int line)
#else
static System_String* new_string_internal__(uintptr_t byteSize)
#endif
{
    const uintptr_t bodySize = sizeof(System_String) + byteSize;

#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        il2c_typeof(System_String),
        bodySize,
        pFile,
        line);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(
        pFile, line);
#else
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        il2c_typeof(System_String),
        bodySize);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    System_String* pString = (System_String*)(pHeader + 1);
    pThreadContext->pTemporaryReferenceAnchor = (System_Object*)pString;

    il2c_assert(pString->vptr0__ == &System_String_VTABLE__);

    wchar_t* string_body = (wchar_t*)(((uint8_t*)pString) + sizeof(System_String));
    pString->string_body__ = string_body;

    // Marked instance is initialized. (and will handle by GC)
    il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);

    return pString;
}

#if defined(IL2C_USE_LINE_INFORMATION)
System_String* il2c_new_string_with_length__(const wchar_t* pString, uint32_t length, const char* pFile, int line)
#else
System_String* il2c_new_string_with_length__(const wchar_t* pString, uint32_t length)
#endif
{
    il2c_assert(pString != NULL);

#if defined(IL2C_USE_LINE_INFORMATION)
    System_String* p = new_string_internal__((length + 1) * sizeof(wchar_t), pFile, line);
#else
    System_String* p = new_string_internal__((length + 1) * sizeof(wchar_t));
#endif

    // Copy string at below
    memcpy((wchar_t*)(p->string_body__), pString, length * sizeof(wchar_t));
    *((wchar_t*)(p->string_body__) + length) = L'\0';

    return p;
}

#if defined(IL2C_USE_LINE_INFORMATION)
System_String* il2c_new_string__(const wchar_t* pString, const char* pFile, int line)
#else
System_String* il2c_new_string__(const wchar_t* pString)
#endif
{
    il2c_assert(pString != NULL);

#if defined(IL2C_USE_LINE_INFORMATION)
    return il2c_new_string_with_length__(pString, (uint32_t)il2c_wcslen(pString), pFile, line);
#else
    return il2c_new_string_with_length__(pString, (uint32_t)il2c_wcslen(pString));
#endif
}

int32_t il2c_get_utf8_length(const char* pUtf8String, bool detectInvalidChars)
{
    il2c_assert(pUtf8String != NULL);

    // https://en.wikipedia.org/wiki/UTF-8

    int32_t length = 1;
    while (1)
    {
        const char ch0 = *pUtf8String;
        if (il2c_unlikely__(ch0 == '\0'))
        {
            break;
        }

        if (il2c_likely__(ch0 <= 0x7f))
        {
            pUtf8String += 1;
            length++;
            continue;
        }
        if (ch0 <= 0xdf)
        {
            pUtf8String += 2;
            length++;
            continue;
        }
        if (ch0 <= 0xef)
        {
            pUtf8String += 3;
            length++;
            continue;
        }
        if (ch0 <= 0xf7)
        {
            pUtf8String += 4;
            length++;
            continue;
        }
        if (ch0 <= 0xfb)
        {
            pUtf8String += 5;
            length++;
            continue;
        }
        if (ch0 <= 0xfd)
        {
            pUtf8String += 6;
            length++;
            continue;
        }

        // Found invalid encoding.
        if (detectInvalidChars)
        {
            return -length;
        }

        // gonna replace one char '?'
        pUtf8String += 1;
        length++;
    }

    return length;
}

wchar_t* il2c_utf16_from_utf8_and_get_last(wchar_t* pDest, const char* pUtf8String)
{
    il2c_assert(pUtf8String != NULL);

    while (1)
    {
        const char ch0 = *pUtf8String++;
        if (il2c_unlikely__(ch0 == '\0'))
        {
            *pDest = L'\0';
            break;
        }

        // 2byte page
        if (il2c_likely__(ch0 <= 0x7f))
        {
            *pDest++ = (wchar_t)ch0;
            continue;
        }
        const char ch1 = *pUtf8String++;
        if (ch0 <= 0xdf)
        {
            *pDest++ = ((((wchar_t)ch0) & 0x1f) << 6) | (((wchar_t)ch1) & 0x3f);
            continue;
        }
        const char ch2 = *pUtf8String++;
        if (ch0 <= 0xef)
        {
            *pDest++ = ((((wchar_t)ch0) & 0x0f) << 8) | ((((wchar_t)ch1) & 0x3f) << 6) | (((wchar_t)ch2) & 0x3f);
            continue;
        }
#if 0 // TODO: 4-6bytes decoder (surrogate pair)
        const char ch3 = *pUtf8String++;
        if (ch0 <= 0xf7)
        {
            il2c_assert(0);
            continue;
        }
        const char ch4 = *pUtf8String++;
        if (ch0 <= 0xfb)
        {
            il2c_assert(0);
            continue;
        }
        const char ch5 = *pUtf8String++;
        if (ch0 <= 0xfd)
        {
            il2c_assert(0);
            continue;
        }
#endif

        *pDest++ = L'?';
    }

    // Return NULL-terminated position.
    return pDest;
}

#if defined(IL2C_USE_LINE_INFORMATION)
System_String* il2c_new_string_from_utf8__(const char* pUtf8String, const char* pFile, int line)
#else
System_String* il2c_new_string_from_utf8__(const char* pUtf8String)
#endif
{
    if (il2c_unlikely__(pUtf8String == NULL))
    {
        return NULL;
    }

    int32_t length = il2c_get_utf8_length(pUtf8String, false);
    il2c_assert(length >= 0);

    uintptr_t size = (uintptr_t)(length) * sizeof(wchar_t);

#if defined(IL2C_USE_LINE_INFORMATION)
    System_String* p = new_string_internal__(size, pFile, line);
#else
    System_String* p = new_string_internal__(size);
#endif

    // Write into internal string buffer.
    il2c_utf16_from_utf8_and_get_last((wchar_t*)(p->string_body__), pUtf8String);

    return p;
}

const wchar_t* il2c_c_str(System_String* str)
{
    if (il2c_likely__(str != NULL))
    {
        il2c_assert(str->string_body__ != NULL);
        return str->string_body__;
    }
    else
    {
        return NULL;
    }
}

////////////////////////////////////////////////////////
// String formatting basis function.
// It's flexible with applicating delegation functions.

// The formatting precess.
int8_t il2c_format_string__(
    const wchar_t* pCompositeFormat,
    IL2C_FORMAT_TOKEN_WRITER pTokenWriter, IL2C_FORMAT_ARGUMENT_WRITER pArgumentWriter,
    void* pState)
{
    il2c_assert(pCompositeFormat != NULL);
    il2c_assert(pTokenWriter != NULL);
    il2c_assert(pArgumentWriter != NULL);

    enum states { state_fetch, state_index0, state_index, state_format }
        state = state_fetch;
    uint16_t argumentIndex = 0;
    uint32_t compositeFormatStartIndex = 0;
    uint32_t compositeFormatIndex = 0;
    uint32_t formatStartIndex = 0;
    uint32_t calculatedArgumentIndex;
    while (1)
    {
        const wchar_t ch = pCompositeFormat[compositeFormatIndex++];

        switch (state)
        {
        case state_fetch:
            if (il2c_unlikely__(ch == L'{'))
            {
                argumentIndex = 0;
                state = state_index0;
            }
            else if (il2c_unlikely__(ch == L'\0'))
            {
                if (il2c_likely__((compositeFormatIndex - 1) > compositeFormatStartIndex))
                {
                    int8_t result = (*pTokenWriter)(
                        pCompositeFormat + compositeFormatStartIndex,
                        (compositeFormatIndex - 1) - compositeFormatStartIndex,
                        pState);
                    if (result != IL2C_STRING_FORMAT_SUCCEEDED)
                    {
                        return result;
                    }
                }

                return IL2C_STRING_FORMAT_SUCCEEDED;
            }
            break;
        case state_index0:
            if (il2c_likely__((ch >= L'0') && (ch <= L'9')))
            {
                if (il2c_likely__((compositeFormatIndex - 2) > compositeFormatStartIndex))
                {
                    int8_t result = (*pTokenWriter)(
                        pCompositeFormat + compositeFormatStartIndex,
                        (compositeFormatIndex - 2) - compositeFormatStartIndex,
                        pState);
                    if (result != IL2C_STRING_FORMAT_SUCCEEDED)
                    {
                        return result;
                    }
                }

                calculatedArgumentIndex = argumentIndex * 10U + (uint32_t)(ch - L'0');
                if (il2c_unlikely__(calculatedArgumentIndex > UINT16_MAX))
                {
                    return IL2C_STRING_FORMAT_ARGUMENT_ABSOLUTE_LIMIT;
                }

                argumentIndex = (uint16_t)calculatedArgumentIndex;
                state = state_index;
            }
            else if (il2c_unlikely__(ch == L'{'))
            {
                if (il2c_likely__((compositeFormatIndex - 1) > compositeFormatStartIndex))
                {
                    int8_t result = (*pTokenWriter)(
                        pCompositeFormat + compositeFormatStartIndex,
                        (compositeFormatIndex - 1) - compositeFormatStartIndex,
                        pState);
                    if (result != IL2C_STRING_FORMAT_SUCCEEDED)
                    {
                        return result;
                    }
                }

                compositeFormatStartIndex = compositeFormatIndex;
                state = state_fetch;
            }
            else if (il2c_likely__(ch != L' '))
            {
                return IL2C_STRING_FORMAT_INVALID;
            }
            break;
        case state_index:
            if (il2c_likely__((ch >= L'0') && (ch <= L'9')))
            {
                calculatedArgumentIndex = argumentIndex * 10U + (uint32_t)(ch - L'0');
                if (il2c_unlikely__(calculatedArgumentIndex > UINT16_MAX))
                {
                    return IL2C_STRING_FORMAT_ARGUMENT_ABSOLUTE_LIMIT;
                }

                argumentIndex = (uint16_t)calculatedArgumentIndex;
            }
            else if (il2c_unlikely__(ch == L':'))
            {
                formatStartIndex = compositeFormatIndex;
                state = state_format;
            }
            else if (il2c_unlikely__(ch == L'}'))
            {
                int8_t result = (*pArgumentWriter)(
                    argumentIndex,
                    NULL,
                    0,
                    pState);
                if (result != IL2C_STRING_FORMAT_SUCCEEDED)
                {
                    return result;
                }

                compositeFormatStartIndex = compositeFormatIndex;
                state = state_fetch;
            }
            else
            {
                return IL2C_STRING_FORMAT_INVALID;
            }
            break;
        case state_format:
            if (il2c_unlikely__(ch == L'}'))
            {
                int8_t result = (*pArgumentWriter)(
                    argumentIndex,
                    pCompositeFormat + formatStartIndex,
                    compositeFormatIndex - formatStartIndex - 1,
                    pState);
                if (result != IL2C_STRING_FORMAT_SUCCEEDED)
                {
                    return result;
                }

                compositeFormatStartIndex = compositeFormatIndex;
                state = state_fetch;
            }
            else if (il2c_unlikely__(ch == L'\0'))
            {
                return IL2C_STRING_FORMAT_INVALID;
            }
            break;
        }
    }
}

/////////////////////////////////////////////////////////////
// System.String

IL2C_CONST_STRING(System_String_Empty, L"");
System_String** System_String_Empty_REF__ = (System_String**)&System_String_Empty;

System_String* System_String_ToString(System_String* this__)
{
    il2c_assert(this__ != NULL);

    return this__;
}

bool System_String_Equals__System_String(System_String* this__, System_String* obj)
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

bool System_String_Equals__System_Object(System_String* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    System_String* pString = il2c_castclass(obj, System_String);
    return System_String_Equals__System_String(this__, pString);
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
        if (il2c_unlikely__(ch == L'\0'))
        {
            break;
        }
        value = (value << 16) ^ ((~(int16_t)ch) & 0xffff);
        p++;
    }
    return (int32_t)value;
}

System_String* System_String_Concat__System_String_System_String(System_String* str0, System_String* str1)
{
    // TODO: IsNullOrEmpty()
    if (str0 == NULL)
    {
        if (str1 == NULL)
        {
            return System_String_Empty;
        }
        else
        {
            return str1;
        }
    }
    
    if (str1 == NULL)
    {
        return str0;
    }

    il2c_assert(str0->string_body__ != NULL);
    il2c_assert(str1->string_body__ != NULL);

    uintptr_t str0Size = (uintptr_t)il2c_wcslen(str0->string_body__) * sizeof(wchar_t);
    uintptr_t str1Size = (uintptr_t)il2c_wcslen(str1->string_body__) * sizeof(wchar_t);

#if defined(IL2C_USE_LINE_INFORMATION)
    System_String* pString = new_string_internal__(str0Size + str1Size + sizeof(wchar_t), __FILE__, __LINE__);
#else
    System_String* pString = new_string_internal__(str0Size + str1Size + sizeof(wchar_t));
#endif

    memcpy((wchar_t*)(pString->string_body__), str0->string_body__, str0Size);
    memcpy(((uint8_t*)(pString->string_body__)) + str0Size, str1->string_body__, str1Size + sizeof(wchar_t));

    return pString;
}

System_String* System_String_Concat__System_Object_System_Object(System_Object* arg0, System_Object* arg1)
{
    // TODO: NullReferenceException
    il2c_assert(arg0 != NULL);
    il2c_assert(arg1 != NULL);

    struct
    {
        const IL2C_EXECUTION_FRAME* pNext__;
        const uint16_t objRefCount__;
        const uint16_t valueCount__;
        System_String* str0;
        System_String* str1;
    } frame__ = { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    frame__.str0 = arg0->vptr0__->ToString(arg0);
    frame__.str1 = arg1->vptr0__->ToString(arg1);

    frame__.str0 = System_String_Concat__System_String_System_String(frame__.str0, frame__.str1);

     il2c_return_unlink_with_objref(&frame__, frame__.str0);
}

System_String* System_String_Concat__System_String_System_String_System_String(System_String* str0, System_String* str1, System_String* str2)
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

#if defined(IL2C_USE_LINE_INFORMATION)
    System_String* pString = new_string_internal__(str0Size + str1Size + str2Size + sizeof(wchar_t), __FILE__, __LINE__);
#else
    System_String* pString = new_string_internal__(str0Size + str1Size + str2Size + sizeof(wchar_t));
#endif

    memcpy((wchar_t*)(pString->string_body__), str0->string_body__, str0Size);
    memcpy(((uint8_t*)(pString->string_body__)) + str0Size, str1->string_body__, str1Size);
    memcpy(((uint8_t*)(pString->string_body__)) + str0Size + str1Size, str2->string_body__, str2Size + sizeof(wchar_t));

    il2c_return_with_objref(pString);
}

System_String* System_String_Substring__System_Int32(System_String* this__, int32_t startIndex)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    // TODO: IndexOutOfRangeException
    il2c_assert(startIndex >= 0);

    if (il2c_unlikely__(startIndex == 0))
    {
        return this__;
    }

    int32_t thisLength = (int32_t)il2c_wcslen(this__->string_body__);
    // TODO: IndexOutOfRangeException
    il2c_assert(startIndex < thisLength);

    uintptr_t newSize = (uintptr_t)(thisLength - startIndex + 1) * sizeof(wchar_t);

#if defined(IL2C_USE_LINE_INFORMATION)
    System_String* pString = new_string_internal__(newSize, __FILE__, __LINE__);
#else
    System_String* pString = new_string_internal__(newSize);
#endif

    memcpy((wchar_t*)(pString->string_body__), this__->string_body__ + startIndex, newSize);

    il2c_return_with_objref(pString);
}

System_String* System_String_Substring__System_Int32_System_Int32(System_String* this__, int32_t startIndex, int32_t length)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    // TODO: IndexOutOfRangeException
    il2c_assert(startIndex >= 0);
    il2c_assert(length >= 0);

    int32_t thisLength = (int32_t)il2c_wcslen(this__->string_body__);
    // TODO: IndexOutOfRangeException
    il2c_assert((startIndex + length) <= thisLength);

    if (il2c_unlikely__((startIndex == 0) && (length == thisLength)))
    {
        return this__;
    }

    uintptr_t newSize = (uintptr_t)length * sizeof(wchar_t);

#if defined(IL2C_USE_LINE_INFORMATION)
    System_String* pString = new_string_internal__(newSize + sizeof(wchar_t), __FILE__, __LINE__);
#else
    System_String* pString = new_string_internal__(newSize + sizeof(wchar_t));
#endif

    memcpy((wchar_t*)(pString->string_body__), this__->string_body__ + startIndex, newSize);
    ((wchar_t*)(pString->string_body__))[length] = L'\0';

    il2c_return_with_objref(pString);
}

wchar_t System_String_get_Chars__System_Int32(System_String* this__, int32_t index)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    // TODO: Improvement
    if (il2c_unlikely__((index < 0) || (index >= (int32_t)il2c_wcslen(this__->string_body__))))
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

bool System_String_IsNullOrWhiteSpace__System_String(System_String* value)
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

bool System_String_op_Equality__System_String_System_String(System_String* lhs, System_String* rhs)
{
    if ((lhs == NULL) && (rhs == NULL))
    {
        return true;
    }

    if ((lhs != NULL) != (rhs != NULL))
    {
        return false;
    }

    il2c_assert(lhs->string_body__ != NULL);
    il2c_assert(rhs->string_body__ != NULL);

    return il2c_wcscmp(lhs->string_body__, rhs->string_body__) == 0;
}

bool System_String_op_Inequality__System_String_System_String(System_String* lhs, System_String* rhs)
{
    if ((lhs == NULL) && (rhs == NULL))
    {
        return false;
    }

    if ((lhs != NULL) != (rhs != NULL))
    {
        return true;
    }

    il2c_assert(lhs->string_body__ != NULL);
    il2c_assert(rhs->string_body__ != NULL);

    return il2c_wcscmp(lhs->string_body__, rhs->string_body__) != 0;
}

////////////////////////////////////////////////////////
// System.String.Format() common functions.

typedef struct System_String_InternalFormatState
{
    // The arguments count.
    uint16_t argumentCount;
    // Number of format items.
    uint16_t formatItemCount;
    // Index of format items.
    uint16_t formatItemIndex;
    // Candidate string length.
    uint32_t length;
    // The arguments.
    System_Object** ppArgs;
    // The formatted strings by ToString().
    System_String** ppFormattedString;
    // String storing buffer.
    wchar_t* pWriteTarget;
} System_String_InternalFormatState;

#define IL2C_STRING_FORMAT_ARGUMENT_INDEX_OUT_OF_RANGE (-3)

// ---------------
// Step 1 writers.

static int8_t System_String_InternalFormatStep1Writer(
    const wchar_t* pTokenFrom, uint32_t tokenLength, void* pState)
{
    il2c_assert(pTokenFrom != NULL);
    il2c_assert(pState != NULL);

    // Nothing to do.
    return IL2C_STRING_FORMAT_SUCCEEDED;
}

static int8_t System_String_InternalFormatStep1ArgumentWriter(
    uint16_t argumentIndex, const wchar_t* pFormatFrom, uint32_t formatLength, void* pState)
{
    il2c_assert(argumentIndex >= 0);
    il2c_assert(pState != NULL);

    System_String_InternalFormatState* p = pState;
    il2c_assert(p->pWriteTarget == NULL);

    if (il2c_unlikely__(argumentIndex >= p->argumentCount))
    {
        return IL2C_STRING_FORMAT_ARGUMENT_INDEX_OUT_OF_RANGE;
    }

    // Count up number of format items.
    p->formatItemCount++;

    return IL2C_STRING_FORMAT_SUCCEEDED;
}

// ---------------
// Step 2 writers.

static int8_t System_String_InternalFormatStep2Writer(
    const wchar_t* pTokenFrom, uint32_t tokenLength, void* pState)
{
    il2c_assert(pTokenFrom != NULL);
    il2c_assert(pState != NULL);

    System_String_InternalFormatState* p = pState;
    il2c_assert(p->pWriteTarget == NULL);

    // Count up total string length.
    p->length += tokenLength;

    return IL2C_STRING_FORMAT_SUCCEEDED;
}

static int8_t System_String_InternalFormatStep2ArgumentWriter(
    uint16_t argumentIndex, const wchar_t* pFormatFrom, uint32_t formatLength, void* pState)
{
    il2c_assert(argumentIndex >= 0);
    il2c_assert(pState != NULL);

    System_String_InternalFormatState* p = pState;
    il2c_assert(p->pWriteTarget == NULL);
    il2c_assert(p->formatItemIndex < p->formatItemCount);

    il2c_assert(argumentIndex < p->argumentCount);

    System_String** ppFormattedString = &p->ppFormattedString[p->formatItemIndex++];
    il2c_assert(*ppFormattedString == NULL);

    void* pArg = p->ppArgs[argumentIndex];
    if (il2c_likely__(pArg != NULL))
    {
        System_Object* pAdjustedReference = il2c_adjusted_reference(pArg);
        System_IFormattable* pFormattable = il2c_isinst(pArg, System_IFormattable);
        if (pFormattable != NULL)
        {
            if (il2c_unlikely__(formatLength >= 1))
            {
                il2c_assert(pFormatFrom != NULL);
                System_String* pFormatString = il2c_new_string_with_length(pFormatFrom, formatLength);
                // TODO: formatProvider
                *ppFormattedString = pFormattable->vptr0__->ToString__System_String_System_IFormatProvider(pAdjustedReference, pFormatString, NULL);
            }
            else
            {
                // TODO: formatProvider
                *ppFormattedString = pFormattable->vptr0__->ToString__System_String_System_IFormatProvider(pAdjustedReference, NULL, NULL);
            }
        }
        else
        {
            *ppFormattedString = pAdjustedReference->vptr0__->ToString(pAdjustedReference);
        }
    }
    else
    {
        *ppFormattedString = System_String_Empty;
    }

    // Count up total string length.
    p->length += (uint32_t)il2c_wcslen((*ppFormattedString)->string_body__);

    return IL2C_STRING_FORMAT_SUCCEEDED;
}

// ---------------
// Step 3 writers.

static int8_t System_String_InternalFormatStep3Writer(
    const wchar_t* pTokenFrom, uint32_t tokenLength, void* pState)
{
    il2c_assert(pTokenFrom != NULL);
    il2c_assert(pState != NULL);

    System_String_InternalFormatState* p = pState;
    il2c_assert(p->pWriteTarget != NULL);
    il2c_assert(p->formatItemIndex <= p->formatItemCount);

    while (il2c_likely__(tokenLength > 0))
    {
        *(p->pWriteTarget)++ = *pTokenFrom++;
        tokenLength--;
    }

    return IL2C_STRING_FORMAT_SUCCEEDED;
}

static int8_t System_String_InternalFormatStep3ArgumentWriter(
    uint16_t argumentIndex, const wchar_t* pFormatFrom, uint32_t formatLength, void* pState)
{
    il2c_assert(pState != NULL);

    System_String_InternalFormatState* p = pState;
    il2c_assert(p->pWriteTarget != NULL);
    il2c_assert(p->formatItemIndex < p->formatItemCount);
    il2c_assert(argumentIndex < p->argumentCount);

    System_String* pFormattedString = p->ppFormattedString[p->formatItemIndex++];
    il2c_assert(pFormattedString != NULL);
    il2c_assert(pFormattedString->string_body__ != NULL);

    const wchar_t* pFrom = pFormattedString->string_body__;
    while (1)
    {
        const wchar_t ch = *pFrom++;
        if (il2c_unlikely__(ch == L'\0'))
        {
            break;
        }
        *(p->pWriteTarget)++ = ch;
    }

    return IL2C_STRING_FORMAT_SUCCEEDED;
}

// ---------------
// The formatter.

static int8_t System_String_InternalFormat(
    System_String** ppString, System_String* pFormat,
    uint16_t argumentCount, System_Object** ppArgs)
{
    il2c_assert(ppString != NULL);
    il2c_assert(pFormat != NULL);
    il2c_assert(pFormat->string_body__ != NULL);
    il2c_assert(argumentCount >= 0);
    il2c_assert(ppArgs != NULL);

    System_String_InternalFormatState state = { 0 };
    state.argumentCount = argumentCount;
    state.ppArgs = ppArgs;

    /////////////////////////////////////////////////
    // Step 1-1. Count formatted string's number of format items.

    int8_t result = il2c_format_string__(
        pFormat->string_body__,
        System_String_InternalFormatStep1Writer,
        System_String_InternalFormatStep1ArgumentWriter,
        &state);
    if (il2c_unlikely__(result != IL2C_STRING_FORMAT_SUCCEEDED))
    {
        return result;
    }

    /////////////////////////////////////////////////
    // Step 1-2. Allocate and link string store spaces into the execution frame.

    struct System_String_InternalFormat_EXECUTION_FRAME
    {
        IL2C_EXECUTION_FRAME* pNext__;
        const uint16_t objRefCount__;
        const uint16_t valueCount__;
        System_String* pString;
        //System_String* pFormattedString[state.count];
    };

    const uint32_t size =
        sizeof(struct System_String_InternalFormat_EXECUTION_FRAME) +
        state.formatItemCount * sizeof(System_String*);
    il2c_mcalloc(struct System_String_InternalFormat_EXECUTION_FRAME, pFrame, size);
    memset(pFrame, 0, size);
    *(uint16_t*)(&pFrame->objRefCount__) = (uint16_t)(1 + state.formatItemCount);
    il2c_link_execution_frame(pFrame);

    state.ppFormattedString = (&pFrame->pString) + 1;

    /////////////////////////////////////////////////
    // Step 2-1. Calculate formatted string length.

    result = il2c_format_string__(
        pFormat->string_body__,
        System_String_InternalFormatStep2Writer,
        System_String_InternalFormatStep2ArgumentWriter,
        &state);
    if (il2c_unlikely__(result != IL2C_STRING_FORMAT_SUCCEEDED))
    {
        il2c_unlink_execution_frame(pFrame, NULL);
        il2c_mcfree(pFrame);
        return result;
    }

    /////////////////////////////////////////////////
    // Step 2-2. Allocate System.String with required length.

#if defined(IL2C_USE_LINE_INFORMATION)
    pFrame->pString = new_string_internal__(
        (state.length + 1) * sizeof(wchar_t), __FILE__, __LINE__);
#else
    pFrame->pString = new_string_internal__(
        (state.length + 1) * sizeof(wchar_t));
#endif

    state.pWriteTarget = (wchar_t*)(pFrame->pString->string_body__);

    /////////////////////////////////////////////////
    // Step 3. Write formatted string into System.String

    // Reset index.
    state.formatItemIndex = 0;

    result = il2c_format_string__(
        pFormat->string_body__,
        System_String_InternalFormatStep3Writer,
        System_String_InternalFormatStep3ArgumentWriter,
        &state);
    il2c_assert(result == IL2C_STRING_FORMAT_SUCCEEDED);
    il2c_assert(state.formatItemIndex == state.formatItemCount);

    *state.pWriteTarget = L'\0';
    il2c_assert((uint32_t)(state.pWriteTarget - pFrame->pString->string_body__) == state.length);

    *ppString = pFrame->pString;

    il2c_unlink_execution_frame(pFrame, pFrame->pString);
    il2c_mcfree(pFrame);

    return result;
}

////////////////////////////////////////////////////////
// System.String.Format()

System_String* System_String_Format__System_String_System_Object(
    System_String* format, System_Object* arg0)
{
    // TODO: ArgumentNullException
    il2c_assert(format != NULL);
    il2c_assert(format->string_body__ != NULL);

    System_String* pString;
    if (il2c_unlikely__(System_String_InternalFormat(
        &pString, format, 1, &arg0) != 0))
    {
        il2c_throw_formatexception__();
    }

    return pString;
}

System_String* System_String_Format__System_String_System_Object_System_Object(
    System_String* format, System_Object* arg0, System_Object* arg1)
{
    // TODO: ArgumentNullException
    il2c_assert(format != NULL);
    il2c_assert(format->string_body__ != NULL);

    System_Object* pArgs[2];
    pArgs[0] = arg0;
    pArgs[1] = arg1;

    System_String* pString;
    if (il2c_unlikely__(System_String_InternalFormat(
        &pString, format, 2, pArgs) != 0))
    {
        il2c_throw_formatexception__();
    }

    return pString;
}

System_String* System_String_Format__System_String_System_Object_System_Object_System_Object(
    System_String* format, System_Object* arg0, System_Object* arg1, System_Object* arg2)
{
    // TODO: ArgumentNullException
    il2c_assert(format != NULL);
    il2c_assert(format->string_body__ != NULL);

    System_Object* pArgs[3];
    pArgs[0] = arg0;
    pArgs[1] = arg1;
    pArgs[2] = arg2;

    System_String* pString;
    if (il2c_unlikely__(System_String_InternalFormat(
        &pString, format, 3, pArgs) != 0))
    {
        il2c_throw_formatexception__();
    }

    return pString;
}

System_String* System_String_Format__System_String_System_Array__System_Object(
    System_String* format, il2c_arraytype(System_Object)* args)
{
    // TODO: ArgumentNullException
    il2c_assert(format != NULL);
    il2c_assert(format->string_body__ != NULL);
    il2c_assert(args != NULL);

    if (il2c_unlikely__(args->Length > UINT16_MAX))
    {
        il2c_throw_formatexception__();
    }

    System_String* pString;
    if (il2c_unlikely__(System_String_InternalFormat(
        &pString, format, (uint16_t)args->Length,
        il2c_array_itemptr(args, System_Object*, 0)) != 0))
    {
        il2c_throw_formatexception__();
    }

    return pString;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

System_String_VTABLE_DECL__ System_String_VTABLE__ = {
    0, // Adjustor offset
    (bool(*)(void*, System_Object*))System_String_Equals__System_Object,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_String_GetHashCode,
    (System_String* (*)(void*))System_String_ToString,
};

IL2C_RUNTIME_TYPE_BEGIN(
    System_String,
    "System.String",
    IL2C_TYPE_REFERENCE | IL2C_TYPE_VARIABLE,
    0,
    System_Object,
    0, 0)
IL2C_RUNTIME_TYPE_END();
