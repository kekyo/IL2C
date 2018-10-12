#ifndef __Calculator_Code_H__
#define __Calculator_Code_H__

#include <il2c.h>
#include <Calculator.Code.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [2-1] Types:

typedef struct Calculator_AbstractNode Calculator_AbstractNode;
typedef struct Calculator_OperatorNode Calculator_OperatorNode;
typedef struct Calculator_ReducibleNode Calculator_ReducibleNode;
typedef struct Calculator_NumericNode Calculator_NumericNode;
typedef struct Calculator_ExpressionNode Calculator_ExpressionNode;
typedef struct Calculator_PolishNotation Calculator_PolishNotation;

////////////////////////////////////////////////////////////
// [1] Calculator.AbstractNode

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Calculator_AbstractNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Calculator_AbstractNode_VTABLE_DECL__;

// [1-3] Class layout
struct Calculator_AbstractNode
{
    __Calculator_AbstractNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Calculator_AbstractNode_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __Calculator_AbstractNode_VTABLE_DECL__ __Calculator_AbstractNode_VTABLE__;

////////////////////////////////////////////////////////////
// [1] Calculator.OperatorNode

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Calculator_OperatorNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Calculator_OperatorNode_VTABLE_DECL__;

// [1-3] Class layout
struct Calculator_OperatorNode
{
    __Calculator_OperatorNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
    wchar_t Operator;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Calculator_OperatorNode_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __Calculator_OperatorNode_VTABLE_DECL__ __Calculator_OperatorNode_VTABLE__;

////////////////////////////////////////////////////////////
// [1] Calculator.ReducibleNode

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Calculator_ReducibleNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Reduce)(Calculator_ReducibleNode* this__);
} __Calculator_ReducibleNode_VTABLE_DECL__;

// [1-3] Class layout
struct Calculator_ReducibleNode
{
    __Calculator_ReducibleNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Calculator_ReducibleNode_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __Calculator_ReducibleNode_VTABLE_DECL__ __Calculator_ReducibleNode_VTABLE__;

////////////////////////////////////////////////////////////
// [1] Calculator.NumericNode

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Calculator_NumericNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Reduce)(Calculator_ReducibleNode* this__);
    int32_t (*Reduce)(Calculator_NumericNode* this__);
} __Calculator_NumericNode_VTABLE_DECL__;

// [1-3] Class layout
struct Calculator_NumericNode
{
    __Calculator_NumericNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
    int32_t Numeric;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Calculator_NumericNode_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __Calculator_NumericNode_VTABLE_DECL__ __Calculator_NumericNode_VTABLE__;

////////////////////////////////////////////////////////////
// [1] Calculator.ExpressionNode

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Calculator_ExpressionNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Reduce)(Calculator_ReducibleNode* this__);
    int32_t (*Reduce)(Calculator_ExpressionNode* this__);
} __Calculator_ExpressionNode_VTABLE_DECL__;

// [1-3] Class layout
struct Calculator_ExpressionNode
{
    __Calculator_ExpressionNode_VTABLE_DECL__* vptr0__;
    int32_t NextIndex;
    Calculator_OperatorNode* Operator;
    Calculator_ReducibleNode* Left;
    Calculator_ReducibleNode* Right;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Calculator_ExpressionNode_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __Calculator_ExpressionNode_VTABLE_DECL__ __Calculator_ExpressionNode_VTABLE__;

////////////////////////////////////////////////////////////
// [1] Calculator.PolishNotation

// [1-2] Class vtable layout
typedef const struct
{
    /* internalcall */ void* (*IL2C_RuntimeCast)(Calculator_PolishNotation* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __Calculator_PolishNotation_VTABLE_DECL__;

// [1-3] Class layout
struct Calculator_PolishNotation
{
    __Calculator_PolishNotation_VTABLE_DECL__* vptr0__;
};

// [1-4] Class runtime type information
extern IL2C_RUNTIME_TYPE_DECL __Calculator_PolishNotation_RUNTIME_TYPE__;

// [1-5] Class vtable
extern __Calculator_PolishNotation_VTABLE_DECL__ __Calculator_PolishNotation_VTABLE__;

//////////////////////////////////////////////////////////////////////////////////
// [2-2] Public static fields:







//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

// [2-4] Member methods: Calculator.AbstractNode

extern /* internalcall */ void __Calculator_AbstractNode_IL2C_MarkHandler__(Calculator_AbstractNode* this__);
extern /* internalcall */ void* __Calculator_AbstractNode_IL2C_RuntimeCast__(Calculator_AbstractNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Calculator_AbstractNode__ctor(Calculator_AbstractNode* this__, int32_t nextIndex);

// [2-5] Virtual methods: Calculator.AbstractNode

#define Calculator_AbstractNode_ToString(/* Calculator_AbstractNode */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Calculator_AbstractNode_GetHashCode(/* Calculator_AbstractNode */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Calculator_AbstractNode_Finalize(/* Calculator_AbstractNode */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Calculator_AbstractNode_Equals(/* Calculator_AbstractNode */ this__, /* Calculator_AbstractNode */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: Calculator.OperatorNode

extern /* internalcall */ void __Calculator_OperatorNode_IL2C_MarkHandler__(Calculator_OperatorNode* this__);
extern /* internalcall */ void* __Calculator_OperatorNode_IL2C_RuntimeCast__(Calculator_OperatorNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Calculator_OperatorNode__ctor(Calculator_OperatorNode* this__, wchar_t oper, int32_t nextIndex);

// [2-5] Virtual methods: Calculator.OperatorNode

#define Calculator_OperatorNode_ToString(/* Calculator_OperatorNode */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Calculator_OperatorNode_GetHashCode(/* Calculator_OperatorNode */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Calculator_OperatorNode_Finalize(/* Calculator_OperatorNode */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Calculator_OperatorNode_Equals(/* Calculator_OperatorNode */ this__, /* Calculator_OperatorNode */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

// [2-4] Member methods: Calculator.ReducibleNode

extern /* internalcall */ void __Calculator_ReducibleNode_IL2C_MarkHandler__(Calculator_ReducibleNode* this__);
extern /* internalcall */ void* __Calculator_ReducibleNode_IL2C_RuntimeCast__(Calculator_ReducibleNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Calculator_ReducibleNode__ctor(Calculator_ReducibleNode* this__, int32_t nextIndex);
extern /* virtual */ int32_t __Calculator_ReducibleNode_Reduce__(Calculator_ReducibleNode* this__);

// [2-5] Virtual methods: Calculator.ReducibleNode

#define Calculator_ReducibleNode_ToString(/* Calculator_ReducibleNode */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Calculator_ReducibleNode_GetHashCode(/* Calculator_ReducibleNode */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Calculator_ReducibleNode_Finalize(/* Calculator_ReducibleNode */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Calculator_ReducibleNode_Equals(/* Calculator_ReducibleNode */ this__, /* Calculator_ReducibleNode */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define Calculator_ReducibleNode_Reduce(/* Calculator_ReducibleNode */ this__) \
    ((this__)->vptr0__->Reduce(this__))

// [2-4] Member methods: Calculator.NumericNode

extern /* internalcall */ void __Calculator_NumericNode_IL2C_MarkHandler__(Calculator_NumericNode* this__);
extern /* internalcall */ void* __Calculator_NumericNode_IL2C_RuntimeCast__(Calculator_NumericNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Calculator_NumericNode__ctor(Calculator_NumericNode* this__, int32_t numeric, int32_t nextIndex);
extern /* virtual */ int32_t __Calculator_NumericNode_Reduce__(Calculator_NumericNode* this__);

// [2-5] Virtual methods: Calculator.NumericNode

#define Calculator_NumericNode_ToString(/* Calculator_NumericNode */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Calculator_NumericNode_GetHashCode(/* Calculator_NumericNode */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Calculator_NumericNode_Finalize(/* Calculator_NumericNode */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Calculator_NumericNode_Equals(/* Calculator_NumericNode */ this__, /* Calculator_NumericNode */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define Calculator_NumericNode_Reduce(/* Calculator_NumericNode */ this__) \
    ((this__)->vptr0__->Reduce(this__))
#define Calculator_NumericNode_Reduce(/* Calculator_NumericNode */ this__) \
    ((this__)->vptr0__->Reduce(this__))

// [2-4] Member methods: Calculator.ExpressionNode

extern /* internalcall */ void __Calculator_ExpressionNode_IL2C_MarkHandler__(Calculator_ExpressionNode* this__);
extern /* internalcall */ void* __Calculator_ExpressionNode_IL2C_RuntimeCast__(Calculator_ExpressionNode* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Calculator_ExpressionNode__ctor(Calculator_ExpressionNode* this__, Calculator_OperatorNode* oper, Calculator_ReducibleNode* left, Calculator_ReducibleNode* right, int32_t nextIndex);
extern /* virtual */ int32_t __Calculator_ExpressionNode_Reduce__(Calculator_ExpressionNode* this__);

// [2-5] Virtual methods: Calculator.ExpressionNode

#define Calculator_ExpressionNode_ToString(/* Calculator_ExpressionNode */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Calculator_ExpressionNode_GetHashCode(/* Calculator_ExpressionNode */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Calculator_ExpressionNode_Finalize(/* Calculator_ExpressionNode */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Calculator_ExpressionNode_Equals(/* Calculator_ExpressionNode */ this__, /* Calculator_ExpressionNode */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))
#define Calculator_ExpressionNode_Reduce(/* Calculator_ExpressionNode */ this__) \
    ((this__)->vptr0__->Reduce(this__))
#define Calculator_ExpressionNode_Reduce(/* Calculator_ExpressionNode */ this__) \
    ((this__)->vptr0__->Reduce(this__))

// [2-4] Member methods: Calculator.PolishNotation

extern /* internalcall */ void __Calculator_PolishNotation_IL2C_MarkHandler__(Calculator_PolishNotation* this__);
extern /* internalcall */ void* __Calculator_PolishNotation_IL2C_RuntimeCast__(Calculator_PolishNotation* this__, IL2C_RUNTIME_TYPE_DECL* type);
extern void Calculator_PolishNotation_Main();
extern void Calculator_PolishNotation__ctor(Calculator_PolishNotation* this__);

// [2-5] Virtual methods: Calculator.PolishNotation

#define Calculator_PolishNotation_ToString(/* Calculator_PolishNotation */ this__) \
    ((this__)->vptr0__->ToString(this__))
#define Calculator_PolishNotation_GetHashCode(/* Calculator_PolishNotation */ this__) \
    ((this__)->vptr0__->GetHashCode(this__))
#define Calculator_PolishNotation_Finalize(/* Calculator_PolishNotation */ this__) \
    ((this__)->vptr0__->Finalize(this__))
#define Calculator_PolishNotation_Equals(/* Calculator_PolishNotation */ this__, /* Calculator_PolishNotation */ obj) \
    ((this__)->vptr0__->Equals(this__, obj))

#ifdef __cplusplus
}
#endif

#endif
