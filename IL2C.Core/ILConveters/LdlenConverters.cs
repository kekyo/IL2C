using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class LdlenConverters : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldlen;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            // ECMA-335 III.4.12 ldlen - load the length of an array

            var siArray = decodeContext.PopStack();
            if (!siArray.TargetType.IsArray)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid array type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siArray.TargetType.FriendlyName);
            }

            // push size by UIntPtr (not Int32.)
            var symbolName = decodeContext.PushStack(
                decodeContext.PrepareContext.MetadataContext.UIntPtrType);

            return _ => new[] { string.Format(
                "{0} = {1}->Length",
                symbolName,
                siArray.SymbolName) };
        }
    }
}
