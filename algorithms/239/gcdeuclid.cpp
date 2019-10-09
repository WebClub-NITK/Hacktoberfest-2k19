#include <iostream>
using namespace std;
int gcd(int a, int b);
int main()
{
   int n1, n2;
   cout << "Enter two positive integers: ";
   cin >> n1 >> n2;
   cout << "G.C.D of " << n1 << " , " <<  n2 << " is: " << gcd(n1, n2);
   return 0;
}
int gcd(int n1, int n2)
{
    if (n2 == 0)
        return n1;
    else 
    return gcd(n2, n1 % n2);
       
}