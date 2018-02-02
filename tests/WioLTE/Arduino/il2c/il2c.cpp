/////////////////////////////////////////////////////////////
// For platform specifics:

#ifdef _WIN32

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <intrin.h>

#define GCALLOC malloc
#define GCFREE free

typedef long interlock_t;

#else

typedef unsigned char interlock_t;
static interlock_t _InterlockedExchange(interlock_t* p, interlock_t v)
{
    interlock_t cv = *p;
    *p = v;
    return cv;
}

static void* _InterlockedExchangePointer(void** p, void* v)
{
    void* cv = *p;
    *p = v;
    return cv;
}

static void* _InterlockedCompareExchangePointer(void** p, void* v, void* c)
{
    void* cv = *p;
    if (cv == c)
    {
        *p = v;
    }
    return cv;
}

#define GCALLOC(size) malloc(size)
#define GCFREE(p) free(p)
#endif

#define INTERLOCKED_EXCHANGE(p, v) (interlock_t)_InterlockedExchange((interlock_t*)p, (interlock_t)v)
#define INTERLOCKED_EXCHANGE_POINTER(p, v) (void*)_InterlockedExchangePointer((void**)p, (void*)v)
#define INTERLOCKED_COMPARE_EXCHANGE_POINTER(p, v, c) (void*)_InterlockedCompareExchangePointer((void**)p, (void*)v, (void*)c)

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <il2c.h>

/////////////////////////////////////////////////////////////

// TODO: Support finalizer
#define GCMARK_NOMARK ((interlock_t)0)
#define GCMARK_LIVE ((interlock_t)1)

struct IL2C_EXECUTION_FRAME
{
    struct IL2C_EXECUTION_FRAME* pNext;
    uint8_t targetCount;
    void** pTargets[];      // We have to track object references.
};

typedef void(*IL2C_MARK_HANDLER)(void*);

struct IL2C_REF_HEADER
{
    struct IL2C_REF_HEADER* pNext;
    IL2C_MARK_HANDLER pMarkHandler;
    interlock_t gcMark;
};

// TODO: Become store to thread local storage
static IL2C_EXECUTION_FRAME* g_pBeginFrame__ = NULL;

static IL2C_REF_HEADER* g_pBeginHeader__ = NULL;

// Part of "pNext".
// HACK: Must arrange structure index to 0.
static const void* g_pTerminator = NULL;

//////////////////////////

void il2c_get_uninitialized_object(
    void** ppReference, uint16_t bodySize, IL2C_MARK_HANDLER pMarkHandler)
{
    assert(ppReference != NULL);
    assert(pMarkHandler != NULL);

    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)GCALLOC(sizeof(IL2C_REF_HEADER) + bodySize);
    void* pReference = pHeader + 1;
    if (bodySize >= 1)
    {
        memset(pReference, 0, bodySize);
    }

    pHeader->pNext = NULL;
    pHeader->pMarkHandler = pMarkHandler;
    pHeader->gcMark = GCMARK_NOMARK;

    // Very important link steps:
    //   Because cause misread on purpose this__ instance is living by concurrent gc's.
    *ppReference = pReference;

    // Safe link both headers.
    while (1)
    {
        // (1)
        IL2C_REF_HEADER* pNext = g_pBeginHeader__;
        // (2)
        pHeader->pNext = pNext;
        // (3)
        if ((IL2C_REF_HEADER*)INTERLOCKED_COMPARE_EXCHANGE_POINTER(
            &g_pBeginHeader__,
            pHeader,
            pNext) == pNext)
        {
            break;
        }
    }

    assert(g_pTerminator == NULL);
}

void il2c_mark_from_handler(void* pReference)
{
    assert(pReference != NULL);

    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)pReference - 1;
    interlock_t currentMark = INTERLOCKED_EXCHANGE(&pHeader->gcMark, GCMARK_LIVE);
    if (currentMark == GCMARK_NOMARK)
    {
        assert(pHeader->pMarkHandler != NULL);
        pHeader->pMarkHandler(pReference);
    }
}

//////////////////////////

void il2c_link_execution_frame(/* EXECUTION_FRAME__* */ void* pNewFrame)
{
    assert(pNewFrame != NULL);

    ((IL2C_EXECUTION_FRAME*)pNewFrame)->pNext = g_pBeginFrame__;
    g_pBeginFrame__ = (IL2C_EXECUTION_FRAME*)pNewFrame;

#ifdef _DEBUG
    IL2C_EXECUTION_FRAME* p = pNewFrame;
    for (uint8_t index = 0; index < p->targetCount; index++)
    {
        assert(*p->pTargets[index] == NULL);
    }
#endif

    assert(g_pTerminator == NULL);
}

void il2c_unlink_execution_frame(/* EXECUTION_FRAME__* */ void* pFrame)
{
    assert(pFrame != NULL);

    g_pBeginFrame__ = ((IL2C_EXECUTION_FRAME*)pFrame)->pNext;

    assert(g_pTerminator == NULL);
}

//////////////////////////

void il2c_step1_clear_gcmark__()
{
    // Clear header marks.
    IL2C_REF_HEADER* pCurrentHeader = g_pBeginHeader__;
    assert(pCurrentHeader != NULL);

    while (pCurrentHeader != NULL)
    {
        pCurrentHeader->gcMark = GCMARK_NOMARK;
        pCurrentHeader = pCurrentHeader->pNext;
    }
}

void il2c_step2_mark_gcmark__()
{
    // Mark headers.
    IL2C_EXECUTION_FRAME* pCurrentFrame = g_pBeginFrame__;
    while (pCurrentFrame != NULL)
    {
        // Traverse current frame.
        uint8_t index;
        for (index = 0; index < pCurrentFrame->targetCount; index++)
        {
            void** ppReference = pCurrentFrame->pTargets[index];
            assert(ppReference != NULL);

            if (*ppReference == NULL)
            {
                continue;
            }

            // Marking process.
            IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)*ppReference - 1;
            interlock_t currentMark = INTERLOCKED_EXCHANGE(&pHeader->gcMark, GCMARK_LIVE);
            if (currentMark == GCMARK_NOMARK)
            {
                assert(pHeader->pMarkHandler != NULL);
                pHeader->pMarkHandler(*ppReference);
            }
        }

        pCurrentFrame = pCurrentFrame->pNext;
    }
}

void il2c_step3_sweep_garbage__()
{
    // Sweep garbage if gcmark isn't marked.
    IL2C_REF_HEADER** ppUnlinkTarget = &g_pBeginHeader__;
    IL2C_REF_HEADER* pCurrentHeader = g_pBeginHeader__;
    while (pCurrentHeader != NULL)
    {
        IL2C_REF_HEADER* pNext = pCurrentHeader->pNext;
        if (pCurrentHeader->gcMark != GCMARK_LIVE)
        {
            // Very important link steps: because cause misread on purpose this__ instance is living.
            *ppUnlinkTarget = pNext;

            // Heap discarded
            GCFREE(pCurrentHeader);

            pCurrentHeader = pNext;
        }
        else
        {
            ppUnlinkTarget = &pCurrentHeader->pNext;
            pCurrentHeader = pNext;
        }

        assert(g_pTerminator == NULL);
    }
}

//////////////////////////

void il2c_collect()
{
    il2c_step1_clear_gcmark__();
    il2c_step2_mark_gcmark__();
    il2c_step3_sweep_garbage__();
}

void il2c_initialize()
{
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF);
#endif

    assert(g_pTerminator == NULL);

    g_pBeginFrame__ = (IL2C_EXECUTION_FRAME*)g_pTerminator;
    g_pBeginHeader__ = (IL2C_REF_HEADER*)g_pTerminator;
}

void il2c_shutdown()
{
    il2c_collect();

#ifdef _WIN32
    _CrtDumpMemoryLeaks();
#endif
}

/////////////////////////////////////////////////////////////

void __System_Object_NEW__(System_Object** ppReference)
{
    il2c_get_uninitialized_object(
        (void**)ppReference, 0, __System_Object_MARK_HANDLER__);
    System_Object__ctor(*ppReference);
}
