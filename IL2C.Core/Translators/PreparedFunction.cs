using System;
using System.Collections.Generic;
using System.Diagnostics;

using IL2C.Metadata;

namespace IL2C.Translators
{
    public enum FunctionTypes
    {
        Standard,
        Virtual,
        InterfaceVirtual,
        DelegateVirtual,
        PInvoke
    }

    public enum AbstractTypes
    {
        Abstract,
        Interface,
        Delegate,
        PInvoke
    }

    public sealed class PreparedFunction
    {
        public readonly FunctionTypes FunctionType;
        public readonly string MethodName;
        internal readonly string RawMethodName;
        internal readonly ITypeInformation ReturnType;
        public readonly VariableInformation[] Parameters;
        internal readonly PreparedILBody[] PreparedILBodies;
        internal readonly SymbolInformation[] LocalVariables;
        internal readonly SymbolInformation[] Stacks;
        public readonly int SlotIndex;

        private readonly IReadOnlyDictionary<int, string> labelNames;

        private PreparedFunction(
            string methodName,
            string rawMethodName,
            ITypeInformation returnType,
            VariableInformation[] parameters,
            PreparedILBody[] preparedILBodies,
            SymbolInformation[] localVariables,
            SymbolInformation[] stacks,
            IReadOnlyDictionary<int, string> labelNames,
            FunctionTypes functionType,
            int slotIndex)
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
            this.SlotIndex = slotIndex;
        }

        internal PreparedFunction(
            string methodName,
            string rawMethodName,
            ITypeInformation returnType,
            VariableInformation[] parameters,
            PreparedILBody[] preparedILBodies,
            SymbolInformation[] localVariables,
            SymbolInformation[] stacks,
            IReadOnlyDictionary<int, string> labelNames,
            int? slotIndex)
            : this(
                  methodName,
                  rawMethodName,
                  returnType,
                  parameters,
                  preparedILBodies,
                  localVariables,
                  stacks,
                  labelNames,
                  slotIndex.HasValue ? FunctionTypes.Virtual : FunctionTypes.Standard,
                  slotIndex ?? -1)
        {
        }

        private static FunctionTypes ToFunctionType(AbstractTypes type)
        {
            switch (type)
            {
                case AbstractTypes.Abstract:
                    return FunctionTypes.Virtual;
                case AbstractTypes.Interface:
                    return FunctionTypes.InterfaceVirtual;
                case AbstractTypes.Delegate:
                    return FunctionTypes.DelegateVirtual;
                case AbstractTypes.PInvoke:
                    return FunctionTypes.PInvoke;
                default:
                    throw new Exception();
            }
        }

        internal PreparedFunction(
            string methodName,
            string rawMethodName,
            ITypeInformation returnType,
            VariableInformation[] parameters,
            AbstractTypes type,
            int? slotIndex)
            : this(
                  methodName,
                  rawMethodName,
                  returnType,
                  parameters,
                  null, null, null, null,
                  ToFunctionType(type),
                  slotIndex ?? -1)
        {
        }

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
