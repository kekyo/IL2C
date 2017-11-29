using System;
using System.Collections.Generic;
using System.Diagnostics;

using Mono.Cecil;
using Mono.Cecil.Cil;

namespace IL2C.Translators
{
    public sealed class PreparedFunction
    {
        public readonly string MethodName;
        internal readonly string RawMethodName;
        internal readonly TypeReference ReturnType;
        public readonly Parameter[] Parameters;
        internal readonly PreparedILBody[] PreparedILBodies;
        internal readonly VariableDefinition[] LocalVariables;
        internal readonly SymbolInformation[] Stacks;

        private readonly IReadOnlyDictionary<int, string> labelNames;

        internal PreparedFunction(
            string methodName,
            string rawMethodName,
            TypeReference returnType,
            Parameter[] parameters,
            PreparedILBody[] preparedILBodies,
            VariableDefinition[] localVariables,
            SymbolInformation[] stacks,
            IReadOnlyDictionary<int, string> labelNames)
        {
            this.MethodName = methodName;
            this.RawMethodName = rawMethodName;
            this.ReturnType = returnType;
            this.Parameters = parameters;
            this.PreparedILBodies = preparedILBodies;
            this.LocalVariables = localVariables;
            this.Stacks = stacks;
            this.labelNames = labelNames;
        }

        internal PreparedFunction(
            string methodName,
            string rawMethodName,
            TypeReference returnType,
            Parameter[] parameters)
            : this(methodName, rawMethodName, returnType, parameters, null, null, null, null)
        {
        }

        public string ReturnTypeName => this.ReturnType.GetFullMemberName();

        public bool TryGetLabelName(Label label, out string labelName)
        {
            Debug.Assert(labelNames != null);

            return labelNames.TryGetValue(label.Offset, out labelName);
        }
    }
}
