#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

std::vector<int> makeArrayConsecutive(std::vector<int> sequence)
{
    sort(sequence.begin(), sequence.end());
    vector<int> v;
    for(int i = 0; i < sequence.size() - 1; i++)
    {
        if (sequence[i+1] - sequence[i] > 1)
        {
            for(int j = sequence[i] + 1 ; j < sequence[i + 1]; j++)
            {
                v.push_back(j);
                cout << j << endl;
            }
        }
    }
    return v;
}
int main()
{
    for(int i : makeArrayConsecutive({6, 2, 3, 8}))
    {
        cout << i << " ";
    }
}