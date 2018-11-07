using System.IO;

namespace IL2C
{
    public static class SimpleDriver
    {
        public static void Translate(
            TextWriter tw,
            string assemblyPath,
            string outputPath,
            bool readSymbols,
            bool enableCpp,
            DebugInformationOptions debugInformationOptions)
        {
            tw.Write("IL2C: Preparing assembly: \"{0}\" ...", Path.GetFullPath(assemblyPath));

            if (Directory.Exists(outputPath) == false)
            {
                try
                {
                    Directory.CreateDirectory(outputPath);
                }
                catch
                {
                }
            }

            var translateContext = new TranslateContext(assemblyPath, readSymbols);
            var preparedFunctions = AssemblyPreparer.Prepare(translateContext);

            tw.WriteLine(" done.");

            var assemblyName = Path.GetFileNameWithoutExtension(assemblyPath);
            var filePath = Path.Combine(outputPath, assemblyName);
            var sourceFilePath = filePath + (enableCpp ? ".cpp" : ".c");

            tw.Write("IL2C: Writing source code: \"{0}\" ...", Path.GetFullPath(sourceFilePath));

            using (var fsSource = new FileStream(
                sourceFilePath,
                FileMode.Create,
                FileAccess.ReadWrite,
                FileShare.None))
            {
                var twSource = CodeTextWriter.Create(fsSource, "    ");
                AssemblyWriter.WriteSourceCode(
                    twSource, translateContext, preparedFunctions, debugInformationOptions);
                twSource.Flush();
            }

            tw.WriteLine(" done.");

            var headerFilePath = filePath + ".h";

            tw.Write("IL2C: Writing header: \"{0}\" ...", Path.GetFullPath(headerFilePath));

            using (var fsHeader = new FileStream(
                headerFilePath,
                FileMode.Create,
                FileAccess.ReadWrite,
                FileShare.None))
            {
                var twHeader = CodeTextWriter.Create(fsHeader, "    ");
                AssemblyWriter.WriteHeader(twHeader, translateContext, preparedFunctions);
                twHeader.Flush();
            }

            tw.WriteLine(" done.");
        }
    }
}
