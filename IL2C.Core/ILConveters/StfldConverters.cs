using System;

using Mono.Cecil;
using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConveters
{
    internal sealed class StfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Stfld;

        public override Func<IExtractContext, string[]> Apply(
            FieldReference field, DecodeContext decodeContext)
        {
            var siValue = decodeContext.PopStack();
            var siReference = decodeContext.PopStack();

            if (siReference.TargetType.IsByReference)
            {
                var dereferencedType = siReference.TargetType.GetElementType();
                if (field.DeclaringType.IsAssignableFrom(dereferencedType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid managed reference: Offset={0}, StackType={1}, Name={2}",
                        decodeContext.Current.Offset,
                        siReference.TargetType.FullName,
                        field.GetFullMemberName());
                }
            }
            else if (siReference.TargetType.IsValueType == false)
            {
                if (field.DeclaringType.IsAssignableFrom(siReference.TargetType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid object reference: Offset={0}, StackType={1}, Name={2}",
                        decodeContext.Current.Offset,
                        siReference.TargetType.FullName,
                        field.GetFullMemberName());
                }
            }
            else
            {
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack: Offset={0}, StackType={1}",
                    decodeContext.Current.Offset,
                    siReference.TargetType.FullName);
            }

            var offset = decodeContext.Current.Offset;

            return extractContext =>
            {
                var rightExpression = extractContext.GetRightExpression(
                    field.FieldType, siValue);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid store operation: Offset={0}, StackType={1}, FieldType={2}",
                        offset,
                        siValue.TargetType.FullName,
                        field.FieldType.FullName);
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
