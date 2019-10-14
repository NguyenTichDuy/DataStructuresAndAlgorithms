#include<bits/stdc++.h>  
#include<string.h>
using namespace std;
#define MaxCount 255

void Counting_Sort(char arr[])
{
    int length = strlen(arr);
    char outPut[length];

    int count[MaxCount + 1];
    memset(count, 0, sizeof(count));
    int i;
    for (i = 0; arr[i]; i++)
    {
        count[arr[i]]++;
    }
    for (i = 1; i <= MaxCount; i++)
    {
        count[i] += count[i - 1];
    }
    for ( i = 0; arr[i]; i++)
    {
        outPut[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for ( i = 0; arr[i]; i++)
    {
        arr[i] = outPut[i];
    }
}

int main()
{
    char arr[] = "fadfenwdnfda";
    
    Counting_Sort(arr);
    cout << arr;
}