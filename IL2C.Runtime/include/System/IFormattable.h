#ifndef System_IFormattable_H__
#define System_IFormattable_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.IFormattable

typedef struct System_IFormattable System_IFormattable;

typedef const struct
{
    intptr_t offset__; // Adjustor offset
    System_String* (*ToString__System_String_System_IFormatProvider)(void* this__, System_String* format, System_IFormatProvider* formatProvider);
} System_IFormattable_VTABLE_DECL__;

struct System_IFormattable
{
    System_IFormattable_VTABLE_DECL__* vptr0__;
};

IL2C_DECLARE_RUNTIME_TYPE(System_IFormattable);

#ifdef __cplusplus
}
#endif

#endif
