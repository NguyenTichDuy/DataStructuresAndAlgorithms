#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool checkSort(std::vector<int> a)
{
    vector<int>::iterator it = unique(a.begin(), a.end());
    a.erase(it, a.end());
    for(auto i : a)
    {
    	cout << i << endl;
    }
    
    return true;
}

int main()
{
	vector<int> a = {1,1,1,3,3,2,2,2,1,1};
	if (checkSort(a))
	{
		cout << "true" << endl;
	}
	else 
		cout << "false" << endl;
}