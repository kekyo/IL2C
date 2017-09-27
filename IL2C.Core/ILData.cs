namespace IL2C
{
    internal struct ILData
    {
        public readonly Label Label;
        public readonly ILConverter ILConverter;
        public readonly object Operand;

        public ILData(Label label, ILConverter ilc, object operand)
        {
            this.Label = label;
            this.ILConverter = ilc;
            this.Operand = operand;
        }
    }
}
