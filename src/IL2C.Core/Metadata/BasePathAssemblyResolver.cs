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
    internal sealed class BasePathAssemblyResolver : DefaultAssemblyResolver
    {
        public BasePathAssemblyResolver(string basePath)
        {
            this.AddSearchDirectory(basePath);
        }

        public override AssemblyDefinition Resolve(AssemblyNameReference name)
        {
            var definition = base.Resolve(name);
            this.RegisterAssembly(definition);
            return definition;
        }
    }
}
