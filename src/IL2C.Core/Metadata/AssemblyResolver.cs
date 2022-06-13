////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System.Collections.Generic;
using System.IO;

using Mono.Cecil;

namespace IL2C.Metadata
{
    // Ported from ILCompose.
    internal sealed class AssemblyResolver : DefaultAssemblyResolver
    {
        private readonly ILogger logger;
        private readonly HashSet<string> loaded = new();
        private readonly SymbolReaderProvider symbolReaderProvider;

        public AssemblyResolver(
            ILogger logger, string targetBasePath, string[] referenceBasePaths)
        {
            this.logger = logger;
            this.symbolReaderProvider = new SymbolReaderProvider(this.logger);

            void Add(string path)
            {
                var fullPath = Path.GetFullPath(path);
                base.AddSearchDirectory(fullPath);
                this.logger.Trace($"Reference base path: {fullPath}");
            }

            Add(targetBasePath);

            foreach (var referenceBasePath in referenceBasePaths)
            {
                Add(referenceBasePath);
            }
        }

        public override AssemblyDefinition Resolve(AssemblyNameReference name)
        {
            var parameters = new ReaderParameters()
            {
                ReadWrite = false,
                InMemory = true,
                AssemblyResolver = this,
                SymbolReaderProvider = this.symbolReaderProvider,
                ReadSymbols = true,
            };
            var ad = base.Resolve(name, parameters);
            if (this.loaded.Add(ad.MainModule.FileName))
            {
                this.logger.Trace($"Assembly loaded: {ad.MainModule.FileName}");
            }
            return ad;
        }

        public AssemblyDefinition ReadAssemblyFrom(string assemblyPath)
        {
            var parameters = new ReaderParameters()
            {
                ReadWrite = false,
                InMemory = true,
                AssemblyResolver = this,
                SymbolReaderProvider = this.symbolReaderProvider,
                ReadSymbols = true,
            };
            var ad = AssemblyDefinition.ReadAssembly(assemblyPath, parameters);
            if (this.loaded.Add(ad.MainModule.FileName))
            {
                this.logger.Trace($"Assembly loaded: {ad.MainModule.FileName}");
            }
            return ad;
        }

        public ModuleDefinition ReadModuleFrom(string modulePath)
        {
            var parameters = new ReaderParameters()
            {
                ReadWrite = false,
                InMemory = true,
                AssemblyResolver = this,
                SymbolReaderProvider = this.symbolReaderProvider,
                ReadSymbols = true,
            };
            var md = ModuleDefinition.ReadModule(modulePath, parameters);
            if (loaded.Add(md.FileName))
            {
                this.logger.Trace($"Module loaded: {md.FileName}");
            }
            return md;
        }
    }
}
