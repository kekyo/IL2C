#include "il2c_private.h"
#include "System.GC.h"

/////////////////////////////////////////////////////////////
// System.GC

void System_GC_Collect(void)
{
    il2c_collect();
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_STATIC(System_GC, "System.GC", System_Object);
