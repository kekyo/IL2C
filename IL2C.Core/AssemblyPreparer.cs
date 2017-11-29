using System;
using System.Collections.Generic;
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

        private static PreparedFunction PrepareMethod(
            IPrepareContext prepareContext,
            string methodName,
            string rawMethodName,
            TypeReference returnType,
            Parameter[] parameters,
            MethodBody body)
        {
            var localVariables = body.Variables.ToArray();

            var decodeContext = new DecodeContext(
                body.Method.Module,
                methodName,
                returnType,
                parameters,
                localVariables,
                body.Instructions.ToArray(),
                prepareContext);

            var preparedILBodies = decodeContext
                .Traverse(dc => dc.TryDequeueNextPath() ? dc : null, true)
                .SelectMany(dc =>
                    from ilBody in DecodeAndEnumerateILBodies(dc)
                    let generator = ilBody.ILConverter.Apply(ilBody.Operand, dc)
                    select new PreparedILBody(ilBody.Label, generator))
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
                labelNames);
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
                parameters);
        }

        private static PreparedFunction PrepareMethod(
            IPrepareContext prepareContext,
            MethodDefinition method)
        {
            var methodName = method.GetFullMemberName();
            var returnType = method.ReturnType?.Resolve() ?? method.GetSafeVoidType();
            var parameters = method.GetSafeParameters();

            prepareContext.RegisterType(returnType);
            parameters.ForEach(parameter => prepareContext.RegisterType(parameter.ParameterType));

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
            types.ForEach(prepareContext.RegisterType);

            // Lookup fields.
            types.SelectMany(type => type.Fields)
                .ForEach(field => prepareContext.RegisterType(field.FieldType));

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
