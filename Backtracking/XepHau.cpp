#include<stdio.h>
#define n 8
bool a[2* n], b[2*n -1], c[n];
int x[n];
int count = 1;
void printResult()
{
    for (int i = 1; i <= n; i++)
    {
        printf("(%d %d)", i, x[i]);
    }
}
void Try(int i)
{
    for (int k = 1; k <= n; k++)
    {
        if (a[i + k] && b[i -  k + (n - 1)] && c[k])
        {
            x[i] = k;
            if (i == n)
            {
                printf("\n%d: ", count);
                count++;
                printResult();
            }
            else
            {
                a[i + k] = b[i - k + (n - 1)] = c[k] = false;
                Try(i + 1);
                a[i + k] = b[i - k + (n - 1)] = c[k] = true;
            }
        }
    }
}
void init()
{
    for (int i = 2; i <= 2*n;i++)
    {
        a[i] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        c[i] = true;
    }
    for(int i = 1; i <= 2*n -1; i++)
    {
        b[i] = true;
    }

}
int main()
{
    init();
    Try(1);
}