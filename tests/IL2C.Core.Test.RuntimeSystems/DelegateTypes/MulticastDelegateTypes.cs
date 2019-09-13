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

namespace IL2C.RuntimeSystems
{
    public delegate string RefIntToStringDelegate(ref int value);

    [TestId("DelegateTypes")]
    [TestCase(1333, new[] { "Static_Void_RefInt_Multicast", "Static_Void_RefIntImpl1", "Static_Void_RefIntImpl2" }, 1000, IncludeTypes = new[] { typeof(RefIntDelegate) })]
    [TestCase("1222", new[] { "Static_RefIntToString_Multicast", "Static_RefIntToStringImpl" }, 1000, IncludeTypes = new[] { typeof(RefIntToStringDelegate) })]
    [TestCase("1234ABC", new[] { "Combination_RefIntToString_Multicast1", "Static_RefIntToStringImpl", "Instance_RefIntToStringImpl" }, 1000, IncludeTypes = new[] { typeof(RefIntToStringDelegate) })]
    [TestCase("1234", new[] { "Combination_RefIntToString_Multicast2", "Static_RefIntToStringImpl", "Instance_RefIntToStringImpl" }, 1000, IncludeTypes = new[] { typeof(RefIntToStringDelegate) })]
    [TestCase("1357ABC", new[] { "Combination_RefIntToString_Multicast3", "Static_RefIntToStringImpl", "Instance_RefIntToStringImpl" }, 1000, IncludeTypes = new[] { typeof(RefIntToStringDelegate) })]
    public sealed class MulticastDelegateTypes
    {
        private static void Static_Void_RefIntImpl1(ref int value)
        {
            value += 111;
        }

        private static void Static_Void_RefIntImpl2(ref int value)
        {
            value += 222;
        }

        public static int Static_Void_RefInt_Multicast(int value)
        {
            var dlg1 = new RefIntDelegate(Static_Void_RefIntImpl1);
            var dlg2 = new RefIntDelegate(Static_Void_RefIntImpl2);
            dlg1 += dlg2;

            var v = value;
            dlg1(ref v);

            return v;
        }

        private static string Static_RefIntToStringImpl(ref int value)
        {
            value += 111;
            return value.ToString();
        }

        public static string Static_RefIntToString_Multicast(int value)
        {
            var dlg1 = new RefIntToStringDelegate(Static_RefIntToStringImpl);
            var dlg2 = new RefIntToStringDelegate(Static_RefIntToStringImpl);
            dlg1 += dlg2;

            var v = value;
            return dlg1(ref v);
        }

        private int v1 = 123;

        private string Instance_RefIntToStringImpl(ref int value)
        {
            value += v1;
            return value.ToString() + "ABC";
        }

        public static string Combination_RefIntToString_Multicast1(int value)
        {
            var inst = new MulticastDelegateTypes();
            var dlg1 = new RefIntToStringDelegate(Static_RefIntToStringImpl);
            var dlg2 = new RefIntToStringDelegate(inst.Instance_RefIntToStringImpl);
            dlg1 += dlg2;

            var v = value;
            return dlg1(ref v);
        }

        public static string Combination_RefIntToString_Multicast2(int value)
        {
            var inst = new MulticastDelegateTypes();
            var dlg1 = new RefIntToStringDelegate(inst.Instance_RefIntToStringImpl);
            var dlg2 = new RefIntToStringDelegate(Static_RefIntToStringImpl);
            dlg1 += dlg2;

            var v = value;
            return dlg1(ref v);
        }

        public static string Combination_RefIntToString_Multicast3(int value)
        {
            var inst = new MulticastDelegateTypes();
            var dlg1 = new RefIntToStringDelegate(inst.Instance_RefIntToStringImpl);
            var dlg2 = new RefIntToStringDelegate(Static_RefIntToStringImpl);
            var dlg3 = new RefIntToStringDelegate(inst.Instance_RefIntToStringImpl);
            dlg1 += dlg2;
            dlg1 += dlg3;

            var v = value;
            return dlg1(ref v);
        }
    }
}
