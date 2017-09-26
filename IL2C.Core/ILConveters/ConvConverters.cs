using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class Conv_i8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_I8;

        public override string Apply(DecodeContext context)
        {
            var siBefore = context.PopStack();
            var resultName = context.PushStack(typeof(long));

            // Ignore emit source code if symbol not changed.
            if (siBefore.SymbolName == resultName)
            {
                return null;
            }

            return string.Format("{0} = (int64_t){1};", resultName, siBefore.SymbolName);
        }
    }
}
