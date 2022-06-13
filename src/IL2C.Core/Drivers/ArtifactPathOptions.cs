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
    public sealed class ArtifactPathOptions
    {
        public readonly string OutputNativeArchiveFileName;
        public readonly string? OutputNativeExecutableFileName;

        public ArtifactPathOptions(
            string outputNativeArchiveFileName,
            string? outputNativeExecutableFileName)
        {
            this.OutputNativeExecutableFileName = outputNativeExecutableFileName;
            this.OutputNativeArchiveFileName = outputNativeArchiveFileName;
        }
    }
}
