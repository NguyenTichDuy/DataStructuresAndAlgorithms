#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> vt = { 1, 1 ,3,4,3, 4, 4, 3, 5, 9, 10, 12};
    vector<int>::iterator it;
    sort(vt.begin(), vt.end());
    it = unique(vt.begin(), vt.end());
    vt.resize(distance(vt.begin(), it));
    for(vector<int>::iterator i = vt.begin(); i!= vt.end(); ++i)
    {
        cout << *i << endl;
    }
}