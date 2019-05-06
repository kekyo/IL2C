// It uses for internal purpose only.

#ifndef IL2C_PRIVATE_FREERTOS_H__
#define IL2C_PRIVATE_FREERTOS_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// FreeRTOS scheduler

#if defined(IL2C_USE_FREERTOS) && defined(portNUM_PROCESSORS)

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

typedef BaseType_t IL2C_TLS_INDEX;
#define il2c_tls_alloc() ((IL2C_TLS_INDEX)((configNUM_THREAD_LOCAL_STORAGE_POINTERS) - 1))
#define il2c_tls_free(tlsIndex) ((void)0)
#define il2c_get_tls_value(tlsIndex) pvTaskGetThreadLocalStoragePointer(NULL, tlsIndex)
#define il2c_set_tls_value(tlsIndex, value) vTaskSetThreadLocalStoragePointer(NULL, tlsIndex, value)

#define IL2C_THREAD_ENTRY_POINT_RESULT_TYPE void
#define IL2C_THREAD_ENTRY_POINT_RETURN(value) ((void)0)
#define IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE void*
typedef IL2C_THREAD_ENTRY_POINT_RESULT_TYPE (*IL2C_THREAD_ENTRY_POINT_TYPE)(IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE);

#define il2c_get_current_thread__() ((intptr_t)xTaskGetCurrentTaskHandle())
#define il2c_get_current_thread_id__() ((int32_t)xTaskGetCurrentTaskHandle())
extern intptr_t il2c_create_thread__(IL2C_THREAD_ENTRY_POINT_TYPE entryPoint, IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE parameter);
#define il2c_resume_thread__(handle)
extern void il2c_join_thread__(intptr_t handle);
#define il2c_close_thread_handle__(handle) vTaskDelete((TaskHandle_t)(handle))

typedef xSemaphoreHandle IL2C_MONITOR_LOCK;
#define il2c_initialize_monitor_lock__(pLock) ((*(pLock)) = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP)
#define il2c_enter_monitor_lock__(pLock) pthread_mutex_lock(pLock)
#define il2c_try_enter_monitor_lock__(pLock) (pthread_mutex_trylock(pLock) != EBUSY)
#define il2c_exit_monitor_lock__(pLock) pthread_mutex_unlock(pLock)
#define il2c_destroy_monitor_lock__(pLock) pthread_mutex_destroy(pLock)

#endif

#ifdef __cplusplus
}
#endif

#endif
