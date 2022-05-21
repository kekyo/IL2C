////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;

namespace IL2C.BasicTypes
{
    public delegate void IntRefDelegate(ref int value);

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

        [TestCase(10100, new[] { "Remove_DelegateInstance", "IntRefImpl1", "IntRefImpl2" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
        public static int Remove_DelegateInstance(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg1;

            // Remove only a tail delegate.
            // (dlg1 + dlg2 + dlg1) - dlg1 = (dlg1 + dlg2)
            var dlg = (IntRefDelegate?)Delegate.Remove(dlgA, dlg1);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        [TestCase(10100, new[] { "Remove_DelegateTarget", "IntRefImpl1", "IntRefImpl2" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
        public static int Remove_DelegateTarget(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl1);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            // Remove only a tail delegate.
            // (dlg1 + dlg2 + dlg3[=dlg1]) - dlg1 = (dlg1 + dlg2)
            var dlg = (IntRefDelegate?)Delegate.Remove(dlgA, dlg1);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        [TestCase(5050, new[] { "Remove_DelegateMiddle", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
        public static int Remove_DelegateMiddle(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            // (dlg1 + dlg2 + dlg3) - dlg2 = (dlg1 + dlg3)
            var dlg = (IntRefDelegate?)Delegate.Remove(dlgA, dlg2);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        [TestCase(50000, new[] { "Remove_DelegateHead", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
        public static int Remove_DelegateHead(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            // (dlg1 + dlg2 + dlg3) - dlg1 = (dlg2 + dlg3)
            var dlg = (IntRefDelegate?)Delegate.Remove(dlgA, dlg1);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        [TestCase(50500, new[] { "Remove_NotContainsDelegate", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3", "IntRefImpl4" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
        public static int Remove_NotContainsDelegate(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);
            var dlg4 = new IntRefDelegate(IntRefImpl4);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            // (dlg1 + dlg2 + dlg3) - dlg4 = (dlg1 + dlg2 + dlg3)
            var dlg = (IntRefDelegate?)Delegate.Remove(dlgA, dlg4);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        [TestCase(1000, new[] { "Remove_FromNullToDelegate", "IntRefImpl1" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
        public static int Remove_FromNullToDelegate(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);

            // null - dlg1 = null
            var dlg = (IntRefDelegate?)Delegate.Remove(null, dlg1);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        [TestCase(5000, new[] { "Remove_ToMulticastDelegate1", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
        public static int Remove_ToMulticastDelegate1(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            var dlgB = dlg1 + dlg2;

            // (dlg1 + dlg2 + dlg3) - (dlg1 + dlg2) = dlg3
            var dlg = (IntRefDelegate?)Delegate.Remove(dlgA, dlgB);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        [TestCase(1010, new[] { "Remove_ToMulticastDelegate2", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
        public static int Remove_ToMulticastDelegate2(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            var dlgB = dlg2 + dlg3;

            // (dlg1 + dlg2 + dlg3) - (dlg2 + dlg3) = dlg1
            var dlg = (IntRefDelegate?)Delegate.Remove(dlgA, dlgB);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        [TestCase(50500, new[] { "Remove_NotContainsMulticastDelegate", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
        public static int Remove_NotContainsMulticastDelegate(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);
            var dlg3 = new IntRefDelegate(IntRefImpl3);

            var dlgA = dlg1 + dlg2;
            dlgA += dlg3;

            var dlgB = dlg2 + dlg1;

            // (dlg1 + dlg2 + dlg3) - (dlg2 + dlg1) = (dlg1 + dlg2 + dlg3)
            var dlg = (IntRefDelegate?)Delegate.Remove(dlgA, dlgB);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        [TestCase(1000, new[] { "Remove_EntireMatchedMulticastDelegate", "IntRefImpl1", "IntRefImpl2", "IntRefImpl3" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
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
            var dlg = (IntRefDelegate?)Delegate.Remove(dlgA, dlgB);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }

        [TestCase(1000, new[] { "Remove_FromNullToMulticastDelegate", "IntRefImpl1", "IntRefImpl2" }, 1000, IncludeTypes = new[] { typeof(IntRefDelegate) })]
        public static int Remove_FromNullToMulticastDelegate(int value)
        {
            var dlg1 = new IntRefDelegate(IntRefImpl1);
            var dlg2 = new IntRefDelegate(IntRefImpl2);

            var dlgA = dlg1 + dlg2;

            // null - (dlg1 + dlg2) = null
            var dlg = (IntRefDelegate?)Delegate.Remove(null, dlgA);

            var v = value;
            dlg?.Invoke(ref v);

            return v;
        }
    }
}
