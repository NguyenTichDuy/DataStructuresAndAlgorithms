#include <bits/stdc++.h>
using namespace std;

vector<int> uoc(int n)
{
	vector<int> vt;
	for(int i = 9; i > 1; i--)
	{
		while(n % i == 0)
		{
			vt.push_back(i);
			n /= i;
		}
	}
	return vt;
}
int digitsProduct(int product)
{
	if (product == 0)
		return 10;
    else if (product < 10)
        return product;

	vector<int> vt = uoc(product);
	if (vt.empty())
		return -1;
    int result = 0;
	for(int i = vt.size() - 1; i >= 0; i--)
    {
        result = result * 10 + vt[i];
 	}
 	return result;
 }

int main()
{
	cout << digitsProduct(450) << endl;
	for(int i : uoc(12))
	{
		cout << i << endl;
	}
}