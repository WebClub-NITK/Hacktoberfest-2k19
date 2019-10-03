//Prints all the prime number between the value low and high
//Algorithm used - Segmented Sieve of Eratosthenes

#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
vector<int>* sieve()
{
    bool isprime[MAX];
    for(int i=0;i<MAX;i++)
    {
        isprime[i] = true;
    }
 
    vector<int>* primes = new vector<int>();
    primes->push_back(2);
    for(int i=2;i*i< MAX;i++)
    {
        for(int j = i*i; j < MAX; j += i)
        {
            isprime[j] = false;
        }
    }
 
    for(int i= 3;i<MAX;i++)
    {
        if(isprime[i])
        {
            primes->push_back(i);
        }
    }
    return primes;
}
 
void getprime(long long l,long long r, vector<int>* &primes)
{
    bool isprime[r-l+1];
    for(int i=0;i<=r-l;i++)
    {
        isprime[i] = true;
    }
 
    for(int i = 0; primes->at(i) *(long long) primes->at(i) <= r; i++)
    {
        int current = primes->at(i);
        long long base = (l/current) * current;
        if(base < l)
        {
            base += current;
        }
        for(int j = base; j<=r; j += current)
        {
            isprime[j-l] = false;
        }
        if(base == current)
        {
            isprime[base-l] = true;
        }
    }
	if(l == 1)
		isprime[0] = false;
	if(l == 0)
	{
		isprime[0] = isprime[1] = false;
	}
    for(int i=0;i<=r-l;i++)
    {
        if(isprime[i])
        {
            cout << i + l << endl;
        }
    }
    cout << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int>*primes = sieve();
    int l,r;
    cout << "Enter the value for low";
    cin >> l;
    cout << "Enter the value for high";
    cin >> r;
    getprime(l,r,primes);
    
}