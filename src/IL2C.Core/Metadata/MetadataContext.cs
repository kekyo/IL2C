////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

using Mono.Cecil;
using Mono.Cecil.Pdb;

using IL2C.Metadata.Specialized;
using System.Diagnostics;

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

        ITypeInformation RuntimeFieldHandle { get; }

        IMethodInformation EntryPoint { get; }
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
                { "System.Delegate", new HashSet<string> { "GetHashCode", "Equals", "Combine", "Remove", "_target", "_methodPtr" } },
                { "System.MulticastDelegate", new HashSet<string> { "GetHashCode", "Equals", "_target", "_methodPtr" } },
                { "System.RuntimeFieldHandle", new HashSet<string> { "GetHashCode", "Equals" } },
            };
        private static readonly HashSet<string> derivedFromMulticastDelegateValidTargetMethods =
            new HashSet<string> { ".ctor", "Invoke" };

        private readonly ILogger logger;

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
        private readonly AssemblyResolver resolver;

        internal MetadataContext(
            ILogger logger, string assemblyPath, string[] referenceBasePaths)
        {
            this.logger = logger;

            this.resolver = new AssemblyResolver(
                this.logger, assemblyPath, referenceBasePaths);

            var mainAssembly = this.resolver.ReadAssemblyFrom(assemblyPath);
            var mainAssemblyInformation = new AssemblyInformation(mainAssembly, this);

            this.resolvedCoreModule = mainAssembly.MainModule.TypeSystem.Object.Resolve().Module;
            this.resolvedCoreAssembly = this.resolvedCoreModule.Assembly;
            var resolvedCoreAssemblyInformation = new AssemblyInformation(
                this.resolvedCoreAssembly, this);
            var resolvedCoreModuleInformation = new ModuleInformation(
                this.resolvedCoreModule, resolvedCoreAssemblyInformation);

            this.MainAssembly = mainAssemblyInformation;
            this.assemblies.Add(mainAssembly, mainAssemblyInformation);
            this.assemblies.Add(this.resolvedCoreAssembly, resolvedCoreAssemblyInformation);
            this.modules.Add(this.resolvedCoreModule, resolvedCoreModuleInformation);
            this.assemblyByModule.Add(this.resolvedCoreModule, resolvedCoreAssembly);

            this.VoidType = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.Void);
            this.ObjectType = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.Object);
            this.ValueTypeType = this.GetOrAddType(this.resolvedCoreModule.GetType("System.ValueType"));
            this.EnumType = this.GetOrAddType(this.resolvedCoreModule.GetType("System.Enum"));
            this.DelegateType = this.GetOrAddType(this.resolvedCoreModule.GetType("System.Delegate"));
            this.MulticastDelegateType = this.GetOrAddType(this.resolvedCoreModule.GetType("System.MulticastDelegate"));
            this.ArrayType = this.GetOrAddType(this.resolvedCoreModule.GetType("System.Array"));
            this.ExceptionType = this.GetOrAddType(this.resolvedCoreModule.GetType("System.Exception"));

            this.ByteType = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.Byte);
            this.SByteType = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.SByte);
            this.Int16Type = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.Int16);
            this.UInt16Type = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.UInt16);
            this.Int32Type = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.Int32);
            this.UInt32Type = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.UInt32);
            this.Int64Type = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.Int64);
            this.UInt64Type = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.UInt64);
            this.SingleType = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.Single);
            this.DoubleType = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.Double);
            this.IntPtrType = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.IntPtr);
            this.UIntPtrType = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.UIntPtr);
            this.CharType = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.Char);
            this.StringType = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.String);
            this.BooleanType = this.GetOrAddType(this.resolvedCoreModule.TypeSystem.Boolean);

            this.RuntimeFieldHandle = this.GetOrAddType(this.resolvedCoreModule.GetType("System.RuntimeFieldHandle"));

            this.EntryPoint = mainAssembly.EntryPoint is { } entryPoint ?
                this.GetOrAddMethod(entryPoint) : null;
        }

        public IAssemblyInformation MainAssembly { get; }
        public IEnumerable<IAssemblyInformation> Assemblies => this.assemblies.Values;

        public IMethodInformation EntryPoint { get; }

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
            TypeReference typeReference)
        {
            if (typeReference == null)
            {
                return default(ModuleInformation);
            }
            var moduleReference = typeReference.Module;
            
            if (typeReference.Scope.MetadataScopeType == MetadataScopeType.AssemblyNameReference)
            {
                var assembly = resolver.Resolve(typeReference.Scope as AssemblyNameReference);
                var typeDeclaration = assembly.MainModule.Types.Where(e => e.FullName == typeReference.FullName).FirstOrDefault();
                if (typeDeclaration != null) moduleReference = assembly.MainModule;
            }
            return GetOrAddModule(moduleReference);
        }

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
                    // Ignore global namespace
                    if (typeReference.FullName.Split('.').Length == 1)
                    {
                        return default(TypeInformation);
                    }

                    var module = this.GetOrAddModule(typeReference);
                    if (typeReference.Module.Assembly.FullName.Equals(resolvedCoreModule.Assembly.FullName))
                    {
                        if (validTargetMembers.TryGetValue(typeReference.FullName, out var filterList))
                        {
                            return new TypeInformation(typeReference, module, filterList);
                        }
                    }

                    // Excepts Corlib's COM interface (Such as _AppDomain, _Assembly, _Attribute ...)
                    var typeDefinition = typeReference.Resolve();
                    if (typeDefinition.Interfaces.
                        Where(ii =>
                            ii.InterfaceType.Module.Assembly.FullName.Equals(resolvedCoreModule.Assembly.FullName) &&
                            ii.InterfaceType.Name.StartsWith("_") &&
                            ii.InterfaceType.Resolve() is { } itd &&
                            itd.CustomAttributes.Any(ca =>
                                ca.AttributeType.FullName == "System.Runtime.InteropServices.ComVisibleAttribute" &&
                                ca.ConstructorArguments.Count == 1 &&
                                ca.ConstructorArguments[0].Value.Equals(true))).
                        Select(it => it.InterfaceType).
                        ToArray() is { } itfts &&
                        itfts.Length >= 1)
                    {
                        return new TypeInformation(typeReference, module, m =>
                        {
                            if (m is TypeReference tr &&
                                itfts.Any(itft => itft.FullName == tr.FullName))
                            {
                                return false;
                            }
                            else
                            {
                                return true;
                            }
                        });
                    }

                    // Special filter for the enum type.
                    if (typeReference.IsValueType && !typeReference.IsPrimitive && !typeReference.IsPointer)
                    {
                        if (typeDefinition.IsEnum)
                        {
                            return new TypeInformation(typeReference, module, m =>
                            {
                                var f = m as FieldReference;
                                if (f != null)
                                {
                                    var fr = f.Resolve();
                                    return fr.IsPublic && fr.IsStatic && fr.IsLiteral;
                                }
                                else
                                {
                                    return false;
                                }
                            });
                        }
                    }

                    // Special filter for the delegate type.
                    if (!typeReference.IsValueType && !typeReference.IsArray &&
                        !typeReference.IsByReference && !typeReference.IsPointer)
                    {
                        if (typeDefinition.IsClass && !typeDefinition.IsAbstract &&
                            MemberReferenceComparer.Instance.Equals(
                                typeDefinition.BaseType, ((TypeInformation)MulticastDelegateType).Member))
                        {
                            return new TypeInformation(
                                typeReference, module, derivedFromMulticastDelegateValidTargetMethods);
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
                () => new FieldInformation(fieldReference, this.GetOrAddModule(fieldReference.DeclaringType)));
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
                () => new MethodInformation(methodReference, this.GetOrAddModule(methodReference.DeclaringType)));
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
        public ITypeInformation ArrayType { get; }
        public ITypeInformation ExceptionType { get; }
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

        public ITypeInformation RuntimeFieldHandle { get; }
        #endregion
    }
}
