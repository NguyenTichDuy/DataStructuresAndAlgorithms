#include <bits/stdc++.h>
using namespace std;
int sumMod(long long n, long long m)
{
    unsigned long long sum =0, mod = m % n, div = m /n, getMod = 0,i = n-1, j = mod;
    sum = ((i*(i+1)) / 2) % 1000000007;
    if(!mod)
    {   
        return (sum*div) % 1000000007;
    } 
    else
    {
        getMod = (mod *(mod + 1))/ 2;
        return (sum*div + getMod) % 1000000007;
    }
}
int main()
{
	cout << sumMod(12144323434, 43123153545);
	
}