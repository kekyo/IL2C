using System;
using System.Collections.Generic;
using System.Diagnostics;

using Mono.Cecil;
using Mono.Cecil.Cil;

namespace IL2C.Translators
{
    public enum FunctionTypes
    {
        Standard,
        Abstract,
        PInvoke
    }

    public sealed class PreparedFunction
    {
        public readonly FunctionTypes FunctionType;
        public readonly string MethodName;
        internal readonly string RawMethodName;
        internal readonly TypeReference ReturnType;
        public readonly Parameter[] Parameters;
        internal readonly PreparedILBody[] PreparedILBodies;
        internal readonly VariableDefinition[] LocalVariables;
        internal readonly SymbolInformation[] Stacks;

        private readonly IReadOnlyDictionary<int, string> labelNames;

        private PreparedFunction(
            string methodName,
            string rawMethodName,
            TypeReference returnType,
            Parameter[] parameters,
            PreparedILBody[] preparedILBodies,
            VariableDefinition[] localVariables,
            SymbolInformation[] stacks,
            IReadOnlyDictionary<int, string> labelNames,
            FunctionTypes functionType)
        {
            this.MethodName = methodName;
            this.RawMethodName = rawMethodName;
            this.ReturnType = returnType;
            this.Parameters = parameters;
            this.PreparedILBodies = preparedILBodies;
            this.LocalVariables = localVariables;
            this.Stacks = stacks;
            this.labelNames = labelNames;
            this.FunctionType = functionType;
        }

        internal PreparedFunction(
            string methodName,
            string rawMethodName,
            TypeReference returnType,
            Parameter[] parameters,
            PreparedILBody[] preparedILBodies,
            VariableDefinition[] localVariables,
            SymbolInformation[] stacks,
            IReadOnlyDictionary<int, string> labelNames)
            : this(
                  methodName,
                  rawMethodName,
                  returnType,
                  parameters,
                  preparedILBodies,
                  localVariables,
                  stacks,
                  labelNames,
                  FunctionTypes.Standard)
        {
        }

        internal PreparedFunction(
            string methodName,
            string rawMethodName,
            TypeReference returnType,
            Parameter[] parameters,
            bool isPInvoke)
            : this(
                  methodName,
                  rawMethodName,
                  returnType,
                  parameters,
                  null, null, null, null,
                  isPInvoke ? FunctionTypes.PInvoke : FunctionTypes.Abstract)
        {
        }

        public string ReturnTypeName => this.ReturnType.GetFullMemberName();

        public bool TryGetLabelName(Label label, out string labelName)
        {
            Debug.Assert(labelNames != null);

            if (labelNames.TryGetValue(label.Offset, out labelName) == false)
            {
                return false;
            }
            labelName = string.Format("IL_{0:x4}", label.Offset);
            return true;
        }
    }
}
