#include <il2c_private.h>

//////////////////////////////////////////////////
// POSIX threading support

#if defined(IL2C_USE_PTHREAD)

IL2C_TLS_INDEX il2c_tls_alloc(void)
{
    pthread_key_t key;
    int result = pthread_key_create(&key, NULL);
    il2c_assert(result == 0);
    ((void)result);

    return key;
}

void* il2c_get_tls_value(IL2C_TLS_INDEX tlsIndex)
{
    return pthread_getspecific((pthread_key_t)tlsIndex);
}

void il2c_set_tls_value(IL2C_TLS_INDEX tlsIndex, void* value)
{
    int result = pthread_setspecific((pthread_key_t)tlsIndex, value);
    il2c_assert(result == 0);
    ((void)result);
}

intptr_t il2c_create_thread__(IL2C_THREAD_ENTRY_POINT_TYPE entryPoint, IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE parameter)
{
    pthread_t handle;

    int result = pthread_create(&handle, NULL, entryPoint, parameter);
    il2c_assert(result == 0);
    ((void)result);

    return (intptr_t)handle;
}

void il2c_join_thread__(intptr_t handle)
{
    il2c_assert(handle != 0);

    void* value;
    pthread_join((pthread_t)handle, &value);
}

void il2c_initialize_monitor_lock__(IL2C_MONITOR_LOCK* pLock)
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(pLock, &attr);
}

#endif
