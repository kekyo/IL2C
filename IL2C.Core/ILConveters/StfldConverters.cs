using System;
using System.Diagnostics;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C.ILConverters
{
    internal static class StfldConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
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
                        "Invalid managed reference: Location={0}, StackType={1}, Name={2}",
                        decodeContext.CurrentCode.RawLocation,
                        siReference.TargetType.FriendlyName,
                        field.FriendlyName);
                }
            }
            else if (siReference.TargetType.IsValueType == false)
            {
                if (field.DeclaringType.IsAssignableFrom(siReference.TargetType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid object reference: Location={0}, StackType={1}, Name={2}",
                        decodeContext.CurrentCode.RawLocation,
                        siReference.TargetType.FriendlyName,
                        field.FriendlyName);
                }
            }
            else
            {
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siReference.TargetType.FriendlyName);
            }

            var codeInformation = decodeContext.CurrentCode;

            // Register referenced field type (at the file scope).
            decodeContext.PrepareContext.RegisterType(field.FieldType, decodeContext.Method);

            return extractContext =>
            {
                var rightExpression = extractContext.GetRightExpression(
                    field.FieldType, siValue);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid store operation: Location={0}, StackType={1}, FieldType={2}",
                        codeInformation.RawLocation,
                        siValue.TargetType.FriendlyName,
                        field.FieldType.FriendlyName);
                }

                return new[] { string.Format(
                    "{0}->{1} = {2}",
                    extractContext.GetSymbolName(siReference),
                    field.MangledName,
                    rightExpression) };
            };
        }
    }

    internal sealed class StfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Stfld;

        public override Func<IExtractContext, string[]> Apply(
            IFieldInformation field, DecodeContext decodeContext)
        {
            return StfldConverterUtilities.Apply(field, decodeContext);
        }
    }

    internal sealed class StsfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Stsfld;

        public override Func<IExtractContext, string[]> Apply(
            IFieldInformation field, DecodeContext decodeContext)
        {
            Debug.Assert(field.IsStatic);

            var targetType = field.FieldType;
            var symbol = decodeContext.PopStack();

            // Special case: This method is the type initializer and target field inside it type.
            if (decodeContext.Method.IsConstructor && decodeContext.Method.IsStatic &&
                decodeContext.Method.DeclaringType.Equals(field.DeclaringType))
            {
                return extractContext => new[] { string.Format(
                    "{0}_STATIC_FIELDS__.{1} = {2}",
                    field.DeclaringType.MangledUniqueName,
                    field.MangledName,
                    extractContext.GetRightExpression(targetType, symbol)) };
            }
            else
            {
                return extractContext => new[] { string.Format(
                    "{0} = {1}",
                    field.MangledUniqueName,
                    extractContext.GetRightExpression(targetType, symbol)) };
            }
        }
    }
}
