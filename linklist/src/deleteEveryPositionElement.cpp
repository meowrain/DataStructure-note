#include <iostream>
struct Node
{
    int data;
    Node *next;
};
Node *head;
void Insert(int);
void Print();
void del_element(int);
int main(void)
{
    head = NULL; // empty list
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Insert(6);
    Print();
    del_element(6);
    Print();
    return 0;
}
void Insert(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
void Print()
{
    std::cout << "链表中的内容为：" << std::endl;
    Node *curr = head;
    while (curr != NULL)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}
void del_element(int n)
{
    if (head == NULL)
    { // 链表为空的情况，不用删除
        std::cout << "链表为空，无法删除，请在链表内插入值后进行删除操作 ！" << std::endl;
        return;
    }
    if (n == 1)
    {
        head = head->next;
        return;
    }

    Node *cur = head;
    for (int i = 1; i < n - 1 && cur->next != NULL; i++)
    {
        cur = cur->next;
    }
    if(cur->next == NULL) {
        std::cout << "输入了非法的删除位置！" << std::endl;
        return;
    }
    cur->next = cur->next->next;
}
