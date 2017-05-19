## 面试题13 在O(1)时间删除链表节点

<!-- TOC -->

- [面试题13 在O(1)时间删除链表节点](#面试题13-在o1时间删除链表节点)
- [题目1](#题目1)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目1
给定单向链表的头指针和节点指针node，要求在O(1)时间删除该节点

### 思路
1. node->next不为NULL，则将node->next的值赋值给node然后删除node->next
2. node为头节点，则此时链表只有一个节点，删除即可
3. node不满足1，2，则node是链表的尾节点，遍历删除

### 实现
```cpp
struct Node
{
    Node* next;
    int value;
};

void deleteNode(Node **head, Node *toDeleteNode)
{
    if (head == NULL || toDeleteNode == NULL)
        return;
    if (toDeleteNode->next != NULL)
    {
        Node *pNext = toDeleteNode->next;
        toDeleteNode->value = pNext->value;
        toDeleteNode->next = pNext->next;
        delete pNext;
        pNext = NULL;
    }
    else
    {
        // 列表中只有一个节点
        if (*head == toDeleteNode)
        {
            delete toDeleteNode;
            toDeleteNode = NULL;
            *head = NULL;
        }
        else
        {
            Node *tmp = *head;
            while (tmp->next != NULL && tmp->next != toDeleteNode)
                tmp = tmp->next;
            if (tmp->next == NULL)
                return;
            tmp->next = NULL;
            delete toDeleteNode;
            toDeleteNode = NULL;
        }
    }
}
``` 

