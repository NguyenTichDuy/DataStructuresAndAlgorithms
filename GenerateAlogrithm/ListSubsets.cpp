#include<stdio.h>
int n, k;
FILE *f;

void printResult(int arraySub[])
{
    printf("\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d", arraySub[i]);
    }
}
void List(int arraySub[])
{
    printResult(arraySub);
    for (int i = k - 1; i >= 0; i--)
    {
        if (arraySub[i] < n - k + i + 1)
        {
            arraySub[i]++;
            for (int j = i + 1; j <= k; j++)
            {
                arraySub[j] = arraySub[j - 1] + 1;
            }
            i = k;
            printResult(arraySub);
        }
    }
}
void init(int arraySub[])
{
    for (int j = 0; j < k; j++)
    {
        arraySub[j] = j + 1;
    }
}
int main()
{
    printf("Enter n:");
    scanf("%d", &n);
    int array[n];
    printf("\nEnter k:");
    scanf("%d", &k);
    int arraySub[k];
    init(arraySub);
    List(arraySub);
}