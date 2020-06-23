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
    internal sealed class LdlenConverters : InlineNoneConverter
    {
        public override OpCode OpCode => OpCodes.Ldlen;

        public override ExpressionEmitter Prepare(DecodeContext decodeContext)
        {
            // ECMA-335 III.4.12 ldlen - load the length of an array

            var siArray = decodeContext.PopStack();
            if (!siArray.TargetType.IsArray)
            {
                throw new InvalidProgramSequenceException(
                    "Invalid array type: Location={0}, StackType={1}",
                    decodeContext.CurrentCode.RawLocation,
                    siArray.TargetType.FriendlyName);
            }

            // push size by UIntPtr (not Int32.)
            var symbol = decodeContext.PushStack(
                decodeContext.PrepareContext.MetadataContext.UIntPtrType);

            return (extractContext, _) => new[] { string.Format(
                "{0} = (uintptr_t){1}->Length",
                extractContext.GetSymbolName(symbol),
                extractContext.GetSymbolName(siArray)) };
        }
    }
}
