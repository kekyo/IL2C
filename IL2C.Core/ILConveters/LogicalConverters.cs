using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal sealed class AndConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.And;

        public override Func<IExtractContext, string[]> Apply(
            DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            if (si0.TargetType.IsInt32Type() && si1.TargetType.IsInt32Type())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeInt32Type());
                return _ => new[] { string.Format(
                    "{0} = {1} & {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }
            if (si0.TargetType.IsInt64Type() && si1.TargetType.IsInt64Type())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeInt64Type());
                return _ => new[] { string.Format(
                    "{0} = {1} & {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown and operation: Offset={0}, Type0={1}, Type1={2}",
                decodeContext.Current.Offset,
                si0.TargetType.FullName,
                si1.TargetType.FullName);
        }
    }
}
