using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal sealed class AddConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Add;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            // https://msdn.microsoft.com/en-us/library/system.reflection.emit.opcodes.add(v=vs.100).aspx
            if ((CecilHelper.Int32Type.MemberEquals(si0.TargetType))
                && (CecilHelper.Int32Type.MemberEquals(si1.TargetType)))
            {
                var resultName = decodeContext.PushStack(CecilHelper.Int32Type);
                return _ => new[] { string.Format("{0} = {1} + {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }
            if ((CecilHelper.Int64Type.MemberEquals(si0.TargetType))
                && (CecilHelper.Int64Type.MemberEquals(si1.TargetType)))
            {
                var resultName = decodeContext.PushStack(CecilHelper.Int64Type);
                return _ => new[] { string.Format("{0} = {1} + {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown add operation: Offset={0}, Type0={1}, Type1={2}",
                decodeContext.Current.Offset,
                si0.TargetType.FullName,
                si1.TargetType.FullName);
        }
    }
}
