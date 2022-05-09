////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System.Collections.Generic;

namespace IL2C.Internal
{
    internal interface ICombinedComparer<T>
        : IEqualityComparer<T>, IComparer<T>
    {
    }
}
