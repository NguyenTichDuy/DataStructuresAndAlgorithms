#ifndef __AUTO_REALEASE_POOL__
#define __AUTO_REALEASE_POOL__
#include <vector>
class Ref;
class AutoRealeasePool
{
    private:    
        std::vector<Ref *> objectArray;
    public:
        void Clear();
        AutoRealeasePool();
        void AddObject(Ref * object);
};

//  

class PoolManager
{
    public:
        static PoolManager *getInstance();
    
        void push(AutoRealeasePool* pool);

        void pop();
     
        AutoRealeasePool *getCurrentPool() const;
        
        static PoolManager *instance;

    private:
        std::vector<AutoRealeasePool*> poolArray;
        ~PoolManager();
};
#endif //__AUTO_REALEASE_POOL__