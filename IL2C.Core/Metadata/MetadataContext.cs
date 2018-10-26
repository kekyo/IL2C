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
            "ToString", "GetHashCode", "Finalize", "Equals", "GetType"});

        private readonly Dictionary<AssemblyDefinition, IAssemblyInformation> assemblies =
            new Dictionary<AssemblyDefinition, IAssemblyInformation>(AssemblyDefinitionComparer.Instance);
        private readonly Dictionary<ModuleReference, IModuleInformation> modules =
            new Dictionary<ModuleReference, IModuleInformation>(ModuleReferenceComparer.Instance);
        private readonly Dictionary<ModuleReference, AssemblyDefinition> assemblyByModule =
            new Dictionary<ModuleReference, AssemblyDefinition>(ModuleReferenceComparer.Instance);
        private readonly Dictionary<MemberReference, IMemberInformation> members =
            new Dictionary<MemberReference, IMemberInformation>(MemberReferenceComparer.Instance);

        private readonly Lazy<TypeInformation> voidType;
        private readonly Lazy<TypeInformation> objectType;
        private readonly Lazy<TypeInformation> valueTypeType;
        private readonly Lazy<TypeInformation> delegateType;

        private readonly Lazy<TypeInformation> byteType;
        private readonly Lazy<TypeInformation> sbyteType;
        private readonly Lazy<TypeInformation> int16Type;
        private readonly Lazy<TypeInformation> uint16Type;
        private readonly Lazy<TypeInformation> int32Type;
        private readonly Lazy<TypeInformation> uint32Type;
        private readonly Lazy<TypeInformation> int64Type;
        private readonly Lazy<TypeInformation> uint64Type;
        private readonly Lazy<TypeInformation> singleType;
        private readonly Lazy<TypeInformation> doubleType;
        private readonly Lazy<TypeInformation> intPtrType;
        private readonly Lazy<TypeInformation> uintPtrType;
        private readonly Lazy<TypeInformation> charType;
        private readonly Lazy<TypeInformation> stringType;
        private readonly Lazy<TypeInformation> booleanType;

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

            voidType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.Void,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            objectType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.Object,
                type => new TypeInformation(type, resolvedCoreModuleInformation, objectMethodValidTarget));
            valueTypeType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.GetType("System.ValueType"),
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            delegateType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.GetType("System.Delegate"),
                type => new TypeInformation(type, resolvedCoreModuleInformation));

            byteType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.Byte,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            sbyteType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.SByte,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            int16Type = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.Int16,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            uint16Type = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.UInt16,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            int32Type = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.Int32,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            uint32Type = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.UInt32,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            int64Type = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.Int64,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            uint64Type = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.UInt64,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            singleType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.Single,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            doubleType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.Double,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            intPtrType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.IntPtr,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            uintPtrType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.UIntPtr,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            charType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.Char,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            stringType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.String,
                type => new TypeInformation(type, resolvedCoreModuleInformation));
            booleanType = this.LazyGetOrAddMember(
                () => resolvedCoreModule.TypeSystem.Boolean,
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

        internal Lazy<TInformation> LazyGetOrAddAssembly<TInformation>(
            Func<AssemblyDefinition> extractor,
            Func<AssemblyDefinition, TInformation> factory)
            where TInformation : IAssemblyInformation
        {
            return Lazy.Create(() => this.GetOrAddAssembly(extractor(), factory));
        }

        internal Lazy<TInformation[]> LazyGetOrAddAssemblies<TInformation>(
            Func<IEnumerable<AssemblyDefinition>> extractor,
            Func<AssemblyDefinition, TInformation> factory)
            where TInformation : IAssemblyInformation
        {
            return Lazy.Create(() => extractor()
                .Select(type => this.GetOrAddAssembly(type, factory))
                .ToArray());
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

        internal Lazy<TInformation> LazyGetOrAddModule<TInformation>(
            AssemblyDefinition assemblyDefinition,
            Func<ModuleReference> extractor,
            Func<AssemblyDefinition, ModuleReference, TInformation> factory)
            where TInformation : IModuleInformation
        {
            return Lazy.Create(() => this.GetOrAddModule(assemblyDefinition, extractor(), factory));
        }

        internal Lazy<TInformation[]> LazyGetOrAddModules<TInformation>(
            AssemblyDefinition assemblyDefinition,
            Func<IEnumerable<ModuleReference>> extractor,
            Func<AssemblyDefinition, ModuleReference, TInformation> factory)
            where TInformation : IModuleInformation
        {
            return Lazy.Create(() => extractor()
                .Select(moduleReference => this.GetOrAddModule(assemblyDefinition, moduleReference, factory))
                .ToArray());
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

        internal Lazy<TInformation> LazyGetOrAddMember<TReference, TInformation>(
            Func<TReference> extractor,
            Func<TReference, TInformation> factory)
            where TReference : MemberReference
            where TInformation : IMemberInformation
        {
            return Lazy.Create(() => this.GetOrAddMember(extractor(), factory));
        }

        internal Lazy<TInformation[]> LazyGetOrAddMembers<TReference, TInformation>(
            Func<IEnumerable<TReference>> extractor,
            Func<TReference, TInformation> factory)
            where TReference : MemberReference
            where TInformation : IMemberInformation
        {
            return Lazy.Create(() => extractor()
                .Select(type => this.GetOrAddMember(type, factory))
                .ToArray());
        }
        #endregion

        #region CoreLibraryTypes
        public ITypeInformation VoidType => voidType.Value;
        public ITypeInformation ObjectType => objectType.Value;
        public ITypeInformation ValueTypeType => valueTypeType.Value;
        public ITypeInformation DelegateType => delegateType.Value;
        public ITypeInformation UntypedReferenceType => UntypedReferenceTypeInformation.UntypedReferenceType;

        public ITypeInformation ByteType => byteType.Value;
        public ITypeInformation SByteType => sbyteType.Value;
        public ITypeInformation Int16Type => int16Type.Value;
        public ITypeInformation UInt16Type => uint16Type.Value;
        public ITypeInformation Int32Type => int32Type.Value;
        public ITypeInformation UInt32Type => uint32Type.Value;
        public ITypeInformation Int64Type => int64Type.Value;
        public ITypeInformation UInt64Type => uint64Type.Value;
        public ITypeInformation SingleType => singleType.Value;
        public ITypeInformation DoubleType => doubleType.Value;
        public ITypeInformation IntPtrType => intPtrType.Value;
        public ITypeInformation UIntPtrType => uintPtrType.Value;
        public ITypeInformation CharType => charType.Value;
        public ITypeInformation StringType => stringType.Value;
        public ITypeInformation BooleanType => booleanType.Value;
        #endregion
    }
}
