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
                // TODO: interface member vptr
                var vptrName = method.CLanguageFunctionName;

                return (extractContext, _) => new[] { string.Format(
                    "{0} = (intptr_t){1}->vptr0__->{2}",
                    extractContext.GetSymbolName(symbol),
                    extractContext.GetSymbolName(si),
                    vptrName) };
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
