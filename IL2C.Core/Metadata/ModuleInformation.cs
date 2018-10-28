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
        public ModuleInformation(ModuleReference module, AssemblyInformation assembly)
            : base(module, assembly.MetadataContext)
        {
            this.DeclaringAssembly = assembly;
        }

        public override string MetadataTypeName => "Module";

        public override string UniqueName => this.Member.Name;
        public override string Name => this.Member.Name;
        public override string FriendlyName => this.Member.Name;

        public IAssemblyInformation DeclaringAssembly { get; }

        public ITypeInformation[] Types =>
            this.MetadataContext.GetOrAddMembers(
                this.Definition.Types,
                type => new TypeInformation(type, this));

        protected override ModuleDefinition OnResolve(ModuleReference member)
        {
            return (ModuleDefinition)member;
        }
    }
}
