using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

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
        ITypeInformation DelegateType { get; }
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
        private static readonly HashSet<string> objectMethodValidTarget =
            new HashSet<string>(new[] {
            ".ctor", "ReferenceEquals", "ToString", "GetHashCode", "Finalize", "Equals", "GetType"});

        private readonly Dictionary<AssemblyDefinition, IAssemblyInformation> assemblies =
            new Dictionary<AssemblyDefinition, IAssemblyInformation>(AssemblyDefinitionComparer.Instance);
        private readonly Dictionary<ModuleReference, IModuleInformation> modules =
            new Dictionary<ModuleReference, IModuleInformation>(ModuleReferenceComparer.Instance);
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

            var resolvedCoreModule = mainAssembly.MainModule.TypeSystem.Object.Resolve().Module;
            var resolvedCoreAssembly = resolvedCoreModule.Assembly;
            var resolvedCoreAssemblyInformation = new AssemblyInformation(
                resolvedCoreAssembly, this);
            var resolvedCoreModuleInformation = new ModuleInformation(
                resolvedCoreModule, resolvedCoreAssemblyInformation);

            assemblies.Add(resolvedCoreModule.Assembly, resolvedCoreAssemblyInformation);
            modules.Add(resolvedCoreModule, resolvedCoreModuleInformation);
            assemblyByModule.Add(resolvedCoreModule, resolvedCoreAssembly);

            this.VoidType = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.Void,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.ObjectType = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.Object,
                type => new TypeInformation(type, resolvedCoreModuleInformation, objectMethodValidTarget));
            this.ValueTypeType = this.GetOrAddMember(
                resolvedCoreModule.GetType("System.ValueType"),
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.DelegateType = this.GetOrAddMember(
                resolvedCoreModule.GetType("System.Delegate"),
                type => new TypeInformation(type, resolvedCoreModuleInformation));

            this.ByteType = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.Byte,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.SByteType = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.SByte,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.Int16Type = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.Int16,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.UInt16Type = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.UInt16,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.Int32Type = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.Int32,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.UInt32Type = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.UInt32,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.Int64Type = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.Int64,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.UInt64Type = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.UInt64,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.SingleType = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.Single,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.DoubleType = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.Double,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.IntPtrType = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.IntPtr,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.UIntPtrType = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.UIntPtr,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.CharType = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.Char,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.StringType = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.String,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            this.BooleanType = this.GetOrAddMember(
                resolvedCoreModule.TypeSystem.Boolean,
                type => new TypeInformation(type, resolvedCoreModuleInformation));

            this.MainAssembly = new AssemblyInformation(mainAssembly, this);
            assemblies.Add(mainAssembly, this.MainAssembly);
        }

        public IAssemblyInformation MainAssembly { get; }
        public IEnumerable<IAssemblyInformation> Assemblies => assemblies.Values;

        #region IAssemblyInformation
        internal TInformation GetOrAddAssembly<TInformation>(
            AssemblyDefinition assemblyDefinition,
            Func<AssemblyDefinition, TInformation> factory)
            where TInformation : IAssemblyInformation
        {
            if (assemblyDefinition == null)
            {
                return default(TInformation);
            }

            lock (assemblies)
            {
                if (!assemblies.TryGetValue(assemblyDefinition, out var assembly))
                {
                    assembly = factory(assemblyDefinition);
                    assemblies.Add(assemblyDefinition, assembly);
                }
                return (TInformation)assembly;
            }
        }

        internal TInformation[] GetOrAddAssemblies<TInformation>(
            IEnumerable<AssemblyDefinition> assemblyDefinitions,
            Func<AssemblyDefinition, TInformation> factory)
            where TInformation : IAssemblyInformation
        {
            return assemblyDefinitions
                .Select(type => this.GetOrAddAssembly(type, factory))
                .ToArray();
        }
        #endregion

        #region IModuleInformation
        internal TInformation GetOrAddModule<TInformation>(
            AssemblyDefinition assemblyDefinition,
            ModuleReference moduleReference,
            Func<AssemblyDefinition, ModuleReference, TInformation> factory)
            where TInformation : IModuleInformation
        {
            if (moduleReference == null)
            {
                return default(TInformation);
            }

            lock (modules)
            {
                IModuleInformation module;
                if (assemblyDefinition == null)
                {
                    if (!assemblyByModule.TryGetValue(moduleReference, out assemblyDefinition))
                    {
                        module = factory(assemblyDefinition, moduleReference);

                        modules.Add(moduleReference, module);
                        assemblyByModule.Add(moduleReference, assemblyDefinition);

                        return (TInformation)module;
                    }
                }

                if (!modules.TryGetValue(moduleReference, out module))
                {
                    module = factory(assemblyDefinition, moduleReference);

                    modules.Add(moduleReference, module);
                    assemblyByModule.Add(moduleReference, assemblyDefinition);
                }

                return (TInformation)module;
            }
        }

        internal TInformation[] GetOrAddModules<TInformation>(
            AssemblyDefinition assemblyDefinition,
            IEnumerable<ModuleReference> moduleReferences,
            Func<AssemblyDefinition, ModuleReference, TInformation> factory)
            where TInformation : IModuleInformation
        {
            return moduleReferences
                .Select(moduleReference => this.GetOrAddModule(assemblyDefinition, moduleReference, factory))
                .ToArray();
        }
        #endregion

        #region IMemberInformation
        internal TInformation GetOrAddMember<TReference, TInformation>(
            TReference memberReference,
            Func<TReference, TInformation> factory)
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
                    member = factory(memberReference);
                    members.Add(memberReference, member);
                }
                return (TInformation)member;
            }
        }

        internal TInformation[] GetOrAddMembers<TReference, TInformation>(
            IEnumerable<TReference> memberReferences,
            Func<TReference, TInformation> factory)
            where TReference : MemberReference
            where TInformation : IMemberInformation
        {
            return memberReferences
                .Select(member => this.GetOrAddMember(member, factory))
                .ToArray();
        }
        #endregion

        #region CoreLibraryTypes
        public ITypeInformation VoidType { get; }
        public ITypeInformation ObjectType { get; }
        public ITypeInformation ValueTypeType { get; }
        public ITypeInformation DelegateType { get; }
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
