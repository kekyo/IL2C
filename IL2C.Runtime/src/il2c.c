#include <il2c_private.h>
#include "Private/debugbreak.h"

/////////////////////////////////////////////////////////////

typedef const struct IL2C_VALUE_DESCRIPTOR_DECL
{
    const IL2C_RUNTIME_TYPE type_value;
    const void* ptr_value;
} IL2C_VALUE_DESCRIPTOR;

typedef volatile struct IL2C_ROOT_REFERENCES_DECL IL2C_ROOT_REFERENCES;

struct IL2C_ROOT_REFERENCES_DECL
{
    IL2C_ROOT_REFERENCES* pNext;
    volatile System_Object* pReferences[3];
};

typedef struct IL2C_MONITOR_LOCK_BLOCK_DECL IL2C_MONITOR_LOCK_BLOCK;

struct IL2C_MONITOR_LOCK_BLOCK_DECL
{
    IL2C_MONITOR_LOCK_BLOCK* pNext;
    volatile System_Object* pReferences[4];
    IL2C_MONITOR_LOCK locks[4];
};

typedef struct IL2C_MONITOR_LOCK_BLOCK_INFORMATION_DECL IL2C_MONITOR_LOCK_BLOCK_INFORMATION;

struct IL2C_MONITOR_LOCK_BLOCK_INFORMATION_DECL
{
    IL2C_MONITOR_LOCK blockLock;
    IL2C_MONITOR_LOCK_BLOCK block0;
};

IL2C_TLS_INDEX g_TlsIndex__;

static IL2C_REF_HEADER* g_pBeginHeader__ = NULL;
static IL2C_ROOT_REFERENCES* g_pRootReferences__ = NULL;
static IL2C_ROOT_REFERENCES* g_pFixedReferences__ = NULL;

static IL2C_STATIC_FIELDS* g_pBeginStaticFields__ = NULL;

static IL2C_MONITOR_LOCK_BLOCK_INFORMATION* g_MonitorLockBlockInformations[7] = { NULL };

static interlock_t g_CollectionMarkIndex__ = 0; //  IL2C_CHARACTERISTIC_MARK_INDEX;
static interlock_t g_ExecutingCollection__ = 0;

// Stop the world global lock.
#if !defined(IL2C_USE_NARROW_LOCK)
IL2C_MONITOR_LOCK g_GlobalLockForCollect__;
#else
static IL2C_MONITOR_LOCK g_GlobalLockForCollect__;
#endif


///////////////////////////////////////////////////////////////////////////////////////////////////////

// The initializer count produces when works the type initializer.
// "il2c_initializer_count" will compare the local type counter,
// the translated code have to initialize first using static members if count value different.
static uintptr_t g_InitializerCount = 0;
const uintptr_t* il2c_initializer_count = &g_InitializerCount;

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
// Thread context functions

#if defined(IL2C_USE_LINE_INFORMATION)
IL2C_THREAD_CONTEXT* il2c_acquire_thread_context__(const char* pFile, int line)
#else
IL2C_THREAD_CONTEXT* il2c_acquire_thread_context__(void)
#endif
{
    // First arrived arbitary native thread: Auto attaching managed thread.
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);
    if (il2c_unlikely__(pThreadContext == NULL))
    {
#if defined(IL2C_USE_LINE_INFORMATION)
        IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
            il2c_typeof(System_Threading_Thread),
            sizeof(IL2C_RUNTIME_THREAD),
            pFile, line);
#else
        IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
            il2c_typeof(System_Threading_Thread),
            sizeof(IL2C_RUNTIME_THREAD));
#endif

        IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)(pHeader + 1);

        // Initialize thread context.
        pThreadContext = &pRuntimeThread->context;

        pThreadContext->rawHandle = il2c_get_current_thread__();
        pThreadContext->id = il2c_get_current_thread_id__();
        il2c_initialize_monitor_lock__((void*)&pThreadContext->lockForCollect);

        // Save IL2C_THREAD_CONTEXT into tls.
        il2c_set_tls_value(g_TlsIndex__, (void*)pThreadContext);

        // Register GC root reference.
        // NOTE: Auto attached Thread class instances aren't freed when before shutdown.
        //   If we instantiated with Thread.Start(), it's manually allocated and can collect by GC.
        //   (See System_Threading_Thread_InternalEntryPoint())
        il2c_register_root_reference__((void*)pRuntimeThread, false);

        // Marked instance is initialized. (and will handle by GC)
        il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);
    }

    return pThreadContext;
}

#if defined(IL2C_USE_LINE_INFORMATION)
System_Threading_Thread* il2c_new_thread__(System_Delegate* start, const char* pFile, int line)
#else
System_Threading_Thread* il2c_new_thread__(System_Delegate* start)
#endif
{
    // TODO: ArgumentNullException
    il2c_assert(start != NULL);

#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        il2c_typeof(System_Threading_Thread),
        sizeof(IL2C_RUNTIME_CREATED_THREAD),
        pFile, line);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(
        pFile, line);
#else
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        il2c_typeof(System_Threading_Thread),
        sizeof(IL2C_RUNTIME_CREATED_THREAD));
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    IL2C_RUNTIME_CREATED_THREAD* pRuntimeThread = (IL2C_RUNTIME_CREATED_THREAD*)(pHeader + 1);
    pThreadContext->pTemporaryReferenceAnchor = (System_Object*)&pRuntimeThread->thread;

    pRuntimeThread->thread.start__ = start;
    pRuntimeThread->context.rawHandle = -1;
     
    // Initialize thread context.
    pRuntimeThread->context.id = il2c_get_current_thread_id__();
    il2c_initialize_monitor_lock__((void*)&pRuntimeThread->context.lockForCollect);

    // Marked instance is initialized. (and will handle by GC)
    il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);

    return (System_Threading_Thread*)&pRuntimeThread->thread;
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

    // Save retval into temporary reference anchor.
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
    il2c_assert(pThreadContext != NULL);

    pThreadContext->pTemporaryReferenceAnchor = pReference;

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
// GC root reference manipulator functions

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

    // If detedted free slot.
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

static void il2c_unregister_all_root_references_for_final_shutdown__(IL2C_ROOT_REFERENCES** ppRootReferences)
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

/////////////////////////////////////////////////////////////
// Monitor lock functions

IL2C_MONITOR_LOCK* il2c_acquire_monitor_lock_from_objref__(void* pReference, bool allocateIfRequired)
{
    il2c_assert(pReference != NULL);

    System_Object* pAdjustedReference = il2c_adjusted_reference(pReference);

    const uint8_t blockIndex =
        (uint8_t)(((uintptr_t)pAdjustedReference) %
        (uint8_t)(sizeof(g_MonitorLockBlockInformations) / sizeof(IL2C_MONITOR_LOCK_BLOCK_INFORMATION*)));

    // Step 1: Get IL2C_MONITOR_LOCK_BLOCK.
    IL2C_MONITOR_LOCK_BLOCK_INFORMATION* pMonitorBlockInformation = g_MonitorLockBlockInformations[blockIndex];
    if (il2c_unlikely__(pMonitorBlockInformation == NULL))
    {
        if (il2c_unlikely__(!allocateIfRequired))
        {
            return NULL;
        }

        // Allocate new IL2C_MONITOR_LOCK_BLOCK_INFORMATION.
#if defined(IL2C_USE_LINE_INFORMATION)
        pMonitorBlockInformation = il2c_malloc(sizeof(IL2C_MONITOR_LOCK_BLOCK_INFORMATION), __FILE__, __LINE__);
#else
        pMonitorBlockInformation = il2c_malloc(sizeof(IL2C_MONITOR_LOCK_BLOCK_INFORMATION));
#endif
        memset(pMonitorBlockInformation, 0, sizeof *pMonitorBlockInformation);
        il2c_initialize_monitor_lock__(&pMonitorBlockInformation->blockLock);

        // TODO: NotEnoughMemoryException
        il2c_assert(pMonitorBlockInformation != NULL);

        IL2C_MONITOR_LOCK_BLOCK_INFORMATION* p = il2c_icmpxchgptr(
            &g_MonitorLockBlockInformations[blockIndex], pMonitorBlockInformation, NULL);
        if (il2c_unlikely__(p != NULL))
        {
            il2c_destroy_monitor_lock__(&pMonitorBlockInformation->blockLock);
            il2c_free(pMonitorBlockInformation);

            pMonitorBlockInformation = p;
        }
    }

    // Step 2: Traverse list with list locked.
    il2c_enter_monitor_lock__(&pMonitorBlockInformation->blockLock);

    IL2C_MONITOR_LOCK_BLOCK* pCurrentBlock = &pMonitorBlockInformation->block0;
    while (1)
    {
        volatile System_Object** ppReference;
        uint8_t index;
        for (index = 0, ppReference = pCurrentBlock->pReferences;
            il2c_likely__(index < (sizeof(pCurrentBlock->pReferences) / sizeof(void*)));
            index++, ppReference++)
        {
            // Already assigned.
            if (il2c_unlikely__(*ppReference == pAdjustedReference))
            {
                il2c_assert(il2c_get_header__(pAdjustedReference)->characteristic & (IL2C_CHARACTERISTIC_CONST | IL2C_CHARACTERISTIC_ACQUIRED_MONITOR_LOCK));
                il2c_exit_monitor_lock__(&pMonitorBlockInformation->blockLock);

                IL2C_MONITOR_LOCK* pLock = &pCurrentBlock->locks[index];
                return pLock;
            }

            // Found free slot.
            if (il2c_unlikely__((*ppReference == NULL) && allocateIfRequired))
            {
                IL2C_MONITOR_LOCK* pLock = &pCurrentBlock->locks[index];
                il2c_initialize_monitor_lock__(pLock);

                // We have to mark acquired to the instance except const instance.
                // The GC phase, can ignore traversing monitor lock table if doesn't detect this flag.
                IL2C_REF_HEADER* pHeader = il2c_get_header__(pAdjustedReference);
                if ((pHeader->characteristic & IL2C_CHARACTERISTIC_CONST) == 0)
                {
                    const interlock_t c = il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_ACQUIRED_MONITOR_LOCK);
                    il2c_assert((c & IL2C_CHARACTERISTIC_ACQUIRED_MONITOR_LOCK) == 0);
                }

                *ppReference = pAdjustedReference;

                il2c_exit_monitor_lock__(&pMonitorBlockInformation->blockLock);
                return pLock;
            }
        }

        if (il2c_unlikely__(pCurrentBlock->pNext == NULL))
        {
            if (il2c_unlikely__(!allocateIfRequired))
            {
                return NULL;
            }

            // TODO: Locking and allocating are a lot of cost.
#if defined(IL2C_USE_LINE_INFORMATION)
            IL2C_MONITOR_LOCK_BLOCK* pNext = il2c_malloc(sizeof(IL2C_MONITOR_LOCK_BLOCK), __FILE__, __LINE__);
#else
            IL2C_MONITOR_LOCK_BLOCK* pNext = il2c_malloc(sizeof(IL2C_MONITOR_LOCK_BLOCK));
#endif
            memset(pNext, 0, sizeof *pNext);

            IL2C_MONITOR_LOCK_BLOCK* pLast = il2c_icmpxchgptr(&pCurrentBlock->pNext, pNext, NULL);
            il2c_assert(pLast == NULL);

            IL2C_MONITOR_LOCK* pLock = &pCurrentBlock->locks[index];
            il2c_initialize_monitor_lock__(pLock);

            // We have to mark acquired to the instance except const instance.
            // The GC phase, can ignore traversing monitor lock table if doesn't detect this flag.
            IL2C_REF_HEADER* pHeader = il2c_get_header__(pAdjustedReference);
            if ((pHeader->characteristic & IL2C_CHARACTERISTIC_CONST) == 0)
            {
                const interlock_t c = il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_ACQUIRED_MONITOR_LOCK);
                il2c_assert((c & IL2C_CHARACTERISTIC_ACQUIRED_MONITOR_LOCK) == 0);
            }

            *ppReference = pAdjustedReference;

            il2c_exit_monitor_lock__(&pMonitorBlockInformation->blockLock);
            return pLock;
        }

        pCurrentBlock = pCurrentBlock->pNext;
    }
}

static void il2c_release_monitor_lock_from_objref__(IL2C_REF_HEADER* pHeader)
{
    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    il2c_assert(pHeader != NULL);
    il2c_assert((pHeader->characteristic & (IL2C_CHARACTERISTIC_CONST | IL2C_CHARACTERISTIC_ACQUIRED_MONITOR_LOCK)));

    System_Object* pAdjustedReference = (System_Object*)(((uint8_t*)pHeader) + sizeof(IL2C_REF_HEADER));

    const uint8_t blockIndex =
        (uint8_t)(((uintptr_t)pAdjustedReference) %
        (uint8_t)(sizeof(g_MonitorLockBlockInformations) / sizeof(IL2C_MONITOR_LOCK_BLOCK_INFORMATION*)));

    IL2C_MONITOR_LOCK_BLOCK_INFORMATION* pMonitorBlockInformation = g_MonitorLockBlockInformations[blockIndex];
    if (il2c_unlikely__(pMonitorBlockInformation == NULL))
    {
        return;
    }

    il2c_enter_monitor_lock__(&pMonitorBlockInformation->blockLock);

    IL2C_MONITOR_LOCK_BLOCK* pCurrentBlock = &pMonitorBlockInformation->block0;
    while (1)
    {
        volatile System_Object* volatile* ppReference;
        uint8_t index;
        for (index = 0, ppReference = pCurrentBlock->pReferences;
            il2c_likely__(index < (sizeof(pCurrentBlock->pReferences) / sizeof(void*)));
            index++, ppReference++)
        {
            // Found this reference.
            if (il2c_unlikely__(*ppReference == pAdjustedReference))
            {
                il2c_runtime_debug_log_format(
                    L"il2c_release_monitor_lock_from_objref__: free lock: blockIndex={0:u}, index={1:u}, *ppReference=0x{2:p}, type={3:s}, characteristic=0x{4:x}",
                    blockIndex,
                    index,
                    *ppReference,
                    pHeader->type->pTypeName,
                    pHeader->characteristic);

                *ppReference = NULL;

                // Destroy the lock.
                IL2C_MONITOR_LOCK* pLock = &pCurrentBlock->locks[index];
                il2c_destroy_monitor_lock__(pLock);

                il2c_exit_monitor_lock__(&pMonitorBlockInformation->blockLock);
                return;
            }
        }

        // Not found.
        if (il2c_unlikely__(pCurrentBlock->pNext == NULL))
        {
            // It's only constant.
            il2c_assert(pHeader->characteristic & IL2C_CHARACTERISTIC_CONST);

            il2c_exit_monitor_lock__(&pMonitorBlockInformation->blockLock);
            return;
        }

        pCurrentBlock = pCurrentBlock->pNext;
    }
}

static void il2c_release_all_monitor_lock_for_final_shutdown__(void)
{
    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    IL2C_MONITOR_LOCK_BLOCK_INFORMATION** ppMonitorBlockInformation;
    uint8_t blockIndex;
    for (blockIndex = 0, ppMonitorBlockInformation = &g_MonitorLockBlockInformations[0];
        blockIndex < (sizeof(g_MonitorLockBlockInformations) / sizeof(IL2C_MONITOR_LOCK_BLOCK_INFORMATION*));
        blockIndex++, ppMonitorBlockInformation++)
    {
        if (*ppMonitorBlockInformation != NULL)
        {
            IL2C_MONITOR_LOCK_BLOCK* pCurrentBlock = &(*ppMonitorBlockInformation)->block0;
            IL2C_MONITOR_LOCK_BLOCK* pLastBlock = NULL;
            goto loop;

            do
            {
                il2c_assert(pLastBlock != NULL);
                il2c_free((void*)pLastBlock);
            loop:
                {
                    volatile System_Object* volatile* ppReference;
                    uint8_t index;
                    for (index = 0, ppReference = pCurrentBlock->pReferences;
                        il2c_likely__(index < (sizeof(pCurrentBlock->pReferences) / sizeof(void*)));
                        index++, ppReference++)
                    {
                        // Assigned at this lock.
                        if (il2c_unlikely__(*ppReference != NULL))
                        {
#if defined(IL2C_USE_RUNTIME_DEBUG_LOG)
                            IL2C_REF_HEADER* pHeader = il2c_get_header__(*ppReference);
                            il2c_runtime_debug_log_format(
                                L"il2c_release_all_monitor_lock_for_final_shutdown__: free lock: blockIndex={0:u}, index={1:u}, *ppReference=0x{2:p}, type={3:s}, characteristic=0x{4:x}",
                                blockIndex,
                                index,
                                *ppReference,
                                pHeader->type->pTypeName,
                                pHeader->characteristic);
#endif
#if defined(_DEBUG)
                            *ppReference = NULL;
#endif
                            // Destroy the lock.
                            IL2C_MONITOR_LOCK* pLock = &pCurrentBlock->locks[index];
                            il2c_destroy_monitor_lock__(pLock);
                        }
                    }
                }

                pLastBlock = pCurrentBlock;
                pCurrentBlock = pCurrentBlock->pNext;
            }
            while (il2c_unlikely__(pCurrentBlock != NULL));

            // Destroy this block information lock.
            il2c_destroy_monitor_lock__(&(*ppMonitorBlockInformation)->blockLock);

            // Free this block information.
            il2c_free(*ppMonitorBlockInformation);

            il2c_runtime_debug_log_format(
                L"il2c_release_all_monitor_lock_for_final_shutdown__: free lock block: blockIndex={0:u}",
                blockIndex);

#if defined(_DEBUG)
            *ppMonitorBlockInformation = NULL;
#endif
        }
    }
}

/////////////////////////////////////////////////////////////
// Internal GC mark handlers

// Has to ignore if objref is const.  (NOT const and initialized and NOT marked)
// HACK: It's shame the icmpxchg may cause system fault if header is placed at read-only memory (CONST).
//   (at x86/x64 cause, another platform may cause)
// TODO: Reduce flags calculation.
#define TRY_GET_HEADER(pHeader, pAdjustedReference) \
    IL2C_REF_HEADER* pHeader = il2c_get_header__(pAdjustedReference); \
    if (il2c_unlikely__(((pHeader->characteristic & \
        (IL2C_CHARACTERISTIC_CONST | IL2C_CHARACTERISTIC_MARK_INDEX)) ^ IL2C_CHARACTERISTIC_MARK_INDEX) == \
        g_CollectionMarkIndex__))

static void il2c_mark_handler_recursive__(void* pTarget, IL2C_RUNTIME_TYPE type, const uint8_t offset);

static void il2c_mark_handler_for_objref__(System_Object* pAdjustedReference)
{
    typedef void (*IL2C_MARK_HANDLER)(void* pReference);

    il2c_assert(pAdjustedReference != NULL);

    IL2C_REF_HEADER* pHeader = il2c_get_header__(pAdjustedReference);
    il2c_assert(pHeader->type != NULL);
    
    // Marking with atomicity.
    const interlock_t lastCharacteristic = il2c_ixor(&pHeader->characteristic, IL2C_CHARACTERISTIC_MARK_INDEX);
    if (il2c_likely__((lastCharacteristic & IL2C_CHARACTERISTIC_MARK_INDEX) == g_CollectionMarkIndex__))
    {
        il2c_runtime_debug_log_format(
            L"il2c_mark_handler_for_objref__ [1]: pAdjustedReference=0x{0:p}, type={1:s}, lastCharacteristic=0x{2:x}",
            pAdjustedReference,
            pHeader->type->pTypeName,
            lastCharacteristic);
        // Already marked/fixed/constant
        return;
    }

    // This type has the custom mark handler.
    // Because it's variable type, can't fix pointer offsets.
    if (il2c_unlikely__((pHeader->type->flags & IL2C_TYPE_WITH_MARK_HANDLER) == IL2C_TYPE_WITH_MARK_HANDLER))
    {
        IL2C_MARK_HANDLER pMarkHandler = (IL2C_MARK_HANDLER)(pHeader->type->markTarget);
        il2c_assert(pMarkHandler != NULL);

        il2c_runtime_debug_log_format(
            L"il2c_mark_handler_for_objref__ [2]: pAdjustedReference=0x{0:p}, type={1:s}, pMarkHandler=0x{2:p}",
            pAdjustedReference,
            pHeader->type->pTypeName,
            pMarkHandler);

        // Invoke custom mark handler
        pMarkHandler(pAdjustedReference);
    }
    // This type doesn't have the custom mark handler, traverser works just now.
    else
    {
        // NOTE: If this type is (boxed) value type,
        //   we have to shift additional offset for System_ValueType (maybe only vptr0).
        const uint8_t offset = (pHeader->type->flags & IL2C_TYPE_VALUE) ?
            sizeof(System_ValueType) :
            0;

        il2c_runtime_debug_log_format(
            L"il2c_mark_handler_for_objref__ [3]: pAdjustedReference=0x{0:p}, type={1:s}, offset={2:u}",
            pAdjustedReference,
            pHeader->type->pTypeName,
            offset);

        // Traverse recursively.
        il2c_mark_handler_recursive__(pAdjustedReference, pHeader->type, offset);
    }
}

static void il2c_mark_handler_for_value_type__(void* pValue, IL2C_RUNTIME_TYPE valueType)
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);
    il2c_assert((valueType->flags & IL2C_TYPE_VALUE) == IL2C_TYPE_VALUE);

    il2c_runtime_debug_log_format(
        L"il2c_mark_handler_for_value_type__: pValue=0x{0:p}, type={1:s}",
        pValue,
        valueType->pTypeName);

    // Traverse recursively.
    il2c_mark_handler_recursive__(pValue, valueType, 0);
}

static void il2c_mark_handler_recursive__(void* pTarget, IL2C_RUNTIME_TYPE type, const uint8_t offset)
{
    il2c_assert(pTarget != NULL);
    il2c_assert(type != NULL);

    // Traverse type fields recursivity.
    IL2C_MARK_TARGET* pMarkTarget = (IL2C_MARK_TARGET*)(type + 1);
    uintptr_t index;
    for (index = 0;
        il2c_likely__(index < type->markTarget);
        index++, pMarkTarget++)
    {
        void* pTargetField = (void*)(((uint8_t*)pTarget) + pMarkTarget->offset + offset);

        // Is this entry value type?
        if (il2c_unlikely__(pMarkTarget->valueType != NULL))
        {
            il2c_assert((pMarkTarget->valueType->flags & IL2C_TYPE_VALUE) == IL2C_TYPE_VALUE);
            il2c_assert(pTargetField != NULL);

            il2c_runtime_debug_log_format(
                L"il2c_mark_handler_recursive__ [1]: pTarget=0x{0:p}, type={1:s}, index={2:u}, pTargetField=0x{3:p}, fieldType={4:s}",
                pTarget,
                type->pTypeName,
                index,
                pTargetField,
                pMarkTarget->valueType->pTypeName);

            // Mark for this value.
            il2c_mark_handler_for_value_type__(pTargetField, pMarkTarget->valueType);
        }
        // This entry is objref.
        else
        {
            // This field isn't assigned.
            void* pReference = *(void**)pTargetField;
            if (il2c_unlikely__(pReference == NULL))
            {
                il2c_runtime_debug_log_format(
                    L"il2c_mark_handler_recursive__ [2]: pTarget=0x{0:p}, type={1:s}, index={2:u}, pReference=NULL",
                    pTarget,
                    type->pTypeName,
                    index,
                    pReference);

                continue;
            }

            System_Object* pAdjustedReferenceInner = il2c_adjusted_reference(pReference);
            TRY_GET_HEADER(pHeaderInner, pAdjustedReferenceInner)
            {
                il2c_runtime_debug_log_format(
                    L"il2c_mark_handler_recursive__ [3]: pTarget=0x{0:p}, type={1:s}, index={2:u}, pAdjustedReferenceInner=0x{3:x}, targetType={4:s}, characteristic=0x{5:x}",
                    pTarget,
                    type->pTypeName,
                    index,
                    pAdjustedReferenceInner,
                    pHeaderInner->type->pTypeName,
                    pHeaderInner->characteristic);

                // Use mark offset from type information.
                il2c_mark_handler_for_objref__(pAdjustedReferenceInner);
            }
            else
            {
                il2c_runtime_debug_log_format(
                    L"il2c_mark_handler_recursive__ [4]: pTarget=0x{0:p}, type={1:s}, index={2:u}, pAdjustedReferenceInner=0x{3:p}, targetType={4:s}, characteristic=0x{5:x}",
                    pTarget,
                    type->pTypeName,
                    index,
                    pAdjustedReferenceInner,
                    pHeaderInner->type->pTypeName,
                    pHeaderInner->characteristic);
            }
        }
    }
}

/////////////////////////////////////////////////////////////
// GC processes

static void il2c_step2_mark_gcmark__(IL2C_GC_TRACKING_INFORMATION* pBeginFrame)
{
    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    // Mark headers.
    IL2C_GC_TRACKING_INFORMATION* pCurrentFrame = pBeginFrame;
    while (il2c_likely__(pCurrentFrame != NULL))
    {
        // Traverse objrefs at the current frame.
        uint16_t index;
        void** ppReference = (void**)&pCurrentFrame->pReferences__[0];
        for (index = 0; il2c_likely__(index < pCurrentFrame->objRefCount__); index++, ppReference++)
        {
            // This variable isn't assigned.
            if (il2c_unlikely__(*ppReference == NULL))
            {
                il2c_runtime_debug_log_format(
                    L"il2c_step2_mark_gcmark__ [2]: pCurrentFrame=0x{0:p}, index={1:u}, *ppReference=NULL",
                    pCurrentFrame,
                    index);
                continue;
            }

            System_Object* pAdjustedReference = il2c_adjusted_reference(*ppReference);
            TRY_GET_HEADER(pHeader, pAdjustedReference)
            {
                il2c_runtime_debug_log_format(
                    L"il2c_step2_mark_gcmark__ [3]: pCurrentFrame=0x{0:p}, index={1:u}, *ppReference=0x{2:p}, pAdjustedReference=0x{3:p}, type={4:s}, characteristic=0x{5:x}",
                    pCurrentFrame,
                    index,
                    *ppReference,
                    pAdjustedReference,
                    pHeader->type->pTypeName,
                    pHeader->characteristic);

                // Mark for this objref.
                il2c_mark_handler_for_objref__(pAdjustedReference);
            }
            else
            {
                il2c_runtime_debug_log_format(
                    L"il2c_step2_mark_gcmark__ [4]: pCurrentFrame=0x{0:p}, index={1:u}, *ppReference=0x{2:p}, pAdjustedReference=0x{3:p}, type={4:s}, characteristic=0x{5:x}",
                    pCurrentFrame,
                    index,
                    *ppReference,
                    pAdjustedReference,
                    pHeader->type->pTypeName,
                    pHeader->characteristic);
            }
        }

        // Traverse value types at the current frame.
        IL2C_VALUE_DESCRIPTOR* pValueDesc =
            (IL2C_VALUE_DESCRIPTOR*)&pCurrentFrame->pReferences__[pCurrentFrame->objRefCount__];
        for (index = 0; il2c_likely__(index < pCurrentFrame->valueCount__); index++, pValueDesc++)
        {
            il2c_assert(pValueDesc->ptr_value != NULL);
            il2c_assert(pValueDesc->type_value != NULL);
            il2c_assert((pValueDesc->type_value->flags & IL2C_TYPE_VALUE) == IL2C_TYPE_VALUE);

            il2c_runtime_debug_log_format(
                L"il2c_step2_mark_gcmark__ [5]: pCurrentFrame=0x{0:p}, index={1:u}, type={2:s}, pValue={3:p}",
                pCurrentFrame,
                index,
                pValueDesc->type_value->pTypeName,
                pValueDesc->ptr_value);

            // Mark for this value.
            il2c_mark_handler_for_value_type__((void*)pValueDesc->ptr_value, pValueDesc->type_value);
        }

        // Next frame
        pCurrentFrame = pCurrentFrame->pNext__;
    }
}

static void il2c_step2_mark_gcmark_for_root_referfences__(IL2C_ROOT_REFERENCES* pRootReferences)
{
    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    while (il2c_likely__(pRootReferences != NULL))
    {
        uint8_t index;
        volatile System_Object* volatile* ppReference;
        for (index = 0, ppReference = &pRootReferences->pReferences[0];
            il2c_likely__(index < sizeof(pRootReferences->pReferences) / sizeof(void*));
            index++, ppReference++)
        {
            // This slot is assigned.
            System_Object* pAdjustedReference = (System_Object*)*ppReference;
            if (il2c_likely__(pAdjustedReference != NULL))
            {
                TRY_GET_HEADER(pHeader, pAdjustedReference)
                {
                    il2c_runtime_debug_log_format(
                        L"il2c_step2_mark_gcmark_for_root_referfences__ [1]: pRootReferences=0x{0:p}, index={1:u}, pAdjustedReference=0x{2:p}, type={3:s}, characteristic=0x{4:x}",
                        pRootReferences,
                        index,
                        pAdjustedReference,
                        pHeader->type->pTypeName,
                        pHeader->characteristic);

                    // Mark for this objref.
                    il2c_mark_handler_for_objref__(pAdjustedReference);
                }
                else
                {
                    il2c_runtime_debug_log_format(
                        L"il2c_step2_mark_gcmark_for_root_referfences__ [2]: pRootReferences=0x{0:p}, index={1:u}, pAdjustedReference=0x{2:p}, type={3:s}, characteristic=0x{4:x}",
                        pRootReferences,
                        index,
                        pAdjustedReference,
                        pHeader->type->pTypeName,
                        pHeader->characteristic);
                }
            }
        }

        pRootReferences = pRootReferences->pNext;
    }
}

static void il2c_step3_sweep_garbage__(void)
{
    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    // Step 1: Collect unmarked instances and call finalizers.

    IL2C_REF_HEADER** ppUnlinkTarget = &g_pBeginHeader__;
    IL2C_REF_HEADER* pCurrentHeader = g_pBeginHeader__;
    IL2C_REF_HEADER* pScheduledHeader = NULL;
    while (il2c_likely__(pCurrentHeader != NULL))
    {
        IL2C_REF_HEADER* pNext = pCurrentHeader->pNext;
        if (il2c_unlikely__(((pCurrentHeader->characteristic &
            (IL2C_CHARACTERISTIC_INITIALIZED | IL2C_CHARACTERISTIC_MARK_INDEX)) ^
            (IL2C_CHARACTERISTIC_INITIALIZED | IL2C_CHARACTERISTIC_MARK_INDEX)) ==
            g_CollectionMarkIndex__))
        {
            // Very important unlink step: because cause misread on purpose this__ instance is living.
            *ppUnlinkTarget = pNext;

            // Class type overrided the finalizer:
            if (il2c_unlikely__((void*)((System_Object_VTABLE_DECL__*)(pCurrentHeader->type->vptr0))->Finalize != (void*)System_Object_Finalize))
            {
                // Do atomic set finalized flag
                interlock_t characteristic = il2c_ior(&pCurrentHeader->characteristic, IL2C_CHARACTERISTIC_FINALIZER_CALLED);
                if (il2c_likely__((characteristic & IL2C_CHARACTERISTIC_FINALIZER_CALLED) == 0))
                {
                    // Finalizer didn't call or reregistered (GC.ReRegisterForFinalize())
                    System_Object* pAdjustedReference = (System_Object*)(((uint8_t*)pCurrentHeader) + sizeof(IL2C_REF_HEADER));
                    il2c_assert((void*)pAdjustedReference->vptr0__ == (void*)pCurrentHeader->type->vptr0);

                    il2c_runtime_debug_log_format(
                        L"il2c_step3_sweep_garbage__ [1]: call finalizer: type={0:s}, pAdjustedReference=0x{0:p}",
                        pCurrentHeader->type->pTypeName,
                        pAdjustedReference);

                    // Call finalizer.
                    pAdjustedReference->vptr0__->Finalize(pAdjustedReference);

                    // GC don't collect current situation because finalizer perhaps made resurrection.
                }
                else
                {
                    // Insert to free list.
                    pCurrentHeader->pNext = pScheduledHeader;
                    pScheduledHeader = pCurrentHeader;
                }
            }
            else
            {
                // Insert to free list.
                pCurrentHeader->pNext = pScheduledHeader;
                pScheduledHeader = pCurrentHeader;
            }
        }
        else
        {
            ppUnlinkTarget = (void*)&pCurrentHeader->pNext;
        }

        // Next
        pCurrentHeader = pNext;
    }

    // Step 2: Free collected instances.

    while (il2c_likely__(pScheduledHeader != NULL))
    {
        IL2C_REF_HEADER* pNext = pScheduledHeader->pNext;

        il2c_runtime_debug_log_format(
            L"il2c_step3_sweep_garbage__ [2]: free: type={0:s}, pObject=0x{1:p}, characteristic=0x{2:x}",
            pScheduledHeader->type->pTypeName,
            ((uint8_t*)pScheduledHeader) + sizeof(IL2C_REF_HEADER),
            pScheduledHeader->characteristic);

        // Simply ignore if this instance didn't mark ACQUIRED.
        if (il2c_unlikely__(pScheduledHeader->characteristic & IL2C_CHARACTERISTIC_ACQUIRED_MONITOR_LOCK))
        {
            // Monitor lock discarded.
            il2c_release_monitor_lock_from_objref__(pScheduledHeader);
        }

        // Heap discarded.
        il2c_free((void*)pScheduledHeader);

        // Next
        pScheduledHeader = pNext;
    }
}

#if defined(_DEBUG)
static uint32_t g_CollectCount = 0;

// For GC debugging purpose.
// Refer g_CollectCount log value and set number to the variable on start debugging.
int64_t g_CollectCountBreak = -1;
#endif

static void il2c_enter_for_collect__(void)
{
    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

#if !defined(IL2C_USE_RUNTIME_GIANT_LOCK)
    IL2C_ROOT_REFERENCES* pRootReferences = g_pRootReferences__;
    while (il2c_likely__(pRootReferences != NULL))
    {
        uint8_t index;
        volatile System_Object* volatile* ppReference;
        for (index = 0, ppReference = &pRootReferences->pReferences[0];
            il2c_likely__(index < sizeof(pRootReferences->pReferences) / sizeof(void*));
            index++, ppReference++)
        {
            // This slot is assigned.
            IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)*ppReference;
            if (il2c_likely__(pRuntimeThread != NULL))
            {
                il2c_assert(pRuntimeThread->thread.vptr0__ == &System_Threading_Thread_VTABLE__);

                il2c_enter_monitor_lock__((void*)&pRuntimeThread->context.lockForCollect);
            }
        }

        pRootReferences = pRootReferences->pNext;
    }
#endif
}

static void il2c_exit_for_collect__(void)
{
    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

#if !defined(IL2C_USE_RUNTIME_GIANT_LOCK)
    IL2C_ROOT_REFERENCES* pRootReferences = g_pRootReferences__;
    while (il2c_likely__(pRootReferences != NULL))
    {
        uint8_t index;
        volatile System_Object* volatile* ppReference;
        for (index = 0, ppReference = &pRootReferences->pReferences[0];
            il2c_likely__(index < sizeof(pRootReferences->pReferences) / sizeof(void*));
            index++, ppReference++)
        {
            // This slot is assigned.
            IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)*ppReference;
            if (il2c_likely__(pRuntimeThread != NULL))
            {
                il2c_assert(pRuntimeThread->thread.vptr0__ == &System_Threading_Thread_VTABLE__);

                il2c_exit_monitor_lock__((void*)&pRuntimeThread->context.lockForCollect);
            }
        }

        pRootReferences = pRootReferences->pNext;
    }
#endif
}

#if defined(IL2C_USE_LINE_INFORMATION)
void il2c_collect__(const char* pFile, int line)
#else
void il2c_collect__(void)
#endif
{
    // Ignores reentrant by the finalizers.
    if (il2c_unlikely__(il2c_iinc(&g_ExecutingCollection__) >= 2))
    {
        il2c_idec(&g_ExecutingCollection__);
        return;
    }

#if defined(_DEBUG)
    const uint32_t collectCount = g_CollectCount++;
    if (il2c_unlikely__(g_CollectCountBreak != -1))
    {
        il2c_assert(collectCount != (uint32_t)g_CollectCountBreak);
    }
#endif

    // Take GC locks.
    il2c_enter_monitor_lock__(&g_GlobalLockForCollect__);
    il2c_enter_for_collect__();

    //////////////////////////////////////////////////
    // GC Step 1:

    // Note: Traditional mark-sweep GC's first step is clearing markings.
    //   The IL2C GC skips this step and mark/clear flag indicates with inverse arithmetic
    //   between g_CollectionMarkIndex__ and characteristic's MARK_INDEX.
    //   The instances characteristic MARK_INDEX will indicate last stats, so makes NOT MARKED if inversed this flag.
    const interlock_t markIndex = il2c_ixor(&g_CollectionMarkIndex__, IL2C_CHARACTERISTIC_MARK_INDEX);
    (void)markIndex;

#if defined(IL2C_USE_LINE_INFORMATION)
    il2c_runtime_debug_log_format(
        L"il2c_collect__: begin: {0:d}: Header=0x{1:p}, StaticFields=0x{2:p}, markIndex={3:x}, {4:s}({5:d})",
        collectCount,
        g_pBeginHeader__,
        g_pBeginStaticFields__,
        markIndex ^ IL2C_CHARACTERISTIC_MARK_INDEX,
        pFile, line);
#elif defined(_DEBUG)
    il2c_runtime_debug_log(
        L"il2c_collect__: begin: {0:d}: Header=0x{1:p}, StaticFields=0x{2:p}, markIndex={3:x}",
        collectCount,
        g_pBeginHeader__,
        g_pBeginStaticFields__,
        markIndex ^ IL2C_CHARACTERISTIC_MARK_INDEX);
#else
    il2c_runtime_debug_log(L"il2c_collect__: begin");
#endif

    il2c_check_heap();

    //////////////////////////////////////
    // GC Step 2:

    il2c_step2_mark_gcmark__(g_pBeginStaticFields__);
    il2c_check_heap();

    il2c_step2_mark_gcmark_for_root_referfences__(g_pRootReferences__);
    il2c_check_heap();
    il2c_step2_mark_gcmark_for_root_referfences__(g_pFixedReferences__);
    il2c_check_heap();

    //////////////////////////////////////////////////
    // GC Step 3:

    il2c_step3_sweep_garbage__();
    il2c_check_heap();

#if defined(IL2C_USE_LINE_INFORMATION)
    il2c_runtime_debug_log_format(
        L"il2c_collect__: finished: {0:d}: {1:s}({2:d})",
        collectCount,
        pFile,
        line);
#elif defined(_DEBUG)
    il2c_runtime_debug_log_format(
        L"il2c_collect__: finished: {0:d}",
        collectCount);
#else
    il2c_runtime_debug_log(L"il2c_collect__: finished");
#endif

    // Release GC locks.
    il2c_exit_for_collect__();
    il2c_exit_monitor_lock__(&g_GlobalLockForCollect__);

    il2c_idec(&g_ExecutingCollection__);
}

static void il2c_collect_for_final_shutdown__(void)
{
    const interlock_t executingCollection = il2c_iinc(&g_ExecutingCollection__);
    il2c_assert(executingCollection == 1);

#if defined(_DEBUG)
    const uint32_t collectCount = g_CollectCount++;
    if (il2c_unlikely__(g_CollectCountBreak != -1))
    {
        il2c_assert(collectCount != (uint32_t)g_CollectCountBreak);
    }
#endif

    // Take GC locks.
    il2c_enter_monitor_lock__(&g_GlobalLockForCollect__);
    il2c_enter_for_collect__();

    il2c_check_heap();

    //////////////////////////////////////////////////
    // GC Step 1:

    // Note: Traditional mark-sweep GC's first step is clearing markings.
    //   The IL2C GC skips this step and mark/clear flag indicates with inverse arithmetic
    //   between g_CollectionMarkIndex__ and characteristic's MARK_INDEX.
    //   The instances characteristic MARK_INDEX will indicate last stats, so makes NOT MARKED if inversed this flag.
    const interlock_t markIndex = il2c_ixor(&g_CollectionMarkIndex__, IL2C_CHARACTERISTIC_MARK_INDEX);
    (void)markIndex;

#if defined(_DEBUG)
    il2c_runtime_debug_log_format(
        L"il2c_collect_for_final_shutdown__: begin: {0:d}: Header=0x{1:p}, StaticFields=0x{2:p}, markIndex={3:x}",
        collectCount,
        g_pBeginHeader__,
        g_pBeginStaticFields__,
        markIndex ^ IL2C_CHARACTERISTIC_MARK_INDEX);
#else
    il2c_runtime_debug_log(
        L"il2c_collect_for_final_shutdown__: begin");
#endif

    //////////////////////////////////////
    // GC Step 2:

    // The final GC step has to ignore both static fields, root references and fixed references.
    // Step 3 collects all instances if GC doesn't have collecting problems ;)
    il2c_unregister_all_root_references_for_final_shutdown__(&g_pRootReferences__);
    il2c_check_heap();
    il2c_unregister_all_root_references_for_final_shutdown__(&g_pFixedReferences__);
    il2c_check_heap();

    //////////////////////////////////////////////////
    // GC Step 3:

    il2c_step3_sweep_garbage__();
    il2c_check_heap();

    // Release monitor locks.
    il2c_release_all_monitor_lock_for_final_shutdown__();

#if defined(_DEBUG)
    il2c_runtime_debug_log_format(
        L"il2c_collect_for_final_shutdown__: finished: {0:d}",
        collectCount);
#else
    il2c_runtime_debug_log(
        L"il2c_collect_for_final_shutdown__: finished");
#endif

    // Release GC locks.
    il2c_exit_for_collect__();
    il2c_exit_monitor_lock__(&g_GlobalLockForCollect__);

    il2c_idec(&g_ExecutingCollection__);
}

/////////////////////////////////////////////////////////////
// Default GC mark handlers for using from externals.

void il2c_default_mark_handler_for_objref__(void* pReference)
{
    il2c_assert(pReference != NULL);

    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    System_Object * pAdjustedReference = il2c_adjusted_reference(pReference);
    TRY_GET_HEADER(pHeader, pAdjustedReference)
    {
        il2c_runtime_debug_log_format(
            L"il2c_default_mark_handler_for_objref__ [1]: pReference=0x{0:p}, pAdjustedReference=0x{1:p}, type={2:s}, characteristic=0x{3:x}",
            pReference,
            pAdjustedReference,
            pHeader->type->pTypeName,
            pHeader->characteristic);

        // Traverse recursively.
        il2c_mark_handler_for_objref__(pAdjustedReference);
    }
    else
    {
        il2c_runtime_debug_log_format(
            L"il2c_default_mark_handler_for_objref__ [2]: pReference=0x{0:p}, pAdjustedReference=0x{1:p}, type={2:s}, characteristic=0x{3:x}",
            pReference,
            pAdjustedReference,
            pHeader->type->pTypeName,
            pHeader->characteristic);
    }
}

void il2c_default_mark_handler_for_value_type__(void* pValue, IL2C_RUNTIME_TYPE valueType)
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);
    il2c_assert((valueType->flags & IL2C_TYPE_VALUE) == IL2C_TYPE_VALUE);

    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    // Traverse recursively.
    il2c_mark_handler_recursive__(pValue, valueType, 0);
}

void il2c_default_mark_handler_for_tracking_information__(IL2C_GC_TRACKING_INFORMATION* pTrackingInformation)
{
    il2c_assert(pTrackingInformation != NULL);

    // It has to be invoked from inside for GC process.
    il2c_assert(g_ExecutingCollection__ >= 1);

    // Traverse recursively.
    il2c_step2_mark_gcmark__(pTrackingInformation);
}

/////////////////////////////////////////////////////////////
// Runtime cast functions

uint32_t il2c_sizeof__(IL2C_RUNTIME_TYPE type)
{
    il2c_assert(type != NULL);

    return ((type)->flags & IL2C_TYPE_VALUE) ?
        (uint32_t)(type)->bodySize :
        (uint32_t)sizeof(intptr_t);
}

void* il2c_isinst__(/* System_Object* */ void* pReference, IL2C_RUNTIME_TYPE type)
{
    il2c_assert(type != NULL);
    il2c_assert(pReference != NULL);

    System_Object* pAdjustedReference = il2c_adjusted_reference(pReference);
    IL2C_REF_HEADER* pHeader = il2c_get_header__(pAdjustedReference);
    IL2C_RUNTIME_TYPE currentType = pHeader->type;

    if (type->flags & IL2C_TYPE_INTERFACE)
    {
        do
        {
            IL2C_IMPLEMENTED_INTERFACE* pInterface =
                (IL2C_IMPLEMENTED_INTERFACE*)(((IL2C_MARK_TARGET*)(currentType + 1)) + currentType->markTarget);
            uintptr_t index;
            for (index = 0;
                il2c_likely__(index < currentType->interfaceCount);
                index++, pInterface++)
            {
                il2c_assert((pInterface->type->flags & IL2C_TYPE_INTERFACE) == IL2C_TYPE_INTERFACE);

                if (il2c_unlikely__(pInterface->type == type))
                {
                    uintptr_t offset = *(const uintptr_t*)(pInterface->vptr0);
                    return (void*)(((uint8_t*)pAdjustedReference) + offset);
                }
            }

            currentType = currentType->baseType;
        }
        while (il2c_likely__(currentType != NULL));
    }
    else
    {
        do
        {
            if (il2c_unlikely__(currentType == type))
            {
                return pReference;
            }
            currentType = currentType->baseType;
        }
        while (il2c_likely__(currentType != NULL));
    }

    return NULL;
}

void* il2c_castclass__(/* System_Object* */ void* pReference, IL2C_RUNTIME_TYPE type)
{
    il2c_assert(type != NULL);
    il2c_assert(pReference != NULL);

    void* p = il2c_isinst__(pReference, type);
    if (il2c_unlikely__(p == NULL))
    {
        il2c_throw_invalidcastexception__();
    }

    return p;
}

/////////////////////////////////////////////////////////////
// Boxing related functions

// +----------------------+
// | IL2C_REF_HEADER      |
// +----------------------+ <-- pBoxed        -----------------------------------------------
// | vptr0__              | <-- pVTable0        | System_ValueType                         ^
// +----------------------+                   -----------                                  |
// |        :             |                     ^                                          | bodySize
// | (value data)         | Copy from pValue    | type->bodySize                           |
// |        :             |                     v                                          |
// +----------------------+                   ---------------------------                  |
// | vptr_IFoo__          |                     | (optional implemented interface vptr)    |
// +----------------------+                   ---------------------------                  |
// | vptr_IBar__          |                     | (optional implemented interface vptr)    v
// +----------------------+                   -----------------------------------------------

#if defined(IL2C_USE_LINE_INFORMATION)
System_ValueType* il2c_box__(
    void* pValue, IL2C_RUNTIME_TYPE valueType, const char* pFile, int line)
#else
System_ValueType* il2c_box__(
    void* pValue, IL2C_RUNTIME_TYPE valueType)
#endif
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);

    uintptr_t bodySize = sizeof(System_ValueType) +
        valueType->bodySize +
        valueType->interfaceCount * sizeof(void*);  // interface vptrs
#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        valueType,
        bodySize,
        pFile,
        line);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(
        pFile, line);
#else
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        valueType,
        bodySize);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    System_ValueType* pBoxed = (System_ValueType*)(pHeader + 1);
    pThreadContext->pTemporaryReferenceAnchor = (System_Object*)pBoxed;

    il2c_assert(pBoxed->vptr0__ == valueType->vptr0);

    memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), pValue, valueType->bodySize);

    // Marked instance is initialized. (and will handle by GC)
    il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);

    return pBoxed;
}

// Boxing with widing/narrowing combination for signed/unsigned integer value.
// NOTE: This implemenation makes safer for endian order.
#if defined(IL2C_USE_LINE_INFORMATION)
System_ValueType* il2c_box2__(
    void* pValue, IL2C_RUNTIME_TYPE valueType, IL2C_RUNTIME_TYPE stackType, const char* pFile, int line)
#else
System_ValueType* il2c_box2__(
    void* pValue, IL2C_RUNTIME_TYPE valueType, IL2C_RUNTIME_TYPE stackType)
#endif
{
    il2c_assert(pValue != NULL);
    il2c_assert(valueType != NULL);
    il2c_assert(stackType != NULL);

    // Require type conversion  (OK: IL2C_TYPE_INTEGER || IL2C_TYPE_UNSIGNED_INTEGER)
    il2c_assert(
        ((valueType->flags & IL2C_TYPE_INTEGER) == IL2C_TYPE_INTEGER) &&
        ((stackType->flags & IL2C_TYPE_INTEGER) == IL2C_TYPE_INTEGER));
    il2c_assert((valueType->bodySize <= 8) && (stackType->bodySize <= 8));
    il2c_assert((valueType->bodySize >= 1) && (stackType->bodySize >= 1));

    // TODO: value type --> interface type

    union _v { // Lesser stack spaces for this combined variables.
        int8_t i1;
        int16_t i2;
        int32_t i4;
        int64_t i8;
        uint8_t u1;
        uint16_t u2;
        uint32_t u4;
        uint64_t u8;
    } v;
    v.u8 = 0;

    // Destination integer value is unsigned.
    const bool vui = (valueType->flags & IL2C_TYPE_UNSIGNED_INTEGER) == IL2C_TYPE_UNSIGNED_INTEGER;
    // Source integer value is unsigned.
    const bool sui = (stackType->flags & IL2C_TYPE_UNSIGNED_INTEGER) == IL2C_TYPE_UNSIGNED_INTEGER;

    // Destination size
    switch (valueType->bodySize)
    {
    case 1:
        // Source size
        switch (stackType->bodySize)
        {
        case 2:
            if (vui && sui) v.u1 = (uint8_t)*(uint16_t*)pValue;
            else if (vui) v.u1 = (uint8_t)*(int16_t*)pValue;
            else if (sui) v.i1 = (int8_t)*(uint16_t*)pValue;
            else v.i1 = (int8_t)*(int16_t*)pValue;
            break;
        case 4:
            if (vui && sui) v.u1 = (uint8_t)*(uint32_t*)pValue;
            else if (vui) v.u1 = (uint8_t)*(int32_t*)pValue;
            else if (sui) v.i1 = (int8_t)*(uint32_t*)pValue;
            else v.i1 = (int8_t)*(int32_t*)pValue;
            break;
        default:
            il2c_throw_invalidcastexception__();
        }
        break;
    case 2:
        // Source size
        switch (stackType->bodySize)
        {
        case 1:
            if (vui && sui) v.u2 = (uint16_t)*(uint8_t*)pValue;
            else if (vui) v.u2 = (uint16_t)*(int8_t*)pValue;
            else if (sui) v.i2 = (int16_t)*(uint8_t*)pValue;
            else v.i2 = (int16_t)*(int8_t*)pValue;
            break;
        case 4:
            if (vui && sui) v.u2 = (uint16_t)*(uint32_t*)pValue;
            else if (vui) v.u2 = (uint16_t)*(int32_t*)pValue;
            else if (sui) v.i2 = (int16_t)*(uint32_t*)pValue;
            else v.i2 = (int16_t)*(int32_t*)pValue;
            break;
        default:
            il2c_throw_invalidcastexception__();
        }
        break;
    case 4:
        // Source size
        switch (stackType->bodySize)
        {
        case 1:
            if (vui && sui) v.u4 = (uint32_t)*(uint8_t*)pValue;
            else if (vui) v.u4 = (uint32_t)*(int8_t*)pValue;
            else if (sui) v.i4 = (int32_t)*(uint8_t*)pValue;
            else v.i4 = (int32_t)*(int8_t*)pValue;
            break;
        case 2:
            if (vui && sui) v.u4 = (uint32_t)*(uint16_t*)pValue;
            else if (vui) v.u4 = (uint32_t)*(int16_t*)pValue;
            else if (sui) v.i4 = (int32_t)*(uint16_t*)pValue;
            else v.i4 = (int32_t)*(int16_t*)pValue;
            break;
        case 8:   // Hmm, the ECMA-335 not contains this conversion but .NET CLR 4 can do it.
            if (vui && sui) v.u4 = (uint32_t)*(uint64_t*)pValue;
            else if (vui) v.u4 = (uint32_t)*(int64_t*)pValue;
            else if (sui) v.i4 = (int32_t)*(uint64_t*)pValue;
            else v.i4 = (int32_t)*(int64_t*)pValue;
            break;
        default:
            il2c_throw_invalidcastexception__();
        }
        break;
    default:
        il2c_throw_invalidcastexception__();
    }

    const uintptr_t bodySize = sizeof(System_ValueType) +
        valueType->bodySize +
        valueType->interfaceCount * sizeof(void*);  // interface vptrs
#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        valueType,
        bodySize,
        pFile,
        line);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(
        pFile, line);
#else
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        valueType,
        bodySize);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    System_ValueType* pBoxed = (System_ValueType*)(pHeader + 1);
    pThreadContext->pTemporaryReferenceAnchor = (System_Object*)pBoxed;

    il2c_assert(pBoxed->vptr0__ == valueType->vptr0);

    switch (valueType->bodySize)
    {
    case 1:
        memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v.i1, 1);
        break;
    case 2:
        memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v.i2, 2);
        break;
    case 4:
        memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v.i4, 4);
        break;
    case 8:
        memcpy(((uint8_t*)pBoxed) + sizeof(System_ValueType), &v.i8, 8);
        break;
    }

    // Marked instance is initialized. (and will handle by GC)
    il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);

    return pBoxed;
}

void* il2c_unbox__(/* System_ValueType* */ void* pReference, IL2C_RUNTIME_TYPE valueType)
{
    if (il2c_unlikely__(pReference == NULL))
    {
        if (il2c_unlikely__(valueType->flags & IL2C_TYPE_VALUE))
        {
            il2c_throw_nullreferenceexception__();
        }
        return NULL;
    }

    IL2C_REF_HEADER* pHeader = (IL2C_REF_HEADER*)
        (((uint8_t*)pReference) - sizeof(IL2C_REF_HEADER));
    if (il2c_unlikely__(pHeader->type != valueType))
    {
        il2c_throw_invalidcastexception__();
    }

    return il2c_unsafe_unbox__(pReference, void);
}

/////////////////////////////////////////////////
// Exception special functions

void il2c_link_unwind_target__(IL2C_EXCEPTION_FRAME* pUnwindTarget, IL2C_EXCEPTION_FILTER filter)
{
    il2c_assert(pUnwindTarget != NULL);
    il2c_assert(filter != NULL);

    // TODO: The tcb will always acquired?
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);
    il2c_assert(pThreadContext != NULL);

    pUnwindTarget->pFrame = pThreadContext->pFrame;
    pUnwindTarget->ex = NULL;   // Current caught exception
    pUnwindTarget->filter = filter;
    pUnwindTarget->pNext = il2c_ixchgptr(&pThreadContext->pUnwindTarget, pUnwindTarget);
}

void il2c_unlink_unwind_target__(IL2C_EXCEPTION_FRAME* pUnwindTarget)
{
    il2c_assert(pUnwindTarget != NULL);

    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);
    il2c_assert(pThreadContext != NULL);

    IL2C_EXCEPTION_FRAME* p = il2c_ixchgptr(&pThreadContext->pUnwindTarget, pUnwindTarget->pNext);
    il2c_assert(p == pUnwindTarget);
    (void)p;
}

static il2c_noreturn__ void il2c_do_throw__(
    System_Exception* ex, IL2C_EXCEPTION_FRAME* pTargetFrame, int16_t filterNumber, IL2C_THREAD_CONTEXT* pThreadContext)
{
    il2c_assert(ex != NULL);
    il2c_assert(pTargetFrame != NULL);
    il2c_assert(pThreadContext != NULL);

    // Update current exception frame.
    pTargetFrame->ex = ex;
    pThreadContext->pUnwindTarget = pTargetFrame;

    // Update execution frame.
    pThreadContext->pFrame = pTargetFrame->pFrame;

    // Transision to target handler.
    il2c_longjmp((void*)pTargetFrame->saved, filterNumber);
}

static il2c_noreturn__ void il2c_throw_internal__(
    System_Exception* ex, IL2C_EXCEPTION_FRAME* pTargetFrame, IL2C_THREAD_CONTEXT* pThreadContext)
{
    il2c_assert(ex != NULL);
    il2c_assert(pThreadContext != NULL);

    IL2C_EXCEPTION_FRAME* pFrame = pTargetFrame;
    IL2C_EXCEPTION_FRAME* pFinallyFrame = NULL;

    while (il2c_likely__(pFrame != NULL))
    {
        il2c_assert(pFrame->filter != NULL);
        il2c_assert(pFrame->pFrame != NULL);

        int16_t filterNumber = pFrame->filter(ex);

        // Found finally block
        if (il2c_unlikely__(filterNumber == IL2C_FILTER_FINALLY))
        {
            // Memoize finally frame
            if (pFinallyFrame == NULL)
            {
                pFinallyFrame = pFrame;
            }
        }
        else if (il2c_unlikely__(filterNumber != IL2C_FILTER_NOMATCH))
        {
            // Already found finally block
            if (il2c_likely__(pFinallyFrame != NULL))
            {
                // Send to finally
                il2c_do_throw__(ex, pFinallyFrame, IL2C_FILTER_FINALLY, pThreadContext);
            }
            else
            {
                // NOTE: This place is the first-chance.
                // Send to catch
                il2c_do_throw__(ex, pFrame, filterNumber, pThreadContext);
            }
        }

        // Not matched: next frame.
        pFrame = pFrame->pNext;
    }

    // Already found finally block
    if (il2c_likely__(pFinallyFrame != NULL))
    {
        // Send to finally
        il2c_do_throw__(ex, pFinallyFrame, IL2C_FILTER_FINALLY, pThreadContext);
    }

    // Unhandled exception
    il2c_runtime_debug_log_format(
        L"Throw unhandled exception: type={0:s}, Message=\"{1:S}\"",
        (il2c_get_header__(ex))->type->pTypeName,
        (ex->message__->string_body__ != NULL) ? ex->message__->string_body__ : L"");

    il2c_invoke_unhandled_exception_on_the_current_domain__((System_Object*)ex);

    debug_break();

    il2c_assert(0);
}

il2c_noreturn__ void il2c_throw__(System_Exception* ex)
{
    il2c_assert(ex != NULL);

    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);
    il2c_assert(pThreadContext != NULL);

    // If this state is inside for caught block, skip current frame.
    // (Throwing new exception instance)
    IL2C_EXCEPTION_FRAME* pFrame =
        (pThreadContext->pUnwindTarget != NULL) ?
            ((pThreadContext->pUnwindTarget->ex != NULL) ? pThreadContext->pUnwindTarget->pNext : pThreadContext->pUnwindTarget) :
        NULL;

    il2c_throw_internal__(ex, pFrame, pThreadContext);
}

il2c_noreturn__ void il2c_rethrow(void)
{
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);
    il2c_assert(pThreadContext != NULL);

    il2c_assert(pThreadContext->pUnwindTarget != NULL);

    // If this state is inside for caught block
    if (il2c_likely__(pThreadContext->pUnwindTarget->ex != NULL))
    {
        // Unwind one frame.
        System_Exception* ex = pThreadContext->pUnwindTarget->ex;
        il2c_ixchgptr(&pThreadContext->pUnwindTarget, pThreadContext->pUnwindTarget->pNext);

        // Throw with this exception
        il2c_throw_internal__(ex, pThreadContext->pUnwindTarget, pThreadContext);
    }

    // Search nearest caught exception
    IL2C_EXCEPTION_FRAME* pFrame = pThreadContext->pUnwindTarget->pNext;
    while (il2c_likely__(pFrame != NULL))
    {
        // Found.
        System_Exception* ex = pFrame->ex;
        if (il2c_unlikely__(ex != NULL))
        {
            // Throw with this exception (at the current frame)
            il2c_throw_internal__(ex, pThreadContext->pUnwindTarget, pThreadContext);
        }
        pFrame = pFrame->pNext;
    }

    debug_break();

    // InvalidProgramException
    il2c_assert(0);
}

#if defined(IL2C_USE_SIGNAL)
static il2c_noreturn__ void il2c_SIGSEGV_handler(int sig)
{
    // NOTE 1:
    //   Run in windows, this handler called from SEH filter context from "_seh_filter_exe()".
    //   The SEH __try - __except() block contains at "__scrt_common_main_seh(),"
    //   the callgraph is:
    //     __scrt_common_main_seh() --> __try --> main() --> [SEGV] --> __except() --> _seh_filter_exe() --> handler()
    //   But the "__except(...)" expression has correct only EBP register except ESP register (!!)
    //   Therefore the "_seh_filter_exe()" called before NO any unroll stacks,
    //   the "handler()" function at deeper stack than "main(),"
    //   We can use the longjmp() and unwinding without any stack corruption.
    //   https://gist.github.com/kekyo/cc9bace942b8c2aa2484431e047d267d

    // NOTE 2:
    //   This handler allocate the NullReferenceException and finally unwind using the longjmp(),
    //   it's dangerous for some situations.
    //   For example, we'll call the "malloc()" function and if it causes SEGV (invalid pointer access) at inside malloc
    //   by the unknown issue, context is maybe unstable condition and will jump to this handler and
    //   the handler call malloc() function recursivity.
    //   It situation, all function will break and unstable our code.
    //   The IL2C currently NOT recovery it state, we'll approach for this problem:
    //     * We have to do not cause any SEGV issue at our using C runtime functions.
    //     * Unhook the handler before enter P/Invoke or external functions and
    //       rehook the handler after leave P/Invoke or external functions.
    //   These external functions may cause unknown problem and cause SEGV, we can't recover it state.
    //   https://wiki.sei.cmu.edu/confluence/display/c/SIG30-C.+Call+only+asynchronous-safe+functions+within+signal+handlers

    // Re-register
    signal(SIGSEGV, il2c_SIGSEGV_handler);

    il2c_throw_nullreferenceexception__();
}

typedef void (*il2c_sighandler)(int sig);

static il2c_sighandler g_SIGSEGV_saved = SIG_DFL;
#endif

/////////////////////////////////////////////////////////////
// IL2C runtime initialzer / shutdown

void il2c_initialize__(void)
{
    g_InitializerCount++;

    g_TlsIndex__ = il2c_tls_alloc();

    g_pBeginHeader__ = NULL;
    g_pBeginStaticFields__ = NULL;
    g_pRootReferences__ = NULL;
    g_pFixedReferences__ = NULL;

    memset(&g_MonitorLockBlockInformations[0], 0, sizeof g_MonitorLockBlockInformations);

    il2c_initialize_monitor_lock__(&g_GlobalLockForCollect__);

#if defined(_DEBUG)
    g_CollectCount = 0;
    g_CollectCountBreak = -1;
#endif

#ifdef IL2C_USE_SIGNAL
    g_SIGSEGV_saved = signal(SIGSEGV, il2c_SIGSEGV_handler);
#endif
}

void il2c_shutdown__(void)
{
    il2c_collect_for_final_shutdown__();

#ifdef IL2C_USE_SIGNAL
    signal(SIGSEGV, g_SIGSEGV_saved);
#endif

    il2c_destroy_monitor_lock__(&g_GlobalLockForCollect__);

    il2c_tls_free(g_TlsIndex__);
}

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

///////////////////////////////////////////////////////
// Basis exceptions

IL2C_CONST_STRING(il2c_null_reference_message, L"Object reference not set to an instance of an object.");

il2c_noreturn__ void il2c_throw_nullreferenceexception__(void)
{
    // TODO: can turn to static allocate for NullReferenceException?
    System_NullReferenceException* ex = il2c_get_uninitialized_object(System_NullReferenceException);
    System_NullReferenceException__ctor_1(ex, il2c_null_reference_message);
    il2c_throw(ex);
}

// NOTE: Hmm, the unbox failed message different to the castclass opcode...
//   IL2C choices short sentence by unbox operator message because better footprint.
//   .NET 4 castclass message format: "Unable to cast object of type 'Foo.Bar' to type 'System.String'."
IL2C_CONST_STRING(il2c_invalid_cast_message, L"Specified cast is not valid.");

il2c_noreturn__ void il2c_throw_invalidcastexception__(void)
{
    System_InvalidCastException* ex = il2c_get_uninitialized_object(System_InvalidCastException);
    System_InvalidCastException__ctor_1(ex, il2c_invalid_cast_message);
    il2c_throw(ex);
}

IL2C_CONST_STRING(il2c_index_out_of_range_message, L"Index was outside the bounds of the array.");

il2c_noreturn__ void il2c_throw_indexoutofrangeexception__(void)
{
    System_IndexOutOfRangeException* ex = il2c_get_uninitialized_object(System_IndexOutOfRangeException);
    System_IndexOutOfRangeException__ctor_1(ex, il2c_index_out_of_range_message);
    il2c_throw(ex);
}

IL2C_CONST_STRING(il2c_format_message, L"Input string was not in a correct format.");

il2c_noreturn__ void il2c_throw_formatexception__(void)
{
    System_FormatException* ex = il2c_get_uninitialized_object(System_FormatException);
    System_FormatException__ctor_1(ex, il2c_format_message);
    il2c_throw(ex);
}
