using System;

using Mono.Cecil;
using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal sealed class LdftnConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Ldftn;

        public override Func<IExtractContext, string[]> Apply(
            MethodReference operand, DecodeContext decodeContext)
        {
            var symbolName = decodeContext.PushStack(decodeContext.Module.GetSafeIntPtrType());

            return _ => new[] { string.Format(
                "{0} = {1}",
                symbolName,
                operand.GetFullMemberName(MethodNameTypes.Index)
                    .ManglingSymbolName()) };
        }
    }
}
