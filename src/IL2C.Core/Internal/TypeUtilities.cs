////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

using Mono.Cecil.Cil;

using IL2C.ILConverters;

namespace IL2C.Internal
{
    internal static class TypeUtilities
    {
        private static readonly Dictionary<OpCode, ILConverter> ilConverters;

        static TypeUtilities()
        {
            ilConverters = typeof(ILConverter).
                GetTypeInfo().
                Assembly.
                DefinedTypes.
                Where(type => type.IsSealed && typeof(ILConverter).GetTypeInfo().IsAssignableFrom(type)).
                Select(type => (ILConverter)Activator.CreateInstance(type.AsType())).
                ToDictionary(ilc => ilc.OpCode);
        }

        public static bool TryGetILConverter(OpCode opCode, out ILConverter ilc) =>
            ilConverters.TryGetValue(opCode, out ilc);

        public static Array ResourceDataToSpecificArray(byte[] values, Type elementType)
        {
            if (elementType == typeof(byte))
            {
                return values;
            }

            var ms = new MemoryStream(values);
            var br = new EndiannessBinaryReader(ms, EndianSpecific.Little, Encoding.Unicode);
            var temp = new ArrayList();

            if (elementType == typeof(sbyte))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadSByte());
                }
            }
            else if (elementType == typeof(short))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadInt16());
                }
            }
            else if (elementType == typeof(int))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadInt32());
                }
            }
            else if (elementType == typeof(long))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadInt64());
                }
            }
            else if (elementType == typeof(ushort))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadUInt16());
                }
            }
            else if (elementType == typeof(uint))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadUInt32());
                }
            }
            else if (elementType == typeof(ulong))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadUInt64());
                }
            }
            else if (elementType == typeof(float))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadSingle());
                }
            }
            else if (elementType == typeof(double))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadDouble());
                }
            }
            else if (elementType == typeof(char))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadChar());
                }
            }
            else if (elementType == typeof(bool))
            {
                while (!br.IsEOF)
                {
                    temp.Add(br.ReadBoolean());
                }
            }
            else
            {
                Debug.Fail("Cannot convert");
            }

            return temp.ToArray(elementType);
        }

        #region LooseTypeKindComparer
        private sealed class LooseTypeKindComparerImpl
            : IEqualityComparer<object>
        {
            public LooseTypeKindComparerImpl()
            {
            }

            public new bool Equals(object x, object y)
            {
                if (object.ReferenceEquals(x, y))
                {
                    return true;
                }

                var tx = x.GetType();
                var ty = y.GetType();
                if (!tx.Equals(ty))
                {
                    return false;
                }

                if (x is string)
                {
                    return x.Equals(y);
                }
                if ((x is IEnumerable) && (y is IEnumerable))
                {
                    var ex = ((IEnumerable)x).RuntimeCast<object>();
                    var ey = ((IEnumerable)y).RuntimeCast<object>();
                    return ex.SequenceEqual(ey, this);
                }

                return x.Equals(y);
            }

            public int GetHashCode(object obj)
            {
                if (obj is string)
                {
                    return obj.GetHashCode();
                }
                if (obj is IEnumerable)
                {
                    return ((IEnumerable)obj).
                        RuntimeCast<object>().
                        Aggregate(0, (s, v) => s ^ this.GetHashCode(v));
                }
                return obj.GetHashCode();
            }
        }

        public static readonly IEqualityComparer<object> LooseTypeKindComparer = new LooseTypeKindComparerImpl();
        #endregion
    }
}
