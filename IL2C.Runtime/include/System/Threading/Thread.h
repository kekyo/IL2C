#ifndef System_Threading_Thread_H__
#define System_Threading_Thread_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Threading.Thread

typedef struct System_Threading_Thread System_Threading_Thread;

typedef System_Object_VTABLE_DECL__ System_Threading_Thread_VTABLE_DECL__;

struct System_Threading_Thread
{
    System_Threading_Thread_VTABLE_DECL__* vptr0__;

    /* IL2C_THREAD_CONTROL_BLOCK: Important field order! */
    IL2C_EXECUTION_FRAME* pFrame__;
    IL2C_EXCEPTION_FRAME* pTopUnwindTarget__;
    volatile intptr_t rawHandle__;
    int32_t id__;

    System_Delegate* start__;
};

#define System_Threading_Thread_VTABLE__ System_Object_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_Threading_Thread);

extern void System_Threading_Thread__ctor(System_Threading_Thread* this__, System_Threading_ThreadStart* start);
extern void System_Threading_Thread_Start(System_Threading_Thread* this__);
extern void System_Threading_Thread_Join(System_Threading_Thread* this__);
extern int32_t System_Threading_Thread_get_ManagedThreadId(System_Threading_Thread* this__);

extern /* static */ System_Threading_Thread* System_Threading_Thread_get_CurrentThread();
extern /* static */ void System_Threading_Thread_Sleep(int millisecondsTimeout);

#ifdef __cplusplus
}
#endif

#endif
