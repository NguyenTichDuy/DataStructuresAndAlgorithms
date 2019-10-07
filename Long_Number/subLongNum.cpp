#include<iostream>
#include<string.h>
using namespace std;

void Sub(string strA, string strB)
{
    int maxLength = (strA.size() > strB.size()) ? strA.size() : strB.size();

    int numA[strA.size()], numB[strB.size()], sub[maxLength];

    memset(sub, 0, sizeof(sub));

    for (int i = 0; i < strA.size(); i++)
    {
        numA[i] = strA[strA.size() - i - 1] - '0';
    }
    for (int i = 0; i < strB.size(); i++)
    {
        numB[i] = strB[strB.size() - i - 1] - '0';
    }

    for (int i = 0; i < maxLength; i++)
    {
        if (numA[i] < numB[i])
        {
            numA[i] += 10;
            numA[i+ 1]--;
        }
        sub[i] = numA[i] - numB[i];
    } 
    for (int i = 0; i < maxLength; i++)
    {
        cout << sub[maxLength - i - 1];
    }
}
int main()
{
    string a, b;
    cout << "Enter num a:" << endl;
    cin >> a;
    cout << "Enter num b:" << endl;
    cin >> b;
    cout << "Result : ";
    Sub(a, b);
}
