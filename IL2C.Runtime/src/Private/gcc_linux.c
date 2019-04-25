#include <il2c_private.h>

//////////////////////////////////////////////////
// GCC

// Linux
#if defined(__GNUC__) && defined(__linux__)

#include <math.h>
#include <pthread.h>

double il2c_fmod(double lhs, double rhs)
{
    return fmod(lhs, rhs);
}

static const wchar_t* g_pHexChars = L"0123456789abcdef";

#define IL2C_DECLARE_INTTOW(name, typeName, utypeName, bufferLength, intOper) \
    wchar_t* name(typeName value, wchar_t* buffer, int radix) { \
        wchar_t temp[bufferLength]; \
        wchar_t *pTemp = &temp[bufferLength - 1]; \
        wchar_t *pBuffer = buffer; \
        utypeName v; \
        *pTemp-- = L'\0'; \
        switch (radix) { \
        case 16: \
            v = (utypeName)value; \
            do { \
                *pTemp-- = g_pHexChars[v % 16]; \
                v /= 16; \
            } while (il2c_likely__(v)); \
            break; \
        default: \
            intOper \
            v = (utypeName)value; \
            do { \
                *pTemp-- = (wchar_t)(v % 10 + L'0'); \
                v /= 10; \
            } while (il2c_likely__(v)); \
            break; \
        } \
        do { \
            *pBuffer++ = *++pTemp; \
        } while (il2c_likely__(*pTemp)); \
        return buffer; \
    }

#define IL2C_DECLARE_INTTOW_INT32_OPERATOR \
    if (il2c_unlikely__(value == INT32_MIN)) { \
        il2c_wcscpy(buffer, L"-2147483648"); \
        return buffer; \
    } \
    if (value < 0) { \
        *pBuffer++ = L'-'; \
        value = -value; \
    }

#define IL2C_DECLARE_INTTOW_INT64_OPERATOR \
    if (il2c_unlikely__(value == INT64_MIN)) { \
        il2c_wcscpy(buffer, L"-9223372036854775808"); \
        return buffer; \
    } \
    if (value < 0) { \
        *pBuffer++ = L'-'; \
        value = -value; \
    }

#define IL2C_DECLARE_INTTOW_UINT_OPERATOR

IL2C_DECLARE_INTTOW(il2c_i32tow, int32_t, uint32_t, 14, IL2C_DECLARE_INTTOW_INT32_OPERATOR)
IL2C_DECLARE_INTTOW(il2c_u32tow, uint32_t, uint32_t, 14, IL2C_DECLARE_INTTOW_UINT_OPERATOR)
IL2C_DECLARE_INTTOW(il2c_i64tow, int64_t, uint64_t, 24, IL2C_DECLARE_INTTOW_INT64_OPERATOR)
IL2C_DECLARE_INTTOW(il2c_u64tow, uint64_t, uint64_t, 24, IL2C_DECLARE_INTTOW_UINT_OPERATOR)

#if defined(IL2C_USE_DEBUG_HEAP)
typedef volatile struct IL2C_DEBUG_HEAP_DECL
{
    size_t Size;
    const char* pFile;
    int32_t Line;
    interlock_t Index;
    int32_t AllocateId;
    int32_t FreeId;
    uintptr_t HeadGuardBytes;
    //uint8_t Body[];
    //uintptr_t TailGuardBytes;
} IL2C_DEBUG_HEAP;

// https://en.wikipedia.org/wiki/Magic_number_(programming)#Magic_debug_values
#define IL2C_HEAP_GUARD_BYTES ((uintptr_t)0xfdfdfdfdfdfdfdfdULL)

static interlock_t g_HeapAllocationIndex = 0;
int64_t g_HeapBreakAlloc__ = INT64_MAX;

// Simple heap corruption detector.
#if defined(IL2C_USE_LINE_INFORMATION)
void* il2c_malloc(size_t size, const char* pFile, int32_t line)
#else
void* il2c_malloc(size_t size)
#endif
{
#if defined(_MSC_VER) && defined(WIN32) && defined(IL2C_USE_LINE_INFORMATION)
    IL2C_DEBUG_HEAP* p0 = _malloc_dbg(sizeof(IL2C_DEBUG_HEAP) + size + sizeof(uintptr_t), _NORMAL_BLOCK, pFile, line);
#else
    IL2C_DEBUG_HEAP* p0 = malloc(sizeof(IL2C_DEBUG_HEAP) + size + sizeof(uintptr_t));
#endif

    if (p0 == NULL)
    {
        return NULL;
    }

    // Size
    p0->Size = size;

#if defined(IL2C_USE_LINE_INFORMATION)
    // File, Line
    p0->pFile = pFile;
    p0->Line = line;
#else
    p0->pFile = NULL;
    p0->Line = -1;
#endif

    // Allocation index
    const interlock_t index = il2c_iinc(&g_HeapAllocationIndex);
    il2c_assert(index != g_HeapBreakAlloc__);
    p0->Index = index;

    // Thread Id
    p0->AllocateId = il2c_get_current_thread_id__();
    p0->FreeId = INT32_MIN;

    // Head guard bytes
    p0->HeadGuardBytes = IL2C_HEAP_GUARD_BYTES;

    // Body (uninitialized bytes)
    void* p = (void*)(p0 + 1);
    memset(p, 0xcc, size);

    // Tail guard bytes
    uintptr_t * pt = (uintptr_t*)(((uint8_t*)p) + size);
    *pt = IL2C_HEAP_GUARD_BYTES;

    return p;
}

void il2c_free(void* p)
{
    if (il2c_likely__(p))
    {
        IL2C_DEBUG_HEAP* p0 = p;
        p0--;

        // Thread Id
        p0->FreeId = il2c_get_current_thread_id__();

        // Front guard bytes
        il2c_assert(p0->HeadGuardBytes == IL2C_HEAP_GUARD_BYTES);

        // Tail guard bytes
        const uintptr_t * pt = (const uintptr_t*)(((const uint8_t*)p) + p0->Size);
        il2c_assert(*pt == IL2C_HEAP_GUARD_BYTES);

        // Overwrite invalid signature to target memory.
        // (For debugging purpose same as VC++ runtime.)
        memset(p, 0xdd, p0->Size);

        free((void*)p0);
    }
}
#endif

#include <time.h>

void il2c_sleep(uint32_t milliseconds)
{
    struct timespec tm1 = { (time_t)(milliseconds) / 1000, ((long)(milliseconds) % 1000) * 1000 * 1000 };
    struct timespec tm2;
    while (1)
    {
        if (nanosleep(&tm1, &tm2) == 0) break;
        if (nanosleep(&tm2, &tm1) == 0) break;
    }
}

IL2C_TLS_INDEX il2c_tls_alloc(void)
{
    pthread_key_t key;
    int result = pthread_key_create(&key, NULL);
    il2c_assert(result == 0);
    ((void)result);

    return key;
}

void* il2c_get_tls_value(IL2C_TLS_INDEX tlsIndex)
{
    return pthread_getspecific((pthread_key_t)tlsIndex);
}

void il2c_set_tls_value(IL2C_TLS_INDEX tlsIndex, void* value)
{
    int result = pthread_setspecific((pthread_key_t)tlsIndex, value);
    il2c_assert(result == 0);
    ((void)result);
}

intptr_t il2c_create_thread__(IL2C_THREAD_ENTRY_POINT_TYPE entryPoint, IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE parameter)
{
    pthread_t handle;

    int result = pthread_create(&handle, NULL, entryPoint, parameter);
    il2c_assert(result == 0);
    ((void)result);

    return (intptr_t)handle;
}

void il2c_join_thread__(intptr_t handle)
{
    il2c_assert(handle != 0);

    void* value;
    pthread_join((pthread_t)handle, &value);
}

void il2c_initialize_monitor_lock__(IL2C_MONITOR_LOCK* pLock)
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(pLock, &attr);
}

// NOT Azure Sphere
#if !defined(__AZURE_SPHERE__)

#if defined(IL2C_USE_RUNTIME_DEBUG_LOG)
void il2c_runtime_debug_log(const wchar_t* message)
{
    // TODO: syslog
    fputws(message, stderr);
}
#endif

void il2c_write(const wchar_t* s)
{
    il2c_assert(s != NULL);
    fputws(s, stdout);
}

void il2c_writeline(const wchar_t* s)
{
    il2c_assert(s != NULL);
    fputws(s, stdout);
    fputws(L"\n", stdout);
}

bool il2c_readline(wchar_t* buffer, int32_t length)
{
    il2c_assert(buffer != NULL);
    il2c_assert(length >= 1);

    const wchar_t* p = fgetws(buffer, length - 1, stdin);
    if (p != NULL)
    {
        wchar_t* cr = wcschr(buffer, L'\r');
        wchar_t* lf = wcschr(buffer, L'\n');
        if ((cr != NULL) || (lf != NULL))
        {
            if ((cr != NULL) && (lf != NULL) && ((lf - cr) == 1))
            {
                *cr = L'\0';
                return true;
            }
            if (lf != NULL)
            {
                *lf = L'\0';
                return true;
            }
            if (cr != NULL)
            {
                *cr = L'\0';
                return true;
            }
        }
    }

    return false;
}

#endif

void il2c_initialize(void)
{
    il2c_initialize__();
}

void il2c_shutdown(void)
{
    il2c_shutdown__();
}

#endif
