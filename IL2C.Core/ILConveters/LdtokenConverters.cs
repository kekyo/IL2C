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
    internal sealed class LdtokenConverters : InlineMemberConverter
    {
        public override OpCode OpCode => OpCodes.Ldtoken;

        public override ExpressionEmitter Prepare(
            IMemberInformation member, DecodeContext decodeContext)
        {
            // ECMA-335 III.4.17 ldtoken - load the runtime representation of a metadata

            var field = member as IFieldInformation;
            if (field != null)
            {
                if (field.DeclaredValue == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid declared value: Location={0}, FieldType={1}",
                        decodeContext.CurrentCode.RawLocation,
                        field.FriendlyName);
                }

                var resourceData = (byte[])field.DeclaredValue;
                var declaredValueName = decodeContext.PrepareContext.
                    RegisterDeclaredValues(field, resourceData);

                // HACK: Push RuntimeFieldHandle with specific declared values hint.
                //   (Prepare to call the "RuntimeHelpers.InitializeArray") method, see the CallConverter.)
                var symbol = decodeContext.PushStack(
                    decodeContext.PrepareContext.MetadataContext.RuntimeFieldHandle,
                    declaredValueName);

                // Register referenced field type (at the file scope).
                decodeContext.PrepareContext.RegisterType(field.FieldType, decodeContext.Method);

                // Store into RuntimeFieldHandle structure.
                return (extractContext, _) => new[] {
                    string.Format(
                        "{0}.size__ = {1}",
                        extractContext.GetSymbolName(symbol),
                        resourceData.Length),
                    string.Format(
                        "{0}.field__ = {1}",
                        extractContext.GetSymbolName(symbol),
                        declaredValueName) };
            }

            throw new InvalidProgramSequenceException(
                "Unknown token: Location={0}, TokenType={1}",
                decodeContext.CurrentCode.RawLocation,
                member.FriendlyName);
        }
    }
}
