using System;

using Mono.Cecil.Cil;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class NopConverter : InlineNoneConverter
    {
        private static readonly string[] empty = new string[0];
        private static readonly Func<IExtractContext, string[]> emptyFunc = _ => empty;

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

            decodeContext.PrepareContext.RegisterType(returnType);

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

            return _ => new[] { string.Format(
                "il2c_throw({0})",
                si.SymbolName) };
        }
    }

    internal sealed class Leave_sConverter : ShortInlineBrTargetConverter
    {
        public override OpCode OpCode => OpCodes.Leave_S;

        public override bool IsEndOfPath => true;

        public override Func<IExtractContext, string[]> Apply(
            ICodeInformation operand, DecodeContext decodeContext)
        {
            var labelName = decodeContext.EnqueueNewPath(operand.Offset);

            return _ => new[] { string.Format("il2c_leave({0})", labelName) };
        }
    }

    internal sealed class LdstrConverter : InlineStringConverter
    {
        public override OpCode OpCode => OpCodes.Ldstr;

        public override Func<IExtractContext, string[]> Apply(
            string operand, DecodeContext decodeContext)
        {
            var symbolName = decodeContext.PushStack(
                decodeContext.PrepareContext.MetadataContext.StringType);
            var constStringName = decodeContext.PrepareContext
                .RegisterConstString(operand);

            return _ =>
            {
                return new[] { string.Format(
                    "{0} = {1}",
                    symbolName,
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
            // MEMO: ldnull pushes the "UntypedReferenceType."
            //   Because we can't understand whats the objref type at now.
            //   The "UntypedReferenceType" is pseudo type information.
            //   It will be resolved at later if using for GetRightExpression method.
            var symbolName = decodeContext.PushStack(
                decodeContext.PrepareContext.MetadataContext.UntypedReferenceType);

            return _ => new[] { string.Format(
                "{0} = NULL",
                symbolName) };
        }
    }

    internal sealed class DupConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Dup;

        public override Func<IExtractContext, string[]> Apply(
            DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            decodeContext.PushStack(si.TargetType);

            var symbolName1 = decodeContext.PushStack(
                si.TargetType);

            return _ => new[] { string.Format(
                "{0} = {1}",
                symbolName1,
                si.SymbolName) };
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

    internal sealed class IsinstConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Isinst;

        public override Func<IExtractContext, string[]> Apply(
            ITypeInformation operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            if (si.TargetType.IsValueType || si.TargetType.IsByReference || si.TargetType.IsPointer)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid isinst operation: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    si.TargetType.FriendlyName);
            }

            // It's maybe boxed objref if operand is value type.
            var resultType = operand.IsValueType ?
                decodeContext.PrepareContext.MetadataContext.ValueTypeType :
                operand;
            var symbolName = decodeContext.PushStack(resultType);

            // If this type can cast statically
            if (operand.IsAssignableFrom(si.TargetType))
            {
                return _ =>
                {
                    return new[] { string.Format(
                        "{0} = ({1}){2}",
                        symbolName,
                        operand.CLanguageTypeName,
                        si.SymbolName) };
                };
            }
            else
            {
                return _ =>
                {
                    return new[] { string.Format(
                        "{0} = il2c_isinst({1}, {2})",
                        symbolName,
                        si.SymbolName,
                        operand.MangledName) };
                };
            }
        }
    }

    internal sealed class CastclassConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Castclass;

        public override Func<IExtractContext, string[]> Apply(
            ITypeInformation operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            if (si.TargetType.IsValueType || si.TargetType.IsByReference || si.TargetType.IsPointer)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid isinst operation: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    si.TargetType.FriendlyName);
            }

            // It's maybe boxed objref if operand is value type.
            var resultType = operand.IsValueType ?
                decodeContext.PrepareContext.MetadataContext.ValueTypeType :
                operand;
            var symbolName = decodeContext.PushStack(resultType);

            // If this type can cast statically
            if (operand.IsAssignableFrom(si.TargetType))
            {
                return _ =>
                {
                    return new[] { string.Format(
                        "{0} = ({1}){2}",
                        symbolName,
                        operand.CLanguageTypeName,
                        si.SymbolName) };
                };
            }
            else
            {
                return _ =>
                {
                    return new[] { string.Format(
                        "{0} = il2c_isinst({1}, {2})",
                        symbolName,
                        si.SymbolName,
                        operand.MangledName) };
                };
            }
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
            var symbolName = decodeContext.PushStack(
                decodeContext.PrepareContext.MetadataContext.UInt32Type);

            return extractContext =>
            {
                return new[] { string.Format(
                    "{0} = il2c_sizeof({1})",
                    symbolName,
                    operand.MangledName) };
            };
        }
    }
}
