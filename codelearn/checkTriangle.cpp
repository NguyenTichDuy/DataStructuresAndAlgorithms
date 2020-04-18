#include <bits/stdc++.h>
using namespace std;

long long lamTronXuong(long double a)
{
	return (long long)((a - (long long)a) > 0 ? a : a -1);
}
std::vector<int> trianglesPointed(int a, int b)
{
	long long a2 = pow(a,2), b2 = pow(b,2);
	long long max = lamTronXuong(sqrt(a2 + b2));
	long double min;

	if (a < b)
	{
		min = (long long)(sqrt(b2 - a2)) + 1;
	}
	else
	{
		min = (long long)(sqrt(a2 - b2)) + 1;
	}
	vector<int> vt;
	vt.push_back(min);
	vt.push_back(max);
	return vt;
}
int main()
{
	vector<int> v = trianglesPointed(345234534,2435345438);
	for(auto i : v)
	{
		cout << i << endl;
	}
}		