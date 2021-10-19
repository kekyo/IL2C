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
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil.Cil;

using IL2C.ILConverters;
using IL2C.Translators;
using IL2C.Metadata;
using IL2C.Internal;

namespace IL2C
{
    public static class AssemblyPreparer
    {
        private struct ILBody
        {
            public readonly Label Label;
            public readonly ILConverter ILConverter;
            public readonly ICodeInformation Code;

            public ILBody(Label label, ILConverter ilc, ICodeInformation code)
            {
                this.Label = label;
                this.ILConverter = ilc;
                this.Code = code;
            }
        }

        private static IEnumerable<ILBody> DecodeAndEnumerateILBodies(
            DecodeContext decodeContext)
        {
            while (true)
            {
                // TODO: Make simplist with Cecil's Instruction type.
                if (decodeContext.MoveNext() == false)
                {
                    break;
                }

                var code = decodeContext.CurrentCode;
                if (Utilities.TryGetILConverter(code.OpCode, out var ilc) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid opcode: Method={0}, OpCode={1}, Offset={2}",
                        decodeContext.Method.FriendlyName,
                        code.OpCode.Name,
                        code.Offset);
                }

                yield return new ILBody(new Label(code.Offset), ilc, code);

                if (ilc.IsEndOfPath)
                {
                    yield break;
                }
            }
        }

        private static readonly SequencePoint[] empty = new SequencePoint[0];

        private static PreparedMethodInformation PrepareMethodBody(
            IPrepareContext prepareContext,
            IMethodInformation method)
        {
            // TODO: move into MethodInformation
            var localVariables = method.LocalVariables.
                // If found non named local variable, force named "local[n]__"
                GroupBy(variable => variable).
                // If contains both named symbol each different scope (in the method by C#'s block), try to named with index number.
                SelectMany(g =>
                {
                    var list = g.ToArray();
                    return (list.Length >= 2) ?
                        list.Select((variable, index) => new LocalVariableInformation(
                            method,
                            variable.Index,
                            string.Format("{0}{1}", g.Key.UnsafeCLanguageSymbolName, index),
                            variable.TargetType)) :
                        new[] { new LocalVariableInformation(
                            method,
                            list[0].Index,
                            string.Format("{0}", g.Key.UnsafeCLanguageSymbolName),
                            list[0].TargetType) };
                }).
                OrderBy(e => e.Index).
#if DEBUG
                Select((e, index) =>
                {
                    Debug.Assert(e.Index == index);
                    return e;
                }).
#endif
                ToArray();

            foreach (var local in localVariables)
            {
                prepareContext.RegisterType(local.TargetType, method);
            }

            //////////////////////////////////////////////////////////////////////////////
            // Construct decode context

            var decodeContext = new DecodeContext(
                method,
                prepareContext);

            //////////////////////////////////////////////////////////////////////////////
            // Important:
            //   It's core decoding sequence.
            //   The flow analysis can't predict by sequential path.
            //   So, it reorders by IL offset.

            var emitters = decodeContext.
                Traverse(dc => dc.TryDequeueNextPath() ? dc : null, true).
                SelectMany(dc =>
                    from ilBody in DecodeAndEnumerateILBodies(dc)
                    let emitter = ilBody.ILConverter.Prepare(ilBody.Code.Operand, dc)
                    select new PreparedILBody(
                        ilBody.Label,
                        emitter,
                        dc.UniqueCodeBlockIndex,
                        ilBody.Code,
                        dc.DecodingPathNumber)).
                OrderBy(ilb => ilb.UniqueCodeBlockIndex).
                ThenBy(ilb => ilb.Label.Offset).
                ToDictionary(ilb => ilb.Label.Offset, ilb => ilb.Emitter);

            //////////////////////////////////////////////////////////////////////////////

            var stacks = decodeContext.
                ExtractStacks().
                ToArray();

            var labelNames = decodeContext.
                ExtractLabelNames();

            var catchVariables = decodeContext.
                ExtractCatchVariables();

            var leaveContinuations = decodeContext.
                ExtractLeaveContinuations();

            return new PreparedMethodInformation(
                method,
                stacks,
                labelNames,
                catchVariables,
                leaveContinuations,
                emitters);
        }

        private static PreparedMethodInformation PrepareMethod(
            IPrepareContext prepareContext,
            IMethodInformation method)
        {
            var returnType = method.ReturnType;
            var parameters = method.Parameters;

            prepareContext.RegisterType(returnType, method.CLanguageMemberScope);
            foreach (var parameter in parameters)
            {
                prepareContext.RegisterType(parameter.TargetType, method.CLanguageMemberScope);
            }

            // Pure abstract method (ignored.)
            if (method.IsVirtual && method.IsAbstract)
            {
                Debug.Assert(!method.HasBody);
                return null;
            }

            // Delegate constructor (ignored, it will be handled by the AssemblyWriter.)
            if (method.IsConstructor && method.DeclaringType.IsDelegate &&
                (method.Parameters.Length == 3) &&
                method.Parameters[1].TargetType.IsObjectType &&
                method.Parameters[2].TargetType.IsIntPtrType)
            {
                // Debug.Assert(!method.HasBody);  // Depended for the compiler (it has no body for Roslyn)
                return null;
            }

            // internalcall or DllImport
            if (method.IsExtern)
            {
                Debug.Assert(!method.HasBody);

                if (method.NativeMethod != null)
                {
                    if (string.IsNullOrWhiteSpace(method.NativeMethod.IncludeFileName))
                    {
                        throw new InvalidProgramSequenceException(
                            "Not given FunctionImport attribute argument. Name={0}",
                            method.FriendlyName);
                    }

                    // TODO: register library name.
                    prepareContext.RegisterImportIncludeFile(method.NativeMethod.IncludeFileName);
                    if (method.ReturnType.NativeType != null)
                    {
                        prepareContext.RegisterImportIncludeFile(method.ReturnType.NativeType.IncludeFileName);
                    }
                    foreach (var parameter in method.Parameters)
                    {
                        if (parameter.TargetType.NativeType != null)
                        {
                            prepareContext.RegisterImportIncludeFile(parameter.TargetType.NativeType.IncludeFileName);
                        }
                    }
                }
                else if (method.PInvokeInformation != null)
                {
                    if (string.IsNullOrWhiteSpace(method.PInvokeInformation.Module.Name))
                    {
                        throw new InvalidProgramSequenceException(
                            "Not given DllImport attribute argument. Name={0}",
                            method.FriendlyName);
                    }

                    // TODO: register library name.
                    //prepareContext.RegisterPrivateIncludeFile(method.PInvokeInformation.Module.Name);
                }

                // Construct dummy information.
                return new PreparedMethodInformation(
                    method,
                    null,
                    null,
                    null,
                    null,
                    null);
            }

            Debug.Assert(method.HasBody);

            return PrepareMethodBody(
                prepareContext,
                method);
        }

        internal static PreparedInformations Prepare(
            TranslateContext translateContext,
            Func<ITypeInformation, bool> predictType,
            Func<IMethodInformation, bool> predictMethod)
        {
            IPrepareContext prepareContext = translateContext;

            var allTypes = translateContext.Assembly.Modules.
                SelectMany(module => module.Types.Concat(module.Types.SelectMany(type => type.NestedTypes))).
                Where(predictType).
                Distinct().
                ToArray();

            // Lookup type references.
            foreach (var type in allTypes)
            {
                // Register used type.
                prepareContext.RegisterType(type, type.CLanguageMemberScope);

                if (type.BaseType != null)
                {
                    prepareContext.RegisterType(type.BaseType, type.CLanguageMemberScope);
                }

                foreach (var interfaceType in type.InterfaceTypes)
                {
                    prepareContext.RegisterType(type.BaseType, type.CLanguageMemberScope);
                }
            }

            // Lookup fields.
            foreach (var field in allTypes.SelectMany(type => type.Fields))
            {
                // Register field type.
                prepareContext.RegisterType(field.FieldType, field.CLanguageMemberScope);

                // Register include file from the native value.
                if (field.NativeValue != null)
                {
                    prepareContext.RegisterImportIncludeFile(field.NativeValue.IncludeFileName);
                }
            }

            // Construct result.
            return new PreparedInformations(
                allTypes,
                (from type in allTypes
                 from method in type.DeclaredMethods
                 where predictMethod(method)
                 let preparedMethod = PrepareMethod(prepareContext, method)
                 where preparedMethod != null
                 select preparedMethod).
                ToDictionary(
                    preparedMethod => preparedMethod.Method,
                    preparedMethod => preparedMethod));
        }

        public static PreparedInformations Prepare(TranslateContext translateContext)
        {
            return Prepare(
                translateContext,
                // All types
                type => true,
                // All methods
                method => true);
        }
    }
}
