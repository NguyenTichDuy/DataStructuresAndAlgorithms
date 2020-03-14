#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;

long max(long a, long b)
{
	return a > b ? a : b;
}
int main()
{
	ifstream input("inputAM");
	int n, m,x,y,z, k;
	input >> n;
	input >> m;
	input.ignore();
	k = m;
	vector<pair<int,int>> map_result;
	while (k--)
	{
		input >> x;
		input >> y;
		input >> z;
		map_result.push_back(make_pair(x, z));
		map_result.push_back(make_pair(y+1, -1 *z));
	}
	sort(map_result.begin(), map_result.end());

	long sum = 0, result = 0;
	for(int i = 0; i < m; ++i) {
		sum += map_result[i].second;
		result = max(result, sum);

	}
	cout << result << endl;
	input.close();
}