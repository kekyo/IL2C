using System;
using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal sealed class LdsfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Ldsfld;

        public override string[] Apply(int fieldToken, DecodeContext decodeContext)
        {
            try
            {
                var field = decodeContext.ResolveField(fieldToken);
                Debug.Assert(field.IsStatic);

                decodeContext.TranslateContext.AddStaticField(field);

                var targetType = field.FieldType;

                var fieldName = Utilities.GetFullMemberName(field);
                var fqFieldName = fieldName.ManglingSymbolName();

                if (targetType == typeof(bool))
                {
                    var symbolName = decodeContext.PushStack(typeof(int));
                    return new [] { string.Format(
                        "{0} = {1} ? 1 : 0",
                        symbolName,
                        fqFieldName) };
                }
                else
                {
                    if ((targetType == typeof(byte))
                        || (targetType == typeof(sbyte))
                        || (targetType == typeof(short))
                        || (targetType == typeof(ushort)))
                    {
                        targetType = typeof(int);
                    }

                    var symbolName = decodeContext.PushStack(targetType);
                    return new[] { string.Format(
                        "{0} = {1}",
                        symbolName,
                        fqFieldName) };
                }
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

    internal sealed class LdfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Ldfld;

        public override string[] Apply(int fieldToken, DecodeContext decodeContext)
        {
            try
            {
                var field = decodeContext.ResolveField(fieldToken);

                var siReference = decodeContext.PopStack();

                var oper = "->";
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
                else if (siReference.TargetType.IsValueType)
                {
                    if (field.DeclaringType.IsAssignableFrom(siReference.TargetType) == false)
                    {
                        throw new InvalidProgramSequenceException(
                            "Invalid managed reference: ILByteIndex={0}, StackType={1}, FieldName={2}.{3}",
                            decodeContext.ILByteIndex,
                            siReference.TargetType.FullName,
                            field.DeclaringType.FullName,
                            field.Name);
                    }

                    oper = ".";
                }
                else
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid type at stack: ILByteIndex={0}, StackType={1}",
                        decodeContext.ILByteIndex,
                        siReference.TargetType.FullName);
                }

                var targetType = field.FieldType;
                if ((targetType == typeof(byte))
                    || (targetType == typeof(sbyte))
                    || (targetType == typeof(short))
                    || (targetType == typeof(ushort))
                    || (targetType == typeof(bool)))
                {
                    targetType = typeof(int);
                }

                var rightExpression = decodeContext.TranslateContext.GetRightExpression(
                    targetType,
                    field.FieldType,
                    siReference.SymbolName + oper + field.Name);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid load operation: ILByteIndex={0}, StackType={1}, FieldType={2}",
                        decodeContext.ILByteIndex,
                        targetType.FullName,
                        field.FieldType.FullName);
                }

                var resultName = decodeContext.PushStack(targetType);

                return new[] { string.Format(
                    "{0} = {1}",
                    resultName,
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
