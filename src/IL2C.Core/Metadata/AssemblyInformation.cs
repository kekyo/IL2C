////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using Mono.Cecil;

namespace IL2C.Metadata
{
    public interface IAssemblyInformation : IMetadataInformation
    {
        string CLanguageIncludeFileName { get; }

        IModuleInformation[] Modules { get; }
    }

    internal sealed class AssemblyInformation
        : MetadataInformation
        , IAssemblyInformation
    {
        private readonly AssemblyDefinition assembly;

        internal AssemblyInformation(AssemblyDefinition assembly, MetadataContext metadataContext)
            : base(metadataContext)
        {
            this.assembly = assembly;
        }

        public override string MetadataTypeName => "Assembly";

        public override string UniqueName => assembly.FullName;
        public override string Name => assembly.Name.Name;
        public override string FriendlyName => assembly.Name.Name;

        // TODO: mscorlib --> il2c.h?
        public string CLanguageIncludeFileName => assembly.Name.Name + ".h";

        public IModuleInformation[] Modules =>
            this.MetadataContext.GetOrAddModules(assembly.Modules);

        public bool Equals(IAssemblyInformation other) =>
            this.UniqueName.Equals(other.UniqueName);

        public override bool Equals(object obj) =>
            this.Equals(obj as IAssemblyInformation);

        public override int GetHashCode() =>
            this.UniqueName.GetHashCode();
    }
}
