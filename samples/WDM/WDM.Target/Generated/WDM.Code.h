#ifndef __WDM_Code_H__
#define __WDM_Code_H__

#include <il2c.h>

#include <il2c.h>
#include <WDM.Code.h>
#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:

typedef struct WDM_Code_InterceptCDRomDevice WDM_Code_InterceptCDRomDevice;
typedef struct WDM_Code_Wdm WDM_Code_Wdm;

////////////////////////////////////////////////////////////
// [1] WDM.Code.InterceptCDRomDevice

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(WDM_Code_InterceptCDRomDevice* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __WDM_Code_InterceptCDRomDevice_VTABLE_DECL__;

// [1-3] Class layout
struct WDM_Code_InterceptCDRomDevice
{
    __WDM_Code_InterceptCDRomDevice_VTABLE_DECL__* vptr0__;
    intptr_t pFrom;
    intptr_t pTo;
    int32_t size;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __WDM_Code_InterceptCDRomDevice_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __WDM_Code_InterceptCDRomDevice_VTABLE_DECL__ __WDM_Code_InterceptCDRomDevice_VTABLE__;

////////////////////////////////////////////////////////////
// [1] WDM.Code.Wdm

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(WDM_Code_Wdm* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __WDM_Code_Wdm_VTABLE_DECL__;

// [1-3] Class layout
struct WDM_Code_Wdm
{
    __WDM_Code_Wdm_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __WDM_Code_Wdm_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __WDM_Code_Wdm_VTABLE_DECL__ __WDM_Code_Wdm_VTABLE__;

//////////////////////////////////////////////////////////////////////////////////
// [2-2] Public static fields:



//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: WDM.Code.InterceptCDRomDevice

extern /* internalcall */ void __WDM_Code_InterceptCDRomDevice_IL2C_MarkHandler__(WDM_Code_InterceptCDRomDevice* this__);
extern /* internalcall */ void* __WDM_Code_InterceptCDRomDevice_IL2C_RuntimeCast__(WDM_Code_InterceptCDRomDevice* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void WDM_Code_InterceptCDRomDevice__ctor(WDM_Code_InterceptCDRomDevice* this__, intptr_t pFrom, intptr_t pTo, int32_t size);
extern uint32_t WDM_Code_InterceptCDRomDevice_ReadCompleted(WDM_Code_InterceptCDRomDevice* this__, intptr_t pBuffer, int32_t offset, int32_t size);

// [2-5] Virtual methods: WDM.Code.InterceptCDRomDevice

#define WDM_Code_InterceptCDRomDevice_ToString(/* WDM_Code_InterceptCDRomDevice */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define WDM_Code_InterceptCDRomDevice_GetHashCode(/* WDM_Code_InterceptCDRomDevice */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define WDM_Code_InterceptCDRomDevice_Finalize(/* WDM_Code_InterceptCDRomDevice */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define WDM_Code_InterceptCDRomDevice_Equals(/* WDM_Code_InterceptCDRomDevice */ this__, /* WDM_Code_InterceptCDRomDevice */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: WDM.Code.Wdm

extern /* internalcall */ void __WDM_Code_Wdm_IL2C_MarkHandler__(WDM_Code_Wdm* this__);
extern /* internalcall */ void* __WDM_Code_Wdm_IL2C_RuntimeCast__(WDM_Code_Wdm* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void WDM_Code_Wdm_DbgPrint(System_String* message);
extern void WDM_Code_Wdm_DbgPrint_1(uint32_t componentId, uint32_t level, System_String* message);
extern intptr_t WDM_Code_Wdm_memmem(intptr_t p1, int32_t s1, intptr_t p2, int32_t s2);
extern void WDM_Code_Wdm_memcpy(intptr_t pDest, intptr_t pSource, int32_t size);
extern void WDM_Code_Wdm__ctor(WDM_Code_Wdm* this__);

// [2-5] Virtual methods: WDM.Code.Wdm

#define WDM_Code_Wdm_ToString(/* WDM_Code_Wdm */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define WDM_Code_Wdm_GetHashCode(/* WDM_Code_Wdm */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define WDM_Code_Wdm_Finalize(/* WDM_Code_Wdm */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define WDM_Code_Wdm_Equals(/* WDM_Code_Wdm */ this__, /* WDM_Code_Wdm */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

#ifdef __cplusplus
}
#endif

#endif
