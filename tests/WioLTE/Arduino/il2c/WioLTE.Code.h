#ifndef __MODULE_WioLTE_Code__
#define __MODULE_WioLTE_Code__

#include <il2c.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:

typedef struct WioLTE_Code_Arduino WioLTE_Code_Arduino;
typedef struct WioLTE_Code_Wio WioLTE_Code_Wio;

////////////////////////////////////////////////////////////
// Class: WioLTE.Code.Arduino


extern const __RUNTIME_TYPE__ __WioLTE_Code_Arduino_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: WioLTE.Code.Wio


extern const __RUNTIME_TYPE__ __WioLTE_Code_Wio_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:



//////////////////////////////////////////////////////////////////////////////////
// Methods:

extern int32_t WioLTE_Code_Arduino_DigitalRead(uint8_t pin);
extern void WioLTE_Code_Arduino_DigitalWrite(uint8_t pin, uint8_t val);
extern void WioLTE_Code_Arduino_Delay(int32_t milliseconds);
extern void WioLTE_Code_Arduino_PrintLn(System_String* message);
extern void WioLTE_Code_Arduino__ctor(WioLTE_Code_Arduino* __this);

extern void WioLTE_Code_Wio_Init(void);
extern void WioLTE_Code_Wio_LedSetRGB(int32_t r, int32_t g, int32_t b);
extern void WioLTE_Code_Wio__ctor(WioLTE_Code_Wio* __this);

#ifdef __cplusplus
}
#endif

#endif
