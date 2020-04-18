#include <iostream>
#include <vector>
using namespace std;

std::vector<std::string> bishopDiagonal(std::string bishop1, std::string bishop2)
{
    int n11 = bishop1[0] - 'a' + 1, n12 = bishop1[1] - '0';
    int n21 = bishop2[0] - 'a' + 1, n22 = bishop2[1] - '0';
    if (n11 + n12 == n21 + n22)
    {
        if (n12 > n22)
        {
            while(n12 < 8 && n11 > 1)
            {
                n12++;
                n11--;
            }
            while(n22 > 1 && n21 < 8)
            {
                n22--;
                n21++;
            }
        }
        else
        {
            while(n22 < 8 && n21 > 1)
            {
                n22++;
                n21--;
            }
            while(n11 < 8 && n12 > 1)
            {
                n11++;
                n12--;
            }
        }
    }
    else if (abs(n11 - n12) == abs(n21 - n22))
    {
        if (n12 > n22)
        {
            while(n11 < 8 && n12 < 8)
            {
                n11++;
                n12++;
            }
            while(n21 > 1 && n22 > 1)
            {
                n21--;
                n22--;
            }
        }
        else
        {
            while(n11 > 1 && n12 > 1)
            {
                n11--;
                n12--;
            }
            while(n21 < 8 && n22 < 8)
            {
                n21++;
                n22++;
            }
        }
    }
    string s,s1;
    vector<string> vt;
    s.push_back((char)(n11+'a'-1));
    s.push_back((char)(n12+'0'));
    vt.push_back(s);
    s1.push_back((char)(n21 + 'a' -1));
    s1.push_back((char)(n22 + '0'));
    vt.push_back(s1);
    return vt;
}
int main()
{
    for(string i : bishopDiagonal("d7", "f5"))
    {
        cout << i << endl;
    }
}