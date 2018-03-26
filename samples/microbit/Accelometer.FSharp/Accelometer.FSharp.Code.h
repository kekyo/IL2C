#ifndef __MODULE_Accelometer_FSharp_Code, Version=0_0_0_0, Culture=neutral, PublicKeyToken=null__
#define __MODULE_Accelometer_FSharp_Code, Version=0_0_0_0, Culture=neutral, PublicKeyToken=null__

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

////////////////////////////////////////////////////////////
// Enum: Accelometer.Demo/ArrowNames

// Enum layout
typedef enum Accelometer_Demo_ArrowNames
{
    Accelometer_Demo_ArrowNames_North = 0,
    Accelometer_Demo_ArrowNames_NorthEast = 1,
    Accelometer_Demo_ArrowNames_East = 2,
    Accelometer_Demo_ArrowNames_SouthEast = 3,
    Accelometer_Demo_ArrowNames_South = 4,
    Accelometer_Demo_ArrowNames_SouthWest = 5,
    Accelometer_Demo_ArrowNames_West = 6,
    Accelometer_Demo_ArrowNames_NorthWest = 7,

// Enum vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Accelometer_Demo_ArrowNames* this__, IL2C_RUNTIME_TYPE_DECL* type);
} __Accelometer_Demo_ArrowNames_VTABLE_DECL__;

// Enum layout
struct Accelometer_Demo_ArrowNames
{
    __Accelometer_Demo_ArrowNames_VTABLE_DECL__* vptr0__;
    __System_IComparable_VTABLE_DECL__* vptr_System_IComparable__;
    __System_IFormattable_VTABLE_DECL__* vptr_System_IFormattable__;
    __System_IConvertible_VTABLE_DECL__* vptr_System_IConvertible__;
    System_Int32 value__;
};


// Enum runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_ArrowNames_RUNTIME_TYPE__;

// Enum vtable
extern __Accelometer_Demo_ArrowNames_VTABLE_DECL__ __Accelometer_Demo_ArrowNames_VTABLE__;

////////////////////////////////////////////////////////////
// Enum: Accelometer.Demo/IconNames

// Enum layout
typedef enum Accelometer_Demo_IconNames
{
    Accelometer_Demo_IconNames_Heart = 0,

// Enum vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Accelometer_Demo_IconNames* this__, IL2C_RUNTIME_TYPE_DECL* type);
} __Accelometer_Demo_IconNames_VTABLE_DECL__;

// Enum layout
struct Accelometer_Demo_IconNames
{
    __Accelometer_Demo_IconNames_VTABLE_DECL__* vptr0__;
    __System_IComparable_VTABLE_DECL__* vptr_System_IComparable__;
    __System_IFormattable_VTABLE_DECL__* vptr_System_IFormattable__;
    __System_IConvertible_VTABLE_DECL__* vptr_System_IConvertible__;
    System_Int32 value__;
};


// Enum runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_IconNames_RUNTIME_TYPE__;

// Enum vtable
extern __Accelometer_Demo_IconNames_VTABLE_DECL__ __Accelometer_Demo_IconNames_VTABLE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:


//////////////////////////////////////////////////////////////////////////////////
// Methods:

// Accelometer_Demo
extern /* internalcall */ void __Accelometer_Demo_IL2C_MarkHandler__(Accelometer_Demo** this__);
extern /* internalcall */ void* __Accelometer_Demo_IL2C_RuntimeCast__(Accelometer_Demo** this__, IL2C_RUNTIME_TYPE_DECL* type);
extern System_Void* Accelometer_Demo_BeginAccelometer_0(System_Boolean highResolution, System_Byte scale)(System_Boolean highResolution, System_Byte scale);
extern System_Byte Accelometer_Demo_UpdateAccelometer_0()();
extern System_SByte Accelometer_Demo_GetAccelometerX_0()();
extern System_SByte Accelometer_Demo_GetAccelometerY_0()();
extern System_SByte Accelometer_Demo_GetAccelometerZ_0()();
extern System_Void* Accelometer_Demo_BeginScreen_0()();
extern System_Void* Accelometer_Demo_ShowArrow_0(Accelometer_Demo_ArrowNames direction, System_UInt32 interval)(Accelometer_Demo_ArrowNames direction, System_UInt32 interval);
extern System_Void* Accelometer_Demo_ShowIcon_0(Accelometer_Demo_IconNames icon, System_UInt32 interval)(Accelometer_Demo_IconNames icon, System_UInt32 interval);
extern System_Void* Accelometer_Demo_Delay_0(System_Int32 millis)(System_Int32 millis);
extern System_Void* Accelometer_Demo_Main_0()();

#ifdef __cplusplus
}
#endif

#endif
