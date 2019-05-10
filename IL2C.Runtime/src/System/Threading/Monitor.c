#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// Monitor lock infrastructures

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

IL2C_MONITOR_LOCK_BLOCK_INFORMATION* g_MonitorLockBlockInformations__[7] = { NULL };

static IL2C_MONITOR_LOCK* il2c_acquire_monitor_lock_from_objref__(void* pReference, bool allocateIfRequired)
{
    il2c_assert(pReference != NULL);

    System_Object* pAdjustedReference = il2c_adjusted_reference(pReference);

    const uint8_t blockIndex =
        (uint8_t)(((uintptr_t)pAdjustedReference) %
        (uint8_t)(sizeof(g_MonitorLockBlockInformations__) / sizeof(IL2C_MONITOR_LOCK_BLOCK_INFORMATION*)));

    // Step 1: Get IL2C_MONITOR_LOCK_BLOCK.
    IL2C_MONITOR_LOCK_BLOCK_INFORMATION* pMonitorBlockInformation = g_MonitorLockBlockInformations__[blockIndex];
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
            &g_MonitorLockBlockInformations__[blockIndex], pMonitorBlockInformation, NULL);
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
            if (il2c_unlikely__((pHeader->characteristic & IL2C_CHARACTERISTIC_CONST) == 0))
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

void il2c_release_monitor_lock_from_objref__(IL2C_REF_HEADER* pHeader)
{
    il2c_assert(pHeader != NULL);
    il2c_assert((pHeader->characteristic & (IL2C_CHARACTERISTIC_CONST | IL2C_CHARACTERISTIC_ACQUIRED_MONITOR_LOCK)));

    System_Object* pAdjustedReference = (System_Object*)(((uint8_t*)pHeader) + sizeof(IL2C_REF_HEADER));

    const uint8_t blockIndex =
        (uint8_t)(((uintptr_t)pAdjustedReference) %
        (uint8_t)(sizeof(g_MonitorLockBlockInformations__) / sizeof(IL2C_MONITOR_LOCK_BLOCK_INFORMATION*)));

    IL2C_MONITOR_LOCK_BLOCK_INFORMATION* pMonitorBlockInformation = g_MonitorLockBlockInformations__[blockIndex];
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

void il2c_release_all_monitor_lock_for_final_shutdown__(void)
{
    IL2C_MONITOR_LOCK_BLOCK_INFORMATION** ppMonitorBlockInformation;
    uint8_t blockIndex;
    for (blockIndex = 0, ppMonitorBlockInformation = &g_MonitorLockBlockInformations__[0];
        blockIndex < (sizeof(g_MonitorLockBlockInformations__) / sizeof(IL2C_MONITOR_LOCK_BLOCK_INFORMATION*));
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
            } while (il2c_unlikely__(pCurrentBlock != NULL));

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
// System.Threading.Monitor

void System_Threading_Monitor_Enter__System_Object(System_Object* obj)
{
    // TODO: ArgumentNullException
    il2c_assert(obj != NULL);

    IL2C_MONITOR_LOCK* pLock = il2c_acquire_monitor_lock_from_objref__(obj, true);
    il2c_assert(pLock != NULL);

    il2c_enter_monitor_lock__(pLock);
}

void System_Threading_Monitor_Enter__System_Object_System_Boolean_REF(System_Object* obj, bool* lockTaken)
{
    il2c_assert(lockTaken != NULL);

    // TODO: ArgumentNullException
    il2c_assert(obj != NULL);

    IL2C_MONITOR_LOCK* pLock = il2c_acquire_monitor_lock_from_objref__(obj, true);
    il2c_assert(pLock != NULL);

    il2c_enter_monitor_lock__(pLock);

    // TODO: DANGER SECTION: cannot interrupt thread at this line.

    *lockTaken = true;
}

bool System_Threading_Monitor_TryEnter__System_Object(System_Object* obj)
{
    // TODO: ArgumentNullException
    il2c_assert(obj != NULL);

    IL2C_MONITOR_LOCK* pLock = il2c_acquire_monitor_lock_from_objref__(obj, true);
    il2c_assert(pLock != NULL);

    return il2c_try_enter_monitor_lock__(pLock);
}

void System_Threading_Monitor_TryEnter__System_Object_System_Boolean_REF(System_Object* obj, bool* lockTaken)
{
    il2c_assert(lockTaken != NULL);

    // TODO: ArgumentNullException
    il2c_assert(obj != NULL);

    IL2C_MONITOR_LOCK* pLock = il2c_acquire_monitor_lock_from_objref__(obj, true);
    il2c_assert(pLock != NULL);

    *lockTaken = il2c_try_enter_monitor_lock__(pLock);
}

void System_Threading_Monitor_Exit__System_Object(System_Object* obj)
{
    // TODO: ArgumentNullException
    il2c_assert(obj != NULL);

    IL2C_MONITOR_LOCK* pLock = il2c_acquire_monitor_lock_from_objref__(obj, false);

    // TODO: SynchronizationLockException
    il2c_assert(pLock != NULL);

    il2c_exit_monitor_lock__(pLock);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_STATIC(
    System_Threading_Monitor,
    "System.Threading.Monitor",
    System_Object);
