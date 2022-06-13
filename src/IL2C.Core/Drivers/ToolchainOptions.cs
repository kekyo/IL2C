////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

namespace IL2C.Drivers
{
    public sealed class ToolchainOptions
    {
        public readonly string NativeCompiler;
        public readonly string NativeCompilerFlags;
        public readonly string NativeLinkingFlags;
        public readonly string NativeArchiver;
        public readonly string[] AdditionalIncludeDirs;
        public readonly string[] LibraryPaths;
        public readonly string? MainTemplatePath;
        public readonly bool EnableParallelism;

        public ToolchainOptions(
            string nativeCompiler,
            string nativeCompilerFlags,
            string nativeLinkingFlags,
            string nativeArchiver,
            string[] additionalIncludeDirs,
            string[] libraryPaths,
            string? mainTemplatePath,
            bool enableParallelism)
        {
            this.NativeCompiler = nativeCompiler;
            this.NativeCompilerFlags = nativeCompilerFlags;
            this.NativeLinkingFlags = nativeLinkingFlags;
            this.NativeArchiver = nativeArchiver;
            this.AdditionalIncludeDirs = additionalIncludeDirs;
            this.LibraryPaths = libraryPaths;
            this.MainTemplatePath = mainTemplatePath;
            this.EnableParallelism = enableParallelism;
        }
    }
}
