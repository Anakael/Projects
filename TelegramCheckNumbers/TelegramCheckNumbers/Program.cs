using System;
using System.Collections.Generic;
using TLSharp.Core;
using System.Threading.Tasks;
using System.IO;

namespace TelegramCheckNumbers
{
	
	class MainClass
	{
		static public bool MainMet(string Number, TelegramClient client)
		{   
            var result = client.IsPhoneRegisteredAsync(Number).Result;
			return result;
		}
        public static void Main(string[] args)
		{
		    var store = new FileSessionStore();
            var client = new TelegramClient(119566, "0099dda2c47fc7bc1b302fa4488cc662",store);
		    
            
            StreamWriter sw = new StreamWriter("output.txt");
            for(int i1 =0; i1< 9; i1++)
            for(int i2 =0; i2< 9; i2++)
            for(int i3 =0; i3< 9; i3++)
            for(int i4 =0; i4< 9; i4++)
            for(int i5 =0; i5< 9; i5++)
            for(int i6 =0; i6< 9; i6++)
            for(int i7 =0; i7< 9; i7++)
            {
                string number = "+7981" + i1 + i2 + i3 + i4 + i5 + i6 + i7;
                var result = MainMet(number, client);
                if (result)
                {
                    Console.WriteLine(number);
                    sw.WriteLine(number);
                }
                
                
            }
            sw.Close();
		}
	}
}
