using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal static class ConditionalConverterUtilities
    {
        public static Func<IExtractContext, string[]> Apply(
            string oper,
            bool isUnsigned,
            DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            // ECMA-335 III.3.45 ldnull - load null pointer, said:
            //   [Rationale: It might be thought that ldnull is redundant: why not use ldc.i4.0 or ldc.i8.0 instead?
            //   The answer is that ldnull provides a size - agnostic null – analogous to an ldc.i instruction, which
            //   does not exist.However, even if CIL were to include an ldc.i instruction it would still benefit
            //   verification algorithms to retain the ldnull instruction because it makes type tracking easier.end
            //   rationale]
            // I found the Roslyn generated from C#:
            //   if (stringValue != null)  // ...
            // To IL:
            //   ldarg.0
            //   ldnull
            //   cgt_un
            //   stloc.0
            // The conditional expression operator can compare between the 'O' type stack value and pseudo 'O' like null value.
            // And I imagine these comparer maybe don't it another combination (ex: int32 and null, int64 and null...)

            if (si0.TargetType.IsInt32StackFriendlyType &&
                si1.TargetType.IsInt32StackFriendlyType)
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
                return extractContext => new[] { string.Format(
                    "{1} = (({0}int32_t){2} {3} ({0}int32_t){4}) ? 1 : 0",
                    isUnsigned ? "u" : string.Empty,
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    oper,
                    extractContext.GetSymbolName(si1)) };
            }

            if (si0.TargetType.IsInt64StackFriendlyType ||
                si1.TargetType.IsInt64StackFriendlyType)
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
                return extractContext => new[] { string.Format(
                    "{1} = (({0}int64_t){2} {3} ({0}int64_t){4}) ? 1 : 0",
                    isUnsigned ? "u" : string.Empty,
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    oper,
                    extractContext.GetSymbolName(si1)) };
            }

            if ((si0.TargetType.IsIntPtrStackFriendlyType || !si0.TargetType.IsValueType || si0.TargetType.IsByReference || si0.TargetType.IsUntypedReferenceType) &&
                (si1.TargetType.IsIntPtrStackFriendlyType || !si1.TargetType.IsValueType || si1.TargetType.IsByReference || si0.TargetType.IsUntypedReferenceType))
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
                return extractContext => new[] { string.Format(
                    "{1} = (({0}intptr_t){2} {3} ({0}intptr_t){4}) ? 1 : 0",
                    isUnsigned ? "u" : string.Empty,
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    oper,
                    extractContext.GetSymbolName(si1)) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown conditional operation: Location={0}, Type0={1}, Type1={2}",
                decodeContext.CurrentCode.RawLocation,
                si0.TargetType.FriendlyName,
                si1.TargetType.FriendlyName);
        }
    }

    internal sealed class CgtConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Cgt;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return ConditionalConverterUtilities.Apply(
                ">", false, decodeContext);
        }
    }

    internal sealed class Cgt_unConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Cgt_Un;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return ConditionalConverterUtilities.Apply(
                ">", true, decodeContext);
        }
    }

    internal sealed class CltConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Clt;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return ConditionalConverterUtilities.Apply(
                "<", false, decodeContext);
        }
    }

    internal sealed class Clt_unConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Clt_Un;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return ConditionalConverterUtilities.Apply(
                "<", true, decodeContext);
        }
    }

    internal sealed class CeqConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ceq;

        public override Func<IExtractContext, string[]> Apply(DecodeContext decodeContext)
        {
            return ConditionalConverterUtilities.Apply(
                "==", false, decodeContext);
        }
    }
}
