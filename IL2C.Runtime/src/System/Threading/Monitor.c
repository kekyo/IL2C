#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Threading.Monitor

typedef struct IL2C_MONITOR_LOCK_BLOCK_DECL IL2C_MONITOR_LOCK_BLOCK;

struct IL2C_MONITOR_LOCK_BLOCK_DECL
{
    IL2C_MONITOR_LOCK_BLOCK* pNext;
    volatile void* pReferences[4];
    IL2C_MONITOR_LOCK locks[4];
};

typedef struct IL2C_MONITOR_LOCK_BLOCK_INFORMATION_DECL IL2C_MONITOR_LOCK_BLOCK_INFORMATION;

struct IL2C_MONITOR_LOCK_BLOCK_INFORMATION_DECL
{
    IL2C_MONITOR_LOCK blockLock;
    IL2C_MONITOR_LOCK_BLOCK block0;
};

static IL2C_MONITOR_LOCK_BLOCK_INFORMATION* g_MonitorLockBlockInformations[7] = { NULL };

static IL2C_MONITOR_LOCK* il2c_get_monitor_lock__(System_Object* pReference, const bool allocateIfRequired)
{
    il2c_assert(pReference != NULL);

    const uint8_t blockIndex =
        (uint8_t)(((uint32_t)(uintptr_t)pReference) %
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
        pMonitorBlockInformation = il2c_malloc(sizeof(IL2C_MONITOR_LOCK_BLOCK_INFORMATION));
        memset(pMonitorBlockInformation, 0, sizeof *pMonitorBlockInformation);
        il2c_initialize_monitor_lock__(&pMonitorBlockInformation->blockLock);

        // TODO: NotEnoughMemoryException
        il2c_assert(pMonitorBlockInformation != NULL);

        IL2C_MONITOR_LOCK_BLOCK_INFORMATION* p = il2c_icmpxchgptr(&g_MonitorLockBlockInformations[blockIndex], pMonitorBlockInformation, NULL);
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
        volatile void** ppReference;
        uint8_t index;
        for (index = 0, ppReference = pCurrentBlock->pReferences;
            il2c_likely__(index < (sizeof(pCurrentBlock->pReferences) / sizeof(void*)));
            index++, ppReference++)
        {
            // Already assigned.
            if (il2c_unlikely__(*ppReference == pReference))
            {
                IL2C_MONITOR_LOCK* pLock = &pCurrentBlock->locks[index];

                il2c_exit_monitor_lock__(&pMonitorBlockInformation->blockLock);
                return pLock;
            }
            // Found free slot.
            if (il2c_unlikely__((*ppReference == NULL) && allocateIfRequired))
            {
                *ppReference = pReference;

                IL2C_MONITOR_LOCK* pLock = &pCurrentBlock->locks[index];
                il2c_initialize_monitor_lock__(pLock);

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
            IL2C_MONITOR_LOCK_BLOCK* pNext = il2c_malloc(sizeof(IL2C_MONITOR_LOCK_BLOCK));
            memset(pNext, 0, sizeof *pNext);

            if (il2c_likely__(il2c_icmpxchgptr(&pCurrentBlock->pNext, pNext, NULL) == NULL))
            {
                IL2C_MONITOR_LOCK* pLock = &pNext->locks[index];

                il2c_exit_monitor_lock__(&pMonitorBlockInformation->blockLock);
                return pLock;
            }
        }

        pCurrentBlock = pCurrentBlock->pNext;
    }
}

void System_Threading_Monitor_Enter(System_Object* obj)
{
    // TODO: ArgumentNullException
    il2c_assert(obj != NULL);

    IL2C_MONITOR_LOCK* pLock = il2c_get_monitor_lock__(obj, true);
    il2c_assert(pLock != NULL);

    il2c_enter_monitor_lock__(pLock);
}

void System_Threading_Monitor_Enter_1(System_Object* obj, bool* lockTaken)
{
    il2c_assert(lockTaken != NULL);

    // TODO: ArgumentNullException
    il2c_assert(obj != NULL);

    IL2C_MONITOR_LOCK* pLock = il2c_get_monitor_lock__(obj, true);
    il2c_assert(pLock != NULL);

    il2c_enter_monitor_lock__(pLock);

    // TODO: DANGER SECTION: cannot interrupt thread at this line.

    *lockTaken = true;
}

void System_Threading_Monitor_Exit(System_Object* obj)
{
    // TODO: ArgumentNullException
    il2c_assert(obj != NULL);

    IL2C_MONITOR_LOCK* pLock = il2c_get_monitor_lock__(obj, false);

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
