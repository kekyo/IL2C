////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;

using Mono.Cecil.Cil;

using IL2C.Translators;
using IL2C.Metadata;
using IL2C.Internal;

namespace IL2C.ILConverters
{
    internal static class LdcConverterUtilities
    {
        public static ExpressionEmitter Prepare(
            ITypeInformation type, object value, DecodeContext decodeContext)
        {
            var symbol = decodeContext.PushStack(type);

            return (extractContext, _) => new[] { string.Format(
                "{0} = {1}",
                extractContext.GetSymbolName(symbol),
                Utilities.GetCLanguageExpression(value)) };
        }

        public static ExpressionEmitter Prepare(
            int value, DecodeContext decodeContext)
        {
            return Prepare(decodeContext.PrepareContext.MetadataContext.Int32Type, value, decodeContext);
        }
    }

    internal sealed class Ldc_i4_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_0;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(0, decodeContext);
        }
    }

    internal sealed class Ldc_i4_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_1;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(1, decodeContext);
        }
    }

    internal sealed class Ldc_i4_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_2;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(2, decodeContext);
        }
    }

    internal sealed class Ldc_i4_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_3;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(3, decodeContext);
        }
    }

    internal sealed class Ldc_i4_4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_4;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(4, decodeContext);
        }
    }

    internal sealed class Ldc_i4_5Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_5;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(5, decodeContext);
        }
    }

    internal sealed class Ldc_i4_6Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_6;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(6, decodeContext);
        }
    }

    internal sealed class Ldc_i4_7Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_7;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(7, decodeContext);
        }
    }

    internal sealed class Ldc_i4_8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_8;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(8, decodeContext);
        }
    }

    internal sealed class Ldc_i4_m1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_M1;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(-1, decodeContext);
        }
    }

    internal sealed class Ldc_i4_sConverter : ShortInlineI1Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4_S;

        public override ExpressionEmitter Prepare(sbyte operand, DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(operand, decodeContext);
        }
    }

    internal sealed class Ldc_i4Converter : InlineI4Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_I4;

        public override ExpressionEmitter Prepare(int operand, DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(operand, decodeContext);
        }
    }

    internal sealed class Ldc_i8Converter : InlineI8Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_I8;

        public override ExpressionEmitter Prepare(long operand, DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(
                decodeContext.PrepareContext.MetadataContext.Int64Type,
                operand,
                decodeContext);
        }
    }

    internal sealed class Ldc_r4Converter : InlineR4Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_R4;

        public override ExpressionEmitter Prepare(float operand, DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(
                decodeContext.PrepareContext.MetadataContext.SingleType,
                operand,
                decodeContext);
        }
    }

    internal sealed class Ldc_r8Converter : InlineR8Converter
    {
        public override OpCode OpCode => OpCodes.Ldc_R8;

        public override ExpressionEmitter Prepare(double operand, DecodeContext decodeContext)
        {
            return LdcConverterUtilities.Prepare(
                decodeContext.PrepareContext.MetadataContext.DoubleType,
                operand,
                decodeContext);
        }
    }
}
