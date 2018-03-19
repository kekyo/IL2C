#ifndef __MODULE_Calculator_Code__
#define __MODULE_Calculator_Code__

#include <il2c.h>
#include <stdint.h>
#include <wchar.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:

typedef struct Calculator_AbstractNode Calculator_AbstractNode;
typedef struct Calculator_OperatorNode Calculator_OperatorNode;
typedef struct Calculator_ReducibleNode Calculator_ReducibleNode;
typedef struct Calculator_NumericNode Calculator_NumericNode;
typedef struct Calculator_ExpressionNode Calculator_ExpressionNode;
typedef struct Calculator_PolishNotation Calculator_PolishNotation;

////////////////////////////////////////////////////////////
// Class: Calculator.AbstractNode

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Calculator_AbstractNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(Calculator_AbstractNode* this__);
    int32_t (*GetHashCode)(Calculator_AbstractNode* this__);
    void (*Finalize)(Calculator_AbstractNode* this__);
    bool (*Equals)(Calculator_AbstractNode* this__, System_Object* obj);
} __Calculator_AbstractNode_VTABLE_DECL__;

// Class layout
struct Calculator_AbstractNode
{
    __Calculator_AbstractNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Calculator_AbstractNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Calculator.OperatorNode

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Calculator_OperatorNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(Calculator_OperatorNode* this__);
    int32_t (*GetHashCode)(Calculator_OperatorNode* this__);
    void (*Finalize)(Calculator_OperatorNode* this__);
    bool (*Equals)(Calculator_OperatorNode* this__, System_Object* obj);
} __Calculator_OperatorNode_VTABLE_DECL__;

// Class layout
struct Calculator_OperatorNode
{
    __Calculator_OperatorNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
    wchar_t Operator;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Calculator_OperatorNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Calculator.ReducibleNode

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Calculator_ReducibleNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(Calculator_ReducibleNode* this__);
    int32_t (*GetHashCode)(Calculator_ReducibleNode* this__);
    void (*Finalize)(Calculator_ReducibleNode* this__);
    bool (*Equals)(Calculator_ReducibleNode* this__, System_Object* obj);
    int32_t (*Reduce)(Calculator_ReducibleNode* this__);
} __Calculator_ReducibleNode_VTABLE_DECL__;

// Class layout
struct Calculator_ReducibleNode
{
    __Calculator_ReducibleNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Calculator_ReducibleNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Calculator.NumericNode

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Calculator_NumericNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(Calculator_NumericNode* this__);
    int32_t (*GetHashCode)(Calculator_NumericNode* this__);
    void (*Finalize)(Calculator_NumericNode* this__);
    bool (*Equals)(Calculator_NumericNode* this__, System_Object* obj);
    int32_t (*Reduce)(Calculator_NumericNode* this__);
} __Calculator_NumericNode_VTABLE_DECL__;

// Class layout
struct Calculator_NumericNode
{
    __Calculator_NumericNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
    int32_t Numeric;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Calculator_NumericNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Calculator.ExpressionNode

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Calculator_ExpressionNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(Calculator_ExpressionNode* this__);
    int32_t (*GetHashCode)(Calculator_ExpressionNode* this__);
    void (*Finalize)(Calculator_ExpressionNode* this__);
    bool (*Equals)(Calculator_ExpressionNode* this__, System_Object* obj);
    int32_t (*Reduce)(Calculator_ExpressionNode* this__);
} __Calculator_ExpressionNode_VTABLE_DECL__;

// Class layout
struct Calculator_ExpressionNode
{
    __Calculator_ExpressionNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
    Calculator_OperatorNode* Operator;
    Calculator_ReducibleNode* Left;
    Calculator_ReducibleNode* Right;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Calculator_ExpressionNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: Calculator.PolishNotation

// Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Calculator_PolishNotation* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(Calculator_PolishNotation* this__);
    int32_t (*GetHashCode)(Calculator_PolishNotation* this__);
    void (*Finalize)(Calculator_PolishNotation* this__);
    bool (*Equals)(Calculator_PolishNotation* this__, System_Object* obj);
} __Calculator_PolishNotation_VTABLE_DECL__;

// Class layout
struct Calculator_PolishNotation
{
    __Calculator_PolishNotation_VTABLE_DECL__* vptr0__;
};


// Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Calculator_PolishNotation_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:







//////////////////////////////////////////////////////////////////////////////////
// Methods:

// Calculator.AbstractNode
extern /* internalcall */ void __Calculator_AbstractNode_IL2C_MarkHandler__(Calculator_AbstractNode* this__);
extern /* internalcall */ void* __Calculator_AbstractNode_IL2C_RuntimeCast__(Calculator_AbstractNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Calculator_AbstractNode__ctor(Calculator_AbstractNode* this__, int32_t nextIndex);
#define Calculator_AbstractNode_ToString(/* Calculator_AbstractNode* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Calculator_AbstractNode_GetHashCode(/* Calculator_AbstractNode* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Calculator_AbstractNode_Finalize(/* Calculator_AbstractNode* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Calculator_AbstractNode_Equals(/* Calculator_AbstractNode* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// Calculator.OperatorNode
extern /* internalcall */ void __Calculator_OperatorNode_IL2C_MarkHandler__(Calculator_OperatorNode* this__);
extern /* internalcall */ void* __Calculator_OperatorNode_IL2C_RuntimeCast__(Calculator_OperatorNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Calculator_OperatorNode__ctor(Calculator_OperatorNode* this__, wchar_t oper, int32_t nextIndex);
#define Calculator_OperatorNode_ToString(/* Calculator_OperatorNode* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Calculator_OperatorNode_GetHashCode(/* Calculator_OperatorNode* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Calculator_OperatorNode_Finalize(/* Calculator_OperatorNode* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Calculator_OperatorNode_Equals(/* Calculator_OperatorNode* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// Calculator.ReducibleNode
extern /* internalcall */ void __Calculator_ReducibleNode_IL2C_MarkHandler__(Calculator_ReducibleNode* this__);
extern /* internalcall */ void* __Calculator_ReducibleNode_IL2C_RuntimeCast__(Calculator_ReducibleNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Calculator_ReducibleNode__ctor(Calculator_ReducibleNode* this__, int32_t nextIndex);
extern /* virtual */ int32_t __Calculator_ReducibleNode_Reduce__(Calculator_ReducibleNode* this__);
#define Calculator_ReducibleNode_ToString(/* Calculator_ReducibleNode* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Calculator_ReducibleNode_GetHashCode(/* Calculator_ReducibleNode* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Calculator_ReducibleNode_Finalize(/* Calculator_ReducibleNode* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Calculator_ReducibleNode_Equals(/* Calculator_ReducibleNode* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define Calculator_ReducibleNode_Reduce(/* Calculator_ReducibleNode* */ this__) \
    ((this__)->vptr0__->Reduce(this__))

// Calculator.NumericNode
extern /* internalcall */ void __Calculator_NumericNode_IL2C_MarkHandler__(Calculator_NumericNode* this__);
extern /* internalcall */ void* __Calculator_NumericNode_IL2C_RuntimeCast__(Calculator_NumericNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Calculator_NumericNode__ctor(Calculator_NumericNode* this__, int32_t numeric, int32_t nextIndex);
extern /* virtual */ int32_t __Calculator_NumericNode_Reduce__(Calculator_NumericNode* this__);
#define Calculator_NumericNode_ToString(/* Calculator_NumericNode* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Calculator_NumericNode_GetHashCode(/* Calculator_NumericNode* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Calculator_NumericNode_Finalize(/* Calculator_NumericNode* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Calculator_NumericNode_Equals(/* Calculator_NumericNode* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define Calculator_NumericNode_Reduce(/* Calculator_NumericNode* */ this__) \
    ((this__)->vptr0__->Reduce(this__))

// Calculator.ExpressionNode
extern /* internalcall */ void __Calculator_ExpressionNode_IL2C_MarkHandler__(Calculator_ExpressionNode* this__);
extern /* internalcall */ void* __Calculator_ExpressionNode_IL2C_RuntimeCast__(Calculator_ExpressionNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Calculator_ExpressionNode__ctor(Calculator_ExpressionNode* this__, Calculator_OperatorNode* oper, Calculator_ReducibleNode* left, Calculator_ReducibleNode* right, int32_t nextIndex);
extern /* virtual */ int32_t __Calculator_ExpressionNode_Reduce__(Calculator_ExpressionNode* this__);
#define Calculator_ExpressionNode_ToString(/* Calculator_ExpressionNode* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Calculator_ExpressionNode_GetHashCode(/* Calculator_ExpressionNode* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Calculator_ExpressionNode_Finalize(/* Calculator_ExpressionNode* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Calculator_ExpressionNode_Equals(/* Calculator_ExpressionNode* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define Calculator_ExpressionNode_Reduce(/* Calculator_ExpressionNode* */ this__) \
    ((this__)->vptr0__->Reduce(this__))

// Calculator.PolishNotation
extern /* internalcall */ void __Calculator_PolishNotation_IL2C_MarkHandler__(Calculator_PolishNotation* this__);
extern /* internalcall */ void* __Calculator_PolishNotation_IL2C_RuntimeCast__(Calculator_PolishNotation* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern int32_t Calculator_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex);
extern Calculator_OperatorNode* Calculator_PolishNotation_ParseOperator(System_String* line, int32_t startIndex);
extern Calculator_NumericNode* Calculator_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex);
extern Calculator_ExpressionNode* Calculator_PolishNotation_ParseExpression(System_String* line, int32_t startIndex);
extern void Calculator_PolishNotation_SendExternalTicker(System_String* message);
extern void Calculator_PolishNotation_Main(void);
extern void Calculator_PolishNotation__ctor(Calculator_PolishNotation* this__);
#define Calculator_PolishNotation_ToString(/* Calculator_PolishNotation* */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Calculator_PolishNotation_GetHashCode(/* Calculator_PolishNotation* */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Calculator_PolishNotation_Finalize(/* Calculator_PolishNotation* */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Calculator_PolishNotation_Equals(/* Calculator_PolishNotation* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

#ifdef __cplusplus
}
#endif

#endif
