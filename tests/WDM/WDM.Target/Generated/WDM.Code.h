#ifndef __MODULE_WDM_Code__
#define __MODULE_WDM_Code__

#include <il2c.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:

typedef struct WDM_Code_HelloDriver WDM_Code_HelloDriver;
typedef struct WDM_Code_Wdm WDM_Code_Wdm;

////////////////////////////////////////////////////////////
// Class: WDM.Code.HelloDriver


extern const __RUNTIME_TYPE__ __WDM_Code_HelloDriver_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: WDM.Code.Wdm


extern const __RUNTIME_TYPE__ __WDM_Code_Wdm_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:



//////////////////////////////////////////////////////////////////////////////////
// Methods:

extern void WDM_Code_HelloDriver__ctor(WDM_Code_HelloDriver* __this);
extern uint32_t WDM_Code_HelloDriver_Read(WDM_Code_HelloDriver* __this, intptr_t pIrp, intptr_t pStackLocation);

extern void WDM_Code_Wdm_DbgPrint(System_String* message);
extern void WDM_Code_Wdm_DbgPrint_1(uint32_t componentId, uint32_t level, System_String* message);
extern void WDM_Code_Wdm__ctor(WDM_Code_Wdm* __this);

#ifdef __cplusplus
}
#endif

#endif
