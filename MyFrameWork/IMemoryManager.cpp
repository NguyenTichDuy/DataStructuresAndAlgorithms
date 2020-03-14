#include "IMemoryManager.h"
#include "Complex.h"
#define POOLSIZE 32

MemoryManager::IMemoryManager()
{
        this->freeStoreHead = 0;
        this->expandPoolSize();     
}

MemoryManager::~IMemoryManager()
{
    this->cleanUp();
}
inline void * MemoryManager::allocate(size_t size)
{
    if(this->freeStoreHead == 0)
    {
        expandPoolSize();
    }
    FreeStore *head = freeStoreHead;
    freeStoreHead = head->next;
    return head;
}
inline void MemoryManager::free(void* deleted)
{
    FreeStore *head = static_cast <FreeStore*> (deleted);
    head->next = freeStoreHead;
    freeStoreHead = head;
}
void MemoryManager::expandPoolsize()
{
    size_t size = (sizeof(Complex) > sizeof(FreeStore*))  ? sizeof(Complex) : sizeof (FreeStore*);
    
}