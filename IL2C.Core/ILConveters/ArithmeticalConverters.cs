using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class AddConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Add;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            // https://msdn.microsoft.com/en-us/library/system.reflection.emit.opcodes.add(v=vs.100).aspx

            // Int32 = Int32 + Int32
            if (si0.TargetType.IsInt32Type && si1.TargetType.IsInt32Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
                return _ => new[] { string.Format(
                    "{0} = {1} + {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            // Int64 = Int64 + Int64
            if (si0.TargetType.IsInt64Type && si1.TargetType.IsInt64Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int64Type);
                return _ => new[] { string.Format(
                    "{0} = {1} + {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            // Double = Double + Double ('F' type)
            if (si0.TargetType.IsDoubleType && si1.TargetType.IsDoubleType)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.DoubleType);
                return _ => new[] { string.Format(
                    "{0} = {1} + {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            // IntPtr = Pointer + Int32
            if (si0.TargetType.IsPointer && si1.TargetType.IsInt32Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return _ => new[] { string.Format(
                    "{0} = ((intptr_t){1}) + ((intptr_t){2})", resultName, si0.SymbolName, si1.SymbolName) };
            }

            // IntPtr = Pointer + IntPtr
            if (si0.TargetType.IsPointer && si1.TargetType.IsIntPtrType)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return _ => new[] { string.Format(
                    "{0} = ((intptr_t){1}) + {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            // IntPtr = IntPtr + Int32
            if (si0.TargetType.IsIntPtrType && si1.TargetType.IsInt32Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return _ => new[] { string.Format(
                    "{0} = {1} + ((intptr_t){2})", resultName, si0.SymbolName, si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown add operation: Location={0}, Type0={1}, Type1={2}",
                decodeContext.CurrentCode.RawLocation,
                si0.TargetType.FriendlyName,
                si1.TargetType.FriendlyName);
        }
    }

    internal sealed class SubConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Sub;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            // Int32 = Int32 - Int32
            if (si0.TargetType.IsInt32Type && si1.TargetType.IsInt32Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
                return _ => new[] { string.Format(
                    "{0} = {1} - {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            // Int64 = Int64 - Int64
            if (si0.TargetType.IsInt64Type && si1.TargetType.IsInt64Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int64Type);
                return _ => new[] { string.Format(
                    "{0} = {1} - {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            // Double = Double - Double ('F' type)
            if (si0.TargetType.IsDoubleType && si1.TargetType.IsDoubleType)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.DoubleType);
                return _ => new[] { string.Format(
                    "{0} = {1} - {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            // IntPtr = Pointer - Int32
            if (si0.TargetType.IsPointer && si1.TargetType.IsInt32Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return _ => new[] { string.Format(
                    "{0} = ((intptr_t){1}) - ((intptr_t){2})", resultName, si0.SymbolName, si1.SymbolName) };
            }

            // IntPtr = Pointer - IntPtr
            if (si0.TargetType.IsPointer && si1.TargetType.IsIntPtrType)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return _ => new[] { string.Format(
                    "{0} = ((intptr_t){1}) - {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            // IntPtr = IntPtr - Int32
            if (si0.TargetType.IsIntPtrType && si1.TargetType.IsInt32Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return _ => new[] { string.Format(
                    "{0} = {1} - ((intptr_t){2})", resultName, si0.SymbolName, si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown sub operation: Location={0}, Type0={1}, Type1={2}",
                decodeContext.CurrentCode.RawLocation,
                si0.TargetType.FriendlyName,
                si1.TargetType.FriendlyName);
        }
    }

    internal sealed class MulConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Mul;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            // TODO: Check these combinations
            if (si0.TargetType.IsInt32Type && si1.TargetType.IsInt32Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
                return _ => new[] { string.Format(
                    "{0} = {1} * {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }
            if (si0.TargetType.IsInt64Type && si1.TargetType.IsInt64Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int64Type);
                return _ => new[] { string.Format(
                    "{0} = {1} * {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            if (si0.TargetType.IsPointer && si1.TargetType.IsInt32Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return _ => new[] { string.Format(
                    "{0} = ((intptr_t){1}) * ((intptr_t){2})", resultName, si0.SymbolName, si1.SymbolName) };
            }

            if (si0.TargetType.IsPointer && si1.TargetType.IsIntPtrType)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return _ => new[] { string.Format(
                    "{0} = ((intptr_t){1}) * {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            if (si0.TargetType.IsIntPtrType && si1.TargetType.IsInt32Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return _ => new[] { string.Format(
                    "{0} = {1} * ((intptr_t){2})", resultName, si0.SymbolName, si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown mul operation: Location={0}, Type0={1}, Type1={2}",
                decodeContext.CurrentCode.RawLocation,
                si0.TargetType.FriendlyName,
                si1.TargetType.FriendlyName);
        }
    }

    internal sealed class DivConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Div;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            // TODO: Check these combinations
            if (si0.TargetType.IsInt32Type && si1.TargetType.IsInt32Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
                return _ => new[] { string.Format(
                    "{0} = {1} / {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }
            if (si0.TargetType.IsInt64Type && si1.TargetType.IsInt64Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int64Type);
                return _ => new[] { string.Format(
                    "{0} = {1} / {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            if (si0.TargetType.IsPointer && si1.TargetType.IsInt32Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return _ => new[] { string.Format(
                    "{0} = ((intptr_t){1}) / ((intptr_t){2})", resultName, si0.SymbolName, si1.SymbolName) };
            }

            if (si0.TargetType.IsPointer && si1.TargetType.IsIntPtrType)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return _ => new[] { string.Format(
                    "{0} = ((intptr_t){1}) / {2}", resultName, si0.SymbolName, si1.SymbolName) };
            }

            if (si0.TargetType.IsIntPtrType && si1.TargetType.IsInt32Type)
            {
                var resultName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return _ => new[] { string.Format(
                    "{0} = {1} / ((intptr_t){2})", resultName, si0.SymbolName, si1.SymbolName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown div operation: Location={0}, Type0={1}, Type1={2}",
                decodeContext.CurrentCode.RawLocation,
                si0.TargetType.FriendlyName,
                si1.TargetType.FriendlyName);
        }
    }
}
