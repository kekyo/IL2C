// It uses for internal purpose only.

#ifndef IL2C_PRIVATE_MSVC_H__
#define IL2C_PRIVATE_MSVC_H__

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////
// Visual C++

#if defined(_MSC_VER)

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <float.h>
#include <math.h>
#include <wchar.h>

#define il2c_iand(pDest, newValue) _InterlockedAnd((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ior(pDest, newValue) _InterlockedOr((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixor(pDest, newValue) _InterlockedXor((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_iinc(pDest) _InterlockedIncrement((interlock_t*)(pDest))
#define il2c_idec(pDest) _InterlockedDecrement((interlock_t*)(pDest))
#define il2c_ixchg(pDest, newValue) _InterlockedExchange((interlock_t*)(pDest), (interlock_t)(newValue))
#define il2c_ixchgptr(ppDest, pNewValue) _InterlockedExchangePointer((void**)(ppDest), (void*)(pNewValue))
#define il2c_icmpxchg(pDest, newValue, comperandValue) _InterlockedCompareExchange((interlock_t*)(pDest), (interlock_t)(newValue), (interlock_t)(comperandValue))
#define il2c_icmpxchgptr(ppDest, pNewValue, pComperandValue) _InterlockedCompareExchangePointer((void**)(ppDest), (void*)(pNewValue), (void*)(pComperandValue))
#define il2c_memory_barrier() MemoryBarrier()

#endif

#ifdef __cplusplus
}
#endif

#endif
