using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class Stloc_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_0;

        public override string Apply(DecodeContext context)
        {
            var si = context.PopStack();
            var localType = context.Locals[0].LocalType;
            if (localType.IsAssignableFrom(si.TargetType) == false)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid store operation: TargetIndex={0}, StackType={1}, LocalType={1}",
                    context.TargetIndex,
                    si.TargetType.FullName,
                    localType.FullName);
            }

            return string.Format("local0 = {0}", si.SymbolName);
        }
    }

    internal sealed class Stloc_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_1;

        public override string Apply(DecodeContext context)
        {
            var si = context.PopStack();
            var localType = context.Locals[1].LocalType;
            if (localType.IsAssignableFrom(si.TargetType) == false)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid store operation: TargetIndex={0}, StackType={1}, LocalType={1}",
                    context.TargetIndex,
                    si.TargetType.FullName,
                    localType.FullName);
            }

            return string.Format("local1 = {0}", si.SymbolName);
        }
    }

    internal sealed class Stloc_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_2;

        public override string Apply(DecodeContext context)
        {
            var si = context.PopStack();
            var localType = context.Locals[2].LocalType;
            if (localType.IsAssignableFrom(si.TargetType) == false)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid store operation: TargetIndex={0}, StackType={1}, LocalType={1}",
                    context.TargetIndex,
                    si.TargetType.FullName,
                    localType.FullName);
            }

            return string.Format("local2 = {0}", si.SymbolName);
        }
    }

    internal sealed class Stloc_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_3;

        public override string Apply(DecodeContext context)
        {
            var si = context.PopStack();
            var localType = context.Locals[3].LocalType;
            if (localType.IsAssignableFrom(si.TargetType) == false)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid store operation: TargetIndex={0}, StackType={1}, LocalType={1}",
                    context.TargetIndex,
                    si.TargetType.FullName,
                    localType.FullName);
            }

            return string.Format("local3 = {0}", si.SymbolName);
        }
    }
}
