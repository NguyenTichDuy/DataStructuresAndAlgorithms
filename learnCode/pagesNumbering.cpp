#include <bits/stdc++.h>
using namespace std;
unsigned long long myPow(int n, int m)
{
    unsigned long long result = n;
    if (m == 0)
        return 1;
    for(int i = 0; i < m-1; i++)
        result *= n;
    return result;
}
int pagesNumbering(int n)
{   
    long long  count = 0, sum = 0, value = n; 
    while(value > 0)
    {   
        count++;
        value /= 10;
    }

    long long du = ((long long )n - (myPow(10, count-1)-1))*(count);
    cout << du << endl;
    for(int i = 1;i <= count -1; i++)
    {
        sum += (myPow(10, i) - myPow(10, i -1))*i;
    }
    return sum + du;
}

int main()	
{
	cout << pagesNumbering(1000) << endl;
	cout << myPow(10, 1) << endl;
}