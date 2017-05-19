## 面试题15 链表中倒数第k个结点

<!-- TOC -->

- [面试题15 链表中倒数第k个结点](#面试题15-链表中倒数第k个结点)
- [[题目1][url1.1]](#题目1url11)
    - [思路](#思路)
    - [实现](#实现)
- [题目2](#题目2)
    - [思路](#思路-1)
    - [实现](#实现-1)
- [题目3](#题目3)
    - [思路](#思路-2)
    - [实现](#实现-2)

<!-- /TOC -->

## [题目1][url1.1]
输入一个链表，输出该链表中倒数第k个结点。

### 思路
1. 两个指针`first secode`，`first`一个先走k步，如果k步过程中碰到NULL则链表长度不足k，返回NULL，如果走了k步，则此时first指向第k+1个节点
2. k步之后`second`开始前进，当`first`指向`NULL`时，`second`指向倒数k个节点

### 实现
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(pListHead==NULL||k==0) return NULL;
        ListNode *first=pListHead,*second=pListHead;
        size_t i=0;
        for(;i<k&&first!=NULL;++i)
            first=first->next;
        if(i<k) return NULL;
        while(first!=NULL)
            {
            first=first->next;
            second=second->next;
        }
        return second;
    }
};
``` 
## 题目2
求链表的中间节点，如果链表长度为偶数返回中间两个节点的前一个，若为奇数返回中间节点。

### 思路
1. 两个指针`fast slow`，`fast`每次前进两步，`slow`每次前进一步
2. 当fast指向尾时(不是NULL)

### 实现
```cpp
struct Node
{
    Node* next;
    int value;
};

Node *middleNode(Node *head)
{
    if (head == NULL)
        return head;
    Node *slow, *fast;
    fast = slow = head;
    // 如果偶数长时，返回中间任意则可以去掉fast->next->next!=NULL
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
``` 
## 题目3
判断单向链表是否存在环

### 思路
1. 两个指针，从头节点出发，一个每次向前2步，一个每次向前一步，如果相遇则存在环

### 实现
```cpp
struct Node
{
    Node* next;
    int value;
};

bool hasCircle(Node *head, Node *&circleNode)
{
    Node *fast, *slow;
    fast = slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            circleNode = fast;
            return true;
        }
    }
    return false;
}
``` 

[url1.1]:https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking