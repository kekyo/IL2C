using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal static class ArithmeticalConverterUtilities
    {
        public enum BinaryOperators
        {
            Add,
            Sub,
            Mul,
            Div,
            Rem
        }

        public static Func<IExtractContext, string[]> Apply(BinaryOperators binaryOperator, DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            char opChar;
            switch (binaryOperator)
            {
                case BinaryOperators.Add: opChar = '+'; break;
                case BinaryOperators.Sub: opChar = '-'; break;
                case BinaryOperators.Mul: opChar = '*'; break;
                case BinaryOperators.Div: opChar = '/'; break;
                case BinaryOperators.Rem: opChar = '%'; break;
                default: throw new Exception();
            }

            // See also: ECMA-335: III.1.5 Operand type table - Binary Numeric Operations

            // Int32 = (Int32) op (Int32)
            if (si0.TargetType.IsInt32StackFriendlyType && si1.TargetType.IsInt32StackFriendlyType)
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
                return extractContext => new[] { string.Format(
                    "{0} = {1} {2} {3}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    opChar,
                    extractContext.GetSymbolName(si1)) };
            }

            // Int64 = (Int64) op (Int64)
            if (si0.TargetType.IsInt64StackFriendlyType && si1.TargetType.IsInt64StackFriendlyType)
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int64Type);
                return extractContext => new[] { string.Format(
                    "{0} = {1} {2} {3}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    opChar,
                    extractContext.GetSymbolName(si1)) };
            }

            // Double = (Float) % (Float)
            if (si0.TargetType.IsFloatStackFriendlyType && si1.TargetType.IsFloatStackFriendlyType &&
                (binaryOperator == BinaryOperators.Rem))
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.DoubleType);

                // Use special runtime function.
                return extractContext => new[] { string.Format(
                    "{0} = il2c_fmod({1}, {2})",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    extractContext.GetSymbolName(si1)) };
            }

            // Double = (Float) op (Float)
            if (si0.TargetType.IsFloatStackFriendlyType && si1.TargetType.IsFloatStackFriendlyType)
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.DoubleType);
                return extractContext => new[] { string.Format(
                    "{0} = (double){1} {2} (double){3}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    opChar,
                    extractContext.GetSymbolName(si1)) };
            }

            // ByRef = (Int32) + (ByRef)
            if (si0.TargetType.IsInt32StackFriendlyType && si1.TargetType.IsByReference &&
                (binaryOperator == BinaryOperators.Add))
            {
                var result = decodeContext.PushStack(si1.TargetType);
                return extractContext => new[] { string.Format(
                    "{0} = ({1})((intptr_t){2} + (intptr_t){3})",
                    extractContext.GetSymbolName(result),
                    si1.TargetType.CLanguageTypeName,
                    extractContext.GetSymbolName(si0),
                    extractContext.GetSymbolName(si1)) };
            }

            // ByRef = (IntPtr) + (ByRef)
            if (si0.TargetType.IsIntPtrStackFriendlyType && si1.TargetType.IsByReference &&
                (binaryOperator == BinaryOperators.Add))
            {
                var result = decodeContext.PushStack(si1.TargetType);
                return extractContext => new[] { string.Format(
                    "{0} = ({1})((intptr_t){2} + (intptr_t){3})",
                    extractContext.GetSymbolName(result),
                    si1.TargetType.CLanguageTypeName,
                    extractContext.GetSymbolName(si0),
                    extractContext.GetSymbolName(si1)) };
            }

            // ByRef = (ByRef) +/- (Int32|IntPtr)
            if (si0.TargetType.IsByReference &&
                (si1.TargetType.IsInt32StackFriendlyType || si1.TargetType.IsIntPtrStackFriendlyType) &&
                ((binaryOperator == BinaryOperators.Add) || (binaryOperator == BinaryOperators.Sub)))
            {
                var result = decodeContext.PushStack(si0.TargetType);
                return extractContext => new[] { string.Format(
                    "{0} = ({1})((intptr_t){2} {3} (intptr_t){4})",
                    extractContext.GetSymbolName(result),
                    si0.TargetType.CLanguageTypeName,
                    extractContext.GetSymbolName(si0),
                    opChar,
                    extractContext.GetSymbolName(si1)) };
            }

            // ByRef = (ByRef) - (ByRef)
            if (si0.TargetType.IsByReference && si1.TargetType.IsByReference &&
                (binaryOperator == BinaryOperators.Sub))
            {
                var result = decodeContext.PushStack(si0.TargetType);
                return extractContext => new[] { string.Format(
                    "{0} = ({1})((intptr_t){2} - (intptr_t){3})",
                    extractContext.GetSymbolName(result),
                    si0.TargetType.CLanguageTypeName,
                    extractContext.GetSymbolName(si0),
                    extractContext.GetSymbolName(si1)) };
            }

            // IntPtr = (Int32|IntPtr) op (Int32|IntPtr)
            if ((si0.TargetType.IsInt32StackFriendlyType || si0.TargetType.IsIntPtrStackFriendlyType) &&
                (si1.TargetType.IsInt32StackFriendlyType || si1.TargetType.IsIntPtrStackFriendlyType))
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return extractContext => new[] { string.Format(
                    "{0} = (intptr_t){1} {2} (intptr_t){3}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    opChar,
                    extractContext.GetSymbolName(si1)) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown arithmetical operation: Location={0}, Op={1}, Type0={2}, Type1={3}",
                decodeContext.CurrentCode.RawLocation,
                binaryOperator,
                si0.TargetType.FriendlyName,
                si1.TargetType.FriendlyName);
        }
    }

    internal sealed class AddConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Add;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return ArithmeticalConverterUtilities.Apply(
                ArithmeticalConverterUtilities.BinaryOperators.Add, decodeContext);
        }
    }

    internal sealed class SubConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Sub;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return ArithmeticalConverterUtilities.Apply(
                ArithmeticalConverterUtilities.BinaryOperators.Sub, decodeContext);
        }
    }

    internal sealed class MulConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Mul;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return ArithmeticalConverterUtilities.Apply(
                ArithmeticalConverterUtilities.BinaryOperators.Mul, decodeContext);
        }
    }

    internal sealed class DivConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Div;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return ArithmeticalConverterUtilities.Apply(
                ArithmeticalConverterUtilities.BinaryOperators.Div, decodeContext);
        }
    }

    internal sealed class RemConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Rem;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return ArithmeticalConverterUtilities.Apply(
                ArithmeticalConverterUtilities.BinaryOperators.Rem, decodeContext);
        }
    }
}
