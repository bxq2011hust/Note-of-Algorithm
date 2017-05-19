## 面试题16 反转单向链表

<!-- TOC -->

- [面试题16 反转单向链表](#面试题16-反转单向链表)
- [[题目1][url1.1]](#题目1url11)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## [题目1][url1.1]
输入一个链表，反转链表后，输出链表的所有元素。
非递归实现与递归实现，假定单向链表中无头节点，也就是头指针(head)指向链表的第一个节点

### 思路
1. 如果只有一个节点则退出，否则保存当前上一个节点的指针`pre`，保存下一个节点的指针`next`，将当前节点`curr`的下一个节点指向上一个节点，当前节点处理结束，将当前节点指向`next`，循环直到当前节点指向`NULL`

### 实现

- 非递归实现
```cpp
Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *pre, *curr, *next;
    pre = head;
    curr = head->next;
    head->next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}
```

- 牛客网-递归实现
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
    ListNode* ReverseList(ListNode* pHead) {
	if (pHead == NULL || pHead->next == NULL)
        return pHead;
    ListNode *newHead = ReverseList(pHead->next);
    pHead->next->next = pHead;
    pHead->next = NULL;

    return newHead;
    }
};
``` 

[url1.1]:https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking