using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal sealed class CgtConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Cgt;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            if (si0.TargetType.IsNumericPrimitive()
                && si1.TargetType.IsNumericPrimitive())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeInt32Type());
                return _ => new[] { string.Format(
                    "{0} = ({1} > {2}) ? 1 : 0",
                    resultName,
                    si0.SymbolName,
                    si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown cgt operation: Offset={0}, Type0={1}, Type1={2}",
                decodeContext.Current.Offset,
                si0.TargetType.FullName,
                si1.TargetType.FullName);
        }
    }

    internal sealed class CltConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Clt;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            if (si0.TargetType.IsNumericPrimitive()
                && si1.TargetType.IsNumericPrimitive())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeInt32Type());
                return _ => new[] { string.Format(
                    "{0} = ({1} < {2}) ? 1 : 0",
                    resultName,
                    si0.SymbolName,
                    si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown clt operation: Offset={0}, Type0={1}, Type1={2}",
                decodeContext.Current.Offset,
                si0.TargetType.FullName,
                si1.TargetType.FullName);
        }
    }

    internal sealed class CeqConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ceq;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            if (si0.TargetType.IsNumericPrimitive()
                && si1.TargetType.IsNumericPrimitive())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeInt32Type());
                return _ => new[] { string.Format(
                    "{0} = ({1} == {2}) ? 1 : 0",
                    resultName,
                    si0.SymbolName,
                    si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown cgt operation: Offset={0}, Type0={1}, Type1={2}",
                decodeContext.Current.Offset,
                si0.TargetType.FullName,
                si1.TargetType.FullName);
        }
    }

}
