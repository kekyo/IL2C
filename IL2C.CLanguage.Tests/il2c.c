#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <il2c.h>

#define GCALLOC(size) malloc(size)
#define GCFREE(p) free(p)

/////////////////////////////////////////////////////////////

// TODO: Support finalizer
#define GCMARK_NOMARK ((uint8_t)0)
#define GCMARK_LIVE ((uint8_t)1)

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
    uint8_t gcMark;
};

static __REF_HEADER__* g_pBeginHeader__ = NULL;

// Part of "pNext".
// HACK: Must arrangement structure index 0.
static const void* g_pTerminator = NULL;

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

    // Very important link steps: because cause misread on purpose this instance is living.
    // 1st: Link from root chain
    *ppReference = pReference;

    // TODO: 2nd and 3rd operation must use atomic exchange operator.

    // 2nd: Link chain to next header
    pHeader->pNext = g_pBeginHeader__;

    // 3rd: Link chain from beginning pointer
    g_pBeginHeader__ = pHeader;

    assert(g_pTerminator == NULL);
}

void __gc_mark_from_handler__(void* pReference)
{
    assert(pReference != NULL);

    __REF_HEADER__* pHeader = (__REF_HEADER__*)pReference - 1;
    if (pHeader->gcMark == GCMARK_NOMARK)
    {
        pHeader->gcMark = GCMARK_LIVE;

        assert(pHeader->pMarkHandler != NULL);
        pHeader->pMarkHandler(pReference);
    }
}

//////////////////////////

// TODO: Become store to thread local storage
static __EXECUTION_FRAME__* g_pBeginFrame__ = NULL;

void __gc_link_execution_frame__(/* EXECUTION_FRAME__* */ void* pNewFrame)
{
    assert(pNewFrame != NULL);

    ((__EXECUTION_FRAME__*)pNewFrame)->pNext = g_pBeginFrame__;
    g_pBeginFrame__ = pNewFrame;

#ifdef _DEBUG
    __EXECUTION_FRAME__* p = pNewFrame;
    for (uint8_t index = 0; index < p->targetCount; index++)
    {
        assert(*(p->pTargets[index]) == NULL);
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

void __gc_clear_gcmark__()
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

void __gc_mark_gcmark__()
{
    // Mark headers.
    __EXECUTION_FRAME__* pCurrentFrame = g_pBeginFrame__;
    while (pCurrentFrame != NULL)
    {
        // Traverse current frame.
        for (uint8_t index = 0; index < pCurrentFrame->targetCount; index++)
        {
            void** ppReference = pCurrentFrame->pTargets[index];
            assert(ppReference != NULL);

            if (*ppReference == NULL)
            {
                continue;
            }

            // Marking process.
            __REF_HEADER__* pHeader = (__REF_HEADER__*)*ppReference - 1;
            if (pHeader->gcMark == GCMARK_NOMARK)
            {
                pHeader->gcMark = GCMARK_LIVE;

                assert(pHeader->pMarkHandler != NULL);
                pHeader->pMarkHandler(*ppReference);
            }
        }

        pCurrentFrame = pCurrentFrame->pNext;
    }
}

void __gc_sweep_garbage__()
{
    // Sweep garbage if gcmark isn't marked.
    assert(g_pBeginHeader__ != NULL);
    __REF_HEADER__** ppLastNext = &g_pBeginHeader__->pNext;
    assert(ppLastNext != NULL);

    while (1)
    {
        __REF_HEADER__* pCurrentHeader = (*ppLastNext)->pNext;
        if (pCurrentHeader == NULL)
        {
            break;
        }

        __REF_HEADER__* pNext = pCurrentHeader->pNext;
        if (pCurrentHeader->gcMark != GCMARK_LIVE)
        {
            // Very important link steps: because cause misread on purpose this instance is living.
            (*ppLastNext)->pNext = pNext;

            // Heap discarded
            GCFREE(pCurrentHeader);
        }
        else
        {
            ppLastNext = &pCurrentHeader->pNext;
        }

        assert(g_pTerminator == NULL);
    }
}

void __gc_initialize__()
{
    assert(g_pTerminator == NULL);

    g_pBeginFrame__ = (__EXECUTION_FRAME__*)g_pTerminator;
    g_pBeginHeader__ = (__REF_HEADER__*)g_pTerminator;
}

/////////////////////////////////////////////////////////////

void System_Object__ctor(System_Object* __this)
{
}

void __System_Object_MARK_HANDLER__(void* pReference)
{
}

void __System_Object_NEW__(System_Object** ppReference)
{
    __gc_get_uninitialized_object__(
        (void**)ppReference, 0, __System_Object_MARK_HANDLER__);
    System_Object__ctor(*ppReference);
}
