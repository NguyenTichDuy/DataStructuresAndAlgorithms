#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<int> binhPhuong(int n)
{
    vector<int> vt;
    for(int i = 0; i < sqrt(n); i++)
         vt.push_back(i*i);
    return vt;
}
int sumOfSquare(int n)
{
    vector<int> vt = binhPhuong(n);
    int count = 0;
    for(int i = 0; i < vt.size(); i++)
    {
        int a = n - vt[i];
        for(int j = i + 1; j < vt.size() - 1; j++)
        {
            int b = a - vt[j];
            vector<int>::iterator it = find(vt.begin() + j, vt.end(), b);
            if (it != vt.end())
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    cout << sumOfSquare(531);
}
