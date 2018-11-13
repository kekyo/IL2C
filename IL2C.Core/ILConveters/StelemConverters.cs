using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class Stelem_i4ConvertersConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stelem_I4;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            // ECMA-335 III.4.26 stelem.<type> - store element to array

            var siValue = decodeContext.PopStack();
            if (!siValue.TargetType.IsNumericPrimitive)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid store type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siValue.TargetType.FriendlyName);
            }

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
                siArray.TargetType.ElementType.IsInt32StackFriendlyType))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid array element type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siArray.TargetType.FriendlyName);
            }

            return extractContext => new[] {
                string.Format("il2c_array_item({0}, {1}, {2}) = {3}",
                    extractContext.GetSymbolName(siArray),
                    siArray.TargetType.ElementType.MangledName,
                    extractContext.GetSymbolName(siIndex),
                    extractContext.GetSymbolName(siValue)) };
        }
    }

    internal sealed class Stelem_refConvertersConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stelem_Ref;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            // ECMA-335 III.4.26 stelem.<type> - store element to array

            var siValue = decodeContext.PopStack();
            if (!siValue.TargetType.IsReferenceType)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid store type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siValue.TargetType.FriendlyName);
            }

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
                siArray.TargetType.ElementType.IsAssignableFrom(siValue.TargetType)))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid array element type: Location={0}, ArrayType={1}, StackType={2}",
                    decodeContext.CurrentCode.RawLocation,
                    siArray.TargetType.FriendlyName,
                    siValue.TargetType.FriendlyName);
            }

            return extractContext => new[] {
                string.Format("il2c_array_item({0}, {1}, {2}) = {3}",
                    extractContext.GetSymbolName(siArray),
                    siArray.TargetType.ElementType.CLanguageTypeName,
                    extractContext.GetSymbolName(siIndex),
                    extractContext.GetSymbolName(siValue)) };
        }
    }
}
