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
using IL2C.Metadata;

namespace IL2C.ILConverters
{
    internal static class ArithmeticalConverterUtilities
    {
        public enum BinaryOperators
        {
            Add,
            Sub,
            Mul,
            Div,
            Rem
        }

        public static ExpressionEmitter Prepare(BinaryOperators binaryOperator, DecodeContext decodeContext)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            char opChar;
            switch (binaryOperator)
            {
                case BinaryOperators.Add: opChar = '+'; break;
                case BinaryOperators.Sub: opChar = '-'; break;
                case BinaryOperators.Mul: opChar = '*'; break;
                case BinaryOperators.Div: opChar = '/'; break;
                case BinaryOperators.Rem: opChar = '%'; break;
                default: throw new Exception();
            }

            // See also: ECMA-335: III.1.5 Operand type table - Binary Numeric Operations

            // Int32 = (Int32) op (Int32)
            if (si0.TargetType.IsInt32StackFriendlyType && si1.TargetType.IsInt32StackFriendlyType)
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
                return (extractContext, _) => new[] { string.Format(
                    "{0} = {1} {2} {3}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    opChar,
                    extractContext.GetSymbolName(si1)) };
            }

            // Int64 = (Int64) op (Int64)
            if (si0.TargetType.IsInt64StackFriendlyType && si1.TargetType.IsInt64StackFriendlyType)
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int64Type);
                return (extractContext, _) => new[] { string.Format(
                    "{0} = {1} {2} {3}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    opChar,
                    extractContext.GetSymbolName(si1)) };
            }

            // Double = (Float) op (Float)
            if (si0.TargetType.IsFloatStackFriendlyType && si1.TargetType.IsFloatStackFriendlyType &&
                (binaryOperator == BinaryOperators.Rem))
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.DoubleType);

                // Use special runtime function.
                return (extractContext, _) => new[] { string.Format(
                    "{0} = il2c_fmod({1}, {2})",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    extractContext.GetSymbolName(si1)) };
            }

            // Double = (Float) op (Float)
            if (si0.TargetType.IsFloatStackFriendlyType && si1.TargetType.IsFloatStackFriendlyType)
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.DoubleType);
                return (extractContext, _) => new[] { string.Format(
                    "{0} = (double){1} {2} (double){3}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    opChar,
                    extractContext.GetSymbolName(si1)) };
            }

            // ByRef = (Int32) + (ByRef)
            if (si0.TargetType.IsInt32StackFriendlyType && (si1.TargetType.IsByReference) &&
                (binaryOperator == BinaryOperators.Add))
            {
                var result = decodeContext.PushStack(si1.TargetType);
                return (extractContext, _) => new[] { string.Format(
                    "{0} = ({1})((intptr_t){2} + (intptr_t){3})",
                    extractContext.GetSymbolName(result),
                    si1.TargetType.CLanguageTypeName,
                    extractContext.GetSymbolName(si0),
                    extractContext.GetSymbolName(si1)) };
            }

            // ByRef = (IntPtr) + (ByRef)
            if (si0.TargetType.IsIntPtrStackFriendlyType && (si1.TargetType.IsByReference) &&
                (binaryOperator == BinaryOperators.Add))
            {
                var result = decodeContext.PushStack(si1.TargetType);
                return (extractContext, _) => new[] { string.Format(
                    "{0} = ({1})((intptr_t){2} + (intptr_t){3})",
                    extractContext.GetSymbolName(result),
                    si1.TargetType.CLanguageTypeName,
                    extractContext.GetSymbolName(si0),
                    extractContext.GetSymbolName(si1)) };
            }

            // ByRef = (ByRef) +/- (Int32|IntPtr)
            if ((si0.TargetType.IsByReference || si0.TargetType.IsArray) &&
                (si1.TargetType.IsInt32StackFriendlyType || si1.TargetType.IsIntPtrStackFriendlyType) &&
                ((binaryOperator == BinaryOperators.Add) || (binaryOperator == BinaryOperators.Sub)))
            {
                var result = decodeContext.PushStack(si0.TargetType);
                return (extractContext, _) => new[] { string.Format(
                    "{0} = ({1})((intptr_t){2} {3} (intptr_t){4})",
                    extractContext.GetSymbolName(result),
                    si0.TargetType.CLanguageTypeName,
                    extractContext.GetSymbolName(si0),
                    opChar,
                    extractContext.GetSymbolName(si1)) };
            }

            // ByRef = (ByRef) - (ByRef)
            if (si0.TargetType.IsByReference && si1.TargetType.IsByReference &&
                (binaryOperator == BinaryOperators.Sub))
            {
                var result = decodeContext.PushStack(si0.TargetType);
                return (extractContext, _) => new[] { string.Format(
                    "{0} = ({1})((intptr_t){2} - (intptr_t){3})",
                    extractContext.GetSymbolName(result),
                    si0.TargetType.CLanguageTypeName,
                    extractContext.GetSymbolName(si0),
                    extractContext.GetSymbolName(si1)) };
            }

            // IntPtr = (Int32|IntPtr) op (Int32|IntPtr)
            if ((si0.TargetType.IsInt32StackFriendlyType || si0.TargetType.IsIntPtrStackFriendlyType) &&
                (si1.TargetType.IsInt32StackFriendlyType || si1.TargetType.IsIntPtrStackFriendlyType))
            {
                var result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.IntPtrType);
                return (extractContext, _) => new[] { string.Format(
                    "{0} = (intptr_t){1} {2} (intptr_t){3}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    opChar,
                    extractContext.GetSymbolName(si1)) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown arithmetical operation: Location={0}, Op={1}, Type0={2}, Type1={3}",
                decodeContext.CurrentCode.RawLocation,
                binaryOperator,
                si0.TargetType.FriendlyName,
                si1.TargetType.FriendlyName);
        }
    }

    internal sealed class AddConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Add;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return ArithmeticalConverterUtilities.Prepare(
                ArithmeticalConverterUtilities.BinaryOperators.Add, decodeContext);
        }
    }

    internal sealed class SubConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Sub;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return ArithmeticalConverterUtilities.Prepare(
                ArithmeticalConverterUtilities.BinaryOperators.Sub, decodeContext);
        }
    }

    internal sealed class MulConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Mul;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return ArithmeticalConverterUtilities.Prepare(
                ArithmeticalConverterUtilities.BinaryOperators.Mul, decodeContext);
        }
    }

    internal sealed class DivConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Div;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return ArithmeticalConverterUtilities.Prepare(
                ArithmeticalConverterUtilities.BinaryOperators.Div, decodeContext);
        }
    }

    internal sealed class RemConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Rem;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return ArithmeticalConverterUtilities.Prepare(
                ArithmeticalConverterUtilities.BinaryOperators.Rem, decodeContext);
        }
    }

    internal sealed class NotConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Not;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var si0 = decodeContext.PopStack();

            if (!(si0.TargetType.IsIntegerPrimitive && !si0.TargetType.IsCharType))
                throw new InvalidProgramSequenceException(
                    "Invalid arithmetical NOT operation: Location={0}, Type0={1}",
                    decodeContext.CurrentCode.RawLocation,
                    si0.TargetType.FriendlyName);

            var result = decodeContext.PushStack(si0.TargetType);
            
            return (extractContext, _) => new[] { string.Format(
                    "{0} = ~{1}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0)) };
        }
    }

    internal enum ShiftDirection
    {
        Left, Right
    }

    internal abstract class ShiftConverter : InlineNoneConverter
    {
        public abstract ShiftDirection Direction { get; }

        public ExpressionEmitter Prepare(DecodeContext decodeContext, Func<ILocalVariableInformation, string> cast)
        {
            var si1 = decodeContext.PopStack();
            var si0 = decodeContext.PopStack();

            if (si0.TargetType.IsFloatStackFriendlyType || si0.TargetType.IsByReference || !si1.TargetType.IsInt32Type)
                throw new InvalidProgramSequenceException(
                    "Invalid arithmetical NOT operation: Location={0}, Type0={1}",
                    decodeContext.CurrentCode.RawLocation,
                    si0.TargetType.FriendlyName);

            var result = decodeContext.PushStack(si0.TargetType);

            if (cast == null)
            {
                return (extractContext, _) => new[] { string.Format(
                    "{0} = {1} {2} {3}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    Direction == ShiftDirection.Left ? "<<" : ">>",
                    extractContext.GetSymbolName(si1)) };
            }
            else
            {
                return (extractContext, _) => new[] { string.Format(
                    "{0} = ({4}){1} {2} {3}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0),
                    Direction == ShiftDirection.Left ? "<<" : ">>",
                    extractContext.GetSymbolName(si1),
                    cast(si0)) };
            }
        }
    }

    internal sealed class ShiftRightConverter : ShiftConverter
    {
        public override OpCode OpCode => OpCodes.Shr;

        public override ShiftDirection Direction => ShiftDirection.Right;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return Prepare(decodeContext, si => si.TargetType.IsInt32StackFriendlyType ? "int32_t" : "int64_t");
        }
    }
    
    internal sealed class ShiftLeftConverter : ShiftConverter
    {
        public override OpCode OpCode => OpCodes.Shl;

        public override ShiftDirection Direction => ShiftDirection.Left;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return Prepare(decodeContext, null);
        }
    }

    internal sealed class ShiftRightUnConverter : ShiftConverter
    {
        public override OpCode OpCode => OpCodes.Shr_Un;

        public override ShiftDirection Direction => ShiftDirection.Right;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return Prepare(decodeContext, si => si.TargetType.IsInt32StackFriendlyType ? "uint32_t" : "uint64_t");
        }
    }

    internal sealed class NegConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Neg;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var si0 = decodeContext.PopStack();
            Metadata.ILocalVariableInformation result;

            if (si0.TargetType.IsByReference)
                throw new InvalidProgramSequenceException(
                    "Invalid arithmetical NEG operation: Location={0}, Type0={1}",
                    decodeContext.CurrentCode.RawLocation,
                    si0.TargetType.FriendlyName);

            if (si0.TargetType.IsInt32StackFriendlyType)
            {
                result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int32Type);
            }
            else if (si0.TargetType.IsInt64StackFriendlyType)
            {   // Int64 = -(Int64)
                result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.Int64Type);
            }
            else
            {   // double = -(double)
                result = decodeContext.PushStack(decodeContext.PrepareContext.MetadataContext.DoubleType);
            }

            return (extractContext, _) => new[] { string.Format(
                    "{0} = -{1}",
                    extractContext.GetSymbolName(result),
                    extractContext.GetSymbolName(si0)) };
        }
    }
}
