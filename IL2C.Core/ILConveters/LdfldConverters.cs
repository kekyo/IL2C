using System;
using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal static class LdfldConverterUtilities
    {
        public static string Apply(int fieldToken, DecodeContext context)
        {
            try
            {
                var field = context.Module.ResolveField(fieldToken);
                Debug.Assert(field.IsStatic);

                context.AddStaticField(field);

                var targetType = field.FieldType;

                var fieldName = Utilities.GetFullMemberName(field);
                var fqFieldName = fieldName.ManglingSymbolName();

                if (targetType == typeof(bool))
                {
                    var symbolName = context.PushStack(typeof(int));
                    return string.Format(
                        "{0} = {1} ? 1 : 0",
                        symbolName,
                        fqFieldName);
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

                    var symbolName = context.PushStack(targetType);
                    return string.Format(
                        "{0} = {1}",
                        symbolName,
                        fqFieldName);
                }
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

    internal sealed class LdsfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Ldsfld;

        public override string Apply(int fieldToken, DecodeContext context)
        {
            return LdfldConverterUtilities.Apply(fieldToken, context);
        }
    }
}
