#include <iostream>
#include <vector>
using namespace std;
bool findPath(std::vector<std::vector<int>> matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int row[] = {1, 0, -1, 0};
    int col[] = {0, 1, 0, -1};
    int x = 0, y = 0;
    for(int i =0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                x = i;
                y = j;
            }
        }
    }
    
    int count = 2;
    bool check = false;
    while(count <= n*m)
    {
        for(int i = 0; i < 4; i++)
        {
            int a = x+col[i], b = y + row[i];
            if ( a >= 0 && b >= 0 && a < n && b < m && matrix[a][b] == count)
            {
                x = x + col[i];
                y = y + row[i];
                i = 4;
                count++;
                check = true;
            }
        }
        if (check)
            check = false;
        else
            return false;
    }

    return true;
}
int main()
{
	vector<vector<int>> vt = {{2,3,4,5},{1,8,7,6}, {12,9,10,11}};
	if (findPath(vt))
		cout << 1;
	else
		cout << 0;
}