/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

using System;

using Mono.Cecil.Cil;

using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal static class ConditionalConverterUtilities
    {
        public static ExpressionEmitter Prepare(
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
                return (extractContext, _) => new[] { string.Format(
                    "{1} = ({0}int32_t){2} {3} ({0}int32_t){4}",
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
                return (extractContext, _) => new[] { string.Format(
                    "{1} = ({0}int64_t){2} {3} ({0}int64_t){4}",
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
                return (extractContext, _) => new[] { string.Format(
                    "{1} = ({0}intptr_t){2} {3} ({0}intptr_t){4}",
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

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return ConditionalConverterUtilities.Prepare(
                ">", false, decodeContext);
        }
    }

    internal sealed class Cgt_unConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Cgt_Un;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return ConditionalConverterUtilities.Prepare(
                ">", true, decodeContext);
        }
    }

    internal sealed class CltConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Clt;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return ConditionalConverterUtilities.Prepare(
                "<", false, decodeContext);
        }
    }

    internal sealed class Clt_unConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Clt_Un;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return ConditionalConverterUtilities.Prepare(
                "<", true, decodeContext);
        }
    }

    internal sealed class CeqConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ceq;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return ConditionalConverterUtilities.Prepare(
                "==", false, decodeContext);
        }
    }
}
