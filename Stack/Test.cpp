#include<iostream>
#include"Stack.h"
FILE* f1, *f2;
void Input(Stack *_stack)
{
    f1 = fopen("input.txt", "r");
    int c = 0;
    while (!feof(f1))
    {   
        fscanf(f1, "%d", &c);
        _stack->push(c);
    }
    fclose(f1);
}
void OutPut(Stack *_stack)
{
    f2 = fopen("output.txt", "w+");
    for (int i = 0; i < _stack->length(); i++)
    {
        fprintf(f2, " %d ", _stack->at(i));
    }
    fclose(f2);
}

int main()
{
    Stack *arrStack = Stack::createStack();
    Input(arrStack);
    arrStack->push(5);
    OutPut(arrStack);
}