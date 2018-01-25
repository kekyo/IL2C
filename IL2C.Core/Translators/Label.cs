namespace IL2C.Translators
{
    public struct Label
    {
        public readonly int Offset;

        public Label(int offset)
        {
            this.Offset = offset;
        }

        public override string ToString()
        {
            return string.Format("IL_{0:x4}", this.Offset);
        }
    }
}
