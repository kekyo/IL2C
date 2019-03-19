#include "il2c_private.h"

// TODO:
#include <process.h>

/////////////////////////////////////////////////////////////
// System.Threading.Thread

void System_Threading_Thread__ctor(System_Threading_Thread* this__, System_Threading_ThreadStart* start)
{
    il2c_assert(this__ != NULL);

    // TODO: ArgumentNullException
    il2c_assert(start != NULL);

    this__->start__ = (System_Delegate*)start;
}

extern IL2C_TLS_INDEX g_TlsIndex__;

static IL2C_THREAD_ENTRY_POINT_RESULT_TYPE System_Threading_Thread_InternalEntryPoint(
    IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE parameter)
{
    il2c_assert(parameter != NULL);

    System_Threading_Thread* pThread = (System_Threading_Thread*)parameter;

    // Set real thread id.
    pThread->id__ = il2c_get_current_thread_id__();

    // Save IL2C_THREAD_CONTROL_BLOCK into tls.
    il2c_set_tls_value(g_TlsIndex__, (void*)&pThread->pFrame__);

    il2c_assert(pThread->vptr0__ == &System_Threading_Thread_VTABLE__);
    il2c_assert(il2c_isinst(pThread->start__, System_Threading_ThreadStart) != NULL);

    // It's naive for passing handle if startup with suspending not implemented. (pthread)
    while (pThread->rawHandle__ == 0);

    // Invoke delegate.
    // TODO: catch exception.
    System_Threading_ThreadStart_Invoke((System_Threading_ThreadStart*)(pThread->start__));

    // Unregister.
    il2c_unregister_fixed_instance__(pThread);

#if defined(_DEBUG)
    il2c_set_tls_value(g_TlsIndex__, NULL);
#endif

    _endthreadex(0);

    IL2C_THREAD_ENTRY_POINT_RETURN(0);
}

void System_Threading_Thread_Start(System_Threading_Thread* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->start__ != NULL);

    // TODO: ThreadStateException
    il2c_assert(this__->rawHandle__ == 0);

    // Register into statically resource.
    il2c_register_fixed_instance__(this__);

    // Create (suspended if available) thread.
    intptr_t rawHandle = il2c_create_thread__(
        System_Threading_Thread_InternalEntryPoint, this__);

    // TODO: OutOfMemoryException
    il2c_assert(rawHandle > 0);

    // It's naive for passing handle if startup with suspending not implemented. (pthread)
    il2c_ixchgptr(&this__->rawHandle__, rawHandle);
    il2c_resume_thread__(rawHandle);
}

void System_Threading_Thread_Join(System_Threading_Thread* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->rawHandle__ != 0);
    il2c_assert(this__->start__ != NULL);

    il2c_join_thread__(this__->rawHandle__);
}

int32_t System_Threading_Thread_get_ManagedThreadId(System_Threading_Thread* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->rawHandle__ != 0);

    return this__->id__;
}

System_Threading_Thread* System_Threading_Thread_get_CurrentThread()
{
    // NOTE: Will assertion failed if doesn't construct any execution frames.
    //   But maybe construct it because we'll save the Thread instance into execution frame strcuture...
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);
    il2c_assert(pThreadContext != NULL);

    // Come from unoffsetted:
    return (System_Threading_Thread*)((*(uint8_t*)pThreadContext) - offsetof(System_Threading_Thread, pFrame__));
}

void System_Threading_Thread_Sleep(int millisecondsTimeout)
{
    il2c_sleep((uint32_t)millisecondsTimeout);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_BEGIN(System_Threading_Thread, "System.Threading.Thread", IL2C_TYPE_REFERENCE, sizeof(System_Threading_Thread), System_Object, 1, 0)
IL2C_RUNTIME_TYPE_MARK_TARGET_FOR_REFERENCE(System_Threading_Thread, start__)
IL2C_RUNTIME_TYPE_END();
