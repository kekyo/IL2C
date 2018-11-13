using System;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;

namespace IL2C.ILConverters
{
    internal static class LdcConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
            ITypeInformation type, object value, DecodeContext decodeContext)
        {
            var symbol = decodeContext.PushStack(type);

            return extractContext => new[] { string.Format(
                "{0} = {1}",
                extractContext.GetSymbolName(symbol),
                Utilities.GetCLanguageExpression(value)) };
        }

        public static Func<IExtractContext, string[]> Apply(
            int value, DecodeContext decodeContext)
        {
            return Apply(decodeContext.PrepareContext.MetadataContext.Int32Type, value, decodeContext);
        }
    }

    internal sealed class Ldc_i4_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_0;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(0, decodeContext);
        }
    }

    internal sealed class Ldc_i4_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(1, decodeContext);
        }
    }

    internal sealed class Ldc_i4_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_2;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(2, decodeContext);
        }
    }

    internal sealed class Ldc_i4_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_3;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(3, decodeContext);
        }
    }

    internal sealed class Ldc_i4_4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_4;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(4, decodeContext);
        }
    }

    internal sealed class Ldc_i4_5Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_5;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(5, decodeContext);
        }
    }

    internal sealed class Ldc_i4_6Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_6;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(6, decodeContext);
        }
    }

    internal sealed class Ldc_i4_7Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_7;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(7, decodeContext);
        }
    }

    internal sealed class Ldc_i4_8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_8;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(8, decodeContext);
        }
    }

    internal sealed class Ldc_i4_m1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_M1;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(-1, decodeContext);
        }
    }

    internal sealed class Ldc_i4_sConverter : ShortInlineI1Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_S;

        public override Func<IExtractContext, string[]> Apply(sbyte operand, DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(operand, decodeContext);
        }
    }

    internal sealed class Ldc_i4Converter : InlineI4Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4;

        public override Func<IExtractContext, string[]> Apply(int operand, DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(operand, decodeContext);
        }
    }

    internal sealed class Ldc_i8Converter : InlineI8Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_I8;

        public override Func<IExtractContext, string[]> Apply(long operand, DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(
                decodeContext.PrepareContext.MetadataContext.Int64Type,
                operand,
                decodeContext);
        }
    }

    internal sealed class Ldc_r4Converter : InlineR4Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_R4;

        public override Func<IExtractContext, string[]> Apply(float operand, DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(
                decodeContext.PrepareContext.MetadataContext.SingleType,
                operand,
                decodeContext);
        }
    }

    internal sealed class Ldc_r8Converter : InlineR8Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_R8;

        public override Func<IExtractContext, string[]> Apply(double operand, DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Apply(
                decodeContext.PrepareContext.MetadataContext.DoubleType,
                operand,
                decodeContext);
        }
    }
}
