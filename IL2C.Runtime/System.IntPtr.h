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

static System_IntPtr System_IntPtr_op_Addition(System_IntPtr lhs, int32_t rhs)
{
    return lhs + rhs;
}

static bool System_IntPtr_op_Inequality(System_IntPtr lhs, System_IntPtr rhs)
{
    return lhs != rhs;
}

extern System_String* System_IntPtr_ToString(intptr_t* this__);

#ifdef __cplusplus
}
#endif

#endif
