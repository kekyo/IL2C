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

#ifndef IL2C_PRIVATE_NO_THREAD_H__
#define IL2C_PRIVATE_NO_THREAD_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// Lack for threading support

#if defined(IL2C_NO_THREADING)

extern intptr_t g_TLS0;

typedef intptr_t IL2C_TLS_INDEX;
#define il2c_tls_alloc() ((IL2C_TLS_INDEX)0)
#define il2c_tls_free(tlsIndex) ((void)tlsIndex, g_TLS0 = 0)
#define il2c_get_tls_value(tlsIndex) ((void)tlsIndex, (void*)(g_TLS0))
#define il2c_set_tls_value(tlsIndex, value) ((void)tlsIndex, g_TLS0 = (intptr_t)(value))

#define IL2C_THREAD_ENTRY_POINT_RESULT_TYPE void
#define IL2C_THREAD_ENTRY_POINT_RETURN(value) ((void)value)
#define IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE void*
typedef IL2C_THREAD_ENTRY_POINT_RESULT_TYPE (*IL2C_THREAD_ENTRY_POINT_TYPE)(IL2C_THREAD_ENTRY_POINT_PARAMETER_TYPE);

#define il2c_get_current_thread__() ((intptr_t)0)
#define il2c_get_current_thread_id__() ((int32_t)0)
#define il2c_create_thread__(entryPoint, parameter) ((void)entryPoint, (void)parameter, (intptr_t)-1)
#define il2c_resume_thread__(handle) ((void)handle)
#define il2c_join_thread__(handle) ((void)handle)
#define il2c_close_thread_handle__(handle) ((void)handle)

typedef uint8_t IL2C_MONITOR_LOCK;
#define il2c_initialize_monitor_lock__(pLock) ((void)pLock)
#define il2c_enter_monitor_lock__(pLock) ((void)pLock)
#define il2c_try_enter_monitor_lock__(pLock) ((void)pLock, true)
#define il2c_exit_monitor_lock__(pLock) ((void)pLock)
#define il2c_destroy_monitor_lock__(pLock) ((void)pLock)

#endif

#ifdef __cplusplus
}
#endif

#endif
