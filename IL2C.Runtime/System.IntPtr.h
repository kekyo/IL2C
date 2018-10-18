#ifndef __System_IntPtr_H__
#define __System_IntPtr_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.IntPtr

typedef intptr_t System_IntPtr;
extern IL2C_RUNTIME_TYPE_DECL __System_IntPtr_RUNTIME_TYPE__;

extern const System_IntPtr System_IntPtr_Zero;

static inline System_IntPtr System_IntPtr_op_Addition(intptr_t lhs, intptr_t rhs)
{
    return lhs + rhs;
}

static inline bool System_IntPtr_op_Inequality(intptr_t lhs, intptr_t rhs)
{
    return lhs != rhs;
}

extern System_String* System_IntPtr_ToString(intptr_t* this__);

#ifdef __cplusplus
}
#endif

#endif
