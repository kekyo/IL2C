#ifndef __System_UInt64_H__
#define __System_UInt64_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UInt64

typedef uint64_t System_UInt64;
extern IL2C_RUNTIME_TYPE_DECL __System_UInt64_RUNTIME_TYPE__;

extern System_String* System_UInt64_ToString(uint64_t* this__);

#ifdef __cplusplus
}
#endif

#endif
