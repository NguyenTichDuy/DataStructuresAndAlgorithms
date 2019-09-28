#include<stdio.h>
#include<vector>
#include<list>
using namespace std;
FILE *f, *f1;

vector<char> MyStack;
vector<char> NewStack;
void Input()
{
	char c;
	f = fopen("BRACKETS.txt", "r");
	while(!feof(f))
	{
		fscanf(f, "%c", &c);
		MyStack.push_back(c);
	}
	fclose(f);
}
void Output()
{
	
}
void Check()
{
	
}
void CheckString()
{
	for (int i = 0; i < MyStack.size(); i++)
	{
		if (MyStack.at(i) == '{')
		{
			for (int j = i + 1; j < MyStack.size(); j++) 
			{
				if (MyStack.at(j) == '}')
				{
					
				}
			}
		}
		if (MyStack.at(i) == '[')
		{
			
			for (int j = i + 1; j < MyStack.size(); j++) 
			{
				if (MyStack.at(j) == ']')
				{
					
				}
			}
		}
		if (MyStack.at(i) == '(')
		{
			
			for (int j = i + 1; j < MyStack.size(); j++) 
			{
				if (MyStack.at(j) == ')')
				{
					
				}
			}
		}
		else
		{
			My
		}
	}
}
int main()
{
	Input();
	for (int i = 0; i < MyStack.size(); i++)
	{
		printf("%c", MyStack[i]);
	}
	
}
