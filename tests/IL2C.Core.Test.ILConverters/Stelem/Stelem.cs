/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Runtime.CompilerServices;

namespace IL2C.ILConverters
{
    [TestCase((byte)123, new[] { "Byte", "ByteInner" }, 0, (byte)123)]
    [TestCase((byte)125, new[] { "Byte", "ByteInner" }, 1, (byte)125)]
    [TestCase((byte)127, new[] { "Byte", "ByteInner" }, 2, (byte)127)]
    [TestCase((byte)123, new[] { "ByteIntPtrIndex", "ByteIntPtrIndexInner" }, 0, (byte)123)]
    [TestCase((byte)125, new[] { "ByteIntPtrIndex", "ByteIntPtrIndexInner" }, 1, (byte)125)]
    [TestCase((byte)127, new[] { "ByteIntPtrIndex", "ByteIntPtrIndexInner" }, 2, (byte)127)]
    [TestCase((short)123, new[] { "Int16", "Int16Inner" }, 0, (short)123)]
    [TestCase((short)456, new[] { "Int16", "Int16Inner" }, 1, (short)456)]
    [TestCase((short)789, new[] { "Int16", "Int16Inner" }, 2, (short)789)]
    [TestCase((short)123, new[] { "Int16IntPtrIndex", "Int16IntPtrIndexInner" }, 0, (short)123)]
    [TestCase((short)456, new[] { "Int16IntPtrIndex", "Int16IntPtrIndexInner" }, 1, (short)456)]
    [TestCase((short)789, new[] { "Int16IntPtrIndex", "Int16IntPtrIndexInner" }, 2, (short)789)]
    [TestCase(123, new[] { "Int32", "Int32Inner" }, 0, 123)]
    [TestCase(456, new[] { "Int32", "Int32Inner" }, 1, 456)]
    [TestCase(789, new[] { "Int32", "Int32Inner" }, 2, 789)]
    [TestCase(123, new[] { "Int32IntPtrIndex", "Int32IntPtrIndexInner" }, 0, 123)]
    [TestCase(456, new[] { "Int32IntPtrIndex", "Int32IntPtrIndexInner" }, 1, 456)]
    [TestCase(789, new[] { "Int32IntPtrIndex", "Int32IntPtrIndexInner" }, 2, 789)]
    [TestCase(123L, new[] { "Int64", "Int64Inner" }, 0, 123L)]
    [TestCase(456L, new[] { "Int64", "Int64Inner" }, 1, 456L)]
    [TestCase(789L, new[] { "Int64", "Int64Inner" }, 2, 789L)]
    [TestCase(123L, new[] { "Int64IntPtrIndex", "Int64IntPtrIndexInner" }, 0, 123L)]
    [TestCase(456L, new[] { "Int64IntPtrIndex", "Int64IntPtrIndexInner" }, 1, 456L)]
    [TestCase(789L, new[] { "Int64IntPtrIndex", "Int64IntPtrIndexInner" }, 2, 789L)]
    [TestCase(123f, new[] { "Single", "SingleInner" }, 0, 123f)]
    [TestCase(456f, new[] { "Single", "SingleInner" }, 1, 456f)]
    [TestCase(789f, new[] { "Single", "SingleInner" }, 2, 789f)]
    [TestCase(123f, new[] { "SingleIntPtrIndex", "SingleIntPtrIndexInner" }, 0, 123f)]
    [TestCase(456f, new[] { "SingleIntPtrIndex", "SingleIntPtrIndexInner" }, 1, 456f)]
    [TestCase(789f, new[] { "SingleIntPtrIndex", "SingleIntPtrIndexInner" }, 2, 789f)]
    [TestCase(123.111, new[] { "Double", "DoubleInner" }, 0, 123.111)]
    [TestCase(456.222, new[] { "Double", "DoubleInner" }, 1, 456.222)]
    [TestCase(789.333, new[] { "Double", "DoubleInner" }, 2, 789.333)]
    [TestCase(123.111, new[] { "DoubleIntPtrIndex", "DoubleIntPtrIndexInner" }, 0, 123.111)]
    [TestCase(456.222, new[] { "DoubleIntPtrIndex", "DoubleIntPtrIndexInner" }, 1, 456.222)]
    [TestCase(789.333, new[] { "DoubleIntPtrIndex", "DoubleIntPtrIndexInner" }, 2, 789.333)]
    [TestCase("123", new[] { "Object", "ObjectInner" }, 0, "123")]
    [TestCase("456", new[] { "Object", "ObjectInner" }, 1, "456")]
    [TestCase("789", new[] { "Object", "ObjectInner" }, 2, "789")]
    [TestCase("123", new[] { "ObjectIntPtrIndex", "ObjectIntPtrIndexInner" }, 0, "123")]
    [TestCase("456", new[] { "ObjectIntPtrIndex", "ObjectIntPtrIndexInner" }, 1, "456")]
    [TestCase("789", new[] { "ObjectIntPtrIndex", "ObjectIntPtrIndexInner" }, 2, "789")]
    public sealed class Stelem
    {
        public static byte Byte(int index, byte value)
        {
            var values = new byte[] { 1, 2, 3 };
            ByteInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void ByteInner(byte[] values, int index, byte value);

        public static byte ByteIntPtrIndex(int index, byte value)
        {
            var values = new byte[] { 1, 2, 3 };
            ByteIntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void ByteIntPtrIndexInner(byte[] values, int index, byte value);

        //////////////////////////////////////////////////////////////////////

        public static short Int16(int index, short value)
        {
            var values = new short[] { 1, 2, 3 };
            Int16Inner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int16Inner(short[] values, int index, short value);

        public static short Int16IntPtrIndex(int index, short value)
        {
            var values = new short[] { 1, 2, 3 };
            Int16IntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int16IntPtrIndexInner(short[] values, int index, short value);

        //////////////////////////////////////////////////////////////////////

        public static int Int32(int index, int value)
        {
            var values = new[] { 1, 2, 3 };
            Int32Inner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int32Inner(int[] values, int index, int value);

        public static int Int32IntPtrIndex(int index, int value)
        {
            var values = new[] { 1, 2, 3 };
            Int32IntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int32IntPtrIndexInner(int[] values, int index, int value);

        //////////////////////////////////////////////////////////////////////

        public static long Int64(int index, long value)
        {
            var values = new long[] { 1, 2, 3 };
            Int64Inner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int64Inner(long[] values, int index, long value);

        public static long Int64IntPtrIndex(int index, long value)
        {
            var values = new long[] { 1, 2, 3 };
            Int64IntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void Int64IntPtrIndexInner(long[] values, int index, long value);

        //////////////////////////////////////////////////////////////////////

        public static float Single(int index, float value)
        {
            var values = new[] { 1f, 2f, 3f };
            SingleInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void SingleInner(float[] values, int index, float value);

        public static float SingleIntPtrIndex(int index, float value)
        {
            var values = new[] { 1f, 2f, 3f };
            SingleIntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void SingleIntPtrIndexInner(float[] values, int index, float value);

        //////////////////////////////////////////////////////////////////////

        public static double Double(int index, double value)
        {
            var values = new double[] { 1, 2, 3 };
            DoubleInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void DoubleInner(double[] values, int index, double value);

        public static double DoubleIntPtrIndex(int index, double value)
        {
            var values = new double[] { 1, 2, 3 };
            DoubleIntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void DoubleIntPtrIndexInner(double[] values, int index, double value);

        //////////////////////////////////////////////////////////////////////

        public static string Object(int index, string value)
        {
            var values = new[] { "1", "2", "3" };
            ObjectInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void ObjectInner(string[] values, int index, string value);

        public static string ObjectIntPtrIndex(int index, string value)
        {
            var values = new[] { "1", "2", "3" };
            ObjectIntPtrIndexInner(values, index, value);
            return values[index];
        }

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern void ObjectIntPtrIndexInner(string[] values, int index, string value);
    }
}
