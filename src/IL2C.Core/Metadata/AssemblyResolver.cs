////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System.IO;
using System.Linq;

using Mono.Cecil;
using Mono.Cecil.Cil;
using Mono.Cecil.Pdb;

using IL2C.Internal;

namespace IL2C.Metadata
{
    internal sealed class AssemblyResolver : DefaultAssemblyResolver
    {
        private sealed class SymbolReaderProvider : ISymbolReaderProvider
        {
            // HACK: cecil will lock symbol file when uses defaulted reading method.
            //   Makes safer around entire building process.

            private static readonly PdbReaderProvider parent = new();

            private readonly ILogger logger;

            public SymbolReaderProvider(ILogger logger) =>
                this.logger = logger;

            public ISymbolReader? GetSymbolReader(ModuleDefinition module, string fileName)
            {
                if (module.HasDebugHeader)
                {
                    var fullPath = Path.GetFullPath(fileName);

                    var header = module.GetDebugHeader();
                    if (header.Entries.
                        FirstOrDefault(e => e.Directory.Type == ImageDebugType.EmbeddedPortablePdb) is { } entry)
                    {
                        var sr = new EmbeddedPortablePdbReaderProvider().
                            GetSymbolReader(module, fileName);
                        this.logger.Trace($"Symbol loaded from: {fullPath}");
                        return sr;
                    }

                    var debuggingPath = Path.Combine(
                        IOAccessor.GetDirectoryPath(fullPath),
                        Path.GetFileNameWithoutExtension(fullPath) + ".pdb");

                    if (File.Exists(debuggingPath))
                    {
                        var ms = new MemoryStream();
                        using (var pdbStream = new FileStream(
                            debuggingPath, FileMode.Open, FileAccess.Read, FileShare.Read))
                        {
                            pdbStream.CopyTo(ms);
                        }
                        ms.Position = 0;

                        var sr = parent.GetSymbolReader(module, ms);
                        this.logger.Trace($"Symbol loaded from: {debuggingPath}");
                        return sr;
                    }
                }

                this.logger.Trace($"Symbol not found: {fileName}");
                return null;
            }

            public ISymbolReader? GetSymbolReader(ModuleDefinition module, Stream symbolStream)
            {
                var ms = new MemoryStream();
                symbolStream.CopyTo(ms);
                ms.Position = 0;

                symbolStream.Dispose();

                return parent.GetSymbolReader(module, ms);
            }
        }

        private readonly ILogger logger;

        public AssemblyResolver(
            ILogger logger, string targetBasePath, string[] referenceBasePaths)
        {
            this.logger = logger;

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
                SymbolReaderProvider = new SymbolReaderProvider(this.logger),
                ReadSymbols = true,
            };
            var ad = base.Resolve(name, parameters);
            this.logger.Trace($"Assembly loaded: {ad.MainModule.FileName}");
            return ad;
        }

        public AssemblyDefinition ReadAssemblyFrom(string assemblyPath)
        {
            var parameters = new ReaderParameters()
            {
                ReadWrite = false,
                InMemory = true,
                AssemblyResolver = this,
                SymbolReaderProvider = new SymbolReaderProvider(this.logger),
                ReadSymbols = true,
            };
            var ad = AssemblyDefinition.ReadAssembly(assemblyPath, parameters);
            this.logger.Trace($"Assembly loaded: {ad.MainModule.FileName}");
            return ad;
        }

        public ModuleDefinition ReadModuleFrom(string modulePath)
        {
            var parameters = new ReaderParameters()
            {
                ReadWrite = false,
                InMemory = true,
                AssemblyResolver = this,
                SymbolReaderProvider = new SymbolReaderProvider(this.logger),
                ReadSymbols = true,
            };
            var md = ModuleDefinition.ReadModule(modulePath, parameters);
            this.logger.Trace($"Module loaded: {md.FileName}");
            return md;
        }
    }
}
