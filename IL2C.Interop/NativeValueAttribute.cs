using System;
using System.Collections;

namespace IL2C
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
