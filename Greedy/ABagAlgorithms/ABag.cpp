#include<stdio.h>

#define MaxLength 50

struct Item
{
	int id;
	int value;
	int weight;
};
FILE *fInput, *fOutput;
int length;
int maxWeight;
typedef Item ElementType;
ElementType item[MaxLength];

void InitItem();
void PrintItem();
int GreedyAlgorithmCase1();
int GreedyAlgorithmCase2();
int GreedyAlgorithmCase3();
int CheckWeight();

void InitItem()
{
	fInput = fopen("Input.txt", "r+");
	fscanf(fInput, "%d", &length);
	fscanf(fInput, "%d", &maxWeight);
	for(int i = 0; i < length; i ++)
	{
		item[i].id = i;
		fscanf(fInput, "%d", &item[i].value);
		fscanf(fInput, "%d", &item[i].weight);
	}
	fclose(fInput);
}
void PrintItem()
{
	fOutput = fopen("Output.txt", "w+");
	//printf("Value: ");
	for(int i = 0; i < length; i++)
	{
		fprintf(fOutput, "%3d", item[i].id);
		fprintf(fOutput, "%3d", item[i].value);
		fprintf(fOutput, "%3d", item[i].weight);
		fprintf(fOutput, "\n");
	}
}
void SelectionSort()
{
}
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int GreedyAlgorithmCase1()
{
	// tt1
	for (int i = 0; i < length; i++)
	{
		for(int j = i + 1; j < length; j++)
		{
			if (item[i].value < item[j].value)
			{
				Swap(item[i].value, item[j].value);
				Swap(item[i].weight, item[j].weight);
				Swap(item[i].id, item[j].id);
			}
		}
	}
	return CheckWeight();

}
int GreedyAlgorithmCase2()
{
	// tt1
	for (int i = 0; i < length; i++)
	{
		for(int j = i + 1; j < length; j++)
		{
			if (item[i].weight > item[j].weight)
			{
				Swap(item[i].value, item[j].value);
				Swap(item[i].weight, item[j].weight);
				Swap(item[i].id, item[j].id);				
			}
		}
	}
	return CheckWeight();
}
int CheckWeight()
{
	int i = 0;
	int sumValue;	
	for (int i = 0; i < length; i++)
	{
		if (item[i].weight < maxWeight)
		{
			sumValue = item[i].value;
			i = length;		
		}
	}

	for (int j = i + 1; j < length; j ++)
	{
		int sumWeight = item[i].weight + item[j].weight;
		if (sumWeight <= maxWeight)
		{
			//printf("hello");
			sumValue = item[i].value + item[j].value;		
		}
	}
	return sumValue;
}
int GreedyAlgorithmCase3()
{
	for (int i = 0; i < length; i++)
	{
		for(int j = i + 1; j < length; j++)
		{
			float value1 = item[i].value / item[i].weight;
			float value2 = item[j].value / item[j].weight;
			
			if (value1 < value2)
			{
				Swap(item[i].value, item[j].value);
				Swap(item[i].weight, item[j].weight);
				Swap(item[i].id, item[j].id);				
			}
		}
	}
	return CheckWeight();

}
int max(int a, int b, int c)
{
	int maxValue = a;
	if (maxValue < b)
	{
		maxValue = b;
	}
	if (maxValue < c)
	{
		maxValue = c;
	}
	return maxValue;
}
int main()
{
	InitItem();
	PrintItem();
	int case1 = GreedyAlgorithmCase1();
	int case2 = GreedyAlgorithmCase2();
		PrintItem();
	int case3 = GreedyAlgorithmCase3();
	printf("%3d", case1);
	printf("%3d", case2);
	printf("%3d", case3);
	printf("\n%d", max(case1, case2, case3));

}
