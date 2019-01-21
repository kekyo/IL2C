using System;
using System.Diagnostics;

using Mono.Cecil.Cil;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class NopConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Nop;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return emptyFunc;
        }
    }

    internal sealed class BreakConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Break;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return _ => new[] { "il2c_break()" };
        }
    }

    internal sealed class RetConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ret;

        public override bool IsEndOfPath => true;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            if (decodeContext.Method.ReturnType.IsVoidType)
            {
                return _ => new[] { "return" };
            }

            var si = decodeContext.PopStack();
            var returnType = decodeContext.Method.ReturnType;

            var codeInformation = decodeContext.CurrentCode;

            return extractContext =>
            {
                var rightExpression = extractContext.GetRightExpression(returnType, si);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid return operation: Location={0}, StackType={1}, ReturnType={2}",
                        codeInformation.RawLocation,
                        si.TargetType.FriendlyName,
                        returnType.FriendlyName);
                }

                return new[] { string.Format(
                    "return {0}",
                    rightExpression) };
            };
        }
    }

    internal sealed class ThrowConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Throw;

        public override bool IsEndOfPath => true;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            if (!si.TargetType.IsException)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid throw type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    si.TargetType.FriendlyName);
            }

            return extractContext => new[] {
                string.Format(
                    "il2c_throw({0})",
                    extractContext.GetSymbolName(si)) };
        }
    }

    internal sealed class RethrowConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Rethrow;

        public override bool IsEndOfPath => true;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return _ => new[] { "il2c_rethrow()" };
        }
    }

    internal sealed class Leave_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Leave_S;

        public override bool IsEndOfPath => true;

        public override Func<IExtractContext, string[]> Apply(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            // Strategy:
            //   The exception handlers have to use "leave" opcode to exit.
            //   It will be transition to finally block if declared.
            //   AND, continue to operand label (therefore it delayed evaluation.)
            //   The AssemblyWriter will write these fragments by labelName side-by-side declared continuationIndex.

            decodeContext.EnqueueNewPath(operand.Offset);
            var continuationIndex = decodeContext.RegisterLeaveContinuation(
                decodeContext.CurrentCode.Offset, operand.Offset);

            return extractContext =>
            {
                var nestedIndexName = extractContext.GetExceptionNestedFrameIndexName();

                return new[] { string.Format(
                    "il2c_leave({0}, {1})",
                    nestedIndexName,
                    continuationIndex) };
            };
        }
    }

    internal sealed class EndfinallyConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Endfinally;

        public override bool IsEndOfPath => true;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            // Finally exit block fragment totally will write by AssemblyWriter.
            return extractContext =>
            {
                var nestedIndexName = extractContext.GetExceptionNestedFrameIndexName();

                return new[] { string.Format(
                    "il2c_endfinally({0})",
                    nestedIndexName) };
            };
        }
    }

    internal sealed class LdstrConverter : InlineStringConverter
    {
        public override OpCode OpCode => OpCodes.Ldstr;

        public override Func<IExtractContext, string[]> Apply(
            string operand, DecodeContext decodeContext)
        {
            var symbol = decodeContext.PushStack(
                decodeContext.PrepareContext.MetadataContext.StringType);
            var constStringName = decodeContext.PrepareContext.
                RegisterConstString(operand);

            return extractContext =>
            {
                return new[] { string.Format(
                    "{0} = {1}",
                    extractContext.GetSymbolName(symbol),
                    constStringName) };
            };
        }
    }

    internal sealed class LdnullConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldnull;

        public override Func<IExtractContext, string[]> Apply(
            DecodeContext decodeContext)
        {
            // NOTE: ldnull pushes the "UntypedReferenceType."
            //   Because we can't understand whats the objref type at now.
            //   The "UntypedReferenceType" is pseudo type information.
            //   It will be resolved at later if using for GetRightExpression method.
            var symbol = decodeContext.PushStack(
                decodeContext.PrepareContext.MetadataContext.UntypedReferenceType);

            return extractContext => new[] { string.Format(
                "{0} = NULL",
                extractContext.GetSymbolName(symbol)) };
        }
    }

    internal sealed class DupConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Dup;

        public override Func<IExtractContext, string[]> Apply(
            DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            var symbol0 = decodeContext.PushStack(si.TargetType);

            Debug.Assert(si.Equals(symbol0));

            var symbol1 = decodeContext.PushStack(
                si.TargetType);

            return extractContext => new[] { string.Format(
                "{0} = {1}",
                extractContext.GetSymbolName(symbol1),
                extractContext.GetSymbolName(si)) };
        }
    }

    internal sealed class PopConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Pop;

        public override Func<IExtractContext, string[]> Apply(
            DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            return _ => new string[0];
        }
    }

    internal static class IsinstConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
            ITypeInformation operand, DecodeContext decodeContext, bool check)
        {
            var si = decodeContext.PopStack();
            if (si.TargetType.IsValueType || si.TargetType.IsByReference || si.TargetType.IsPointer)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid {0} operation: Location={1}, StackType={2}",
                    check ? "castclass" : "isinst",
                    decodeContext.CurrentCode.RawLocation,
                    si.TargetType.FriendlyName);
            }

            // It's maybe boxed objref if operand is value type.
            var resultType = operand.IsValueType ?
                decodeContext.PrepareContext.MetadataContext.ValueTypeType :
                operand;
            var symbol = decodeContext.PushStack(resultType);

            // If this type can cast statically:
            if (operand.IsAssignableFrom(si.TargetType))
            {
                // To interface type
                if (operand.IsInterface)
                {
                    return extractContext =>
                    {
                        return new[] { string.Format(
                        "{0} = il2c_cast_to_interface({1}, {2}, {3})",
                        extractContext.GetSymbolName(symbol),
                        operand.MangledUniqueName,
                        si.TargetType.MangledUniqueName,
                        extractContext.GetSymbolName(si)) };
                    };
                }
                else
                {
                    return extractContext =>
                    {
                        return new[] { string.Format(
                        "{0} = ({1}){2}",
                        extractContext.GetSymbolName(symbol),
                        operand.CLanguageTypeName,
                        extractContext.GetSymbolName(si)) };
                    };
                }
            }

            return extractContext =>
            {
                return new[] { string.Format(
                    "{0} = {1}({2}, {3})",
                    extractContext.GetSymbolName(symbol),
                    check ? "il2c_castclass" : "il2c_isinst",
                    extractContext.GetSymbolName(si),
                    operand.MangledUniqueName) };
            };
        }
    }

    internal sealed class IsinstConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Isinst;

        public override Func<IExtractContext, string[]> Apply(
            ITypeInformation operand, DecodeContext decodeContext)
        {
            return IsinstConverterUtilities.Apply(
                operand, decodeContext, false);
        }
    }

    internal sealed class CastclassConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Castclass;

        public override Func<IExtractContext, string[]> Apply(
            ITypeInformation operand, DecodeContext decodeContext)
        {
            return IsinstConverterUtilities.Apply(
                operand, decodeContext, true);
        }
    }

    internal sealed class SizeofConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Sizeof;

        public override Func<IExtractContext, string[]> Apply(
            ITypeInformation operand, DecodeContext decodeContext)
        {
            // ECMA-335 III.4.25 sizeof - load the size, in bytes,of a type 
            //   sizeof opcode has to push size by UInt32 (not Int32.)
            var symbol = decodeContext.PushStack(
                decodeContext.PrepareContext.MetadataContext.UInt32Type);

            return extractContext =>
            {
                return new[] { string.Format(
                    "{0} = il2c_sizeof({1})",
                    extractContext.GetSymbolName(symbol),
                    operand.MangledUniqueName) };
            };
        }
    }
}
