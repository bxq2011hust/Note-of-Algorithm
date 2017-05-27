## 面试题37 两个链表的第一个公共结点

<!-- TOC -->

- [面试题37 两个链表的第一个公共结点](#面试题37-两个链表的第一个公共结点)
- [[题目][url]](#题目url)
    - [思路1](#思路1)
    - [实现1](#实现1)
    - [思路2](#思路2)
    - [实现2](#实现2)

<!-- /TOC -->

## [题目][url]

输入两个链表，找出它们的第一个公共结点。

### 思路1
1. 使用两个栈保存两个链表的节点，然后一次比较栈顶节点
2. 如果栈顶节点不同，则上一个节点就是第一个公共节点
3. 时间复杂度O(m+n) 空间复杂度O(m+n)

### 实现1

```cpp
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution
{
  public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == NULL || pHead2 == NULL)
            return NULL;
        stack<ListNode *> stack1, stack2;
        ListNode *pNode = pHead1;
        while (pNode != NULL)
        {
            stack1.push(pNode);
            pNode = pNode->next;
        }
        pNode = pHead2;
        while (pNode != NULL)
        {
            stack2.push(pNode);
            pNode = pNode->next;
        }
        pNode = NULL;
        while (stack1.top() == stack2.top())
        {
            pNode = stack1.top();
            stack1.pop();
            stack2.pop();
            if (stack1.empty() || stack2.empty())
                break;
        }
        return pNode;
    }
};
``` 
### 思路2
1. 遍历的到长度，然后用长链表长度减去短链表长度差为lengthDif，长链表先走k步
2. 接下来一起前进，直到第一个相同的节点。如果没有相同节点则会指向NULL，相同退出循环
3. 时间复杂度O(m+n)不需要辅助的栈

### 实现2

```cpp
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution
{
  public:
  //得到链表长度
    unsigned int GetListLength(ListNode *pHead)
    {
        unsigned int length = 0;
        while (pHead != NULL)
        {
            ++length;
            pHead = pHead->next;
        }
        return length;
    }
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == NULL || pHead2 == NULL)
            return NULL;
        unsigned int len1 = GetListLength(pHead1);
        unsigned int len2 = GetListLength(pHead2);
        int lengthDif = len1 - len2;

        ListNode *pLong = pHead1;
        ListNode *pShort = pHead2;

        if (len2 > len1)
        {
            pLong = pHead2;
            pShort = pHead1;
            lengthDif = -lengthDif;
        }
        // 先在长链表上前进
        for (int i = 0; i < lengthDif; ++i)
            pLong = pLong->next;

        while (pLong != pShort)
        {
            pLong = pLong->next;
            pShort = pShort->next;
        }
        return pLong;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
