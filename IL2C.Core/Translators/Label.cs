namespace IL2C.Translators
{
    public struct Label
    {
        public readonly int ILByteIndex;

        public Label(int ilByteIndex)
        {
            this.ILByteIndex = ilByteIndex;
        }
    }
}
