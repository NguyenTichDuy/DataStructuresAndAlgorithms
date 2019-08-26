#include<stdio.h>

#define MaxLength 50
typedef int ElementType;
ElementType x[MaxLength];
int n;

void Try(int i)
{
	for (int j = 0; j <= 1; j++)
	{
		x[i] = j;
		if (i == n - 1)	
		{
			for (int k = 0; k < n; k++)
			{
				printf("%d", x[k]);
			}
			printf("\n");
		}
		else
		{
			Try(i + 1);
		}
	}
}
int main()
{
	printf("Import n:");
	scanf("%d" ,&n);
	Try(0);
}
