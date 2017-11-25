using System;
using System.Collections.Generic;
using System.Text;

namespace IL2C.Translators
{
    public struct Parameter
    {
        public readonly string Name;
        public readonly Type ParameterType;

        public Parameter(string name, Type parameterType)
        {
            this.Name = name;
            this.ParameterType = parameterType;
        }
    }
}
