using System.Collections.Generic;

namespace IL2C.Internal
{
    internal interface ICombinedComparer<T>
        : IEqualityComparer<T>, IComparer<T>
    {
    }
}
