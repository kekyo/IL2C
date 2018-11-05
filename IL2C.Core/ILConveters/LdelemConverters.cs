using System;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C.ILConverters
{
    internal static class LdelemConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
            ITypeInformation targetType,
            Func<ITypeInformation, bool> validateElementType,
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

            var symbolName = decodeContext.PushStack(targetType);

            return extractContext =>
            {
                var expression = extractContext.GetRightExpression(
                    targetType,
                    siArray.TargetType.ElementType,
                    string.Format("il2c_array_item({0}, {1}, {2})",
                        siArray.SymbolName,
                        siArray.TargetType.ElementType.MangledName,
                        siIndex.SymbolName));
                if (expression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid target type: Location={0}, StackType={1}, TargetType={2}",
                        decodeContext.CurrentCode.RawLocation,
                        siArray.TargetType.FriendlyName,
                        targetType.FriendlyName);
                }

                return new[] { string.Format(
                    "{0} = {1}",
                    symbolName,
                    expression) };
            };
        }
    }
    
    internal sealed class Ldelem_i2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_I2;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                decodeContext.PrepareContext.MetadataContext.Int16Type,
                type => type.IsInt32StackFriendlyType,
                decodeContext);
        }
    }

    internal sealed class Ldelem_i4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_I4;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                decodeContext.PrepareContext.MetadataContext.Int32Type,
                type => type.IsInt32StackFriendlyType,
                decodeContext);
        }
    }

    internal sealed class Ldelem_i8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_I8;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                decodeContext.PrepareContext.MetadataContext.Int64Type,
                type => type.IsInt64StackFriendlyType,
                decodeContext);
        }
    }

    internal sealed class Ldelem_u1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_U1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdelemConverterUtilities.Apply(
                decodeContext.PrepareContext.MetadataContext.ByteType,
                type => type.IsInt32StackFriendlyType,
                decodeContext);
        }
    }
}
