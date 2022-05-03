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
    internal static class LdlocConverterUtilities
    {
        private static ExpressionEmitter Prepare(
            ILocalVariableInformation target, ITypeInformation targetType, DecodeContext decodeContext, bool isReference)
        {
            targetType = isReference ? targetType.MakeByReference() : targetType;
                
            var symbol = decodeContext.PushStack(targetType);

            return (extractContext, _) => new[] { string.Format(
                "{0} = {1}{2}",
                extractContext.GetSymbolName(symbol),
                // NOTE: Don't check "targetType.IsByReference" instead "isReference."
                //   Because it's maybe double encoded byref type.
                isReference ? "&" : string.Empty,
                extractContext.GetSymbolName(target)) };
        }

        public static ExpressionEmitter Prepare(
            int localIndex, DecodeContext decodeContext, bool isReference = false)
        {
            var local = decodeContext.Method.LocalVariables[localIndex];
            return Prepare(local, local.TargetType, decodeContext, isReference);
        }

        public static ExpressionEmitter Prepare(
            VariableInformation localVariable, DecodeContext decodeContext, bool isReference = false)
        {
            var local = decodeContext.Method.LocalVariables[localVariable.Index];
            return Prepare(local, local.TargetType, decodeContext, isReference);
        }
    }

    internal sealed class Ldloc_0Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_0;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Prepare(0, decodeContext);
        }
    }

    internal sealed class Ldloc_1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_1;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Prepare(1, decodeContext);
        }
    }

    internal sealed class Ldloc_2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_2;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Prepare(2, decodeContext);
        }
    }

    internal sealed class Ldloc_3Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_3;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Prepare(3, decodeContext);
        }
    }

    internal sealed class Ldloc_SConverter : ShortInlineVarConverter
    {
        public override OpCode OpCode => OpCodes.Ldloc_S;

        public override ExpressionEmitter Prepare(
            VariableInformation operand, DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Prepare(operand, decodeContext);
        }
    }

    internal sealed class Ldloca_sConverter : ShortInlineVarConverter
    {
        public override OpCode OpCode => OpCodes.Ldloca_S;

        public override ExpressionEmitter Prepare(
            VariableInformation operand, DecodeContext decodeContext)
        {
            return LdlocConverterUtilities.Prepare(operand, decodeContext, true);
        }
    }
}
