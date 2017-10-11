using System;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class StfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Stfld;

        public override string Apply(int fieldToken, DecodeContext context)
        {
            try
            {
                var field = context.Module.ResolveField(fieldToken);

                var siValue = context.PopStack();
                var siReference = context.PopStack();

                if (siReference.TargetType.IsByRef == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid type at stack: ILByteIndex={0}, StackType={1}",
                        context.ILByteIndex,
                        siReference.TargetType.FullName);
                }

                var dereferencedType = siReference.TargetType.GetElementType();
                if (field.DeclaringType.IsAssignableFrom(dereferencedType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid managed reference: ILByteIndex={0}, StackType={1}, FieldName={2}.{3}",
                        context.ILByteIndex,
                        siReference.TargetType.FullName,
                        field.DeclaringType.FullName,
                        field.Name);
                }

                var rightExpression = Utilities.GetRightExpression(field.FieldType, siValue);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid store operation: ILByteIndex={0}, StackType={1}, FieldType={2}",
                        context.ILByteIndex,
                        siValue.TargetType.FullName,
                        field.FieldType.FullName);
                }

                return string.Format(
                    "{0}->{1} = {2}",
                    siReference.SymbolName,
                    field.Name,
                    rightExpression);
            }
            catch (ArgumentException)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid field token: ILByteIndex={0}, Token={1:x2}",
                    context.ILByteIndex,
                    fieldToken);
            }
        }
    }
}
