#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.MulticastDelegate

// All members transfered to System.Delegate.

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_MulticastDelegate_RUNTIME_TYPE__ = {
    "System.MulticastDelegate",
    IL2C_TYPE_VARIABLE,
    0,
    /* internalcall */ (IL2C_MARK_HANDLER)__System_Delegate_IL2C_MarkHandler__,
    il2c_typeof(System_Delegate)
};
