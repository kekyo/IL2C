#ifndef __IL2C_Tests_Code_H__
#define __IL2C_Tests_Code_H__

#include <il2c.h>

#include <il2c.h>
#include <IL2C.Tests.Code.h>
#include <mscorlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:

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
// [1] IL2C.Tests.BoxingTest

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_BoxingTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __IL2C_Tests_BoxingTest_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_BoxingTest
{
    __IL2C_Tests_BoxingTest_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_BoxingTest_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_BoxingTest_VTABLE_DECL__ __IL2C_Tests_BoxingTest_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.ClassTypeTestTarget

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_ClassTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __IL2C_Tests_ClassTypeTestTarget_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_ClassTypeTestTarget
{
    __IL2C_Tests_ClassTypeTestTarget_VTABLE_DECL__* vptr0__;
    int32_t Value2;
    IL2C_Tests_ClassTypeTestTarget* OR2;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_ClassTypeTestTarget_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_ClassTypeTestTarget_VTABLE_DECL__ __IL2C_Tests_ClassTypeTestTarget_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.ClassTypeTest

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_ClassTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __IL2C_Tests_ClassTypeTest_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_ClassTypeTest
{
    __IL2C_Tests_ClassTypeTest_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_ClassTypeTest_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_ClassTypeTest_VTABLE_DECL__ __IL2C_Tests_ClassTypeTest_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.Hoge1

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_Hoge1* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __IL2C_Tests_Hoge1_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_Hoge1
{
    __IL2C_Tests_Hoge1_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_Hoge1_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_Hoge1_VTABLE_DECL__ __IL2C_Tests_Hoge1_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.Hoge2

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_Hoge2* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __IL2C_Tests_Hoge2_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_Hoge2
{
    __IL2C_Tests_Hoge2_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_Hoge2_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_Hoge2_VTABLE_DECL__ __IL2C_Tests_Hoge2_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.InheritTestTargetBase1

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_InheritTestTargetBase1* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Calc)(IL2C_Tests_InheritTestTargetBase1* this__, int32_t a, int32_t b);
} __IL2C_Tests_InheritTestTargetBase1_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_InheritTestTargetBase1
{
    __IL2C_Tests_InheritTestTargetBase1_VTABLE_DECL__* vptr0__;
    int32_t Value2;
    IL2C_Tests_ClassTypeTestTarget* OR2;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InheritTestTargetBase1_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_InheritTestTargetBase1_VTABLE_DECL__ __IL2C_Tests_InheritTestTargetBase1_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.InheritTestTarget2

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_InheritTestTarget2* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Calc)(IL2C_Tests_InheritTestTargetBase1* this__, int32_t a, int32_t b);
    int32_t (*Calc)(IL2C_Tests_InheritTestTarget2* this__, int32_t a, int32_t b);
} __IL2C_Tests_InheritTestTarget2_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_InheritTestTarget2
{
    __IL2C_Tests_InheritTestTarget2_VTABLE_DECL__* vptr0__;
    int32_t Value2;
    IL2C_Tests_ClassTypeTestTarget* OR2;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InheritTestTarget2_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_InheritTestTarget2_VTABLE_DECL__ __IL2C_Tests_InheritTestTarget2_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.InheritTypeTest

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_InheritTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __IL2C_Tests_InheritTypeTest_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_InheritTypeTest
{
    __IL2C_Tests_InheritTypeTest_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InheritTypeTest_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_InheritTypeTest_VTABLE_DECL__ __IL2C_Tests_InheritTypeTest_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.IInterfaceTestTarget

// [1-2] Interface vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_IInterfaceTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Calc)(IL2C_Tests_IInterfaceTestTarget* this__, int32_t a, int32_t b);
} __IL2C_Tests_IInterfaceTestTarget_VTABLE_DECL__;

// [1-3] Interface layout
struct IL2C_Tests_IInterfaceTestTarget
{
    __IL2C_Tests_IInterfaceTestTarget_VTABLE_DECL__* vptr0__;
};

// [1-4] Interface runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_IInterfaceTestTarget_RUNTIME_TYPE__;

// [1-5] Interface vtable
extern __IL2C_Tests_IInterfaceTestTarget_VTABLE_DECL__ __IL2C_Tests_IInterfaceTestTarget_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.IInterfaceTestTarget2

// [1-2] Interface vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_IInterfaceTestTarget2* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Calc2)(IL2C_Tests_IInterfaceTestTarget2* this__, int32_t a, int32_t b);
} __IL2C_Tests_IInterfaceTestTarget2_VTABLE_DECL__;

// [1-3] Interface layout
struct IL2C_Tests_IInterfaceTestTarget2
{
    __IL2C_Tests_IInterfaceTestTarget2_VTABLE_DECL__* vptr0__;
};

// [1-4] Interface runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_IInterfaceTestTarget2_RUNTIME_TYPE__;

// [1-5] Interface vtable
extern __IL2C_Tests_IInterfaceTestTarget2_VTABLE_DECL__ __IL2C_Tests_IInterfaceTestTarget2_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.InterfaceTestTargetClass

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_InterfaceTestTargetClass* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Calc)(IL2C_Tests_InterfaceTestTargetClass* this__, int32_t a, int32_t b);
    int32_t (*Calc2)(IL2C_Tests_InterfaceTestTargetClass* this__, int32_t a, int32_t b);
} __IL2C_Tests_InterfaceTestTargetClass_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_InterfaceTestTargetClass
{
    __IL2C_Tests_InterfaceTestTargetClass_VTABLE_DECL__* vptr0__;
    __IL2C_Tests_IInterfaceTestTarget_VTABLE_DECL__* vptr_IL2C_Tests_IInterfaceTestTarget__;
    __IL2C_Tests_IInterfaceTestTarget2_VTABLE_DECL__* vptr_IL2C_Tests_IInterfaceTestTarget2__;
    int32_t Value2;
    IL2C_Tests_ClassTypeTestTarget* OR2;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InterfaceTestTargetClass_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_InterfaceTestTargetClass_VTABLE_DECL__ __IL2C_Tests_InterfaceTestTargetClass_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.InterfaceTypeTest

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_InterfaceTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __IL2C_Tests_InterfaceTypeTest_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_InterfaceTypeTest
{
    __IL2C_Tests_InterfaceTypeTest_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_InterfaceTypeTest_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_InterfaceTypeTest_VTABLE_DECL__ __IL2C_Tests_InterfaceTypeTest_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.Win32

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_Win32* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __IL2C_Tests_Win32_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_Win32
{
    __IL2C_Tests_Win32_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_Win32_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_Win32_VTABLE_DECL__ __IL2C_Tests_Win32_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.StringTest

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_StringTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __IL2C_Tests_StringTest_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_StringTest
{
    __IL2C_Tests_StringTest_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_StringTest_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_StringTest_VTABLE_DECL__ __IL2C_Tests_StringTest_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.UnsafeTest

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_UnsafeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __IL2C_Tests_UnsafeTest_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_UnsafeTest
{
    __IL2C_Tests_UnsafeTest_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_UnsafeTest_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_UnsafeTest_VTABLE_DECL__ __IL2C_Tests_UnsafeTest_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.ValueTypeTestTarget

// [1-2] Struct vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_ValueTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*GetHashCode)(System_ValueType* this__);
    System_String* (*ToString)(System_ValueType* this__);
    bool (*Equals)(System_ValueType* this__, System_Object* obj);
} __IL2C_Tests_ValueTypeTestTarget_VTABLE_DECL__;

// [1-3] Struct layout
struct IL2C_Tests_ValueTypeTestTarget
{
    __IL2C_Tests_ValueTypeTestTarget_VTABLE_DECL__* vptr0__;
    int32_t Value2;
    IL2C_Tests_ClassTypeTestTarget* OR2;
};

// [1-4] Struct runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_ValueTypeTestTarget_RUNTIME_TYPE__;

// [1-5] Struct vtable
extern __IL2C_Tests_ValueTypeTestTarget_VTABLE_DECL__ __IL2C_Tests_ValueTypeTestTarget_VTABLE__;

////////////////////////////////////////////////////////////
// [1] IL2C.Tests.ValueTypeTest

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(IL2C_Tests_ValueTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __IL2C_Tests_ValueTypeTest_VTABLE_DECL__;

// [1-3] Class layout
struct IL2C_Tests_ValueTypeTest
{
    __IL2C_Tests_ValueTypeTest_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __IL2C_Tests_ValueTypeTest_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __IL2C_Tests_ValueTypeTest_VTABLE_DECL__ __IL2C_Tests_ValueTypeTest_VTABLE__;

//////////////////////////////////////////////////////////////////////////////////
// [2-2] Public static fields:


extern int32_t IL2C_Tests_ClassTypeTestTarget_Value1;
extern IL2C_Tests_ClassTypeTestTarget* IL2C_Tests_ClassTypeTestTarget_OR1;














extern int32_t IL2C_Tests_ValueTypeTestTarget_Value1;


//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: IL2C.Tests.BoxingTest

extern /* internalcall */ void __IL2C_Tests_BoxingTest_IL2C_MarkHandler__(IL2C_Tests_BoxingTest* this__);
extern /* internalcall */ void* __IL2C_Tests_BoxingTest_IL2C_RuntimeCast__(IL2C_Tests_BoxingTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_BoxingTest_BoxingInt32(int32_t a);
extern void IL2C_Tests_BoxingTest__ctor(IL2C_Tests_BoxingTest* this__);

// [2-5] Virtual methods: IL2C.Tests.BoxingTest

#define IL2C_Tests_BoxingTest_ToString(/* IL2C_Tests_BoxingTest */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_BoxingTest_GetHashCode(/* IL2C_Tests_BoxingTest */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_BoxingTest_Finalize(/* IL2C_Tests_BoxingTest */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_BoxingTest_Equals(/* IL2C_Tests_BoxingTest */ this__, /* IL2C_Tests_BoxingTest */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: IL2C.Tests.ClassTypeTestTarget

extern /* internalcall */ void __IL2C_Tests_ClassTypeTestTarget_IL2C_MarkHandler__(IL2C_Tests_ClassTypeTestTarget* this__);
extern /* internalcall */ void* __IL2C_Tests_ClassTypeTestTarget_IL2C_RuntimeCast__(IL2C_Tests_ClassTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_ClassTypeTestTarget__ctor(IL2C_Tests_ClassTypeTestTarget* this__);
extern void IL2C_Tests_ClassTypeTestTarget__ctor_1(IL2C_Tests_ClassTypeTestTarget* this__, int32_t value);
extern int32_t IL2C_Tests_ClassTypeTestTarget_GetValue2(IL2C_Tests_ClassTypeTestTarget* this__, int32_t a, int32_t b);
extern int32_t IL2C_Tests_ClassTypeTestTarget_GetValue2_1(IL2C_Tests_ClassTypeTestTarget* this__, int32_t a, int32_t b, int32_t c);

// [2-5] Virtual methods: IL2C.Tests.ClassTypeTestTarget

#define IL2C_Tests_ClassTypeTestTarget_ToString(/* IL2C_Tests_ClassTypeTestTarget */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_ClassTypeTestTarget_GetHashCode(/* IL2C_Tests_ClassTypeTestTarget */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_ClassTypeTestTarget_Finalize(/* IL2C_Tests_ClassTypeTestTarget */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_ClassTypeTestTarget_Equals(/* IL2C_Tests_ClassTypeTestTarget */ this__, /* IL2C_Tests_ClassTypeTestTarget */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: IL2C.Tests.ClassTypeTest

extern /* internalcall */ void __IL2C_Tests_ClassTypeTest_IL2C_MarkHandler__(IL2C_Tests_ClassTypeTest* this__);
extern /* internalcall */ void* __IL2C_Tests_ClassTypeTest_IL2C_RuntimeCast__(IL2C_Tests_ClassTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_ClassTypeTest_Test4();
extern int32_t IL2C_Tests_ClassTypeTest_Test5();
extern int32_t IL2C_Tests_ClassTypeTest_Test6();
extern int32_t IL2C_Tests_ClassTypeTest_Test7();
extern void IL2C_Tests_ClassTypeTest__ctor(IL2C_Tests_ClassTypeTest* this__);

// [2-5] Virtual methods: IL2C.Tests.ClassTypeTest

#define IL2C_Tests_ClassTypeTest_ToString(/* IL2C_Tests_ClassTypeTest */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_ClassTypeTest_GetHashCode(/* IL2C_Tests_ClassTypeTest */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_ClassTypeTest_Finalize(/* IL2C_Tests_ClassTypeTest */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_ClassTypeTest_Equals(/* IL2C_Tests_ClassTypeTest */ this__, /* IL2C_Tests_ClassTypeTest */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: IL2C.Tests.Hoge1

extern /* internalcall */ void __IL2C_Tests_Hoge1_IL2C_MarkHandler__(IL2C_Tests_Hoge1* this__);
extern /* internalcall */ void* __IL2C_Tests_Hoge1_IL2C_RuntimeCast__(IL2C_Tests_Hoge1* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_Hoge1_Add1(int32_t a, bool isTwo);
extern int64_t IL2C_Tests_Hoge1_Add2(int64_t a, bool isTwo);
extern void IL2C_Tests_Hoge1__ctor(IL2C_Tests_Hoge1* this__);

// [2-5] Virtual methods: IL2C.Tests.Hoge1

#define IL2C_Tests_Hoge1_ToString(/* IL2C_Tests_Hoge1 */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_Hoge1_GetHashCode(/* IL2C_Tests_Hoge1 */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_Hoge1_Finalize(/* IL2C_Tests_Hoge1 */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_Hoge1_Equals(/* IL2C_Tests_Hoge1 */ this__, /* IL2C_Tests_Hoge1 */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: IL2C.Tests.Hoge2

extern /* internalcall */ void __IL2C_Tests_Hoge2_IL2C_MarkHandler__(IL2C_Tests_Hoge2* this__);
extern /* internalcall */ void* __IL2C_Tests_Hoge2_IL2C_RuntimeCast__(IL2C_Tests_Hoge2* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern uint8_t IL2C_Tests_Hoge2_Add3(uint8_t a, bool isTwo);
extern uint16_t IL2C_Tests_Hoge2_Add4(uint16_t a, bool isTwo);
extern void IL2C_Tests_Hoge2__ctor(IL2C_Tests_Hoge2* this__);

// [2-5] Virtual methods: IL2C.Tests.Hoge2

#define IL2C_Tests_Hoge2_ToString(/* IL2C_Tests_Hoge2 */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_Hoge2_GetHashCode(/* IL2C_Tests_Hoge2 */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_Hoge2_Finalize(/* IL2C_Tests_Hoge2 */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_Hoge2_Equals(/* IL2C_Tests_Hoge2 */ this__, /* IL2C_Tests_Hoge2 */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: IL2C.Tests.InheritTestTargetBase1

extern /* internalcall */ void __IL2C_Tests_InheritTestTargetBase1_IL2C_MarkHandler__(IL2C_Tests_InheritTestTargetBase1* this__);
extern /* internalcall */ void* __IL2C_Tests_InheritTestTargetBase1_IL2C_RuntimeCast__(IL2C_Tests_InheritTestTargetBase1* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_InheritTestTargetBase1__ctor(IL2C_Tests_InheritTestTargetBase1* this__);
extern void IL2C_Tests_InheritTestTargetBase1__ctor_1(IL2C_Tests_InheritTestTargetBase1* this__, int32_t value);
extern int32_t IL2C_Tests_InheritTestTargetBase1_Calc(IL2C_Tests_InheritTestTargetBase1* this__, int32_t a);
extern /* virtual */ int32_t __IL2C_Tests_InheritTestTargetBase1_Calc_1__(IL2C_Tests_InheritTestTargetBase1* this__, int32_t a, int32_t b);

// [2-5] Virtual methods: IL2C.Tests.InheritTestTargetBase1

#define IL2C_Tests_InheritTestTargetBase1_ToString(/* IL2C_Tests_InheritTestTargetBase1 */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_InheritTestTargetBase1_GetHashCode(/* IL2C_Tests_InheritTestTargetBase1 */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_InheritTestTargetBase1_Finalize(/* IL2C_Tests_InheritTestTargetBase1 */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_InheritTestTargetBase1_Equals(/* IL2C_Tests_InheritTestTargetBase1 */ this__, /* IL2C_Tests_InheritTestTargetBase1 */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define IL2C_Tests_InheritTestTargetBase1_Calc_1(/* IL2C_Tests_InheritTestTargetBase1 */ this__, /* IL2C_Tests_InheritTestTargetBase1 */ a, /* IL2C_Tests_InheritTestTargetBase1 */ b) \
    ((this__)->vptr0__->Calc_1(this__, a, b))

// [2-4] Member methods: IL2C.Tests.InheritTestTarget2

extern /* internalcall */ void __IL2C_Tests_InheritTestTarget2_IL2C_MarkHandler__(IL2C_Tests_InheritTestTarget2* this__);
extern /* internalcall */ void* __IL2C_Tests_InheritTestTarget2_IL2C_RuntimeCast__(IL2C_Tests_InheritTestTarget2* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_InheritTestTarget2__ctor(IL2C_Tests_InheritTestTarget2* this__);
extern void IL2C_Tests_InheritTestTarget2__ctor_1(IL2C_Tests_InheritTestTarget2* this__, int32_t value);
extern int32_t IL2C_Tests_InheritTestTarget2_Calc(IL2C_Tests_InheritTestTarget2* this__, int32_t a);
extern /* virtual */ int32_t __IL2C_Tests_InheritTestTarget2_Calc_1__(IL2C_Tests_InheritTestTarget2* this__, int32_t a, int32_t b);

// [2-5] Virtual methods: IL2C.Tests.InheritTestTarget2

#define IL2C_Tests_InheritTestTarget2_ToString(/* IL2C_Tests_InheritTestTarget2 */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_InheritTestTarget2_GetHashCode(/* IL2C_Tests_InheritTestTarget2 */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_InheritTestTarget2_Finalize(/* IL2C_Tests_InheritTestTarget2 */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_InheritTestTarget2_Equals(/* IL2C_Tests_InheritTestTarget2 */ this__, /* IL2C_Tests_InheritTestTarget2 */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define IL2C_Tests_InheritTestTarget2_Calc_1(/* IL2C_Tests_InheritTestTarget2 */ this__, /* IL2C_Tests_InheritTestTarget2 */ a, /* IL2C_Tests_InheritTestTarget2 */ b) \
    ((this__)->vptr0__->Calc_1(this__, a, b))
#define IL2C_Tests_InheritTestTarget2_Calc_1(/* IL2C_Tests_InheritTestTarget2 */ this__, /* IL2C_Tests_InheritTestTarget2 */ a, /* IL2C_Tests_InheritTestTarget2 */ b) \
    ((this__)->vptr0__->Calc_1(this__, a, b))

// [2-4] Member methods: IL2C.Tests.InheritTypeTest

extern /* internalcall */ void __IL2C_Tests_InheritTypeTest_IL2C_MarkHandler__(IL2C_Tests_InheritTypeTest* this__);
extern /* internalcall */ void* __IL2C_Tests_InheritTypeTest_IL2C_RuntimeCast__(IL2C_Tests_InheritTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_InheritTypeTest_Test1();
extern int32_t IL2C_Tests_InheritTypeTest_Test2();
extern int32_t IL2C_Tests_InheritTypeTest_Test3();
extern int32_t IL2C_Tests_InheritTypeTest_Test4();
extern int32_t IL2C_Tests_InheritTypeTest_Test5();
extern void IL2C_Tests_InheritTypeTest__ctor(IL2C_Tests_InheritTypeTest* this__);

// [2-5] Virtual methods: IL2C.Tests.InheritTypeTest

#define IL2C_Tests_InheritTypeTest_ToString(/* IL2C_Tests_InheritTypeTest */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_InheritTypeTest_GetHashCode(/* IL2C_Tests_InheritTypeTest */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_InheritTypeTest_Finalize(/* IL2C_Tests_InheritTypeTest */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_InheritTypeTest_Equals(/* IL2C_Tests_InheritTypeTest */ this__, /* IL2C_Tests_InheritTypeTest */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: IL2C.Tests.IInterfaceTestTarget

extern /* internalcall */ void* __IL2C_Tests_IInterfaceTestTarget_IL2C_RuntimeCast__(IL2C_Tests_IInterfaceTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern /* virtual */ int32_t __IL2C_Tests_IInterfaceTestTarget_Calc__(IL2C_Tests_IInterfaceTestTarget* this__, int32_t a, int32_t b);

// [2-5] Virtual methods: IL2C.Tests.IInterfaceTestTarget

#define IL2C_Tests_IInterfaceTestTarget_ToString(/* IL2C_Tests_IInterfaceTestTarget */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_IInterfaceTestTarget_GetHashCode(/* IL2C_Tests_IInterfaceTestTarget */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_IInterfaceTestTarget_Finalize(/* IL2C_Tests_IInterfaceTestTarget */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_IInterfaceTestTarget_Equals(/* IL2C_Tests_IInterfaceTestTarget */ this__, /* IL2C_Tests_IInterfaceTestTarget */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define IL2C_Tests_IInterfaceTestTarget_Calc(/* IL2C_Tests_IInterfaceTestTarget */ this__, /* IL2C_Tests_IInterfaceTestTarget */ a, /* IL2C_Tests_IInterfaceTestTarget */ b) \
    ((this__)->vptr0__->Calc(this__, a, b))

// [2-4] Member methods: IL2C.Tests.IInterfaceTestTarget2

extern /* internalcall */ void* __IL2C_Tests_IInterfaceTestTarget2_IL2C_RuntimeCast__(IL2C_Tests_IInterfaceTestTarget2* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern /* virtual */ int32_t __IL2C_Tests_IInterfaceTestTarget2_Calc2__(IL2C_Tests_IInterfaceTestTarget2* this__, int32_t a, int32_t b);

// [2-5] Virtual methods: IL2C.Tests.IInterfaceTestTarget2

#define IL2C_Tests_IInterfaceTestTarget2_ToString(/* IL2C_Tests_IInterfaceTestTarget2 */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_IInterfaceTestTarget2_GetHashCode(/* IL2C_Tests_IInterfaceTestTarget2 */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_IInterfaceTestTarget2_Finalize(/* IL2C_Tests_IInterfaceTestTarget2 */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_IInterfaceTestTarget2_Equals(/* IL2C_Tests_IInterfaceTestTarget2 */ this__, /* IL2C_Tests_IInterfaceTestTarget2 */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define IL2C_Tests_IInterfaceTestTarget2_Calc2(/* IL2C_Tests_IInterfaceTestTarget2 */ this__, /* IL2C_Tests_IInterfaceTestTarget2 */ a, /* IL2C_Tests_IInterfaceTestTarget2 */ b) \
    ((this__)->vptr0__->Calc2(this__, a, b))

// [2-4] Member methods: IL2C.Tests.InterfaceTestTargetClass

extern /* internalcall */ void __IL2C_Tests_InterfaceTestTargetClass_IL2C_MarkHandler__(IL2C_Tests_InterfaceTestTargetClass* this__);
extern /* internalcall */ void* __IL2C_Tests_InterfaceTestTargetClass_IL2C_RuntimeCast__(IL2C_Tests_InterfaceTestTargetClass* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_InterfaceTestTargetClass__ctor(IL2C_Tests_InterfaceTestTargetClass* this__);
extern /* virtual */ int32_t __IL2C_Tests_InterfaceTestTargetClass_Calc__(IL2C_Tests_InterfaceTestTargetClass* this__, int32_t a, int32_t b);
extern /* virtual */ int32_t __IL2C_Tests_InterfaceTestTargetClass_Calc2__(IL2C_Tests_InterfaceTestTargetClass* this__, int32_t a, int32_t b);

// [2-5] Virtual methods: IL2C.Tests.InterfaceTestTargetClass

#define IL2C_Tests_InterfaceTestTargetClass_ToString(/* IL2C_Tests_InterfaceTestTargetClass */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_InterfaceTestTargetClass_GetHashCode(/* IL2C_Tests_InterfaceTestTargetClass */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_InterfaceTestTargetClass_Finalize(/* IL2C_Tests_InterfaceTestTargetClass */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_InterfaceTestTargetClass_Equals(/* IL2C_Tests_InterfaceTestTargetClass */ this__, /* IL2C_Tests_InterfaceTestTargetClass */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define IL2C_Tests_InterfaceTestTargetClass_Calc(/* IL2C_Tests_InterfaceTestTargetClass */ this__, /* IL2C_Tests_InterfaceTestTargetClass */ a, /* IL2C_Tests_InterfaceTestTargetClass */ b) \
    ((this__)->vptr0__->Calc(this__, a, b))
#define IL2C_Tests_InterfaceTestTargetClass_Calc2(/* IL2C_Tests_InterfaceTestTargetClass */ this__, /* IL2C_Tests_InterfaceTestTargetClass */ a, /* IL2C_Tests_InterfaceTestTargetClass */ b) \
    ((this__)->vptr0__->Calc2(this__, a, b))

// [2-4] Member methods: IL2C.Tests.InterfaceTypeTest

extern /* internalcall */ void __IL2C_Tests_InterfaceTypeTest_IL2C_MarkHandler__(IL2C_Tests_InterfaceTypeTest* this__);
extern /* internalcall */ void* __IL2C_Tests_InterfaceTypeTest_IL2C_RuntimeCast__(IL2C_Tests_InterfaceTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_InterfaceTypeTest_Test1();
extern int32_t IL2C_Tests_InterfaceTypeTest_Test2();
extern int32_t IL2C_Tests_InterfaceTypeTest_Test3();
extern void IL2C_Tests_InterfaceTypeTest__ctor(IL2C_Tests_InterfaceTypeTest* this__);

// [2-5] Virtual methods: IL2C.Tests.InterfaceTypeTest

#define IL2C_Tests_InterfaceTypeTest_ToString(/* IL2C_Tests_InterfaceTypeTest */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_InterfaceTypeTest_GetHashCode(/* IL2C_Tests_InterfaceTypeTest */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_InterfaceTypeTest_Finalize(/* IL2C_Tests_InterfaceTypeTest */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_InterfaceTypeTest_Equals(/* IL2C_Tests_InterfaceTypeTest */ this__, /* IL2C_Tests_InterfaceTypeTest */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: IL2C.Tests.Win32

extern /* internalcall */ void __IL2C_Tests_Win32_IL2C_MarkHandler__(IL2C_Tests_Win32* this__);
extern /* internalcall */ void* __IL2C_Tests_Win32_IL2C_RuntimeCast__(IL2C_Tests_Win32* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_Win32_GetCurrentProcessId();
extern int32_t IL2C_Tests_Win32_GetCurrentThreadId();
extern void IL2C_Tests_Win32_OutputDebugString(System_String* message);
extern void IL2C_Tests_Win32__ctor(IL2C_Tests_Win32* this__);

// [2-5] Virtual methods: IL2C.Tests.Win32

#define IL2C_Tests_Win32_ToString(/* IL2C_Tests_Win32 */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_Win32_GetHashCode(/* IL2C_Tests_Win32 */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_Win32_Finalize(/* IL2C_Tests_Win32 */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_Win32_Equals(/* IL2C_Tests_Win32 */ this__, /* IL2C_Tests_Win32 */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: IL2C.Tests.StringTest

extern /* internalcall */ void __IL2C_Tests_StringTest_IL2C_MarkHandler__(IL2C_Tests_StringTest* this__);
extern /* internalcall */ void* __IL2C_Tests_StringTest_IL2C_RuntimeCast__(IL2C_Tests_StringTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_StringTest_LiteralString();
extern System_String* IL2C_Tests_StringTest_InOutString(System_String* a);
extern System_String* IL2C_Tests_StringTest_LiteralCombinedString();
extern System_String* IL2C_Tests_StringTest_LiteralSubstring();
extern wchar_t IL2C_Tests_StringTest_GetChar();
extern wchar_t IL2C_Tests_StringTest_GetCharByIndex(System_String* str, int32_t index);
extern System_String* IL2C_Tests_StringTest_GetString();
extern void IL2C_Tests_StringTest__ctor(IL2C_Tests_StringTest* this__);

// [2-5] Virtual methods: IL2C.Tests.StringTest

#define IL2C_Tests_StringTest_ToString(/* IL2C_Tests_StringTest */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_StringTest_GetHashCode(/* IL2C_Tests_StringTest */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_StringTest_Finalize(/* IL2C_Tests_StringTest */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_StringTest_Equals(/* IL2C_Tests_StringTest */ this__, /* IL2C_Tests_StringTest */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: IL2C.Tests.UnsafeTest

extern /* internalcall */ void __IL2C_Tests_UnsafeTest_IL2C_MarkHandler__(IL2C_Tests_UnsafeTest* this__);
extern /* internalcall */ void* __IL2C_Tests_UnsafeTest_IL2C_RuntimeCast__(IL2C_Tests_UnsafeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void IL2C_Tests_UnsafeTest__ctor(IL2C_Tests_UnsafeTest* this__);

// [2-5] Virtual methods: IL2C.Tests.UnsafeTest

#define IL2C_Tests_UnsafeTest_ToString(/* IL2C_Tests_UnsafeTest */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_UnsafeTest_GetHashCode(/* IL2C_Tests_UnsafeTest */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_UnsafeTest_Finalize(/* IL2C_Tests_UnsafeTest */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_UnsafeTest_Equals(/* IL2C_Tests_UnsafeTest */ this__, /* IL2C_Tests_UnsafeTest */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: IL2C.Tests.ValueTypeTestTarget

extern /* internalcall */ void __IL2C_Tests_ValueTypeTestTarget_IL2C_MarkHandler__(IL2C_Tests_ValueTypeTestTarget* this__);
extern /* internalcall */ void* __IL2C_Tests_ValueTypeTestTarget_IL2C_RuntimeCast__(IL2C_Tests_ValueTypeTestTarget* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_ValueTypeTestTarget_GetValue2(IL2C_Tests_ValueTypeTestTarget* this__, int32_t a, int32_t b);

// [2-5] Virtual methods: IL2C.Tests.ValueTypeTestTarget

#define IL2C_Tests_ValueTypeTestTarget_ToString(/* IL2C_Tests_ValueTypeTestTarget */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_ValueTypeTestTarget_GetHashCode(/* IL2C_Tests_ValueTypeTestTarget */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_ValueTypeTestTarget_Finalize(/* IL2C_Tests_ValueTypeTestTarget */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_ValueTypeTestTarget_Equals(/* IL2C_Tests_ValueTypeTestTarget */ this__, /* IL2C_Tests_ValueTypeTestTarget */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define IL2C_Tests_ValueTypeTestTarget_GetHashCode(/* IL2C_Tests_ValueTypeTestTarget */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_ValueTypeTestTarget_ToString(/* IL2C_Tests_ValueTypeTestTarget */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_ValueTypeTestTarget_Equals(/* IL2C_Tests_ValueTypeTestTarget */ this__, /* IL2C_Tests_ValueTypeTestTarget */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: IL2C.Tests.ValueTypeTest

extern /* internalcall */ void __IL2C_Tests_ValueTypeTest_IL2C_MarkHandler__(IL2C_Tests_ValueTypeTest* this__);
extern /* internalcall */ void* __IL2C_Tests_ValueTypeTest_IL2C_RuntimeCast__(IL2C_Tests_ValueTypeTest* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t IL2C_Tests_ValueTypeTest_Test4();
extern int32_t IL2C_Tests_ValueTypeTest_Test5();
extern void IL2C_Tests_ValueTypeTest__ctor(IL2C_Tests_ValueTypeTest* this__);

// [2-5] Virtual methods: IL2C.Tests.ValueTypeTest

#define IL2C_Tests_ValueTypeTest_ToString(/* IL2C_Tests_ValueTypeTest */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define IL2C_Tests_ValueTypeTest_GetHashCode(/* IL2C_Tests_ValueTypeTest */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define IL2C_Tests_ValueTypeTest_Finalize(/* IL2C_Tests_ValueTypeTest */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define IL2C_Tests_ValueTypeTest_Equals(/* IL2C_Tests_ValueTypeTest */ this__, /* IL2C_Tests_ValueTypeTest */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

#ifdef __cplusplus
}
#endif

#endif
