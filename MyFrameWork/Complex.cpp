#include "Complex.h"

MemoryManager gMemoryManager;
void* Complex::operator new(size_t size)
{
    return gMemoryManager.allocate(size);
}
void* Complex::operator new[] (size_t size)
{
    return gMemoryManager.allocate(size);
}
void Complex::operator delete (void* poinerToDelete)
{
    gMemoryManager.free(poinerToDelete);
}
void Complex::operator delete[](void* arrayToDelete)
{
    gMemoryManager.free(arrayToDelete);
}