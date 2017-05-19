## 面试题17 合并两个排序的链表

<!-- TOC -->

- [面试题17 合并两个排序的链表](#面试题17-合并两个排序的链表)
- [[题目1][url1.1]](#题目1url11)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目1][url1.1]
输入两个单调递增的链表，输出两个链表合成后的链表

### 思路
类似归并排序的思想实现
1. 如果head1为空，返回head2；如果head2为空，返回head1
2. 根据head1和head2的值确定新的头节点
3. 归并排序

### 实现

- 非递归实现
```cpp
struct Node
{
    Node* next;
    int value;
};

Node *mergeSortList(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node *newHead = NULL;
    if (head1->value < head2->value)
    {
        newHead = head1;
        head1 = head1->next;
    }
    else
    {
        newHead = head2;
        head2 = head2->next;
    }

    Node *tmp = newHead;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->value < head2->value)
        {
            tmp->next = head1;
            head1 = head1->next;
        }
        else
        {
            tmp->next = head2;
            head1 = head2->next;
        }
        tmp = tmp->next;
        tmp->next = NULL;
    }
    if (head1 != NULL)
        tmp->next = head1;
    else if (head2 != NULL)
        tmp->next = head2;
    return newHead;
}
```

- 牛客网-递归实现
1. 如果head1为空，返回head2；如果head2为空，返回head1
2. 如果`head1->val < head2->val`则`newHead=head1`，然后处理(head1->next,head2)
2. 如果`head1->val >= head2->val`则`newHead=head2`，然后处理(head1,head2->next)

```cpp
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL) return pHead2;
        if(pHead2==NULL) return pHead1;
        ListNode * newHead=NULL;
        if(pHead1->val < pHead2->val)
        {
            newHead = pHead1;
            newHead->next=Merge(pHead1->next,pHead2);
        }
        else
        {
            newHead = pHead2;
            newHead->next=Merge(pHead1,pHead2->next);
        }
        return newHead;
    }
};
``` 

[url1.1]:https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking