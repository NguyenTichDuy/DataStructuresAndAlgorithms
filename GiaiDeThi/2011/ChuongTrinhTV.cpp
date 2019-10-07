#include<stdio.h>
#include<vector>
using namespace std;
FILE *f1, *f2;
int n, count = 0;
vector<int> timeStart, timeEnd;
void InputFile()
{
	f1 = fopen("TVSHOW_INP.txt", "r");
	fscanf(f1, "%d", &n);
	while(!feof(f1))
	{
		int a, b;
		fscanf(f1, "%d", &a);
		fscanf(f1, "%d", &b);
		timeStart.push_back(a);
		timeEnd.push_back(b);
	}
	fclose(f1);
}
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Sort()
{
	for (int i = 0; i < n - 1 ;i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (timeStart.at(i) > timeStart.at(j))
			{
				Swap(timeStart.at(i), timeStart.at(j));
				Swap(timeEnd.at(i), timeEnd.at(j));
			}
		}
	}
}
void FindTVShow()
{
	bool check;
	for (int i = 0; i < n; i++)
	{
		check = true;
		for (int j = i+1; j < n && check; j++)
		{
			if (timeEnd.at(i) > timeStart.at(j))
			{
				++count;
			}
			else
			{
				check = false;
			}
				
		}
	}
}
void OutputFile()
{
	f2 = fopen("TVSHOW_OUT.txt", "w");
	fprintf(f2, "%d", count);
	fclose(f2);
}
void print()
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", timeStart.at(i));
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", timeEnd.at(i));
	}
	printf("\n");
}
int main()
{
	InputFile();
	print();
	Sort();
	print();
	FindTVShow();	
	OutputFile();
}
