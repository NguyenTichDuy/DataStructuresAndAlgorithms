#include<stdio.h>
#include<vector>
#include<list>
using namespace std;
FILE *f, *f1;

list<char> StartList;
list<char>::iterator iter;
vector<char> MyVector;

bool check = true;
int k = 1;

void Input()
{
    char c;
    f = fopen("StringIn.txt", "r");
    while(!feof(f))
    {
        fscanf(f, "%c", &c);
        StartList.push_back(c);
    }
    fclose(f);
}
void Output()
{
    if (check)
    {
        k = -1;
        printf("%d", k);
    }
    else
    {
        printf("%d", k);
    }
    
}
bool Check(char _char)
{
    char c;
    if (_char == '{' || _char == '(' 
    || _char == '[')
    {
        MyVector.push_back(_char);
        return true;
    }
    else
    {
        if (MyVector.empty())
        {
            return false;
        }
        else
        {
            c = MyVector.back();
            if ((_char == '{' && c == '}') || (_char == '[' && c == ']') 
            || (_char == '(' && c == ')'))
            {
                MyVector.pop_back();
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
void Execute()
{
    char c;
    iter = StartList.begin();
    int count = 1;
    while(iter != StartList.end() && count <= StartList.size())
    {
        if (!Check(*(iter)))
        {
            c = StartList.front();
            StartList.pop_front();
            StartList.push_back(c);
            k++;
            iter = StartList.begin();
            check = false;
        }
        count++;
    }
}
int main()
{
    Execute();
    Output();
}