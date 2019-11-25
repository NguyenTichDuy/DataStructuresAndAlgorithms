#include <iostream>
using namespace std;
int mountain(int n)
{
    for (int i = n; i >=1; i--)
    {
        for(int j = n; j >= 1; j--)
        {
            for(int k = 1; k <= j; k++)
            {
                if (k == i)
                {
                    cout << "/";
                }
                else
                {
                    cout << " ";
                }
            }
            for (int h = j; h >= 1; h--)
            {
                if (h == i)
                {
                    cout << "\\";
                }
                else
                {
                    cout << ' ';
                }
            }
            
        }
        cout << endl;
    }
}
int main()
{
    mountain(8);
}