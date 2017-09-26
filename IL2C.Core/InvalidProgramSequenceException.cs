using System;

namespace IL2C
{
    public sealed class InvalidProgramSequenceException : Exception
    {
        public InvalidProgramSequenceException(string format, params object[] args)
            : base(string.Format(format, args))
        {
        }
    }
}
