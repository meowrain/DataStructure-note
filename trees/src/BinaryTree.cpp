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
class BinaryTree
{
private:
    Node<T> *root;

public:
    BinaryTree() : root(nullptr){};
    Node<T> *getRoot()
    {
        return root;
    }
    void insert(T value)
    {
        root = insertRecursive(root, value);
    }

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
};

int main(void)
{
    BinaryTree<int> binaryTree;
    binaryTree.insert(1); // 第一个插入的结点是根节点
    binaryTree.insert(0); // 小于根节点，在根节点左侧
    binaryTree.insert(2); // 大于根结点,在根节点右侧
    binaryTree.insert(3); //大于根结点，在根节点右侧，又大于2，在2结点的右侧
    Node<int> *root = binaryTree.getRoot();
    std::cout << root->left->data << std::endl;
    std::cout << root->right->data << std::endl;
    std::cout << root->right->right->data << std::endl;
}