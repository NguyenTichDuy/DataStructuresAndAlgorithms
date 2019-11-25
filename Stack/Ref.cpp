#include "Ref.h"
#include "AutoReleasePool.h"

void Ref::autoRealease()
{
    PoolManager::getInstance()->getCurrentPool()->AddObject(this);
}
Ref::~Ref()
{
    
}