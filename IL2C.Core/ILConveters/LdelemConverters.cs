using System;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C.ILConverters
{
    internal static class LdelemConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
            Func<ITypeInformation, bool> validateElementType,
            Func<ITypeInformation, ITypeInformation> extractElementType,
            bool isByReference,
            DecodeContext decodeContext)
        {
            // ECMA-335 III.4.8 ldelem.<type> - load an element of an array

            var siIndex = decodeContext.PopStack();
            if (!(siIndex.TargetType.IsInt32StackFriendlyType || siIndex.TargetType.IsIntPtrStackFriendlyType))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid index type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siIndex.TargetType.FriendlyName);
            }

            var siArray = decodeContext.PopStack();
            if (!(siArray.TargetType.IsArray &&
                validateElementType(siArray.TargetType.ElementType)))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid array element type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siArray.TargetType.FriendlyName);
            }

            var elementType = extractElementType(siArray.TargetType);
            var symbol = decodeContext.PushStack(elementType);

            return extractContext =>
            {
                var expression = extractContext.GetRightExpression(
                    elementType,
                    siArray.TargetType.ElementType,
                    string.Format("il2c_array_item{0}({1}, {2}, {3})",
                        isByReference ? "ptr" : string.Empty,
                        extractContext.GetSymbolName(siArray),
                        siArray.TargetType.ElementType.CLanguageTypeName,
                        extractContext.GetSymbolName(siIndex)));
                if (expression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid target type: Location={0}, StackType={1}, TargetType={2}",
                        decodeContext.CurrentCode.RawLocation,
                        siArray.TargetType.FriendlyName,
                        elementType.FriendlyName);
                }

                return new[] { string.Format(
                    "{0} = {1}",
                    extractContext.GetSymbolName(symbol),
                    expression) };
            };
        }

        public static Func<IExtractContext, string[]> Apply(
            Func<ITypeInformation, bool> validateElementType,
            ITypeInformation elementType,
            bool isByReference,
            DecodeContext decodeContext)
        {
            return Apply(validateElementType, _ => elementType, isByReference, decodeContext);
        }
    }

    internal sealed class Ldelem_i1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_I1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                elementType => elementType.IsInt32StackFriendlyType,
                decodeContext.PrepareContext.MetadataContext.SByteType,
                false,
                decodeContext);
        }
    }

    internal sealed class Ldelem_i2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_I2;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                elementType => elementType.IsInt32StackFriendlyType,
                decodeContext.PrepareContext.MetadataContext.Int16Type,
                false,
                decodeContext);
        }
    }

    internal sealed class Ldelem_i4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_I4;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                elementType => elementType.IsInt32StackFriendlyType,
                decodeContext.PrepareContext.MetadataContext.Int32Type,
                false,
                decodeContext);
        }
    }

    internal sealed class Ldelem_i8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_I8;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                elementType => elementType.IsInt64StackFriendlyType,
                decodeContext.PrepareContext.MetadataContext.Int64Type,
                false,
                decodeContext);
        }
    }

    internal sealed class Ldelem_u1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_U1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                elementType => elementType.IsInt32StackFriendlyType,
                decodeContext.PrepareContext.MetadataContext.ByteType,
                false,
                decodeContext);
        }
    }

    internal sealed class Ldelem_u2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_U2;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                elementType => elementType.IsInt32StackFriendlyType,
                decodeContext.PrepareContext.MetadataContext.UInt16Type,
                false,
                decodeContext);
        }
    }

    internal sealed class Ldelem_u4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_U4;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                elementType => elementType.IsInt32StackFriendlyType,
                decodeContext.PrepareContext.MetadataContext.UInt32Type,
                false,
                decodeContext);
        }
    }

    internal sealed class Ldelem_r8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_R8;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                elementType => elementType.IsFloatStackFriendlyType,
                decodeContext.PrepareContext.MetadataContext.DoubleType,
                false,
                decodeContext);
        }
    }

    internal sealed class Ldelem_r4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_R4;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                elementType => elementType.IsFloatStackFriendlyType,
                decodeContext.PrepareContext.MetadataContext.SingleType,
                false,
                decodeContext);
        }
    }

    internal sealed class Ldelem_refConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_Ref;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                elementType => elementType.IsReferenceType,
                arrayType => arrayType.ElementType,
                false,
                decodeContext);
        }
    }

    internal sealed class LdelemaConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Ldelema;

        public override Func<IExtractContext, string[]> Apply(ITypeInformation operand, DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                elementType => operand.IsAssignableFrom(elementType),
                operand.MakeByReference(),
                true,
                decodeContext);
        }
    }
}
