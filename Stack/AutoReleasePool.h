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
class DestroyedMyInstance;
class PoolManager
{
    public:
        static PoolManager* getInstance();
    
        void push(AutoRealeasePool* pool);

        void pop();
     
        AutoRealeasePool *getCurrentPool() const;

        static void releaseInstance();
    protected:
        friend class DestroyedMyInstance;
        virtual ~PoolManager();
    private:
    
        static PoolManager* instance;

        static DestroyedMyInstance detroyInstance;
        
        std::vector<AutoRealeasePool*> poolArray;     
};
//  
class DestroyedMyInstance
{
private:
    PoolManager *singleton;
public:
    DestroyedMyInstance(PoolManager *_instance);
    void setInstance(PoolManager *_instance);
    ~DestroyedMyInstance();
};

#endif //__AUTO_REALEASE_POOL__