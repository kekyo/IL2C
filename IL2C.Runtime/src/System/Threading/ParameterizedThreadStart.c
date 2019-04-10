#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Threading.ParameterizedThreadStart

void System_Threading_ParameterizedThreadStart_Invoke(System_Threading_ParameterizedThreadStart* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->vptr0__ == &System_Delegate_VTABLE__);
    il2c_assert(this__->count__ >= 1);

    uintptr_t index = 0;
    do
    {
        IL2C_METHOD_TABLE* pMethodtbl = &this__->methodtbl__[index];
        if (pMethodtbl->target != NULL)
            ((void (*)(void*, System_Object*))(pMethodtbl->methodPtr))(pMethodtbl->target, obj);
        else
            ((void (*)(System_Object*))(pMethodtbl->methodPtr))(obj);
        index++;
    }
    while (il2c_unlikely__(index < this__->count__));
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_BEGIN(
    System_Threading_ParameterizedThreadStart,
    "System.Threading.ParameterizedThreadStart",
    IL2C_TYPE_VARIABLE | IL2C_TYPE_WITH_MARK_HANDLER,
    0,
    System_MulticastDelegate,
    System_Delegate_MarkHandler__,
    0)
IL2C_RUNTIME_TYPE_END();
