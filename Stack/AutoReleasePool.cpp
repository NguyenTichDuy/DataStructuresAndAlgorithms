#include "AutoReleasePool.h"
#include "Ref.h"
AutoRealeasePool::AutoRealeasePool()
{
    this->objectArray.reserve(150);
    PoolManager::getInstance()->push(this);
}
void AutoRealeasePool::AddObject(Ref* _object)
{   
    this->objectArray.push_back(_object);
}

void AutoRealeasePool::Clear()
{
    while (!this->objectArray.empty())
    {
        auto &object = objectArray.back();  
        delete object;
        object = nullptr;
    }
}

// defintion of class pool manager
PoolManager* PoolManager::instance = nullptr;

PoolManager* PoolManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new PoolManager();

        new AutoRealeasePool();
    }
    return instance;
}
PoolManager::~PoolManager() 
{
    while (!poolArray.empty())
    {
        AutoRealeasePool *pool = this->poolArray.back();

        delete pool;
    }
}
void PoolManager::push(AutoRealeasePool *pool)
{
    poolArray.push_back(pool);
}
AutoRealeasePool *PoolManager::getCurrentPool() const
{
    return  poolArray.back();
}