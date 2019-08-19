#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h> 

#define MaxLength 50
int D[MaxLength];
int Matrix[MaxLength][MaxLength];
FILE *f, *f1;
int nodeNumber;

void OutPutGraph();
void FindShortWay();
void InPutGraph();
void AlgorithmsFindShortWay();

void OutPutGraph()
{
	f1 = fopen("OutPutGraph.txt", "a+");
	fprintf(f1, "\n");
	for (int i = 1; i <= nodeNumber;i++)
	{
		for (int j = 1; j <= nodeNumber; j++)
		{
			fprintf(f1, "\t%10d", Matrix[i][j]);
		}
		fprintf(f1, "\n");
	}
	fclose(f1);
}
void AlgorithmsFindShortWay()
{
	for (int k = 1; k <= nodeNumber; k++)
	{
		for (int i = 1; i <= nodeNumber; i++)
		{
			for (int j = 1; j <= nodeNumber; j++)
			{
				int newValue = Matrix[i][k] + Matrix[k][j];
				if (newValue < Matrix[i][j])
				{
					Matrix[i][j] = newValue;
				}
			}
		}
		OutPutGraph();
	}
}
void FindShortWay()
{
	char c;
	int x, y;
	do
	{
		printf("Print the way: ");
		scanf("%d", &x);
		scanf("%d", &y);
		for (int k = 1; k <= nodeNumber; k++)
		{
			int newValue = Matrix[x][k] + [k][y];
			if (Matrix[x][y] == newValue)
			{
				printf("\nWay: %d", x);
				
			}
			
		}
	}
	
}
void InPutGraph()
{
	f = fopen("InPutGraph.txt", "r+");
	int x, y;
	fscanf(f, "%d", &nodeNumber);
	while(!feof(f))
	{
		fscanf(f, "%d", &x);
		fscanf(f, "%d", &y);
		fscanf(f, "%d", &Matrix[x][y]);
	}
	fclose(f);
	OutPutGraph();
}
void InitMatrix()
{
	f = fopen("InPutGraph.txt", "r+");
	fscanf(f, "%d", &nodeNumber);
	fclose(f);
	for(int i = 1; i <= nodeNumber;i++)
	{
		for (int j = 1; j <= nodeNumber; j++)
		{
			if (i == j)
			{
				Matrix[i][j] = 0;	
			}
			else 
			{
				Matrix[i][j] = 30000;
			}
		}
	}
	OutPutGraph();
}

int main()
{
	InitMatrix();
	InPutGraph();
	AlgorithmsFindShortWay();
	
}
