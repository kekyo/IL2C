////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System;
using System.Collections;
using System.Collections.Generic;

namespace IL2C.Internal
{
    internal static class Utilities
    {
        public static IEnumerable<T> RuntimeCast<T>(this IEnumerable enumerable)
        {
            foreach (object? value in enumerable)
            {
                yield return (T)value!;
            }
        }

        public static IEnumerable<T> Traverse<T>(this T first, Func<T, T> next, bool invokeNextFirst = false)
            where T : class
        {
            T current = first;
            if (invokeNextFirst)
            {
                if (current != null)
                {
                    while (true)
                    {
                        current = next(current);
                        if (current == null)
                        {
                            break;
                        }
                        yield return current;
                    }
                }
            }
            else
            {
                while (current != null)
                {
                    yield return current;
                    current = next(current);
                }
            }
        }

        public static IEnumerable<T> Distinct<T, U>(
            this IEnumerable<T> enumerable,
            Func<T, U> keySelector)
        {
            var took = new HashSet<U>();
            foreach (var value in enumerable)
            {
                if (took.Add(keySelector(value)))
                {
                    yield return value;
                }
            }
        }

        private sealed class DistinctEqualityComparer<T> : IEqualityComparer<T>
        {
            private readonly Func<T, int> getHashCode;
            private readonly Func<T?, T?, bool> equals;

            public DistinctEqualityComparer(
                Func<T, int> getHashCode,
                Func<T?, T?, bool> equals)
            {
                this.getHashCode = getHashCode;
                this.equals = equals;
            }

            public bool Equals(T? x, T? y)
            {
                return equals(x, y);
            }

            public int GetHashCode(T obj)
            {
                return getHashCode(obj);
            }
        }

        public static IEnumerable<T> Distinct<T>(
            this IEnumerable<T> enumerable,
            Func<T, int> getHashCode,
            Func<T?, T?, bool> equals)
        {
            var took = new HashSet<T>(new DistinctEqualityComparer<T>(getHashCode, equals));
            foreach (var value in enumerable)
            {
                if (took.Add(value))
                {
                    yield return value;
                }
            }
        }

        public static U UnsafeGetValue<T, U>(this IReadOnlyDictionary<T, U> dict, T key, U defaultValue = default(U)!)
            where T : notnull =>
            dict.TryGetValue(key, out var value) ? value : defaultValue;

        public static U GetOrAdd<T, U>(this Dictionary<T, U> dict, T key, U value)
            where T : notnull
        {
            if (dict.TryGetValue(key, out var v) == false)
            {
                v = value;
                dict.Add(key, v);
            }

            return v;
        }
    }
}
