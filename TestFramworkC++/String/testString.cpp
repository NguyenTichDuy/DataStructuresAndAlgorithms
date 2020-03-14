#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<int ,string > test;
	string s = "asdfasd";
	test[2] = s;
	cout << test[2] << endl;
}