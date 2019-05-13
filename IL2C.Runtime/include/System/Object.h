#ifndef System_Object_H__
#define System_Object_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Object

typedef struct System_Object System_Object;
typedef struct System_String System_String;
typedef struct System_Type System_Type;

typedef const struct
{
    intptr_t offset__; // Adjustor offset
    bool(*Equals__System_Object)(void* this__, System_Object* obj);
    void(*Finalize)(void* this__);
    int32_t(*GetHashCode)(void* this__);
    System_String* (*ToString)(void* this__);
} System_Object_VTABLE_DECL__;

struct System_Object
{
    System_Object_VTABLE_DECL__* vptr0__;
};

extern System_Object_VTABLE_DECL__ System_Object_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Object);

static inline void System_Object__ctor(System_Object* this__)
{
}

extern /* virtual */ System_String* System_Object_ToString(System_Object* this__);
extern /* virtual */ int32_t System_Object_GetHashCode(System_Object* this__);
extern System_Type* System_Object_GetType(System_Object* this__);
extern /* virtual */ void System_Object_Finalize(System_Object* this__);
extern /* virtual */ bool System_Object_Equals__System_Object(System_Object* this__, System_Object* obj);

extern /* static */ bool System_Object_ReferenceEquals__System_Object_System_Object(System_Object* objA, System_Object* objB);

#ifdef __cplusplus
}
#endif

#endif
