#include<iostream>
#include<vector>
using namespace std;
int longestSequence(std::vector<int> a)
{
    int count = 2, max = 0;;
    for(int i = 0; i < a.size() - 2; i++)
    {
        for(int j = i + 1; j < a.size() - 1; j++)
        {
            int temp = a[j];
            int sub = a[j] - a[i];
            for(int t = j + 1; t < a.size(); t++)
            {
                if (sub == a[t] - temp)
                {
                    count++;
                    temp = a[t];
                }

            }
            if (max < count)
                max = count;
            count = 2;
        }

    }
    return max;
}
int main()
{
    cout << longestSequence({4, 1, 2, 4, 3, 5, 4, 6});
}
