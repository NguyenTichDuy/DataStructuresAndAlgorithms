#include <bits/stdc++.h>
using namespace std;
int helpMe(int n, int m)
{
    int count = 0;
    while(n != m)
    {
        if (n>m)
        {
            --n;
        }
        else if (n < m)
        {
            if (n <= ceil((double)m / 2))
            n *=2;
            else
            --n;

        }
        count++;
    }
    return count;
}
int main()
{
	cout << ceil((double)10 / 2);
}
