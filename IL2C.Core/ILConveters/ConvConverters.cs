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
    internal sealed class Conv_i1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_I1;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            // See also: ECMA-335: III.1.5 Operand type table - Conversion Operations

            var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.SByteType);

            // HACK: On gcc 4, if only uses int16_t cast expression, result may causes INT16_MIN value.
            //   On Visual C++ result is good.
            //   This workaround makes good result, we have to use downgrade cast step by step "F --> int32 --> int8"
            return (extractContext, _) => new[] { string.Format(
                "{0} = (int8_t)(int32_t){1}",
                extractContext.GetSymbolName(result),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Conv_i2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_I2;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            // See also: ECMA-335: III.1.5 Operand type table - Conversion Operations

            var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int16Type);

            // HACK: On gcc 4, if only uses int16_t cast expression, result may causes INT16_MIN value.
            //   On Visual C++ result is good.
            //   This workaround makes good result, we have to use downgrade cast step by step "F --> int32 --> int16"
            return (extractContext, _) => new[] { string.Format(
                "{0} = (int16_t)(int32_t){1}",
                extractContext.GetSymbolName(result),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Conv_i4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_I4;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            // See also: ECMA-335: III.1.5 Operand type table - Conversion Operations

            var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
            return (extractContext, _) => new[] { string.Format(
                "{0} = (int32_t){1}",
                extractContext.GetSymbolName(result),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Conv_i8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_I8;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int64Type);
            return (extractContext, _) => new[] { string.Format(
                "{0} = (int64_t){1}",
                extractContext.GetSymbolName(result),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Conv_iConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_I;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            // See also: ECMA-335: III.1.5 Operand type table - Conversion Operations

            var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
            return (extractContext, _) => new[] { string.Format(
                "{0} = (intptr_t){1}",
                extractContext.GetSymbolName(result),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Conv_u1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_U1;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.ByteType);

            // HACK: On gcc 4, if only uses int16_t cast expression, result may causes INT16_MIN value.
            //   On Visual C++ result is good.
            //   This workaround makes good result, we have to use downgrade cast step by step "F --> uint32 --> uint8"
            return (extractContext, _) => new[] { string.Format(
                "{0} = (uint8_t)(uint32_t){1}",
                extractContext.GetSymbolName(result),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Conv_u2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_U2;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.UInt16Type);
            return (extractContext, _) => new[] { string.Format(
                "{0} = (uint16_t){1}",
                extractContext.GetSymbolName(result),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Conv_u4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_U4;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.UInt32Type);
            return (extractContext, _) => new[] { string.Format(
                "{0} = (uint32_t){1}",
                extractContext.GetSymbolName(result),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Conv_u8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_U8;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.UInt64Type);
            return (extractContext, _) => new[] { string.Format(
                "{0} = (uint64_t){1}",
                extractContext.GetSymbolName(result),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Conv_uConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_U;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (siFrom.TargetType.IsNumericPrimitive == false)
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to numeric type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.UIntPtrType);
            return (extractContext, _) => new[] { string.Format(
                "{0} = (uintptr_t){1}",
                extractContext.GetSymbolName(result),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Conv_r4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_R4;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (!(siFrom.TargetType.IsSingleType || siFrom.TargetType.IsDoubleType))
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to floating point type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.SingleType);
            return (extractContext, _) => new[] { string.Format(
                "{0} = (float){1}",
                extractContext.GetSymbolName(result),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Conv_r8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Conv_R8;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();
            if (!(siFrom.TargetType.IsSingleType || siFrom.TargetType.IsDoubleType))
            {
                throw new InvalidProgramSequenceException(
                    "Cannot convert to floating point type: Location={0}, FromType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.DoubleType);
            return (extractContext, _) => new[] { string.Format(
                "{0} = (double){1}",
                extractContext.GetSymbolName(result),
                extractContext.GetSymbolName(siFrom)) };
        }
    }
}
