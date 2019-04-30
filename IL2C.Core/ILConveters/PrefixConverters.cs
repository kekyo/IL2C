using System;
using System.Diagnostics;

using Mono.Cecil.Cil;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class ConstrainedConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Constrained;

        public override ExpressionEmitter Prepare(
            ITypeInformation type, DecodeContext decodeContext)
        {
            decodeContext.SetPrefixCode();

            return emptyEmitter;
        }
    }
}
