#include<stdio.h>

#define MaxLength 50
typedef int ElementType;
ElementType x[MaxLength];
int n;
int max;
int count;
int countPt = 0;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int Factorial(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n*(Factorial(n - 1));
}
void Permutation(int i)
{
	for (int k = n - 1 ; k >= 0;k--)
	{
		if (i == n - 1)							
		{
			if (count == Factorial(n))
			{
				return;
			}
			else
			{
				printf("%d: ", countPt);
				for(int j = 0; j < n; j++)
				{
					printf("%d",  x[j]);
				}
				printf("\n");
				swap(x[i], x[k]);
				count++;
				countPt++;
			}		
			
		}
		else
		{
			Permutation(i + 1);
		}	
	}

}
int main()
{
	printf("Import n:");
	scanf("%d", &n);
	max = n;
	count = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	Permutation(0);
}
