using System;
using System.Collections;

namespace IL2C
{
    [AttributeUsage(AttributeTargets.Method, AllowMultiple=false, Inherited=false)]
    public sealed class NativeMethodAttribute : Attribute
    {
        public NativeMethodAttribute(string includeFileName)
        {
            this.IncludeFileName = includeFileName;
        }

        internal NativeMethodAttribute(object arg0, IDictionary props)
        {
            this.IncludeFileName = (string)arg0;
            this.LibraryFileName = (string)props["LibraryFileName"];
            this.EntryPoint = (string)props["EntryPoint"];
            var charSet = props["CharSet"];
            if (charSet is CharSet) this.CharSet = (CharSet)charSet;
        }

        public string IncludeFileName { get; }
        public string LibraryFileName { get; set; }
        public string EntryPoint { get; set; }
        public CharSet CharSet { get; set; }
    }
}
