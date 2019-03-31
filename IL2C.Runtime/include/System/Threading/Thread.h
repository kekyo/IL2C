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

    /* IL2C_THREAD_CONTEXT: Important field order! */
    IL2C_EXECUTION_FRAME* pFrame__;
    IL2C_EXCEPTION_FRAME* pUnwindTarget__;
    volatile intptr_t rawHandle__;
    int32_t id__;

    System_Delegate* start__;
    System_Object* parameter__;
};

extern System_Threading_Thread_VTABLE_DECL__ System_Threading_Thread_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Threading_Thread);

extern void System_Threading_Thread__ctor(System_Threading_Thread* this__, System_Threading_ThreadStart* start);
extern void System_Threading_Thread__ctor_1(System_Threading_Thread* this__, System_Threading_ParameterizedThreadStart* start);
extern void System_Threading_Thread_Finalize(System_Threading_Thread* this__);
extern void System_Threading_Thread_Start(System_Threading_Thread* this__);
extern void System_Threading_Thread_Start_2(System_Threading_Thread* this__, System_Object* parameter);
extern void System_Threading_Thread_Join(System_Threading_Thread* this__);
#define System_Threading_Thread_get_ManagedThreadId(this__) ((int32_t)(this__->id__))
extern /* static */ System_Threading_Thread* System_Threading_Thread_get_CurrentThread(void);
extern /* static */ void System_Threading_Thread_Sleep(int millisecondsTimeout);

#ifdef __cplusplus
}
#endif

#endif
