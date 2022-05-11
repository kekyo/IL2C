////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Diagnostics;

using Mono.Cecil.Cil;

using IL2C.Metadata;
using IL2C.Translators;

namespace IL2C.ILConverters
{
    internal sealed class ConstrainedConverter : InlineTypeConverter
    {
        public override OpCode OpCode => OpCodes.Constrained;

        public override ExpressionEmitter Prepare(
            ITypeInformation type, DecodeContext decodeContext)
        {
            decodeContext.SetPrefixCode();

            return emptyEmitter;
        }
    }
}
