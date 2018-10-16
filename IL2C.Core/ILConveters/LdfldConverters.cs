using System;
using System.Diagnostics;

using Mono.Cecil;
using Mono.Cecil.Cil;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class LdsfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Ldsfld;

        public override Func<IExtractContext, string[]> Apply(
            IFieldInformation field, DecodeContext decodeContext)
        {
            Debug.Assert(field.IsStatic);

            decodeContext.PrepareContext.RegisterStaticField(field);

            var targetType = field.FieldType;
            var symbolName = decodeContext.PushStack(targetType);

            return extractContext => new [] { string.Format(
                "{0} = {1}",
                symbolName,
                extractContext.GetRightExpression(targetType, field.FieldType, field.MangledName)) };
        }
    }

    internal sealed class LdfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Ldfld;

        public override Func<IExtractContext, string[]> Apply(
            IFieldInformation field, DecodeContext decodeContext)
        {
            var siReference = decodeContext.PopStack();

            var oper = "->";
            if (siReference.TargetType.IsByReference)
            {
                var dereferencedType = siReference.TargetType.ElementType;
                if (field.DeclaringType.IsAssignableFrom(dereferencedType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid managed reference: Location={0}, StackType={1}, Name={2}",
                        decodeContext.CurrentCode.RawLocation,
                        siReference.TargetType.FriendlyName,
                        field.FriendlyName);
                }
            }
            else if (!siReference.TargetType.IsValueType)
            {
                Debug.Assert(siReference.TargetType.IsClass
                    || siReference.TargetType.IsInterface);

                if (field.DeclaringType.IsAssignableFrom(siReference.TargetType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid object reference: Location={0}, StackType={1}, Name={2}",
                        decodeContext.CurrentCode.RawLocation,
                        siReference.TargetType.FriendlyName,
                        field.FriendlyName);
                }
            }
            else if (!siReference.TargetType.IsPrimitive)
            {
                Debug.Assert(siReference.TargetType.IsValueType);

                if (field.DeclaringType.IsAssignableFrom(siReference.TargetType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid managed reference: Location={0}, StackType={1}, Name={2}",
                        decodeContext.CurrentCode.RawLocation,
                        siReference.TargetType.FriendlyName,
                        field.FriendlyName);
                }

                oper = ".";
            }
            else
            {
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siReference.TargetType.FriendlyName);
            }

            var targetType = field.FieldType;
            var resultName = decodeContext.PushStack(targetType);

            var codeInformation = decodeContext.CurrentCode;

            return extractContext =>
            {
                var rightExpression = extractContext.GetRightExpression(
                    targetType,
                    field.FieldType,
                    siReference.SymbolName + oper + field.Name);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid load operation: Location={0}, StackType={1}, FieldType={2}",
                        codeInformation.RawLocation,
                        targetType.FriendlyName,
                        field.FieldType.FriendlyName);
                }

                return new[] { string.Format(
                    "{0} = {1}",
                    resultName,
                    rightExpression) };
            };
        }
    }
}
