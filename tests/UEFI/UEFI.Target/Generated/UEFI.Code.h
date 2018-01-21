#ifndef __MODULE_UEFI_Code__
#define __MODULE_UEFI_Code__

#include <il2c.h>
#include <wchar.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:

typedef struct UEFI_Code_OperatorResult UEFI_Code_OperatorResult;
typedef struct UEFI_Code_NumericResult UEFI_Code_NumericResult;
typedef struct UEFI_Code_PolishNotation UEFI_Code_PolishNotation;

////////////////////////////////////////////////////////////
// Struct: UEFI.Code.OperatorResult

struct UEFI_Code_OperatorResult
{
    wchar_t Operator;
    int32_t Index;
};

extern const __RUNTIME_TYPE__ __UEFI_Code_OperatorResult_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Struct: UEFI.Code.NumericResult

struct UEFI_Code_NumericResult
{
    int32_t Numeric;
    int32_t Index;
};

extern const __RUNTIME_TYPE__ __UEFI_Code_NumericResult_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.PolishNotation


extern const __RUNTIME_TYPE__ __UEFI_Code_PolishNotation_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:




//////////////////////////////////////////////////////////////////////////////////
// Methods:

extern void UEFI_Code_OperatorResult__ctor(UEFI_Code_OperatorResult* __this, wchar_t oper, int32_t index);

extern void UEFI_Code_NumericResult__ctor(UEFI_Code_NumericResult* __this, int32_t numeric, int32_t index);

extern int32_t UEFI_Code_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex);
extern UEFI_Code_OperatorResult UEFI_Code_PolishNotation_ParseOperator(System_String* line, int32_t startIndex);
extern UEFI_Code_NumericResult UEFI_Code_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex);
extern void UEFI_Code_PolishNotation_Main(void);
extern void UEFI_Code_PolishNotation__ctor(UEFI_Code_PolishNotation* __this);

#ifdef __cplusplus
}
#endif

#endif
