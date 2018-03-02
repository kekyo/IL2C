#ifndef __MODULE_Accelometer_Code__
#define __MODULE_Accelometer_Code__

#include <il2c.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:

typedef struct Accelometer_Code_Class1 Accelometer_Code_Class1;

////////////////////////////////////////////////////////////
// Class: Accelometer.Code.Class1


extern const __RUNTIME_TYPE__ __Accelometer_Code_Class1_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:


//////////////////////////////////////////////////////////////////////////////////
// Methods:

extern void Accelometer_Code_Class1__ctor(Accelometer_Code_Class1* __this);

typedef const struct
{
    intptr_t __reserved0__;
    intptr_t __reserved1__;
    intptr_t __reserved2__;
    System_String* (*ToString)(System_Object* __this);
    int32_t (*GetHashCode)(System_Object* __this);
    void (*Finalize)(System_Object* __this);
    bool (*Equals)(System_Object* __this, System_Object* obj);
} __Accelometer_Code_Class1_TYPE_DEF_TYPE__;


#ifdef __cplusplus
}
#endif

#endif
