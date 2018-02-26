using System;

using Mono.Cecil;

namespace IL2C.Metadata
{
    public interface IAssemblyInformation : IMetadataInformation
    {
        IModuleInformation[] Modules { get; }
    }

    internal sealed class AssemblyInformation
        : MetadataInformation
        , IAssemblyInformation
    {
        private readonly AssemblyDefinition assembly;
        private readonly Lazy<ModuleInformation[]> modules;

        internal AssemblyInformation(AssemblyDefinition assembly, MetadataContext context)
            : base(context)
        {
            this.assembly = assembly;

            modules = context.LazyGetOrAddModule(
                assembly,
                () => assembly.Modules,
                (_, module) => new ModuleInformation(module, this));
        }

        public override string UniqueName => assembly.FullName;

        public IModuleInformation[] Modules => modules.Value;

        public bool Equals(IAssemblyInformation other)
        {
            return this.UniqueName.Equals(other.UniqueName);
        }

        public override bool Equals(object obj)
        {
            return this.Equals(obj as IAssemblyInformation);
        }

        public override int GetHashCode()
        {
            return this.UniqueName.GetHashCode();
        }
    }
}
