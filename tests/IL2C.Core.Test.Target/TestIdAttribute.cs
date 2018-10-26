using System;

namespace IL2C
{
    [AttributeUsage(AttributeTargets.Class)]
    public sealed class TestIdAttribute : Attribute
    {
        public TestIdAttribute(string id)
        {
            this.Id = id;
        }

        public string Id { get; }
    }
}
