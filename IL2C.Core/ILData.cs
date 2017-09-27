namespace IL2C
{
    internal struct ILData
    {
        public readonly string LabelName;
        public readonly ILConverter ILConverter;
        public readonly object Operand;

        public ILData(string labelName, ILConverter ilc, object operand)
        {
            this.LabelName = labelName;
            this.ILConverter = ilc;
            this.Operand = operand;
        }
    }
}
