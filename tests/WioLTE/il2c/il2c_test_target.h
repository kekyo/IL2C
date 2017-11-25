#ifndef __MODULE_il2c_test_target__
#define __MODULE_il2c_test_target__

#include <il2c.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:

typedef struct il2c_test_target_ClassTypeTestTarget il2c_test_target_ClassTypeTestTarget;
typedef struct il2c_test_target_ClassTypeTest il2c_test_target_ClassTypeTest;
typedef struct il2c_test_target_Wio il2c_test_target_Wio;
typedef struct il2c_test_target_ValueTypeTestTarget il2c_test_target_ValueTypeTestTarget;
typedef struct il2c_test_target_ValueTypeTest il2c_test_target_ValueTypeTest;
typedef struct il2c_test_target_Hoge2 il2c_test_target_Hoge2;
typedef struct il2c_test_target_Hoge1 il2c_test_target_Hoge1;

////////////////////////////////////////////////////////////
// Class: il2c_test_target.ClassTypeTestTarget

struct il2c_test_target_ClassTypeTestTarget
{
    int32_t Value2;
    il2c_test_target_ClassTypeTestTarget* OR2;
};

#define __il2c_test_target_ClassTypeTestTarget_SIZEOF__() (sizeof(il2c_test_target_ClassTypeTestTarget))

////////////////////////////////////////////////////////////
// Class: il2c_test_target.ClassTypeTest


#define __il2c_test_target_ClassTypeTest_SIZEOF__() (0)

////////////////////////////////////////////////////////////
// Class: il2c_test_target.Wio


#define __il2c_test_target_Wio_SIZEOF__() (0)

////////////////////////////////////////////////////////////
// Struct: il2c_test_target.ValueTypeTestTarget

struct il2c_test_target_ValueTypeTestTarget
{
    int32_t Value2;
};

#define __il2c_test_target_ValueTypeTestTarget_SIZEOF__() (sizeof(il2c_test_target_ValueTypeTestTarget))

////////////////////////////////////////////////////////////
// Class: il2c_test_target.ValueTypeTest


#define __il2c_test_target_ValueTypeTest_SIZEOF__() (0)

////////////////////////////////////////////////////////////
// Class: il2c_test_target.Hoge2


#define __il2c_test_target_Hoge2_SIZEOF__() (0)

////////////////////////////////////////////////////////////
// Class: il2c_test_target.Hoge1


#define __il2c_test_target_Hoge1_SIZEOF__() (0)

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:

extern int32_t il2c_test_target_ClassTypeTestTarget_Value1;
extern il2c_test_target_ClassTypeTestTarget* il2c_test_target_ClassTypeTestTarget_OR1;



extern int32_t il2c_test_target_ValueTypeTestTarget_Value1;




//////////////////////////////////////////////////////////////////////////////////
// Methods:

extern int32_t il2c_test_target_ClassTypeTestTarget_GetValue2(il2c_test_target_ClassTypeTestTarget* __this, int32_t a, int32_t b);
extern void il2c_test_target_ClassTypeTestTarget__ctor(il2c_test_target_ClassTypeTestTarget* __this);
extern void __il2c_test_target_ClassTypeTestTarget_MARK_HANDLER__(void* pReference);
extern void __il2c_test_target_ClassTypeTestTarget_NEW__(il2c_test_target_ClassTypeTestTarget** ppReference);

extern int32_t il2c_test_target_ClassTypeTest_Test4(void);
extern int32_t il2c_test_target_ClassTypeTest_Test5(void);
extern void il2c_test_target_ClassTypeTest__ctor(il2c_test_target_ClassTypeTest* __this);
extern void __il2c_test_target_ClassTypeTest_MARK_HANDLER__(void* pReference);
extern void __il2c_test_target_ClassTypeTest_NEW__(il2c_test_target_ClassTypeTest** ppReference);

extern void il2c_test_target_Wio_Init(void);
extern void il2c_test_target_Wio_LedSetRGB(int32_t r, int32_t g, int32_t b);
extern void il2c_test_target_Wio_delay(int32_t milliseconds);
extern void il2c_test_target_Wio__ctor(il2c_test_target_Wio* __this);
extern void __il2c_test_target_Wio_MARK_HANDLER__(void* pReference);
extern void __il2c_test_target_Wio_NEW__(il2c_test_target_Wio** ppReference);

extern int32_t il2c_test_target_ValueTypeTestTarget_GetValue2(il2c_test_target_ValueTypeTestTarget* __this, int32_t a, int32_t b);

extern int32_t il2c_test_target_ValueTypeTest_Test4(void);
extern int32_t il2c_test_target_ValueTypeTest_Test5(void);
extern void il2c_test_target_ValueTypeTest__ctor(il2c_test_target_ValueTypeTest* __this);
extern void __il2c_test_target_ValueTypeTest_MARK_HANDLER__(void* pReference);
extern void __il2c_test_target_ValueTypeTest_NEW__(il2c_test_target_ValueTypeTest** ppReference);

extern uint8_t il2c_test_target_Hoge2_Add3(uint8_t a, bool isTwo);
extern uint16_t il2c_test_target_Hoge2_Add4(uint16_t a, bool isTwo);
extern void il2c_test_target_Hoge2__ctor(il2c_test_target_Hoge2* __this);
extern void __il2c_test_target_Hoge2_MARK_HANDLER__(void* pReference);
extern void __il2c_test_target_Hoge2_NEW__(il2c_test_target_Hoge2** ppReference);

extern int32_t il2c_test_target_Hoge1_Add1(int32_t a, bool isTwo);
extern int64_t il2c_test_target_Hoge1_Add2(int64_t a, bool isTwo);
extern void il2c_test_target_Hoge1__ctor(il2c_test_target_Hoge1* __this);
extern void __il2c_test_target_Hoge1_MARK_HANDLER__(void* pReference);
extern void __il2c_test_target_Hoge1_NEW__(il2c_test_target_Hoge1** ppReference);

#ifdef __cplusplus
}
#endif

#endif
