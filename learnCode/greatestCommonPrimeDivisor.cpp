#include <bits/stdc++.h>
using namespace std;
vector<int> eratosthenes(int n)
{
    bool prime[n + 1];
    vector<int> vt;
    memset(prime, true, sizeof(prime));

    for(int p = 2; p*p < n; p++)
    {
        if (prime[p] == true)
        {
            for(int i = p *p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
    for(int i = 2; i <= n; i++)
    {
        if (prime[i])
            vt.push_back(i);
    }
    return vt;
}
// int min(int a, int b)
// {
//     return a > b ? b : a;
// }
int greatestCommonPrimeDivisor(int a, int b)
{   
    int m = min(a, b);
    vector<int> vt = eratosthenes(m);
    for(int i : vt)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
}
int main()
{
	cout greatestCommonPrimeDivisor(12, 18);
}