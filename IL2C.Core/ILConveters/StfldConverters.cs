using System;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class StfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Stfld;

        public override string[] Apply(int fieldToken, DecodeContext decodeContext)
        {
            try
            {
                var field = decodeContext.ResolveField(fieldToken);

                var siValue = decodeContext.PopStack();
                var siReference = decodeContext.PopStack();

                if (siReference.TargetType.IsByRef)
                {
                    var dereferencedType = siReference.TargetType.GetElementType();
                    if (field.DeclaringType.IsAssignableFrom(dereferencedType) == false)
                    {
                        throw new InvalidProgramSequenceException(
                            "Invalid managed reference: ILByteIndex={0}, StackType={1}, FieldName={2}.{3}",
                            decodeContext.ILByteIndex,
                            siReference.TargetType.FullName,
                            field.DeclaringType.FullName,
                            field.Name);
                    }
                }
                else if (siReference.TargetType.IsClass)
                {
                    if (field.DeclaringType.IsAssignableFrom(siReference.TargetType) == false)
                    {
                        throw new InvalidProgramSequenceException(
                            "Invalid object reference: ILByteIndex={0}, StackType={1}, FieldName={2}.{3}",
                            decodeContext.ILByteIndex,
                            siReference.TargetType.FullName,
                            field.DeclaringType.FullName,
                            field.Name);
                    }
                }
                else
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid type at stack: ILByteIndex={0}, StackType={1}",
                        decodeContext.ILByteIndex,
                        siReference.TargetType.FullName);
                }

                var rightExpression = decodeContext.TranslateContext.GetRightExpression(
                    field.FieldType, siValue);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid store operation: ILByteIndex={0}, StackType={1}, FieldType={2}",
                        decodeContext.ILByteIndex,
                        siValue.TargetType.FullName,
                        field.FieldType.FullName);
                }

                return new[] { string.Format(
                    "{0}->{1} = {2}",
                    siReference.SymbolName,
                    field.Name,
                    rightExpression) };
            }
            catch (ArgumentException)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid field token: ILByteIndex={0}, Token={1:x2}",
                    decodeContext.ILByteIndex,
                    fieldToken);
            }
        }
    }
}
