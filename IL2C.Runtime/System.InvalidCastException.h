#ifndef __System_InvalidCastException_H__
#define __System_InvalidCastException_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.InvalidCastException

typedef System_Exception System_InvalidCastException;

typedef __System_Exception_VTABLE_DECL__ __System_InvalidCastException_VTABLE_DECL__;

#define __System_InvalidCastException_VTABLE__ __System_Exception_VTABLE__
extern IL2C_RUNTIME_TYPE_DECL __System_InvalidCastException_RUNTIME_TYPE__;

#define __System_InvalidCastException_IL2C_MarkHandler__ __System_Exception_IL2C_MarkHandler__

static inline void System_InvalidCastException__ctor(System_InvalidCastException* this__)
{
    System_Exception__ctor((System_Exception*)this__);
}

static inline void System_InvalidCastException__ctor_1(System_InvalidCastException* this__, System_String* message)
{
    System_Exception__ctor_1((System_Exception*)this__, message);
}

#ifdef __cplusplus
}
#endif

#endif
