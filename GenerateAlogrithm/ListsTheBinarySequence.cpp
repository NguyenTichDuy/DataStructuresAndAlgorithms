#include<stdio.h>
int n, count = 1;
void initArray(int array[])
{
    for(int i = 0; i < n; i++)
    {
        array[i] = 0;
    }
}
void printResult(int array[])
{
    printf("\n%d :", count);
    count++;
    for(int i = 0; i < n; i++)
    {
        printf("%d", array[i]);
    }
}
void Generate(int array[])
{
    printResult(array);
    int i = n - 1;
    while ( i >= 0)
    {
        if (array[i] == 0)
        {
            array[i] = 1;
            for(int j = i + 1; j < n; j++)
            {
                array[j] = 0;
            }
            printResult(array);
            i = n - 1;
        }
        else
        {
            i--;
        }
    }
}

int main()
{

    printf("Enter n:");
    scanf("%d", &n);
    int array[n];
    initArray(array);
    Generate(array);
}