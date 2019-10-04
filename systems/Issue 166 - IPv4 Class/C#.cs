using System;
using System.Linq;

namespace IPv4ClassApp
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.Write("Enter the IPv4 Address: ");
            string ipAddr = Console.ReadLine();

            if (ValidateIPv4(ipAddr))
            {
                FindClass(ipAddr);

                Console.WriteLine("Press any key to exit");
                Console.ReadKey();
            }
            else { 
                Console.WriteLine("{0} is not a valid IP address", ipAddr);

                Console.WriteLine("Press any key to exit");
                Console.ReadKey();
            }
        }

        private static bool ValidateIPv4(string ipString)
        {
            if (String.IsNullOrWhiteSpace(ipString))
            {
                return false;
            }

            string[] splitValues = ipString.Split('.');
            if (splitValues.Length != 4)
            {
                return false;
            }

            byte tempForParsing;

            return splitValues.All(r => byte.TryParse(r, out tempForParsing));
        }

        private static void FindClass(string ipAddr)
        {
            char[] data = ipAddr.ToCharArray(0, 4);

            char[] arr = new char[4];
            int i = 0;

            while (data[i] != '.')
            {
                arr[i] = data[i];
                i++;
            }
            i--;

            int ip = 0, j = 1;
            while (i >= 0)
            {
                ip = ip + (data[i] - '0') * j;
                j = j * 10;
                i--;
            }

            // Class A 
            if (ip >= 0 && ip <= 127)
                Console.WriteLine("This is a class A IPv4 address");

            // Class B 
            else if (ip >= 128 && ip <= 191)
                Console.WriteLine("This is a class B IPv4 address");

            // Class C 
            else if (ip >= 192 && ip <= 223)
                Console.WriteLine("This is a class C IPv4 address");

            // Class D 
            else if (ip >= 224 && ip <= 239)
                Console.WriteLine("This is a class D IPv4 address");
            // Class E 
            else
                Console.WriteLine("This is a class E IPv4 address");
        }
    }
}
