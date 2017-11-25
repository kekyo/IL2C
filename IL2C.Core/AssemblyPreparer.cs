using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
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
                var label = decodeContext.MakeLabel();
                if (decodeContext.TryDecode(out var ilc) == false)
                {
                    break;
                }

                var operand = ilc.DecodeOperand(decodeContext);
                yield return new ILBody(label, ilc, operand);

                if (ilc.IsEndOfPath)
                {
                    yield break;
                }
            }
        }

        private static PreparedFunction PrepareMethod(
            IPrepareContext prepareContext,
            Module module,
            string methodName,
            string rawMethodName,
            Type returnType,
            Parameter[] parameters,
            MethodBody body)
        {
            var localVariables = body.LocalVariables.ToArray();

            var decodeContext = new DecodeContext(
                module,
                methodName,
                returnType,
                parameters,
                localVariables,
                body.GetILAsByteArray(),
                prepareContext);

            var preparedOpCodes = decodeContext
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
                preparedOpCodes,
                localVariables,
                stacks,
                labelNames);
        }

        private static PreparedFunction PreparePInvokeMethod(
            IPrepareContext prepareContext,
            string methodName,
            string rawMethodName,
            Type returnType,
            Parameter[] parameters,
            DllImportAttribute dllImportAttribute)
        {
            // TODO: Switch DllImport.Value include direction to library direction.
            prepareContext.RegisterPrivateIncludeFile(dllImportAttribute.Value);

            return new PreparedFunction(
                methodName,
                rawMethodName,
                returnType,
                parameters);
        }

        private static PreparedFunction PrepareMethod(
            IPrepareContext prepareContext,
            MethodBase method)
        {
            var methodName = Utilities.GetFullMemberName(method);
            var mi = method as MethodInfo;
            var returnType = mi?.ReturnType ?? typeof(void);
            var parameters = method.GetSafeParameters();

            prepareContext.RegisterType(returnType);
            parameters.ForEach(parameter => prepareContext.RegisterType(parameter.ParameterType));

            var body = method.GetMethodBody();
            if (body != null)
            {
                return PrepareMethod(
                    prepareContext,
                    method.Module,
                    methodName,
                    method.Name,
                    returnType,
                    parameters,
                    body);
            }
            else if ((method.Attributes & MethodAttributes.PinvokeImpl)
                == MethodAttributes.PinvokeImpl)
            {
                var dllImportAttribute = method.GetCustomAttribute<DllImportAttribute>();
                if (dllImportAttribute == null)
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
                    dllImportAttribute);
            }
            else
            {
                throw new InvalidProgramSequenceException(
                    "Invalid method: Method={0}",
                    methodName);
            }
        }

        internal static IReadOnlyDictionary<MethodBase, PreparedFunction> Prepare(
            TranslateContext translateContext,
            Func<MethodBase, bool> predict)
        {
            IPrepareContext prepareContext = translateContext;

            var allTypes = translateContext.Assembly.GetTypes()
                .Where(type => type.IsValueType || type.IsClass)
                .ToArray();
            var types = allTypes
                .Where(type => !(type.IsPublic || type.IsNestedPublic || type.IsNestedFamily || type.IsNestedFamORAssem))
                .ToArray();

            // Lookup type references.
            types.ForEach(prepareContext.RegisterType);

            // Lookup fields.
            types.SelectMany(type => type.GetFields(
                    BindingFlags.Public | BindingFlags.NonPublic
                    | BindingFlags.Static | BindingFlags.Instance
                    | BindingFlags.DeclaredOnly))
                .ForEach(field => prepareContext.RegisterType(field.FieldType));

            // Construct result.
            return allTypes
                .SelectMany(type => type.GetMembers(
                    BindingFlags.Public | BindingFlags.NonPublic
                    | BindingFlags.Static | BindingFlags.Instance
                    | BindingFlags.DeclaredOnly))
                .OfType<MethodBase>()
                .Where(predict)
                .ToDictionary(method => method, method => PrepareMethod(prepareContext, method));
        }

        public static IReadOnlyDictionary<MethodBase, PreparedFunction> Prepare(
            TranslateContext translateContext)
        {
            return Prepare(translateContext, method => method is MethodInfo || !method.IsStatic);
        }
    }
}
