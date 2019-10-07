#include<stdio.h>
#include<vector>
using namespace std;
FILE *f1, *f2;
int c, n, count = 0;
vector<int> execise, execiseIn;
void InputFile()
{
	f1 = fopen("OLYMPIC_IN.txt", "r");
	fscanf(f1, "%d", &n);
	fscanf(f1, "%d", &c);
	while(!feof(f1))
	{
		int a, b;
		fscanf(f1, "%d", &a);
		fscanf(f1, "%d", &b);
		execise.push_back(a);
		execiseIn.push_back(b);
	}
	fclose(f1);
}
void WorkExecise()
{
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (c >= execise.at(j) && execise.at(j) >= 1)
			{
				c+= execiseIn.at(j);
				execise.at(j) = -1;
				count++;
			}
		}
	}
}
void OutputFile()
{
	f2 = fopen("OLYMPIC_OUT.txt", "w");
	fprintf(f2, "%d", count);
	fclose(f2);
}
int main()
{
	InputFile();
	WorkExecise();	
	OutputFile();
}
