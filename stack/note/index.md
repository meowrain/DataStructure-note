# 栈

# 用数组实现栈

```cpp
#include <iostream>
using namespace std;

int MAX_SIZE = 10;              // 定义栈的最大容量
int *Stack = new int[MAX_SIZE]; // 动态分配数组空间
int top = -1;                   // 栈顶指针初始化为-1

void push_back(int n)
{ // 入栈操作
    if (top == MAX_SIZE - 1)
    { // 如果栈已满，扩容两倍
        MAX_SIZE = 2 * MAX_SIZE;
        int *newStack = new int[MAX_SIZE]; // 动态分配更大的数组空间
        for (int i = 0; i <= top; i++)
        { // 将原数组中的元素复制到新数组中
            newStack[i] = Stack[i];
        }
        Stack = newStack; // 将指针指向新数组的首地址
    }
    top = top + 1;  // 栈顶指针加1
    Stack[top] = n; // 将元素压入栈顶
}

void pop()
{                  // 出栈操作
    top = top - 1; // 栈顶指针减1
}

bool IsEmpty()
{ // 判断栈是否为空
    if (top == -1)
    { // 栈顶指针为-1时，栈为空
        return true;
    }
    return false;
}

int top_element()
{ // 返回栈顶元素
    return Stack[top];
}

int search(int n)
{ // 查找元素在栈中的位置
    for (int i = 0; i <= top; i++)
    { // 从栈底开始遍历栈中的所有元素
        if (Stack[i] == n)
        {             // 如果找到指定的元素
            return i; // 返回元素在栈中的位置
        }
    }
    return -1; // 否则返回-1
}

int main(void)
{
    // 测试代码
    for (int i = 0; i < 200; i++)
    { // 入栈200个元素
        push_back(i);
    }
    while (!IsEmpty())
    { // 出栈并输出元素
        cout << top_element() << " ";
        pop();
    }
    cout << search(3) << endl; // 查找元素3在栈中的位置
    delete[] Stack;            // 释放动态分配的数组空间
    return 0;
}
```

为了更加清晰明了，我写了下面的程序，实现了和上面一样的功能
`stack_array_v2.cpp`
```cpp
#include <iostream>
using namespace std;
class Stack
{
private:
    int MAX_SIZE = 10;              // 定义栈的最大容量
    int *Stack = new int[MAX_SIZE]; // 动态分配数组空间
    int top = -1;

public:
    void push_back(int val)
    {
        if (top >= MAX_SIZE - 1)
        {
            MAX_SIZE *= 2;
            int *newStack = new int[MAX_SIZE];
            for (int i = 0; i <= top; i++)
            {
                newStack[i] = Stack[i];
            }
            Stack = newStack;
        }
        top++;
        Stack[top] = val;
    }
    void pop()
    {
        top--;
    }
    bool is_empty()
    {
        return top == -1; // 判断栈是否为空
    }
    int top_element()
    {
        return Stack[top];
    }
    int search(int n)
    { // 查找元素在栈中的位置
        for (int i = 0; i <= top; i++)
        { // 从栈底开始遍历栈中的所有元素
            if (Stack[i] == n)
            {             // 如果找到指定的元素
                return i; // 返回元素在栈中的位置
            }
        }
        return -1; // 否则返回-1
    }
};
int main(void)
{
    Stack s;
    for (int i = 0; i <= 200; i++)
    {
        s.push_back(i);
    }
    while (!s.is_empty())
    {
        cout << s.top_element() << " ";
        s.pop();
    }
    
    return 0;
}
```

# 用链表实现栈
```cpp
#include <iostream>
struct Node {
    int data;
    Node *next;
};
class Stack {
private:
    Node *top;
public:
    Stack() {
        top = nullptr;
    }
    void push(int val) {
        Node *node = new Node();
        node->data = val;
        node->next = top;
        top = node;
    }
    void pop() {
        if(top != nullptr) {
            Node *node = top;
            top = top->next;
            delete node;
        }
    }
    int topVal() {
        if(top != nullptr) {
            return top->data;
        }else {
            return -1;
        }
    }
    bool isEmpty() {
        return top == nullptr;
    }
};
int main(void) {
    Stack s;
    for(int i = 0; i < 200; i++) {
        s.push(i);
    }
    while(!s.isEmpty()) {
        std::cout << s.topVal() << std::endl;
        s.pop();
    }
}
```



# 翻转一个字符串或者翻转一个链表(用栈实现)

## Reverse a string in default

例如： 

hello -> olleh

### 翻转字符串的常规做法

```cpp
#include <iostream>
#include <string>
using namespace std;
void reverse_string(string &s) {
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}
int main(void) {
    string s = "hello";
    cout << "The valine of s is: " << s << endl;
    reverse_string(s);
    cout << "The reverse result of s is: " << s << endl;
    return 0;
}
```

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void) {
    string s = "hello";
    cout << "The valine string value is: " << s << endl; 
    s.reverse(s.begin(),s.end());
    cout << "The reverse string value is: "<< s << endl;
    return 0;
}

```
## Reverse a string using Stack
我们首先把HELLO这个字符串一个字符一个字符的放入栈中
![我们首先把HELLO这个字符串一个字符一个字符的放入栈中](image/index/1689384041187.png)

然后让栈里面的字符从栈顶依次出栈就行了！

![让栈里面的字符从栈顶依次出栈就行](image/index/1689384109769.png)



下面是代码实现

```cpp
#include <iostream>
#include <string>
using namespace std;
class Stack
{
private:
    int MAX_SIZE = 5;
    char *stack = new char[MAX_SIZE];
    int top = -1;

public:
    void push_back(char n)
    {
        if (top == MAX_SIZE - 1)
        {
            MAX_SIZE *= 2;
            char *newStack = new char[MAX_SIZE];
            for (int i = 0; i <= top; i++)
            {
                newStack[i] = stack[i];
            }
            stack = newStack;
        }
        top++;
        stack[top] = n;
    }
    char pop()
    {
        if (top == -1)
        {
            return '\0';
        }
        else
        {
            char temp = stack[top]; // 存储栈顶元素
            top--;                  // 弹出栈顶元素
            return temp;            // 返回被弹出的栈顶元素
        }
    }
};
int main(void)
{
    string s = "hello";
    Stack stack;
        for (char c : s) {
        stack.push_back(c);
    }
    for (int j = 0; j < s.size(); j++)
    {
        cout << stack.pop();
    }
    return 0;
}
```
![1689384777834](image/index/1689384777834.png)





## Reverse a linklist using Stack

让我们想一想我们之前是怎么翻转链表的？



首先，函数判断链表的头部是否为空或只有一个节点，如果是，则无需进行翻转，直接返回。这一步的判断是非常必要的，因为链表为空或只有一个节点时，翻转链表是没有意义的。

接着，函数定义了三个指针变量 cur、prev、next，它们分别指向当前节点、当前节点的前一个节点和当前节点的后一个节点。其中，cur 变量初始化为链表的头部，prev 变量初始化为 NULL。

进入 while 循环，每次将 next 指向当前节点 cur 的下一个节点，然后将 cur 的 next 指针指向 prev，这样就完成了当前节点的翻转。接着，将 prev 指向当前节点 cur，cur 指向下一个节点 next，继续执行下一轮循环。这样不断地执行，直到 cur 指向链表的最后一个节点，此时整个链表就被翻转了。

最后，将链表的头部指向反转后的链表头部 prev，完成链表的翻转操作。

综上所述，您的 Reverse() 函数采用了迭代的方式翻转链表，通过遍历链表，每次将当前节点的 next 指针指向前一个节点，最终完成整个链表的翻转。

```cpp
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head;
void Insert(int num);
void Print();
void Reverse();
int main(void)
{
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Insert(6);
    Print();
    cout << "Now we will reverse this linklist!" << endl;
    Reverse();
    Print();
}
void Insert(int num)
{
    Node *temp = new Node();
    temp->data = num;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
    }
}
void Print()
{
    cout << "The content in linklist:" << endl;
    Node *cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
void Reverse()
{
    if (head == NULL || head->next == NULL)
    {
        cout << "元素数量不足，无法进行翻转!" << endl;
        return;
    }
    Node *cur,*prev,*next;
    cur = head;
    prev = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}
```



> 那该如何用栈来翻转链表呢？
>
> 使用栈可以将链表翻转为逆序，具体步骤如下：
>
> 1. 遍历链表，将每个节点的指针依次压入栈中。
> 2. 弹出栈顶元素，将其指针指向下一个栈顶元素，直到栈为空。
> 3. 返回链表的新头节点。





```cpp
#include <iostream>
#include <stack>
using namespace std;

// 链表节点结构体
struct Node
{
    int data;       // 数据
    Node *next;     // 指向下一个节点的指针
};

// 链表类
class LinkList
{
public:
    Node *head = nullptr;   // 链表的头节点

    // 在链表末尾插入一个节点
    void Insert(int val)
    {
        Node *temp = new Node();    // 创建新节点
        temp->data = val;           // 设置新节点的数据
        temp->next = nullptr;       // 新节点的下一个节点指针为nullptr

        if (head == nullptr)        // 如果链表为空
        {
            head = temp;            // 将新节点设置为头节点
            return;
        }
        else                        // 如果链表不为空
        {
            Node *cur = head;
            while (cur->next != nullptr)    // 遍历链表找到最后一个节点
            {
                cur = cur->next;
            }
            cur->next = temp;       // 将新节点连接到最后一个节点的后面
        }
    }

    // 打印链表中的所有元素
    void Print()
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }

    // 将链表逆序
    void Reverse()
    {
        stack<Node *> s;   // 创建一个栈，用来存储链表中的所有节点

        Node *cur = head;
        while (cur != nullptr)      // 将链表中的所有节点都压入栈中
        {
            s.push(cur);
            cur = cur->next;
        }

        head = s.top();     // 将栈顶元素设置为链表的新头节点
        s.pop();

        cur = head;         // 遍历链表，将栈中的节点依次弹出并连接起来
        while (!s.empty())
        {
            cur->next = s.top();
            s.pop();
            cur = cur->next;
        }
        cur->next = nullptr;    // 最后一个节点的下一个节点指针为nullptr
    }
};

int main(void)
{
    LinkList l;     // 创建一个链表对象

    // 向链表中插入元素
    l.Insert(1);
    l.Insert(2);
    l.Insert(3);
    l.Insert(4);
    l.Insert(5);
    l.Insert(6);
    l.Insert(7);

    // 打印原始链表
    l.Print();
    cout << endl;

    // 将链表逆序
    l.Reverse();

    // 打印逆序后的链表
    l.Print();
    cout << endl;

    return 0;
}
```

