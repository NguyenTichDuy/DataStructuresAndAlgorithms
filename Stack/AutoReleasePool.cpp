#include "AutoReleasePool.h"
#include "Ref.h"
#include <iostream>

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
        Ref *object = objectArray.back();
        objectArray.pop_back();
        delete object;
        object = nullptr;
    }
}
//
DestroyedMyInstance::DestroyedMyInstance(PoolManager *_instance)
{
    this->singleton = _instance;
}

DestroyedMyInstance::~DestroyedMyInstance()
{
    delete this->singleton;
    this->singleton = nullptr;
}
void DestroyedMyInstance::setInstance(PoolManager *_instance)
{
    this->singleton = _instance;
}
// defintion of class pool manager
PoolManager* PoolManager::instance = nullptr;

PoolManager* PoolManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new (std::nothrow) PoolManager();
        PoolManager::detroyInstance.setInstance(instance);
        new AutoRealeasePool();
    }
    return instance;
}

PoolManager::~PoolManager() 
{
    std::cout << "hihii" << std::endl;
    
    while (!poolArray.empty())
    {
        AutoRealeasePool *pool = this->poolArray.back();
        pool->Clear();
        this->poolArray.pop_back();
        delete pool;
    }
    delete instance;
    instance = nullptr;
}

void PoolManager::push(AutoRealeasePool *pool)
{
    poolArray.push_back(pool);
}
AutoRealeasePool *PoolManager::getCurrentPool() const
{
    return  poolArray.back();
}