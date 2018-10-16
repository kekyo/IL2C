#ifndef __System_UIntPtr_H__
#define __System_UIntPtr_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UIntPtr

typedef uintptr_t System_UIntPtr;
extern IL2C_RUNTIME_TYPE_DECL __System_UIntPtr_RUNTIME_TYPE__;

extern const System_UIntPtr System_UIntPtr_Zero;

extern System_String* System_UIntPtr_ToString(uintptr_t* this__);

#ifdef __cplusplus
}
#endif

#endif
