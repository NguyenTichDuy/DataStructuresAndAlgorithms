#include<stdio.h>
#define MaxLength 50
char StackContainNum[MaxLength];
char StackContainOperator[MaxLength];
char StackContainToInt[MaxLength];
int StackContainInt[MaxLength];

int moveOfStackNum = MaxLength;
int moveOfStackOperator = MaxLength;
int moveOfStackInt = MaxLength;
int moveOfStackToInt = MaxLength;

void Push(char x, char Stack[], int &n)
{
	if (n == 0)
	{
		printf("Stack is full!!!");
	}
	else
	{
		n = n - 1;
		Stack[n] = x;
	}
}
void Pop(char &y, char Stack[], int &n)
{
	if (n == MaxLength)
	{
		printf("Stack is null!!!");
	}
	else
	{
		y = Stack[n];
		n = n + 1;
	}
}
void PushInt(int x, int Stack[], int &n)
{
	if (n == 0)
	{
		printf("Stack is full!!!");
	}
	else
	{
		n = n - 1;
		Stack[n] = x;
	}
}
void PopInt(int &y, int Stack[], int &n)
{
	if (n == MaxLength)
	{
		printf("Stack is null!!!");
	}
	else
	{
		y = Stack[n];
		n = n + 1;
	}
}
int main()
{
	char expression[50];
	char compareChar, printChar;
	int valueInt;
	char c;
	int x1, x2;
	float result;
	//do 
	//{
		printf("\nPrint expression: ");
		fgets(expression);
		for(int i = 0 ;expression[i] != NULL; i++)
		{
			if (expression[i] == '(')
			{
				Push(expression[i], StackContainOperator, moveOfStackOperator);
			}
			else if (expression[i] == ')')
			{
				char character;
				bool check = true;
				for (int j = 0; check; j++)
				{
				 	Pop(character, StackContainOperator, moveOfStackOperator);
					if (character == '(')
					{
						check = false;
						continue;
					}
					Push(character, StackContainNum, moveOfStackNum);
				}
			}
			else if (expression[i] >= 48 && expression[i] <= 57)
			{
				Push(expression[i], StackContainNum, moveOfStackNum);
			}
			else if (expression[i] == '*' || expression[i] == '/')
			{
				Push(expression[i], StackContainOperator, moveOfStackOperator);
			}
			else if (expression[i] == '+'|| expression[i] == '-')
			{
				if (moveOfStackOperator < MaxLength)
				{
					Pop(compareChar, StackContainOperator, moveOfStackOperator);
					moveOfStackOperator--;
					if (compareChar == '*' || compareChar == '/')
					{
						Push(compareChar, StackContainNum, moveOfStackNum);
						moveOfStackOperator++;
					}	
				}
				Push(expression[i], StackContainOperator, moveOfStackOperator);
			}
			else
			{
				printf("\nOperator isn't found\n");
			}
		}
		while (moveOfStackOperator != MaxLength)
		{
			Pop(printChar, StackContainOperator, moveOfStackOperator);
			Push(printChar, StackContainNum, moveOfStackNum);
		}
		printf("\nSwitch to Polish notation: ");
		for(int i = MaxLength; i >= moveOfStackNum; i--)
		{
			printf("%c", StackContainNum[i]);
		}
		//-----Calculate the value of Polish notaion expression-------
		printf("\n");
		moveOfStackOperator = MaxLength;
		while(moveOfStackNum != MaxLength)
		{
			Pop(printChar, StackContainNum, moveOfStackNum);
			Push(printChar,StackContainToInt, moveOfStackToInt);
		}
		while(moveOfStackToInt != MaxLength)
		{
			Pop(printChar, StackContainToInt, moveOfStackToInt);
			if (printChar >= 48 && printChar <= 57)
			{
				valueInt = printChar - 48;
				printf("\t%d", valueInt);
				PushInt(valueInt, StackContainInt, moveOfStackInt);
			}
			else if (printChar == '*')
			{
				PopInt(x1, StackContainInt, moveOfStackInt);
				PopInt(x2, StackContainInt, moveOfStackInt);
				result = x2 * x1;
				PushInt(result, StackContainInt, moveOfStackInt);
			}
			else if (printChar == '/')
			{
				PopInt(x1, StackContainInt, moveOfStackInt);
				PopInt(x2, StackContainInt, moveOfStackInt);
				PushInt(result, StackContainInt, moveOfStackInt);
				result = (float)x2 / x1;
			}
			else if (printChar == '+')
			{
	
				PopInt(x1, StackContainInt, moveOfStackInt);
				PopInt(x2, StackContainInt, moveOfStackInt);
				result = x2 + x1;
				PushInt(result, StackContainInt, moveOfStackInt);
			}
			else if (printChar == '-')
			{
				PopInt(x1, StackContainInt, moveOfStackInt);
				PopInt(x2, StackContainInt, moveOfStackInt);
				result = x2 - x1;
				PushInt(result, StackContainInt, moveOfStackInt);
			}						
		}
		printf("\nResult: %f", result);
	//}while()

}
