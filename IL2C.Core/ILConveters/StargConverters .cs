﻿/////////////////////////////////////////////////////////////////////////////////////////////////
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
    internal static class StargConverterUtilities
    {
        public static ExpressionEmitter Prepare(
            int parameterIndex, DecodeContext decodeContext)
        {
            var si = decodeContext.PopStack();
            var parameter = decodeContext.Method.Parameters[parameterIndex];

            // TODO: check target and source type

            return (extractContext, _) => new[] { string.Format(
                "{0} = {1}",
                parameter.ParameterName,
                extractContext.GetSymbolName(si)) };
        }
    }

    internal sealed class StargSConverter : ShortInlineParamConverter
    {
        public override OpCode OpCode => OpCodes.Starg_S;

        public override ExpressionEmitter Prepare(VariableInformation operand, DecodeContext decodeContext)
        {
            return StargConverterUtilities.Prepare(operand.Index, decodeContext);
        }
    }

    internal sealed class StargConverter : InlineParamConverter
    {
        public override OpCode OpCode => OpCodes.Starg;

        public override ExpressionEmitter Prepare(VariableInformation operand, DecodeContext decodeContext)
        {
            return StargConverterUtilities.Prepare(operand.Index, decodeContext);
        }
    }
}
