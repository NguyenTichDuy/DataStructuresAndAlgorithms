#include<stdio.h>

#define Length 50

int fc[Length];

int L[Length][Length];
int fa[Length],fb[Length];
FILE *f;
int lengthFa, lengthFb;


int Max(int _x1, int _x2)
{
	if (_x1 > _x2)
	{
		return _x1;
	}
	else
	{
		return _x2;
	}
}
void Handling()
{
	
	for (int i = 0 ; i <= lengthFa; i++)
	{
		for (int j = 0; j <= lengthFb; j++)
		{
			if (i == 0 || j == 0)
			{
				L[i][j] = 0;
			}
			else if (i > 0 && j > 0)
			{
				if (fa[i] != fb[j])
				{
					L[i][j] = Max(L[i][j - 1], L[i- 1][j]);
				}
				else if (fa[i] == fb[j])
				{
					L[i][j] = 1 + L[i - 1][j - 1];
				}
			}
		}
	}
	printf("Number of number in the sequence: %d", L[7][6]);
}
void PrintArray2()
{
	printf("\n\t");
	for (int i = 0; i <= lengthFb; i++)
	{
		printf("%d\t", fb[i]);
	}
	printf("\n\n");
	for (int i = 0; i <= lengthFa; i++)
	{
		printf("%d", fa[i]);
		for (int j = 0; j <= lengthFb; j++)
		{
			printf("\t%d", L[i][j]);
		}
		printf("\n");
	}
}
void ImportArray()
{
	f = fopen("InPut.txt", "r+");
	fscanf(f, "%d", &lengthFa);
	fscanf(f, "%d", &lengthFb);
	for(int i = 1; i <= lengthFa; i++)
	{
		fscanf(f, "%d", &fa[i]);
	}
	for (int j = 1; j <= lengthFb; j++)
	{
		fscanf(f, "%d", &fb[j]);			
	}
	fclose(f);
}

void PrintArray(int i, int j)
{
	if (L[i][j] == 0)
	{
	}
	else if (fa[i] == fb[j])
	{
		fc[L[i][j]] = fa[i];
		PrintArray(--i, --j);
	}
	else if (fa[i] != fb[j])
	{
		if (L[i][j - 1] > 0)
		{
			PrintArray(i,--j);
		}
		else if (L[i - 1][j] > 0)
		{
			PrintArray(--i,j);
		}
	}
}
int main()
{
	int L[Length][Length];
	
	ImportArray();
	Handling();
	PrintArray2();
	printf("\nPrint Array: ");
	PrintArray(lengthFa, lengthFb);

	for (int i = 1; i <= 4; i++)
	{
		printf("%d ", fc[i]);
	}
}
