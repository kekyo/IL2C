#ifndef __Accelometer_FSharp_Code_H__
#define __Accelometer_FSharp_Code_H__

#include <il2c.h>

#include <il2c.h>
#include <Accelometer.FSharp.Code.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:

typedef struct Accelometer_Demo Accelometer_Demo;

////////////////////////////////////////////////////////////
// [1] Accelometer.Demo

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Accelometer_Demo* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* __System_Object_ToString__(System_Object* this__);
    int32_t __System_Object_GetHashCode__(System_Object* this__);
    void __System_Object_Finalize__(System_Object* this__);
    bool __System_Object_Equals__(System_Object* this__, System_Object* obj);
} __Accelometer_Demo_VTABLE_DECL__;

// [1-3] Class layout
struct Accelometer_Demo
{
    __Accelometer_Demo_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __Accelometer_Demo_VTABLE_DECL__ __Accelometer_Demo_VTABLE__;

////////////////////////////////////////////////////////////
// [1] Accelometer.Demo.ArrowNames

// [1-1] Enum layout
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
} Accelometer_Demo_ArrowNames;

// [1-4] Enum runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_ArrowNames_RUNTIME_TYPE__;

// [1-5] Enum vtable
extern __Accelometer_Demo_ArrowNames_VTABLE_DECL__ __Accelometer_Demo_ArrowNames_VTABLE__;

////////////////////////////////////////////////////////////
// [1] Accelometer.Demo.IconNames

// [1-1] Enum layout
typedef enum Accelometer_Demo_IconNames
{
    Accelometer_Demo_IconNames_Heart = 0,
} Accelometer_Demo_IconNames;

// [1-4] Enum runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_IconNames_RUNTIME_TYPE__;

// [1-5] Enum vtable
extern __Accelometer_Demo_IconNames_VTABLE_DECL__ __Accelometer_Demo_IconNames_VTABLE__;

//////////////////////////////////////////////////////////////////////////////////
// [2-2] Public static fields:




//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: <StartupCode$Accelometer-FSharp-Code>.$.NETStandard,Version=v2.0.AssemblyAttributes


// [2-4] Member methods: Accelometer.Demo

extern void Accelometer_Demo_BeginAccelometer(bool highResolution, uint8_t scale);
extern uint8_t Accelometer_Demo_UpdateAccelometer();
extern int8_t Accelometer_Demo_GetAccelometerX();
extern int8_t Accelometer_Demo_GetAccelometerY();
extern int8_t Accelometer_Demo_GetAccelometerZ();
extern void Accelometer_Demo_BeginScreen();
extern void Accelometer_Demo_ShowArrow(Accelometer_Demo_ArrowNames direction, uint32_t interval);
extern void Accelometer_Demo_ShowIcon(Accelometer_Demo_IconNames icon, uint32_t interval);
extern void Accelometer_Demo_Delay(int32_t millis);
extern void Accelometer_Demo_Main();

// [2-4] Member methods: <StartupCode$Accelometer-FSharp-Code>.$Demo


#ifdef __cplusplus
}
#endif

#endif
