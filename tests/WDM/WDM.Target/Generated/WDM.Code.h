#ifndef __MODULE_WDM_Code__
#define __MODULE_WDM_Code__

#include <il2c.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:

typedef struct WDM_Code_InterceptCDRomDevice WDM_Code_InterceptCDRomDevice;
typedef struct WDM_Code_Wdm WDM_Code_Wdm;

////////////////////////////////////////////////////////////
// Class: WDM.Code.InterceptCDRomDevice

struct WDM_Code_InterceptCDRomDevice
{
    intptr_t pFrom;
    intptr_t pTo;
    int32_t size;
};

extern const IL2C_RUNTIME_TYPE __WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: WDM.Code.Wdm


extern const IL2C_RUNTIME_TYPE __WDM_Code_Wdm_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:



//////////////////////////////////////////////////////////////////////////////////
// Methods:

extern void WDM_Code_InterceptCDRomDevice__ctor(WDM_Code_InterceptCDRomDevice* this__, intptr_t pFrom, intptr_t pTo, int32_t size);
extern uint32_t WDM_Code_InterceptCDRomDevice_ReadCompleted(WDM_Code_InterceptCDRomDevice* this__, intptr_t pBuffer, int32_t offset, int32_t size);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(WDM_Code_InterceptCDRomDevice* this__);
    int32_t (*GetHashCode)(WDM_Code_InterceptCDRomDevice* this__);
    void (*Finalize)(WDM_Code_InterceptCDRomDevice* this__);
    bool (*Equals)(WDM_Code_InterceptCDRomDevice* this__, System_Object* obj);
} __WDM_Code_InterceptCDRomDevice_TYPE_DEF_TYPE__;

#define WDM_Code_InterceptCDRomDevice_ToString(/* WDM_Code_InterceptCDRomDevice* */ this__) \
    (il2c_get_vtable(WDM_Code_InterceptCDRomDevice, this__)->ToString(this__))
#define WDM_Code_InterceptCDRomDevice_GetHashCode(/* WDM_Code_InterceptCDRomDevice* */ this__) \
    (il2c_get_vtable(WDM_Code_InterceptCDRomDevice, this__)->GetHashCode(this__))
#define WDM_Code_InterceptCDRomDevice_Finalize(/* WDM_Code_InterceptCDRomDevice* */ this__) \
    (il2c_get_vtable(WDM_Code_InterceptCDRomDevice, this__)->Finalize(this__))
#define WDM_Code_InterceptCDRomDevice_Equals(/* WDM_Code_InterceptCDRomDevice* */ this__, /* System_Object* */ obj) \
    (il2c_get_vtable(WDM_Code_InterceptCDRomDevice, this__)->Equals(this__, obj))

extern void WDM_Code_Wdm_DbgPrint(System_String* message);
extern void WDM_Code_Wdm_DbgPrint_1(uint32_t componentId, uint32_t level, System_String* message);
extern intptr_t WDM_Code_Wdm_memmem(intptr_t p1, int32_t s1, intptr_t p2, int32_t s2);
extern void WDM_Code_Wdm_memcpy(intptr_t pDest, intptr_t pSource, int32_t size);
extern void WDM_Code_Wdm__ctor(WDM_Code_Wdm* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(WDM_Code_Wdm* this__);
    int32_t (*GetHashCode)(WDM_Code_Wdm* this__);
    void (*Finalize)(WDM_Code_Wdm* this__);
    bool (*Equals)(WDM_Code_Wdm* this__, System_Object* obj);
} __WDM_Code_Wdm_TYPE_DEF_TYPE__;

#define WDM_Code_Wdm_ToString(/* WDM_Code_Wdm* */ this__) \
    (il2c_get_vtable(WDM_Code_Wdm, this__)->ToString(this__))
#define WDM_Code_Wdm_GetHashCode(/* WDM_Code_Wdm* */ this__) \
    (il2c_get_vtable(WDM_Code_Wdm, this__)->GetHashCode(this__))
#define WDM_Code_Wdm_Finalize(/* WDM_Code_Wdm* */ this__) \
    (il2c_get_vtable(WDM_Code_Wdm, this__)->Finalize(this__))
#define WDM_Code_Wdm_Equals(/* WDM_Code_Wdm* */ this__, /* System_Object* */ obj) \
    (il2c_get_vtable(WDM_Code_Wdm, this__)->Equals(this__, obj))

#ifdef __cplusplus
}
#endif

#endif
