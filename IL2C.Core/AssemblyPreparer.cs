using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil.Cil;

using IL2C.ILConverters;
using IL2C.Translators;
using IL2C.Metadata;

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
                GroupBy(variable => variable.SymbolName).
                // If contains both named symbol each different scope (in the method by C#'s block), try to named with index number.
                SelectMany(g =>
                {
                    var list = g.ToArray();
                    return (list.Length >= 2)
                        ? list.Select((variable, index) => new VariableInformation(
                            method,
                            variable.Index,
                            string.Format("{0}{1}", g.Key, index),
                            variable.TargetType))
                        : new[] { new VariableInformation(
                            method,
                            list[0].Index,
                            string.Format("{0}", g.Key),
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
                prepareContext.RegisterType(local.TargetType);
            }

            var decodeContext = new DecodeContext(
                method,
                prepareContext);

            //////////////////////////////////////////////////////////////////////////////
            // Important:
            //   It's core decoding sequence.
            //   The flow analysis can't predict by sequential path.
            //   So, it reorders by IL offset.

            var generators = decodeContext.
                Traverse(dc => dc.TryDequeueNextPath() ? dc : null, true).
                SelectMany(dc =>
                    from ilBody in DecodeAndEnumerateILBodies(dc)
                    let generator = ilBody.ILConverter.Apply(ilBody.Code.Operand, dc)
                    select new PreparedILBody(
                        ilBody.Label,
                        generator,
                        dc.UniqueCodeBlockIndex,
                        ilBody.Code,
                        dc.DecodingPathNumber)).
                OrderBy(ilb => ilb.UniqueCodeBlockIndex).
                ThenBy(ilb => ilb.Label.Offset).
                ToDictionary(ilb => ilb.Label.Offset, ilb => ilb.Generator);

            //////////////////////////////////////////////////////////////////////////////

            var stacks = decodeContext.
                ExtractStacks().
                ToArray();

            var labelNames = decodeContext.
                ExtractLabelNames();

            return new PreparedMethodInformation(
                method,
                stacks,
                labelNames,
                generators);
        }

        private static PreparedMethodInformation PrepareMethod(
            IPrepareContext prepareContext,
            IMethodInformation method)
        {
            var returnType = method.ReturnType;
            var parameters = method.Parameters;

            prepareContext.RegisterType(returnType);
            foreach (var parameter in parameters)
            {
                prepareContext.RegisterType(parameter.TargetType);
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

                var pinvokeInfo = method.PInvokeInfo;
                if (pinvokeInfo != null)
                {
                    // TODO: Switch DllImport.Value include direction to library direction.
                    if (string.IsNullOrWhiteSpace(pinvokeInfo.Module.Name))
                    {
                        throw new InvalidProgramSequenceException(
                            "Not given DllImport attribute argument. Name={0}",
                            method.FriendlyName);
                    }

                    prepareContext.RegisterPrivateIncludeFile(pinvokeInfo.Module.Name);
                }

                // Construct dummy information.
                return new PreparedMethodInformation(
                    method,
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
                SelectMany(module => module.Types).
                Where(predictType).
                Distinct().
                ToArray();

            // Lookup type references.
            foreach (var type in allTypes)
            {
                prepareContext.RegisterType(type);
            }

            // Lookup fields.
            foreach (var field in allTypes.SelectMany(type => type.Fields))
            {
                prepareContext.RegisterType(field.FieldType);
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
                // The methods except type initializer.
                method => !(method.IsConstructor && method.IsStatic));
        }
    }
}
