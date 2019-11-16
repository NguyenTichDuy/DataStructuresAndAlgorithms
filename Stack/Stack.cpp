#include"Stack.h"

Stack::Stack()
{
    arr = Element_type[MAX_LENGTH];
}
Stack::~Stack()
{
    delete [] arr;
}
void Stack::push(int value) 
{
    if (index >= MAX_LENGTH - 1)
    {
        cout << "Stack over flow!!!" << endl;
    }
    else
    {
        arr[++index] = value;
    }
}

Element_type Stack::pop()
{
    Element_type value;
    if (IsEmpty())
    {
        cout << "Stack is empty!!!1" << endl;
    }
    else
    {
        value = arr[index];
        --index;
        return value;
    }
}
bool Stack::IsEmpty()
{
    if (index == -1)
    {
        return true;
    }
    return false;
}
int Stack::length()
{
    return index + 1;
}
Element_type Stack::at(int _index)
{
    return this->arr[_index];
}

Stack* Stack::createStack()
{
    Stack *stack = new Stack();
    if (stack)
    {
        stack->autoRealease();
        return stack;
    }

    delete stack;
    stack = nullptr;
    return stack;
}
