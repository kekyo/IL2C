using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class NopConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Nop;

        public override string Apply(DecodeContext context)
        {
            return null;
        }
    }

    internal sealed class RetConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ret;

        public override string Apply(DecodeContext context)
        {
            var si = context.PopStack();
            return string.Format("return {0};", si.SymbolName);
        }
    }
}
