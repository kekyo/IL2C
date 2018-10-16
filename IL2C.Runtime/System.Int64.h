#ifndef __System_Int64_H__
#define __System_Int64_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Int64

typedef int64_t System_Int64;
extern IL2C_RUNTIME_TYPE_DECL __System_Int64_RUNTIME_TYPE__;

extern System_String* System_Int64_ToString(int64_t* this__);

#ifdef __cplusplus
}
#endif

#endif
