#ifndef __System_Int32_H__
#define __System_Int32_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Int32

typedef int32_t System_Int32;
extern IL2C_RUNTIME_TYPE_DECL __System_Int32_RUNTIME_TYPE__;

extern System_String* System_Int32_ToString(int32_t* this__);
extern bool System_Int32_TryParse(System_String* s, int32_t* result);

#ifdef __cplusplus
}
#endif

#endif
