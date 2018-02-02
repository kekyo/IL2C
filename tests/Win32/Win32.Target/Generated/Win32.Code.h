#ifndef __MODULE_Win32_Code__
#define __MODULE_Win32_Code__

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

typedef struct Win32_Code_BoxingTest Win32_Code_BoxingTest;
typedef struct Win32_Code_ClassTypeTestTarget Win32_Code_ClassTypeTestTarget;
typedef struct Win32_Code_ClassTypeTest Win32_Code_ClassTypeTest;
typedef struct Win32_Code_Hoge1 Win32_Code_Hoge1;
typedef struct Win32_Code_Hoge2 Win32_Code_Hoge2;
typedef struct Win32_Code_InheritTestTargetBase1 Win32_Code_InheritTestTargetBase1;
typedef struct Win32_Code_InheritTestTarget2 Win32_Code_InheritTestTarget2;
typedef struct Win32_Code_InheritTypeTest Win32_Code_InheritTypeTest;
typedef struct Win32_Code_Win32 Win32_Code_Win32;
typedef struct Win32_Code_AbstractNode Win32_Code_AbstractNode;
typedef struct Win32_Code_OperatorNode Win32_Code_OperatorNode;
typedef struct Win32_Code_ReducibleNode Win32_Code_ReducibleNode;
typedef struct Win32_Code_NumericNode Win32_Code_NumericNode;
typedef struct Win32_Code_ExpressionNode Win32_Code_ExpressionNode;
typedef struct Win32_Code_PolishNotation Win32_Code_PolishNotation;
typedef struct Win32_Code_StringTest Win32_Code_StringTest;
typedef struct Win32_Code_UnsafeTest Win32_Code_UnsafeTest;
typedef struct Win32_Code_ValueTypeTestTarget Win32_Code_ValueTypeTestTarget;
typedef struct Win32_Code_ValueTypeTest Win32_Code_ValueTypeTest;

////////////////////////////////////////////////////////////
// Class: Win32.Code.BoxingTest


extern const IL2C_RUNTIME_TYPE __Win32_Code_BoxingTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.ClassTypeTestTarget

struct Win32_Code_ClassTypeTestTarget
{
    int32_t Value2;
    Win32_Code_ClassTypeTestTarget* OR2;
};

extern const IL2C_RUNTIME_TYPE __Win32_Code_ClassTypeTestTarget_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.ClassTypeTest


extern const IL2C_RUNTIME_TYPE __Win32_Code_ClassTypeTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.Hoge1


extern const IL2C_RUNTIME_TYPE __Win32_Code_Hoge1_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.Hoge2


extern const IL2C_RUNTIME_TYPE __Win32_Code_Hoge2_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.InheritTestTargetBase1

struct Win32_Code_InheritTestTargetBase1
{
    int32_t Value2;
    Win32_Code_ClassTypeTestTarget* OR2;
};

extern const IL2C_RUNTIME_TYPE __Win32_Code_InheritTestTargetBase1_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.InheritTestTarget2

struct Win32_Code_InheritTestTarget2
{
    int32_t Value2;
    Win32_Code_ClassTypeTestTarget* OR2;
};

extern const IL2C_RUNTIME_TYPE __Win32_Code_InheritTestTarget2_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.InheritTypeTest


extern const IL2C_RUNTIME_TYPE __Win32_Code_InheritTypeTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.Win32


extern const IL2C_RUNTIME_TYPE __Win32_Code_Win32_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.AbstractNode

struct Win32_Code_AbstractNode
{
    int32_t NextIndex;
};

extern const IL2C_RUNTIME_TYPE __Win32_Code_AbstractNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.OperatorNode

struct Win32_Code_OperatorNode
{
    int32_t NextIndex;
    wchar_t Operator;
};

extern const IL2C_RUNTIME_TYPE __Win32_Code_OperatorNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.ReducibleNode

struct Win32_Code_ReducibleNode
{
    int32_t NextIndex;
};

extern const IL2C_RUNTIME_TYPE __Win32_Code_ReducibleNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.NumericNode

struct Win32_Code_NumericNode
{
    int32_t NextIndex;
    int32_t Numeric;
};

extern const IL2C_RUNTIME_TYPE __Win32_Code_NumericNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.ExpressionNode

struct Win32_Code_ExpressionNode
{
    int32_t NextIndex;
    Win32_Code_OperatorNode* Operator;
    Win32_Code_ReducibleNode* Left;
    Win32_Code_ReducibleNode* Right;
};

extern const IL2C_RUNTIME_TYPE __Win32_Code_ExpressionNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.PolishNotation


extern const IL2C_RUNTIME_TYPE __Win32_Code_PolishNotation_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.StringTest


extern const IL2C_RUNTIME_TYPE __Win32_Code_StringTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.UnsafeTest


extern const IL2C_RUNTIME_TYPE __Win32_Code_UnsafeTest_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Struct: Win32.Code.ValueTypeTestTarget

struct Win32_Code_ValueTypeTestTarget
{
    int32_t Value2;
    Win32_Code_ClassTypeTestTarget* OR2;
};

extern const IL2C_RUNTIME_TYPE __Win32_Code_ValueTypeTestTarget_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Win32.Code.ValueTypeTest


extern const IL2C_RUNTIME_TYPE __Win32_Code_ValueTypeTest_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:


extern int32_t Win32_Code_ClassTypeTestTarget_Value1;
extern Win32_Code_ClassTypeTestTarget* Win32_Code_ClassTypeTestTarget_OR1;
















extern int32_t Win32_Code_ValueTypeTestTarget_Value1;


//////////////////////////////////////////////////////////////////////////////////
// Methods:

extern void Win32_Code_BoxingTest_BoxingInt32(int32_t a);
extern void Win32_Code_BoxingTest__ctor(Win32_Code_BoxingTest* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_BoxingTest_TYPE_DEF_TYPE__;


extern void Win32_Code_ClassTypeTestTarget__ctor(Win32_Code_ClassTypeTestTarget* this__);
extern void Win32_Code_ClassTypeTestTarget__ctor_1(Win32_Code_ClassTypeTestTarget* this__, int32_t value);
extern int32_t Win32_Code_ClassTypeTestTarget_GetValue2(Win32_Code_ClassTypeTestTarget* this__, int32_t a, int32_t b);
extern int32_t Win32_Code_ClassTypeTestTarget_GetValue2_1(Win32_Code_ClassTypeTestTarget* this__, int32_t a, int32_t b, int32_t c);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_ClassTypeTestTarget_TYPE_DEF_TYPE__;


extern int32_t Win32_Code_ClassTypeTest_Test4(void);
extern int32_t Win32_Code_ClassTypeTest_Test5(void);
extern int32_t Win32_Code_ClassTypeTest_Test6(void);
extern int32_t Win32_Code_ClassTypeTest_Test7(void);
extern void Win32_Code_ClassTypeTest__ctor(Win32_Code_ClassTypeTest* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_ClassTypeTest_TYPE_DEF_TYPE__;


extern int32_t Win32_Code_Hoge1_Add1(int32_t a, bool isTwo);
extern int64_t Win32_Code_Hoge1_Add2(int64_t a, bool isTwo);
extern void Win32_Code_Hoge1__ctor(Win32_Code_Hoge1* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_Hoge1_TYPE_DEF_TYPE__;


extern uint8_t Win32_Code_Hoge2_Add3(uint8_t a, bool isTwo);
extern uint16_t Win32_Code_Hoge2_Add4(uint16_t a, bool isTwo);
extern void Win32_Code_Hoge2__ctor(Win32_Code_Hoge2* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_Hoge2_TYPE_DEF_TYPE__;


extern void Win32_Code_InheritTestTargetBase1__ctor(Win32_Code_InheritTestTargetBase1* this__);
extern void Win32_Code_InheritTestTargetBase1__ctor_1(Win32_Code_InheritTestTargetBase1* this__, int32_t value);
extern int32_t Win32_Code_InheritTestTargetBase1_Calc(Win32_Code_InheritTestTargetBase1* this__, int32_t a);
extern int32_t __Win32_Code_InheritTestTargetBase1_Calc_1__(Win32_Code_InheritTestTargetBase1* this__, int32_t a, int32_t b);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Calc_1)(Win32_Code_InheritTestTargetBase1* this__, int32_t a, int32_t b);
} __Win32_Code_InheritTestTargetBase1_TYPE_DEF_TYPE__;

#define Win32_Code_InheritTestTargetBase1_Calc_1(this__, a, b) \
    (((__Win32_Code_InheritTestTargetBase1_TYPE_DEF_TYPE__*)(il2c_get_type(this__)))->Calc_1(this__, a, b))

extern void Win32_Code_InheritTestTarget2__ctor(Win32_Code_InheritTestTarget2* this__);
extern void Win32_Code_InheritTestTarget2__ctor_1(Win32_Code_InheritTestTarget2* this__, int32_t value);
extern int32_t Win32_Code_InheritTestTarget2_Calc(Win32_Code_InheritTestTarget2* this__, int32_t a);
extern int32_t __Win32_Code_InheritTestTarget2_Calc_1__(Win32_Code_InheritTestTarget2* this__, int32_t a, int32_t b);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Calc_1)(Win32_Code_InheritTestTarget2* this__, int32_t a, int32_t b);
} __Win32_Code_InheritTestTarget2_TYPE_DEF_TYPE__;

#define Win32_Code_InheritTestTarget2_Calc_1(this__, a, b) \
    (((__Win32_Code_InheritTestTarget2_TYPE_DEF_TYPE__*)(il2c_get_type(this__)))->Calc_1(this__, a, b))

extern int32_t Win32_Code_InheritTypeTest_Test1(void);
extern int32_t Win32_Code_InheritTypeTest_Test2(void);
extern int32_t Win32_Code_InheritTypeTest_Test3(void);
extern int32_t Win32_Code_InheritTypeTest_Test4(void);
extern void Win32_Code_InheritTypeTest__ctor(Win32_Code_InheritTypeTest* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_InheritTypeTest_TYPE_DEF_TYPE__;


extern int32_t Win32_Code_Win32_GetCurrentProcessId(void);
extern int32_t Win32_Code_Win32_GetCurrentThreadId(void);
extern void Win32_Code_Win32_OutputDebugString(System_String* message);
extern void Win32_Code_Win32__ctor(Win32_Code_Win32* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_Win32_TYPE_DEF_TYPE__;


extern void Win32_Code_AbstractNode__ctor(Win32_Code_AbstractNode* this__, int32_t nextIndex);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_AbstractNode_TYPE_DEF_TYPE__;


extern void Win32_Code_OperatorNode__ctor(Win32_Code_OperatorNode* this__, wchar_t oper, int32_t nextIndex);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_OperatorNode_TYPE_DEF_TYPE__;


extern void Win32_Code_ReducibleNode__ctor(Win32_Code_ReducibleNode* this__, int32_t nextIndex);
extern int32_t __Win32_Code_ReducibleNode_Reduce__(Win32_Code_ReducibleNode* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Reduce)(Win32_Code_ReducibleNode* this__);
} __Win32_Code_ReducibleNode_TYPE_DEF_TYPE__;

#define Win32_Code_ReducibleNode_Reduce(this__) \
    (((__Win32_Code_ReducibleNode_TYPE_DEF_TYPE__*)(il2c_get_type(this__)))->Reduce(this__))

extern void Win32_Code_NumericNode__ctor(Win32_Code_NumericNode* this__, int32_t numeric, int32_t nextIndex);
extern int32_t __Win32_Code_NumericNode_Reduce__(Win32_Code_NumericNode* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Reduce)(Win32_Code_NumericNode* this__);
} __Win32_Code_NumericNode_TYPE_DEF_TYPE__;

#define Win32_Code_NumericNode_Reduce(this__) \
    (((__Win32_Code_NumericNode_TYPE_DEF_TYPE__*)(il2c_get_type(this__)))->Reduce(this__))

extern void Win32_Code_ExpressionNode__ctor(Win32_Code_ExpressionNode* this__, Win32_Code_OperatorNode* oper, Win32_Code_ReducibleNode* left, Win32_Code_ReducibleNode* right, int32_t nextIndex);
extern int32_t __Win32_Code_ExpressionNode_Reduce__(Win32_Code_ExpressionNode* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Reduce)(Win32_Code_ExpressionNode* this__);
} __Win32_Code_ExpressionNode_TYPE_DEF_TYPE__;

#define Win32_Code_ExpressionNode_Reduce(this__) \
    (((__Win32_Code_ExpressionNode_TYPE_DEF_TYPE__*)(il2c_get_type(this__)))->Reduce(this__))

extern int32_t Win32_Code_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex);
extern Win32_Code_OperatorNode* Win32_Code_PolishNotation_ParseOperator(System_String* line, int32_t startIndex);
extern Win32_Code_NumericNode* Win32_Code_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex);
extern Win32_Code_ExpressionNode* Win32_Code_PolishNotation_ParseExpression(System_String* line, int32_t startIndex);
extern void Win32_Code_PolishNotation_Main(void);
extern void Win32_Code_PolishNotation__ctor(Win32_Code_PolishNotation* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_PolishNotation_TYPE_DEF_TYPE__;


extern void Win32_Code_StringTest_LiteralString(void);
extern System_String* Win32_Code_StringTest_InOutString(System_String* a);
extern System_String* Win32_Code_StringTest_LiteralCombinedString(void);
extern System_String* Win32_Code_StringTest_LiteralSubstring(void);
extern wchar_t Win32_Code_StringTest_GetChar(void);
extern wchar_t Win32_Code_StringTest_GetCharByIndex(System_String* str, int32_t index);
extern void Win32_Code_StringTest__ctor(Win32_Code_StringTest* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_StringTest_TYPE_DEF_TYPE__;


extern void Win32_Code_UnsafeTest__ctor(Win32_Code_UnsafeTest* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_UnsafeTest_TYPE_DEF_TYPE__;


extern int32_t Win32_Code_ValueTypeTestTarget_GetValue2(Win32_Code_ValueTypeTestTarget* this__, int32_t a, int32_t b);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_ValueType* this__);
    int32_t (*GetHashCode)(System_ValueType* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_ValueType* this__, System_Object* obj);
} __Win32_Code_ValueTypeTestTarget_TYPE_DEF_TYPE__;


extern int32_t Win32_Code_ValueTypeTest_Test4(void);
extern int32_t Win32_Code_ValueTypeTest_Test5(void);
extern void Win32_Code_ValueTypeTest__ctor(Win32_Code_ValueTypeTest* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Win32_Code_ValueTypeTest_TYPE_DEF_TYPE__;


#ifdef __cplusplus
}
#endif

#endif
