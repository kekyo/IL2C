#include <il2c_private.h>

#include "../Platform/debugbreak.h"

///////////////////////////////////////////////////////
// Another special runtime helper functions

#if defined(IL2C_USE_LINE_INFORMATION)
void il2c_break__(const char* pFile, int line)
#else
void il2c_break__(void)
#endif
{
    debug_break();
}

///////////////////////////////////////////////////////
// Low level debugger formatted writer

#if defined(IL2C_USE_RUNTIME_DEBUG_LOG)

typedef struct IL2C_RUNTIME_DEBUG_LOG_FORMAT_STATE_DECL
{
    va_list va;
    uint16_t argumentCount;
    uint16_t length;
    wchar_t* pBuffer;
} IL2C_RUNTIME_DEBUG_LOG_FORMAT_STATE;

static int8_t il2c_runtime_debug_log_format_writer_step1__(
    const wchar_t* pTokenFrom, uint32_t tokenLength, void* pState)
{
    IL2C_RUNTIME_DEBUG_LOG_FORMAT_STATE* p = pState;

    p->length = (uint16_t)(p->length + tokenLength);
    return IL2C_STRING_FORMAT_SUCCEEDED;
}

static int8_t il2c_runtime_debug_log_format_argument_writer_step1__(
    uint16_t argumentIndex, const wchar_t* pFormatFrom, uint32_t formatLength, void* pState)
{
    IL2C_RUNTIME_DEBUG_LOG_FORMAT_STATE* p = pState;
    wchar_t buffer[24];

    if (il2c_unlikely__((argumentIndex != (p->argumentCount++)) || (formatLength != 1)))
    {
        return IL2C_STRING_FORMAT_INVALID;
    }

    switch (*pFormatFrom)
    {
    case L'd':
        {
            int32_t value = va_arg(p->va, int32_t);
            il2c_i32tow(value, buffer, 10);
        }
        break;
    case L'u':
        {
            uint32_t value = va_arg(p->va, uint32_t);
            il2c_u32tow(value, buffer, 10);
        }
        break;
    case L'x':
        {
            uint32_t value = va_arg(p->va, uint32_t);
            il2c_u32tow(value, buffer, 16);
        }
        break;
    case L'D':
        {
            int64_t value = va_arg(p->va, int64_t);
            il2c_i64tow(value, buffer, 10);
        }
        break;
    case L'U':
        {
            uint64_t value = va_arg(p->va, uint64_t);
            il2c_u64tow(value, buffer, 10);
        }
        break;
    case L'X':
        {
            uint64_t value = va_arg(p->va, uint64_t);
            il2c_u64tow(value, buffer, 16);
        }
        break;
    case L'p':
        {
            uintptr_t value = va_arg(p->va, uintptr_t);
            il2c_u64tow(value, buffer, 16);
        }
        break;
    case L's':
        {
            const char* pStr = va_arg(p->va, const char*);
            p->length = (uint16_t)(strlen(pStr) + p->length);
        }
        return IL2C_STRING_FORMAT_SUCCEEDED;
    case L'S':
        {
            const wchar_t* pStr = va_arg(p->va, const wchar_t*);
            p->length = (uint16_t)(il2c_wcslen(pStr) + p->length);
        }
        return IL2C_STRING_FORMAT_SUCCEEDED;
    default:
        return IL2C_STRING_FORMAT_INVALID;
    }

    p->length = (uint16_t)(il2c_wcslen(buffer) + p->length);
    return IL2C_STRING_FORMAT_SUCCEEDED;
}

static int8_t il2c_runtime_debug_log_format_writer_step2__(
    const wchar_t* pTokenFrom, uint32_t tokenLength, void* pState)
{
    IL2C_RUNTIME_DEBUG_LOG_FORMAT_STATE* p = pState;

    memcpy(p->pBuffer, pTokenFrom, tokenLength * sizeof(wchar_t));
    p->pBuffer += tokenLength;

    return 0;
}

static int8_t il2c_runtime_debug_log_format_argument_writer_step2__(
    uint16_t argumentIndex, const wchar_t* pFormatFrom, uint32_t formatLength, void* pState)
{
    IL2C_RUNTIME_DEBUG_LOG_FORMAT_STATE* p = pState;
    wchar_t buffer[24];
    uint16_t length;

    switch (*pFormatFrom)
    {
    case L'd':
        {
            int32_t value = va_arg(p->va, int32_t);
            il2c_i32tow(value, buffer, 10);
        }
        break;
    case L'u':
        {
            uint32_t value = va_arg(p->va, uint32_t);
            il2c_u32tow(value, buffer, 10);
        }
        break;
    case L'x':
        {
            uint32_t value = va_arg(p->va, uint32_t);
            il2c_u32tow(value, buffer, 16);
        }
        break;
    case L'D':
        {
            int64_t value = va_arg(p->va, int64_t);
            il2c_i64tow(value, buffer, 10);
        }
        break;
    case L'U':
        {
            uint64_t value = va_arg(p->va, uint64_t);
            il2c_u64tow(value, buffer, 10);
        }
        break;
    case L'X':
        {
            uint64_t value = va_arg(p->va, uint64_t);
            il2c_u64tow(value, buffer, 16);
        }
        break;
    case L'p':
        {
            uintptr_t value = va_arg(p->va, uintptr_t);
            il2c_u64tow(value, buffer, 16);
        }
        break;
    case L's':
        {
            const char* pStr = va_arg(p->va, const char*);
            while (*pStr != '\0')
            {
                *p->pBuffer++ = (wchar_t)*pStr++;
            }
        }
        return IL2C_STRING_FORMAT_SUCCEEDED;
    case L'S':
        {
            const wchar_t* pStr = va_arg(p->va, const wchar_t*);
            while (*pStr != L'\0')
            {
                *p->pBuffer++ = *pStr++;
            }
        }
        return IL2C_STRING_FORMAT_SUCCEEDED;
    default:
        return IL2C_STRING_FORMAT_INVALID;
    }

    length = (uint16_t)il2c_wcslen(buffer);
    memcpy(p->pBuffer, buffer, length * sizeof(wchar_t));
    p->pBuffer += length;
    return IL2C_STRING_FORMAT_SUCCEEDED;
}

void il2c_runtime_debug_log_format(const wchar_t* format, ...)
{
    IL2C_RUNTIME_DEBUG_LOG_FORMAT_STATE state = { 0 };

    va_start(state.va, format);

    int8_t result = il2c_format_string__(
        format,
        il2c_runtime_debug_log_format_writer_step1__,
        il2c_runtime_debug_log_format_argument_writer_step1__,
        &state);
    if (il2c_likely__(result == IL2C_STRING_FORMAT_SUCCEEDED))
    {
        il2c_mcalloc(wchar_t, pBuffer, (state.length + 3U) * sizeof(wchar_t));
        state.pBuffer = pBuffer;

        va_end(state.va);
        va_start(state.va, format);

        result = il2c_format_string__(
            format,
            il2c_runtime_debug_log_format_writer_step2__,
            il2c_runtime_debug_log_format_argument_writer_step2__,
            &state);
        if (il2c_likely__(result == IL2C_STRING_FORMAT_SUCCEEDED))
        {
            *state.pBuffer++ = L'\r';
            *state.pBuffer++ = L'\n';
            *state.pBuffer = L'\0';
            il2c_runtime_debug_log(pBuffer);
        }

        il2c_mcfree(pBuffer);
    }

    va_end(state.va);
}

#endif
