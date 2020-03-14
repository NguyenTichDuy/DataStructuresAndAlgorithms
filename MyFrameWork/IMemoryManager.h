#ifndef __MEMORYMANAGER__
#define __MEMORYMANAGER__
class IMemoryManager
{
public:
    virtual void* allocate(size_t) = 0;
    virtual void free(void*) = 0;
};

class MemoryManager : public IMemoryManager
{
private:
    struct FreeStore
    {
        FreeStore *next;
    };

    void expandPoolSize();
    void cleanUp();

    FreeStore *freeStoreHead;
public:
    MemoryManager();
    virtual ~MemoryManager();

    virtual void *allocate(size_t);
    virtual void free(void*);
};
#endif

