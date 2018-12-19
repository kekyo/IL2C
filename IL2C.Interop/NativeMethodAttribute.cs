using System;
using System.Collections;

namespace IL2C
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
            if (charSet is CharSet) this.CharSet = (CharSet)charSet;
        }

        public string LibraryFileName { get; set; }
        public CharSet CharSet { get; set; }
    }
}
