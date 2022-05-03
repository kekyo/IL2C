////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using Mono.Cecil;

namespace IL2C.Metadata.Attributes
{
    public sealed class NativeValueAttributeInformation
    {
        internal NativeValueAttributeInformation(CustomAttribute attribute)
        {
            this.IncludeFileName = attribute.GetArgument<string>(0);
            this.SymbolName = attribute.GetProperty<string>("SymbolName");
        }

        public string IncludeFileName { get; }
        public string SymbolName { get; set; }

        internal static readonly string FullName = "System.Runtime.InteropServices.NativeValueAttribute";
    }
}
