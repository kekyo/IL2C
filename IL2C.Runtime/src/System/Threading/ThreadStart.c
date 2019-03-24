#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Threading.ThreadStart

void System_Threading_ThreadStart_Invoke(System_Threading_ThreadStart* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->vptr0__ == &System_Delegate_VTABLE__);
    il2c_assert(this__->count__ >= 1);

    uintptr_t index = 0;
    do
    {
        IL2C_METHOD_TABLE* pMethodtbl = &this__->methodtbl__[index];
        if (pMethodtbl->target != NULL)
            ((void (*)(void*))(pMethodtbl->methodPtr))(pMethodtbl->target);
        else
            ((void (*)(void))(pMethodtbl->methodPtr))();
        index++;
    }
    while (index < this__->count__);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_BEGIN(
    System_Threading_ThreadStart,
    "System.Threading.ThreadStart",
    IL2C_TYPE_REFERENCE,
    sizeof(System_Threading_ThreadStart),
    System_MulticastDelegate,
    0, 0)
IL2C_RUNTIME_TYPE_END();
