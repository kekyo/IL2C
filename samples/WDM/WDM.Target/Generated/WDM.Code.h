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

// Class vtable layout
typedef const struct
{
    void* (*IL2C_RuntimeCast)(WDM_Code_InterceptCDRomDevice* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(WDM_Code_InterceptCDRomDevice* this__);
    int32_t (*GetHashCode)(WDM_Code_InterceptCDRomDevice* this__);
    void (*Finalize)(WDM_Code_InterceptCDRomDevice* this__);
    bool (*Equals)(WDM_Code_InterceptCDRomDevice* this__, System_Object* obj);
} __WDM_Code_InterceptCDRomDevice_VTABLE_DECL__;

// Class layout
struct WDM_Code_InterceptCDRomDevice
{
// Instance's vptr
    __WDM_Code_InterceptCDRomDevice_VTABLE_DECL__* vptr__;

    intptr_t pFrom;
    intptr_t pTo;
    int32_t size;
};

// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: WDM.Code.Wdm

// Class vtable layout
typedef const struct
{
    void* (*IL2C_RuntimeCast)(WDM_Code_Wdm* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(WDM_Code_Wdm* this__);
    int32_t (*GetHashCode)(WDM_Code_Wdm* this__);
    void (*Finalize)(WDM_Code_Wdm* this__);
    bool (*Equals)(WDM_Code_Wdm* this__, System_Object* obj);
} __WDM_Code_Wdm_VTABLE_DECL__;

// Class layout
struct WDM_Code_Wdm
{
// Instance's vptr
    __WDM_Code_Wdm_VTABLE_DECL__* vptr__;

};

// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __WDM_Code_Wdm_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:



//////////////////////////////////////////////////////////////////////////////////
// Methods:

extern void WDM_Code_InterceptCDRomDevice__ctor(WDM_Code_InterceptCDRomDevice* this__, intptr_t pFrom, intptr_t pTo, int32_t size);
extern uint32_t WDM_Code_InterceptCDRomDevice_ReadCompleted(WDM_Code_InterceptCDRomDevice* this__, intptr_t pBuffer, int32_t offset, int32_t size);
#define WDM_Code_InterceptCDRomDevice_ToString(/* WDM_Code_InterceptCDRomDevice* */ this__) \
    ((this__)->vptr__->ToString((System_Object*)(this__)))
#define WDM_Code_InterceptCDRomDevice_GetHashCode(/* WDM_Code_InterceptCDRomDevice* */ this__) \
    ((this__)->vptr__->GetHashCode((System_Object*)(this__)))
#define WDM_Code_InterceptCDRomDevice_Finalize(/* WDM_Code_InterceptCDRomDevice* */ this__) \
    ((this__)->vptr__->Finalize((System_Object*)(this__)))
#define WDM_Code_InterceptCDRomDevice_Equals(/* WDM_Code_InterceptCDRomDevice* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr__->Equals((System_Object*)(this__), (obj)))

extern void WDM_Code_Wdm_DbgPrint(System_String* message);
extern void WDM_Code_Wdm_DbgPrint_1(uint32_t componentId, uint32_t level, System_String* message);
extern intptr_t WDM_Code_Wdm_memmem(intptr_t p1, int32_t s1, intptr_t p2, int32_t s2);
extern void WDM_Code_Wdm_memcpy(intptr_t pDest, intptr_t pSource, int32_t size);
extern void WDM_Code_Wdm__ctor(WDM_Code_Wdm* this__);
#define WDM_Code_Wdm_ToString(/* WDM_Code_Wdm* */ this__) \
    ((this__)->vptr__->ToString((System_Object*)(this__)))
#define WDM_Code_Wdm_GetHashCode(/* WDM_Code_Wdm* */ this__) \
    ((this__)->vptr__->GetHashCode((System_Object*)(this__)))
#define WDM_Code_Wdm_Finalize(/* WDM_Code_Wdm* */ this__) \
    ((this__)->vptr__->Finalize((System_Object*)(this__)))
#define WDM_Code_Wdm_Equals(/* WDM_Code_Wdm* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr__->Equals((System_Object*)(this__), (obj)))

#ifdef __cplusplus
}
#endif

#endif
