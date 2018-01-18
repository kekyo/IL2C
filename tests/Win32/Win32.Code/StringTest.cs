using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace Win32.Code
{
    public class StringTest
    {
        public static void LiteralString()
        {
            string a = "ABC";
        }

        public static string InOutString(string a)
        {
            return a;
        }

        public static string LiteralCombinedString()
        {
            string a = "ABC";
            string b = "DEF";
            return a + b;
        }

        public static string LiteralSubstring()
        {
            string a = "ABCDEFGHIJKLMN";
            return a.Substring(3);
        }

        public static char GetChar()
        {
            return 'A';
        }
    }
}
