using System;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C.ILConverters
{
    internal sealed class Ldelem_i4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldelem_I4;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
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
                siArray.TargetType.ElementType.IsInt32StackFriendlyType))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid array element type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siArray.TargetType.FriendlyName);
            }

            var symbolName = decodeContext.PushStack(
                decodeContext.PrepareContext.MetadataContext.Int32Type);

            return _ => new[] { string.Format(
                "{0} = {1}->Item[{2}]",
                symbolName,
                siArray.SymbolName,
                siIndex.SymbolName) };
        }
    }
}
