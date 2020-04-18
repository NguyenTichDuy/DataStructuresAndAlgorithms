#include <iostream>
#include <vector>
using namespace std;

std::vector<std::vector<int>> spiralNumbers(int n)
{
    vector<vector<int>> vt(n, vector<int> (n, 0));
    int col = 0, row = n - 1, count = 0;
    while(col <= row)
    {
        for(int i = col; i < row; i++)
            vt[col][i] = ++count;
        for(int i = col; i < row; i++)
            vt[i][row] = ++count;
        for(int i = row; i > col; i--)
            vt[row][i] = ++count;
        for(int i = row; i > col; i--)
            vt[i][col] = ++count;
        col++;
        row--;
    }
    if (n&1)
        vt[n/2][n/2] = ++count;
    return vt;
}
int main()
{
    int n = 3;
    vector<vector<int>> vt = spiralNumbers(n);
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << vt[i][j] << " ";
        }
        cout << endl;
    }
}