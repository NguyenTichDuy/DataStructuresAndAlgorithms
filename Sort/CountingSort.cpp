#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Counting_Sort(vector<int> &stack)
{
    int maxElement = *max_element(stack.begin(), stack.end());
    int minElement = *min_element(stack.begin(), stack.end());

    int maxRange = maxElement - minElement + 1;

    vector<int> count(maxRange), outPut(stack.size());
    int i;
    for (i = 0; i < stack.size(); i++)
    {
        count[stack[i] - minElement]++;
    }
    for (i = 1; i < maxRange; i++)
    {
        count[i] += count[i-1];
    }
    for (i = outPut.size() - 1; i >= 0; i--)
    {
        outPut[count[stack[i] - minElement] - 1] = stack[i];
        --count[stack[i] - minElement];
    }
    for (i = 0; i < outPut.size(); i++)
    {
        stack[i] = outPut[i];
    }
    
    
}
void printArr(vector<int> stack)
{
    for (int i = 0; i < stack.size(); i++)
    {
        cout << stack[i] << " ";
    }
    
}
int main()
{
    vector<int> stack = {4, -5, 6, 7, 5, 3, -9};

    Counting_Sort(stack);
    printArr(stack);
}