using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace nekosharp
{
    public class NekoSharp
    {
        [DllImport("nekowrapper.dll", CallingConvention=CallingConvention.Cdecl)]
        private extern static int execute_file_in_vm(string nekoFile);

        public static int ExecuteFileInNekoVM(string nekoFile)
        {
            return execute_file_in_vm(nekoFile);
        }
    }
}
