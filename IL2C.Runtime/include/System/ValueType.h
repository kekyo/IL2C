#ifndef System_ValueType_H__
#define System_ValueType_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.ValueType

typedef struct System_ValueType System_ValueType;

typedef System_Object_VTABLE_DECL__ System_ValueType_VTABLE_DECL__;

struct System_ValueType
{
    System_ValueType_VTABLE_DECL__* vptr0__;
};

extern System_ValueType_VTABLE_DECL__ System_ValueType_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_ValueType);

extern /* virtual */ System_String* System_ValueType_ToString(System_ValueType* this__);
extern /* virtual */ int32_t System_ValueType_GetHashCode(System_ValueType* this__);
extern /* virtual */ bool System_ValueType_Equals__System_Object(System_ValueType* this__, System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
