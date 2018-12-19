#ifndef __MT3620Blink_H__
#define __MT3620Blink_H__

#pragma once

#include <il2c.h>

#include <MT3620Blink.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:

typedef struct MT3620Blink_Program MT3620Blink_Program;

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Program

// [1-2-1] Class VTable layout (Same as System.Object)
typedef System_Object_VTABLE_DECL__ MT3620Blink_Program_VTABLE_DECL__;

// [1-1-2] Class layout
struct MT3620Blink_Program
{
    MT3620Blink_Program_VTABLE_DECL__* vptr0__;
};

// [1-5-1] VTable (Same as System.Object)
#define MT3620Blink_Program_VTABLE__ System_Object_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Program);

//////////////////////////////////////////////////////////////////////////////////
// [2-2] Public static fields:

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: MT3620Blink.Program

extern /* static */ int32_t MT3620Blink_Program_Main(void);

#ifdef __cplusplus
}
#endif

#endif
