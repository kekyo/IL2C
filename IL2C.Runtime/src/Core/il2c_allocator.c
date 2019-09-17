#include <il2c_private.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////

extern IL2C_TLS_INDEX g_TlsIndex__;
extern interlock_t g_CollectionMarkIndex__;

IL2C_REF_HEADER* g_pBeginHeader__ = NULL;
IL2C_ROOT_REFERENCES* g_pRootReferences__ = NULL;
IL2C_ROOT_REFERENCES* g_pFixedReferences__ = NULL;
IL2C_STATIC_FIELDS* g_pBeginStaticFields__ = NULL;

/////////////////////////////////////////////////////////////
// Instance allocator functions

#if defined(IL2C_USE_LINE_INFORMATION)
IL2C_REF_HEADER* il2c_get_uninitialized_object_internal__(
    IL2C_RUNTIME_TYPE type, uintptr_t bodySize, const char* pFile, int line)
#else
IL2C_REF_HEADER* il2c_get_uninitialized_object_internal__(
    IL2C_RUNTIME_TYPE type, uintptr_t bodySize)
#endif
{
    il2c_assert(type != NULL);

    // TODO: always collect
#if defined(IL2C_USE_LINE_INFORMATION)
    il2c_collect__(pFile, line);
#else
    il2c_collect__();
#endif

    // +----------------------+ <-- pHeader
    // | IL2C_REF_HEADER      |
    // +----------------------+ <-- pReference   -------
    // |          :           |                    ^
    // | (Instance body)      |                    | bodySize
    // |          :           |                    v
    // +----------------------+                  -------

    const uintptr_t totalSize = sizeof(IL2C_REF_HEADER) + bodySize;
#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)il2c_malloc(totalSize, pFile, line);
#else
    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)il2c_malloc(totalSize);
#endif
    if (il2c_unlikely__(pHeader == NULL))
    {
        while (1)
        {
            // Cannot allocate: force collecting
#if defined(IL2C_USE_LINE_INFORMATION)
            il2c_collect__(pFile, line);
#else
            il2c_collect__();
#endif

            // Retry
#if defined(IL2C_USE_LINE_INFORMATION)
            pHeader = (IL2C_REF_HEADER*)il2c_malloc(totalSize, pFile, line);
#else
            pHeader = (IL2C_REF_HEADER*)il2c_malloc(totalSize);
#endif
            if (il2c_likely__(pHeader != NULL))
            {
                break;
            }

            // throw NotEnoughMemoryException();
            il2c_assert(0);
        }
    }

    // Guarantee cleared body
    memset((void*)pHeader, 0, totalSize);

    // Set RTTI.
    pHeader->type = type;

    // Setup vptr0.
    System_Object* pReference = (System_Object*)(((uint8_t*)pHeader) + sizeof(IL2C_REF_HEADER));
    *((const void**)pReference) = type->vptr0;

    // Setup interface vptrs.
    IL2C_IMPLEMENTED_INTERFACE* pInterface =
        (IL2C_IMPLEMENTED_INTERFACE*)(((IL2C_MARK_TARGET*)(type + 1)) + type->markTarget);
    uintptr_t index;
    for (index = 0;
        il2c_likely__(index < type->interfaceCount);
        index++, pInterface++)
    {
        il2c_assert((pInterface->type->flags & IL2C_TYPE_INTERFACE) == IL2C_TYPE_INTERFACE);

        // The interface vptr offset placed at vptr[0].
        uintptr_t offset = *(const uintptr_t*)(pInterface->vptr0);
        *((const void**)(((uint8_t*)pReference) + offset)) = pInterface->vptr0;
    }

    // FOR GC TEST.
    //il2c_sleep(100);

    // Safe link both headers.
    while (1)
    {
        IL2C_REF_HEADER* pNext = g_pBeginHeader__;
        pHeader->pNext = pNext;
        if (il2c_likely__((IL2C_REF_HEADER*)il2c_icmpxchgptr(&g_pBeginHeader__, pHeader, pNext) == pNext))
        {
            break;
        }
    }

    // NOTE: Entered critical section for partially construted instance.
    //   IL2C will make the mark INITIALIZED.

    // HACK: Current GC mark status is same as g_CollectionMarkIndex__,
    // it means MARKED but NOT INITIALIZED.
    pHeader->characteristic = g_CollectionMarkIndex__;

    // FOR GC TEST.
    //il2c_sleep(100);

    return pHeader;
}

#if defined(IL2C_USE_LINE_INFORMATION)
void* il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE type, const char* pFile, int line)
#else
void* il2c_get_uninitialized_object__(IL2C_RUNTIME_TYPE type)
#endif
{
    il2c_assert(type != NULL);
    il2c_assert(type->vptr0 != NULL);

    // String, Delegate, Array and Thread (IL2C_TYPE_VARIABLE):
    // throw new InvalidProgramException();
    il2c_assert((type->flags & IL2C_TYPE_VARIABLE) != IL2C_TYPE_VARIABLE);
    il2c_assert(type->bodySize >= sizeof(void*));   // vptr0

    // Allocate heap memory.
#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        type, type->bodySize, pFile, line);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(
        pFile, line);
#else
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        type, type->bodySize);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    System_Object* pReference = (System_Object*)(pHeader + 1);
    pThreadContext->pTemporaryReferenceAnchor = pReference;

    // Marked instance is initialized. (and will handle by GC)
    il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);

    return pReference;
}

/////////////////////////////////////////////////////////////
// Execution frame linker functions

#if defined(IL2C_USE_LINE_INFORMATION)
void il2c_link_execution_frame__(/* EXECUTION_FRAME__* */ volatile void* pNewFrame, const char* pFile, int line)
#else
void il2c_link_execution_frame__(/* EXECUTION_FRAME__* */ volatile void* pNewFrame)
#endif
{
    il2c_assert(pNewFrame != NULL);
    il2c_assert(((IL2C_EXECUTION_FRAME*)pNewFrame)->pNext__ == NULL);

    // Get thread context.
#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(pFile, line);
#else
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    // Touch for lock region.
    il2c_enter_monitor_lock__((void*)IL2C_THREAD_LOCK_TARGET(pThreadContext));

    while (1)
    {
        IL2C_EXECUTION_FRAME* pNext = pThreadContext->pFrame;
        ((IL2C_EXECUTION_FRAME*)pNewFrame)->pNext__ = pNext;
        if (il2c_likely__(il2c_icmpxchgptr(&pThreadContext->pFrame, pNewFrame, pNext) == pNext))
        {
            break;
        }
    }

    // Exit for lock region.
    il2c_exit_monitor_lock__((void*)IL2C_THREAD_LOCK_TARGET(pThreadContext));
}

#if defined(IL2C_USE_LINE_INFORMATION)
void* il2c_unlink_execution_frame__(/* EXECUTION_FRAME__* */ volatile void* pFrame, void* pReference, const char* pFile, int line)
#else
void* il2c_unlink_execution_frame__(/* EXECUTION_FRAME__* */ volatile void* pFrame, void* pReference)
#endif
{
    il2c_assert(pFrame != NULL);

    // TODO: always collect
#if defined(IL2C_USE_LINE_INFORMATION)
    il2c_collect__(pFile, line);
#else
    il2c_collect__();
#endif

    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);
    il2c_assert(pThreadContext != NULL);

    // IMPORTANT: Save retval into temporary reference anchor.
    pThreadContext->pTemporaryReferenceAnchor = pReference;

    // Touch for lock region.
    il2c_enter_monitor_lock__((void*)IL2C_THREAD_LOCK_TARGET(pThreadContext));

    il2c_assert(pThreadContext->pFrame == pFrame);
    pThreadContext->pFrame = ((IL2C_EXECUTION_FRAME*)pFrame)->pNext__;

    // Exit for lock region.
    il2c_exit_monitor_lock__((void*)IL2C_THREAD_LOCK_TARGET(pThreadContext));

    // TODO: Remove thread context for the last frame?

    return pReference;
}

void* il2c_cleanup_at_return__(void* pReference)
{
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);

    // The thread context will not allocate if arrives here with arbitrary thread context
    // and didn't construct execution frames.
    if (il2c_likely__(pThreadContext != NULL))
    {
        // IMPORTANT: Save retval into temporary reference anchor.
        pThreadContext->pTemporaryReferenceAnchor = pReference;
    }

    return pReference;
}

/////////////////////////////////////////////////////////////
// Static fields manipulator functions

void il2c_register_static_fields(/* IL2C_STATIC_FIELDS* */ volatile void* pStaticFields)
{
    il2c_assert(pStaticFields != NULL);

    IL2C_STATIC_FIELDS* p = pStaticFields;

    memset((void*)&(p->pReferences__[0]), 0,
        (p->objRefCount__ * sizeof(void*)) + (p->valueCount__ * sizeof(IL2C_VALUE_DESCRIPTOR)));

    while (1)
    {
        IL2C_STATIC_FIELDS* pNext = g_pBeginStaticFields__;
        p->pNext__ = pNext;
        if (il2c_likely__(il2c_icmpxchgptr(&g_pBeginStaticFields__, p, pNext) == pNext))
        {
            break;
        }
    }
}

/////////////////////////////////////////////////////////////
// Root reference manipulator functions

void il2c_register_root_reference__(void* pReference, bool isFixed)
{
    il2c_assert(pReference != NULL);

    System_Object* pAdjustedReference = il2c_adjusted_reference(pReference);

    // TODO: O(n) order
    IL2C_ROOT_REFERENCES** ppRootReferences = isFixed ?
        &g_pFixedReferences__ :
        &g_pRootReferences__;
    volatile System_Object* volatile* ppFreeReference = NULL;
    IL2C_ROOT_REFERENCES* pCurrentRootReferences = *ppRootReferences;
    while (il2c_likely__(pCurrentRootReferences != NULL))
    {
        uint8_t index;
        volatile System_Object* volatile* ppReference;
        for (index = 0, ppReference = &pCurrentRootReferences->pReferences[0];
            il2c_likely__(index < sizeof(pCurrentRootReferences->pReferences) / sizeof(void*));
            index++, ppReference++)
        {
            if (il2c_unlikely__(*ppReference == pAdjustedReference))
            {
                // Already registered.
                return;
            }
            if (il2c_unlikely__(*ppReference == NULL))
            {
                // Memoize free position.
                if (il2c_unlikely__(ppFreeReference == NULL))
                {
                    ppFreeReference = ppReference;
                }
            }
        }

        pCurrentRootReferences = pCurrentRootReferences->pNext;
    }

    // If detected free slot.
    if (il2c_likely__(ppFreeReference != NULL))
    {
        // Try store.
        if (il2c_likely__(il2c_icmpxchgptr(ppFreeReference, pAdjustedReference, NULL) == NULL))
        {
            // Success.
            return;
        }
    }

    // Nothing free place (or failed), append new slots.
    // It's safe for duplicates new slots rarely critical timing...

#if defined(IL2C_USE_LINE_INFORMATION)
    pCurrentRootReferences = il2c_malloc(sizeof(IL2C_ROOT_REFERENCES), __FILE__, __LINE__);
#else
    pCurrentRootReferences = il2c_malloc(sizeof(IL2C_ROOT_REFERENCES));
#endif
    memset((void*)pCurrentRootReferences, 0, sizeof(IL2C_ROOT_REFERENCES));

    pCurrentRootReferences->pReferences[0] = pAdjustedReference;

    while (1)
    {
        IL2C_ROOT_REFERENCES* pNext = *ppRootReferences;
        pCurrentRootReferences->pNext = pNext;
        if (il2c_likely__(il2c_icmpxchgptr(ppRootReferences, pCurrentRootReferences, pNext) == pNext))
        {
            break;
        }
    }
}

void il2c_unregister_root_reference__(void* pReference, bool isFixed)
{
    il2c_assert(pReference != NULL);

    System_Object* pAdjustedReference = il2c_adjusted_reference(pReference);

    // TODO: O(n) order
    IL2C_ROOT_REFERENCES** ppRootReferences = isFixed ?
        &g_pFixedReferences__ :
        &g_pRootReferences__;
    IL2C_ROOT_REFERENCES* pCurrentRootReferences = *ppRootReferences;
    while (il2c_likely__(pCurrentRootReferences != NULL))
    {
        uint8_t index;
        volatile System_Object* volatile* ppReference;
        for (index = 0, ppReference = &pCurrentRootReferences->pReferences[0];
            il2c_likely__(index < sizeof(pCurrentRootReferences->pReferences) / sizeof(void*));
            index++, ppReference++)
        {
            if (il2c_unlikely__(*ppReference == pAdjustedReference))
            {
                // Found, unregister.
                *ppReference = NULL;
                return;
            }
        }

        pCurrentRootReferences = pCurrentRootReferences->pNext;
    }
}

void il2c_unregister_all_root_references_for_final_shutdown__(IL2C_ROOT_REFERENCES** ppRootReferences)
{
    while (1)
    {
        IL2C_ROOT_REFERENCES* pCurrentRootReferences = *ppRootReferences;
        if (il2c_unlikely__(pCurrentRootReferences == NULL))
        {
            break;
        }

        IL2C_ROOT_REFERENCES* pNext = pCurrentRootReferences->pNext;
        if (il2c_unlikely__(il2c_icmpxchgptr(ppRootReferences, pNext, pCurrentRootReferences) != pCurrentRootReferences))
        {
            continue;
        }

        il2c_free((void*)pCurrentRootReferences);
    }
}
