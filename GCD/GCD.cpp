#include<iostream>
using namespace std;

int GCD_division(int a, int b)
{
    int t;
    while(b != 0)
    {
        t = b;
        b = a % b;
        a  = t;
    }
    return a;
}
int GCD_Sub(int a, int b)
{
    while(a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
        
    }
    return a;
}
int main()
{
    cout << GCD_division(105, 252) << endl;
    cout << GCD_Sub(105, 252) << endl;
}