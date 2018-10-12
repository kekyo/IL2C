#ifndef __Accelometer_Code_H__
#define __Accelometer_Code_H__

#include <il2c.h>
#include <Accelometer.Code.h>

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
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
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

// [2-4] Member methods: Accelometer.Demo

extern void Accelometer_Demo_Main();

#ifdef __cplusplus
}
#endif

#endif
