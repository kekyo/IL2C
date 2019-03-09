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

#if defined(_DEBUG)
static System_String* new_string_internal__(uintptr_t byteSize, const char* pFile, int line)
#else
static System_String* new_string_internal__(uintptr_t byteSize)
#endif
{
    uintptr_t bodySize = sizeof(System_String) + byteSize;

#if defined(_DEBUG)
    System_String* pString = il2c_get_uninitialized_object_internal__(
        il2c_typeof(System_String),
        bodySize, pFile, line);
#else
    System_String* pString = il2c_get_uninitialized_object_internal__(
        il2c_typeof(System_String),
        bodySize);
#endif

    pString->vptr0__ = &System_String_VTABLE__;
    wchar_t* string_body = (wchar_t*)(((uint8_t*)pString) + sizeof(System_String));
    pString->string_body__ = string_body;
    return pString;
}

#if defined(_DEBUG)
System_String* il2c_new_string__(const wchar_t* pString, const char* pFile, int line)
#else
System_String* il2c_new_string__(const wchar_t* pString)
#endif
{
    if (pString == NULL)
    {
        return NULL;
    }

    uintptr_t size = (uintptr_t)(il2c_wcslen(pString) + 1) * sizeof(wchar_t);

#if defined(_DEBUG)
    System_String* p = new_string_internal__(size, pFile, line);
#else
    System_String* p = new_string_internal__(size);
#endif

    // Copy string at below
    memcpy((wchar_t*)(p->string_body__), pString, size);

    return p;
}

int32_t il2c_get_utf8_length(const char* pUtf8String, bool detectInvalidChars)
{
    il2c_assert(pUtf8String != NULL);

    // https://en.wikipedia.org/wiki/UTF-8

    int32_t length = 1;
    while (1)
    {
        const char ch0 = *pUtf8String;
        if (ch0 == '\0')
        {
            break;
        }

        if (ch0 <= 0x7f)
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

#if defined(_DEBUG)
System_String* il2c_new_string_from_utf8__(const char* pUtf8String, const char* pFile, int line)
#else
System_String* il2c_new_string_from_utf8__(const char* pUtf8String)
#endif
{
    if (pUtf8String == NULL)
    {
        return NULL;
    }

    int32_t length = il2c_get_utf8_length(pUtf8String, false);
    il2c_assert(length >= 0);

    uintptr_t size = (uintptr_t)(length) * sizeof(wchar_t);

#if defined(_DEBUG)
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

////////////////////////////////////////////////////////
// String formatting basis function.
// It's flexible with applicating delegation functions.

// The formatting precess.
bool il2c_format_string__(
    const wchar_t* pFormat,
    IL2C_FORMAT_WRITER pWriter, IL2C_FORMAT_ARGUMENT_WRITER pArgumentWriter,
    void* pState)
{
    il2c_assert(pFormat != NULL);
    il2c_assert(pWriter != NULL);
    il2c_assert(pArgumentWriter != NULL);

    enum { state_fetch, state_index0, state_index } state = state_fetch;
    uint32_t argumentIndex = 0;
    uint32_t formatStartIndex = 0;
    uint32_t formatIndex = 0;
    while (1)
    {
        const wchar_t ch = pFormat[formatIndex++];
        if (ch == L'\0')
        {
            if ((formatIndex - 1) > formatStartIndex)
            {
                if (!(*pWriter)(pFormat + formatStartIndex, (formatIndex - 1) - formatStartIndex, pState))
                {
                    return false;
                }
            }
            
            break;
        }

        switch (state)
        {
        case state_fetch:
            if (ch == L'{')
            {
                argumentIndex = 0;
                state = state_index0;
            }
            break;
        case state_index0:
            if ((ch >= L'0') && (ch <= L'9'))
            {
                if ((formatIndex - 2) > formatStartIndex)
                {
                    if (!(*pWriter)(pFormat + formatStartIndex, (formatIndex - 2) - formatStartIndex, pState))
                    {
                        return false;
                    }
                }

                argumentIndex = argumentIndex * 10 + (ch - L'0');
                state = state_index;
            }
            else if (ch == L'{')
            {
                if ((formatIndex - 1) > formatStartIndex)
                {
                    if (!(*pWriter)(pFormat + formatStartIndex, (formatIndex - 1) - formatStartIndex, pState))
                    {
                        return false;
                    }
                }

                formatStartIndex = formatIndex;
                state = state_fetch;
            }
            else
            {
                return false;
            }
            break;
        case state_index:
            if ((ch >= L'0') && (ch <= L'9'))
            {
                argumentIndex = argumentIndex * 10 + (ch - L'0');
            }
            else if (ch == L'}')
            {
                if (!(*pArgumentWriter)(argumentIndex, pState))
                {
                    return false;
                }

                formatStartIndex = formatIndex;
                state = state_fetch;
            }
            else
            {
                return false;
            }
            break;
        }
    }

    return true;
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

    System_String* pString = il2c_castclass(obj, System_String);
    return System_String_Equals(this__, pString);
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
        value = (value << 16) ^ ((~(int16_t)ch) & 0xffff);
        p++;
    }
    return (int32_t)value;
}

System_String* System_String_Concat_3(System_String* str0, System_String* str1)
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

#if defined(_DEBUG)
    System_String* pString = new_string_internal__(str0Size + str1Size + sizeof(wchar_t), __FILE__, __LINE__);
#else
    System_String* pString = new_string_internal__(str0Size + str1Size + sizeof(wchar_t));
#endif

    memcpy((wchar_t*)(pString->string_body__), str0->string_body__, str0Size);
    memcpy(((uint8_t*)(pString->string_body__)) + str0Size, str1->string_body__, str1Size + sizeof(wchar_t));

    return pString;
}

System_String* System_String_Concat_4(System_Object* arg0, System_Object* arg1)
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

    frame__.str0 = System_String_Concat_3(frame__.str0, frame__.str1);
    il2c_unlink_execution_frame(&frame__);
    return frame__.str0;
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

#if defined(_DEBUG)
    System_String* pString = new_string_internal__(str0Size + str1Size + str2Size + sizeof(wchar_t), __FILE__, __LINE__);
#else
    System_String* pString = new_string_internal__(str0Size + str1Size + str2Size + sizeof(wchar_t));
#endif

    memcpy((wchar_t*)(pString->string_body__), str0->string_body__, str0Size);
    memcpy(((uint8_t*)(pString->string_body__)) + str0Size, str1->string_body__, str1Size);
    memcpy(((uint8_t*)(pString->string_body__)) + str0Size + str1Size, str2->string_body__, str2Size + sizeof(wchar_t));

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

#if defined(_DEBUG)
    System_String* pString = new_string_internal__(newSize, __FILE__, __LINE__);
#else
    System_String* pString = new_string_internal__(newSize);
#endif

    memcpy((wchar_t*)(pString->string_body__), this__->string_body__ + startIndex, newSize);

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

#if defined(_DEBUG)
    System_String* pString = new_string_internal__(newSize + sizeof(wchar_t), __FILE__, __LINE__);
#else
    System_String* pString = new_string_internal__(newSize + sizeof(wchar_t));
#endif

    memcpy((wchar_t*)(pString->string_body__), this__->string_body__ + startIndex, newSize);
    ((wchar_t*)(pString->string_body__))[length] = L'\0';

    return pString;
}

wchar_t System_String_get_Chars(System_String* this__, int32_t index)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->string_body__ != NULL);

    // TODO: Improvement
    if ((index < 0) || (index >= (int32_t)il2c_wcslen(this__->string_body__)))
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

    return il2c_wcscmp(lhs->string_body__, rhs->string_body__) == 0;
}

bool System_String_op_Inequality(System_String* lhs, System_String* rhs)
{
    // TODO: ArgumentNullException
    il2c_assert(lhs != NULL);
    il2c_assert(rhs != NULL);

    il2c_assert(lhs->string_body__ != NULL);
    il2c_assert(rhs->string_body__ != NULL);

    return il2c_wcscmp(lhs->string_body__, rhs->string_body__) != 0;
}

////////////////////////////////////////////////////////
// System.String.Format() common functions.

typedef struct System_String_InternalFormatState
{
    // Total formatted string length.
    uint32_t length;

    // The arguments count.
    uint32_t argumentCount;

    // The arguments.
    System_Object** ppArgs;

    // The string converted arguments by System.Object.ToString().
    System_String** ppStringArgs;

    // String storing buffer.
    wchar_t* pWriteTarget;
} System_String_InternalFormatState;

static bool System_String_InternalFormatPrepareWriter(
    const wchar_t* pFrom, uint32_t length, void* pState)
{
    il2c_assert(pFrom != NULL);
    il2c_assert(pState != NULL);

    System_String_InternalFormatState* p = pState;
    il2c_assert(p->pWriteTarget == NULL);

    p->length += length;

    return true;
}

static bool System_String_InternalFormatPrepareArgumentWriter(
    uint32_t argumentIndex, void* pState)
{
    il2c_assert(argumentIndex >= 0);
    il2c_assert(pState != NULL);

    System_String_InternalFormatState* p = pState;
    il2c_assert(p->pWriteTarget == NULL);

    if (argumentIndex >= p->argumentCount)
    {
        return false;
    }

    System_String** ppStringArg = &p->ppStringArgs[argumentIndex];
    if (*ppStringArg == NULL)
    {
        void* pArg = p->ppArgs[argumentIndex];
        if (pArg != NULL)
        {
            System_Object* pAdjustedReference = il2c_adjusted_reference(pArg);
            *ppStringArg = pAdjustedReference->vptr0__->ToString(pAdjustedReference);
        }
        else
        {
            *ppStringArg = System_String_Empty;
        }
    }

    p->length += (uint32_t)il2c_wcslen((*ppStringArg)->string_body__);

    return true;
}

static bool System_String_InternalFormatWriter(
    const wchar_t* pFrom, uint32_t length, void* pState)
{
    il2c_assert(pFrom != NULL);
    il2c_assert(pState != NULL);

    System_String_InternalFormatState* p = pState;
    il2c_assert(p->pWriteTarget != NULL);

    while (length > 0)
    {
        *(p->pWriteTarget)++ = *pFrom++;
        length--;
    }

    return true;
}

static bool System_String_InternalFormatArgumentWriter(
    uint32_t argumentIndex, void* pState)
{
    il2c_assert(pState != NULL);

    System_String_InternalFormatState* p = pState;
    il2c_assert(p->pWriteTarget != NULL);
    il2c_assert(argumentIndex < p->argumentCount);

    System_String* pStringArg = p->ppStringArgs[argumentIndex];
    il2c_assert(pStringArg != NULL);
    il2c_assert(pStringArg->string_body__ != NULL);

    const wchar_t* pFrom = pStringArg->string_body__;
    while (1)
    {
        const wchar_t ch = *pFrom++;
        if (ch == L'\0')
        {
            break;
        }
        *(p->pWriteTarget)++ = ch;
    }

    return true;
}

static bool System_String_InternalFormat(
    System_String** ppString, System_String* pFormat,
    uint32_t argumentCount, System_Object** ppArgs, System_String** ppStringArgs)
{
    il2c_assert(ppString != NULL);
    il2c_assert(pFormat != NULL);
    il2c_assert(pFormat->string_body__ != NULL);
    il2c_assert(argumentCount >= 0);
    il2c_assert(ppArgs != NULL);
    il2c_assert(ppStringArgs != NULL);

    System_String_InternalFormatState state = { 0 };
    state.argumentCount = argumentCount;
    state.ppArgs = ppArgs;
    state.ppStringArgs = ppStringArgs;

    /////////////////////////////////////////////////
    // Step 1. Calculate formatted string length.

    if (!il2c_format_string__(
        pFormat->string_body__,
        System_String_InternalFormatPrepareWriter,
        System_String_InternalFormatPrepareArgumentWriter,
        &state))
    {
        return false;
    }

    /////////////////////////////////////////////////
    // Step 2. Allocate once System.String

#if defined(_DEBUG)
    *ppString = new_string_internal__((state.length + 1) * sizeof(wchar_t), __FILE__, __LINE__);
#else
    *ppString = new_string_internal__((state.length + 1) * sizeof(wchar_t));
#endif

    state.pWriteTarget = (wchar_t*)((*ppString)->string_body__);

    /////////////////////////////////////////////////
    // Step 3. Write formatted string into System.String

#if defined(_DEBUG)
    bool result =
#endif
    il2c_format_string__(
        pFormat->string_body__,
        System_String_InternalFormatWriter,
        System_String_InternalFormatArgumentWriter,
        &state);
    il2c_assert(result);

    *state.pWriteTarget = L'\0';

    return true;
}

////////////////////////////////////////////////////////
// System.String.Format()

System_String* System_String_Format(
    System_String* format, System_Object* arg0)
{
    // TODO: ArgumentNullException
    il2c_assert(format != NULL);
    il2c_assert(format->string_body__ != NULL);

    struct System_String_Format_EXECUTION_FRAME
    {
        IL2C_EXECUTION_FRAME* pNext__;
        const uint16_t objRefCount__;
        const uint16_t valueCount__;
        System_String* pString;
        System_String* pStringArg0;
    } frame__ = { NULL, 2 };
    il2c_link_execution_frame(&frame__);

    if (!System_String_InternalFormat(
        &frame__.pString, format, 1, &arg0, &frame__.pStringArg0))
    {
        il2c_throw_formatexception__();
    }

    il2c_unlink_execution_frame(&frame__);
    return frame__.pString;
}

System_String* System_String_Format_1(
    System_String* format, System_Object* arg0, System_Object* arg1)
{
    // TODO: ArgumentNullException
    il2c_assert(format != NULL);
    il2c_assert(format->string_body__ != NULL);

    System_Object* pArgs[2];
    pArgs[0] = arg0;
    pArgs[1] = arg1;

    struct System_String_Format1_EXECUTION_FRAME
    {
        IL2C_EXECUTION_FRAME* pNext__;
        const uint16_t objRefCount__;
        const uint16_t valueCount__;
        System_String* pString;
        System_String* pStringArg0;
        System_String* pStringArg1;
    } frame__ = { NULL, 3 };
    il2c_link_execution_frame(&frame__);

    if (!System_String_InternalFormat(
        &frame__.pString, format, 2, pArgs, &frame__.pStringArg0))
    {
        il2c_throw_formatexception__();
    }

    il2c_unlink_execution_frame(&frame__);
    return frame__.pString;
}

System_String* System_String_Format_3(
    System_String* format, System_Object* arg0, System_Object* arg1, System_Object* arg2)
{
    // TODO: ArgumentNullException
    il2c_assert(format != NULL);
    il2c_assert(format->string_body__ != NULL);

    System_Object* pArgs[3];
    pArgs[0] = arg0;
    pArgs[1] = arg1;
    pArgs[2] = arg2;

    struct System_String_Format3_EXECUTION_FRAME
    {
        IL2C_EXECUTION_FRAME* pNext__;
        const uint16_t objRefCount__;
        const uint16_t valueCount__;
        System_String* pString;
        System_String* pStringArg0;
        System_String* pStringArg1;
        System_String* pStringArg2;
    } frame__ = { NULL, 4 };
    il2c_link_execution_frame(&frame__);

    if (!System_String_InternalFormat(
        &frame__.pString, format, 3, pArgs, &frame__.pStringArg0))
    {
        il2c_throw_formatexception__();
    }

    il2c_unlink_execution_frame(&frame__);
    return frame__.pString;
}

System_String* System_String_Format_6(
    System_String* format, il2c_arraytype(System_Object)* args)
{
    // TODO: ArgumentNullException
    il2c_assert(format != NULL);
    il2c_assert(format->string_body__ != NULL);
    il2c_assert(args != NULL);
    il2c_assert(args->Length <= UINT32_MAX);

    typedef struct System_String_Format6_EXECUTION_FRAME
    {
        IL2C_EXECUTION_FRAME* pNext__;
        const uint16_t objRefCount__;
        const uint16_t valueCount__;
        System_String* pString;
        //System_String* pStringArg[n];
    } System_String_Format6_EXECUTION_FRAME;

    intptr_t size = sizeof(System_String_Format6_EXECUTION_FRAME) + args->Length * sizeof(System_String*);
    System_String_Format6_EXECUTION_FRAME* il2c_mcalloc(pFrame, size);
    memset(pFrame, 0, size);
    *((uint16_t*)(&pFrame->objRefCount__)) = (uint16_t)(args->Length + 1);

    il2c_link_execution_frame(pFrame);

    if (!System_String_InternalFormat(
        &pFrame->pString, format, (uint32_t)(args->Length),
        il2c_array_itemptr(args, System_Object*, 0),
        (&pFrame->pString) + 1))
    {
        // Very important, it blocks leaking dynamic allocation frame.
        // TODO: Will lost current execution frame. Maybe not recorded stack frame into the Exception if it holds.
        il2c_unlink_execution_frame(pFrame);
        il2c_mcfree(pFrame);

        il2c_throw_formatexception__();
    }

    System_String* pFormatted = pFrame->pString;

    il2c_unlink_execution_frame(pFrame);
    il2c_mcfree(pFrame);

    return pFormatted;
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
