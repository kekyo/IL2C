#ifndef __System_UInt32_H__
#define __System_UInt32_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UInt32

typedef uint32_t System_UInt32;
extern IL2C_RUNTIME_TYPE_DECL __System_UInt32_RUNTIME_TYPE__;

extern System_String* System_UInt32_ToString(uint32_t* this__);

#ifdef __cplusplus
}
#endif

#endif
