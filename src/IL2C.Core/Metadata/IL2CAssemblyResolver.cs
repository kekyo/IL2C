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

namespace IL2C.Metadata
{
    internal sealed class IL2CAssemblyResolver : DefaultAssemblyResolver
    {
        private sealed class IL2CSymbolReaderProvider : ISymbolReaderProvider
        {
            // HACK: cecil will lock symbol file when uses defaulted reading method.
            //   Makes safer around entire building process.

            private static readonly PdbReaderProvider parent = new();

            public ISymbolReader? GetSymbolReader(ModuleDefinition module, string fileName)
            {
                if (module.HasDebugHeader)
                {
                    var header = module.GetDebugHeader();
                    if (header.Entries.
                        FirstOrDefault(e => e.Directory.Type == ImageDebugType.EmbeddedPortablePdb) is { } entry)
                    {
                        return new EmbeddedPortablePdbReaderProvider().
                            GetSymbolReader(module, fileName);
                    }

                    var fullPath = Path.GetFullPath(fileName);
                    var debuggingPath = Path.Combine(
                        fullPath,
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

                        return parent.GetSymbolReader(module, ms);
                    }
                }

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

        public IL2CAssemblyResolver(
            string assemblyPath, string[] referenceBasePaths, bool readSymbols)
        {
            base.AddSearchDirectory(Path.GetDirectoryName(Path.GetFullPath(assemblyPath)));

            foreach (var referenceBasePath in referenceBasePaths)
            {
                base.AddSearchDirectory(Path.GetFullPath(referenceBasePath));
            }
        }

        public override AssemblyDefinition Resolve(AssemblyNameReference name)
        {
            var parameters = new ReaderParameters()
            {
                ReadWrite = false,
                InMemory = true,
                AssemblyResolver = this,
                SymbolReaderProvider = new IL2CSymbolReaderProvider(),
                ReadSymbols = true,
            };
            return base.Resolve(name, parameters);
        }

        public AssemblyDefinition ReadFrom(string assemblyPath)
        {
            var parameters = new ReaderParameters()
            {
                ReadWrite = false,
                InMemory = true,
                AssemblyResolver = this,
                SymbolReaderProvider = new IL2CSymbolReaderProvider(),
                ReadSymbols = true,
            };
            return AssemblyDefinition.ReadAssembly(assemblyPath, parameters);
        }
    }
}
