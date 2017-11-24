using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;

namespace IL2C.Translators
{
    public struct Label
    {
        public readonly int ILByteIndex;

        public Label(int ilByteIndex)
        {
            this.ILByteIndex = ilByteIndex;
        }
    }

    public struct Parameter
    {
        public readonly string Name;
        public readonly Type ParameterType;

        public Parameter(string name, Type parameterType)
        {
            this.Name = name;
            this.ParameterType = parameterType;
        }
    }

    public struct PreparedOpCode
    {
        public readonly Label Label;
        internal readonly Func<IExtractContext, string[]> Generator;

        internal PreparedOpCode(Label label, Func<IExtractContext, string[]> generator)
        {
            this.Label = label;
            this.Generator = generator;
        }
    }

    public struct SymbolInformation
    {
        public readonly string SymbolName;
        public readonly Type TargetType;

        internal SymbolInformation(string symbolName, Type targetType)
        {
            this.SymbolName = symbolName;
            this.TargetType = targetType;
        }

        public bool Equals(SymbolInformation rhs)
        {
            return this.SymbolName.Equals(rhs.SymbolName)
                && this.TargetType.Equals(rhs.TargetType);
        }

        public override bool Equals(object rhs)
        {
            if (rhs is SymbolInformation)
            {
                return this.Equals((SymbolInformation)rhs);
            }
            else
            {
                return false;
            }
        }

        public override int GetHashCode()
        {
            return this.SymbolName.GetHashCode() ^ this.TargetType.GetHashCode();
        }
    }

    public sealed class PreparedFunction
    {
        public readonly string MethodName;
        public readonly string RawMethodName;
        public readonly Type ReturnType;
        public readonly Parameter[] Parameters;
        public readonly PreparedOpCode[] PreparedOpCodes;
        public readonly LocalVariableInfo[] LocalVariables;
        public readonly SymbolInformation[] Stacks;

        private readonly IReadOnlyDictionary<int, string> labelNames;

        internal PreparedFunction(
            string methodName,
            string rawMethodName,
            Type returnType,
            Parameter[] parameters,
            PreparedOpCode[] preparedOpCodes,
            LocalVariableInfo[] localVariables,
            SymbolInformation[] stacks,
            IReadOnlyDictionary<int, string> labelNames)
        {
            this.MethodName = methodName;
            this.RawMethodName = rawMethodName;
            this.ReturnType = returnType;
            this.Parameters = parameters;
            this.PreparedOpCodes = preparedOpCodes;
            this.LocalVariables = localVariables;
            this.Stacks = stacks;
            this.labelNames = labelNames;
        }

        internal PreparedFunction(
            string methodName,
            string rawMethodName,
            Type returnType,
            Parameter[] parameters)
            : this(methodName, rawMethodName, returnType, parameters, null, null, null, null)
        {
        }

        public bool TryGetLabelName(Label label, out string labelName)
        {
            Debug.Assert(labelNames != null);

            return labelNames.TryGetValue(label.ILByteIndex, out labelName);
        }
    }

    public static class AssemblyPreparer
    {
        private static IEnumerable<ILData> DecodeAndEnumerateOpCodes(
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
                yield return new ILData(label, ilc, operand);

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
                    from ilData in DecodeAndEnumerateOpCodes(dc)
                    let generator = ilData.ILConverter.Apply(ilData.Operand, dc)
                    select new PreparedOpCode(ilData.Label, generator))
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
