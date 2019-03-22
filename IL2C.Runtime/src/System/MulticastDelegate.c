#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.MulticastDelegate

// All members transfered to System.Delegate.

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_BEGIN(
    System_MulticastDelegate,
    "System.MulticastDelegate",
    IL2C_TYPE_VARIABLE | IL2C_TYPE_WITH_MARK_HANDLER,
    0,
    System_Delegate,
    System_Delegate_MarkHandler__,
    0)
IL2C_RUNTIME_TYPE_END();
