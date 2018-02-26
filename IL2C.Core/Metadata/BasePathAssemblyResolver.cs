using Mono.Cecil;

namespace IL2C.Metadata
{
    internal sealed class BasePathAssemblyResolver : IAssemblyResolver
    {
        private readonly DefaultAssemblyResolver resolver = new DefaultAssemblyResolver();

        public BasePathAssemblyResolver(string basePath)
        {
            resolver.AddSearchDirectory(basePath);
        }

        public void Dispose()
        {
            resolver.Dispose();
        }

        public AssemblyDefinition Resolve(AssemblyNameReference name)
        {
            return resolver.Resolve(name);
        }

        public AssemblyDefinition Resolve(AssemblyNameReference name, ReaderParameters parameters)
        {
            return resolver.Resolve(name, parameters);
        }
    }
}
