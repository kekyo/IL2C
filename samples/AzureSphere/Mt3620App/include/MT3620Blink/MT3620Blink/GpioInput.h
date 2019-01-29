// [14-1] This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////
// [14-2] Type pre definitions:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

/* internal sealed class */ typedef struct MT3620Blink_GpioInput MT3620Blink_GpioInput;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef MT3620Blink_Descriptor_VTABLE_DECL__ MT3620Blink_GpioInput_VTABLE_DECL__;

///////////////////////////////////////////////////////////////////////////
// [14-3] Type body definitions:

#ifdef MT3620Blink_DECL_TYPE_BODY__

////////////////////////////////////////////////////////////
// [1] MT3620Blink.GpioInput

// [1-1-2] Class layout
/* internal sealed class */ struct MT3620Blink_GpioInput
{
    MT3620Blink_GpioInput_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t baseField1__;
};

// [1-5-1] VTable (Same as MT3620Blink.Descriptor)
#define MT3620Blink_GpioInput_VTABLE__ MT3620Blink_Descriptor_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_GpioInput);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: MT3620Blink.GpioInput

extern /* public sealed */ void MT3620Blink_GpioInput__ctor(MT3620Blink_GpioInput* this__, int32_t gpioId);
extern /* public sealed */ bool MT3620Blink_GpioInput_get_Value(MT3620Blink_GpioInput* this__);

#endif

#ifdef __cplusplus
}
#endif
