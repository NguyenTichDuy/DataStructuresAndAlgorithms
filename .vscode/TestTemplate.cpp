#include<iostream>
using namespace std;

float &funt()
{   
    int a;
    cout << a << " " << &a << endl;
    a=10;
    return a;
}
void funt2()
{   
    int a;
    cout << a << " " << &a << endl;
    a=10;
}
int main()
{
    // int b = funt();
    // b=15;
    // funt();
    cout << funt << endl;
}