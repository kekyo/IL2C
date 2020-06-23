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

namespace IL2C.BasicTypes
{
    public delegate void IntRefDelegate(ref int value);

    [TestCase(10100, new[] { "Remove_DelegateInstance", "IntRefImpl1", "IntRefImpl2" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    [TestCase(10100, new[] { "Remove_DelegateTarget", "IntRefImpl1", "IntRefImpl2" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    [TestCase(5050, new[] { "Remove_DelegateMiddle", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    [TestCase(50000, new[] { "Remove_DelegateHead", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    [TestCase(50500, new[] { "Remove_NotContainsDelegate", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3", "IntRefImpl4" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    [TestCase(1000, new[] { "Remove_FromNullToDelegate", "IntRefImpl1" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    [TestCase(5000, new[] { "Remove_ToMulticastDelegate1", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    [TestCase(1010, new[] { "Remove_ToMulticastDelegate2", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    [TestCase(50500, new[] { "Remove_NotContainsMulticastDelegate", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    [TestCase(1000, new[] { "Remove_EntireMatchedMulticastDelegate", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    [TestCase(1000, new[] { "Remove_FromNullToMulticastDelegate", "IntRefImpl1", "IntRefImpl2" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
    public sealed class System_Delegate
    {
        private static void IntRefImpl1(ref int value)
        {
            value += 10;
        }

        private static void IntRefImpl2(ref int value)
        {
            value *= 10;
        }

        private static void IntRefImpl3(ref int value)
        {
            value *= 5;
        }

        private static void IntRefImpl4(ref int value)
        {
            value *= 3;
        }

        public static int Remove_DelegateInstance(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg1;

            // Remove only a tail delegate.
            // (dlg1 + dlg2 + dlg1) - dlg1 = (dlg1 + dlg2)
            var dlg = (IntRefDelegate)Delegate.Remove(dlgA, dlg1);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        public static int Remove_DelegateTarget(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl1);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            // Remove only a tail delegate.
            // (dlg1 + dlg2 + dlg3[=dlg1]) - dlg1 = (dlg1 + dlg2)
            var dlg = (IntRefDelegate)Delegate.Remove(dlgA, dlg1);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        public static int Remove_DelegateMiddle(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            // (dlg1 + dlg2 + dlg3) - dlg2 = (dlg1 + dlg3)
            var dlg = (IntRefDelegate)Delegate.Remove(dlgA, dlg2);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        public static int Remove_DelegateHead(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            // (dlg1 + dlg2 + dlg3) - dlg1 = (dlg2 + dlg3)
            var dlg = (IntRefDelegate)Delegate.Remove(dlgA, dlg1);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        public static int Remove_NotContainsDelegate(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);
            var dlg4 = new IntRefDelegate(IntRefImpl4);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            // (dlg1 + dlg2 + dlg3) - dlg4 = (dlg1 + dlg2 + dlg3)
            var dlg = (IntRefDelegate)Delegate.Remove(dlgA, dlg4);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        public static int Remove_FromNullToDelegate(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);

            // null - dlg1 = null
            var dlg = (IntRefDelegate)Delegate.Remove(null, dlg1);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        public static int Remove_ToMulticastDelegate1(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            var dlgB = dlg1 + dlg2;

            // (dlg1 + dlg2 + dlg3) - (dlg1 + dlg2) = dlg3
            var dlg = (IntRefDelegate)Delegate.Remove(dlgA, dlgB);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        public static int Remove_ToMulticastDelegate2(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            var dlgB = dlg2 + dlg3;

            // (dlg1 + dlg2 + dlg3) - (dlg2 + dlg3) = dlg1
            var dlg = (IntRefDelegate)Delegate.Remove(dlgA, dlgB);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        public static int Remove_NotContainsMulticastDelegate(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            var dlgB = dlg2 + dlg1;

            // (dlg1 + dlg2 + dlg3) - (dlg2 + dlg1) = (dlg1 + dlg2 + dlg3)
            var dlg = (IntRefDelegate)Delegate.Remove(dlgA, dlgB);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        public static int Remove_EntireMatchedMulticastDelegate(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            var dlgB = dlg1 + dlg2;
            dlgB += dlg3;

            // (dlg1 + dlg2 + dlg3) - (dlg1 + dlg2 + dlg3) = null
            var dlg = (IntRefDelegate)Delegate.Remove(dlgA, dlgB);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        public static int Remove_FromNullToMulticastDelegate(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);

            var dlgA = dlg1 + dlg2;

            // null - (dlg1 + dlg2) = null
            var dlg = (IntRefDelegate)Delegate.Remove(null, dlgA);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }
    }
}
