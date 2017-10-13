using System;
using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class NopConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Nop;

        public override string Apply(DecodeContext decodeContext)
        {
            return null;
        }
    }

    internal sealed class RetConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ret;

        public override bool IsEndOfPath => true;

        public override string Apply(DecodeContext decodeContext)
        {
            if (decodeContext.ReturnType == typeof(void))
            {
                return "return";
            }

            var si = decodeContext.PopStack();
            var returnType = decodeContext.ReturnType;

            var rightExpression = decodeContext.TranslateContext.GetRightExpression(returnType, si);
            if (rightExpression == null)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid return operation: ILByteIndex={0}, StackType={1}, ReturnType={2}",
                    decodeContext.ILByteIndex,
                    si.TargetType.FullName,
                    returnType.FullName);
            }

            return string.Format(
                "return {0}",
                rightExpression);
        }

        internal sealed class InitobjConverter : InlineTypeConverter
        {
            public override OpCode OpCode => OpCodes.Initobj;

            public override string Apply(int typeToken, DecodeContext decodeContext)
            {
                try
                {
                    var type = decodeContext.ResolveType(typeToken);

                    var si = decodeContext.PopStack();
                    if (si.TargetType.IsByRef == false)
                    {
                        throw new InvalidProgramSequenceException(
                            "Invalid type at stack: ILByteIndex={0}, TokenType={1}, StackType={2}",
                            decodeContext.ILByteIndex,
                            type.FullName,
                            si.TargetType.FullName);
                    }

                    return string.Format(
                        "memset({0}, 0x00, sizeof({1}))",
                        si.SymbolName,
                        decodeContext.TranslateContext.GetCLanguageTypeName(type));
                }
                catch (ArgumentException)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid type token: ILByteIndex={0}, Token={1:x2}",
                        decodeContext.ILByteIndex,
                        typeToken);
                }
            }
        }

    }
}
