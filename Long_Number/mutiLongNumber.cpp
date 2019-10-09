#include<iostream>
#include<string.h>
#include<string>
using namespace std;

void multi(string str1, string str2)
{
    int maxLength = str1.size() + str2.size();
    int result[maxLength + 1], num1[str1.size()], num2[str2.size()];

    memset(result, 0, sizeof(result));

    for (int i = 0; i < str1.size(); i++)
    {
        num1[i] = str1[str1.size() - i - 1] - '0';
    }
    for (int i = 0; i < str2.size(); i++)
    {
        num2[i] = str2[str2.size() - i - 1] - '0';
    }

    for (int i = 0; i < str1.size(); i++)
    {
        for (int j = 0; j < str2.size(); j++)
        {
            result[i + j] += num1[i] * num2[j];
        }
    }
    int temp = 0;
    for (int i = 0; i < maxLength + 1; i++)
    {
        result[i] = result[i]  + temp;
        temp = result[i] / 10;
        result[i] %= 10;
    }
    for (int i = 0; i < maxLength + 1; i++)
    {
        cout << result[maxLength - i];
    }

}
int main()
{
    string a, b;
    a = "5424252";
    b = "4354";
    multi(a, b);
}