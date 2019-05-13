#ifndef System_Type_H__
#define System_Type_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Type

typedef struct System_Type System_Type;

typedef const struct
{
    intptr_t offset__; // Adjustor offset
    bool(*Equals__System_Object)(void* this__, System_Object* obj);
    void(*Finalize)(void* this__);
    int32_t(*GetHashCode)(void* this__);
    System_String* (*ToString)(void* this__);
    System_Type* (*get_BaseType)(void* this__);
    System_String* (*get_FullName)(void* this__);
} System_Type_VTABLE_DECL__;

struct System_Type
{
    System_Type_VTABLE_DECL__* vptr0__;
    IL2C_RUNTIME_TYPE type__;
};

IL2C_DECLARE_RUNTIME_TYPE(System_Type);

extern /* virtual */ System_String* System_Type_ToString(System_Type* this__);
extern /* virtual */ int32_t System_Type_GetHashCode(System_Type* this__);
extern bool System_Type_Equals__System_Type(System_Type* this__, System_Type* obj);
extern /* virtual */ bool System_Type_Equals__System_Object(System_Type* this__, System_Object* obj);
extern /* virtual */ System_Type* System_Type_get_BaseType(System_Type* this__);
extern /* virtual */ System_String* System_Type_get_FullName(System_Type* this__);

#ifdef __cplusplus
}
#endif

#endif
