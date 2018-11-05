using System;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;

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

            return _ => new[] {
                string.Format("il2c_array_item({0}, {1}, {2}) = {3}",
                    siArray.SymbolName,
                    siArray.TargetType.ElementType.MangledName,
                    siIndex.SymbolName,
                    siValue.SymbolName) };
        }
    }
}
