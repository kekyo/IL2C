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
