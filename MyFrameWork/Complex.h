#ifndef __COMPLEX.H__
#define __COMPLEX.H__
#include"IMemoryManager.h"
class Complex
{
private:
    double r;
    double c;
public:
    Complex(double a, double b) : r(a), c(b) {};
    inline void* operator new (size_t);
    inline void* operator new[] (size_t);
    inline void operator delete (void*);
    inline void operator delete[] (void*);
};
#endif

