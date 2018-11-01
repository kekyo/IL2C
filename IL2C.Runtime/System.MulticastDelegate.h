#ifndef __System_MulticastDelegate_H__
#define __System_MulticastDelegate_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.MulticastDelegate

// Maybe all delegate derived types are same as System.Delegate internally.

typedef System_Delegate System_MulticastDelegate;

typedef __System_Delegate_VTABLE_DECL__ __System_MulticastDelegate_VTABLE_DECL__;

#define __System_MulticastDelegate_VTABLE__ __System_Delegate_VTABLE__
extern IL2C_RUNTIME_TYPE_DECL __System_MulticastDelegate_RUNTIME_TYPE__;

// All members transfered to System.Delegate.

static inline void __System_MulticastDelegate_IL2C_MarkHandler__(System_MulticastDelegate* this__)
{
    __System_Delegate_IL2C_MarkHandler__((System_Delegate*)this__);
}

static inline int32_t System_MulticastDelegate_GetHashCode(System_MulticastDelegate* this__)
{
    return System_Delegate_GetHashCode((System_Delegate*)this__);
}

static inline bool System_MulticastDelegate_Equals(System_MulticastDelegate* this__, System_Object* obj)
{
    return System_Delegate_Equals((System_Delegate*)this__, obj);
}

#ifdef __cplusplus
}
#endif

#endif
