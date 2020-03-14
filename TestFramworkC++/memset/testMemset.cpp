#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int arr[] = {4, 5, 2,12,78, 22};
	memset(arr+1, 1, 3*sizeof(arr[0]));
	for(unsigned i = 0; i < 6; ++i) {
		cout << arr[i] << endl;
	}
}