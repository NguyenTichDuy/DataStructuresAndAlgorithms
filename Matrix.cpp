#include<stdio.h>

#define Length 50

int Matrix[Length][Length];
int h[Length][Length];

void Integrated_Matrix(int length, int _matrix[])
{
	int q, j;
	for (int d = 1; d <= length; d++)
	{
		for (int i = 1; i <= length - d; i++)
		{
			j = i + d;
			Matrix[i][j] = 65535;
			for (int k = i; k <= j; k++)
			{
				q = Matrix[i][k] + Matrix[k+1][j] + _matrix[i - 1] * _matrix[k] * _matrix[j];
				if (q < Matrix[i][j])
				{
					Matrix[i][j] = q;
					h[i][j] = k;
				}
			}
		}
	}
}
int main()
{
	int matrix[] = {20, 2, 30, 12, 8};
	int length = sizeof(matrix) / sizeof(int) - 1;
	
	Integrated_Matrix(length, matrix);
	
	for (int i = 1; i <= length; i++)
	{
		for (int j = 1 ; j <= length; j++)
		{
			printf("\t%d", Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 1; i <= length; i++)
	{
		for (int j = 1 ; j <= length; j++)
		{
			printf("\t%d", h[i][j]);
		}
		printf("\n");
	}
	
}

