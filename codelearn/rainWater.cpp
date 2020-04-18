#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> rainWater(std::vector<int> a)
{
	int left,right;
	vector<int> vt;
	vt.push_back(a[0]);
	for(int i = 1; i < a.size() - 1; i++)
	{
		left = a[i];
		for(int j = 0; j < i; j++)
		{
			left = max(left, a[j]);
		}
		right = a[i];
		for(int j = i + 1; j < a.size(); j++)
		{
			right = max(right, a[j]);
		}
		vt.push_back(min(right, left));
	}
	vt.push_back(a[a.size() - 1]);
	return vt;
}
std::vector<int> rainWaterOn(std::vector<int> a)
{
	int n = a.size();
	int left[n],right[n];
	vector<int> vt;
	left[0] = a[0];
	for(int i = 1; i < n; ++i)
	{
		left[i] = max(left[i - 1], a[i]);
	}
	right[n-1] = a[n-1];
	for(int i = n-2; i >= 0; --i)
	{
		right[i] = max(right[i + 1], a[i]);
	}
	for(int i = 0; i < n; i++)
	{
		vt.push_back(min(right[i], left[i]));
	}
	return vt;
}
std::vector<int> rainWaterO1(std::vector<int> a)
{ 
	vector<int> vt;
	int n = a.size() - 1;
	int leftMax = 0, rightMax = 0;

	int l = 0, r = n - 1;

	while(l <= r)
	{
		if (a[l] < a[r])
		{
			if (a[l] > leftMax){
				leftMax = a[l];
				vt.push_back(leftMax);
			}
			else
				vt.push_back(leftMax);
			l++;
		}
		else
		{
			if (a[r] > rightMax){
				rightMax = a[r];
				vt.push_back(rightMax);
			}
			else
				vt.push_back(rightMax);

			r--;
		}
	}
    return vt; 
} 
int main()
{
	vector<int> a = {10,5,14,8,10,13};
	for(int b : rainWaterO1(a))
	{
		cout << b << endl;
	}
}
