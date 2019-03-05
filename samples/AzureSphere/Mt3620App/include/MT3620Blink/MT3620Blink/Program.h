// [14-1] This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////
// [14-2] Type pre definitions:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

/* private sealed class */ typedef struct MT3620Blink_Program_GpioBlinker MT3620Blink_Program_GpioBlinker;
/* private sealed class */ typedef struct MT3620Blink_Program_GpioPoller MT3620Blink_Program_GpioPoller;
/* public static class */ typedef struct MT3620Blink_Program MT3620Blink_Program;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef MT3620Blink_Timer_VTABLE_DECL__ MT3620Blink_Program_GpioBlinker_VTABLE_DECL__;
typedef MT3620Blink_Timer_VTABLE_DECL__ MT3620Blink_Program_GpioPoller_VTABLE_DECL__;
typedef System_Object_VTABLE_DECL__ MT3620Blink_Program_VTABLE_DECL__;

///////////////////////////////////////////////////////////////////////////
// [14-3] Type body definitions:

#ifdef MT3620Blink_DECL_TYPE_BODY__

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Program.GpioBlinker

// [1-1-2] Class layout
/* private sealed class */ struct MT3620Blink_Program_GpioBlinker
{
    MT3620Blink_Program_GpioBlinker_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t baseField1__;
    MT3620Blink_IEPollListener_VTABLE_DECL__* vptr_MT3620Blink_IEPollListener__;
    il2c_arraytype(System_Int64)* blinkIntervals;
    MT3620Blink_GpioOutput* output;
    bool flag;
    int32_t blinkIntervalIndex;
};

// [1-5-2] VTable (Derived from MT3620Blink.Timer)
extern MT3620Blink_Program_GpioBlinker_VTABLE_DECL__ MT3620Blink_Program_GpioBlinker_VTABLE__;

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Program_GpioBlinker);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: MT3620Blink.Program.GpioBlinker

extern /* public sealed */ void MT3620Blink_Program_GpioBlinker__ctor(MT3620Blink_Program_GpioBlinker* this__, int32_t gpioId);
extern /* public override sealed */ void MT3620Blink_Program_GpioBlinker_Dispose(MT3620Blink_Program_GpioBlinker* this__);
extern /* protected override sealed */ void MT3620Blink_Program_GpioBlinker_Raised(MT3620Blink_Program_GpioBlinker* this__);
extern /* public sealed */ void MT3620Blink_Program_GpioBlinker_NextInterval(MT3620Blink_Program_GpioBlinker* this__);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Program.GpioPoller

// [1-1-2] Class layout
/* private sealed class */ struct MT3620Blink_Program_GpioPoller
{
    MT3620Blink_Program_GpioPoller_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t baseField1__;
    MT3620Blink_IEPollListener_VTABLE_DECL__* vptr_MT3620Blink_IEPollListener__;
    MT3620Blink_GpioInput* changeInput;
    MT3620Blink_GpioInput* exitInput;
    bool lastChangeInput;
    bool lastExitInput;
    MT3620Blink_Program_GpioBlinker* blinker;
    MT3620Blink_Application* app;
};

// [1-5-2] VTable (Derived from MT3620Blink.Timer)
extern MT3620Blink_Program_GpioPoller_VTABLE_DECL__ MT3620Blink_Program_GpioPoller_VTABLE__;

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Program_GpioPoller);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: MT3620Blink.Program.GpioPoller

extern /* public sealed */ void MT3620Blink_Program_GpioPoller__ctor(MT3620Blink_Program_GpioPoller* this__, int32_t changeInputGpioId, int32_t exitInputGpioId, MT3620Blink_Program_GpioBlinker* blinker, MT3620Blink_Application* app);
extern /* public override sealed */ void MT3620Blink_Program_GpioPoller_Dispose(MT3620Blink_Program_GpioPoller* this__);
extern /* protected override sealed */ void MT3620Blink_Program_GpioPoller_Raised(MT3620Blink_Program_GpioPoller* this__);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Program

// [1-1-2] Class layout
/* public static class */ struct MT3620Blink_Program
{
    MT3620Blink_Program_VTABLE_DECL__* vptr0__;
};

// [1-5-1] VTable (Same as System.Object)
#define MT3620Blink_Program_VTABLE__ System_Object_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Program);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: MT3620Blink.Program

extern /* public static sealed */ int32_t MT3620Blink_Program_Main(void);

#endif

#ifdef __cplusplus
}
#endif
