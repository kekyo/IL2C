using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace MT3620Blink
{
    public static class Program
    {
        public static int Main()
        {
            while (true)
            {
                for (var index = 0; index < 10000; index++)
                {
                    Console.WriteLine("Hello Azure Sphere with C#! " + index);
                }
            }
        }
    }
}
