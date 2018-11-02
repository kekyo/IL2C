using System;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;
using System.Linq;

namespace IL2C.ILConverters
{
    internal sealed class LdftnConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Ldftn;

        public override Func<IExtractContext, string[]> Apply(
            IMethodInformation operand, DecodeContext decodeContext)
        {
            var symbolName = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);

            return _ => new[] { string.Format(
                "{0} = (intptr_t){1}",
                symbolName,
                operand.CLanguageFunctionName) };
        }
    }

    internal sealed class LdvirtftnConverter : InlineMethodConverter
    {
        public override OpCode OpCode => OpCodes.Ldvirtftn;

        public override Func<IExtractContext, string[]> Apply(
            IMethodInformation operand, DecodeContext decodeContext)
        {
            // ECMA-335 III.4.18: ldvirtfn - load a virtual method pointer

            if (operand.IsStatic)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid method token (static): Location={0}, Method={1}",
                    decodeContext.CurrentCode.RawLocation,
                    operand.FriendlyName);
            }

            var si = decodeContext.PopStack();
            if (!operand.DeclaringType.IsAssignableFrom(si.TargetType))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid method token (not a member): Location={0}, Method={1}",
                    decodeContext.CurrentCode.RawLocation,
                    operand.FriendlyName);
            }

            var symbolName = decodeContext.PushStack(
                decodeContext.PrepareContext.MetadataContext.IntPtrType);

            if (operand.IsVirtual && !operand.IsSealed)
            {
                // TODO: interface member vptr
                var virtualMethods =
                    operand.DeclaringType.CalculatedVirtualMethods;
                var (method, overloadIndex) =
                    virtualMethods.First(entry => entry.method.Equals(operand));

                var vptrName = method.GetCLanguageDeclarationName(overloadIndex);

                return _ => new[] { string.Format(
                    "{0} = (intptr_t){1}->vptr0__->{2}",
                    symbolName,
                    si.SymbolName,
                    vptrName) };
            }
            else
            {
                return _ => new[] { string.Format(
                    "{0} = (intptr_t){1}",
                    symbolName,
                    operand.CLanguageFunctionName) };
            }
        }
    }
}
