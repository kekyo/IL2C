#ifndef __System_Object_H__
#define __System_Object_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Object

typedef struct System_Object System_Object;
typedef struct System_String System_String;

typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(System_Object* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __System_Object_VTABLE_DECL__;

struct System_Object
{
    __System_Object_VTABLE_DECL__* vptr0__;
};

extern IL2C_RUNTIME_TYPE_DECL __System_Object_RUNTIME_TYPE__;
extern __System_Object_VTABLE_DECL__ __System_Object_VTABLE__;

static void System_Object__ctor(System_Object* this__)
{
}

extern /* internalcall */ void __System_Object_IL2C_MarkHandler__(System_Object* this__);
extern /* internalcall */ void* __System_Object_IL2C_RuntimeCast__(System_Object* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern /* virtual */ System_String* __System_Object_ToString__(System_Object* this__);
extern /* virtual */ int32_t __System_Object_GetHashCode__(System_Object* this__);
extern /* virtual */ void __System_Object_Finalize__(System_Object* this__);
extern /* virtual */ bool __System_Object_Equals__(System_Object* this__, System_Object* obj);

#define System_Object_ToString(/* System_Object* */ this__) \
    ((this__)->vptr0__->ToString((this__)))
#define System_Object_GetHashCode(/* System_Object* */ this__) \
    ((this__)->vptr0__->GetHashCode((this__)))
#define System_Object_Finalize(/* System_Object* */ this__) \
    ((this__)->vptr0__->Finalize((this__)))
#define System_Object_Equals(/* System_Object* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals((this__), (obj)))

#ifdef __cplusplus
}
#endif

#endif
