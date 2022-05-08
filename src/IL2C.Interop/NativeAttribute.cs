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
    public abstract class NativeAttribute : Attribute
    {
        protected NativeAttribute(string includeFileName)
        {
            this.IncludeFileName = includeFileName;
        }

        internal NativeAttribute(object arg0, IDictionary props)
        {
            this.IncludeFileName = (string)arg0;
            this.SymbolName = (string?)props["SymbolName"];
        }

        public string IncludeFileName { get; }
        public string? SymbolName { get; set; }
    }
}
