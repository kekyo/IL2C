using System;
using System.Collections;

namespace System.Runtime.InteropServices
{
    [AttributeUsage(AttributeTargets.Struct | AttributeTargets.Enum | AttributeTargets.Delegate, AllowMultiple=false, Inherited=false)]
    public sealed class NativeTypeAttribute : NativeAttribute
    {
        public NativeTypeAttribute(string includeFileName)
            : base(includeFileName)
        {
        }

        internal NativeTypeAttribute(object arg0, IDictionary props)
            : base(arg0, props)
        {
        }
    }
}
