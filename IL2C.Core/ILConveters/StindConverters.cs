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
    internal static class StindConverter_Utilities
    {
        public static ExpressionEmitter Prepare(
            DecodeContext decodeContext)
        {
            // NOTE: This method's sharing for the stind opcode family.
            //   IL2C can recognize target type implicitly.
            //   Because IL2C can type inference at evaluation stack, so don't need stind's opcode attribute.

            var siValue = decodeContext.PopStack();
            var siReference = decodeContext.PopStack();

            if (siReference.TargetType.IsByReference)
            {
                var dereferencedType = siReference.TargetType.ElementType;
                if (dereferencedType.IsAssignableFrom(siValue.TargetType) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid managed reference: Location={0}, ReferenceType={1}, Value={2}",
                        decodeContext.CurrentCode.RawLocation,
                        siReference.TargetType.FriendlyName,
                        siValue.TargetType.FriendlyName);
                }
            }
            else
            {
                throw new InvalidProgramSequenceException(
                    "Invalid type at stack: Location={0}, ReferenceType={1}, Value={2}",
                    decodeContext.CurrentCode.RawLocation,
                    siReference.TargetType.FriendlyName,
                    siValue.TargetType.FriendlyName);
            }

            var codeInformation = decodeContext.CurrentCode;

            return (extractContext, _) =>
            {
                var rightExpression = extractContext.GetRightExpression(
                    siReference.TargetType.ElementType, siValue);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid store operation: Location={0}, ReferenceType={1}, Value={2}",
                        codeInformation.RawLocation,
                    siReference.TargetType.FriendlyName,
                    siValue.TargetType.FriendlyName);
                }

                return new[] { string.Format(
                    "*{0} = {1}",
                    extractContext.GetSymbolName(siReference),
                    rightExpression) };
            };
        }
    }

    internal sealed class Stind_i1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stind_I1;

        public override ExpressionEmitter Prepare(
            DecodeContext decodeContext)
        {
            return StindConverter_Utilities.Prepare(decodeContext);
        }
    }

    internal sealed class Stind_i2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stind_I2;

        public override ExpressionEmitter Prepare(
            DecodeContext decodeContext)
        {
            return StindConverter_Utilities.Prepare(decodeContext);
        }
    }

    internal sealed class Stind_i4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stind_I4;

        public override ExpressionEmitter Prepare(
            DecodeContext decodeContext)
        {
            return StindConverter_Utilities.Prepare(decodeContext);
        }
    }

    internal sealed class Stind_i8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stind_I8;

        public override ExpressionEmitter Prepare(
            DecodeContext decodeContext)
        {
            return StindConverter_Utilities.Prepare(decodeContext);
        }
    }

    internal sealed class Stind_r4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stind_R4;

        public override ExpressionEmitter Prepare(
            DecodeContext decodeContext)
        {
            return StindConverter_Utilities.Prepare(decodeContext);
        }
    }

    internal sealed class Stind_r8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stind_R8;

        public override ExpressionEmitter Prepare(
            DecodeContext decodeContext)
        {
            return StindConverter_Utilities.Prepare(decodeContext);
        }
    }

    internal sealed class Stind_RefConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stind_Ref;

        public override ExpressionEmitter Prepare(
            DecodeContext decodeContext)
        {
            return StindConverter_Utilities.Prepare(decodeContext);
        }
    }

    // It is just a generalized Stind. C compiler handles struct copy
    internal sealed class StobjConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Stobj;

        public override ExpressionEmitter Prepare(Metadata.ITypeInformation operand, DecodeContext decodeContext)
        {
            // Note: note really need the operand in this case, since IL2C knows the type already
            return StindConverter_Utilities.Prepare(decodeContext);
        }
    }
}
