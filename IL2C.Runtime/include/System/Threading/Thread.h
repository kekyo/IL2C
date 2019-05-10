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
    System_Delegate* start__;
};

extern System_Threading_Thread_VTABLE_DECL__ System_Threading_Thread_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Threading_Thread);

extern void System_Threading_Thread_Finalize(System_Threading_Thread* this__);
extern void System_Threading_Thread_Start(System_Threading_Thread* this__);
extern void System_Threading_Thread_Start__System_Object(System_Threading_Thread* this__, System_Object* parameter);
extern void System_Threading_Thread_Join(System_Threading_Thread* this__);
extern int32_t System_Threading_Thread_get_ManagedThreadId(System_Threading_Thread* this__);
extern /* static */ System_Threading_Thread* System_Threading_Thread_get_CurrentThread(void);
extern /* static */ void System_Threading_Thread_Sleep__System_Int32(int millisecondsTimeout);

#if defined(IL2C_USE_LINE_INFORMATION)
extern System_Threading_Thread* il2c_new_thread__(System_Delegate* start, const char* pFile, int line);
#define il2c_new_thread(start) il2c_new_thread__(start, __FILE__, __LINE__)
#else
extern System_Threading_Thread* il2c_new_thread__(System_Delegate* start);
#define il2c_new_thread(start) il2c_new_thread__(start)
#endif

#ifdef __cplusplus
}
#endif

#endif
