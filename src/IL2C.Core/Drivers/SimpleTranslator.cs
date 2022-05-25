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
        public readonly string[] ReferenceBasePaths;
        public readonly bool EnableBundler;
        public readonly TargetPlatforms TargetPlatform;
        public readonly DebugInformationOptions DebugInformationOption;

        public TranslationOptions(
            string[] referenceBasePaths,
            bool enableBundler,
            TargetPlatforms targetPlatform,
            DebugInformationOptions debugInformationOption)
        {
            this.ReferenceBasePaths = referenceBasePaths;
            this.EnableBundler = enableBundler;
            this.TargetPlatform = targetPlatform;
            this.DebugInformationOption = debugInformationOption;
        }
    }

    public static class SimpleTranslator
    {
        public static async ValueTask<IMethodInformation> TranslateAsync(
            ILogger logger,
            CodeTextStorage storage,
            TranslationOptions options,
            string assemblyPath)
        {
            logger.Information($"Preparing assembly: {Path.GetFullPath(assemblyPath)}");

            await IOAccessor.SafeCreateDirectoryAsync(
                storage.BasePath, true).
                ConfigureAwait(false);

            var translateContext = new TranslateContext(
                logger, assemblyPath, options.ReferenceBasePaths, options.TargetPlatform);
            var preparedFunctions = AssemblyPreparer.Prepare(
                translateContext);

            logger.Information($"Translating assembly: {Path.GetFullPath(assemblyPath)}");

            // TODO: Makes asynchronously operation.

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

            logger.Information($"Translated assembly: Stored into {Path.GetFullPath(storage.BasePath)}");

            return translateContext.MetadataContext.EntryPoint;
        }

        public static ValueTask<IMethodInformation> TranslateAsync(
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
