#include<stdio.h>
#include<string.h>

void Sieve(int n, bool array[])
{
    for (int i = 2; i < n; i++)
    {
        if (!array[i])
        {
            printf("%d ", i);
            for (int j = i*i; j < n; j+=i)
            {
                array[j] = true;
            }
        }
    }
    
}

int main()
{
    int n;
    
    printf("Enter n:");
    scanf("%d", &n);
    bool array[n];
    memset(array, false, sizeof(array));
    Sieve(n, array);
}