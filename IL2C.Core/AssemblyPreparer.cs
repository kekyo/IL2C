using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil;
using Mono.Cecil.Cil;

using IL2C.ILConveters;
using IL2C.Translators;

namespace IL2C
{
    public static class AssemblyPreparer
    {
        private struct ILBody
        {
            public readonly Label Label;
            public readonly ILConverter ILConverter;
            public readonly object Operand;

            public ILBody(Label label, ILConverter ilc, object operand)
            {
                this.Label = label;
                this.ILConverter = ilc;
                this.Operand = operand;
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

                var instruction = decodeContext.Current;
                if (Utilities.TryGetILConverter(instruction.OpCode, out var ilc) == false)
                {
                    throw new InvalidProgramSequenceException(
                        "Invalid opcode: MethodName={0}, OpCode={1}, Offset={2}",
                        decodeContext.MethodName,
                        instruction.OpCode.Name,
                        instruction.Offset);
                }

                yield return new ILBody(new Label(instruction.Offset), ilc, instruction.Operand);

                if (ilc.IsEndOfPath)
                {
                    yield break;
                }
            }
        }

        private static readonly SequencePoint[] empty = new SequencePoint[0];

        private static PreparedFunction PrepareMethod(
            IPrepareContext prepareContext,
            string methodName,
            string rawMethodName,
            TypeReference returnType,
            Parameter[] parameters,
            MethodBody body)
        {
            var localVariables = body.Variables
                // If found non named local variable, force named "local[n]__"
                .GroupBy(v => body.Method.DebugInformation.TryGetName(v, out var name) ? name : "local")
                // If contains both named symbol each different scope (in the method by C#'s block), try to named with index number.
                .SelectMany(g =>
                {
                    var list = g.ToArray();
                    return (list.Length >= 2)
                        ? list.Select((v, index) => new {
                            Name = string.Format("{0}{1}", g.Key, index),
                            Type = v.VariableType,
                            Index = v.Index })
                        : new[] { new {
                            Name = string.Format("{0}", g.Key),
                            Type = list[0].VariableType,
                            Index = list[0].Index} };
                })
                .OrderBy(e => e.Index)
                .Select((e, index) =>
                {
                    Debug.Assert(e.Index == index);
                    return new SymbolInformation(e.Name, e.Type);
                })
                .ToArray();

            foreach (var local in localVariables)
            {
                prepareContext.RegisterType(local.TargetType);
            }

            var decodeContext = new DecodeContext(
                body.Method.Module,
                methodName,
                returnType,
                parameters,
                localVariables,
                body.Instructions.ToArray(),
                prepareContext);

            // It gathers sequence point informations.
            // It will use writing the line preprocessor directive.
            var sequencePoints =
                (from sp in body.Method.DebugInformation.SequencePoints
                 where !sp.IsHidden
                 group sp by sp.Offset into g
                 let sps = g.OrderBy(sp => sp.Offset).ToArray()
                 where sps.Length >= 1
                 select new { g.Key, sps })
                .ToDictionary(g => g.Key, g => g.sps);

            // Important:
            //   It's core decoding sequence.
            //   The flow analysis can't predict by sequential path.
            //   So, it reorders by IL offset.
            var preparedILBodies = decodeContext
                .Traverse(dc => dc.TryDequeueNextPath() ? dc : null, true)
                .SelectMany(dc =>
                    from ilBody in DecodeAndEnumerateILBodies(dc)
                    let sps = sequencePoints.UnsafeGetValue(ilBody.Label.Offset, empty)
                    let generator = ilBody.ILConverter.Apply(ilBody.Operand, dc)
                    select new PreparedILBody(
                        ilBody.Label,
                        generator,
                        dc.UniqueCodeBlockIndex,
                        sps,
                        ilBody.ILConverter.OpCode,
                        ilBody.Operand,
                        dc.DecodingPathNumber))
                .OrderBy(ilb => ilb.UniqueCodeBlockIndex)
                .ThenBy(ilb => ilb.Label.Offset)
                .ToArray();

            var stacks = decodeContext
                .ExtractStacks()
                .ToArray();

            var labelNames = decodeContext
                .ExtractLabelNames();

            return new PreparedFunction(
                methodName,
                rawMethodName,
                returnType,
                parameters,
                preparedILBodies,
                localVariables,
                stacks,
                labelNames,
                body.Method.IsVirtual ? (int?)body.Method.GetMethodOverloadIndex() : null);
        }

        private static PreparedFunction PrepareAbstractMethod(
            IPrepareContext prepareContext,
            string methodName,
            string rawMethodName,
            TypeReference returnType,
            Parameter[] parameters,
            bool isInterface,
            int slotIndex)
        {
            // TODO: throw
            //prepareContext.RegisterIncludeFile("assert.h");

            return new PreparedFunction(
                methodName,
                rawMethodName,
                returnType,
                parameters,
                isInterface,
                slotIndex);
        }

        private static PreparedFunction PreparePInvokeMethod(
            IPrepareContext prepareContext,
            string methodName,
            string rawMethodName,
            TypeReference returnType,
            Parameter[] parameters,
            PInvokeInfo pinvokeInfo)
        {
            // TODO: Switch DllImport.Value include direction to library direction.
            if (string.IsNullOrWhiteSpace(pinvokeInfo.Module.Name))
            {
                throw new InvalidProgramSequenceException(
                    "Not given DllImport attribute argument. Name={0}",
                    methodName);
            }

            prepareContext.RegisterPrivateIncludeFile(pinvokeInfo.Module.Name);

            return new PreparedFunction(
                methodName,
                rawMethodName,
                returnType,
                parameters,
                false,
                null);
        }

        private static PreparedFunction PrepareMethod(
            IPrepareContext prepareContext,
            MethodDefinition method)
        {
            var methodName = method.GetFullMemberName(MethodNameTypes.Index)
                .ManglingSymbolName();
            var returnType = method.ReturnType?.Resolve() ?? method.GetSafeVoidType();
            var parameters = method.GetSafeParameters();

            prepareContext.RegisterType(returnType);
            foreach (var parameter in parameters)
            {
                prepareContext.RegisterType(parameter.ParameterType);
            }

            if (method.IsPInvokeImpl)
            {
                var pinvokeInfo = method.PInvokeInfo;
                if (pinvokeInfo == null)
                {
                    throw new InvalidProgramSequenceException(
                        "Missing DllImport attribute at P/Invoke entry: Method={0}",
                        methodName);
                }

                return PreparePInvokeMethod(
                    prepareContext,
                    methodName,
                    method.Name,
                    returnType,
                    parameters,
                    pinvokeInfo);
            }

            if (method.IsAbstract)
            {
                Debug.Assert(method.Body == null);

                return PrepareAbstractMethod(
                    prepareContext,
                    methodName,
                    method.Name,
                    returnType,
                    parameters,
                    method.DeclaringType.IsInterface,
                    method.GetMethodOverloadIndex());
            }

            Debug.Assert(method.Body != null);

            return PrepareMethod(
                prepareContext,
                methodName,
                method.Name,
                returnType,
                parameters,
                method.Body);
        }

        internal static PreparedFunctions Prepare(
            TranslateContext translateContext,
            Func<MethodDefinition, bool> predict)
        {
            IPrepareContext prepareContext = translateContext;

            var allTypes = translateContext.Assembly.Modules
                .SelectMany(module => module.Types)
                .Where(type => type.IsValidDefinition())
                .ToArray();
            var types = allTypes
                .Where(type => !(type.IsPublic || type.IsNestedPublic || type.IsNestedFamily || type.IsNestedFamilyOrAssembly))
                .ToArray();

            // Lookup type references.
            foreach (var type in types)
            {
                prepareContext.RegisterType(type);
            }

            // Lookup fields.
            foreach (var field in types.SelectMany(type => type.Fields))
            {
                prepareContext.RegisterType(field.FieldType);
            }

            // Construct result.
            return new PreparedFunctions(allTypes
                .SelectMany(type => type.Methods)
                .Where(predict)
                .ToDictionary(
                    method => method,
                    method => PrepareMethod(prepareContext, method),
                    CecilHelper.MemberReferenceComparer<MethodDefinition>.Instance));
        }

        public static PreparedFunctions Prepare(TranslateContext translateContext)
        {
            return Prepare(
                translateContext,
                method => !method.IsConstructor || !method.IsStatic);
        }
    }
}
