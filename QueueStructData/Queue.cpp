#include<stdio.h>

#define MaxLength 5
int Queue[MaxLength];
int front = 0;
int rear = 0;
bool Queue_emtpy(int Queue[], int &_front, int &_rear)
{
	if (_front == _rear)
	{
		return true;
	}
	else
		return false;
}
void Push(int _in, int Queue[], int &_front, int &_rear)
{
	if (Queue_emtpy(Queue, _front, _rear))
	{
		_front = _rear = 0;
	}
	if (_rear >= MaxLength - 1)
	{
		if (_front > 0)
		{
			for(int i = 0; i <_rear - _front - 1; i++)
			{
				Queue[i] = Queue[_front + i];
			}
		}
		else
		{
			printf("Queue is full!!!");
			return;			
		}
	}
	Queue[_rear] = _in;
	_rear++;
}
void Pop(int &_out, int Queue[], int &_front, int &_rear)
{
	if (Queue_emtpy(Queue, _front, _rear))
	{
		_front = _rear = 0;
		printf("Queue is empty");
	}
	_out = Queue[_front];
	_front++;
}
int main()
{
	int n;
	char c;
	do
	{
		printf("\nPush value to queue: ");
		scanf("%d", &n);
		Push(n, Queue, front, rear);
		fflush(stdin);
		printf("\nDo you want to continues???? (y)");
		scanf("%c", &c);
	}while(c == 'y' || c == 'Y');
	do
	{
		printf("\nPop value to queue: ");
		Pop(n, Queue, front, rear);
		printf("\nValue: %d", n);
		fflush(stdin);
		printf("\nDo you want to continues???? (y)");
		scanf("%c", &c);
	}while(c == 'y' || c == 'Y');
}














