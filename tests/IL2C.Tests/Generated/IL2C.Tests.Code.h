#ifndef __MODULE_IL2C_Tests_Code__
#define __MODULE_IL2C_Tests_Code__

#include <il2c.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:

typedef struct IL2C_Tests_BoxingTest IL2C_Tests_BoxingTest;
typedef struct IL2C_Tests_ClassTypeTestTarget IL2C_Tests_ClassTypeTestTarget;
typedef struct IL2C_Tests_ClassTypeTest IL2C_Tests_ClassTypeTest;
typedef struct IL2C_Tests_Hoge1 IL2C_Tests_Hoge1;
typedef struct IL2C_Tests_Hoge2 IL2C_Tests_Hoge2;
typedef struct IL2C_Tests_InheritTestTargetBase1 IL2C_Tests_InheritTestTargetBase1;
typedef struct IL2C_Tests_InheritTestTarget2 IL2C_Tests_InheritTestTarget2;
typedef struct IL2C_Tests_InheritTypeTest IL2C_Tests_InheritTypeTest;
typedef struct IL2C_Tests_IInterfaceTestTarget IL2C_Tests_IInterfaceTestTarget;
typedef struct IL2C_Tests_IInterfaceTestTarget2 IL2C_Tests_IInterfaceTestTarget2;
typedef struct IL2C_Tests_InterfaceTestTargetClass IL2C_Tests_InterfaceTestTargetClass;
typedef struct IL2C_Tests_InterfaceTypeTest IL2C_Tests_InterfaceTypeTest;
typedef struct IL2C_Tests_Win32 IL2C_Tests_Win32;
typedef struct IL2C_Tests_StringTest IL2C_Tests_StringTest;
typedef struct IL2C_Tests_UnsafeTest IL2C_Tests_UnsafeTest;
typedef struct IL2C_Tests_ValueTypeTestTarget IL2C_Tests_ValueTypeTestTarget;
typedef struct IL2C_Tests_ValueTypeTest IL2C_Tests_ValueTypeTest;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.BoxingTest

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_BoxingTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_BoxingTest* this__);
    int32_t (*GetHashCode)(IL2C_Tests_BoxingTest* this__);
    void (*Finalize)(IL2C_Tests_BoxingTest* this__);
    bool (*Equals)(IL2C_Tests_BoxingTest* this__, System_Object* obj);
} __IL2C_Tests_BoxingTest_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_BoxingTest
{
    __IL2C_Tests_BoxingTest_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_BoxingTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.ClassTypeTestTarget

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_ClassTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_ClassTypeTestTarget* this__);
    int32_t (*GetHashCode)(IL2C_Tests_ClassTypeTestTarget* this__);
    void (*Finalize)(IL2C_Tests_ClassTypeTestTarget* this__);
    bool (*Equals)(IL2C_Tests_ClassTypeTestTarget* this__, System_Object* obj);
} __IL2C_Tests_ClassTypeTestTarget_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_ClassTypeTestTarget
{
    __IL2C_Tests_ClassTypeTestTarget_VTABLE_DECL__* vptr0__;
    int32_t Value2;
    IL2C_Tests_ClassTypeTestTarget* OR2;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_ClassTypeTestTarget_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.ClassTypeTest

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_ClassTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_ClassTypeTest* this__);
    int32_t (*GetHashCode)(IL2C_Tests_ClassTypeTest* this__);
    void (*Finalize)(IL2C_Tests_ClassTypeTest* this__);
    bool (*Equals)(IL2C_Tests_ClassTypeTest* this__, System_Object* obj);
} __IL2C_Tests_ClassTypeTest_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_ClassTypeTest
{
    __IL2C_Tests_ClassTypeTest_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_ClassTypeTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.Hoge1

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_Hoge1* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_Hoge1* this__);
    int32_t (*GetHashCode)(IL2C_Tests_Hoge1* this__);
    void (*Finalize)(IL2C_Tests_Hoge1* this__);
    bool (*Equals)(IL2C_Tests_Hoge1* this__, System_Object* obj);
} __IL2C_Tests_Hoge1_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_Hoge1
{
    __IL2C_Tests_Hoge1_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_Hoge1_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.Hoge2

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_Hoge2* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_Hoge2* this__);
    int32_t (*GetHashCode)(IL2C_Tests_Hoge2* this__);
    void (*Finalize)(IL2C_Tests_Hoge2* this__);
    bool (*Equals)(IL2C_Tests_Hoge2* this__, System_Object* obj);
} __IL2C_Tests_Hoge2_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_Hoge2
{
    __IL2C_Tests_Hoge2_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_Hoge2_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.InheritTestTargetBase1

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_InheritTestTargetBase1* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_InheritTestTargetBase1* this__);
    int32_t (*GetHashCode)(IL2C_Tests_InheritTestTargetBase1* this__);
    void (*Finalize)(IL2C_Tests_InheritTestTargetBase1* this__);
    bool (*Equals)(IL2C_Tests_InheritTestTargetBase1* this__, System_Object* obj);
    int32_t (*Calc_1)(IL2C_Tests_InheritTestTargetBase1* this__, int32_t a, int32_t b);
} __IL2C_Tests_InheritTestTargetBase1_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_InheritTestTargetBase1
{
    __IL2C_Tests_InheritTestTargetBase1_VTABLE_DECL__* vptr0__;
    int32_t Value2;
    IL2C_Tests_ClassTypeTestTarget* OR2;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InheritTestTargetBase1_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.InheritTestTarget2

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_InheritTestTarget2* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_InheritTestTarget2* this__);
    int32_t (*GetHashCode)(IL2C_Tests_InheritTestTarget2* this__);
    void (*Finalize)(IL2C_Tests_InheritTestTarget2* this__);
    bool (*Equals)(IL2C_Tests_InheritTestTarget2* this__, System_Object* obj);
    int32_t (*Calc_1)(IL2C_Tests_InheritTestTarget2* this__, int32_t a, int32_t b);
} __IL2C_Tests_InheritTestTarget2_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_InheritTestTarget2
{
    __IL2C_Tests_InheritTestTarget2_VTABLE_DECL__* vptr0__;
    int32_t Value2;
    IL2C_Tests_ClassTypeTestTarget* OR2;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InheritTestTarget2_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.InheritTypeTest

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_InheritTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_InheritTypeTest* this__);
    int32_t (*GetHashCode)(IL2C_Tests_InheritTypeTest* this__);
    void (*Finalize)(IL2C_Tests_InheritTypeTest* this__);
    bool (*Equals)(IL2C_Tests_InheritTypeTest* this__, System_Object* obj);
} __IL2C_Tests_InheritTypeTest_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_InheritTypeTest
{
    __IL2C_Tests_InheritTypeTest_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InheritTypeTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Interface: IL2C.Tests.IInterfaceTestTarget

// Interface vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_IInterfaceTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_IInterfaceTestTarget* this__);
    int32_t (*GetHashCode)(IL2C_Tests_IInterfaceTestTarget* this__);
    void (*Finalize)(IL2C_Tests_IInterfaceTestTarget* this__);
    bool (*Equals)(IL2C_Tests_IInterfaceTestTarget* this__, System_Object* obj);
    int32_t (*Calc)(IL2C_Tests_IInterfaceTestTarget* this__, int32_t a, int32_t b);
} __IL2C_Tests_IInterfaceTestTarget_VTABLE_DECL__;

// Interface layout
struct IL2C_Tests_IInterfaceTestTarget
{
    __IL2C_Tests_IInterfaceTestTarget_VTABLE_DECL__* vptr0__;
};


// Interface runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_IInterfaceTestTarget_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Interface: IL2C.Tests.IInterfaceTestTarget2

// Interface vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_IInterfaceTestTarget2* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_IInterfaceTestTarget2* this__);
    int32_t (*GetHashCode)(IL2C_Tests_IInterfaceTestTarget2* this__);
    void (*Finalize)(IL2C_Tests_IInterfaceTestTarget2* this__);
    bool (*Equals)(IL2C_Tests_IInterfaceTestTarget2* this__, System_Object* obj);
    int32_t (*Calc2)(IL2C_Tests_IInterfaceTestTarget2* this__, int32_t a, int32_t b);
} __IL2C_Tests_IInterfaceTestTarget2_VTABLE_DECL__;

// Interface layout
struct IL2C_Tests_IInterfaceTestTarget2
{
    __IL2C_Tests_IInterfaceTestTarget2_VTABLE_DECL__* vptr0__;
};


// Interface runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_IInterfaceTestTarget2_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.InterfaceTestTargetClass

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_InterfaceTestTargetClass* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_InterfaceTestTargetClass* this__);
    int32_t (*GetHashCode)(IL2C_Tests_InterfaceTestTargetClass* this__);
    void (*Finalize)(IL2C_Tests_InterfaceTestTargetClass* this__);
    bool (*Equals)(IL2C_Tests_InterfaceTestTargetClass* this__, System_Object* obj);
    int32_t (*Calc)(IL2C_Tests_InterfaceTestTargetClass* this__, int32_t a, int32_t b);
    int32_t (*Calc2)(IL2C_Tests_InterfaceTestTargetClass* this__, int32_t a, int32_t b);
} __IL2C_Tests_InterfaceTestTargetClass_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_InterfaceTestTargetClass
{
    __IL2C_Tests_InterfaceTestTargetClass_VTABLE_DECL__* vptr0__;
    __IL2C_Tests_IInterfaceTestTarget_VTABLE_DECL__* vptr_IL2C_Tests_IInterfaceTestTarget__;
    __IL2C_Tests_IInterfaceTestTarget2_VTABLE_DECL__* vptr_IL2C_Tests_IInterfaceTestTarget2__;
    int32_t Value2;
    IL2C_Tests_ClassTypeTestTarget* OR2;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InterfaceTestTargetClass_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.InterfaceTypeTest

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_InterfaceTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_InterfaceTypeTest* this__);
    int32_t (*GetHashCode)(IL2C_Tests_InterfaceTypeTest* this__);
    void (*Finalize)(IL2C_Tests_InterfaceTypeTest* this__);
    bool (*Equals)(IL2C_Tests_InterfaceTypeTest* this__, System_Object* obj);
} __IL2C_Tests_InterfaceTypeTest_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_InterfaceTypeTest
{
    __IL2C_Tests_InterfaceTypeTest_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InterfaceTypeTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.Win32

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_Win32* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_Win32* this__);
    int32_t (*GetHashCode)(IL2C_Tests_Win32* this__);
    void (*Finalize)(IL2C_Tests_Win32* this__);
    bool (*Equals)(IL2C_Tests_Win32* this__, System_Object* obj);
} __IL2C_Tests_Win32_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_Win32
{
    __IL2C_Tests_Win32_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_Win32_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.StringTest

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_StringTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_StringTest* this__);
    int32_t (*GetHashCode)(IL2C_Tests_StringTest* this__);
    void (*Finalize)(IL2C_Tests_StringTest* this__);
    bool (*Equals)(IL2C_Tests_StringTest* this__, System_Object* obj);
} __IL2C_Tests_StringTest_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_StringTest
{
    __IL2C_Tests_StringTest_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_StringTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.UnsafeTest

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_UnsafeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_UnsafeTest* this__);
    int32_t (*GetHashCode)(IL2C_Tests_UnsafeTest* this__);
    void (*Finalize)(IL2C_Tests_UnsafeTest* this__);
    bool (*Equals)(IL2C_Tests_UnsafeTest* this__, System_Object* obj);
} __IL2C_Tests_UnsafeTest_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_UnsafeTest
{
    __IL2C_Tests_UnsafeTest_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_UnsafeTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Struct: IL2C.Tests.ValueTypeTestTarget

// Struct vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_ValueTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_ValueTypeTestTarget this__);
    int32_t (*GetHashCode)(IL2C_Tests_ValueTypeTestTarget this__);
    void (*Finalize)(IL2C_Tests_ValueTypeTestTarget this__);
    bool (*Equals)(IL2C_Tests_ValueTypeTestTarget this__, System_Object* obj);
} __IL2C_Tests_ValueTypeTestTarget_VTABLE_DECL__;

// Struct layout
struct IL2C_Tests_ValueTypeTestTarget
{
    __IL2C_Tests_ValueTypeTestTarget_VTABLE_DECL__* vptr0__;
    int32_t Value2;
    IL2C_Tests_ClassTypeTestTarget* OR2;
};


// Struct runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_ValueTypeTestTarget_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: IL2C.Tests.ValueTypeTest

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_ValueTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(IL2C_Tests_ValueTypeTest* this__);
    int32_t (*GetHashCode)(IL2C_Tests_ValueTypeTest* this__);
    void (*Finalize)(IL2C_Tests_ValueTypeTest* this__);
    bool (*Equals)(IL2C_Tests_ValueTypeTest* this__, System_Object* obj);
} __IL2C_Tests_ValueTypeTest_VTABLE_DECL__;

// Class layout
struct IL2C_Tests_ValueTypeTest
{
    __IL2C_Tests_ValueTypeTest_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_ValueTypeTest_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:


extern int32_t IL2C_Tests_ClassTypeTestTarget_Value1;
extern IL2C_Tests_ClassTypeTestTarget* IL2C_Tests_ClassTypeTestTarget_OR1;














extern int32_t IL2C_Tests_ValueTypeTestTarget_Value1;


//////////////////////////////////////////////////////////////////////////////////
// Methods:

// IL2C.Tests.BoxingTest
extern /* internalcall */ void __IL2C_Tests_BoxingTest_IL2C_MarkHandler__(IL2C_Tests_BoxingTest* this__);
extern /* internalcall */ void* __IL2C_Tests_BoxingTest_IL2C_RuntimeCast__(IL2C_Tests_BoxingTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_BoxingTest_BoxingInt32(int32_t a);
extern void IL2C_Tests_BoxingTest__ctor(IL2C_Tests_BoxingTest* this__);
#define IL2C_Tests_BoxingTest_ToString(/* IL2C_Tests_BoxingTest* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_BoxingTest_GetHashCode(/* IL2C_Tests_BoxingTest* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_BoxingTest_Finalize(/* IL2C_Tests_BoxingTest* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_BoxingTest_Equals(/* IL2C_Tests_BoxingTest* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// IL2C.Tests.ClassTypeTestTarget
extern /* internalcall */ void __IL2C_Tests_ClassTypeTestTarget_IL2C_MarkHandler__(IL2C_Tests_ClassTypeTestTarget* this__);
extern /* internalcall */ void* __IL2C_Tests_ClassTypeTestTarget_IL2C_RuntimeCast__(IL2C_Tests_ClassTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_ClassTypeTestTarget__ctor(IL2C_Tests_ClassTypeTestTarget* this__);
extern void IL2C_Tests_ClassTypeTestTarget__ctor_1(IL2C_Tests_ClassTypeTestTarget* this__, int32_t value);
extern int32_t IL2C_Tests_ClassTypeTestTarget_GetValue2(IL2C_Tests_ClassTypeTestTarget* this__, int32_t a, int32_t b);
extern int32_t IL2C_Tests_ClassTypeTestTarget_GetValue2_1(IL2C_Tests_ClassTypeTestTarget* this__, int32_t a, int32_t b, int32_t c);
#define IL2C_Tests_ClassTypeTestTarget_ToString(/* IL2C_Tests_ClassTypeTestTarget* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_ClassTypeTestTarget_GetHashCode(/* IL2C_Tests_ClassTypeTestTarget* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_ClassTypeTestTarget_Finalize(/* IL2C_Tests_ClassTypeTestTarget* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_ClassTypeTestTarget_Equals(/* IL2C_Tests_ClassTypeTestTarget* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// IL2C.Tests.ClassTypeTest
extern /* internalcall */ void __IL2C_Tests_ClassTypeTest_IL2C_MarkHandler__(IL2C_Tests_ClassTypeTest* this__);
extern /* internalcall */ void* __IL2C_Tests_ClassTypeTest_IL2C_RuntimeCast__(IL2C_Tests_ClassTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_ClassTypeTest_Test4(void);
extern int32_t IL2C_Tests_ClassTypeTest_Test5(void);
extern int32_t IL2C_Tests_ClassTypeTest_Test6(void);
extern int32_t IL2C_Tests_ClassTypeTest_Test7(void);
extern void IL2C_Tests_ClassTypeTest__ctor(IL2C_Tests_ClassTypeTest* this__);
#define IL2C_Tests_ClassTypeTest_ToString(/* IL2C_Tests_ClassTypeTest* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_ClassTypeTest_GetHashCode(/* IL2C_Tests_ClassTypeTest* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_ClassTypeTest_Finalize(/* IL2C_Tests_ClassTypeTest* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_ClassTypeTest_Equals(/* IL2C_Tests_ClassTypeTest* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// IL2C.Tests.Hoge1
extern /* internalcall */ void __IL2C_Tests_Hoge1_IL2C_MarkHandler__(IL2C_Tests_Hoge1* this__);
extern /* internalcall */ void* __IL2C_Tests_Hoge1_IL2C_RuntimeCast__(IL2C_Tests_Hoge1* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_Hoge1_Add1(int32_t a, bool isTwo);
extern int64_t IL2C_Tests_Hoge1_Add2(int64_t a, bool isTwo);
extern void IL2C_Tests_Hoge1__ctor(IL2C_Tests_Hoge1* this__);
#define IL2C_Tests_Hoge1_ToString(/* IL2C_Tests_Hoge1* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_Hoge1_GetHashCode(/* IL2C_Tests_Hoge1* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_Hoge1_Finalize(/* IL2C_Tests_Hoge1* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_Hoge1_Equals(/* IL2C_Tests_Hoge1* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// IL2C.Tests.Hoge2
extern /* internalcall */ void __IL2C_Tests_Hoge2_IL2C_MarkHandler__(IL2C_Tests_Hoge2* this__);
extern /* internalcall */ void* __IL2C_Tests_Hoge2_IL2C_RuntimeCast__(IL2C_Tests_Hoge2* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern uint8_t IL2C_Tests_Hoge2_Add3(uint8_t a, bool isTwo);
extern uint16_t IL2C_Tests_Hoge2_Add4(uint16_t a, bool isTwo);
extern void IL2C_Tests_Hoge2__ctor(IL2C_Tests_Hoge2* this__);
#define IL2C_Tests_Hoge2_ToString(/* IL2C_Tests_Hoge2* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_Hoge2_GetHashCode(/* IL2C_Tests_Hoge2* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_Hoge2_Finalize(/* IL2C_Tests_Hoge2* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_Hoge2_Equals(/* IL2C_Tests_Hoge2* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// IL2C.Tests.InheritTestTargetBase1
extern /* internalcall */ void __IL2C_Tests_InheritTestTargetBase1_IL2C_MarkHandler__(IL2C_Tests_InheritTestTargetBase1* this__);
extern /* internalcall */ void* __IL2C_Tests_InheritTestTargetBase1_IL2C_RuntimeCast__(IL2C_Tests_InheritTestTargetBase1* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_InheritTestTargetBase1__ctor(IL2C_Tests_InheritTestTargetBase1* this__);
extern void IL2C_Tests_InheritTestTargetBase1__ctor_1(IL2C_Tests_InheritTestTargetBase1* this__, int32_t value);
extern int32_t IL2C_Tests_InheritTestTargetBase1_Calc(IL2C_Tests_InheritTestTargetBase1* this__, int32_t a);
extern /* virtual */ int32_t __IL2C_Tests_InheritTestTargetBase1_Calc_1__(IL2C_Tests_InheritTestTargetBase1* this__, int32_t a, int32_t b);
#define IL2C_Tests_InheritTestTargetBase1_ToString(/* IL2C_Tests_InheritTestTargetBase1* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_InheritTestTargetBase1_GetHashCode(/* IL2C_Tests_InheritTestTargetBase1* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_InheritTestTargetBase1_Finalize(/* IL2C_Tests_InheritTestTargetBase1* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_InheritTestTargetBase1_Equals(/* IL2C_Tests_InheritTestTargetBase1* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define IL2C_Tests_InheritTestTargetBase1_Calc_1(/* IL2C_Tests_InheritTestTargetBase1* */ this__, /* int32_t */ a, /* int32_t */ b) \
    ((this__)->vptr0__->Calc_1(this__, a, b))

// IL2C.Tests.InheritTestTarget2
extern /* internalcall */ void __IL2C_Tests_InheritTestTarget2_IL2C_MarkHandler__(IL2C_Tests_InheritTestTarget2* this__);
extern /* internalcall */ void* __IL2C_Tests_InheritTestTarget2_IL2C_RuntimeCast__(IL2C_Tests_InheritTestTarget2* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_InheritTestTarget2__ctor(IL2C_Tests_InheritTestTarget2* this__);
extern void IL2C_Tests_InheritTestTarget2__ctor_1(IL2C_Tests_InheritTestTarget2* this__, int32_t value);
extern int32_t IL2C_Tests_InheritTestTarget2_Calc(IL2C_Tests_InheritTestTarget2* this__, int32_t a);
extern /* virtual */ int32_t __IL2C_Tests_InheritTestTarget2_Calc_1__(IL2C_Tests_InheritTestTarget2* this__, int32_t a, int32_t b);
#define IL2C_Tests_InheritTestTarget2_ToString(/* IL2C_Tests_InheritTestTarget2* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_InheritTestTarget2_GetHashCode(/* IL2C_Tests_InheritTestTarget2* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_InheritTestTarget2_Finalize(/* IL2C_Tests_InheritTestTarget2* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_InheritTestTarget2_Equals(/* IL2C_Tests_InheritTestTarget2* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define IL2C_Tests_InheritTestTarget2_Calc_1(/* IL2C_Tests_InheritTestTarget2* */ this__, /* int32_t */ a, /* int32_t */ b) \
    ((this__)->vptr0__->Calc_1(this__, a, b))

// IL2C.Tests.InheritTypeTest
extern /* internalcall */ void __IL2C_Tests_InheritTypeTest_IL2C_MarkHandler__(IL2C_Tests_InheritTypeTest* this__);
extern /* internalcall */ void* __IL2C_Tests_InheritTypeTest_IL2C_RuntimeCast__(IL2C_Tests_InheritTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_InheritTypeTest_Test1(void);
extern int32_t IL2C_Tests_InheritTypeTest_Test2(void);
extern int32_t IL2C_Tests_InheritTypeTest_Test3(void);
extern int32_t IL2C_Tests_InheritTypeTest_Test4(void);
extern int32_t IL2C_Tests_InheritTypeTest_Test5(void);
extern void IL2C_Tests_InheritTypeTest__ctor(IL2C_Tests_InheritTypeTest* this__);
#define IL2C_Tests_InheritTypeTest_ToString(/* IL2C_Tests_InheritTypeTest* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_InheritTypeTest_GetHashCode(/* IL2C_Tests_InheritTypeTest* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_InheritTypeTest_Finalize(/* IL2C_Tests_InheritTypeTest* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_InheritTypeTest_Equals(/* IL2C_Tests_InheritTypeTest* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// IL2C.Tests.IInterfaceTestTarget
extern /* internalcall */ void* __IL2C_Tests_IInterfaceTestTarget_IL2C_RuntimeCast__(IL2C_Tests_IInterfaceTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern /* virtual */ int32_t IL2C_Tests_IInterfaceTestTarget_Calc(IL2C_Tests_IInterfaceTestTarget* this__, int32_t a, int32_t b);
#define IL2C_Tests_IInterfaceTestTarget_ToString(/* IL2C_Tests_IInterfaceTestTarget* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_IInterfaceTestTarget_GetHashCode(/* IL2C_Tests_IInterfaceTestTarget* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_IInterfaceTestTarget_Finalize(/* IL2C_Tests_IInterfaceTestTarget* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_IInterfaceTestTarget_Equals(/* IL2C_Tests_IInterfaceTestTarget* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define IL2C_Tests_IInterfaceTestTarget_Calc(/* IL2C_Tests_IInterfaceTestTarget* */ this__, /* int32_t */ a, /* int32_t */ b) \
    ((this__)->vptr0__->Calc(this__, a, b))

// IL2C.Tests.IInterfaceTestTarget2
extern /* internalcall */ void* __IL2C_Tests_IInterfaceTestTarget2_IL2C_RuntimeCast__(IL2C_Tests_IInterfaceTestTarget2* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern /* virtual */ int32_t IL2C_Tests_IInterfaceTestTarget2_Calc2(IL2C_Tests_IInterfaceTestTarget2* this__, int32_t a, int32_t b);
#define IL2C_Tests_IInterfaceTestTarget2_ToString(/* IL2C_Tests_IInterfaceTestTarget2* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_IInterfaceTestTarget2_GetHashCode(/* IL2C_Tests_IInterfaceTestTarget2* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_IInterfaceTestTarget2_Finalize(/* IL2C_Tests_IInterfaceTestTarget2* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_IInterfaceTestTarget2_Equals(/* IL2C_Tests_IInterfaceTestTarget2* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define IL2C_Tests_IInterfaceTestTarget2_Calc2(/* IL2C_Tests_IInterfaceTestTarget2* */ this__, /* int32_t */ a, /* int32_t */ b) \
    ((this__)->vptr0__->Calc2(this__, a, b))

// IL2C.Tests.InterfaceTestTargetClass
extern /* internalcall */ void __IL2C_Tests_InterfaceTestTargetClass_IL2C_MarkHandler__(IL2C_Tests_InterfaceTestTargetClass* this__);
extern /* internalcall */ void* __IL2C_Tests_InterfaceTestTargetClass_IL2C_RuntimeCast__(IL2C_Tests_InterfaceTestTargetClass* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_InterfaceTestTargetClass__ctor(IL2C_Tests_InterfaceTestTargetClass* this__);
extern /* virtual */ int32_t __IL2C_Tests_InterfaceTestTargetClass_Calc__(IL2C_Tests_InterfaceTestTargetClass* this__, int32_t a, int32_t b);
extern /* virtual */ int32_t __IL2C_Tests_InterfaceTestTargetClass_Calc2__(IL2C_Tests_InterfaceTestTargetClass* this__, int32_t a, int32_t b);
#define IL2C_Tests_InterfaceTestTargetClass_ToString(/* IL2C_Tests_InterfaceTestTargetClass* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_InterfaceTestTargetClass_GetHashCode(/* IL2C_Tests_InterfaceTestTargetClass* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_InterfaceTestTargetClass_Finalize(/* IL2C_Tests_InterfaceTestTargetClass* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_InterfaceTestTargetClass_Equals(/* IL2C_Tests_InterfaceTestTargetClass* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define IL2C_Tests_InterfaceTestTargetClass_Calc(/* IL2C_Tests_InterfaceTestTargetClass* */ this__, /* int32_t */ a, /* int32_t */ b) \
    ((this__)->vptr0__->Calc(this__, a, b))
#define IL2C_Tests_InterfaceTestTargetClass_Calc2(/* IL2C_Tests_InterfaceTestTargetClass* */ this__, /* int32_t */ a, /* int32_t */ b) \
    ((this__)->vptr0__->Calc2(this__, a, b))

// IL2C.Tests.InterfaceTypeTest
extern /* internalcall */ void __IL2C_Tests_InterfaceTypeTest_IL2C_MarkHandler__(IL2C_Tests_InterfaceTypeTest* this__);
extern /* internalcall */ void* __IL2C_Tests_InterfaceTypeTest_IL2C_RuntimeCast__(IL2C_Tests_InterfaceTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_InterfaceTypeTest_Test1(void);
extern int32_t IL2C_Tests_InterfaceTypeTest_Test2(void);
extern int32_t IL2C_Tests_InterfaceTypeTest_Test3(void);
extern void IL2C_Tests_InterfaceTypeTest__ctor(IL2C_Tests_InterfaceTypeTest* this__);
#define IL2C_Tests_InterfaceTypeTest_ToString(/* IL2C_Tests_InterfaceTypeTest* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_InterfaceTypeTest_GetHashCode(/* IL2C_Tests_InterfaceTypeTest* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_InterfaceTypeTest_Finalize(/* IL2C_Tests_InterfaceTypeTest* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_InterfaceTypeTest_Equals(/* IL2C_Tests_InterfaceTypeTest* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// IL2C.Tests.Win32
extern /* internalcall */ void __IL2C_Tests_Win32_IL2C_MarkHandler__(IL2C_Tests_Win32* this__);
extern /* internalcall */ void* __IL2C_Tests_Win32_IL2C_RuntimeCast__(IL2C_Tests_Win32* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_Win32_GetCurrentProcessId(void);
extern int32_t IL2C_Tests_Win32_GetCurrentThreadId(void);
extern void IL2C_Tests_Win32_OutputDebugString(System_String* message);
extern void IL2C_Tests_Win32__ctor(IL2C_Tests_Win32* this__);
#define IL2C_Tests_Win32_ToString(/* IL2C_Tests_Win32* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_Win32_GetHashCode(/* IL2C_Tests_Win32* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_Win32_Finalize(/* IL2C_Tests_Win32* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_Win32_Equals(/* IL2C_Tests_Win32* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// IL2C.Tests.StringTest
extern /* internalcall */ void __IL2C_Tests_StringTest_IL2C_MarkHandler__(IL2C_Tests_StringTest* this__);
extern /* internalcall */ void* __IL2C_Tests_StringTest_IL2C_RuntimeCast__(IL2C_Tests_StringTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_StringTest_LiteralString(void);
extern System_String* IL2C_Tests_StringTest_InOutString(System_String* a);
extern System_String* IL2C_Tests_StringTest_LiteralCombinedString(void);
extern System_String* IL2C_Tests_StringTest_LiteralSubstring(void);
extern wchar_t IL2C_Tests_StringTest_GetChar(void);
extern wchar_t IL2C_Tests_StringTest_GetCharByIndex(System_String* str, int32_t index);
extern System_String* IL2C_Tests_StringTest_GetString(void);
extern void IL2C_Tests_StringTest__ctor(IL2C_Tests_StringTest* this__);
#define IL2C_Tests_StringTest_ToString(/* IL2C_Tests_StringTest* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_StringTest_GetHashCode(/* IL2C_Tests_StringTest* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_StringTest_Finalize(/* IL2C_Tests_StringTest* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_StringTest_Equals(/* IL2C_Tests_StringTest* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// IL2C.Tests.UnsafeTest
extern /* internalcall */ void __IL2C_Tests_UnsafeTest_IL2C_MarkHandler__(IL2C_Tests_UnsafeTest* this__);
extern /* internalcall */ void* __IL2C_Tests_UnsafeTest_IL2C_RuntimeCast__(IL2C_Tests_UnsafeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_UnsafeTest__ctor(IL2C_Tests_UnsafeTest* this__);
#define IL2C_Tests_UnsafeTest_ToString(/* IL2C_Tests_UnsafeTest* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_UnsafeTest_GetHashCode(/* IL2C_Tests_UnsafeTest* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_UnsafeTest_Finalize(/* IL2C_Tests_UnsafeTest* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_UnsafeTest_Equals(/* IL2C_Tests_UnsafeTest* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// IL2C.Tests.ValueTypeTestTarget
extern /* internalcall */ void __IL2C_Tests_ValueTypeTestTarget_IL2C_MarkHandler__(IL2C_Tests_ValueTypeTestTarget* this__);
extern /* internalcall */ void* __IL2C_Tests_ValueTypeTestTarget_IL2C_RuntimeCast__(IL2C_Tests_ValueTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_ValueTypeTestTarget_GetValue2(IL2C_Tests_ValueTypeTestTarget* this__, int32_t a, int32_t b);
#define IL2C_Tests_ValueTypeTestTarget_ToString(/* IL2C_Tests_ValueTypeTestTarget */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_ValueTypeTestTarget_GetHashCode(/* IL2C_Tests_ValueTypeTestTarget */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_ValueTypeTestTarget_Finalize(/* IL2C_Tests_ValueTypeTestTarget */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_ValueTypeTestTarget_Equals(/* IL2C_Tests_ValueTypeTestTarget */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// IL2C.Tests.ValueTypeTest
extern /* internalcall */ void __IL2C_Tests_ValueTypeTest_IL2C_MarkHandler__(IL2C_Tests_ValueTypeTest* this__);
extern /* internalcall */ void* __IL2C_Tests_ValueTypeTest_IL2C_RuntimeCast__(IL2C_Tests_ValueTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_ValueTypeTest_Test4(void);
extern int32_t IL2C_Tests_ValueTypeTest_Test5(void);
extern void IL2C_Tests_ValueTypeTest__ctor(IL2C_Tests_ValueTypeTest* this__);
#define IL2C_Tests_ValueTypeTest_ToString(/* IL2C_Tests_ValueTypeTest* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_ValueTypeTest_GetHashCode(/* IL2C_Tests_ValueTypeTest* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_ValueTypeTest_Finalize(/* IL2C_Tests_ValueTypeTest* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_ValueTypeTest_Equals(/* IL2C_Tests_ValueTypeTest* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

#ifdef __cplusplus
}
#endif

#endif
