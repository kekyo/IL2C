using System;
using System.Diagnostics;
using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal static class LdfldConverterUtilities
    {
        public static string Apply(int fieldToken, DecodeContext decodeContext)
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

                    var symbolName = decodeContext.PushStack(targetType);
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
                    decodeContext.ILByteIndex,
                    fieldToken);
            }
        }
    }

    internal sealed class LdsfldConverter : InlineFieldConverter
    {
        public override OpCode OpCode => OpCodes.Ldsfld;

        public override string Apply(int fieldToken, DecodeContext decodeContext)
        {
            return LdfldConverterUtilities.Apply(fieldToken, decodeContext);
        }
    }
}
