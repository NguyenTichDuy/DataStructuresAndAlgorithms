#include<iostream>
#include<vector>
using namespace std;
bool isTournament(int n, std::vector<int> fromV, std::vector<int> toV)
{
    if (n < 2) 
        return false;
    if (fromV.size() < n - 1)
        return false;
    vector<vector<int>> v(n + 1, vector<int> (n+ 1, 0));
    for(int i = 0; i < fromV.size(); i++)
    {
        if (v[fromV[i]][toV[i]] == 1 || v[toV[i]][fromV[i]] == 1)
            return false;
        v[fromV[i]][toV[i]] = 1;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if (v[i][j] != 1 && v[j][i] != 1)
                return false;
        }
    }
    return true;
}
int main()
{
    cout << isTournament(2, {2}, {1}) ? "true" : "false";
}