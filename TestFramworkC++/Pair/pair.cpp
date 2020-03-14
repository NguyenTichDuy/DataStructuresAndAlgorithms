#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	pair<int, int> foo,bar, nam, mo;
	foo = make_pair(5, 90);
	bar = make_pair(9, 2);
	nam = { 3, 100};
	mo = {1, 4};
	vector<pair<int,int>> vt;
	vt.push_back(foo);
	vt.push_back(bar);
	vt.push_back(nam);
	vt.push_back(mo);
	sort(vt.begin(), vt.end());
	for(vector<pair<int,int>>::iterator it = vt.begin(); it != vt.end(); it++)
	{
		//cout << it->first << endl;
		cout << it->second << endl;
	}
}