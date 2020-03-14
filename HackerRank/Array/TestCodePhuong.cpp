#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("input");
    int nLine;
    string line;
    map<string,int> Str_Line;
    fin>>nLine;
    fin.ignore();
    while(nLine--)
    {
        getline(fin,line);
        Str_Line[line]++;
        line.clear();
    }
    int nQue;
    fin>>nQue;fin.ignore();
    while(nQue--)
    {
        getline(fin,line);
        cout<<Str_Line[line] << endl;
        line.clear();
    }
    fin.close();
}