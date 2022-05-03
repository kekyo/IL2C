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
    internal static class LdargConverterUtilities
    {
        public static ExpressionEmitter Prepare(
            int parameterIndex, DecodeContext decodeContext, bool isReference)
        {
            var parameter = decodeContext.Method.Parameters[parameterIndex];
            var targetType = isReference ? parameter.TargetType.MakeByReference() : parameter.TargetType;
            var symbol = decodeContext.PushStack(targetType);

            return (extractContext, _) => new[] { string.Format(
                "{0} = {1}{2}",
                extractContext.GetSymbolName(symbol),
                // NOTE: Don't check "targetType.IsByReference" instead "isReference."
                //   Because it's maybe double encoded byref type.
                isReference ? "&" : string.Empty,
                parameter.ParameterName) };
        }
    }

    internal sealed class Ldarg_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_0;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Prepare(0, decodeContext, false);
        }
    }

    internal sealed class Ldarg_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_1;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Prepare(1, decodeContext, false);
        }
    }

    internal sealed class Ldarg_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_2;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Prepare(2, decodeContext, false);
        }
    }

    internal sealed class Ldarg_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_3;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Prepare(3, decodeContext, false);
        }
    }

    internal sealed class Ldarg_sConverter : ShortInlineParamConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg_S;

        public override ExpressionEmitter Prepare(
            VariableInformation operand, DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Prepare(operand.Index, decodeContext, false);
        }
    }

    internal sealed class LdargConverter : InlineParamConverter
    {
        public override OpCode OpCode => OpCodes.Ldarg;

        public override ExpressionEmitter Prepare(
            VariableInformation operand, DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Prepare(operand.Index, decodeContext, false);
        }
    }

    internal sealed class Ldarga_sConverter : ShortInlineParamConverter
    {
        public override OpCode OpCode => OpCodes.Ldarga_S;

        public override ExpressionEmitter Prepare(
            VariableInformation operand, DecodeContext decodeContext)
        {
            return LdargConverterUtilities.Prepare(operand.Index, decodeContext, true);
        }
    }
}
