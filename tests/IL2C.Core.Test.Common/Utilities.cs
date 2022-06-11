////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System;
using System.Runtime.InteropServices;

namespace IL2C
{
    [IgnoreTranslation]
    public static class Utilities
    {
        public static readonly bool IsRunningOnWindows =
            Environment.OSVersion.Platform == PlatformID.Win32NT;

        public static readonly bool IsRunningOnMono =
            Type.GetType("Mono.Runtime") != null;
    }
}
