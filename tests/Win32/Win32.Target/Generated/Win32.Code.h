#ifndef __MODULE_Win32_Code__
#define __MODULE_Win32_Code__

#include <il2c.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:

typedef struct Win32_Code_StringTest Win32_Code_StringTest;
typedef struct Win32_Code_ClassTypeTestTarget Win32_Code_ClassTypeTestTarget;
typedef struct Win32_Code_ClassTypeTest Win32_Code_ClassTypeTest;
typedef struct Win32_Code_BoxingTest Win32_Code_BoxingTest;
typedef struct Win32_Code_Win32 Win32_Code_Win32;
typedef struct Win32_Code_ValueTypeTestTarget Win32_Code_ValueTypeTestTarget;
typedef struct Win32_Code_ValueTypeTest Win32_Code_ValueTypeTest;
typedef struct Win32_Code_Hoge2 Win32_Code_Hoge2;
typedef struct Win32_Code_Hoge1 Win32_Code_Hoge1;

////////////////////////////////////////////////////////////
// Class: Win32.Code.StringTest


extern const __RUNTIME_TYPE__ __Win32_Code_StringTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.ClassTypeTestTarget

struct Win32_Code_ClassTypeTestTarget
{
    int32_t Value2;
    Win32_Code_ClassTypeTestTarget* OR2;
};

extern const __RUNTIME_TYPE__ __Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.ClassTypeTest


extern const __RUNTIME_TYPE__ __Win32_Code_ClassTypeTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.BoxingTest


extern const __RUNTIME_TYPE__ __Win32_Code_BoxingTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.Win32


extern const __RUNTIME_TYPE__ __Win32_Code_Win32_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Struct: Win32.Code.ValueTypeTestTarget

struct Win32_Code_ValueTypeTestTarget
{
    int32_t Value2;
    Win32_Code_ClassTypeTestTarget* OR2;
};

extern const __RUNTIME_TYPE__ __Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.ValueTypeTest


extern const __RUNTIME_TYPE__ __Win32_Code_ValueTypeTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.Hoge2


extern const __RUNTIME_TYPE__ __Win32_Code_Hoge2_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.Hoge1


extern const __RUNTIME_TYPE__ __Win32_Code_Hoge1_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:


extern int32_t Win32_Code_ClassTypeTestTarget_Value1;
extern Win32_Code_ClassTypeTestTarget* Win32_Code_ClassTypeTestTarget_OR1;




extern int32_t Win32_Code_ValueTypeTestTarget_Value1;




//////////////////////////////////////////////////////////////////////////////////
// Methods:

extern void Win32_Code_StringTest_LiteralString(void);
extern System_String* Win32_Code_StringTest_InOutString(System_String* a);
extern System_String* Win32_Code_StringTest_LiteralCombinedString(void);
extern void Win32_Code_StringTest__ctor(Win32_Code_StringTest* __this);

extern void Win32_Code_ClassTypeTestTarget__ctor(Win32_Code_ClassTypeTestTarget* __this);
extern void Win32_Code_ClassTypeTestTarget__ctor_1(Win32_Code_ClassTypeTestTarget* __this, int32_t value);
extern int32_t Win32_Code_ClassTypeTestTarget_GetValue2(Win32_Code_ClassTypeTestTarget* __this, int32_t a, int32_t b);
extern int32_t Win32_Code_ClassTypeTestTarget_GetValue2_1(Win32_Code_ClassTypeTestTarget* __this, int32_t a, int32_t b, int32_t c);

extern int32_t Win32_Code_ClassTypeTest_Test4(void);
extern int32_t Win32_Code_ClassTypeTest_Test5(void);
extern int32_t Win32_Code_ClassTypeTest_Test6(void);
extern int32_t Win32_Code_ClassTypeTest_Test7(void);
extern void Win32_Code_ClassTypeTest__ctor(Win32_Code_ClassTypeTest* __this);

extern void Win32_Code_BoxingTest_BoxingInt32(int32_t a);
extern void Win32_Code_BoxingTest__ctor(Win32_Code_BoxingTest* __this);

extern int32_t Win32_Code_Win32_GetCurrentProcessId(void);
extern int32_t Win32_Code_Win32_GetCurrentThreadId(void);
extern void Win32_Code_Win32_OutputDebugString(System_String* message);
extern void Win32_Code_Win32__ctor(Win32_Code_Win32* __this);

extern int32_t Win32_Code_ValueTypeTestTarget_GetValue2(Win32_Code_ValueTypeTestTarget* __this, int32_t a, int32_t b);

extern int32_t Win32_Code_ValueTypeTest_Test4(void);
extern int32_t Win32_Code_ValueTypeTest_Test5(void);
extern void Win32_Code_ValueTypeTest__ctor(Win32_Code_ValueTypeTest* __this);

extern uint8_t Win32_Code_Hoge2_Add3(uint8_t a, bool isTwo);
extern uint16_t Win32_Code_Hoge2_Add4(uint16_t a, bool isTwo);
extern void Win32_Code_Hoge2__ctor(Win32_Code_Hoge2* __this);

extern int32_t Win32_Code_Hoge1_Add1(int32_t a, bool isTwo);
extern int64_t Win32_Code_Hoge1_Add2(int64_t a, bool isTwo);
extern void Win32_Code_Hoge1__ctor(Win32_Code_Hoge1* __this);

#ifdef __cplusplus
}
#endif

#endif
