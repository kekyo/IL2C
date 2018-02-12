#ifndef __MODULE_UEFI_Code__
#define __MODULE_UEFI_Code__

#include <il2c.h>
#include <stdint.h>
#include <wchar.h>
#include <stdbool.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:

typedef struct UEFI_Code_AbstractNode UEFI_Code_AbstractNode;
typedef struct UEFI_Code_OperatorNode UEFI_Code_OperatorNode;
typedef struct UEFI_Code_ReducibleNode UEFI_Code_ReducibleNode;
typedef struct UEFI_Code_NumericNode UEFI_Code_NumericNode;
typedef struct UEFI_Code_ExpressionNode UEFI_Code_ExpressionNode;
typedef struct UEFI_Code_PolishNotation UEFI_Code_PolishNotation;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.AbstractNode

typedef const struct
{
    void* (*IL2C_RuntimeCast)(System_Object* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __UEFI_Code_AbstractNode_VTABLE_DECL__;

struct UEFI_Code_AbstractNode
{
    __UEFI_Code_AbstractNode_VTABLE_DECL__* vptr__;

    int32_t NextIndex;
};

extern IL2C_RUNTIME_TYPE_DECL __UEFI_Code_AbstractNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.OperatorNode

typedef const struct
{
    void* (*IL2C_RuntimeCast)(System_Object* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __UEFI_Code_OperatorNode_VTABLE_DECL__;

struct UEFI_Code_OperatorNode
{
    __UEFI_Code_OperatorNode_VTABLE_DECL__* vptr__;

    int32_t NextIndex;
    wchar_t Operator;
};

extern IL2C_RUNTIME_TYPE_DECL __UEFI_Code_OperatorNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.ReducibleNode

typedef const struct
{
    void* (*IL2C_RuntimeCast)(System_Object* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Reduce)(UEFI_Code_ReducibleNode* this__);
} __UEFI_Code_ReducibleNode_VTABLE_DECL__;

struct UEFI_Code_ReducibleNode
{
    __UEFI_Code_ReducibleNode_VTABLE_DECL__* vptr__;

    int32_t NextIndex;
};

extern IL2C_RUNTIME_TYPE_DECL __UEFI_Code_ReducibleNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.NumericNode

typedef const struct
{
    void* (*IL2C_RuntimeCast)(System_Object* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Reduce)(UEFI_Code_NumericNode* this__);
} __UEFI_Code_NumericNode_VTABLE_DECL__;

struct UEFI_Code_NumericNode
{
    __UEFI_Code_NumericNode_VTABLE_DECL__* vptr__;

    int32_t NextIndex;
    int32_t Numeric;
};

extern IL2C_RUNTIME_TYPE_DECL __UEFI_Code_NumericNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.ExpressionNode

typedef const struct
{
    void* (*IL2C_RuntimeCast)(System_Object* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Reduce)(UEFI_Code_ExpressionNode* this__);
} __UEFI_Code_ExpressionNode_VTABLE_DECL__;

struct UEFI_Code_ExpressionNode
{
    __UEFI_Code_ExpressionNode_VTABLE_DECL__* vptr__;

    int32_t NextIndex;
    UEFI_Code_OperatorNode* Operator;
    UEFI_Code_ReducibleNode* Left;
    UEFI_Code_ReducibleNode* Right;
};

extern IL2C_RUNTIME_TYPE_DECL __UEFI_Code_ExpressionNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.PolishNotation

typedef const struct
{
    void* (*IL2C_RuntimeCast)(System_Object* this__, IL2C_RUNTIME_TYPE_DECL* type);
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __UEFI_Code_PolishNotation_VTABLE_DECL__;

struct UEFI_Code_PolishNotation
{
    __UEFI_Code_PolishNotation_VTABLE_DECL__* vptr__;

};

extern IL2C_RUNTIME_TYPE_DECL __UEFI_Code_PolishNotation_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:







//////////////////////////////////////////////////////////////////////////////////
// Methods:

extern void UEFI_Code_AbstractNode__ctor(UEFI_Code_AbstractNode* this__, int32_t nextIndex);
#define UEFI_Code_AbstractNode_ToString(/* UEFI_Code_AbstractNode* */ this__) \
    ((this__)->vptr__->ToString((System_Object*)(this__)))
#define UEFI_Code_AbstractNode_GetHashCode(/* UEFI_Code_AbstractNode* */ this__) \
    ((this__)->vptr__->GetHashCode((System_Object*)(this__)))
#define UEFI_Code_AbstractNode_Finalize(/* UEFI_Code_AbstractNode* */ this__) \
    ((this__)->vptr__->Finalize((System_Object*)(this__)))
#define UEFI_Code_AbstractNode_Equals(/* UEFI_Code_AbstractNode* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr__->Equals((System_Object*)(this__), (obj)))

extern void UEFI_Code_OperatorNode__ctor(UEFI_Code_OperatorNode* this__, wchar_t oper, int32_t nextIndex);
#define UEFI_Code_OperatorNode_ToString(/* UEFI_Code_OperatorNode* */ this__) \
    ((this__)->vptr__->ToString((System_Object*)(this__)))
#define UEFI_Code_OperatorNode_GetHashCode(/* UEFI_Code_OperatorNode* */ this__) \
    ((this__)->vptr__->GetHashCode((System_Object*)(this__)))
#define UEFI_Code_OperatorNode_Finalize(/* UEFI_Code_OperatorNode* */ this__) \
    ((this__)->vptr__->Finalize((System_Object*)(this__)))
#define UEFI_Code_OperatorNode_Equals(/* UEFI_Code_OperatorNode* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr__->Equals((System_Object*)(this__), (obj)))

extern void UEFI_Code_ReducibleNode__ctor(UEFI_Code_ReducibleNode* this__, int32_t nextIndex);
extern int32_t __UEFI_Code_ReducibleNode_Reduce__(UEFI_Code_ReducibleNode* this__);
#define UEFI_Code_ReducibleNode_ToString(/* UEFI_Code_ReducibleNode* */ this__) \
    ((this__)->vptr__->ToString((System_Object*)(this__)))
#define UEFI_Code_ReducibleNode_GetHashCode(/* UEFI_Code_ReducibleNode* */ this__) \
    ((this__)->vptr__->GetHashCode((System_Object*)(this__)))
#define UEFI_Code_ReducibleNode_Finalize(/* UEFI_Code_ReducibleNode* */ this__) \
    ((this__)->vptr__->Finalize((System_Object*)(this__)))
#define UEFI_Code_ReducibleNode_Equals(/* UEFI_Code_ReducibleNode* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr__->Equals((System_Object*)(this__), (obj)))
#define UEFI_Code_ReducibleNode_Reduce(/* UEFI_Code_ReducibleNode* */ this__) \
    ((this__)->vptr__->Reduce((UEFI_Code_ReducibleNode*)(this__)))

extern void UEFI_Code_NumericNode__ctor(UEFI_Code_NumericNode* this__, int32_t numeric, int32_t nextIndex);
extern int32_t __UEFI_Code_NumericNode_Reduce__(UEFI_Code_NumericNode* this__);
#define UEFI_Code_NumericNode_ToString(/* UEFI_Code_NumericNode* */ this__) \
    ((this__)->vptr__->ToString((System_Object*)(this__)))
#define UEFI_Code_NumericNode_GetHashCode(/* UEFI_Code_NumericNode* */ this__) \
    ((this__)->vptr__->GetHashCode((System_Object*)(this__)))
#define UEFI_Code_NumericNode_Finalize(/* UEFI_Code_NumericNode* */ this__) \
    ((this__)->vptr__->Finalize((System_Object*)(this__)))
#define UEFI_Code_NumericNode_Equals(/* UEFI_Code_NumericNode* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr__->Equals((System_Object*)(this__), (obj)))
#define UEFI_Code_NumericNode_Reduce(/* UEFI_Code_NumericNode* */ this__) \
    ((this__)->vptr__->Reduce((UEFI_Code_NumericNode*)(this__)))

extern void UEFI_Code_ExpressionNode__ctor(UEFI_Code_ExpressionNode* this__, UEFI_Code_OperatorNode* oper, UEFI_Code_ReducibleNode* left, UEFI_Code_ReducibleNode* right, int32_t nextIndex);
extern int32_t __UEFI_Code_ExpressionNode_Reduce__(UEFI_Code_ExpressionNode* this__);
#define UEFI_Code_ExpressionNode_ToString(/* UEFI_Code_ExpressionNode* */ this__) \
    ((this__)->vptr__->ToString((System_Object*)(this__)))
#define UEFI_Code_ExpressionNode_GetHashCode(/* UEFI_Code_ExpressionNode* */ this__) \
    ((this__)->vptr__->GetHashCode((System_Object*)(this__)))
#define UEFI_Code_ExpressionNode_Finalize(/* UEFI_Code_ExpressionNode* */ this__) \
    ((this__)->vptr__->Finalize((System_Object*)(this__)))
#define UEFI_Code_ExpressionNode_Equals(/* UEFI_Code_ExpressionNode* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr__->Equals((System_Object*)(this__), (obj)))
#define UEFI_Code_ExpressionNode_Reduce(/* UEFI_Code_ExpressionNode* */ this__) \
    ((this__)->vptr__->Reduce((UEFI_Code_ExpressionNode*)(this__)))

extern int32_t UEFI_Code_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex);
extern UEFI_Code_OperatorNode* UEFI_Code_PolishNotation_ParseOperator(System_String* line, int32_t startIndex);
extern UEFI_Code_NumericNode* UEFI_Code_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex);
extern UEFI_Code_ExpressionNode* UEFI_Code_PolishNotation_ParseExpression(System_String* line, int32_t startIndex);
extern void UEFI_Code_PolishNotation_Main(void);
extern void UEFI_Code_PolishNotation__ctor(UEFI_Code_PolishNotation* this__);
#define UEFI_Code_PolishNotation_ToString(/* UEFI_Code_PolishNotation* */ this__) \
    ((this__)->vptr__->ToString((System_Object*)(this__)))
#define UEFI_Code_PolishNotation_GetHashCode(/* UEFI_Code_PolishNotation* */ this__) \
    ((this__)->vptr__->GetHashCode((System_Object*)(this__)))
#define UEFI_Code_PolishNotation_Finalize(/* UEFI_Code_PolishNotation* */ this__) \
    ((this__)->vptr__->Finalize((System_Object*)(this__)))
#define UEFI_Code_PolishNotation_Equals(/* UEFI_Code_PolishNotation* */ this__, /* System_Object* */ obj) \
    ((this__)->vptr__->Equals((System_Object*)(this__), (obj)))

#ifdef __cplusplus
}
#endif

#endif
