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
    internal static class LdindConverterUtilities
    {
        public static ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            var siFrom = decodeContext.PopStack();

            // Require only managed refs
            if (!siFrom.TargetType.IsByReference)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid managed reference: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siFrom.TargetType.FriendlyName);
            }

            var targetType = siFrom.TargetType.ElementType;
            var symbol = decodeContext.PushStack(targetType);

            return (extractContext, _) => new[] { string.Format(
                "{0} = *{1}",
                extractContext.GetSymbolName(symbol),
                extractContext.GetSymbolName(siFrom)) };
        }
    }

    internal sealed class Ldind_u1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_U1;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_i2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_I2;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_i4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_I4;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_i8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_I8;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_i1Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_I1;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_u2Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_U2;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_u4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_U4;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_r4Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_R4;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_r8Converter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_R8;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_iConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_I;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    internal sealed class Ldind_refConverter : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldind_Ref;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }

    // It is just a generalized Ldind. C compiler handles struct copy
    internal sealed class LdobjConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Ldobj;

        public override ExpressionEmitter Prepare(Metadata.ITypeInformation operand, DecodeContext decodeContext)
        {
            // Note: note really need the operand in this case, since IL2C knows the type already
            return LdindConverterUtilities.Prepare(decodeContext);
        }
    }
}
