#ifndef __System_UInt16_H__
#define __System_UInt16_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.UInt16

typedef uint16_t System_UInt16;
extern IL2C_RUNTIME_TYPE_DECL __System_UInt16_RUNTIME_TYPE__;

extern System_String* System_UInt16_ToString(uint16_t* this__);

#ifdef __cplusplus
}
#endif

#endif
