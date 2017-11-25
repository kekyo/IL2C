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

struct __EXECUTION_FRAME__
{
    struct __EXECUTION_FRAME__* pNext;
    uint8_t targetCount;
    void** pTargets[];      // We have to track object references.
};

typedef void(*__MARK_HANDLER__)(void*);

struct __REF_HEADER__
{
    struct __REF_HEADER__* pNext;
    __MARK_HANDLER__ pMarkHandler;
    interlock_t gcMark;
};

// TODO: Become store to thread local storage
static __EXECUTION_FRAME__* g_pBeginFrame__ = NULL;

static __REF_HEADER__* g_pBeginHeader__ = NULL;

// Part of "pNext".
// HACK: Must arrange structure index to 0.
static const void* g_pTerminator = NULL;

//////////////////////////

void __gc_get_uninitialized_object__(
    void** ppReference, uint16_t bodySize, __MARK_HANDLER__ pMarkHandler)
{
    assert(ppReference != NULL);
    assert(pMarkHandler != NULL);

    __REF_HEADER__* pHeader = (__REF_HEADER__*)GCALLOC(sizeof(__REF_HEADER__) + bodySize);
    void* pReference = pHeader + 1;
    if (bodySize >= 1)
    {
        memset(pReference, 0, bodySize);
    }

    pHeader->pNext = NULL;
    pHeader->pMarkHandler = pMarkHandler;
    pHeader->gcMark = GCMARK_NOMARK;

    // Very important link steps:
    //   Because cause misread on purpose this instance is living by concurrent gc's.
    *ppReference = pReference;

    // Safe link both headers.
    while (1)
    {
        // (1)
        __REF_HEADER__* pNext = g_pBeginHeader__;
        // (2)
        pHeader->pNext = pNext;
        // (3)
        if ((__REF_HEADER__*)INTERLOCKED_COMPARE_EXCHANGE_POINTER(
            &g_pBeginHeader__,
            pHeader,
            pNext) == pNext)
        {
            break;
        }
    }

    assert(g_pTerminator == NULL);
}

void __gc_mark_from_handler__(void* pReference)
{
    assert(pReference != NULL);

    __REF_HEADER__* pHeader = (__REF_HEADER__*)pReference - 1;
    interlock_t currentMark = INTERLOCKED_EXCHANGE(&pHeader->gcMark, GCMARK_LIVE);
    if (currentMark == GCMARK_NOMARK)
    {
        assert(pHeader->pMarkHandler != NULL);
        pHeader->pMarkHandler(pReference);
    }
}

//////////////////////////

void __gc_link_execution_frame__(/* EXECUTION_FRAME__* */ void* pNewFrame)
{
    assert(pNewFrame != NULL);

    ((__EXECUTION_FRAME__*)pNewFrame)->pNext = g_pBeginFrame__;
    g_pBeginFrame__ = (__EXECUTION_FRAME__*)pNewFrame;

#ifdef _DEBUG
    __EXECUTION_FRAME__* p = pNewFrame;
    for (uint8_t index = 0; index < p->targetCount; index++)
    {
        assert(*p->pTargets[index] == NULL);
    }
#endif

    assert(g_pTerminator == NULL);
}

void __gc_unlink_execution_frame__(/* EXECUTION_FRAME__* */ void* pFrame)
{
    assert(pFrame != NULL);

    g_pBeginFrame__ = ((__EXECUTION_FRAME__*)pFrame)->pNext;

    assert(g_pTerminator == NULL);
}

//////////////////////////

void __gc_step1_clear_gcmark__()
{
    // Clear header marks.
    __REF_HEADER__* pCurrentHeader = g_pBeginHeader__;
    assert(pCurrentHeader != NULL);

    while (pCurrentHeader != NULL)
    {
        pCurrentHeader->gcMark = GCMARK_NOMARK;
        pCurrentHeader = pCurrentHeader->pNext;
    }
}

void __gc_step2_mark_gcmark__()
{
    // Mark headers.
    __EXECUTION_FRAME__* pCurrentFrame = g_pBeginFrame__;
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
            __REF_HEADER__* pHeader = (__REF_HEADER__*)*ppReference - 1;
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

void __gc_step3_sweep_garbage__()
{
    // Sweep garbage if gcmark isn't marked.
    __REF_HEADER__** ppUnlinkTarget = &g_pBeginHeader__;
    __REF_HEADER__* pCurrentHeader = g_pBeginHeader__;
    while (pCurrentHeader != NULL)
    {
        __REF_HEADER__* pNext = pCurrentHeader->pNext;
        if (pCurrentHeader->gcMark != GCMARK_LIVE)
        {
            // Very important link steps: because cause misread on purpose this instance is living.
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

void __gc_collect__()
{
    __gc_step1_clear_gcmark__();
    __gc_step2_mark_gcmark__();
    __gc_step3_sweep_garbage__();
}

void __gc_initialize__()
{
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF);
#endif

    assert(g_pTerminator == NULL);

    g_pBeginFrame__ = (__EXECUTION_FRAME__*)g_pTerminator;
    g_pBeginHeader__ = (__REF_HEADER__*)g_pTerminator;
}

void __gc_shutdown__()
{
    __gc_collect__();

#ifdef _WIN32
    _CrtDumpMemoryLeaks();
#endif
}

/////////////////////////////////////////////////////////////

void __System_Object_NEW__(System_Object** ppReference)
{
    __gc_get_uninitialized_object__(
        (void**)ppReference, 0, __System_Object_MARK_HANDLER__);
    System_Object__ctor(*ppReference);
}
