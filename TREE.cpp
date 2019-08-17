#include<stdio.h>
struct node
{
	int num;
	node *left;
	node *right;
};
node *newNode;

//--------Tien to--------------------
void Pre(node *masterNode)
{
	node *moveNode;
	moveNode = masterNode;
	if (moveNode != NULL)
	{
		printf("%5d", moveNode->num);
		Pre(moveNode->left);
		Pre(moveNode->right);
	}
}
//--------Trung to--------------------
void In(node *masterNode)
{
	node *moveNode;
	moveNode = masterNode;

	if (moveNode != NULL)
	{
		In(moveNode->left);
		printf("%5d",moveNode->num);
		In(moveNode->right);
	}
}
//--------Hau to--------------------
void Pos(node *masterNode)
{
	node *moveNode;
	moveNode = masterNode;

	if (moveNode != NULL)
	{
		Pos(moveNode->left);
		Pos(moveNode->right);
		printf("%5d",moveNode->num);
	}
}
//--------Chen nut-------------------
void InsertNode(int _num, node *&_node)
{
	if (_node == NULL)
	{
		_node = new node;
		_node->num = _num;
		_node->left = _node->right = NULL;
	}
	else if (_num < _node->num) 
	{
		InsertNode(_num, _node->left);
	}
	else if (_num > _node->num)
	{
		InsertNode(_num, _node->right);
	}
	else 
	{
		printf("Node is instead!!!");
	}
}
int main()
{
	int x;
	char choose;
	newNode = NULL;
	do{
		printf("\nNum = ");
		scanf("%d", &x);
		InsertNode(x, newNode);
		printf("\nDo you want to continues? (y)");
		fflush(stdin);
		scanf("%c", &choose);
	}while(choose == 'y' || choose == 'Y');
	
	printf("\nTien to:");
	Pre(newNode);
	
	printf("\nTrung to:");
	In(newNode);
	
	printf("\nHau to:");
	Pos(newNode);
}
