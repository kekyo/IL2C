namespace IL2C
{
    internal sealed class ILData
    {
        public readonly ILConverter ILConverter;
        public readonly object Operand;

        public ILData(ILConverter ilc)
        {
            this.ILConverter = ilc;
            this.Operand = null;
        }

        public ILData(ILConverter ilc, object operand)
        {
            this.ILConverter = ilc;
            this.Operand = operand;
        }
    }
}
