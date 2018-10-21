using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

using Mono.Cecil;
using Mono.Cecil.Cil;

namespace IL2C.Metadata
{
    [Flags]
    public enum FriendlyNameTypes
    {
        Less = 0x00,
        FullName = 0x01,
        ArgumentTypes = 0x02,
        ArgumentNames = 0x03,
        Index = 0x08,
        Full = 0x0f,
        Mangled = 0x10,
    }

    public interface IMethodInformation : IMemberInformation
    {
        bool IsPublic { get; }
        bool IsFamily { get; }
        bool IsFamilyOrAssembly { get; }

        bool IsConstructor { get; }
        bool IsStatic { get; }
        bool IsVirtual { get; }
        bool IsAbstract { get; }
        bool IsSealed { get; }
        bool IsNewSlot { get; }
        bool IsExtern { get; }
        bool HasThis { get; }
        bool HasBody { get; }

        ITypeInformation ReturnType { get; }
        VariableInformation[] Parameters { get; }
        VariableInformation[] LocalVariables { get; }
        ICodeStream CodeStream { get; }
        int OverloadIndex { get; }

        string GetFriendlyName(FriendlyNameTypes type = FriendlyNameTypes.Full);
        VariableInformation[] GetParameters(ITypeInformation thisType);

        PInvokeInfo PInvokeInfo { get; }

        string CLanguageFunctionName { get; }
        string CLanguageVirtualFunctionDeclarationName { get; }
        string CLanguageRawFunctionPrototype { get; }
        string CLanguageFunctionPrototype { get; }
        string CLanguageFunctionTypePrototype { get; }
    }

    internal sealed class MethodInformation
        : MemberInformation<MethodReference, MethodDefinition>
        , IMethodInformation
    {
        private static readonly DebugInformation[] empty = new DebugInformation[0];

        private readonly Lazy<ITypeInformation> returnType;
        private readonly Lazy<VariableInformation[]> parameters;
        private readonly Lazy<VariableInformation[]> variables;
        private readonly Lazy<CodeStream> codeStreams;
        private readonly Lazy<int> overloadIndex;

        public MethodInformation(MethodReference method, ModuleInformation module)
            : base(method, module)
        {
            returnType = this.MetadataContext.LazyGetOrAddMember(
                () => this.Member.ReturnType,
                type => (type != null) ? new TypeInformation(type, module) : this.MetadataContext.VoidType);

            parameters = Lazy.Create(() => (method.HasThis)
                ? new[] { this.CreateThisParameterInformation(this.DeclaringType) }
                    .Concat(this.Member.Parameters.Select(this.ToParameterInformation))
                    .ToArray()
                : this.Member.Parameters
                    .Select(ToParameterInformation)
                    .ToArray());

            variables = Lazy.Create(() => this.Definition.Body.Variables
                .Select(variable => new VariableInformation(
                    this,
                    variable.Index,
                    this.Definition.Body.Method.DebugInformation.TryGetName(variable, out var name)
                        ? name
                        : string.Format("local{0}__", variable.Index),
                    this.MetadataContext.GetOrAddMember(
                        variable.VariableType,
                        variableType => new TypeInformation(
                            variableType,
                            this.MetadataContext.GetOrAddModule(
                                variableType.Module.Assembly,
                                variableType.Module,
                                (assembly, module_) => new ModuleInformation(
                                    module_,
                                    this.MetadataContext.GetOrAddAssembly(
                                        assembly,
                                        assembly_ => new AssemblyInformation(assembly_, this.MetadataContext))))))))
                .ToArray());

            codeStreams = Lazy.Create(() =>
                {
                    // It gathers sequence point informations.
                    // It will use writing the line preprocessor directive.
                    var paths = new Dictionary<string, string>();
                    var spd =
                        (from sp in this.Definition.DebugInformation.SequencePoints
                         where !sp.IsHidden
                         group sp by sp.Offset into g
                         let sps = g
                            .OrderBy(sp => sp.Offset)
                            .Select(sp => new DebugInformation(
                                paths.GetOrAdd(sp.Document.Url, sp.Document.Url),
                                sp.StartLine,
                                sp.StartColumn))
                            .ToArray()
                         where sps.Length >= 1
                         select new { g.Key, sps })
                        .ToDictionary(g => g.Key, g => g.sps);

                    var codeStream = new CodeStream();

                    object translateOperand(object operand)
                    {
                        var inst = operand as Instruction;
                        if (inst != null)
                        {
                            return codeStream[inst.Offset];
                        }

                        var parameter = operand as ParameterReference;
                        if (parameter != null)
                        {
                            return this.Parameters[this.HasThis ? (parameter.Index + 1) : parameter.Index];
                        }

                        var local = operand as VariableReference;
                        if (local != null)
                        {
                            return this.LocalVariables[local.Index];
                        }

                        var typeRef = operand as TypeReference;
                        if (typeRef != null)
                        {
                            return this.MetadataContext.GetOrAddMember(typeRef, t => new TypeInformation(t, module));
                        }

                        var fieldRef = operand as FieldReference;
                        if (fieldRef != null)
                        {
                            return this.MetadataContext.GetOrAddMember(fieldRef, f => new FieldInformation(f, module));
                        }

                        var methodRef = operand as MethodReference;
                        if (methodRef != null)
                        {
                            return this.MetadataContext.GetOrAddMember(methodRef, m => new MethodInformation(m, module));
                        }

                        return operand;
                    }

                    foreach (var inst in this.Definition.Body.Instructions
                        .OrderBy(instruction => instruction.Offset)
                        .Select(instruction => new CodeInformation(
                            this,
                            instruction.Offset,
                            instruction.OpCode,
                            instruction.Operand,
                            instruction.GetSize(),
                            spd.TryGetValue(instruction.Offset, out var sps) ? sps : empty,
                            translateOperand)))
                    {
                        codeStream.Add(inst.Offset, inst);
                    }
                    return codeStream;
                });

            overloadIndex = Lazy.Create(() =>
                {
                    var found = this.DeclaringType.CalculatedMethods
                        .Where(m => m.Name == this.Member.Name)
                        .OrderByStableAllOverloads()     // Stable by overload types.
                        .Select((m, i) => new { m, i })
                        .First(e => this.Equals(e.m));
                    return found.i;
                });
        }

        public override string MemberTypeName =>
            this.IsStatic
                ? "Static method"
                : this.IsAbstract
                    ? this.DeclaringType.IsInterface
                        ? "Interface method"
                        : "Abstract method"
                    : "Method";

        private VariableInformation CreateThisParameterInformation(ITypeInformation thisType) =>
            new VariableInformation(
                this,
                0,
                "this__",
                thisType.IsValueType ? thisType.MakeByReference() : thisType);

        private VariableInformation ToParameterInformation(ParameterReference parameter) =>
            new VariableInformation(
                this,
                this.HasThis ? (parameter.Index + 1) : parameter.Index,
                parameter.Name,
                this.MetadataContext.GetOrAddMember(
                    parameter.ParameterType,
                    type_ => new TypeInformation(
                        type_,
                        this.MetadataContext.GetOrAddModule(
                            type_.Module.Assembly,
                            type_.Module,
                            (assembly_, module_) => new ModuleInformation(
                                module_,
                                this.MetadataContext.GetOrAddAssembly(
                                    assembly_,
                                    assembly__ => new AssemblyInformation(assembly__, this.MetadataContext)))))));

        public override string MetadataTypeName => "Method";

        public override string FriendlyName =>
            this.GetFriendlyName(FriendlyNameTypes.ArgumentTypes | FriendlyNameTypes.ArgumentNames);

        public override string MangledName =>
            this.GetFriendlyName(FriendlyNameTypes.Index | FriendlyNameTypes.Mangled);

        public bool IsPublic =>
            this.Definition.IsPublic;
        public bool IsFamily =>
            this.Definition.IsFamily;
        public bool IsFamilyOrAssembly =>
            this.Definition.IsFamilyOrAssembly;

        public bool IsConstructor =>
            this.Definition.IsConstructor;
        public bool IsStatic =>
            this.Definition.IsStatic;
        public bool IsVirtual =>
            this.Definition.IsVirtual;
        public bool IsAbstract =>
            this.Definition.IsAbstract;
        public bool IsSealed =>
            this.Definition.IsFinal;
        public bool IsNewSlot =>
            this.Definition.IsNewSlot;
        public bool IsExtern =>
            this.Definition.IsPInvokeImpl || this.Definition.IsInternalCall;
        public bool HasThis =>
            this.Definition.HasThis;
        public bool HasBody => 
            this.Definition.HasBody;

        public ITypeInformation ReturnType =>
            returnType.Value;
        public VariableInformation[] Parameters =>
            parameters.Value;
        public VariableInformation[] LocalVariables =>
            variables.Value;
        public ICodeStream CodeStream =>
            codeStreams.Value;
        public int OverloadIndex =>
            overloadIndex.Value;

        private static bool FullName(FriendlyNameTypes type) =>
            (type & FriendlyNameTypes.FullName) == FriendlyNameTypes.FullName;

        private static bool IncludeNames(FriendlyNameTypes type) =>
            (type & FriendlyNameTypes.ArgumentNames) == FriendlyNameTypes.ArgumentNames;

        private static bool IncludeTypes(FriendlyNameTypes type) =>
            (type & FriendlyNameTypes.ArgumentTypes) == FriendlyNameTypes.ArgumentTypes;

        private static bool IncludeIndex(FriendlyNameTypes type) =>
            (type & FriendlyNameTypes.Index) == FriendlyNameTypes.Index;

        private static bool Mangled(FriendlyNameTypes type) =>
            (type & FriendlyNameTypes.Mangled) == FriendlyNameTypes.Mangled;

        public string GetFriendlyName(FriendlyNameTypes type = FriendlyNameTypes.Full)
        {
            // Apply index number if NOT default method (method have no arguments)
            var index = (IncludeIndex(type) && (this.OverloadIndex >= 1))
                ? string.Format("@{0}", this.OverloadIndex)
                : string.Empty;

            var arguments = (IncludeNames(type) || IncludeTypes(type))
                ? string.Format(
                    "({0})",
                    string.Join(
                        ", ",
                        this.Parameters.Select(parameter =>
                            (IncludeNames(type) && IncludeTypes(type))
                                ? string.Format(
                                    "{0} {1}",
                                    parameter.TargetType.FriendlyName,
                                    parameter.SymbolName)
                                : IncludeTypes(type)
                                    ? parameter.TargetType.FriendlyName
                                    : parameter.SymbolName)))
                : string.Empty;

            var name = string.Format(
                "{0}{1}{2}",
                FullName(type) ? this.Member.GetFriendlyName() : this.Member.Name,
                index,
                arguments);

            return Mangled(type) ? ToMangledName(name) : name;
        }

        public VariableInformation[] GetParameters(ITypeInformation thisType)
        {
            Debug.Assert(this.Member.HasThis);

            return new[] { this.CreateThisParameterInformation(thisType) }
                .Concat(this.Member.Parameters.Select(this.ToParameterInformation))
                .ToArray();
        }

        public PInvokeInfo PInvokeInfo =>
            this.Definition.PInvokeInfo;

        public override bool IsCLanguagePublicScope =>
            this.Definition.IsPublic;
        public override bool IsCLanguageLinkageScope =>
            !this.Definition.IsPublic && !this.Definition.IsPrivate;
        public override bool IsCLanguageFileScope =>
            this.Definition.IsPrivate;

        private string GetFunctionPrototype(bool decorate)
        {
            var parametersString = string.Join(
                ", ",
                this.Parameters.Select(parameter => string.Format(
                    "{0} {1}",
                    parameter.TargetType.CLanguageTypeName,
                    parameter.SymbolName)));

            var returnTypeName =
                this.ReturnType.CLanguageTypeName;

            return string.Format(
                decorate ? "{0} __{1}__({2})" : "{0} {1}({2})",
                returnTypeName,
                this.CLanguageFunctionName,
                parametersString);
        }

        public string CLanguageFunctionName =>
            this.GetFriendlyName(FriendlyNameTypes.FullName | FriendlyNameTypes.Index | FriendlyNameTypes.Mangled);
        public string CLanguageVirtualFunctionDeclarationName =>
            this.GetFriendlyName(FriendlyNameTypes.Index | FriendlyNameTypes.Mangled);

        public string CLanguageRawFunctionPrototype =>
            this.GetFunctionPrototype(false);
        public string CLanguageFunctionPrototype =>
            this.GetFunctionPrototype(this.IsVirtual);

        public string CLanguageFunctionTypePrototype
        {
            get
            {
                var parametersString = string.Join(
                    ", ",
                    this.Parameters.Select(parameter => string.Format(
                        "{0} {1}",
                        parameter.TargetType.CLanguageTypeName,
                        parameter.SymbolName)));

                var returnTypeName =
                    this.ReturnType.CLanguageTypeName;

                return string.Format(
                    "{0} (*{1})({2})",
                    returnTypeName,
                    this.Name,
                    parametersString);
            }
        }

        protected override MethodDefinition OnResolve(MethodReference member) =>
            member.Resolve();
    }
}
