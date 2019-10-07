#include<stdio.h>

int modExpr(int x, int y, int m)
{
    if (y == 0)
    {
        return 1;
    }
    else if (y % 2 == 0)
    {
        return modExpr(x *x, y / 2, m) % m;
    }
    else
    {
        return (x % m) * modExpr(x * x, (y -1) / 2, m) %m;
    }
    
}
int modeExprLoop(int x, int y, int m)
{
    if (y == 0 && m > 1)
    {
        return 1;
    }
    x = x % m;
    long long res = 1;
    while (y > 0)
    {
        if (y % 2)
        {
            res = (res * x) %m;
        }
        x = (x * x) % m;
        y = y / 2;
    }
    return res;  
}
int main()
{
    printf("%d %d", modExpr(7, 7, 5), modeExprLoop(7, 7, 5));
}