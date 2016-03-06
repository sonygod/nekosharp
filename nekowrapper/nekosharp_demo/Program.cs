using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using nekosharp;

namespace nekosharp_demo
{
    class Program
    {
        static void Main(string[] args)
        {
            int ret = NekoSharp.ExecuteFileInNekoVM("hi.n");
            Console.WriteLine(ret);
            Console.ReadLine();
        }
    }
}
