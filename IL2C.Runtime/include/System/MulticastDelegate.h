#ifndef System_MulticastDelegate_H__
#define System_MulticastDelegate_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.MulticastDelegate

// Maybe all delegate derived types are same as System.Delegate internally.

typedef System_Delegate System_MulticastDelegate;

typedef System_Delegate_VTABLE_DECL__ System_MulticastDelegate_VTABLE_DECL__;

#define System_MulticastDelegate_VTABLE__ System_Delegate_VTABLE__

IL2C_DECLARE_RUNTIME_TYPE(System_MulticastDelegate);

// All members transfered to System.Delegate.

static inline void System_MulticastDelegate_MarkHandler__(System_MulticastDelegate* this__)
{
    System_Delegate_MarkHandler__((System_Delegate*)this__);
}

static inline int32_t System_MulticastDelegate_GetHashCode(System_MulticastDelegate* this__)
{
    return System_Delegate_GetHashCode((System_Delegate*)this__);
}

static inline bool System_MulticastDelegate_Equals__System_Object(System_MulticastDelegate* this__, System_Object* obj)
{
    return System_Delegate_Equals__System_Object((System_Delegate*)this__, obj);
}

#ifdef __cplusplus
}
#endif

#endif
