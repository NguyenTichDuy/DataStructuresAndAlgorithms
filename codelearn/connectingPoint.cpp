#include <iostream>
using namespace std;

int catalanNumber(int n)
{
	if (n <= 1)
		return 1;
	long long res = 0;
	for(int i = 0; i < n; ++i)
	{
		res += catalanNumber(i)*catalanNumber(n - i - 1);
	}
	return res;
}

int connectingPoints(int n)
{
	
}
