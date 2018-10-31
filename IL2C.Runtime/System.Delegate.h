#ifndef __System_Delegate_H__
#define __System_Delegate_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Delegate

typedef struct System_Delegate System_Delegate;

typedef __System_Object_VTABLE_DECL__ __System_Delegate_VTABLE_DECL__;

struct System_Delegate
{
    __System_Delegate_VTABLE_DECL__* vptr0__;
    System_Object* _target;
    intptr_t _methodPtr;
};

extern __System_Delegate_VTABLE_DECL__ __System_Delegate_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Delegate_RUNTIME_TYPE__;

extern /* internalcall */ void __System_Delegate_IL2C_MarkHandler__(System_Delegate* this__);

extern /* virtual */ int32_t System_Delegate_GetHashCode(System_Delegate* this__);
extern /* virtual */ bool System_Delegate_Equals(System_Delegate* this__, System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
