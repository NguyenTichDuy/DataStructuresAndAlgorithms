#include <iostream>
using namespace std;
template<class Element_type>
class QueuePointer
{
    private:
    Element_type *arr;
    int front;
    int rear;
    unsigned capacity;
    public:
    void createQueue(unsigned _capacity);
    void push(Element_type *_queue);
    Element_type* pop();
};
template<class Element_type> void QueuePointer<Element_type>::createQueue(unsigned _capacity)
{
    QueuePointer *queue = new QueuePointer();
    queue->capacity = _capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->arr = new Element_type[queue->capacity];
    return queue;
}
template<class Element_type> void QueuePointer<Element_type>::push(Element_type _queue)
{
    if (front >= )
}
int main()
{
    QueuePointer<int> *queue = new QueuePointer;
    queue->push(50);

}