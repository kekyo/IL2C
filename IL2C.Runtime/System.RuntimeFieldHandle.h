#ifndef __System_RuntimeFieldHandle_H__
#define __System_RuntimeFieldHandle_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.RuntimeFieldHandle

typedef struct System_RuntimeFieldHandle System_RuntimeFieldHandle;

struct System_RuntimeFieldHandle
{
    uintptr_t size__;
    const void* field__;
};

extern IL2C_RUNTIME_TYPE_DECL __System_RuntimeFieldHandle_RUNTIME_TYPE__;

#ifdef __cplusplus
}
#endif

#endif
