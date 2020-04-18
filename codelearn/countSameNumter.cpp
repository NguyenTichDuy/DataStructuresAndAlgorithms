#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool findCheck(vector<int> a, int id)
{
	for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
    {
        if (*it == id)
        	return true;
    }
    return false;
}
int kthBiggestFrequency(std::vector<int> a, int k)
{
    map<int, int> m;
    vector<pair<int,int>> vt;
    vector<int> vt1,vt2;


    for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
    {
        m[*it]++;
        if (!findCheck(vt1, *it))
        {
        	vt1.push_back(*it);
        }
    }
    for(auto i : vt1)
    {
    	if (!findCheck(vt2, m[i]))
    	{
    		vt2.push_back(m[i]);
    		vt.push_back(make_pair(m[i], i));
    	} 
    }
    
    sort(vt.begin(), vt.end(), [](pair<int,int> &l, pair<int,int> &r){
        return l.first > r.first;
    });


    for(int i = vt.size() -1 ; i >= 0; i--)
    {
    	if (i+1 == k)
        {
            return vt[i].second;
        }
    }
     return -1;
}

int main()
{
	 vector<int> vt = {12,19,12,14,1,3,13,18,6,14,6,5,1,20,0,9,3,17,17,19,19,4,19,11,19,10,20,11,8,4,16,8,14,15,17,15,14,15,9,6,8,14,8,15,1,1,2,16,1,6};
	 int k = 5;
    cout << kthBiggestFrequency(vt, k) << endl;
}

