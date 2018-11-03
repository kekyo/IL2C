using System.Collections.Generic;

namespace IL2C
{
    internal interface ICombinedComparer<T>
        : IEqualityComparer<T>, IComparer<T>
    {
    }
}
