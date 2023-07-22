#include <iostream>
// 链表节点模板
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

// 队列类模板
template <typename T>
class Queue
{
private:
    Node<T> *front; // 队头指针
    Node<T> *rear;  // 队尾指针
public:
    Queue()
    {
        front = rear = nullptr;
    }
    // 入队
    void enqueue(const T &value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    // 出队
    void dequeue()
    {
        if (front == nullptr)
        {
            rear = nullptr;
            std::cout << "队列为空，无法出队！" << std::endl;
            return;
        }
        front = front->next;
    }
    // 获取队头元素
    T getFront()
    {
        if (front == nullptr)
        {
            std::cout << "队列为空，无法获取队头元素！" << std::endl;
            return T();
        }
        return front->data;
    }
    // 判断队列是否为空
    bool isEmpty()
    {
        return front == nullptr;
    }
};

int main()
{
    Queue<int> intQueue;
    for (int i = 0; i < 10; i++)
    {
        intQueue.enqueue(i);
    }
    std::cout << "Queue Head:" << intQueue.getFront() << std::endl;
    std::cout << "Is Queue empty? " << std::boolalpha << intQueue.isEmpty() << std::endl;
    std::cout << "Dequeue from the head of Queue:" << std::endl;
    while (!intQueue.isEmpty())
    {
        std::cout << intQueue.getFront() << " ";
        intQueue.dequeue();
    }
    std::cout << "Is Queue empty? " << std::boolalpha << intQueue.isEmpty() << std::endl;
    return 0;
}