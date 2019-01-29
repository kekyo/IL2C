#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Threading.Thread

void System_Threading_Thread_Sleep(int millisecondsTimeout)
{
    il2c_sleep(millisecondsTimeout);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_STATIC(
    System_Threading_Thread,
    "System.Threading.Thread",
    System_Object);
