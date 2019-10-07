#include<stdio.h>
#include<vector>
using namespace std;
FILE *f1, *f2;
vector<int> stack;
int countMax = -1;
int n;
void InputFile()
{
	f1 = fopen("FSEQ_INP.txt", "r");
	fscanf(f1, "%d", &n);
	int num;
	while(!feof(f1))
	{
		fscanf(f1, "%d", &num);
		stack.push_back(num);
	}
	fclose(f1);
}
void OutputFile()
{
	f2 = fopen("FSEQ_OUT.txt", "w");
	fprintf(f2, "%d", countMax);
	fclose(f2);
}
void FindSubFibonacci()
{
	int count = 2;
	for (int i = n - 1; i >= 2; i--)
	{
		if (stack.at(i) == (stack.at(i-1) + stack.at(i-2)))
		{
			count++;
		}
		else 
		{
			if (count > 2 && count > countMax)
			{
				countMax = count;
			}
			count = 2;
		}
	}
}
int main()
{
	InputFile();
	FindSubFibonacci();
	OutputFile();
}
