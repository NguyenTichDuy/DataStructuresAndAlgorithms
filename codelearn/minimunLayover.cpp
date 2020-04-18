#include <bits/stdc++.h>
using namespace std;
vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

vector<pair<int, int>> timeFly(vector<string> a)
{
	int x, y;
	string num;
	vector<pair<int,int>> vt;
	vector<int> v;
    for(vector<string>::iterator it = a.begin(); it != a.end(); ++it)
    {
        for(int i = 0; i < (*it).size(); i++)
        {
        	if ((*it)[i] <= '9' && (*it)[i] >= '0')
        	{
        		num.push_back((*it)[i]);
        	}
        	else if((*it)[i] == 'P')
        	{
        		v.push_back(stoi(num) + 12);
        		num.clear();
        	}
        	else if ((*it)[i] == 'A')
        	{
        		v.push_back(stoi(num));
        		num.clear();
        	}
        }
        vt.push_back(make_pair(v[0],v[1]));
        v.clear();
    }
    return vt;
}
int minimumLayover(std::vector<std::string> a, std::vector<std::string> b)
{
    
}
int main()
{
	vector<string> a = {"1 AM - 3 AM", "4 AM - 6 AM", "11 AM - 1 PM", "2 PM - 4 PM", "8 PM - 10 PM", "8 PM - 11 PM"}, 
	b  = {"3 AM - 4 AM", "8 AM - 10 AM", "9 AM - 11 AM", "7 AM - 10 AM", "7 PM - 9 PM", "8 PM - 11 PM"};
	// vector<pair<int,int>> vt = timeFly(a);
	// for(pair<int,int> num : vt)
	// {
	// 	cout << num.first << " " << num.second << endl;
	// }

	for(auto x : timeFly(a))
	{
		cout << x.first << " " << x.second << "   ";
	}
	cout << endl;
	for(auto x : timeFly(b))
	{
		cout << x.first << " " << x.second << "   ";
	}
}