////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System;

namespace IL2C.Tests
{
    public static class TestMain
    {
        public static int Main()
        {
            try
            {
#if {mainIsVoid}
                ////////////////////////
                // Execute target function.

                {mainSymbol}();
#else
                ////////////////////////
                // Execute target function.

                var actual = {mainSymbol}();

                ////////////////////////
                // Check result.

                if (actual != {expected})
                {
                    Console.WriteLine(actual?.ToString());
                    return 1;
                }
#endif
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
                return 2;
            }

            return 0;
        }
    }
}
