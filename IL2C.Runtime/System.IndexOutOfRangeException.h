#ifndef __System_IndexOutOfRangeException_H__
#define __System_IndexOutOfRangeException_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.IndexOutOfRangeException

typedef System_Exception System_IndexOutOfRangeException;

typedef __System_Exception_VTABLE_DECL__ __System_IndexOutOfRangeException_VTABLE_DECL__;

#define __System_IndexOutOfRangeException_VTABLE__ __System_Exception_VTABLE__
extern IL2C_RUNTIME_TYPE_DECL __System_IndexOutOfRangeException_RUNTIME_TYPE__;

#define __System_IndexOutOfRangeException_IL2C_MarkHandler__ __System_Exception_IL2C_MarkHandler__

static inline void System_IndexOutOfRangeException__ctor(System_IndexOutOfRangeException* this__)
{
    System_Exception__ctor((System_Exception*)this__);
}

static inline void System_IndexOutOfRangeException__ctor_1(System_IndexOutOfRangeException* this__, System_String* message)
{
    System_Exception__ctor_1((System_Exception*)this__, message);
}

#ifdef __cplusplus
}
#endif

#endif
