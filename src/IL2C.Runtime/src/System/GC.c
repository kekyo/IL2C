#include "il2c_private.h"
#include <System/GC.h>

extern volatile uint32_t g_PendingRemains__;

/////////////////////////////////////////////////////////////
// System.GC

void System_GC_SuppressFinalize__System_Object(System_Object* obj)
{
    // TODO: ArgumentNullException
    il2c_assert(obj != NULL);

    IL2C_REF_HEADER* pHeader = il2c_get_header__(obj);

    // TODO: Check overriding finalizer.
    il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_FINALIZER_CALLED);
}

void System_GC_ReRegisterForFinalize__System_Object(System_Object* obj)
{
    // TODO: ArgumentNullException
    il2c_assert(obj != NULL);

    IL2C_REF_HEADER* pHeader = il2c_get_header__(obj);

    // TODO: Check overriding finalizer.
    il2c_iand(&pHeader->characteristic, ~IL2C_CHARACTERISTIC_FINALIZER_CALLED);
}

void System_GC_Collect(void)
{
    il2c_collect();
}

void System_GC_WaitForPendingFinalizers(void)
{
    while (g_PendingRemains__ >= 1)
    {
        il2c_collect();
    }
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_STATIC(
    System_GC,
    "System.GC",
    System_Object);
