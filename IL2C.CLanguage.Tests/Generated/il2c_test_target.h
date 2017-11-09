#ifndef __MODULE_il2c_test_target__
#define __MODULE_il2c_test_target__

#include <il2c.h>

typedef struct il2c_test_target_ClassTypeTestTarget
{
    int32_t Value2;
    struct il2c_test_target_ClassTypeTestTarget* OR2;
} il2c_test_target_ClassTypeTestTarget;
#define __il2c_test_target_ClassTypeTestTarget_SIZEOF__() (sizeof(il2c_test_target_ClassTypeTestTarget))

typedef struct il2c_test_target_ClassTypeTest il2c_test_target_ClassTypeTest;
#define __il2c_test_target_ClassTypeTest_SIZEOF__() (0)

typedef struct il2c_test_target_ValueTypeTestTarget
{
    int32_t Value2;
} il2c_test_target_ValueTypeTestTarget;
#define __il2c_test_target_ValueTypeTestTarget_SIZEOF__() (sizeof(il2c_test_target_ValueTypeTestTarget))

typedef struct il2c_test_target_ValueTypeTest il2c_test_target_ValueTypeTest;
#define __il2c_test_target_ValueTypeTest_SIZEOF__() (0)

typedef struct il2c_test_target_Hoge2 il2c_test_target_Hoge2;
#define __il2c_test_target_Hoge2_SIZEOF__() (0)

typedef struct il2c_test_target_Hoge1 il2c_test_target_Hoge1;
#define __il2c_test_target_Hoge1_SIZEOF__() (0)

extern int32_t il2c_test_target_ValueTypeTestTarget_Value1;

extern int32_t il2c_test_target_ClassTypeTestTarget_GetValue2(il2c_test_target_ClassTypeTestTarget* __this, int32_t a, int32_t b);
extern void il2c_test_target_ClassTypeTestTarget__ctor(il2c_test_target_ClassTypeTestTarget* __this);
extern void __il2c_test_target_ClassTypeTestTarget_MARK_HANDLER__(void* pReference);
extern void __il2c_test_target_ClassTypeTestTarget_NEW__(il2c_test_target_ClassTypeTestTarget** ppReference);

extern int32_t il2c_test_target_ClassTypeTest_Test4(void);
extern int32_t il2c_test_target_ClassTypeTest_Test5(void);
extern void il2c_test_target_ClassTypeTest__ctor(il2c_test_target_ClassTypeTest* __this);
extern int32_t il2c_test_target_ValueTypeTestTarget_GetValue2(il2c_test_target_ValueTypeTestTarget* __this, int32_t a, int32_t b);
extern int32_t il2c_test_target_ValueTypeTest_Test4(void);
extern int32_t il2c_test_target_ValueTypeTest_Test5(void);
extern void il2c_test_target_ValueTypeTest__ctor(il2c_test_target_ValueTypeTest* __this);
extern uint8_t il2c_test_target_Hoge2_Add3(uint8_t a, bool isTwo);
extern uint16_t il2c_test_target_Hoge2_Add4(uint16_t a, bool isTwo);
extern void il2c_test_target_Hoge2__ctor(il2c_test_target_Hoge2* __this);
extern int32_t il2c_test_target_Hoge1_Add1(int32_t a, bool isTwo);
extern int64_t il2c_test_target_Hoge1_Add2(int64_t a, bool isTwo);
extern void il2c_test_target_Hoge1__ctor(il2c_test_target_Hoge1* __this);

#endif
