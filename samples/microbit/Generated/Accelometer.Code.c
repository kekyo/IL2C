#include "Accelometer.Code.h"

//////////////////////////////////////////////////////////////////////////////////
// Const strings:


#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:


//////////////////////////////////////////////////////////////////////////////////
// Public static fields:

//////////////////////////////////////////////////////////////////////////////////
// Methods:

#ifdef __cplusplus
}
#endif

//////////////////////////////////////////////////////////////////////////////////
// Static fields:


//////////////////////////////////////////////////////////////////////////////////
// Methods:

////////////////////////////////////////////////////////////
// Type: Accelometer.Code.Class1

///////////////////////////////////////
// .ctor

void Accelometer_Code_Class1__ctor(Accelometer_Code_Class1* __this)
{
    //-------------------
    // Local variables:


    //-------------------
    // Evaluation stacks:

    Accelometer_Code_Class1* __stack0_0 = NULL;

    //-------------------
    // Setup stack frame:

    struct /* __EXECUTION_FRAME__ */
    {
        __EXECUTION_FRAME__* pNext;
        uint8_t targetCount;
        Accelometer_Code_Class1** p__stack0_0;
    } __executionFrame__;

    __executionFrame__.targetCount = 1;
    __executionFrame__.p__stack0_0 = &__stack0_0;
    __gc_link_execution_frame__(&__executionFrame__);

    //-------------------
    // IL body:

    /* Path=1, Unique=0: IL_0000: ldarg.0 */
    __stack0_0 = __this;
    /* Path=1, Unique=0: IL_0001: call System.Void System.Object::.ctor() */
    System_Object__ctor((System_Object*)__stack0_0);
    /* Path=1, Unique=0: IL_0006: nop */
    /* Path=1, Unique=0: IL_0007: ret */
    __gc_unlink_execution_frame__(&__executionFrame__);
    return;
}

//////////////////////
// Runtime helpers:

static void __Accelometer_Code_Class1_MARK_HANDLER__(void* pReference)
{
    __typeof__(System_Object)->pMarkHandler(pReference);
}

static __Accelometer_Code_Class1_TYPE_DEF_TYPE__ __Accelometer_Code_Class1_RUNTIME_TYPE_DEF__ = {
    (intptr_t)"Accelometer.Code.Class1",
    (intptr_t)0,
    (intptr_t)__Accelometer_Code_Class1_MARK_HANDLER__,
    __System_Object_ToString__,
    __System_Object_GetHashCode__,
    __System_Object_Finalize__,
    __System_Object_Equals__,
};
const __RUNTIME_TYPE__ __Accelometer_Code_Class1_RUNTIME_TYPE__ =
   (const __RUNTIME_TYPE__)(&__Accelometer_Code_Class1_RUNTIME_TYPE_DEF__);
