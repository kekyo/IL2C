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

#ifndef IL2C_PRIVATE_GCC_H__
#define IL2C_PRIVATE_GCC_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// GNU C Compiler

#if defined(__GNUC__)

#if defined(__x86_64__) || defined(__i386__)
#include <x86intrin.h>
#elif defined(__ARM_NEON__)
#include <arm_neon.h>
#elif defined(__IWMMXT__)
#include <mmintrin.h>
#endif

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <float.h>
#include <math.h>
#include <wchar.h>

#define il2c_iand(pDest, newValue) __sync_fetch_and_and((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ior(pDest, newValue) __sync_fetch_and_or((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixor(pDest, newValue) __sync_fetch_and_xor((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_iinc(pDest) __sync_add_and_fetch((interlock_t*)(pDest), 1)
#define il2c_idec(pDest) __sync_sub_and_fetch((interlock_t*)(pDest), 1)
#define il2c_ixchg(pDest, newValue) __sync_lock_test_and_set((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixchgptr(ppDest, pNewValue) __sync_lock_test_and_set((void**)(ppDest), (void*)(pNewValue))
#define il2c_icmpxchg(pDest, newValue, comperandValue) __sync_val_compare_and_swap((interlock_t*)(pDest), (interlock_t)(comperandValue), (interlock_t)(newValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) __sync_val_compare_and_swap((void**)(ppDest), (void*)(pComperandValue), (void*)(pNewValue))
#define il2c_memory_barrier() __sync_synchronize()

#endif

#ifdef __cplusplus
}
#endif

#endif
