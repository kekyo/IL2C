#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Threading.Monitor

void System_Threading_Monitor_Enter(System_Object* obj)
{
    // TODO: ArgumentNullException
    il2c_assert(obj != NULL);

    IL2C_MONITOR_LOCK* pLock = il2c_acquire_monitor_lock_from_objref__(obj, true);
    il2c_assert(pLock != NULL);

    il2c_enter_monitor_lock__(pLock);
}

void System_Threading_Monitor_Enter_1(System_Object* obj, bool* lockTaken)
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

void System_Threading_Monitor_Exit(System_Object* obj)
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
