#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> splittString(string s)
{
	vector<int> result;
	for(string::iterator it = s.begin(); it != s.end(); it++)
	{
		if(*it != ' ')
		{
			result.push_back(*it - '0');
		}
	}
	return result;
}
int main()
{
	string s = "2 3 5   1 2 2 4 5 6 6";

	vector<int> vt = splittString(s);
	for(unsigned i = 0; i < vt.size(); ++i) {
		cout << vt[i] << endl;
	}
}