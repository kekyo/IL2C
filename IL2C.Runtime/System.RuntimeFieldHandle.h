#ifndef System_RuntimeFieldHandle_H__
#define System_RuntimeFieldHandle_H__

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

IL2C_DECLARE_RUNTIME_TYPE(System_RuntimeFieldHandle);

#ifdef __cplusplus
}
#endif

#endif
