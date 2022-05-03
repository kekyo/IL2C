////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;

namespace IL2C
{
    public sealed class InvalidProgramSequenceException : Exception
    {
        public InvalidProgramSequenceException(string format, params object[] args)
            : base(string.Format(format, args))
        {
        }
    }
}
