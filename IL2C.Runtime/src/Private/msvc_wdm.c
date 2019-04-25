#include <il2c_private.h>

//////////////////////////////////////////////////
// Visual C++

// WDM
#if defined(_MSC_VER) && defined(_WDM)

#include <math.h>

double il2c_fmod(double lhs, double rhs)
{
    return fmod(lhs, rhs);
}

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

#if defined(IL2C_USE_RUNTIME_DEBUG_LOG)
void il2c_runtime_debug_log(const wchar_t* message)
{
    // TODO:
    OutputDebugStringW(message);
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
    _putws(s);
}

bool il2c_readline(wchar_t* buffer, int32_t length)
{
    // Can't read from the default console on the WDM kernel mode driver.
    return false;
}

void il2c_initialize(void)
{
    il2c_initialize__();
}

void il2c_shutdown(void)
{
    il2c_shutdown__();
}

#endif
