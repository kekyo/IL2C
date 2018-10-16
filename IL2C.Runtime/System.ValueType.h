#ifndef __System_ValueType_H__
#define __System_ValueType_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.ValueType

typedef struct System_ValueType System_ValueType;

typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(System_ValueType* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_ValueType* this__);
    int32_t (*GetHashCode)(System_ValueType* this__);
    void (*Finalize)(System_ValueType* this__);
    bool (*Equals)(System_ValueType* this__, System_Object* obj);
} __System_ValueType_VTABLE_DECL__;

struct System_ValueType
{
    __System_ValueType_VTABLE_DECL__* vptr0__;
};

extern IL2C_RUNTIME_TYPE_DECL __System_ValueType_RUNTIME_TYPE__;
extern __System_ValueType_VTABLE_DECL__ __System_ValueType_VTABLE__;

static void System_ValueType__ctor(System_ValueType* this__)
{
}

extern /* internalcall */ void __System_ValueType_IL2C_MarkHandler__(System_ValueType* this__);
extern /* internalcall */ void* __System_ValueType_IL2C_RuntimeCast__(System_ValueType* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern /* virtual */ System_String* __System_ValueType_ToString__(System_ValueType* this__);
extern /* virtual */ int32_t __System_ValueType_GetHashCode__(System_ValueType* this__);
extern /* virtual */ bool __System_ValueType_Equals__(System_ValueType* this__, System_Object* obj);

#define System_ValueType_ToString(/* System_ValueType* */ this__) \
    ((this__)->vptr0__->ToString((this__)))
#define System_ValueType_GetHashCode(/* System_ValueType* */ this__) \
    ((this__)->vptr0__->GetHashCode((this__)))
#define System_ValueType_Finalize(/* System_ValueType* */ this__) \
    ((this__)->vptr0__->Finalize((this__)))
#define System_ValueType_Equals(/* System_ValueType* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals((this__), (obj)))

#ifdef __cplusplus
}
#endif

#endif
