#include <iostream>
using namespace std;
long long catalanNumber(long long n)
{
    if (n <= 1) return 1;
    long long res = 0;
    for(int i = 0; i < n; ++i)
        res += catalanNumber(i) * catalanNumber(n - i - 1);
    return res;
}
long long countRightBracket(long long n)
{
    if (n&1 || n == 0)
        return 0;
    else 
        return catalanNumber(n / 2);
}

int main()
{
	cout << countRightBracket(0) << endl;
}