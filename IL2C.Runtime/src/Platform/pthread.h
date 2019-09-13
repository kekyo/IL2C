/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

// It uses for internal purpose only.

#ifndef IL2C_PRIVATE_PTHREAD_H__
#define IL2C_PRIVATE_PTHREAD_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// POSIX threading support

#if defined(IL2C_USE_PTHREAD)

#include <pthread.h>

typedef pthread_key_t IL2C_TLS_INDEX;
extern IL2C_TLS_INDEX il2c_tls_alloc(void);
#define il2c_tls_free(tlsIndex) pthread_key_delete(tlsIndex)
extern void* il2c_get_tls_value(IL2C_TLS_INDEX tlsIndex);
extern void il2c_set_tls_value(IL2C_TLS_INDEX tlsIndex, void* value);

#define IL2C_THREAD_ENTRY_POINT_RESULT_TYPE void*
#define IL2C_THREAD_ENTRY_POINT_RETURN(value) pthread_exit(value); return value
#define IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE void*
typedef IL2C_THREAD_ENTRY_POINT_RESULT_TYPE (*IL2C_THREAD_ENTRY_POINT_TYPE)(IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE);

#define il2c_get_current_thread__() ((intptr_t)pthread_self())
#if defined(__linux__)
// Native thread id on the Linux
#define il2c_get_current_thread_id__() ((int32_t)syscall(SYS_gettid))
#else
#define il2c_get_current_thread_id__() ((int32_t)pthread_self())
#endif
extern intptr_t il2c_create_thread__(IL2C_THREAD_ENTRY_POINT_TYPE entryPoint, IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE parameter);
#define il2c_resume_thread__(handle)
extern void il2c_join_thread__(intptr_t handle);
#define il2c_close_thread_handle__(handle)

typedef pthread_mutex_t IL2C_MONITOR_LOCK;
extern void il2c_initialize_monitor_lock__(IL2C_MONITOR_LOCK* pLock);
#define il2c_enter_monitor_lock__(pLock) pthread_mutex_lock(pLock)
#define il2c_try_enter_monitor_lock__(pLock) (pthread_mutex_trylock(pLock) != EBUSY)
#define il2c_exit_monitor_lock__(pLock) pthread_mutex_unlock(pLock)
#define il2c_destroy_monitor_lock__(pLock) pthread_mutex_destroy(pLock)

#endif

#ifdef __cplusplus
}
#endif

#endif
