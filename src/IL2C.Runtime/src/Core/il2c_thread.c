#include <il2c_private.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////

IL2C_TLS_INDEX g_TlsIndex__;

/////////////////////////////////////////////////////////////
// Thread context functions

#if defined(IL2C_USE_LINE_INFORMATION)
IL2C_THREAD_CONTEXT* il2c_acquire_thread_context__(const char* pFile, int line)
#else
IL2C_THREAD_CONTEXT* il2c_acquire_thread_context__(void)
#endif
{
    // First arrived arbitrary native thread: Auto attaching managed thread.
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);
    if (il2c_unlikely__(pThreadContext == NULL))
    {
#if defined(IL2C_USE_LINE_INFORMATION)
        IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
            il2c_typeof(System_Threading_Thread),
            sizeof(IL2C_RUNTIME_THREAD),
            pFile, line);
#else
        IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
            il2c_typeof(System_Threading_Thread),
            sizeof(IL2C_RUNTIME_THREAD));
#endif

        IL2C_RUNTIME_THREAD* pRuntimeThread = (IL2C_RUNTIME_THREAD*)(pHeader + 1);

        // Initialize thread context.
        pThreadContext = &pRuntimeThread->context;

        pThreadContext->rawHandle = il2c_get_current_thread__();
        pThreadContext->id = il2c_get_current_thread_id__();
        il2c_initialize_monitor_lock__((void*)&pThreadContext->lockForCollect);

        // Save IL2C_THREAD_CONTEXT into tls.
        il2c_set_tls_value(g_TlsIndex__, (void*)pThreadContext);

        // Register GC root reference.
        // NOTE: Auto attached Thread class instances aren't freed when before shutdown.
        //   If we instantiated with Thread.Start(), it's manually allocated and can collect by GC.
        //   (See System_Threading_Thread_InternalEntryPoint())
        il2c_register_root_reference__((void*)pRuntimeThread, false);

        // Marked instance is initialized. (and will handle by GC)
        il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);
    }

    return pThreadContext;
}

#if defined(IL2C_USE_LINE_INFORMATION)
System_Threading_Thread* il2c_new_thread__(System_Delegate* start, const char* pFile, int line)
#else
System_Threading_Thread* il2c_new_thread__(System_Delegate* start)
#endif
{
    // TODO: ArgumentNullException
    il2c_assert(start != NULL);

#if defined(IL2C_USE_LINE_INFORMATION)
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        il2c_typeof(System_Threading_Thread),
        sizeof(IL2C_RUNTIME_CREATED_THREAD),
        pFile, line);
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__(
        pFile, line);
#else
    IL2C_REF_HEADER* pHeader = il2c_get_uninitialized_object_internal__(
        il2c_typeof(System_Threading_Thread),
        sizeof(IL2C_RUNTIME_CREATED_THREAD));
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_acquire_thread_context__();
#endif

    IL2C_RUNTIME_CREATED_THREAD* pRuntimeThread = (IL2C_RUNTIME_CREATED_THREAD*)(pHeader + 1);
    pThreadContext->pTemporaryReferenceAnchor = (System_Object*)&pRuntimeThread->thread;

    pRuntimeThread->thread.start__ = start;
    pRuntimeThread->context.rawHandle = -1;
     
    // Initialize thread context.
    pRuntimeThread->context.id = il2c_get_current_thread_id__();
    il2c_initialize_monitor_lock__((void*)&pRuntimeThread->context.lockForCollect);

    // Marked instance is initialized. (and will handle by GC)
    il2c_ior(&pHeader->characteristic, IL2C_CHARACTERISTIC_INITIALIZED);

    return (System_Threading_Thread*)&pRuntimeThread->thread;
}
