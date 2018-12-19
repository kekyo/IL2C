using System;
using System.Collections;

namespace IL2C
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
            this.SymbolName = (string)props["SymbolName"];
        }

        public string IncludeFileName { get; }
        public string SymbolName { get; set; }
    }
}
