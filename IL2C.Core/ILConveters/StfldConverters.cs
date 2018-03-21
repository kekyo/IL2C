using System;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C.ILConveters
{
    internal sealed class StfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Stfld;

        public override Func<IExtractContext, string[]> Apply(
            IFieldInformation field, DecodeContext decodeContext)
        {
            var siValue = decodeContext.PopStack();
            var siReference = decodeContext.PopStack();

            if (siReference.TargetType.IsByReference)
            {
                var dereferencedType = siReference.TargetType.ElementType;
                if (field.DeclaringType.IsAssignableFrom(dereferencedType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid managed reference: Offset={0}, StackType={1}, Name={2}",
                        decodeContext.CurrentCode.Offset,
                        siReference.TargetType.FriendlyName,
                        field.FriendlyName);
                }
            }
            else if (siReference.TargetType.IsValueType == false)
            {
                if (field.DeclaringType.IsAssignableFrom(siReference.TargetType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid object reference: Offset={0}, StackType={1}, Name={2}",
                        decodeContext.CurrentCode.Offset,
                        siReference.TargetType.FriendlyName,
                        field.FriendlyName);
                }
            }
            else
            {
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack: Offset={0}, StackType={1}",
                    decodeContext.CurrentCode.Offset,
                    siReference.TargetType.FriendlyName);
            }

            var offset = decodeContext.CurrentCode.Offset;

            return extractContext =>
            {
                var rightExpression = extractContext.GetRightExpression(
                    field.FieldType, siValue);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid store operation: Offset={0}, StackType={1}, FieldType={2}",
                        offset,
                        siValue.TargetType.FriendlyName,
                        field.FieldType.FriendlyName);
                }

                return new[] { string.Format(
                    "{0}->{1} = {2}",
                    siReference.SymbolName,
                    field.Name,
                    rightExpression) };
            };
        }
    }
}
