#include <iostream>
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class Tree
{
private:
    Node *root;
    Node *insertRecursive(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

public:
    Tree() : root(nullptr){};
    Node *getRoot()
    {
        return root;
    }
    void insert(int value)
    {
        root = insertRecursive(root, value);
    }
    int getHeight(Node *node)
    {
        if (node == nullptr)
        {
            return -1;
        }
        return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
};

int main(void)
{
    Tree bst;
    bst.insert(1);
    bst.insert(3);
    bst.insert(2);
    bst.insert(4);
    bst.insert(0);
    bst.insert(-1);
    bst.insert(-2);
    std::cout << "bst.getHeight(bst.getRoot()):" << bst.getHeight(bst.getRoot()) << std::endl;
    return 0;
}