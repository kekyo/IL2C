#ifndef System_EventArgs_H__
#define System_EventArgs_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.EventArgs

typedef struct System_EventArgs System_EventArgs;
typedef System_Object_VTABLE_DECL__ System_EventArgs_VTABLE_DECL__;

struct System_EventArgs
{
    System_EventArgs_VTABLE_DECL__* vptr0__;
};

#define System_EventArgs_VTABLE__ System_Object_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_EventArgs);

static inline void System_EventArgs__ctor(System_EventArgs* this__)
{
}

#ifdef __cplusplus
}
#endif

#endif
