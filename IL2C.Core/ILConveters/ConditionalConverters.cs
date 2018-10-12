using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class CgtConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Cgt;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            if (si0.TargetType.IsNumericPrimitive
                && si1.TargetType.IsNumericPrimitive)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
                return _ => new[] { string.Format(
                    "{0} = ({1} > {2}) ? 1 : 0",
                    resultName,
                    si0.SymbolName,
                    si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown cgt operation: Location={0}, Type0={1}, Type1={2}",
                decodeContext.CurrentCode.RawLocation,
                si0.TargetType.FriendlyName,
                si1.TargetType.FriendlyName);
        }
    }

    internal sealed class CltConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Clt;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            if (si0.TargetType.IsNumericPrimitive
                && si1.TargetType.IsNumericPrimitive)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
                return _ => new[] { string.Format(
                    "{0} = ({1} < {2}) ? 1 : 0",
                    resultName,
                    si0.SymbolName,
                    si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown clt operation: Location={0}, Type0={1}, Type1={2}",
                decodeContext.CurrentCode.RawLocation,
                si0.TargetType.FriendlyName,
                si1.TargetType.FriendlyName);
        }
    }

    internal sealed class CeqConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ceq;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);

            if (si0.TargetType.IsNumericPrimitive
                && si1.TargetType.IsNumericPrimitive)
            {
                return _ => new[] { string.Format(
                    "{0} = ({1} == {2}) ? 1 : 0",
                    resultName,
                    si0.SymbolName,
                    si1.SymbolName) };
            }

            return extractContext =>
            {
                var rhsExpr = extractContext.GetRightExpression(si0.TargetType, si1);
                if (rhsExpr == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Unknown cgt operation: Location={0}, Type0={1}, Type1={2}",
                        decodeContext.CurrentCode.RawLocation,
                        si0.TargetType.FriendlyName,
                        si1.TargetType.FriendlyName);
                }

                return new[] { string.Format(
                    "{0} = ({1} == ({2})) ? 1 : 0",
                    resultName,
                    si0.SymbolName,
                    rhsExpr) };
            };
        }
    }
}
