#include<iostream>
#include<string.h>
using namespace std;

void Swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}
void SumLong(string a, string b)
{
    if (a.size() > b.size())
    {
        Swap(a, b);
    } 
    int maxLength = b.size();
    int numSmall = a.size();
    int num1[a.size()], num2[b.size()], sum[maxLength + 1];
    memset(sum, 0, sizeof(sum));

    for (int  i = 0; i < a.size(); i++) num1[i] = a[a.size() - i - 1] - '0';
    for (int i = 0; i < b.size(); i++)  num2[i] = b[b.size() - i - 1] - '0';

    int carry = 0;

    for (int i = 0; i < numSmall; i++)
    {
        sum[i] = (num1[i] + num2[i]) + carry;
        carry = sum[i] / 10;
        sum[i] %= 10;
    }
    for (int i = numSmall; i < maxLength; i++)
    {
        sum[i] = num2[i] + carry;
        carry = sum[i] / 10;
        sum[i] %= 10;
    }
    
    if (sum[maxLength] == 1)
    {
        cout << "1";
    }
    for (int i = 0; i < maxLength; i++)
    {
        cout << sum[maxLength - i - 1];
    }
}

int main()
{
    string a, b;
    a = "342342345635";
    b = "4245322345234524";
    SumLong(a ,b);
    cout << endl;
}