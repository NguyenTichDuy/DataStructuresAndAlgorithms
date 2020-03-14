#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node *next;

	Node(int _data)
	{
		this->data = _data;
		this->next = nullptr;
	}
};
class LinkList
{
public:
	Node *head;
	Node *tail;
	LinkList()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insertNodeLastList(int _data);
	void insertNodeFirstList(int _data);
	void insertNodeAtList(int _data, int _index);

	void printLinkList();

	
	
	Node *middleNode(int _index);
};
void LinkList::printLinkList()
{
	Node *node = this->head;

	while(node)
	{
		cout << node->data << endl;
		node = node->next;
	}
}
void LinkList::insertNodeLastList(int _data)
{
	Node *node = new Node(_data);
	Node *nodeH = this->head;
	if (head == nullptr)
	{
		this->head = node;

	}
	else
	{
		while(nodeH->next != nullptr)
		{
			nodeH = nodeH->next;
		}
		nodeH->next = node;
	}
};
void LinkList::insertNodeFirstList(int _data)
{
	Node *newNode = new Node(_data);
	if (this->head == nullptr)
	{
		this->head = newNode;
	}
	else
	{
		newNode->next = this->head;
		this->head = newNode;
	}
}
void LinkList::insertNodeAtList(int _data, int _position)
{
	Node* newNode = new Node(_data);
	Node* node = this->head;
	while (--_position)
	{
		if (node == nullptr)
		{
			cout << "Position is out of list size" << endl;
			return;
		}
		node = node->next;
	}
	newNode->next = node->next;
	node->next = newNode;
}
int main()
{
	LinkList *list = new LinkList();

	list->insertNodeFirstList(23);
	list->insertNodeFirstList(12);
	list->insertNodeFirstList(2);
	list->insertNodeFirstList(3);
	list->insertNodeFirstList(6);

	list->insertNodeAtList(100, 10);
	list->printLinkList();
}