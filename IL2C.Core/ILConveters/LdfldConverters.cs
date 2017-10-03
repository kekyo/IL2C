using System.Reflection.Emit;

namespace IL2C.ILConveters
{
    internal static class LdfldConverterUtilities
    {
        public static string Apply(int fieldToken, DecodeContext context)
        {
            var field = context.Module.ResolveField(fieldToken);
            var targetType = field.FieldType;

            var fieldName = Utilities.GetFullMemberName(field);
            var fqFieldName = fieldName.Replace(".", "_");

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
