using System;
using System.Diagnostics;
using IL2C.Metadata;
using Mono.Cecil;
using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal abstract class InlineNoneConverter : ILConverter
    {
        public sealed override Func<IExtractContext, string[]> Apply(object operand, DecodeContext decodeContext)
        {
            Debug.Assert(operand == null);
            return this.Apply(decodeContext);
        }

        public abstract Func<IExtractContext, string[]> Apply(DecodeContext decodeContext);
    }

    internal abstract class InlineI4Converter : ILConverter<int>
    {
    }

    internal abstract class InlineI8Converter : ILConverter<long>
    {
    }

    internal abstract class InlineR4Converter : ILConverter<float>
    {
    }

    internal abstract class InlineR8Converter : ILConverter<double>
    {
    }

    internal abstract class InlineMethodConverter : ILConverter<IMethodInformation>
    {
    }

    internal abstract class InlineFieldConverter : ILConverter<IFieldInformation>
    {
    }

    internal abstract class InlineTypeConverter : ILConverter<ITypeInformation>
    {
    }

    internal abstract class InlineStringConverter : ILConverter<string>
    {
    }

    internal abstract class InlineBrTargetConverter : ILConverter<ICodeInformation>
    {
    }

    internal abstract class ShortInlineBrTargetConverter : ILConverter<ICodeInformation>
    {
    }

    internal abstract class ShortInlineI1Converter : ILConverter<sbyte>
    {
    }

    internal abstract class ShortInlineParamConverter : ILConverter<VariableInformation>
    {
    }

    internal abstract class ShortInlineVarConverter : ILConverter<VariableInformation>
    {
    }
}
