using System;
using System.Diagnostics;

using Mono.Cecil.Cil;

using IL2C.Translators;
using Mono.Cecil;

namespace IL2C.ILConveters
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

    internal abstract class InlineMethodConverter : ILConverter<MethodReference>
    {
    }

    internal abstract class InlineFieldConverter : ILConverter<FieldReference>
    {
    }

    internal abstract class InlineTypeConverter : ILConverter<TypeReference>
    {
    }

    internal abstract class InlineStringConverter : ILConverter<string>
    {
    }

    internal abstract class ShortInlineBrTargetConverter : ILConverter<Instruction>
    {
    }

    internal abstract class ShortInlineI1Converter : ILConverter<sbyte>
    {
    }

    internal abstract class ShortInlineVarConverter : ILConverter<VariableReference>
    {
    }
}
