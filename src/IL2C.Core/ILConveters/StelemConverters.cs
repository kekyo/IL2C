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
    internal static class StelemConverterUtilities
    {
        public static ExpressionEmitter Prepare(
            Func<ITypeInformation, bool> validateElementValueType,
            Func<ITypeInformation, ITypeInformation, bool> validateElementType,
            Func<ITypeInformation, string> arrayCTypeSymbol,
            DecodeContext decodeContext)
        {
            // ECMA-335 III.4.26 stelem.<type> - store element to array

            var siValue = decodeContext.PopStack();
            if (!validateElementValueType(siValue.TargetType))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid store type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siValue.TargetType.FriendlyName);
            }

            var siIndex = decodeContext.PopStack();
            if (!(siIndex.TargetType.IsInt32StackFriendlyType || siIndex.TargetType.IsIntPtrStackFriendlyType))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid index type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siIndex.TargetType.FriendlyName);
            }

            var siArray = decodeContext.PopStack();
            if (!(siArray.TargetType.IsArray && validateElementType(siArray.TargetType.ElementType, siValue.TargetType)))
            {
                throw new InvalidProgramSequenceException(
                    "Invalid array element type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siArray.TargetType.FriendlyName);
            }

            return (extractContext, _) => new[] {
                string.Format("il2c_array_item({0}, {1}, {2}) = {3}",
                    extractContext.GetSymbolName(siArray),
                    arrayCTypeSymbol(siArray.TargetType.ElementType),
                    extractContext.GetSymbolName(siIndex),
                    extractContext.GetRightExpression(siArray.TargetType.ElementType, siValue)) };
        }
    }

    internal sealed class Stelem_i1ConvertersConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stelem_I1;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return StelemConverterUtilities.Prepare(
                elementValueType => elementValueType.IsNumericPrimitive,
                (elementType, elementValueType) => elementType.IsInt32StackFriendlyType || elementType.IsIntPtrStackFriendlyType,
                arrayType => arrayType.MangledUniqueName,
                decodeContext
                );
        }
    }

    internal sealed class Stelem_i2ConvertersConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stelem_I2;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return StelemConverterUtilities.Prepare(
                elementValueType => elementValueType.IsNumericPrimitive,
                (elementType, elementValueType) => elementType.IsInt32StackFriendlyType || elementType.IsIntPtrStackFriendlyType,
                arrayType => arrayType.MangledUniqueName,
                decodeContext
                );
        }
    }

    internal sealed class Stelem_i4ConvertersConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stelem_I4;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return StelemConverterUtilities.Prepare(
                elementValueType => elementValueType.IsNumericPrimitive,
                (elementType, elementValueType) => elementType.IsInt32StackFriendlyType || elementType.IsIntPtrStackFriendlyType,
                arrayType => arrayType.MangledUniqueName,
                decodeContext
                );
        }
    }

    internal sealed class Stelem_i8ConvertersConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stelem_I8;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return StelemConverterUtilities.Prepare(
                elementValueType => elementValueType.IsNumericPrimitive,
                (elementType, elementValueType) => elementType.IsInt64StackFriendlyType,
                arrayType => arrayType.MangledUniqueName,
                decodeContext
                );
        }
    }

    internal sealed class Stelem_r4ConvertersConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stelem_R4;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return StelemConverterUtilities.Prepare(
                elementValueType => elementValueType.IsFloatStackFriendlyType,
                (elementType, elementValueType) => elementType.IsFloatStackFriendlyType,
                arrayType => arrayType.MangledUniqueName,
                decodeContext
                );
        }
    }

    internal sealed class Stelem_r8ConvertersConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stelem_R8;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return StelemConverterUtilities.Prepare(
                elementValueType => elementValueType.IsFloatStackFriendlyType,
                (elementType, elementValueType) => elementType.IsFloatStackFriendlyType,
                arrayType => arrayType.MangledUniqueName,
                decodeContext
                );
        }
    }

    internal sealed class Stelem_refConvertersConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stelem_Ref;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return StelemConverterUtilities.Prepare(
                elementValueType => elementValueType.IsReferenceType,
                (elementType, elementValueType) => elementType.IsAssignableFrom(elementValueType),
                arrayType => arrayType.CLanguageTypeName,
                decodeContext
                );
        }
    }

    internal sealed class Stelem_anyConvertersConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Stelem_Any;

        public override ExpressionEmitter Prepare(ITypeInformation operand, DecodeContext decodeContext)
        {
            return StelemConverterUtilities.Prepare(
                elementValueType => operand.IsAssignableFrom(elementValueType),
                (elementType, elementValueType) => elementType.IsAssignableFrom(elementValueType),
                arrayType => operand.CLanguageTypeName,
                decodeContext
                );
        }
    }
}
