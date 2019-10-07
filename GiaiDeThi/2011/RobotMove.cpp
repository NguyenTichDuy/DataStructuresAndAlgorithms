#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
FILE *f, *f1;
int n;
int left = 0, right = 0, ahead = 0;
vector<int> x1, x2;
bool check = false;
void Input()
{
	int _x1,_x2;
	f = fopen("ROBOTINP.txt", "r");
	fscanf(f, "%d", &n);
	for(int i = 0; i < n; i++)
	{
		fscanf(f, "%d", &_x1);
		fscanf(f, "%d", &_x2);
		x1.push_back(_x1);
		x2.push_back(_x2);
	}
	fclose(f);
}
void RobotMoveRight()
{
	for (int i = 0; i < n - 2; i++)
	{
		if (abs(x1[i] - x1[i+1]) + abs(x2[i] - x2[i+1]) != 1)
		{
			check = true;
			return;
		}
		else if (((x1[i + 1] - x1[i])*(x2[i+2] - x2[i+1]) + (x2[i + 1] - x2[i])*(x1[i+2] - x1[i+1])) < 0)
		{
			right++;
		}
		else if (((x1[i + 1] - x1[i])*(x2[i+2] - x2[i+1]) + (x2[i + 1] - x2[i])*(x1[i+2] - x1[i+1])) == 0)
		{
			ahead++;
		}
		else
		{
			left++;
		}
	}
}
void Output()
{
	f1 = fopen("ROBOTOUT.txt", "w");
	if (check)
	{
		printf("Output is error!!!");
	}
	else
	{
		fprintf(f1, "\nRight: %d", right);
		fprintf(f1, "\nLeft: %d", left);
		fprintf(f1, "\nAhead: %d", ahead);
	}
	fclose(f1);
}
int main()
{
	Input();
	RobotMoveRight();
	Output();
	
}
