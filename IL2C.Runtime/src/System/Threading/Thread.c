#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Threading.Thread

typedef volatile struct IL2C_RUNTIME_THREAD_BOTTOM_EXECUTION_FRAME /* IL2C_EXECUTION_FRAME */
{
    IL2C_EXECUTION_FRAME* pNext__;
    uint16_t objRefCount__;
    uint16_t valueCount__;
    System_Exception* exception__;
} IL2C_RUNTIME_THREAD_BOTTOM_EXECUTION_FRAME;

// The real thread structure.
typedef volatile struct IL2C_RUNTIME_THREAD
{
    System_Threading_Thread thread;
    IL2C_RUNTIME_THREAD_BOTTOM_EXECUTION_FRAME bottomFrame__;
} IL2C_RUNTIME_THREAD;

void System_Threading_Thread__ctor(System_Threading_Thread* this__, System_Threading_ThreadStart* start)
{
    il2c_assert(this__ != NULL);

    // TODO: ArgumentNullException
    il2c_assert(start != NULL);

    IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)this__;

    pRuntimeThread->thread.start__ = (System_Delegate*)start;
    pRuntimeThread->thread.rawHandle__ = -1;
}

void System_Threading_Thread__ctor_1(System_Threading_Thread* this__, System_Threading_ParameterizedThreadStart* start)
{
    il2c_assert(this__ != NULL);

    // TODO: ArgumentNullException
    il2c_assert(start != NULL);

    IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)this__;

    pRuntimeThread->thread.start__ = (System_Delegate*)start;
    pRuntimeThread->thread.rawHandle__ = -1;
}

extern IL2C_TLS_INDEX g_TlsIndex__;

void System_Threading_Thread_Finalize(System_Threading_Thread* this__)
{
    il2c_assert(this__ != NULL);

    if (il2c_likely__(this__->rawHandle__ != -1))
    {
        il2c_close_thread_handle__(this__->rawHandle__);
#if defined(_DEBUG)
        this__->rawHandle__ = -1;
        this__->id__ = 0;
        this__->start__ = NULL;
        this__->parameter__ = NULL;
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

    IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)parameter;
    il2c_assert(pRuntimeThread->thread.vptr0__ == &System_Threading_Thread_VTABLE__);
    il2c_assert(il2c_isinst(pRuntimeThread->thread.start__, System_Threading_ThreadStart) != NULL);
    il2c_assert(pRuntimeThread->thread.parameter__ == NULL);
    il2c_assert(pRuntimeThread->bottomFrame__.pNext__ == NULL);
    il2c_assert(pRuntimeThread->bottomFrame__.objRefCount__ == 0);
    il2c_assert(pRuntimeThread->bottomFrame__.valueCount__ == 0);
    il2c_assert(pRuntimeThread->bottomFrame__.exception__ == NULL);

    // Set real thread id.
    pRuntimeThread->thread.id__ = il2c_get_current_thread_id__();

    // Save IL2C_THREAD_CONTEXT into tls.
    il2c_set_tls_value(g_TlsIndex__, (void*)&pRuntimeThread->thread.pFrame__);

    // It's naive for passing handle if startup with suspending not implemented. (pthread/FreeRTOS)
    while (pRuntimeThread->thread.rawHandle__ == -1);

    pRuntimeThread->bottomFrame__.objRefCount__ = 1;
    il2c_link_execution_frame(&pRuntimeThread->bottomFrame__);

    il2c_try(bottomNest, System_Threading_Thread_InternalExceptionFilter)
    {
        // Invoke delegate.
        System_Threading_ThreadStart_Invoke(
            (System_Threading_ThreadStart*)(pRuntimeThread->thread.start__));
        il2c_leave(bottomNest, 0);
    }
    il2c_catch(bottomNest, 1, pRuntimeThread->bottomFrame__.exception__)
    {
        il2c_invoke_unhandled_exception_on_the_current_domain__(
            (System_Object*)pRuntimeThread->bottomFrame__.exception__);
        il2c_leave(bottomNest, 0);
    }
    il2c_leave_to(bottomNest)
    {
        il2c_leave_bind(bottomNest, 0, exit);
    }
    il2c_end_try(bottomNest);

exit:
    il2c_unlink_execution_frame(&pRuntimeThread->bottomFrame__);

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

    IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)parameter;
    il2c_assert(pRuntimeThread->thread.vptr0__ == &System_Threading_Thread_VTABLE__);
    il2c_assert(il2c_isinst(pRuntimeThread->thread.start__, System_Threading_ParameterizedThreadStart) != NULL);
    il2c_assert(pRuntimeThread->bottomFrame__.pNext__ == NULL);
    il2c_assert(pRuntimeThread->bottomFrame__.objRefCount__ == 0);
    il2c_assert(pRuntimeThread->bottomFrame__.valueCount__ == 0);
    il2c_assert(pRuntimeThread->bottomFrame__.exception__ == NULL);

    // Set real thread id.
    pRuntimeThread->thread.id__ = il2c_get_current_thread_id__();

    // Save IL2C_THREAD_CONTEXT into tls.
    il2c_set_tls_value(g_TlsIndex__, (void*)&pRuntimeThread->thread.pFrame__);

    // It's naive for passing handle if startup with suspending not implemented. (pthread/FreeRTOS)
    while (pRuntimeThread->thread.rawHandle__ == -1);

    pRuntimeThread->bottomFrame__.objRefCount__ = 1;
    il2c_link_execution_frame(&pRuntimeThread->bottomFrame__);

    il2c_try(bottomNest, System_Threading_Thread_InternalExceptionFilter)
    {
        // Invoke delegate.
        System_Threading_ParameterizedThreadStart_Invoke(
            (System_Threading_ParameterizedThreadStart*)(pRuntimeThread->thread.start__), pRuntimeThread->thread.parameter__);
        il2c_leave(bottomNest, 0);
    }
    il2c_catch(bottomNest, 1, pRuntimeThread->bottomFrame__.exception__)
    {
        il2c_invoke_unhandled_exception_on_the_current_domain__(
            (System_Object*)pRuntimeThread->bottomFrame__.exception__);
        il2c_leave(bottomNest, 0);
    }
    il2c_leave_to(bottomNest)
    {
        il2c_leave_bind(bottomNest, 0, exit);
    }
    il2c_end_try(bottomNest);

exit:
    il2c_unlink_execution_frame(&pRuntimeThread->bottomFrame__);

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

    // TODO: ThreadStateException? (Already started)
    il2c_assert(this__->rawHandle__ == -1);

    // Register GC root tracking.
    il2c_register_root_reference__(this__, false);

    // Create (suspended if available) thread.
    intptr_t rawHandle = il2c_create_thread__(
        System_Threading_Thread_InternalEntryPoint, this__);

    // TODO: OutOfMemoryException (have to unlink from root)
    il2c_assert(rawHandle >= 0);

    // It's naive for passing handle if startup with suspending not implemented. (pthread/FreeRTOS)
    this__->rawHandle__ = rawHandle;
    il2c_resume_thread__(rawHandle);
}

void System_Threading_Thread_Start_2(System_Threading_Thread* this__, System_Object* parameter)
{
    il2c_assert(this__ != NULL);

    // TODO: InvalidOperationException? (Auto attached managed thread)
    il2c_assert(this__->start__ != NULL);

    // TODO: ThreadStateException? (Already started)
    il2c_assert(this__->rawHandle__ == -1);

    // Register GC root tracking.
    il2c_register_root_reference__(this__, false);

    // Store parameter
    this__->parameter__ = parameter;

    // Create (suspended if available) thread.
    intptr_t rawHandle = il2c_create_thread__(
        System_Threading_Thread_InternalEntryPointWithParameter, this__);

    // TODO: OutOfMemoryException (have to unlink from root)
    il2c_assert(rawHandle >= 0);

    // It's naive for passing handle if startup with suspending not implemented. (pthread/FreeRTOS)
    this__->rawHandle__ = rawHandle;
    il2c_resume_thread__(rawHandle);
}

void System_Threading_Thread_Join(System_Threading_Thread* this__)
{
    il2c_assert(this__ != NULL);
    il2c_assert(this__->rawHandle__ >= 0);
    il2c_assert(this__->start__ != NULL);

    il2c_join_thread__(this__->rawHandle__);
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
    return (System_Threading_Thread*)(((uint8_t*)pThreadContext) - offsetof(System_Threading_Thread, pFrame__));
}

void System_Threading_Thread_Sleep(int millisecondsTimeout)
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
    }
    if (pRuntimeThread->thread.parameter__ != NULL)
    {
        il2c_default_mark_handler_for_objref__(pRuntimeThread->thread.parameter__);
    }

    ///////////////////////////////////////////////////////////////
    // Check IL2C_EXECUTION_FRAME.
    // It's important step for GC collecting sequence.
    // All method execution frame traversal begins this location.

    if (il2c_likely__(pRuntimeThread->thread.pFrame__ != NULL))
    {
        il2c_default_mark_handler_for_tracking_information__(pRuntimeThread->thread.pFrame__);
    }
}

System_Threading_Thread_VTABLE_DECL__ System_Threading_Thread_VTABLE__ = {
    0, // Adjustor offset
    (bool(*)(void*, System_Object*))System_Object_Equals,
    (void(*)(void*))System_Threading_Thread_Finalize,
    (int32_t(*)(void*))System_Object_GetHashCode,
    (System_String* (*)(void*))System_Object_ToString
};

// If System_Threading_Thread is allocated by il2c_get_uninitialized_object(),
// the storage space contains additional spaces by IL2C_RUNTIME_THREAD tail fields.
IL2C_RUNTIME_TYPE_BEGIN(
    System_Threading_Thread,
    "System.Threading.Thread",
    IL2C_TYPE_REFERENCE | IL2C_TYPE_WITH_MARK_HANDLER,
    sizeof(IL2C_RUNTIME_THREAD),
    System_Object,
    System_Threading_Thread_MarkHandler__,
    0)
IL2C_RUNTIME_TYPE_END();
