#ifndef __Accelometer_Code_H__
#define __Accelometer_Code_H__

#include <il2c.h>
#include <stdbool.h>
#include <stdint.h>

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

//////////////////////////////////////////////////////////////////////////////////
// [2-2] Public static fields:


//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// Accelometer_Demo
extern /* internalcall */ void __Accelometer_Demo_IL2C_MarkHandler__(Accelometer_Demo* this__);
extern /* internalcall */ void* __Accelometer_Demo_IL2C_RuntimeCast__(Accelometer_Demo* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Accelometer_Demo_Main();
extern void Accelometer_Demo__ctor(Accelometer_Demo* this__);
#define System_Object_ToString(/* System_Object* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define System_Object_GetHashCode(/* System_Object* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define System_Object_Finalize(/* System_Object* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define System_Object_Equals(/* System_Object* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

#ifdef __cplusplus
}
#endif

#endif
