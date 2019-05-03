// It uses for internal purpose only.

#ifndef IL2C_PRIVATE_NO_THREAD_H__
#define IL2C_PRIVATE_NO_THREAD_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// Lack for threading support

#if defined(IL2C_NO_THREADING)

// UEFI enviuronment: multithreading feature not supported.
typedef intptr_t IL2C_TLS_INDEX;
#define il2c_tls_alloc() ((IL2C_TLS_INDEX)0)
#define il2c_tls_free(tlsIndex) (tlsIndex = 0)
#define il2c_get_tls_value(tlsIndex) ((void*)(tlsIndex))
#define il2c_set_tls_value(tlsIndex, value) (tlsIndex = (intptr_t)(value))

#define IL2C_THREAD_ENTRY_POINT_RESULT_TYPE void
#define IL2C_THREAD_ENTRY_POINT_RETURN(value) ((void)0)
#define IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE void*
typedef IL2C_THREAD_ENTRY_POINT_RESULT_TYPE (*IL2C_THREAD_ENTRY_POINT_TYPE)(IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE);

#define il2c_get_current_thread__() ((intptr_t)0)
#define il2c_get_current_thread_id__() ((int32_t)0)
#define il2c_create_thread__(entryPoint, parameter) ((intptr_t)-1)
#define il2c_resume_thread__(handle) ((void)0)
#define il2c_join_thread__(handle) ((void)0)
#define il2c_close_thread_handle__(handle) ((void)0)

typedef uint8_t IL2C_MONITOR_LOCK;
#define il2c_initialize_monitor_lock__(pLock) ((void)0)
#define il2c_enter_monitor_lock__(pLock) ((void)0)
#define il2c_try_enter_monitor_lock__(pLock) (true)
#define il2c_exit_monitor_lock__(pLock) ((void)0)
#define il2c_destroy_monitor_lock__(pLock) ((void)0)

#endif

#ifdef __cplusplus
}
#endif

#endif
