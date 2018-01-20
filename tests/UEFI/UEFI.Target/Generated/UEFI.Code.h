#ifndef __MODULE_UEFI_Code__
#define __MODULE_UEFI_Code__

#include <il2c.h>
#include <wchar.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// Types:

typedef struct UEFI_Code_Expression UEFI_Code_Expression;
typedef struct UEFI_Code_PolishNotation UEFI_Code_PolishNotation;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.Expression

struct UEFI_Code_Expression
{
    UEFI_Code_Expression* Lhs;
    UEFI_Code_Expression* Rhs;
    wchar_t Oper;
};

extern const __RUNTIME_TYPE__ __UEFI_Code_Expression_RUNTIME_TYPE__;

////////////////////////////////////////////////////////////
// Class: UEFI.Code.PolishNotation


extern const __RUNTIME_TYPE__ __UEFI_Code_PolishNotation_RUNTIME_TYPE__;

//////////////////////////////////////////////////////////////////////////////////
// Public static fields:



//////////////////////////////////////////////////////////////////////////////////
// Methods:

extern void UEFI_Code_Expression__ctor(UEFI_Code_Expression* __this, UEFI_Code_Expression* lhs, UEFI_Code_Expression* rhs, wchar_t oper);

extern UEFI_Code_Expression* UEFI_Code_PolishNotation_Parse(System_String* line, int32_t startIndex);
extern void UEFI_Code_PolishNotation_Main(void);
extern void UEFI_Code_PolishNotation__ctor(UEFI_Code_PolishNotation* __this);

#ifdef __cplusplus
}
#endif

#endif
