#include <iostream>
using namespace std;


int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
	long long fib[n+1];
	fib[1]=0;
	fib[2]=1;
	for(int i=3;i<=n;i++)
		fib[i]=fib[i-1]+fib[i-2];
    cout << "The " << n << "th fibonacci number is " << fib[n] << endl;
    return 0;
}