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
            FieldReference field, DecodeContext decodeContext)
        {
            Debug.Assert(field.Resolve().IsStatic);

            decodeContext.PrepareContext.RegisterStaticField(field);

            var fieldName = field.GetFullMemberName();
            var fqFieldName = fieldName.ManglingSymbolName();

            var targetType = field.FieldType.GetStackableType();
            var symbolName = decodeContext.PushStack(targetType);

            if (field.FieldType.IsBooleanType())
            {
                return _ => new [] { string.Format(
                    "{0} = {1} ? 1 : 0",
                    symbolName,
                    fqFieldName) };
            }
            else
            {
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
            FieldReference field, DecodeContext decodeContext)
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
            else if (!siReference.TargetType.IsValueType)
            {
                Debug.Assert(siReference.TargetType.Resolve().IsClass
                    || siReference.TargetType.Resolve().IsInterface);

                if (field.DeclaringType.IsAssignableFrom(siReference.TargetType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid object reference: Offset={0}, StackType={1}, Name={2}",
                        decodeContext.Current.Offset,
                        siReference.TargetType.FullName,
                        field.GetFullMemberName());
                }
            }
            else if (!siReference.TargetType.IsPrimitive)
            {
                Debug.Assert(siReference.TargetType.IsValueType);

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

            var targetType = field.FieldType.GetStackableType();
            var resultName = decodeContext.PushStack(targetType);

            var offset = decodeContext.Current.Offset;

            return extractContext =>
            {
                var rightExpression = extractContext.GetRightExpression(
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
