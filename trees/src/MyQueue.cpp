#include "MyQueue.h"

MyQueue::MyQueue() : front_index(-1), rear_index(-1) {}

void MyQueue::push(Node *val)
{
    if (empty())
    {
        front_index = rear_index = 0;
    }
    else
    {
        rear_index++;
    }
    data.push_back(val);
}

void MyQueue::pop()
{
    if (!empty())
    {
        front_index++;
        if (front_index > rear_index)
        {
            front_index = rear_index = -1;
        }
    }
}

Node *MyQueue::front() const
{
    if (!empty())
    {
        return data[front_index];
    }
    return nullptr;
}

Node *MyQueue::back() const
{
    if (!empty())
    {
        return data[rear_index];
    }
    return nullptr;
}

bool MyQueue::empty() const
{
    return front_index == -1 && rear_index == -1;
}
