#include <iostream>
using namespace std;

void uppercase(char *s)
{
    int i = 0;
 
    while(s[i])
    {
        if(s[i]>='a' && s[i]<='z')
		{
            s[i]=s[i]-32;
        }
        ++i;
    }
}
 
int main()
{
    char str[100];
    
    cin.getline(str,100);
   
    uppercase(str);
    cout <<str <<endl;
    
    return 0;
}
 


