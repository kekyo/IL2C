using System;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C.ILConverters
{
    internal sealed class LdftnConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Ldftn;

        public override Func<IExtractContext, string[]> Apply(
            IMethodInformation operand, DecodeContext decodeContext)
        {
            var symbolName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);

            return _ => new[] { string.Format(
                "{0} = {1}",
                symbolName,
                operand.MangledName) };
        }
    }
}
