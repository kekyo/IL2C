using System;
using System.Collections;

namespace IL2C
{
    [AttributeUsage(AttributeTargets.Struct | AttributeTargets.Enum | AttributeTargets.Delegate, AllowMultiple=false, Inherited=false)]
    public sealed class NativeTypeAttribute : Attribute
    {
        public NativeTypeAttribute(string includeFileName)
        {
            this.IncludeFileName = includeFileName;
        }

        internal NativeTypeAttribute(object arg0, IDictionary props)
        {
            this.IncludeFileName = (string)arg0;
            this.SymbolName = (string)props["SymbolName"];
        }

        public string IncludeFileName { get; }
        public string SymbolName { get; set; }
    }
}
