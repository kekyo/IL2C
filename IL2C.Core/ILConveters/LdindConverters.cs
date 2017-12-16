using System;

using Mono.Cecil.Cil;
using Mono.Cecil.Rocks;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal sealed class Ldind_u1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_U1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();

            var targetType = decodeContext.Module.GetSafeByteType();
            var symbolName = decodeContext.PushStack(targetType.GetStackableType());

            return extractContext => new[] { string.Format(
                "{0} = *((uint8_t*){1})",
                symbolName,
                siFrom.SymbolName) };

        }
    }
}
