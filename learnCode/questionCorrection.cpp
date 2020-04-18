#include <bits/stdc++.h>
using namespace std;
std::string questionCorrection(std::string s)
{
    string::iterator it = unique(s.begin(), s.end(), [](char &a, char &b)
    {
        return a == b && (a == ',' || a == ' ');
    });
    s.erase(it, s.end());

    for(int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
            continue;
        else if (s[i] >= 'a' && s[i] <= 'z')
            continue;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            continue;
        else if (s[i] == ',')
        {
            if (s[i + 1] != ' ')
            {
                s.insert(i, " ");
            }
            if (s[i - 1] == ' ')
            {
                s.erase(s.begin() + i - 1);
            }
        }
        else 
            s[i] = ' ';
    }
    string::iterator it1 = unique(s.begin(), s.end(), [](char &a, char &b)
    {
        return a == b && a == ' ';
    });
    s.erase(it1, s.end());
    int i = 0;
    while(s[i++] == ' ')
    {
        s.erase(s.begin());
    }
    while(*(s.end() - 1) == ' ')
    {
        s.pop_back();
    }
    *s.begin() = toupper(*s.begin());
    s.push_back('?');
    return s;
}

int main(){
    string s = "  s.??^&";
    cout << questionCorrection(s) << endl;

}