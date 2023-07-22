#include <iostream>
template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree
{
private:
    Node<T> *root;
    Node<T> *insertRecursive(Node<T> *node, T value)
    {
        if (node == nullptr)
        {
            return new Node<T>(value);
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
    BinarySearchTree() : root(nullptr){};
    Node<T> *getRoot()
    {
        return root;
    }
    void Insert(T value)
    {
        root = insertRecursive(root, value);
    }

    Node<T> *findMin()
    {
        Node<T> *current = root;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }
    Node<T> *findMax()
    {
        Node<T> *current = root;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }
};
int main(void)
{
    BinarySearchTree<int> bst;
    bst.Insert(1);
    bst.Insert(2);
    bst.Insert(0);
    bst.Insert(-1);
    bst.Insert(4);
    bst.Insert(3);
    std::cout << "bst.findMax() = " << bst.findMax()->data << std::endl;
    std::cout << "bst.findMin() = " << bst.findMin()->data << std::endl;
    return 0;
}