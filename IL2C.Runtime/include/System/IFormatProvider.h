#ifndef System_IFormatProvider_H__
#define System_IFormatProvider_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.IFormatProvider

typedef struct System_IFormatProvider System_IFormatProvider;

typedef const struct
{
    intptr_t offset__; // Adjustor offset
    System_Object* (*GetFormat__System_Type)(void* this__, System_Type* formatType);
} System_IFormatProvider_VTABLE_DECL__;

struct System_IFormatProvider
{
    System_IFormatProvider_VTABLE_DECL__* vptr0__;
};

IL2C_DECLARE_RUNTIME_TYPE(System_IFormatProvider);

#ifdef __cplusplus
}
#endif

#endif
