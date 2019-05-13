#ifndef System_Enum_H__
#define System_Enum_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Enum

typedef struct System_Enum System_Enum;

typedef System_ValueType_VTABLE_DECL__ System_Enum_VTABLE_DECL__;

struct System_Enum
{
    System_Enum_VTABLE_DECL__* vptr0__;
};

extern System_Enum_VTABLE_DECL__ System_Enum_VTABLE__;

IL2C_DECLARE_RUNTIME_TYPE(System_Enum);

extern /* virtual */ System_String* System_Enum_ToString(System_Enum* this__);
extern /* virtual */ int32_t System_Enum_GetHashCode(System_Enum* this__);
extern /* virtual */ bool System_Enum_Equals__System_Object(System_Enum* this__, System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
