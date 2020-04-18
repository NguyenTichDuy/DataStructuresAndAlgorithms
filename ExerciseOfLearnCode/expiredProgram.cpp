#include <bits/stdc++.h>
using namespace std;
int expiredProgram(std::string time1, std::string time2)
{
    vector<int> t1,t2;
    int num = 0;
    for(string::iterator it = time1.begin(); it != time1.end(); ++it)
    {
        if (*it != '-' && *it != '/')
        {
            num =  (*it - '0') + num*10;
        }
        else
        {
            t1.push_back(num);
            num = 0;
        }
        if (it == time1.end() - 1)
        {
        	t1.push_back(num);
        	num = 0;
        }
    }
    for(int i : t1)
    {
    	cout << i << endl;
    }
    for(string::iterator it = time2.begin(); it != time2.end(); ++it)
    {
        if (*it != '-' && *it != '/')
        {
            num =  (*it - '0') + num*10;
        }
        else
        {
            t2.push_back(num);
            num = 0;
        }
        if (it == time2.end() - 1)
        {
        	t2.push_back(num);
        	num = 0;
        }
    }
    for(int i : t2)
    {
    	cout << i << endl;
    }
    if (t1[3] != t2[3])
        return 100000*abs(t1[3] - t2[3]);
    if (t1[2] != t2[2])
        return 10000*abs(t1[2] - t2[2]);
    if (t1[1] != t2[1])
        return 1000*abs(t1[1] - t2[1]);
    if (t1[0] != t2[0])
        return 50*abs(t1[0] - t2[0]);
}


int main()
{
	cout << expiredProgram("23-22/04/2019", "05-15/12/2020");
}