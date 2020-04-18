#include <iostream>
#include <math.h>
using namespace std;
bool check(int n)
{
    if(n <= 1)
        return false;
    for(int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int factorSum(int n)
{
    int sum = 0; 
    for(int i = 2 ; n > 1;)
    {

        if (n % i == 0){
            sum += i;
            n = n / i;
            cout << n << " " << sum << endl;
        }
        else
        {
            i++;
        }
        if (n == 1)
        {
            if (check(sum))
                return sum;
            else
            {
                n = sum;
                sum = 0;
                i = 2;
            }
        }
    }
}
int main()
{
    cout << factorSum(24) << endl;
    //cout << 1 / 3 << endl;
}