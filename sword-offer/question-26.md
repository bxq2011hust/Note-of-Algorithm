## 面试题26 复杂链表的复制

<!-- TOC -->

- [面试题26 复杂链表的复制](#面试题26-复杂链表的复制)
- [[题目1][url]](#题目1url)
    - [思路O(n)](#思路on)
    - [实现](#实现)

<!-- /TOC -->

## [题目1][url]
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。

### 思路O(n)
1. 先序遍历链表，将复制节点接在原节点之后
2. 处理随机节点，源节点指向的随机后面是新链表应该指向的随机节点
3. 分离复制的链表和原链表

### 实现

```cpp
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL) return NULL;
        // 复制节点位于原节点之后
        RandomListNode *pNode=pHead;
        while(pNode!=NULL)
        {
            RandomListNode* pClone= new RandomListNode(pNode->label);
            //pClone->label=pNode->label;
            pClone->next=pNode->next;
            //pClone->random=NULL;
            pNode->next=pClone;
            pNode=pClone->next;
        }

        //复制节点的随机节点位于原节点的随机节点之后
        pNode=pHead;
        RandomListNode * pNew=NULL;
        while(pNode!=NULL)
        {
            pNew=pNode->next;
            if(pNode->random!=NULL)
            	pNew->random=pNode->random->next;
            pNode=pNew->next;
        }
        // 防止只有1个节点，分离原链表与复制链表
        RandomListNode * pNewHead=pHead->next;
        pNode=pHead;
        pNew=pNewHead;
        pNode->next=pNew->next;
        pNode=pNode->next;
        while(pNode!=NULL)
            {
            pNew->next=pNode->next;
            pNew=pNew->next;
            pNode->next=pNew->next;
            pNode=pNode->next;
        }
        return pNewHead;
    }
};
``` 

[url]:https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking