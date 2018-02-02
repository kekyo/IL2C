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

struct UEFI_Code_AbstractNode
{
    int32_t NextIndex;
};

extern const IL2C_RUNTIME_TYPE __UEFI_Code_AbstractNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.OperatorNode

struct UEFI_Code_OperatorNode
{
    int32_t NextIndex;
    wchar_t Operator;
};

extern const IL2C_RUNTIME_TYPE __UEFI_Code_OperatorNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.ReducibleNode

struct UEFI_Code_ReducibleNode
{
    int32_t NextIndex;
};

extern const IL2C_RUNTIME_TYPE __UEFI_Code_ReducibleNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.NumericNode

struct UEFI_Code_NumericNode
{
    int32_t NextIndex;
    int32_t Numeric;
};

extern const IL2C_RUNTIME_TYPE __UEFI_Code_NumericNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.ExpressionNode

struct UEFI_Code_ExpressionNode
{
    int32_t NextIndex;
    UEFI_Code_OperatorNode* Operator;
    UEFI_Code_ReducibleNode* Left;
    UEFI_Code_ReducibleNode* Right;
};

extern const IL2C_RUNTIME_TYPE __UEFI_Code_ExpressionNode_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.PolishNotation


extern const IL2C_RUNTIME_TYPE __UEFI_Code_PolishNotation_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:







//////////////////////////////////////////////////////////////////////////////////
// Methods:

extern void UEFI_Code_AbstractNode__ctor(UEFI_Code_AbstractNode* this__, int32_t nextIndex);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __UEFI_Code_AbstractNode_TYPE_DEF_TYPE__;


extern void UEFI_Code_OperatorNode__ctor(UEFI_Code_OperatorNode* this__, wchar_t oper, int32_t nextIndex);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __UEFI_Code_OperatorNode_TYPE_DEF_TYPE__;


extern void UEFI_Code_ReducibleNode__ctor(UEFI_Code_ReducibleNode* this__, int32_t nextIndex);
extern int32_t __UEFI_Code_ReducibleNode_Reduce__(UEFI_Code_ReducibleNode* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Reduce)(UEFI_Code_ReducibleNode* this__);
} __UEFI_Code_ReducibleNode_TYPE_DEF_TYPE__;

#define UEFI_Code_ReducibleNode_Reduce(this__) \
    (((__UEFI_Code_ReducibleNode_TYPE_DEF_TYPE__*)(il2c_get_type(this__)))->Reduce(this__))

extern void UEFI_Code_NumericNode__ctor(UEFI_Code_NumericNode* this__, int32_t numeric, int32_t nextIndex);
extern int32_t __UEFI_Code_NumericNode_Reduce__(UEFI_Code_NumericNode* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Reduce)(UEFI_Code_NumericNode* this__);
} __UEFI_Code_NumericNode_TYPE_DEF_TYPE__;

#define UEFI_Code_NumericNode_Reduce(this__) \
    (((__UEFI_Code_NumericNode_TYPE_DEF_TYPE__*)(il2c_get_type(this__)))->Reduce(this__))

extern void UEFI_Code_ExpressionNode__ctor(UEFI_Code_ExpressionNode* this__, UEFI_Code_OperatorNode* oper, UEFI_Code_ReducibleNode* left, UEFI_Code_ReducibleNode* right, int32_t nextIndex);
extern int32_t __UEFI_Code_ExpressionNode_Reduce__(UEFI_Code_ExpressionNode* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
    int32_t (*Reduce)(UEFI_Code_ExpressionNode* this__);
} __UEFI_Code_ExpressionNode_TYPE_DEF_TYPE__;

#define UEFI_Code_ExpressionNode_Reduce(this__) \
    (((__UEFI_Code_ExpressionNode_TYPE_DEF_TYPE__*)(il2c_get_type(this__)))->Reduce(this__))

extern int32_t UEFI_Code_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex);
extern UEFI_Code_OperatorNode* UEFI_Code_PolishNotation_ParseOperator(System_String* line, int32_t startIndex);
extern UEFI_Code_NumericNode* UEFI_Code_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex);
extern UEFI_Code_ExpressionNode* UEFI_Code_PolishNotation_ParseExpression(System_String* line, int32_t startIndex);
extern void UEFI_Code_PolishNotation_Main(void);
extern void UEFI_Code_PolishNotation__ctor(UEFI_Code_PolishNotation* this__);

typedef const struct
{
    intptr_t reserved0__;
    intptr_t reserved1__;
    intptr_t reserved2__;
    System_String* (*ToString)(System_Object* this__);
    int32_t (*GetHashCode)(System_Object* this__);
    void (*Finalize)(System_Object* this__);
    bool (*Equals)(System_Object* this__, System_Object* obj);
} __UEFI_Code_PolishNotation_TYPE_DEF_TYPE__;


#ifdef __cplusplus
}
#endif

#endif
