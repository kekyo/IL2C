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
using System.Threading.Tasks;

using IL2C.Internal;
using IL2C.Metadata;

namespace IL2C.Drivers
{
    public sealed class TranslationOptions
    {
        public readonly bool ReadSymbols;
        public readonly bool EnableBundler;
        public readonly TargetPlatforms TargetPlatform;
        public readonly DebugInformationOptions DebugInformationOption;

        public TranslationOptions(
            bool readSymbols,
            bool enableBundler,
            TargetPlatforms targetPlatform,
            DebugInformationOptions debugInformationOption)
        {
            this.ReadSymbols = readSymbols;
            this.EnableBundler = enableBundler;
            this.TargetPlatform = targetPlatform;
            this.DebugInformationOption = debugInformationOption;
        }
    }

    public static class SimpleTranslator
    {
        public static Task<IMethodInformation> TranslateAsync(
            ILogger logger,
            CodeTextStorage storage,
            TranslationOptions options,
            string assemblyPath)
        {
            logger.Information($"Preparing assembly: \"{Path.GetFullPath(assemblyPath)}\" ...");

            Utilities.SafeCreateDirectory(storage.BasePath, true);

            var translateContext = new TranslateContext(
                assemblyPath, options.ReadSymbols, options.TargetPlatform);
            var preparedFunctions = AssemblyPreparer.Prepare(
                translateContext);

            logger.Information($"Translating assembly: \"{Path.GetFullPath(assemblyPath)}\" ...");

            using (var _ = storage.EnterScope("include"))
            {
                AssemblyWriter.WriteHeader(
                    storage,
                    translateContext,
                    preparedFunctions);
            }

            using (var _ = storage.EnterScope("src"))
            {
                AssemblyWriter.WriteSourceCode(
                    storage,
                    translateContext,
                    preparedFunctions,
                    options.EnableBundler,
                    options.DebugInformationOption);
            }

            logger.Information($"Translated assembly: Stored into \"{Path.GetFullPath(storage.BasePath)}\"");

            // TODO: Makes asynchronously operation.
            return Task.FromResult(translateContext.MetadataContext.EntryPoint);
        }

        public static Task<IMethodInformation> TranslateAsync(
            ILogger logger,
            string outputBaseDirPath,
            bool produceCpp,
            TranslationOptions options,
            string assemblyPath)
        {
            var storage = new CodeTextStorage(
                logger,
                outputBaseDirPath,
                produceCpp,
                "    ");

            return TranslateAsync(
                logger,
                storage,
                options,
                assemblyPath);
        }
    }
}
