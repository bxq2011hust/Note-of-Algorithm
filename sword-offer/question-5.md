## 面试题5 从尾到头打印链表

<!-- TOC -->

- [面试题5 从尾到头打印链表](#面试题5-从尾到头打印链表)
    - [题目](#题目)
    - [思路](#思路)
    - [栈实现](#栈实现)
    - [递归实现](#递归实现)

<!-- /TOC -->

### 题目
输入单向链表头结点，从尾到头打印

### 思路
使用栈保存节点，然后打印；递归打印

### 栈实现
```cpp
void reversePrint(Node *head)
{
    std::stack<Node *> s;
    while (head != NULL)
    {
        s.push(head);
        head = head->next;
    }
    Node *tmp;
    while (!s.empty())
    {
        tmp = s.top();
        std::cout << tmp->value << " ";
        s.pop();
    }
}
``` 
### 递归实现
```cpp
void reversePrint(Node *head)
{
    if (head == NULL)
        return;
    reversePrint(head->next);
    std::cout << head->value << " ";
}
``` 

