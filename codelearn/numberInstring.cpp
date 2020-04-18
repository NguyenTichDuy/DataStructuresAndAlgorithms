#include <bits/stdc++.h>
using namespace std;

int giaiThua(int n)
{
	if (n == 1 || n == 0)
		return 1;
	return n + giaiThua(n-1);
}

int numbersInString(std::string str)
{
    vector<string> st;
    vector<int> vt,result;
    string ch;
    int n;
    for(int i = 0; i <= str.length(); i++)
    {
        if (str[i] <= '9' && str[i] >= '0')
        {

        	ch.push_back(str[i]);
        }
        else
        {
        	if (!ch.empty())
        	{
        		st.push_back(ch);
        		ch.clear();
        	}
        	
        }
    }
    int max = 0,num;
    for (auto i : st)
    {
    	num = giaiThua(i.size());
    	cout << num << endl;
    	max += num;
    	 
    }

    return max;
}
int main()
{
	string str = "4h57ctsi941gn72b2zm86huavcepim";
	cout << numbersInString(str);
}