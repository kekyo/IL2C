using System;
using System.Collections;

namespace System.Runtime.InteropServices
{
    [AttributeUsage(AttributeTargets.Method, AllowMultiple=false, Inherited=false)]
    public sealed class NativeMethodAttribute : NativeAttribute
    {
        public NativeMethodAttribute(string includeFileName)
            : base(includeFileName)
        {
        }

        internal NativeMethodAttribute(object arg0, IDictionary props)
            : base(arg0, props)
        {
            this.LibraryFileName = (string)props["LibraryFileName"];
            var charSet = props["CharSet"];
            if (charSet is NativeCharSet) this.CharSet = (NativeCharSet)charSet;
        }

        public string LibraryFileName { get; set; }
        public NativeCharSet CharSet { get; set; }
    }
}
