#ifndef __MODULE_Accelometer_Code, Version=0_3_1_0, Culture=neutral, PublicKeyToken=null__
#define __MODULE_Accelometer_Code, Version=0_3_1_0, Culture=neutral, PublicKeyToken=null__

#include <il2c.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:

typedef struct Accelometer_Demo Accelometer_Demo;

////////////////////////////////////////////////////////////
// Class: Accelometer.Demo

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Accelometer_Demo* this__, IL2C_RUNTIME_TYPE_DECL* type);
} __Accelometer_Demo_VTABLE_DECL__;

// Class layout
struct Accelometer_Demo
{
    __Accelometer_Demo_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_RUNTIME_TYPE__;

// Class vtable
extern __Accelometer_Demo_VTABLE_DECL__ __Accelometer_Demo_VTABLE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:


//////////////////////////////////////////////////////////////////////////////////
// Methods:

// Accelometer_Demo
extern /* internalcall */ void __Accelometer_Demo_IL2C_MarkHandler__(Accelometer_Demo** this__);
extern /* internalcall */ void* __Accelometer_Demo_IL2C_RuntimeCast__(Accelometer_Demo** this__, IL2C_RUNTIME_TYPE_DECL* type);
extern System_Void* Accelometer_Demo_Main_0()();
extern System_Void* Accelometer_Demo__ctor_0(Accelometer_Demo this__)(Accelometer_Demo* this__);

#ifdef __cplusplus
}
#endif

#endif
