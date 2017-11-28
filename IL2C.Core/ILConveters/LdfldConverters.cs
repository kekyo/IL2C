using System;
using System.Diagnostics;

using Mono.Cecil.Cil;

using IL2C.Translators;
using Mono.Cecil;

namespace IL2C.ILConveters
{
    internal sealed class LdsfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Ldsfld;

        public override Func<IExtractContext, string[]> Apply(
            FieldDefinition field, DecodeContext decodeContext)
        {
            Debug.Assert(field.IsStatic);

            decodeContext.prepareContext.RegisterStaticField(field);

            var targetType = field.FieldType;

            var fieldName = field.GetFullMemberName();
            var fqFieldName = fieldName.ManglingSymbolName();

            if (targetType.MemberEquals(CecilHelper.BooleanType))
            {
                var symbolName = decodeContext.PushStack(CecilHelper.Int32Type);
                return _ => new [] { string.Format(
                    "{0} = {1} ? 1 : 0",
                    symbolName,
                    fqFieldName) };
            }
            else
            {
                targetType = Utilities.GetStackableType(targetType);
                var symbolName = decodeContext.PushStack(targetType);
                return _ => new[] { string.Format(
                    "{0} = {1}",
                    symbolName,
                    fqFieldName) };
            }
        }
    }

    internal sealed class LdfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Ldfld;

        public override Func<IExtractContext, string[]> Apply(
            FieldDefinition field, DecodeContext decodeContext)
        {
            var siReference = decodeContext.PopStack();

            var oper = "->";
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
            else if (siReference.TargetType.IsClass())
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
            else if (siReference.TargetType.IsValueType)
            {
                if (field.DeclaringType.IsAssignableFrom(siReference.TargetType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid managed reference: Offset={0}, StackType={1}, Name={2}",
                        decodeContext.Current.Offset,
                        siReference.TargetType.FullName,
                        field.GetFullMemberName());
                }

                oper = ".";
            }
            else
            {
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack: Offset={0}, StackType={1}",
                    decodeContext.Current.Offset,
                    siReference.TargetType.FullName);
            }

            var targetType = field.FieldType;
            targetType = Utilities.GetStackableType(targetType);
            var resultName = decodeContext.PushStack(targetType);

            var offset = decodeContext.Current.Offset;

            return lookupper =>
            {
                var rightExpression = lookupper.GetRightExpression(
                    targetType,
                    field.FieldType,
                    siReference.SymbolName + oper + field.Name);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid load operation: Offset={0}, StackType={1}, FieldType={2}",
                        offset,
                        targetType.FullName,
                        field.FieldType.FullName);
                }

                return new[] { string.Format(
                    "{0} = {1}",
                    resultName,
                    rightExpression) };
            };
        }
    }
}
