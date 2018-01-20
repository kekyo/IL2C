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
            if (si0.TargetType.IsInt32Type() && si1.TargetType.IsInt32Type())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeInt32Type());
                return _ => new[] { string.Format(
                    "{0} = {1} + {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }
            if (si0.TargetType.IsInt64Type() && si1.TargetType.IsInt64Type())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeInt64Type());
                return _ => new[] { string.Format(
                    "{0} = {1} + {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            if (si0.TargetType.IsPointer && si1.TargetType.IsInt32Type())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeIntPtrType());
                return _ => new[] { string.Format(
                    "{0} = ((intptr_t){1}) + ((intptr_t){2})", resultName, si0.SymbolName, si1.SymbolName) };
            }

            if (si0.TargetType.IsPointer && si1.TargetType.IsIntPtrType())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeIntPtrType());
                return _ => new[] { string.Format(
                    "{0} = ((intptr_t){1}) + {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            if (si0.TargetType.IsIntPtrType() && si1.TargetType.IsInt32Type())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeIntPtrType());
                return _ => new[] { string.Format(
                    "{0} = {1} + ((intptr_t){2})", resultName, si0.SymbolName, si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown add operation: Offset={0}, Type0={1}, Type1={2}",
                decodeContext.Current.Offset,
                si0.TargetType.FullName,
                si1.TargetType.FullName);
        }
    }

    internal sealed class SubConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Sub;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            // TODO: Check these combinations
            if (si0.TargetType.IsInt32Type() && si1.TargetType.IsInt32Type())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeInt32Type());
                return _ => new[] { string.Format(
                    "{0} = {1} - {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }
            if (si0.TargetType.IsInt64Type() && si1.TargetType.IsInt64Type())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeInt64Type());
                return _ => new[] { string.Format(
                    "{0} = {1} - {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            if (si0.TargetType.IsPointer && si1.TargetType.IsInt32Type())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeIntPtrType());
                return _ => new[] { string.Format(
                    "{0} = ((intptr_t){1}) - ((intptr_t){2})", resultName, si0.SymbolName, si1.SymbolName) };
            }

            if (si0.TargetType.IsPointer && si1.TargetType.IsIntPtrType())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeIntPtrType());
                return _ => new[] { string.Format(
                    "{0} = ((intptr_t){1}) - {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            if (si0.TargetType.IsIntPtrType() && si1.TargetType.IsInt32Type())
            {
                var resultName = decodeContext.PushStack(decodeContext.Module.GetSafeIntPtrType());
                return _ => new[] { string.Format(
                    "{0} = {1} - ((intptr_t){2})", resultName, si0.SymbolName, si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown sub operation: Offset={0}, Type0={1}, Type1={2}",
                decodeContext.Current.Offset,
                si0.TargetType.FullName,
                si1.TargetType.FullName);
        }
    }
}
