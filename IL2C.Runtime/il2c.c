#include "il2c_private.h"

#include "debugbreak.h"

/////////////////////////////////////////////////////////////

// TODO: Support finalizer
#define GCMARK_NOMARK ((interlock_t)1)
#define GCMARK_LIVE ((interlock_t)0)

struct IL2C_EXECUTION_FRAME
{
    IL2C_EXECUTION_FRAME* pNext;
    uint8_t targetCount;
    void** pTargets[1];      // We have to track object references.
};

// TODO: Become store to thread local storage
static IL2C_EXECUTION_FRAME* g_pBeginFrame__ = NULL;

static IL2C_REF_HEADER* g_pBeginHeader__ = NULL;

//////////////////////////

void* il2c_get_uninitialized_object_internal__(
    IL2C_RUNTIME_TYPE_DECL* type, uintptr_t bodySize)
{
    // +----------------------+ <-- pHeader
    // | IL2C_REF_HEADER      |
    // +----------------------+ <-- pReference   -------
    // |          :           |                    ^
    // | (Instance body)      |                    | bodySize
    // |          :           |                    v
    // +----------------------+                  -------

    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)il2c_malloc(sizeof(IL2C_REF_HEADER) + bodySize);
    if (pHeader == NULL)
    {
        while (1)
        {
            il2c_collect();

            pHeader = (IL2C_REF_HEADER*)il2c_malloc(sizeof(IL2C_REF_HEADER) + bodySize);
            if (pHeader != NULL)
            {
                break;
            }

            // throw NotEnoughMemoryException();
            il2c_assert(0);
        }
    }

    void* pReference = ((uint8_t*)pHeader) + sizeof(IL2C_REF_HEADER);
    if (bodySize >= 1)
    {
        // Guarantee cleared body
        il2c_memset(pReference, 0, bodySize);
    }

    pHeader->pNext = NULL;
    pHeader->type = type;
    pHeader->gcMark = GCMARK_NOMARK;

    // Safe link both headers.
    while (1)
    {
        // (1)
        IL2C_REF_HEADER* pNext = g_pBeginHeader__;
        // (2)
        pHeader->pNext = pNext;
        // (3)
        if ((IL2C_REF_HEADER*)il2c_icmpxchgptr(
            &g_pBeginHeader__,
            pHeader,
            pNext) == pNext)
        {
            break;
        }
    }

    return pReference;
}

void* il2c_get_uninitialized_object(IL2C_RUNTIME_TYPE_DECL* type)
{
    il2c_assert(type != NULL);

    // String or Array (IL2C_TYPE_VARIABLE):
    // throw new InvalidProgramException();
    il2c_assert((type->flags & IL2C_TYPE_VARIABLE) == 0);

    return il2c_get_uninitialized_object_internal__(type, type->bodySize);
}

void il2c_mark_from_handler(void* pReference)
{
    il2c_assert(pReference != NULL);

    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)
        (((uint8_t*)pReference) - sizeof(IL2C_REF_HEADER));
    interlock_t currentMark = il2c_icmpxchg(&pHeader->gcMark, GCMARK_LIVE, GCMARK_NOMARK);
    if (currentMark == GCMARK_NOMARK)
    {
        il2c_assert(pHeader->type != NULL);
        il2c_assert(pHeader->type->IL2C_MarkHandler != NULL);
        pHeader->type->IL2C_MarkHandler(pReference);
    }
}

//////////////////////////

void il2c_link_execution_frame(/* EXECUTION_FRAME__* */ void* pNewFrame)
{
    il2c_assert(pNewFrame != NULL);

    ((IL2C_EXECUTION_FRAME*)pNewFrame)->pNext = g_pBeginFrame__;
    g_pBeginFrame__ = (IL2C_EXECUTION_FRAME*)pNewFrame;

#ifdef _DEBUG
    {
        IL2C_EXECUTION_FRAME* p = (IL2C_EXECUTION_FRAME*)pNewFrame;
        uint8_t index;
        for (index = 0; index < p->targetCount; index++)
        {
            il2c_assert(*p->pTargets[index] == NULL);
        }
    }
#endif
}

void il2c_unlink_execution_frame(/* EXECUTION_FRAME__* */ void* pFrame)
{
    il2c_assert(pFrame != NULL);

    // TODO: always collect
    il2c_collect();

    g_pBeginFrame__ = ((IL2C_EXECUTION_FRAME*)pFrame)->pNext;
}

//////////////////////////

void il2c_step1_clear_gcmark__()
{
    // Clear header marks.
    IL2C_REF_HEADER* pCurrentHeader = g_pBeginHeader__;
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
            il2c_assert(ppReference != NULL);

            if (*ppReference == NULL)
            {
                continue;
            }

            // Marking process.
            IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)
                (((uint8_t*)*ppReference) - sizeof(IL2C_REF_HEADER));
            interlock_t currentMark = il2c_icmpxchg(&pHeader->gcMark, GCMARK_LIVE, GCMARK_NOMARK);
            if (currentMark == GCMARK_NOMARK)
            {
                il2c_assert(pHeader->type != NULL);
                il2c_assert(pHeader->type->IL2C_MarkHandler != NULL);

                DEBUG_WRITE("il2c_step2_mark_gcmark__", pHeader->type->pTypeName);

                pHeader->type->IL2C_MarkHandler(*ppReference);
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

            DEBUG_WRITE("il2c_step3_sweep_garbage__", pCurrentHeader->type->pTypeName);

            // Heap discarded
            il2c_free(pCurrentHeader);

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

void il2c_collect()
{
    il2c_step1_clear_gcmark__();
    il2c_step2_mark_gcmark__();
    il2c_step3_sweep_garbage__();
}

void il2c_initialize()
{
#ifdef _CRTDBG_ALLOC_MEM_DF
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF);
#endif

    g_pBeginFrame__ = NULL;
    g_pBeginHeader__ = NULL;
}

void il2c_shutdown()
{
    il2c_collect();

#ifdef _CRTDBG_ALLOC_MEM_DF
    _CrtDumpMemoryLeaks();
#endif
}

/////////////////////////////////////////////////////////////
// Boxing related functions

// +----------------------+
// | IL2C_REF_HEADER      |
// +----------------------+ <-- pBoxed        ---------------------------
// | vptr0__              |                     | System_ValueType    ^
// +----------------------+                   -----------             |
// |        :             |                     ^                     | bodySize
// | (value data)         | Copy from pValue    | type->bodySize      |
// |        :             |                     v                     v
// +----------------------+                   ---------------------------

System_Object* il2c_box1__(
    void* pValue, IL2C_RUNTIME_TYPE_DECL* valueType)
{
    uintptr_t bodySize = sizeof(System_ValueType) + valueType->bodySize;
    System_ValueType* pBoxed = il2c_get_uninitialized_object_internal__(valueType, bodySize);

    // TODO: toType's VTABLE
    pBoxed->vptr0__ = &__System_ValueType_VTABLE__;
    il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), pValue, valueType->bodySize);

    return (System_Object*)pBoxed;
}

System_Object* il2c_box2__(
    void* pValue, IL2C_RUNTIME_TYPE_DECL* valueType, IL2C_RUNTIME_TYPE_DECL* stackType)
{
    // Require type conversion
    il2c_assert(((valueType->flags & IL2C_TYPE_INTEGER) != 0) && ((stackType->flags & IL2C_TYPE_INTEGER) != 0));
    il2c_assert((valueType->bodySize <= 4) && (stackType->bodySize <= 4));
    il2c_assert((valueType->bodySize >= 1) && (stackType->bodySize >= 1));

    // TODO: value type --> interface type

    uintptr_t bodySize = sizeof(System_ValueType) + valueType->bodySize;
    System_ValueType* pBoxed = il2c_get_uninitialized_object_internal__(valueType, bodySize);

    // TODO: toType's VTABLE
    pBoxed->vptr0__ = &__System_ValueType_VTABLE__;

    uint8_t v1;
    uint16_t v2;
    uint16_t v4;
    switch (valueType->bodySize)
    {
    case 1:
        switch (stackType->bodySize)
        {
        case 2:
            v1 = (uint8_t)*(uint16_t*)pValue;
            il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v1, 1);
            break;
        case 4:
            v1 = (uint8_t)*(uint32_t*)pValue;
            il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v1, 1);
            break;
        }
        break;
    case 2:
        switch (stackType->bodySize)
        {
        case 1:
            v2 = *(uint8_t*)pValue;
            il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v2, 2);
            break;
        case 4:
            v2 = (uint16_t)*(uint32_t*)pValue;
            il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v2, 2);
            break;
        }
        break;
    case 4:
        switch (stackType->bodySize)
        {
        case 1:
            v4 = *(uint8_t*)pValue;
            il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v4, 4);
            break;
        case 2:
            v4 = *(uint16_t*)pValue;
            il2c_memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v4, 4);
            break;
        }
        break;
    }

    return (System_Object*)pBoxed;
}

void* il2c_unbox__(System_Object* pObject, IL2C_RUNTIME_TYPE_DECL* valueType)
{
    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)
        (((uint8_t*)pObject) - sizeof(IL2C_REF_HEADER));
    if (pHeader->type != valueType)
    {
        // new InvalidCastException();
        il2c_assert(0);
    }

    return ((uint8_t*)pObject) + sizeof(System_ValueType);
}

///////////////////////////////////////////////////////
// Another special runtime helper functions

double il2c_fmod(double lhs, double rhs)
{
    return fmod(lhs, rhs);
}

void il2c_break()
{
    debug_break();
}
