#ifndef __System_Enum_H__
#define __System_Enum_H__

#pragma once

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////
// System.Enum

typedef struct System_Enum System_Enum;

typedef __System_ValueType_VTABLE_DECL__ __System_Enum_VTABLE_DECL__;

struct System_Enum
{
    __System_Enum_VTABLE_DECL__* vptr0__;
};

extern __System_Enum_VTABLE_DECL__ __System_Enum_VTABLE__;
extern IL2C_RUNTIME_TYPE_DECL __System_Enum_RUNTIME_TYPE__;

#define __System_Enum_IL2C_MarkHandler__ IL2C_DEFAULT_MARK_HANDLER

extern /* virtual */ System_String* System_Enum_ToString(System_Enum* this__);
extern /* virtual */ int32_t System_Enum_GetHashCode(System_Enum* this__);
extern /* virtual */ bool System_Enum_Equals(System_Enum* this__, System_Object* obj);

#ifdef __cplusplus
}
#endif

#endif
