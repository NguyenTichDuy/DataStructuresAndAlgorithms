#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int d = 4;
	vector<int> arr = { 1, 3, 4, 5, 2, 4};
	vector<int>::iterator it = arr.begin();
	for(int i =0; i < d; i++)
	{
		arr.push_back(arr[i]);
	}
	arr.erase(arr.begin(), arr.begin()+d);
	for(int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
}