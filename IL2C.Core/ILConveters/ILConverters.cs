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

            return extractContext =>
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

    internal sealed class CastclassConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Castclass;

        public override Func<IExtractContext, string[]> Apply(
            ITypeInformation operand, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            var symbolName = decodeContext.PushStack(operand);

            // If this type can cast statically
            if (operand.IsAssignableFrom(si.TargetType))
            {
                return extractContext =>
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
                return extractContext =>
                {
                    return new[] { string.Format(
                        "{0} = il2c_runtime_cast({1}, {2})",
                        symbolName,
                        si.SymbolName,
                        operand.MangledName) };
                };
            }
        }
    }
}
