using System;

namespace HelloWorld
{
  class Program
  {
  
  	static bool IsPalindrome(string s){
    	for(int i = 0; i < s.Length / 2; i++){
        	if(s[i] != s[s.Length - 1 - i]){
            	return false;
            }
        }
        return true;
    }
    
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        for(int i = 0; i < n; i++){
        	string s = Console.ReadLine();
            if(!IsPalindrome(s)){
            	Console.WriteLine(s.Length);
            }else if(s.Length != 1){
            	bool done = false;
            	for(int j = 0; j < s.Length; j++){
                	string t = s.Substring(0, j) + s.Substring(j + 1, s.Length - j - 1);
                	if(!IsPalindrome(t)){
            			Console.WriteLine(t.Length);
                        done = true;
                        break;
                    }
                }
                if(!done){
                	Console.WriteLine(-1);
                }
            }else{
                Console.WriteLine(-1);
            }
        }
    }
  }
}
