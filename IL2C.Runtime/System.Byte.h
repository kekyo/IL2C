#ifndef __System_Byte_H__
#define __System_Byte_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Byte

typedef uint8_t System_Byte;
extern IL2C_RUNTIME_TYPE_DECL __System_Byte_RUNTIME_TYPE__;

extern System_String* System_Byte_ToString(uint8_t* this__);

#ifdef __cplusplus
}
#endif

#endif
