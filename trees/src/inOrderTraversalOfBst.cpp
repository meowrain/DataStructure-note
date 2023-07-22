/* 中序遍历 */
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
class BST
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
    BST() : root(nullptr){};
    Node<T> *getRoot() { return root; };
    void insert(T value)
    {
        root = insertRecursive(root, value);
    }
    void inOrder(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }
};
int main(void)
{
    BST<int> bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.insert(6);
    bst.insert(5);
    bst.insert(7);
    bst.inOrder(bst.getRoot());
}