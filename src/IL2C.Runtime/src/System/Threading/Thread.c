#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Threading.Thread

extern IL2C_TLS_INDEX g_TlsIndex__;

void System_Threading_Thread_Finalize(System_Threading_Thread* this__)
{
    il2c_assert(this__ != NULL);

    IL2C_RUNTIME_CREATED_THREAD* pRuntimeThread = (IL2C_RUNTIME_CREATED_THREAD*)this__;

    const intptr_t rawHandle = (intptr_t)il2c_ixchgptr(&pRuntimeThread->context.rawHandle, (intptr_t)-1);
    if (il2c_likely__(rawHandle != -1))
    {
        il2c_close_thread_handle__(pRuntimeThread->context.rawHandle);

#if !defined(IL2C_USE_RUNTIME_GIANT_LOCK)
        // HACK: The finalizer is called from GC processes,
        //   so the lock already acquired at beginning collection (il2c_enter_for_collect__).
        //   And, all instance's lock except thread are freeing at il2c_exit_for_collect__(),
        //   but the thread instance will free and cannot find in it.
        il2c_exit_monitor_lock__((void*)&pRuntimeThread->context.lockForCollect);
#endif

        il2c_destroy_monitor_lock__((void*)&pRuntimeThread->context.lockForCollect);

#if defined(_DEBUG)
        pRuntimeThread->context.rawHandle = -1;
        pRuntimeThread->context.id = 0;
        if (this__->start__ != NULL)
        {
            pRuntimeThread->parameter = NULL;
            this__->start__ = NULL;
        }
#endif
    }
}

static int16_t System_Threading_Thread_InternalExceptionFilter(System_Exception* ex)
{
    il2c_assert(ex != NULL);
    return 1;
}

static IL2C_THREAD_ENTRY_POINT_RESULT_TYPE System_Threading_Thread_InternalEntryPoint(
    IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE parameter)
{
    il2c_assert(parameter != NULL);

    IL2C_RUNTIME_CREATED_THREAD* pRuntimeThread = (IL2C_RUNTIME_CREATED_THREAD*)parameter;
    il2c_assert(pRuntimeThread->thread.vptr0__ == &System_Threading_Thread_VTABLE__);
    il2c_assert(il2c_isinst(pRuntimeThread->thread.start__, System_Threading_ThreadStart) != NULL);
    il2c_assert(pRuntimeThread->parameter == NULL);
    il2c_assert(pRuntimeThread->bottomFrame.pNext__ == NULL);
    il2c_assert(pRuntimeThread->bottomFrame.objRefCount__ == 0);
    il2c_assert(pRuntimeThread->bottomFrame.valueCount__ == 0);
    il2c_assert(pRuntimeThread->bottomFrame.exception__ == NULL);

    // Set real thread id.
    pRuntimeThread->context.id = il2c_get_current_thread_id__();

    // Save IL2C_THREAD_CONTEXT into tls.
    il2c_set_tls_value(g_TlsIndex__, (void*)&pRuntimeThread->context.pFrame);

    // It's naive for passing handle if startup with suspending not implemented. (pthread/FreeRTOS)
    while (pRuntimeThread->context.rawHandle == -1);

    pRuntimeThread->bottomFrame.objRefCount__ = 1;
    il2c_link_execution_frame(&pRuntimeThread->bottomFrame);

    il2c_try(bottomNest, System_Threading_Thread_InternalExceptionFilter)
    {
        // Invoke delegate.
        System_Threading_ThreadStart_Invoke(
            (System_Threading_ThreadStart*)(pRuntimeThread->thread.start__));
        il2c_leave(bottomNest, 0);
    }
    il2c_catch(bottomNest, 1, pRuntimeThread->bottomFrame.exception__)
    {
        il2c_invoke_unhandled_exception_on_the_current_domain__(
            (System_Object*)pRuntimeThread->bottomFrame.exception__);
        il2c_leave(bottomNest, 0);
    }
    il2c_leave_to(bottomNest)
    {
        il2c_leave_bind(bottomNest, 0, exit);
    }
    il2c_end_try(bottomNest);

exit:
    il2c_unlink_execution_frame(&pRuntimeThread->bottomFrame, NULL);

#if defined(_DEBUG)
    il2c_set_tls_value(g_TlsIndex__, NULL);
#endif

    // Unregister GC root tracking.
    il2c_unregister_root_reference__((void*)pRuntimeThread, false);

    IL2C_THREAD_ENTRY_POINT_RETURN(0);
}

static IL2C_THREAD_ENTRY_POINT_RESULT_TYPE System_Threading_Thread_InternalEntryPointWithParameter(
    IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE parameter)
{
    il2c_assert(parameter != NULL);

    IL2C_RUNTIME_CREATED_THREAD* pRuntimeThread = (IL2C_RUNTIME_CREATED_THREAD*)parameter;
    il2c_assert(pRuntimeThread->thread.vptr0__ == &System_Threading_Thread_VTABLE__);
    il2c_assert(il2c_isinst(pRuntimeThread->thread.start__, System_Threading_ParameterizedThreadStart) != NULL);
    il2c_assert(pRuntimeThread->bottomFrame.pNext__ == NULL);
    il2c_assert(pRuntimeThread->bottomFrame.objRefCount__ == 0);
    il2c_assert(pRuntimeThread->bottomFrame.valueCount__ == 0);
    il2c_assert(pRuntimeThread->bottomFrame.exception__ == NULL);

    // Set real thread id.
    pRuntimeThread->context.id = il2c_get_current_thread_id__();

    // Save IL2C_THREAD_CONTEXT into tls.
    il2c_set_tls_value(g_TlsIndex__, (void*)&pRuntimeThread->context.pFrame);

    // It's naive for passing handle if startup with suspending not implemented. (pthread/FreeRTOS)
    while (pRuntimeThread->context.rawHandle == -1);

    pRuntimeThread->bottomFrame.objRefCount__ = 1;
    il2c_link_execution_frame(&pRuntimeThread->bottomFrame);

    il2c_try(bottomNest, System_Threading_Thread_InternalExceptionFilter)
    {
        // Invoke delegate.
        System_Threading_ParameterizedThreadStart_Invoke(
            (System_Threading_ParameterizedThreadStart*)(pRuntimeThread->thread.start__), pRuntimeThread->parameter);
        il2c_leave(bottomNest, 0);
    }
    il2c_catch(bottomNest, 1, pRuntimeThread->bottomFrame.exception__)
    {
        il2c_invoke_unhandled_exception_on_the_current_domain__(
            (System_Object*)pRuntimeThread->bottomFrame.exception__);
        il2c_leave(bottomNest, 0);
    }
    il2c_leave_to(bottomNest)
    {
        il2c_leave_bind(bottomNest, 0, exit);
    }
    il2c_end_try(bottomNest);

exit:
    il2c_unlink_execution_frame(&pRuntimeThread->bottomFrame, NULL);

#if defined(_DEBUG)
    il2c_set_tls_value(g_TlsIndex__, NULL);
#endif

    // Unregister GC root tracking.
    il2c_unregister_root_reference__((void*)pRuntimeThread, false);

    IL2C_THREAD_ENTRY_POINT_RETURN(0);
}

void System_Threading_Thread_Start(System_Threading_Thread* this__)
{
    il2c_assert(this__ != NULL);

    // TODO: InvalidOperationException? (Auto attached managed thread)
    il2c_assert(this__->start__ != NULL);

    IL2C_RUNTIME_CREATED_THREAD* pRuntimeThread = (IL2C_RUNTIME_CREATED_THREAD*)this__;

    // TODO: ThreadStateException? (Already started)
    il2c_assert(pRuntimeThread->context.rawHandle == -1);

    // Register GC root tracking.
    il2c_register_root_reference__(this__, false);

    // Create (suspended if available) thread.
    intptr_t rawHandle = il2c_create_thread__(
        System_Threading_Thread_InternalEntryPoint, this__);

    // TODO: OutOfMemoryException (have to unlink from root)
    il2c_assert(rawHandle >= 0);

    // It's naive for passing handle if startup with suspending not implemented. (pthread/FreeRTOS)
    pRuntimeThread->context.rawHandle = rawHandle;
    il2c_resume_thread__(rawHandle);
}

void System_Threading_Thread_Start__System_Object(System_Threading_Thread* this__, System_Object* parameter)
{
    il2c_assert(this__ != NULL);

    // TODO: InvalidOperationException? (Auto attached managed thread)
    il2c_assert(this__->start__ != NULL);

    IL2C_RUNTIME_CREATED_THREAD* pRuntimeThread = (IL2C_RUNTIME_CREATED_THREAD*)this__;

    // TODO: ThreadStateException? (Already started)
    il2c_assert(pRuntimeThread->context.rawHandle == -1);

    // Register GC root tracking.
    il2c_register_root_reference__(this__, false);

    // Store parameter
    pRuntimeThread->parameter = parameter;

    // Create (suspended if available) thread.
    intptr_t rawHandle = il2c_create_thread__(
        System_Threading_Thread_InternalEntryPointWithParameter, this__);

    // TODO: OutOfMemoryException (have to unlink from root)
    il2c_assert(rawHandle >= 0);

    // It's naive for passing handle if startup with suspending not implemented. (pthread/FreeRTOS)
    pRuntimeThread->context.rawHandle = rawHandle;
    il2c_resume_thread__(rawHandle);
}

void System_Threading_Thread_Join(System_Threading_Thread* this__)
{
    il2c_assert(this__ != NULL);

    IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)this__;

    il2c_assert(this__->start__ != NULL);
    il2c_assert(pRuntimeThread->context.rawHandle >= 0);

    il2c_join_thread__(pRuntimeThread->context.rawHandle);
}

int32_t System_Threading_Thread_get_ManagedThreadId(System_Threading_Thread* this__)
{
    il2c_assert(this__ != NULL);

    IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)this__;
    return pRuntimeThread->context.id;
}

System_Threading_Thread* System_Threading_Thread_get_CurrentThread(void)
{
    // Get thread context.
#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(__FILE__, __LINE__);
#else
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    // Come from unoffsetted:
    return (System_Threading_Thread*)(((uint8_t*)pThreadContext) - offsetof(IL2C_RUNTIME_THREAD, context));
}

void System_Threading_Thread_Sleep__System_Int32(int millisecondsTimeout)
{
    il2c_sleep((uint32_t)millisecondsTimeout);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

static void System_Threading_Thread_MarkHandler__(System_Threading_Thread* thread)
{
    il2c_assert(thread != NULL);
    il2c_assert(thread->vptr0__ == &System_Threading_Thread_VTABLE__);

    IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)thread;

    // Check start and parameter field.
    if (il2c_likely__(pRuntimeThread->thread.start__ != NULL))
    {
        il2c_default_mark_handler_for_objref__(pRuntimeThread->thread.start__);

        IL2C_RUNTIME_CREATED_THREAD* pRuntimeCreatedThread = (IL2C_RUNTIME_CREATED_THREAD*)pRuntimeThread;
        if (pRuntimeCreatedThread->parameter != NULL)
        {
            il2c_default_mark_handler_for_objref__(pRuntimeCreatedThread->parameter);
        }
    }

    // Check temporary reference anchor.
    if (il2c_likely__(pRuntimeThread->context.pTemporaryReferenceAnchor != NULL))
    {
        il2c_default_mark_handler_for_objref__(pRuntimeThread->context.pTemporaryReferenceAnchor);
    }

    ///////////////////////////////////////////////////////////////
    // Check IL2C_EXECUTION_FRAME.
    // It's important step for GC collecting sequence.
    // All method execution frame traversal begins this location.

    if (il2c_likely__(pRuntimeThread->context.pFrame != NULL))
    {
        il2c_default_mark_handler_for_tracking_information__(pRuntimeThread->context.pFrame);
    }
}

System_Threading_Thread_VTABLE_DECL__ System_Threading_Thread_VTABLE__ = {
    0, // Adjustor offset
    (bool(*)(void*, System_Object*))System_Object_Equals__System_Object,
    (void(*)(void*))System_Threading_Thread_Finalize,
    (int32_t(*)(void*))System_Object_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString
};

// If System_Threading_Thread is allocated by il2c_get_uninitialized_object(),
// the storage space contains additional spaces by IL2C_RUNTIME_THREAD tail fields.
IL2C_RUNTIME_TYPE_BEGIN(
    System_Threading_Thread,
    "System.Threading.Thread",
    IL2C_TYPE_REFERENCE | IL2C_TYPE_VARIABLE | IL2C_TYPE_WITH_MARK_HANDLER,
    0,
    System_Object,
    System_Threading_Thread_MarkHandler__,
    0)
IL2C_RUNTIME_TYPE_END();
