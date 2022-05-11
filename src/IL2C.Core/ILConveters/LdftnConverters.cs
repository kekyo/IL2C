////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Linq;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C.ILConverters
{
    internal sealed class LdftnConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Ldftn;

        public override ExpressionEmitter Prepare(
            IMethodInformation operand, DecodeContext decodeContext)
        {
            var symbol = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);

            // Register callee method declaring type (at the file scope).
            decodeContext.PrepareContext.RegisterType(operand.DeclaringType, decodeContext.Method);

            return (extractContext, _) => new[] { string.Format(
                "{0} = (intptr_t){1}",
                extractContext.GetSymbolName(symbol),
                operand.CLanguageFunctionFullName) };
        }
    }

    internal sealed class LdvirtftnConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Ldvirtftn;

        public override ExpressionEmitter Prepare(
            IMethodInformation method, DecodeContext decodeContext)
        {
            // ECMA-335 III.4.18: ldvirtfn - load a virtual method pointer

            if (method.IsStatic)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid method token (static): Location={0}, Method={1}",
                    decodeContext.CurrentCode.RawLocation,
                    method.FriendlyName);
            }

            var si = decodeContext.PopStack();
            if (!method.DeclaringType.IsAssignableFrom(si.TargetType))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid method token (not a member): Location={0}, Method={1}",
                    decodeContext.CurrentCode.RawLocation,
                    method.FriendlyName);
            }

            var symbol = decodeContext.PushStack(
                decodeContext.PrepareContext.MetadataContext.IntPtrType);

            // Register callee method declaring type (at the file scope).
            decodeContext.PrepareContext.RegisterType(method.DeclaringType, decodeContext.Method);

            if (method.IsVirtual && !method.IsSealed)
            {
                // Last newslot method is short named function: "ToString",
                // But have to apply full named function when NOT equals last newslot method: "System_Object_ToString"
                var methodsBySlots = method.DeclaringType.AllCombinedMethods.
                    Where(entry => entry.Item1.CLanguageFunctionName == method.CLanguageFunctionName).
                    ToArray();
                var slotIndex = methodsBySlots.
                    Select((entry, index) => entry.Item2.Any(m => m.Equals(method)) ? index : -1).
                    First(index => index >= 0);
                var newslotMethod = methodsBySlots[slotIndex].Item1;

                return (extractContext, _) => new[] { string.Format(
                    "{0} = (intptr_t){1}->vptr0__->{2}",
                    extractContext.GetSymbolName(symbol),
                    extractContext.GetSymbolName(si),
                    (slotIndex == (methodsBySlots.Length - 1)) ?
                        newslotMethod.CLanguageFunctionName :
                        newslotMethod.CLanguageFunctionFullName) };
            }
            else
            {
                return (extractContext, _) => new[] { string.Format(
                    "{0} = (intptr_t){1}",
                    extractContext.GetSymbolName(symbol),
                    method.CLanguageFunctionFullName) };
            }
        }
    }
}
