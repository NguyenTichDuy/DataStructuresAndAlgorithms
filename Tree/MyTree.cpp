#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    struct Node* nodeLeft;
    struct Node* nodeRight;
};
struct Node* NewNode(int _data)
{
    struct Node* temp = new Node;
    temp->data = _data;
    temp->nodeLeft = NULL;
    temp->nodeRight = NULL;
    return temp;
}
void printInOrder(struct Node* temp)
{
    if(!temp)
    {
        return;
    }
    printInOrder(temp->nodeLeft);
    cout << temp->data << " ";
    printInOrder(temp->nodeRight);
}
void printPosOrder(struct Node* temp)
{
    if(!temp)
    {
        return;
    }
    cout << temp->data << " ";
    printPosOrder(temp->nodeLeft);
    printPosOrder(temp->nodeRight);
}
void insertNode(struct Node* temp, int key)
{
    queue<struct Node*> q;
    q.push(temp);
    while (!q.empty())
    {
        struct Node* temp = q.front();
        q.pop();
        if (!temp->nodeLeft)
        {
            temp->nodeLeft = NewNode(key);
            break;
        }
        else
        {
            q.push(temp->nodeLeft);
        }
        
        if (!temp->nodeRight)
        {
            temp->nodeRight = NewNode(key);
            break;
        }
        else
        {
            q.push(temp->nodeRight);
        }
        
    }
}
int main()
{
    struct Node* root = NewNode(3);
    root->nodeLeft = NewNode(2);
    root->nodeRight = NewNode(5);
    root->nodeRight->nodeRight = NewNode(6);
    root->nodeLeft->nodeLeft = NewNode(12);
    printInOrder(root);
    cout << endl;
    insertNode(root, 100);
    printPosOrder(root);
}