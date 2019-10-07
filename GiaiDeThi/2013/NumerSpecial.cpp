#include<stdio.h>
#include<vector>
using namespace std;
FILE *f1, *f2;
long long n;
int NumSpecial();
void InputFile()
{
	f1 = fopen("NUMSPECIAL.INP", "r");
	fscanf(f1, "%d", &n);
	fclose(f1);
}
void OutputFile()
{
	f2 = fopen("NUMSPECIAL.OUT", "w");
	fprintf(f2, "%l", NumSpecial());
	fclose(f2);
}
int NumSpecial()
{
	long long sum = 0, elementNum, value = n;
	while (value > 0)
	{
		elementNum = value % 10;
		sum += elementNum;
		value /= 10;		
	}
	if (n % sum)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	InputFile();
	NumSpecial();
	OutputFile();
	printf("%d", NumSpecial());
}
