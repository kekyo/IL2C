using System;

using Mono.Cecil;

namespace IL2C.Metadata
{
    public interface IModuleInformation : IMetadataInformation
    {
        IAssemblyInformation DeclaringAssembly { get; }

        ITypeInformation[] Types { get; }
    }

    internal sealed class ModuleInformation
        : MetadataInformation<ModuleReference, ModuleDefinition>
        , IModuleInformation
    {
        private readonly Lazy<TypeInformation[]> types;

        public ModuleInformation(ModuleReference module, AssemblyInformation assembly)
            : base(module, assembly.MetadataContext)
        {
            this.DeclaringAssembly = assembly;

            types = this.MetadataContext.LazyGetOrAddMembers(
                () => this.Definition.Types,
                type => new TypeInformation(type, this));
        }

        public override string MetadataTypeName => "Module";

        public override string UniqueName => this.Member.Name;
        public override string Name => this.Member.Name;
        public override string FriendlyName => this.Member.Name;

        public IAssemblyInformation DeclaringAssembly { get; }

        public ITypeInformation[] Types => types.Value;

        protected override ModuleDefinition OnResolve(ModuleReference member)
        {
            return (ModuleDefinition)member;
        }
    }
}
