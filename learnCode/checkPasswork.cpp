#include <iostream>
#include <string>
#include <string.h>
using namespace std;
bool checkStrongPassword(std::string password)
{
	string s = "!@#$%^&*()-+";
	bool check[4];
	memset(check, false, sizeof(check));
	if (password.length() < 6)
        return false;
    for(string::iterator it = password.begin(); it != password.end(); ++it)
    {
        int a = *it;
        size_t found = s.find(*it);
        if (found != string::npos)
        	check[0] = true;
        if ((a >= '0' && a <= '9'))
        	check[1] = true;
        if (a >= 'a' && a <= 'z')
        	check[2] = true;
        if (a >= 'A' && a <= 'Z')
        	check[3] = true;
    }
	for(bool i : check)
	{
		if (!check)
			return false;
	}
	return true;
}

int main()
{
	string s = "asdfasdfwei23411!!";
	string s1 = "!@#$%^&*()-+";
	cout << s1 << endl;
	if (checkStrongPassword(s))
	{
		cout << "log in";
	}
	else
		cout << "log out";
}