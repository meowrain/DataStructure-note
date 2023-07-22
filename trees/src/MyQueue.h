#ifndef MY_QUEUE_H
#define MY_QUEUE_H
#include <iostream>
#include <vector>
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class MyQueue
{
private:
    std::vector<Node *> data;
    int front_index;
    int rear_index;

public:
    MyQueue();
    void push(Node *val);
    void pop();
    Node *front() const;
    Node *back() const;
    bool empty() const;
};

#endif