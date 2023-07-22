#include <iostream>
#include "MyQueue.h"

class BinarySearchTree
{
private:
    Node *root;

    // Helper function for inserting a value into the binary search tree
    Node* insertHelper(Node *current, int value)
    {
        if (current == nullptr)
        {
            return new Node(value);
        }

        if (value < current->data)
        {
            current->left = insertHelper(current->left, value);
        }
        else if (value > current->data)
        {
            current->right = insertHelper(current->right, value);
        }

        return current;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insertHelper(root, value);
    }

    void levelOrderTraversal()
    {
        if (root == nullptr)
        {
            return;
        }

        MyQueue queue;
        queue.push(root);

        while (!queue.empty())
        {
            Node *current = queue.front();
            std::cout << current->data << " ";

            if (current->left)
            {
                queue.push(current->left);
            }

            if (current->right)
            {
                queue.push(current->right);
            }

            queue.pop();
        }
    }
};

int main()
{
    BinarySearchTree bst;

    // 插入节点构建二叉搜索树
    bst.insert(4);
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.insert(6);
    bst.insert(5);
    bst.insert(7);

    // 层序遍历并输出结果
    std::cout << "Level Order Traversal: ";
    bst.levelOrderTraversal();
    std::cout << std::endl;

    return 0;
}
