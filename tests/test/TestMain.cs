////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;

namespace test
{
    public static class TestMain
    {
        public static int Main()
        {
            //try
            //{
#if false
                ////////////////////////
                // Execute target function.

                {mainSymbol}();
#else
                var expected = true;

                ////////////////////////
                // Execute target function.

                var actual = IL2C.BasicTypes.System_Boolean.IsValueType();

                ////////////////////////
                // Check result.

                if (actual != expected)
                {
                    Console.WriteLine(
                        (((object)actual) == null) ?
                        "null" :
                        actual.ToString());
                    return 1;
                }
#endif
            //}
            //catch (Exception ex)
            //{
            //    Console.WriteLine(ex.ToString());
            //    return 2;
            //}

            return 0;
        }
    }
}
