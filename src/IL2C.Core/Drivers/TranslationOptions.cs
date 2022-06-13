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
}
