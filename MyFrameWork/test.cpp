#include<iostream>
using namespace std;
class MemoryManager
{
    private:
        MemoryManager();
        static MemoryManager *instance;
    public:
        static MemoryManager *getInstance()
        {
            if (instance == NULL)
            {
                instance = new MemoryManager();
            }
            return instance;
        }
};
class Complex
{
    private:
    double r;
    double h;
    public:
    Complex()
    {
        
    }

};
int main()
{

}