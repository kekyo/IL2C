using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using IL2C.Metadata.Specialized;
using Mono.Cecil;

namespace IL2C.Metadata
{
    public interface IMetadataContext
    {
        IAssemblyInformation MainAssembly { get; }
        IEnumerable<IAssemblyInformation> Assemblies { get; }

        ITypeInformation VoidType { get; }
        ITypeInformation ObjectType { get; }
        ITypeInformation ValueTypeType { get; }
        ITypeInformation EnumType { get; }
        ITypeInformation DelegateType { get; }
        ITypeInformation MulticastDelegateType { get; }
        ITypeInformation UntypedReferenceType { get; }

        ITypeInformation ByteType { get; }
        ITypeInformation SByteType { get; }
        ITypeInformation Int16Type { get; }
        ITypeInformation UInt16Type { get; }
        ITypeInformation Int32Type { get; }
        ITypeInformation UInt32Type { get; }
        ITypeInformation Int64Type { get; }
        ITypeInformation UInt64Type { get; }
        ITypeInformation SingleType { get; }
        ITypeInformation DoubleType { get; }
        ITypeInformation IntPtrType { get; }
        ITypeInformation UIntPtrType { get; }
        ITypeInformation CharType { get; }
        ITypeInformation StringType { get; }
        ITypeInformation BooleanType { get; }
    }

    internal sealed class MetadataContext
        : IMetadataContext
    {
        // These tables are the member filter entries for mscorlib 4.0 library.
        // Reconstruct if we're ganna change to netstandard.
        private static readonly Dictionary<string, HashSet<string>> validTargetMembers =
            new Dictionary<string, HashSet<string>>
            {
                { "System.Object", new HashSet<string> { ".ctor", "ReferenceEquals", "ToString", "GetHashCode", "Finalize", "Equals", "GetType" } },
                { "System.ValueType", new HashSet<string> { "ToString", "GetHashCode", "Equals" } },
                { "System.Enum", new HashSet<string> { "ToString", "GetHashCode", "Equals" } },
                { "System.Delegate", new HashSet<string> { "GetHashCode", "Equals", "_target", "_methodPtr" } },
                { "System.MulticastDelegate", new HashSet<string> { "GetHashCode", "Equals", "_target", "_methodPtr" } },
            };
        private static readonly HashSet<string> derivedFromMulticastDelegateValidTargetMethods =
            new HashSet<string> { ".ctor", "Invoke" };

        private readonly AssemblyDefinition resolvedCoreAssembly;
        private readonly ModuleDefinition resolvedCoreModule;

        private readonly Dictionary<AssemblyDefinition, AssemblyInformation> assemblies =
            new Dictionary<AssemblyDefinition, AssemblyInformation>(AssemblyDefinitionComparer.Instance);
        private readonly Dictionary<ModuleReference, ModuleInformation> modules =
            new Dictionary<ModuleReference, ModuleInformation>(ModuleReferenceComparer.Instance);
        private readonly Dictionary<ModuleReference, AssemblyDefinition> assemblyByModule =
            new Dictionary<ModuleReference, AssemblyDefinition>(ModuleReferenceComparer.Instance);
        private readonly Dictionary<MemberReference, IMemberInformation> members =
            new Dictionary<MemberReference, IMemberInformation>(MemberReferenceComparer.Instance);

        internal MetadataContext(string assemblyPath, bool readSymbols)
        {
            var resolver = new BasePathAssemblyResolver(Path.GetDirectoryName(assemblyPath));
            var parameter = new ReaderParameters
            {
                AssemblyResolver = resolver,
                ReadSymbols = readSymbols
            };

            var mainAssembly = AssemblyDefinition.ReadAssembly(assemblyPath, parameter);
            var mainAssemblyInformation = new AssemblyInformation(mainAssembly, this);

            resolvedCoreModule = mainAssembly.MainModule.TypeSystem.Object.Resolve().Module;
            resolvedCoreAssembly = resolvedCoreModule.Assembly;
            var resolvedCoreAssemblyInformation = new AssemblyInformation(
                resolvedCoreAssembly, this);
            var resolvedCoreModuleInformation = new ModuleInformation(
                resolvedCoreModule, resolvedCoreAssemblyInformation);

            this.MainAssembly = mainAssemblyInformation;
            assemblies.Add(mainAssembly, mainAssemblyInformation);
            assemblies.Add(resolvedCoreAssembly, resolvedCoreAssemblyInformation);
            modules.Add(resolvedCoreModule, resolvedCoreModuleInformation);
            assemblyByModule.Add(resolvedCoreModule, resolvedCoreAssembly);

            this.VoidType = this.GetOrAddType(resolvedCoreModule.TypeSystem.Void);
            this.ObjectType = this.GetOrAddType(resolvedCoreModule.TypeSystem.Object);
            this.ValueTypeType = this.GetOrAddType(resolvedCoreModule.GetType("System.ValueType"));
            this.EnumType = this.GetOrAddType(resolvedCoreModule.GetType("System.Enum"));
            this.DelegateType = this.GetOrAddType(resolvedCoreModule.GetType("System.Delegate"));
            this.MulticastDelegateType = this.GetOrAddType(resolvedCoreModule.GetType("System.MulticastDelegate"));

            this.ByteType = this.GetOrAddType(resolvedCoreModule.TypeSystem.Byte);
            this.SByteType = this.GetOrAddType(resolvedCoreModule.TypeSystem.SByte);
            this.Int16Type = this.GetOrAddType(resolvedCoreModule.TypeSystem.Int16);
            this.UInt16Type = this.GetOrAddType(resolvedCoreModule.TypeSystem.UInt16);
            this.Int32Type = this.GetOrAddType(resolvedCoreModule.TypeSystem.Int32);
            this.UInt32Type = this.GetOrAddType(resolvedCoreModule.TypeSystem.UInt32);
            this.Int64Type = this.GetOrAddType(resolvedCoreModule.TypeSystem.Int64);
            this.UInt64Type = this.GetOrAddType(resolvedCoreModule.TypeSystem.UInt64);
            this.SingleType = this.GetOrAddType(resolvedCoreModule.TypeSystem.Single);
            this.DoubleType = this.GetOrAddType(resolvedCoreModule.TypeSystem.Double);
            this.IntPtrType = this.GetOrAddType(resolvedCoreModule.TypeSystem.IntPtr);
            this.UIntPtrType = this.GetOrAddType(resolvedCoreModule.TypeSystem.UIntPtr);
            this.CharType = this.GetOrAddType(resolvedCoreModule.TypeSystem.Char);
            this.StringType = this.GetOrAddType(resolvedCoreModule.TypeSystem.String);
            this.BooleanType = this.GetOrAddType(resolvedCoreModule.TypeSystem.Boolean);
        }

        public IAssemblyInformation MainAssembly { get; }
        public IEnumerable<IAssemblyInformation> Assemblies => assemblies.Values;

        #region IAssemblyInformation
        internal AssemblyInformation GetOrAddAssembly(
            AssemblyDefinition assemblyDefinition)
        {
            if (assemblyDefinition == null)
            {
                return default(AssemblyInformation);
            }

            lock (assemblies)
            {
                if (!assemblies.TryGetValue(assemblyDefinition, out var assembly))
                {
                    assembly = new AssemblyInformation(assemblyDefinition, this);
                    assemblies.Add(assemblyDefinition, assembly);
                }
                return assembly;
            }
        }

        internal AssemblyInformation GetOrAddAssembly(
            ModuleReference moduleReference)
        {
            if (moduleReference == null)
            {
                return default(AssemblyInformation);
            }

            lock (assemblyByModule)
            {
                if (!assemblyByModule.TryGetValue(moduleReference, out var assemblyDefinition))
                {
                    assemblyDefinition = ((ModuleDefinition)moduleReference).Assembly;
                    assemblyByModule.Add(moduleReference, assemblyDefinition);
                }
                return this.GetOrAddAssembly(assemblyDefinition);
            }
        }
        #endregion

        #region IModuleInformation
        internal ModuleInformation GetOrAddModule(
            ModuleReference moduleReference)
        {
            if (moduleReference == null)
            {
                return default(ModuleInformation);
            }

            lock (modules)
            {
                if (!modules.TryGetValue(moduleReference, out var module))
                {
                    var assembly = this.GetOrAddAssembly(moduleReference);
                    module = new ModuleInformation(moduleReference, assembly);
                    modules.Add(moduleReference, module);
                }
                return module;
            }
        }

        internal ModuleInformation[] GetOrAddModules(
            IEnumerable<ModuleReference> moduleReferences)
        {
            return moduleReferences.
                Select(moduleReference => this.GetOrAddModule(moduleReference)).
                Where(module => module != null).
                ToArray();
        }
        #endregion

        #region GetOrAddMember
        private TInformation GetOrAddMember<TInformation, TReference>(
            TReference memberReference,
            Func<TInformation> generator)
            where TReference : MemberReference
            where TInformation : IMemberInformation
        {
            if (memberReference == null)
            {
                return default(TInformation);
            }

            lock (members)
            {
                if (!members.TryGetValue(memberReference, out var member))
                {
                    member = generator();
                    members.Add(memberReference, member);
                }
                return (TInformation)member;
            }
        }
        #endregion

        #region ITypeInformation
        internal TypeInformation GetOrAddType(
            TypeReference typeReference)
        {
            return this.GetOrAddMember(
                typeReference,
                () =>
                {
                    if (typeReference.FullName == "<Module>")
                    {
                        return default(TypeInformation);
                    }

                    var module = this.GetOrAddModule(typeReference.Module);
                    if (typeReference.Module.Equals(resolvedCoreModule) &&
                        validTargetMembers.TryGetValue(typeReference.FullName, out var filterList))
                    {
                        return new TypeInformation(typeReference, module, filterList);
                    }

                    // Special filter for the delegate type.
                    if (!typeReference.IsValueType && !typeReference.IsArray &&
                        !typeReference.IsByReference && !typeReference.IsPointer)
                    {
                        var typeDefinition = typeReference.Resolve();
                        if (typeDefinition.IsClass && !typeDefinition.IsAbstract &&
                            MemberReferenceComparer.Instance.Equals(
                                typeDefinition.BaseType, ((TypeInformation)MulticastDelegateType).Member))
                        {
                            return new TypeInformation(typeReference, module, derivedFromMulticastDelegateValidTargetMethods);
                        }
                    }

                    return new TypeInformation(typeReference, module);
                });
        }

        internal TypeInformation[] GetOrAddTypes(
            IEnumerable<TypeReference> typeReferences)
        {
            return typeReferences.
                Select(typeReference => this.GetOrAddType(typeReference)).
                Where(type => type != null).
                ToArray();
        }
        #endregion

        #region IFieldInformation
        internal FieldInformation GetOrAddField(
            FieldReference fieldReference)
        {
            return this.GetOrAddMember(
                fieldReference,
                () => new FieldInformation(fieldReference, this.GetOrAddModule(fieldReference.Module)));
        }

        internal FieldInformation[] GetOrAddFields(
            IEnumerable<FieldReference> fieldReferences)
        {
            return fieldReferences.
                Select(fieldReference => this.GetOrAddField(fieldReference)).
                Where(field => field != null).
                ToArray();
        }
        #endregion

        #region IMethodInformation
        internal MethodInformation GetOrAddMethod(
            MethodReference methodReference)
        {
            return this.GetOrAddMember(
                methodReference,
                () => new MethodInformation(methodReference, this.GetOrAddModule(methodReference.Module)));
        }

        internal MethodInformation[] GetOrAddMethods(
            IEnumerable<MethodReference> methodReferences)
        {
            return methodReferences.
                Select(methodReference => this.GetOrAddMethod(methodReference)).
                Where(method => method != null).
                ToArray();
        }
        #endregion

        #region CoreLibraryTypes
        public ITypeInformation VoidType { get; }
        public ITypeInformation ObjectType { get; }
        public ITypeInformation ValueTypeType { get; }
        public ITypeInformation EnumType { get; }
        public ITypeInformation DelegateType { get; }
        public ITypeInformation MulticastDelegateType { get; }
        public ITypeInformation UntypedReferenceType =>
            UntypedReferenceTypeInformation.UntypedReferenceType;

        public ITypeInformation ByteType { get; }
        public ITypeInformation SByteType { get; }
        public ITypeInformation Int16Type { get; }
        public ITypeInformation UInt16Type { get; }
        public ITypeInformation Int32Type { get; }
        public ITypeInformation UInt32Type { get; }
        public ITypeInformation Int64Type { get; }
        public ITypeInformation UInt64Type { get; }
        public ITypeInformation SingleType { get; }
        public ITypeInformation DoubleType { get; }
        public ITypeInformation IntPtrType { get; }
        public ITypeInformation UIntPtrType { get; }
        public ITypeInformation CharType { get; }
        public ITypeInformation StringType { get; }
        public ITypeInformation BooleanType { get; }
        #endregion
    }
}
