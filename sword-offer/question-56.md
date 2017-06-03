## 面试题56 链表中环的入口结点

<!-- TOC -->

- [面试题56 链表中环的入口结点](#面试题56-链表中环的入口结点)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

一个链表中包含环，请找出该链表的环的入口结点。[牛客网地址][url]

### 思路
1. 首先使用快慢指针判断是否存在环
2. 如果存在环，则将其中一个指针置为头指针，另一个指针指向相遇节点，继续前进直到再次相遇，相遇处就是环的入口

### 实现

```cpp
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution
{
  public:
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return NULL;
        ListNode *fast, *slow;
        fast = slow = pHead;
        while (fast != NULL && slow != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                break;
        }
        // 不存在环
        if (fast != slow)
            return NULL;

        fast = pHead;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking