## 面试题57 删除链表中重复的结点

<!-- TOC -->

- [面试题57 删除链表中重复的结点](#面试题57-删除链表中重复的结点)
- [题目](#题目)
    - [思路](#思路)
    - [实现](#实现)

<!-- /TOC -->

## 题目

在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5。[牛客网地址][url]

### 思路
1. 初始`preNode=NULL pNode=pHead`
2. 判断pNode与pNode->next是否存在，存在则判断其值是否相等，相等则需要删除
3. 不想等则处理下一个节点，此时`preNode=pNode pNode=pNode->next`
4. 考虑特殊输入`1 1`、`1 1 2`
 
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
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode *pNode = pHead;
        ListNode *preNode = NULL;
        while (pNode != NULL && pNode->next != NULL)
        {
            if (pNode->val == pNode->next->val)
            {
                // 删除与当前结点重复的节点
                while (pNode->next != NULL && pNode->val == pNode->next->val)
                {
                    ListNode *tmp = pNode->next;
                    pNode->next = pNode->next->next;
                    delete tmp;
                }
                // 删除当前结点
                ListNode *tmp = pNode->next;
                delete pNode;
                pNode = tmp;
                if (preNode != NULL)
                    preNode->next = tmp;
            }
            else
            {
                if (preNode == NULL)
                    pHead = pNode;
                preNode = pNode;
                pNode = pNode->next;
            }
        }
        // 处理1 1这类情况
        if (preNode == NULL)
            pHead = pNode;
        return pHead;
    }
};
``` 
[url]:https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking