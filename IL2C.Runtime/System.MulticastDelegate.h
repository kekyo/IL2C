#ifndef __System_MulticastDelegate_H__
#define __System_MulticastDelegate_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.MulticastDelegate

typedef struct System_MulticastDelegate System_MulticastDelegate;

typedef __System_Delegate_VTABLE_DECL__ __System_MulticastDelegate_VTABLE_DECL__;

struct System_MulticastDelegate
{
    __System_MulticastDelegate_VTABLE_DECL__* vptr0__;
    System_Object* _target;
    intptr_t _methodPtr;
};

extern __System_MulticastDelegate_VTABLE_DECL__ __System_MulticastDelegate_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_MulticastDelegate_RUNTIME_TYPE__;

extern /* internalcall */ void __System_MulticastDelegate_IL2C_MarkHandler__(System_MulticastDelegate* this__);

extern /* virtual */ int32_t System_MulticastDelegate_GetHashCode(System_MulticastDelegate* this__);
extern /* virtual */ bool System_MulticastDelegate_Equals(System_MulticastDelegate* this__, System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
