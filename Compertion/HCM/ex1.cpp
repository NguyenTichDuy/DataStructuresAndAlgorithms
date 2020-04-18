#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
vector<int> sie(int n)
{
    bool re[n + 1];
    vector<int> res;
    memset(re, true, n+1);
    for(int i = 2; i < n; i ++)
    {
        for(int j = i * i; j <= n; j+= i)
        {
            if (re)
                re[j] = false;
        }
    }
    for(int i = 2; i <= n; i++)
    {
        if (re[i])
            res.push_back(i);
    }
    return res;
}
std::vector<int> sumOfTwoPrime(int n)
{
    vector<int> v = sie(n),res;
    if (n == *v.end())
        return res;
    for(int i = 0; i < v.size(); i++)
    {
        int value = n - v[i];
        vector<int>::iterator p = find(v.begin(), v.end(), value);
            if (p != v.end())
            {
                res.push_back(value);
                res.push_back(*p);
                return res;
            }  
    }
    return res;
}
int main()
{
    for(int i : sumOfTwoPrime(4))
    {
        cout << i << " ";
    }
}