////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections;

namespace System.Runtime.InteropServices
{
    [AttributeUsage(AttributeTargets.Field, AllowMultiple=false, Inherited=false)]
    public sealed class NativeValueAttribute : NativeAttribute
    {
        public NativeValueAttribute(string includeFileName)
            : base(includeFileName)
        {
        }

        internal NativeValueAttribute(object arg0, IDictionary props)
            : base(arg0, props)
        {
        }
    }
}
