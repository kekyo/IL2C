/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

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
