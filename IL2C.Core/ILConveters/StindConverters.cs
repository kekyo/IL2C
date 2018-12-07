using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal static class StindConverter_Utilities
    {
        public static Func<IExtractContext, string[]> Apply(
            DecodeContext decodeContext)
        {
            // NOTE: This method's sharing for the stind opcode family.
            //   IL2C can recognize target type implicitly.
            //   Because IL2C can type inference at evaluation stack, so don't need stind's opcode attribute.

            var siValue = decodeContext.PopStack();
            var siReference = decodeContext.PopStack();

            if (siReference.TargetType.IsByReference)
            {
                var dereferencedType = siReference.TargetType.ElementType;
                if (dereferencedType.IsAssignableFrom(siValue.TargetType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid managed reference: Location={0}, ReferenceType={1}, Value={2}",
                        decodeContext.CurrentCode.RawLocation,
                        siReference.TargetType.FriendlyName,
                        siValue.TargetType.FriendlyName);
                }
            }
            else
            {
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack: Location={0}, ReferenceType={1}, Value={2}",
                    decodeContext.CurrentCode.RawLocation,
                    siReference.TargetType.FriendlyName,
                    siValue.TargetType.FriendlyName);
            }

            var codeInformation = decodeContext.CurrentCode;

            return extractContext =>
            {
                var rightExpression = extractContext.GetRightExpression(
                    siReference.TargetType.ElementType, siValue);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid store operation: Location={0}, ReferenceType={1}, Value={2}",
                        codeInformation.RawLocation,
                    siReference.TargetType.FriendlyName,
                    siValue.TargetType.FriendlyName);
                }

                return new[] { string.Format(
                    "*{0} = {1}",
                    extractContext.GetSymbolName(siReference),
                    rightExpression) };
            };
        }
    }

    internal sealed class Stind_i4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stind_I4;

        public override Func<IExtractContext, string[]> Apply(
            DecodeContext decodeContext)
        {
            return StindConverter_Utilities.Apply(decodeContext);
        }
    }

    internal sealed class Stind_RefConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stind_Ref;

        public override Func<IExtractContext, string[]> Apply(
            DecodeContext decodeContext)
        {
            return StindConverter_Utilities.Apply(decodeContext);
        }
    }
}
