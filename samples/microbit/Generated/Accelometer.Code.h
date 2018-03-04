#ifndef __MODULE_Accelometer_Code__
#define __MODULE_Accelometer_Code__

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
    System_String* (*ToString)(Accelometer_Demo* this__);
    int32_t (*GetHashCode)(Accelometer_Demo* this__);
    void (*Finalize)(Accelometer_Demo* this__);
    bool (*Equals)(Accelometer_Demo* this__, System_Object* obj);
} __Accelometer_Demo_VTABLE_DECL__;

// Class layout
struct Accelometer_Demo
{
    __Accelometer_Demo_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Accelometer_Demo_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:


//////////////////////////////////////////////////////////////////////////////////
// Methods:

// Accelometer.Demo
extern /* internalcall */ void __Accelometer_Demo_IL2C_MarkHandler__(Accelometer_Demo* this__);
extern /* internalcall */ void* __Accelometer_Demo_IL2C_RuntimeCast__(Accelometer_Demo* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Accelometer_Demo_Main(void);
extern void Accelometer_Demo__ctor(Accelometer_Demo* this__);
#define Accelometer_Demo_ToString(/* Accelometer_Demo* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Accelometer_Demo_GetHashCode(/* Accelometer_Demo* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Accelometer_Demo_Finalize(/* Accelometer_Demo* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Accelometer_Demo_Equals(/* Accelometer_Demo* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

#ifdef __cplusplus
}
#endif

#endif
