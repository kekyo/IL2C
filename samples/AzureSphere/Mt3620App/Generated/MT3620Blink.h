#ifndef __MT3620Blink_H__
#define __MT3620Blink_H__

#pragma once

#include <il2c.h>

#include <MT3620Blink.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

typedef struct MT3620Blink_Descriptor MT3620Blink_Descriptor;
typedef struct MT3620Blink_IEPollListener MT3620Blink_IEPollListener;
typedef struct MT3620Blink_Application MT3620Blink_Application;
typedef struct MT3620Blink_Program MT3620Blink_Program;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef const struct MT3620Blink_Descriptor_VTABLE_DECL___ MT3620Blink_Descriptor_VTABLE_DECL__;
typedef const struct MT3620Blink_IEPollListener_VTABLE_DECL___ MT3620Blink_IEPollListener_VTABLE_DECL__;
typedef MT3620Blink_Descriptor_VTABLE_DECL__ MT3620Blink_Application_VTABLE_DECL__;
typedef System_Object_VTABLE_DECL__ MT3620Blink_Program_VTABLE_DECL__;

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Descriptor

// [1-2-3] Class VTable layout (Derived from System.Object)
struct MT3620Blink_Descriptor_VTABLE_DECL___
{
    intptr_t offset__; // Adjustor offset
    bool (*Equals)(void* this__, System_Object* obj);
    void (*Finalize)(void* this__);
    int32_t (*GetHashCode)(void* this__);
    System_String* (*ToString)(void* this__);
    void (*Dispose)(void* this__);
    void (*OnRaised)(void* this__);
};

// [1-1-2] Class layout
struct MT3620Blink_Descriptor
{
    MT3620Blink_Descriptor_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t _Identity_k__BackingField;
};

// [1-5-2] VTable (Derived from System.Object)
extern MT3620Blink_Descriptor_VTABLE_DECL__ MT3620Blink_Descriptor_VTABLE__;

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Descriptor);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.IEPollListener

// [1-2-2] Interface VTable layout
struct MT3620Blink_IEPollListener_VTABLE_DECL___
{
    intptr_t offset__; // Adjustor offset
    int32_t (*get_Identity)(void* this__);
    void (*OnRaised)(void* this__);
};

// [1-1-2] Interface layout
struct MT3620Blink_IEPollListener
{
    MT3620Blink_IEPollListener_VTABLE_DECL__* vptr0__;
};

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_IEPollListener);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Application

// [1-1-2] Class layout
struct MT3620Blink_Application
{
    MT3620Blink_Application_VTABLE_DECL__* vptr0__;
    System_IDisposable_VTABLE_DECL__* vptr_System_IDisposable__;
    int32_t baseField1__;
};

// [1-5-1] VTable (Same as MT3620Blink.Descriptor)
#define MT3620Blink_Application_VTABLE__ MT3620Blink_Descriptor_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Application);

////////////////////////////////////////////////////////////
// [1] MT3620Blink.Program

// [1-1-2] Class layout
struct MT3620Blink_Program
{
    MT3620Blink_Program_VTABLE_DECL__* vptr0__;
};

// [1-5-1] VTable (Same as System.Object)
#define MT3620Blink_Program_VTABLE__ System_Object_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(MT3620Blink_Program);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: MT3620Blink.Descriptor

extern /* public */ void MT3620Blink_Descriptor__ctor(MT3620Blink_Descriptor* this__, int32_t fd);
extern /* public virtual */ void MT3620Blink_Descriptor_Dispose(MT3620Blink_Descriptor* this__);
extern /* protected */ int32_t MT3620Blink_Descriptor_get_Identity(MT3620Blink_Descriptor* this__);
extern /* protected virtual */ void MT3620Blink_Descriptor_OnRaised(MT3620Blink_Descriptor* this__);

// [2-4] Member methods: MT3620Blink.Application

extern /* public sealed */ void MT3620Blink_Application__ctor(MT3620Blink_Application* this__);
extern /* public sealed */ void MT3620Blink_Application_RegisterDescriptor(MT3620Blink_Application* this__, MT3620Blink_IEPollListener* target);
extern /* public sealed */ void MT3620Blink_Application_UnregisterDescriptor(MT3620Blink_Application* this__, MT3620Blink_IEPollListener* target);
extern /* public sealed */ void MT3620Blink_Application_Run(MT3620Blink_Application* this__);

// [2-4] Member methods: MT3620Blink.Program

extern /* public static sealed */ int32_t MT3620Blink_Program_Main(void);

#ifdef __cplusplus
}
#endif

#endif
