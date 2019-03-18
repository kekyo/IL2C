// [14-1] This is Calculator.Core native code translated by IL2C, do not edit.

#include <Calculator.Core.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////
// [14-2] Type pre definitions:

////////////////////////////////////////////////////////////
// [2-1-1] .NET types:

/* public class */ typedef struct Calculator_PolishNotation Calculator_PolishNotation;

////////////////////////////////////////////////////////////
// [2-1-2] VTable types:

typedef System_Object_VTABLE_DECL__ Calculator_PolishNotation_VTABLE_DECL__;

///////////////////////////////////////////////////////////////////////////
// [14-3] Type body definitions:

#ifdef Calculator_Core_DECL_TYPE_BODY__

////////////////////////////////////////////////////////////
// [1] Calculator.PolishNotation

// [1-1-2] Class layout
/* public class */ struct Calculator_PolishNotation
{
    Calculator_PolishNotation_VTABLE_DECL__* vptr0__;
};

// [1-5-1] VTable (Same as System.Object)
#define Calculator_PolishNotation_VTABLE__ System_Object_VTABLE__

// [1-4] Runtime type information
IL2C_DECLARE_RUNTIME_TYPE(Calculator_PolishNotation);

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods: Calculator.PolishNotation

extern /* internal static */ int32_t Calculator_PolishNotation_SkipWhiteSpace(System_String* line, int32_t startIndex);
extern /* internal static */ Calculator_OperatorNode* Calculator_PolishNotation_ParseOperator(System_String* line, int32_t startIndex);
extern /* internal static */ Calculator_NumericNode* Calculator_PolishNotation_ParseNumeric(System_String* line, int32_t startIndex);
extern /* internal static */ Calculator_ExpressionNode* Calculator_PolishNotation_ParseExpression(System_String* line, int32_t startIndex);
extern /* public static */ void Calculator_PolishNotation_Main(void);
extern /* public */ void Calculator_PolishNotation__ctor(Calculator_PolishNotation* this__);

#endif

#ifdef __cplusplus
}
#endif
