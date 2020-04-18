#include <bits/stdc++.h>
using namespace std;
std::string formatString(std::string input)
{
    string::iterator it = unique(input.begin(), input.end(), [](char &a, char &b)
    {
        if (a == b && a == ' ')
            return true;
        else
            return false;
    });
    input.erase(it, input.end());
    input.pop_back();
    input.erase(input.begin());
    return input;
}
int main()
{
	string s = formatString(" aa     aad  d ");
	cout << s << endl;
}