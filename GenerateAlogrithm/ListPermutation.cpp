#include<stdio.h>
#include<string>
int n;
void PrintResult(int array[])
{
    printf("\n");
    for (int i = 0 ;i < n; i++)
    {
        printf("%d", array[i]);
    }
}
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = a;
}
void List(int array[])
{
    PrintResult(array);
    for (int i = n - 2; i > 0; i--)
    {
        if (array[i] < array[i + 1])
        {
            int min = array[n - 1];
            int index = 0;
            for (int j = n - 2; j >= i + 1; j++)
            {
                if (min < array[j] && array[i] < array[j])
                {
                    min = array[j];
                    index = j;
                }
            }
            Swap(array[i], array[index]);
            int k = n - 1;
            for(int j = i + 1; i < n / 2; i++)
            {
                Swap(array[j], array[k]);
                k--;
            }
            PrintResult(array);
        }
    }
}
void Init(int array[])
{
    for (int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }
}
int main()
{
    printf("Enter n:");
    scanf("%d", &n);
    int array[n];
    Init(array);
    List(array);
}