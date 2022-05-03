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

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal static class StlocConverterUtilities
    {
        private static ExpressionEmitter Prepare(
            ILocalVariableInformation target,
            ITypeInformation targetType,
            DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();

            var codeInformation = decodeContext.CurrentCode;

            return (extractContext, _) =>
            {
                var rightExpression = extractContext.GetRightExpression(targetType, si);
                if (rightExpression == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid store operation: Location={0}, StackType={1}, LocalType={2}, SymbolName={3}",
                        codeInformation.RawLocation,
                        si.TargetType.FriendlyName,
                        targetType.FriendlyName,
                        target);
                }

                return new[] { string.Format(
                    "{0} = {1}",
                    extractContext.GetSymbolName(target),
                    rightExpression) };
            };
        }

        public static ExpressionEmitter Prepare(
            int localIndex,
            DecodeContext decodeContext)
        {
            var local = decodeContext.Method.LocalVariables[localIndex];
            return Prepare(local, local.TargetType, decodeContext);
        }

        public static ExpressionEmitter Prepare(
            VariableInformation localVariable,
            DecodeContext decodeContext)
        {
            var local = decodeContext.Method.LocalVariables[localVariable.Index];
            return Prepare(local, local.TargetType, decodeContext);
        }
    }

    internal sealed class Stloc_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_0;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return StlocConverterUtilities.Prepare(0, decodeContext);
        }
    }

    internal sealed class Stloc_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_1;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return StlocConverterUtilities.Prepare(1, decodeContext);
        }
    }

    internal sealed class Stloc_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_2;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return StlocConverterUtilities.Prepare(2, decodeContext);
        }
    }

    internal sealed class Stloc_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_3;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return StlocConverterUtilities.Prepare(3, decodeContext);
        }
    }

    internal sealed class Stloc_SConverter : ShortInlineVarConverter
    {
        public override OpCode OpCode => OpCodes.Stloc_S;

        public override ExpressionEmitter Prepare(
            VariableInformation operand, DecodeContext decodeContext)
        {
            return StlocConverterUtilities.Prepare(operand, decodeContext);
        }
    }
}
