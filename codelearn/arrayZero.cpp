#include<bits/stdc++.h>
using namespace std;
long long myStol(string s)
{
    long long result = 0;
    for(int i = 0; i < s.length(); ++i)
    {
        result = result*10 + (s[i] - '0');
    }
    return result;
}
int arrayZero(std::vector<std::string> s)
{
    vector<long long> vt;
    long long count = 0,a,b,c,d, sum = 1;
    for(auto i : s)
    {
        vt.push_back(stol(i));
    }
    while(sum)
    {
        a = abs(vt[0]-vt[1]);
        b = abs(vt[1]-vt[2]);
        c = abs(vt[2]-vt[3]);
        d = abs(vt[3]-vt[0]);
        vt[0] = a;vt[1] = b;vt[2] = c;vt[3] = d;
        count++;
        cout << a << " " << b << " " << c << " " << d << endl;
        sum = a + b + c + d;
    }
    return count;
}
int main()
{
	cout << arrayZero({"5712240087","5875777547","2387477982","8508269502"});
}