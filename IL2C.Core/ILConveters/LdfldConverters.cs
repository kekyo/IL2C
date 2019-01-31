using System;
using System.Diagnostics;

using Mono.Cecil.Cil;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal static class LdfldConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
            IFieldInformation field, DecodeContext decodeContext, bool requestPointer)
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

            var codeInformation = decodeContext.CurrentCode;

            // Register referenced field type (at the file scope).
            decodeContext.PrepareContext.RegisterType(field.FieldType, decodeContext.Method);

            if (requestPointer)
            {
                var result = decodeContext.PushStack(field.FieldType.MakeByReference());

                return extractContext =>
                {
                    return new[] { string.Format(
                    "{0} = &{1}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(siReference) + oper + field.MangledName) };
                };
            }
            else
            {
                var result = decodeContext.PushStack(field.FieldType);

                return extractContext =>
                {
                    return new[] { string.Format(
                    "{0} = {1}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(siReference) + oper + field.MangledName) };
                };
            }
        }

        public static Func<IExtractContext, string[]> ApplyStatic(
            IFieldInformation field, DecodeContext decodeContext, bool requestPointer)
        {
            Debug.Assert(field.IsStatic);

            var targetType = field.FieldType;
            var symbol = decodeContext.PushStack(
                requestPointer ? targetType.MakeByReference() : targetType);

            // Special case: This method is the type initializer and target field inside it type.
            if (decodeContext.Method.IsConstructor && decodeContext.Method.IsStatic &&
                decodeContext.Method.DeclaringType.Equals(field.DeclaringType))
            {
                if (field.FieldType.IsReferenceType ||
                    (field.FieldType.IsValueType && field.FieldType.IsRequiredTraverse))
                {
                    return extractContext => new[] { string.Format(
                        "{0} = {1}{2}_STATIC_FIELDS__.{3}",
                        extractContext.GetSymbolName(symbol),
                        requestPointer ? "&" : string.Empty,
                        field.DeclaringType.MangledUniqueName,
                        field.MangledName) };
                }
                else
                {
                    return extractContext => new[] { string.Format(
                        "{0} = {1}{2}",
                        extractContext.GetSymbolName(symbol),
                        requestPointer ? "&" : string.Empty,
                        field.MangledUniqueName) };
                }
            }
            else
            {
                return extractContext => new[] { string.Format(
                "{0} = {1}{2}_REF__",
                extractContext.GetSymbolName(symbol),
                requestPointer ? string.Empty : "*",
                extractContext.GetRightExpression(targetType, field.FieldType, field.MangledUniqueName)) };
            }
        }
    }

    internal sealed class LdfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Ldfld;

        public override Func<IExtractContext, string[]> Apply(
            IFieldInformation field, DecodeContext decodeContext)
        {
            return LdfldConverterUtilities.Apply(field, decodeContext, false);
        }
    }

    internal sealed class LdfldaConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Ldflda;

        public override Func<IExtractContext, string[]> Apply(
            IFieldInformation field, DecodeContext decodeContext)
        {
            return LdfldConverterUtilities.Apply(field, decodeContext, true);
        }
    }

    internal sealed class LdsfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Ldsfld;

        public override Func<IExtractContext, string[]> Apply(
            IFieldInformation field, DecodeContext decodeContext)
        {
            return LdfldConverterUtilities.ApplyStatic(field, decodeContext, false);
        }
    }

    internal sealed class LdsfldaConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Ldsflda;

        public override Func<IExtractContext, string[]> Apply(
            IFieldInformation field, DecodeContext decodeContext)
        {
            return LdfldConverterUtilities.ApplyStatic(field, decodeContext, true);
        }
    }
}
