#include<stdio.h>
#define MaxLength 50
typedef int ElementType;
ElementType node[MaxLength][MaxLength];

FILE *FInput, *FOutput;
int MaxNode;
int num[MaxLength];
void ImportData();
void PrintData();

void ImportData()
{
	FInput = fopen("Input.txt", "r");
	fscanf(FInput, "%d", &MaxNode);
	int k = 0;
	while(!feof(FInput))
	{
		int i;
		int j;
		fscanf(FInput, "%d", &i);
		fscanf(FInput, "%d", &j);
		fscanf(FInput, "%d", &node[i][j]);
		num[k] = node[i][j];
	}
	fclose(FInput);
}
void PrintData()
{
	for (int i = 1; i <= MaxNode; i++)
	{
		for (int j = 1; j <= MaxNode; j++)
		{
			printf("%3d", node[i][j]);
		}
		printf("\n");
	}
}
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SelectionSort()
{
	for(int i = 1; i <= MaxNode; i++)
	{
		for (int j = i; j <= MaxNode; j++)
		{
			if (num[i] < num[j])
			{
				Swap(num[i], num[j]);
			}
		}
	}
}

int main()
{
	ImportData();
	PrintData();
	SelectionSort();
}
