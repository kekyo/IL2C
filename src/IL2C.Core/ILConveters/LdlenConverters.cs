////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class LdlenConverters : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldlen;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
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
            var symbol = decodeContext.PushStack(
                decodeContext.PrepareContext.MetadataContext.UIntPtrType);

            return (extractContext, _) => new[] { string.Format(
                "{0} = (uintptr_t){1}->Length",
                extractContext.GetSymbolName(symbol),
                extractContext.GetSymbolName(siArray)) };
        }
    }
}
