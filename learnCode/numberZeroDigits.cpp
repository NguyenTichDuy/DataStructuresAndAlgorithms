#include <bits/stdc++.h>
using namespace std;
long long numberZeroDigits(long long n)
{
    long long a = n, sum = 0;
    while (a != 0)
    {
    	sum += floor(a/5);
    	//cout << sum << endl;
    	a /= 5;
    	cout << a << endl;
    }
    return sum;
}

int main()
{
	cout << numberZeroDigits(100) << endl;
	cout << floor(4 / 5) << endl;
}