#include <iostream>
#include <vector>
using namespace std;

int countTriangles(std::vector<int> x, std::vector<int> y)
{
    int count = 0, size = x.size();
    for(int i = 0; i < size - 2; i++)
    {
        for(int j = i + 1; j < size - 1; j++)
        {
            
            int value = (x[j] - x[i]) * (y[j + 1] - y[i]) - (x[j + 1] - x[i]) * (y[j] - y[i]);
            //cout << value << endl;
            if (value != 0)
                count++;
            
        }
    }
    return count;
}
int main()
{
    vector<int> x = {0, 0, 1, 1}, y = {0, 1, 1, 0};
    cout << countTriangles(x, y);
}