#ifndef __STACK__
#define __STACK__
#include "Ref.h"

#define MAX_LENGTH 10
typedef int Element_type;
class Stack : public Ref
{
    private:
    int index;
    Element_type *arr;

    public:
    Stack();
    ~Stack();
    static Stack* createStack();

    void push(int value);
    Element_type pop();
    int length();
    bool IsEmpty();
    Element_type at(int index);  
};

#endif 