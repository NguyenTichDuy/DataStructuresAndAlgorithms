#include <bits/stdc++.h>
using namespace std;
struct mountain
{
	int count, begin, end;
};

std::vector<int> maxLengMountain(std::vector<int> a)
{
	vector<mountain> Mountain;
    vector<int> v;
    int i = 0, max = 0,n;
    int count1 = 0, count2 = 0;

    for(int i = 0; i < a.size()-1; i++)
    {
    	n = i,count1 = 0, count2 = 0;

    	while(a[n] < a[n+1] && n < a.size()-1)
       	{
       		count1++;
        	++n;
        }
        if (count1)
    	while(a[n] > a[n+1] && n < a.size()-1)
       	{
       		count2++;
        	++n;
        }
        if (count1 && count2)
        {
        	Mountain.push_back({count1 + count2, i, n});
        }
    }
    sort(Mountain.begin(), Mountain.end(), [](mountain &a, mountain &b)
    	{
    		return (a.count > b.count) ? true : false;
    			 
    	});
    for(int i = Mountain[0].begin; i <= Mountain[0].end;i++)
    {
    	v.push_back(a[i]);
    }

    return v;
}
int main()
{
	vector<int> a = {1,3,2,4,0}, b;

	b = maxLengMountain(a);
	for(int i = 0; i < b.size(); i++)
	{
		cout << b[i] << " ";
	}
}