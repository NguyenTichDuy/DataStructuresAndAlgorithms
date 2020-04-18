#include <vector>
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
long long dynamicCatalan(long long n)
{
	unsigned long long catalan[n + 1];
	catalan[0] = catalan[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		catalan[i] = 0;
		for(int j = 0; j < i; j++)
		{
			catalan[i] += catalan[j] * catalan[i - j - 1];
		}
	}
	return catalan[n];// % 1000000009;
}
unsigned long int binomialCoeff(unsigned int n, unsigned int k) 
{ 
    unsigned long int res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
  
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
    for (int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 
  
// A Binomial coefficient based function to find nth catalan 
// number in O(n) time 
unsigned long int catalan(unsigned int n) 
{ 
    // Calculate value of 2nCn 
    unsigned long int c = binomialCoeff(2*n, n); 
  
    // return 2nCn/(n+1) 
    return c/(n+1); 
} 
int main()
{
	//for(int i = 0; i < 40; i++)
		cout << dynamicCatalan(1000)<< " ";
	cout << endl;
}