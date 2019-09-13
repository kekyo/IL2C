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
using System;

namespace IL2C.Metadata
{
    public interface IModuleInformation : IMetadataInformation
    {
        IAssemblyInformation DeclaringAssembly { get; }

        ITypeInformation[] Types { get; }
    }

    internal sealed class ModuleInformation
        : MetadataInformation<ModuleReference, ModuleDefinition>, IModuleInformation
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
            this.MetadataContext.GetOrAddTypes(this.Definition.Types);

        protected override ModuleDefinition OnResolve(ModuleReference member)
        {
            return (ModuleDefinition)member;
        }
    }
}
