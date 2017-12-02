/////////////////////////////////////////////////////////////
// For platform specifics:

#ifdef _WIN32

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <intrin.h>

#define GCALLOC malloc
#define GCFREE free

#include <stdint.h>

typedef long interlock_t;

#else

#include <stdint.h>

typedef uint8_t interlock_t;

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
    __RUNTIME_TYPE__ type;
    interlock_t gcMark;
};

// TODO: Become store to thread local storage
static __EXECUTION_FRAME__* g_pBeginFrame__ = NULL;

static __REF_HEADER__* g_pBeginHeader__ = NULL;

//////////////////////////

void __gc_get_uninitialized_object__(void** ppReference, __RUNTIME_TYPE__ type)
{
    assert(ppReference != NULL);
    assert(type != NULL);

    __REF_HEADER__* pHeader = (__REF_HEADER__*)GCALLOC(sizeof(__REF_HEADER__) + type->bodySize);
    if (pHeader == NULL)
    {
        while (1)
        {
            __gc_collect__();

            pHeader = (__REF_HEADER__*)GCALLOC(sizeof(__REF_HEADER__) + type->bodySize);
            if (pHeader != NULL)
            {
                break;
            }

            // throw NotEnoughMemoryException();
            assert(0);
        }
    }

    void* pReference = ((uint8_t*)pHeader)
        + sizeof(__REF_HEADER__);
    if (type->bodySize >= 1)
    {
        memset(pReference, 0, type->bodySize);
    }

    pHeader->pNext = NULL;
    pHeader->type = type;
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
}

void __gc_mark_from_handler__(void* pReference)
{
    assert(pReference != NULL);

    __REF_HEADER__* pHeader = (__REF_HEADER__*)
        (((uint8_t*)pReference) - sizeof(__REF_HEADER__));
    interlock_t currentMark = INTERLOCKED_EXCHANGE(&pHeader->gcMark, GCMARK_LIVE);
    if (currentMark == GCMARK_NOMARK)
    {
        assert(pHeader->type != NULL);
        assert(pHeader->type->pMarkHandler != NULL);
        pHeader->type->pMarkHandler(pReference);
    }
}

//////////////////////////

void __gc_link_execution_frame__(/* EXECUTION_FRAME__* */ void* pNewFrame)
{
    assert(pNewFrame != NULL);

    ((__EXECUTION_FRAME__*)pNewFrame)->pNext = g_pBeginFrame__;
    g_pBeginFrame__ = (__EXECUTION_FRAME__*)pNewFrame;

#ifdef _DEBUG
    {
        __EXECUTION_FRAME__* p = (__EXECUTION_FRAME__*)pNewFrame;
        uint8_t index;
        for (index = 0; index < p->targetCount; index++)
        {
            assert(*p->pTargets[index] == NULL);
        }
    }
#endif
}

void __gc_unlink_execution_frame__(/* EXECUTION_FRAME__* */ void* pFrame)
{
    assert(pFrame != NULL);

    g_pBeginFrame__ = ((__EXECUTION_FRAME__*)pFrame)->pNext;
}

//////////////////////////

void __gc_step1_clear_gcmark__()
{
    // Clear header marks.
    __REF_HEADER__* pCurrentHeader = g_pBeginHeader__;
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
            __REF_HEADER__* pHeader = (__REF_HEADER__*)
                (((uint8_t*)*ppReference) - sizeof(__REF_HEADER__));
            interlock_t currentMark = INTERLOCKED_EXCHANGE(&pHeader->gcMark, GCMARK_LIVE);
            if (currentMark == GCMARK_NOMARK)
            {
                assert(pHeader->type != NULL);
                assert(pHeader->type->pMarkHandler != NULL);
                pHeader->type->pMarkHandler(*ppReference);
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

    g_pBeginFrame__ = NULL;
    g_pBeginHeader__ = NULL;
}

void __gc_shutdown__()
{
    __gc_collect__();

#ifdef _WIN32
    _CrtDumpMemoryLeaks();
#endif
}

/////////////////////////////////////////////////////////////
// Basic type informations

static void __Dummy_MARK_HANDLER__(void* pReference)
{
}

static const __RUNTIME_TYPE_DEF__ __System_Object_RUNTIME_TYPE_DEF__ = {
    "System.Object", 0, __Dummy_MARK_HANDLER__ };
__RUNTIME_TYPE__ __System_Object_RUNTIME_TYPE__ = &__System_Object_RUNTIME_TYPE_DEF__;

static const __RUNTIME_TYPE_DEF__ __System_Byte_RUNTIME_TYPE_DEF__ = {
    "System.Byte", sizeof(uint8_t), __Dummy_MARK_HANDLER__ };
__RUNTIME_TYPE__ __System_Byte_RUNTIME_TYPE__ = &__System_Byte_RUNTIME_TYPE_DEF__;

static const __RUNTIME_TYPE_DEF__ __System_SByte_RUNTIME_TYPE_DEF__ = {
    "System.SByte", sizeof(int8_t), __Dummy_MARK_HANDLER__ };
__RUNTIME_TYPE__ __System_SByte_RUNTIME_TYPE__ = &__System_SByte_RUNTIME_TYPE_DEF__;

static const __RUNTIME_TYPE_DEF__ __System_Int32_RUNTIME_TYPE_DEF__ = {
    "System.Int32", sizeof(int32_t), __Dummy_MARK_HANDLER__ };
__RUNTIME_TYPE__ __System_Int32_RUNTIME_TYPE__ = &__System_Int32_RUNTIME_TYPE_DEF__;

static const __RUNTIME_TYPE_DEF__ __System_Int64_RUNTIME_TYPE_DEF__ = {
    "System.Int64", sizeof(int64_t), __Dummy_MARK_HANDLER__ };
__RUNTIME_TYPE__ __System_Int64_RUNTIME_TYPE__ = &__System_Int64_RUNTIME_TYPE_DEF__;

/////////////////////////////////////////////////////////////

System_Object* __box__(void* pValue, __RUNTIME_TYPE__ type)
{
    void* pBoxed;
    __gc_get_uninitialized_object__(&pBoxed, type);
    memcpy(pBoxed, pValue, type->bodySize);
    return (System_Object*)pBoxed;
}
