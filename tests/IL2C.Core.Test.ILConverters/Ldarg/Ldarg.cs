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
    [TestCase(true, "Boolean_4", 0, 1, 2, 3, false)]
    [TestCase(false, "Boolean_4", 0, 1, 2, 3, true)]
    [TestCase((byte)(byte.MaxValue - 1), "Byte_4", 0, 1, 2, 3, byte.MaxValue)]
    [TestCase((short)(short.MaxValue - 1), "Int16_4", 0, 1, 2, 3, short.MaxValue)]
    [TestCase(int.MaxValue - 1, "Int32_4", 0, 1, 2, 3, int.MaxValue)]
    [TestCase(long.MaxValue - 1, "Int64_4", 0, 1, 2, 3, long.MaxValue)]
    [TestCase((sbyte)(sbyte.MaxValue - 1), "SByte_4", 0, 1, 2, 3, sbyte.MaxValue)]
    [TestCase((ushort)(ushort.MaxValue - 1), "UInt16_4", 0, 1, 2, 3, ushort.MaxValue)]
    [TestCase(uint.MaxValue - 1, "UInt32_4", 0, 1, 2, 3, uint.MaxValue)]
    [TestCase(ulong.MaxValue - 1, "UInt64_4", 0, 1, 2, 3, ulong.MaxValue)]
    [TestCase(int.MaxValue - 1, "IntPtr_4", 0, 1, 2, 3, int.MaxValue)]
    [TestCase(uint.MaxValue - 1, "UIntPtr_4", 0, 1, 2, 3, uint.MaxValue)]
    [TestCase((float)((double)123.45f + (double)3.14159274f), "Single_4", 0, 1, 2, 3, 123.45f)]
    [TestCase(123.45 + 3.1415926535897931, "Double_4", 0, 1, 2, 3, 123.45)]
    [TestCase("ABCD", "String_4", 0, 1, 2, 3, "ABC")]
    [TestCase('B', "Char_4", 0, 1, 2, 3, 'A')]
    [TestCase("ABCD", "Argument_256",
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        "ABC")]
    public sealed class Ldarg
    {
        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern bool Boolean_4(
            int arg0, int arg1, int arg2, int arg3, bool value);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern byte Byte_4(
            int arg0, int arg1, int arg2, int arg3, byte num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern short Int16_4(
            int arg0, int arg1, int arg2, int arg3, short num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern int Int32_4(
            int arg0, int arg1, int arg2, int arg3, int num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern long Int64_4(
            int arg0, int arg1, int arg2, int arg3, long num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern sbyte SByte_4(
            int arg0, int arg1, int arg2, int arg3, sbyte num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ushort UInt16_4(
            int arg0, int arg1, int arg2, int arg3, ushort num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern uint UInt32_4(
            int arg0, int arg1, int arg2, int arg3, uint num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern ulong UInt64_4(
            int arg0, int arg1, int arg2, int arg3, ulong num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern IntPtr IntPtr_4(
            int arg0, int arg1, int arg2, int arg3, IntPtr num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern UIntPtr UIntPtr_4(
            int arg0, int arg1, int arg2, int arg3, UIntPtr num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern float Single_4(
            int arg0, int arg1, int arg2, int arg3, float num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern double Double_4(
            int arg0, int arg1, int arg2, int arg3, double num);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern char Char_4(
            int arg0, int arg1, int arg2, int arg3, char ch);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string String_4(
            int arg0, int arg1, int arg2, int arg3, string v);

        [MethodImpl(MethodImplOptions.ForwardRef)]
        public static extern string Argument_256(
            int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7,
            int arg8, int arg9, int arga, int argb, int argc, int argd, int arge, int argf,
            int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17,
            int arg18, int arg19, int arg1a, int arg1b, int arg1c, int arg1d, int arg1e, int arg1f,
            int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27,
            int arg28, int arg29, int arg2a, int arg2b, int arg2c, int arg2d, int arg2e, int arg2f,
            int arg30, int arg31, int arg32, int arg33, int arg34, int arg35, int arg36, int arg37,
            int arg38, int arg39, int arg3a, int arg3b, int arg3c, int arg3d, int arg3e, int arg3f,
            int arg40, int arg41, int arg42, int arg43, int arg44, int arg45, int arg46, int arg47,
            int arg48, int arg49, int arg4a, int arg4b, int arg4c, int arg4d, int arg4e, int arg4f,
            int arg50, int arg51, int arg52, int arg53, int arg54, int arg55, int arg56, int arg57,
            int arg58, int arg59, int arg5a, int arg5b, int arg5c, int arg5d, int arg5e, int arg5f,
            int arg60, int arg61, int arg62, int arg63, int arg64, int arg65, int arg66, int arg67,
            int arg68, int arg69, int arg6a, int arg6b, int arg6c, int arg6d, int arg6e, int arg6f,
            int arg70, int arg71, int arg72, int arg73, int arg74, int arg75, int arg76, int arg77,
            int arg78, int arg79, int arg7a, int arg7b, int arg7c, int arg7d, int arg7e, int arg7f,
            int arg80, int arg81, int arg82, int arg83, int arg84, int arg85, int arg86, int arg87,
            int arg88, int arg89, int arg8a, int arg8b, int arg8c, int arg8d, int arg8e, int arg8f,
            int arg90, int arg91, int arg92, int arg93, int arg94, int arg95, int arg96, int arg97,
            int arg98, int arg99, int arg9a, int arg9b, int arg9c, int arg9d, int arg9e, int arg9f,
            int arga0, int arga1, int arga2, int arga3, int arga4, int arga5, int arga6, int arga7,
            int arga8, int arga9, int argaa, int argab, int argac, int argad, int argae, int argaf,
            int argb0, int argb1, int argb2, int argb3, int argb4, int argb5, int argb6, int argb7,
            int argb8, int argb9, int argba, int argbb, int argbc, int argbd, int argbe, int argbf,
            int argc0, int argc1, int argc2, int argc3, int argc4, int argc5, int argc6, int argc7,
            int argc8, int argc9, int argca, int argcb, int argcc, int argcd, int argce, int argcf,
            int argd0, int argd1, int argd2, int argd3, int argd4, int argd5, int argd6, int argd7,
            int argd8, int argd9, int argda, int argdb, int argdc, int argdd, int argde, int argdf,
            int arge0, int arge1, int arge2, int arge3, int arge4, int arge5, int arge6, int arge7,
            int arge8, int arge9, int argea, int argeb, int argec, int arged, int argee, int argef,
            int argf0, int argf1, int argf2, int argf3, int argf4, int argf5, int argf6, int argf7,
            int argf8, int argf9, int argfa, int argfb, int argfc, int argfd, int argfe, int argff,
            string v);
    }
}
