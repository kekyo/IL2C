using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

using Mono.Cecil;

namespace IL2C
{
#if true
    internal sealed class BasePathAssemblyResolver : DefaultAssemblyResolver
    {
        public BasePathAssemblyResolver(string basePath)
        {
            base.AddSearchDirectory(basePath);
        }
    }
#else
    internal sealed class BasePathAssemblyResolver : IAssemblyResolver
    {
        private static readonly string[] relatives = { ".", "bin" };
        private static readonly string[] extensions = { ".exe", ".dll" };

        private readonly Dictionary<string, AssemblyDefinition> cache =
            new Dictionary<string, AssemblyDefinition>();

        public BasePathAssemblyResolver(string basePath)
        {
            this.BasePath = basePath;
        }

        public string BasePath { get; }

        public void Dispose()
        {
            cache.Clear();
        }

        public AssemblyDefinition Resolve(AssemblyNameReference name)
        {
            return this.Resolve(name, null);
        }

        public AssemblyDefinition Resolve(AssemblyNameReference name, ReaderParameters parameters)
        {
            AssemblyDefinition assemblyDefinition = null;
            lock (cache)
            {
                this.cache.TryGetValue(name.FullName, out assemblyDefinition);
            }

            if (assemblyDefinition == null)
            {
                var results =
                    from r in relatives
                    from e in extensions
                    let p = Path.Combine(this.BasePath, r, name.Name + e)
                    where File.Exists(p)
                    select p;
                var path = results.FirstOrDefault();
                if (path != null)
                {
                    lock (cache)
                    {
                        assemblyDefinition = AssemblyDefinition.ReadAssembly(path, parameters);
                        if (assemblyDefinition != null)
                        {
                            cache.Add(name.FullName, assemblyDefinition);
                        }
                    }
                }
            }

            return assemblyDefinition;
        }
    }
#endif
}
